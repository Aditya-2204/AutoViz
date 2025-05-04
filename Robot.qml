import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: myRectangle
    width: 100
    height: 100
    color: "skyblue"
    x: 50  // Initial x position
    y: 50  // Initial y position

    // You can optionally add an animation to make the movement smoother
    PropertyAnimation {
        id: moveAnimation
        target: myRectangle
        property: "x"
        to: 200  // Target x position
        duration: 500  // Duration of the movement in milliseconds
        easing.type: Easing.InOutQuad  // Easing for smooth transition
    }

    MouseArea {
        id: moveButton
        anchors.centerIn: parent
        width: 100
        height: 50
        onClicked: {
            // Move rectangle to new position when the button is clicked
            moveAnimation.to = 200  // Set new x position
            moveAnimation.running = true  // Trigger the animation

            // If you want to change both x and y position, you can do it like this:
            moveAnimation.property = "y";
            moveAnimation.to = 200; // New y position
            moveAnimation.running = true;
        }

        Rectangle {
            width: parent.width
            height: parent.height
            color: "lightgreen"
            radius: 10
            anchors.centerIn: parent
        }
    }
}
