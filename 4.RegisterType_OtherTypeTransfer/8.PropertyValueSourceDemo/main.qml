import QtQuick 2.11
import QtQuick.Window 2.11
import RandomUtil 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Property Value Souces Demo")

    Rectangle{
        id: mRect
        width: 300
        height: 300
        color: "dodgerblue"
        RandomNumber on radius {
            maxValue: 100
        }
    }
}
