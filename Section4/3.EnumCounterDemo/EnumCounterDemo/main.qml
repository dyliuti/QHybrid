import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.2
import com.dyliuti.counter 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    // 需要先初始化下，主要是得到这个id,可控制cpp中定义的类
    Counter {
        id: mCounter
    }

    Column{
        anchors.centerIn: parent
        spacing: 10

        Rectangle{
            width: 200
            height: 200
            radius: 20
            color: (mCounter.count >= 0) ? "green": "red"

            Text {
                id: mText
                text: mCounter.count
                anchors.centerIn: parent
                font.pointSize: 20
                color: "white"
            }
        }

        Button {
            width: 200
            text: "Start"
            onClicked: {
                mCounter.start()
            }
        }

        Button {
            width: 200
            text: "Stop"
            onClicked: {
                mCounter.stop()
            }
        }

        Button {
            width: 200
            text: "Up"
            onClicked: {
                mCounter.up = true;
            }
        }

        Button {
            width: 200
            text: "Down"
            onClicked: {
                mCounter.up = false;
            }
        }
    }
}
