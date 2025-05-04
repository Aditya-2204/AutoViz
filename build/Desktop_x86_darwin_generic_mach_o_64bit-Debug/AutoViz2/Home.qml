import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    Button {
        text: "Go to Screen 2"
        anchors.centerIn: parent
        onClicked: {
            StackView.view.push("Screen2.qml")
        }
    }
}

