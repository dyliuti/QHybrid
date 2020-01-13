import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Connections C++ Demo")

    // 捕获Cpp中发的信号
    Connections{
        target: CppSignalSender
        onCallQml:{
            console.log("在qml中捕获cpp信号")
            mText.text = param
        }

        onCppTimer:{
            console.log("在qml中捕获cpp时间信号")
            mRectText.text = value;
        }
    }

    Column{
        Rectangle{
            id: rect
            width: 200
            height: 200
            color: "red"
            radius: 20

            Text{
                id: mRectText
                text: "0"
                anchors.centerIn: parent
                color: "white"
                font.pointSize: 20
            }
        }

        Button{
            text: "Call C++ Method"
            onClicked: {
                CppSignalSender.cppSlot()
            }
        }

        Text{
            id: mText
            text: qsTr("default")
        }
    }
}
