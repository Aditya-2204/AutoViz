import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    Rectangle {
        anchors.fill: parent
        color: "lightblue"

        Text {
            text: "Screen 2"
            anchors.centerIn: parent
        }
    }

    Button {
        text: "Back"
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: StackView.view.pop()
    }
}
