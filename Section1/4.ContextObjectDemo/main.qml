import QtQuick 2.11
import QtQuick.Window 2.11

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("ContextObject Demo")

    Rectangle{
        id: mRect1
        width: mText1.implicitWidth + 20
        height: mText1.implicitHeight + 20
        color: "beige"
        border.color: "yellowgreen"

        Text{
            id: mText1
            anchors.centerIn: parent
            text: lastName  // mLastName  // Doe
            font.pointSize: 20
        }
    }

    Rectangle{
        id: mRect2
        anchors.left: mRect1.right
        anchors.leftMargin: 5
        width: mText2.implicitWidth + 20
        height: mText2.implicitHeight + 20
        color: "beige"
        border.color: "yellowgreen"

        Text{
            id: mText2
            anchors.centerIn: parent
            text: firstName //mFirstName    // John
            font.pointSize: 20
        }
    }
}
