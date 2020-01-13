import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    id: mainWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    property Component component: null

    Column{
        spacing: 10
        Button{
            text: "Call C++ Method"
            onClicked: {
                mainWindow.component = Qt.createComponent("Other.qml")
                BWorker.regularMethod();
                BWorker.cppSlot();
            }
        }

        Rectangle {
            width: 360
            height: 360
            Text {
                anchors.centerIn: parent
                text: BWorker.regularMethodWithReturn("john", 25)
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    Qt.quit();
                }
            }
        }
    }
}
