import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.3

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column {
        spacing: 20
        // 读取属性
        Text {
            id: titleId
            width: 500
            text: Movie.title
            font.pointSize: 20
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Text {
            id: mainCharId
            width: 500
            text: Movie.mainCharacter
            font.pointSize: 20
            anchors.horizontalCenter: parent.horizontalCenter
        }
        // 改变属性
        Row{
            anchors.horizontalCenterOffset: parent.horizontalCenter

            TextField{
                id: titleTextFieldId
                width: 300
            }

            Button {
                width: 200
                id: button
                text: "change Title"
                onClicked: {
                    Movie.title = titleTextFieldId.text
                }
            }
        }

        Row{
            anchors.horizontalCenterOffset: parent.horizontalCenter

            TextField{
                id: mainCharTextFieldId
                width: 300
            }

            Button {
                width: 200
                id: button2
                text: "change main character"
                onClicked: {
                    Movie.mainCharacter = mainCharTextFieldId.text
                }
            }
        }
    }
}
