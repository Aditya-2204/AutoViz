import QtQuick

Rectangle {
    id: robotBody
    width: 29.8125
    height: 29.8125
    color: "#5A5A5A"
    border.color: "white"
    border.width: 3
    radius: 10

    Component.onCompleted: {
        robotBody.rotation=90-controller.radiansToDegrees(controller.getHeading());
    }

    property alias frontLeft: FL
    property alias frontRight: FR
    property alias backLeft: BL
    property alias backRight: BR



    property real m: 29.8125

    // Front Left wheel
    Rectangle {
        id: FL
        width: parent.width*0.1
        height: parent.height*0.3
        color: "black"
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.margins: 10
        rotation: 0
        transformOrigin: Item.Center
    }

    // Front Right wheel
    Rectangle {
        id: FR
        width: parent.width*0.1
        height: parent.height*0.3
        color: "black"
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.margins: 10
        rotation: 0
        transformOrigin: Item.Center
    }

    // Back Left wheel
    Rectangle {
        id: BL
        width: parent.width*0.1
        height: parent.height*0.3
        color: "black"
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.margins: 10
        rotation: 0
        transformOrigin: Item.Center
    }

    // Back Right wheel
    Rectangle {
        id: BR
        width: parent.width*0.1
        height: parent.height*0.3
        color: "black"
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 10
        rotation: 0
        transformOrigin: Item.Center
    }
}
