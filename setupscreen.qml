import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Dialogs

ApplicationWindow {
    id: window
    visible: true
    width: 900
    height: 600
    title: "AutoViz - Setup"
    Material.theme: Material.Dark
    Material.accent: "#89CFF0"

    property string projectName: "";
    property bool simulationRecording: true;

    StackView {
        id: stackView
        anchors.fill: parent
    }

    Rectangle {
        anchors.fill: parent
        color: "#121212"

        ColumnLayout {
            anchors.centerIn: parent
            spacing: 20
            width: parent.width * 0.8

            Text {
                text: "AutoViz Simulator Setup"
                font.pixelSize: 32
                color: "#89CFF0"
                horizontalAlignment: Text.AlignHCenter
                Layout.alignment: Qt.AlignHCenter
            }

            Text {
                text: "Configure your simulation project below:"
                font.pixelSize: 18
                color: "white"
                horizontalAlignment: Text.AlignHCenter
                Layout.alignment: Qt.AlignHCenter
            }

            // Project Directory
            RowLayout {
                spacing: 0
                Layout.fillWidth: true

                TextField {
                    id: directoryField
                    placeholderText: "Select Project Directory"
                    Layout.fillWidth: true
                    background: Rectangle {
                        color: "#1f1f1f"
                        radius: 10
                    }
                    color: "white"
                }

                Button {
                    id: folderDialogButton
                    contentItem: Text{
                        text: "📁"
                        color: "White"
                    }

                    Layout.preferredWidth: 50
                    onClicked: folderDialog.open()
                    background: Rectangle {
                        color: "#2e2e2e"
                        radius: 10
                    }

                    anchors.leftMargin: 10
                }

                FolderDialog {
                    id: folderDialog
                    title: "Choose Project Directory"
                    onAccepted: {
                        directoryField.text = folderDialog.selectedFolder.toString().replace("file://", "");
                    }
                }
            }

            // Project Name
            TextField {
                id: projectNameField
                placeholderText: "Enter Project Name"
                Layout.fillWidth: true
                background: Rectangle {
                    color: "#1f1f1f"
                    radius: 10
                }
                color: "white"
            }

            Label {
                id: errorMsg
                visible: false
                text: "Project Already Exists"
                color: "Red"
            }

            // Start Button
            Button {
                text: "Start Simulation"
                Layout.alignment: Qt.AlignHCenter
                font.pixelSize: 16
                padding: 10
                background: Rectangle {
                    color: "#89CFF0"
                    radius: 10
                }
                onClicked: {
                    const success = controller.startNewProject(projectNameField.text, directoryField.text)
                    if(success){
                        onClicked: {
                            let component = Qt.createComponent("qrc:/QML/simscreen.qml");
                            if (component.status === Component.Ready) {
                                let win = component.createObject(null, {
                                    simulationRecording: true,
                                    projectName: projectNameField.text
                                });
                                if (win) {
                                    win.show();  // ensure it's visible
                                } else {
                                    console.error("❌ Failed to create window");
                                }
                            } else {
                                console.error("❌ Component load error:", component.errorString());
                            }
                        }
                    }
                    else {
                        errorMsg.visible = true;
                    }
                    window.close();
                }
            }
        }
    }
}
