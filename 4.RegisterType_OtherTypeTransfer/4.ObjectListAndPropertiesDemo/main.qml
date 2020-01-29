import QtQuick 2.11
import QtQuick.Window 2.11
import com.dyliuti.Football 1.0
import QtQuick.Controls 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("ObjectListAndPropertiesDemo")

    // Cpp中定义了FootballTeam的4个属性，可在qml中调用
    FootballTeam{
        id: team1
        title: "Rayon Sports"
        coath: "Coatch Name"
        // 队长
        captain: Player{
            name: "小明captain"
            position: "中场"
            playing: true
        }

        // PROPERTY中的QQmlListProperty<Player>属性
        players: [
            // Cpp中定义了Player的3个属性，可在qml中调用
            Player{
                name: "Player1"
                position: "中场"
                playing: true
            },
            Player{
                name: "Player2"
                position: "前锋"
                playing: true
            },
            Player{
                name: "Player3"
                position: "后场"
                playing: true
            },
            Player{
                name: "dyliuti"
                position: "前锋"
                playing: false
            }
        ]
    }

    // 使用qml中的对象作为model,QML中的model关联了Cpp数据
    ListView{
        anchors.fill: parent
        model: team1.players
        delegate: Rectangle{
            width: parent.width
            height: 50
            border.width: 1
            border.color: "yellowgreen"
            color: "beige"

            Text{
                anchors.centerIn: parent
                text: name
                font.pixelSize: 20
            }
        }
    }

    Component.onCompleted: {
        console.log("We have :" + team1.players.length + " players in the team " + team1.title)
    }
}
