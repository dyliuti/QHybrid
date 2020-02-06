import QtQuick 2.11
import QtQuick.Window 2.11

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("StringList Model Demo")

    ListView{
        id : mListView
        anchors.fill: parent

        model: continentModel  // 20的话就是从0到19了
        delegate: Rectangle {
            height: 50
            radius: 10
            color: "dodgerblue"
            border.color: "cyan"
            width: parent.width
            Text {
                text: modelData
                font.pointSize: 20
                anchors.centerIn: parent
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }
}
