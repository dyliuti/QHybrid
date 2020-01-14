import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.2
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Sequence2ArrayDemo")


    Button{
        id: mButton1
        text: "Send to C++"
        onClicked: {
            var arr = ['Apple', "Banana", "Avocado", 'Pear']
            CppClass.qmlArrayToCPP(arr)
        }
    }

    Button{
        id: mButton2
        anchors.top: mButton1.bottom
        text: "Read form Cpp"
        onClicked: {
            var arr = CppClass.retrieveStrings()
            print("The length is :" + arr.length)

            // 遍历qml中的arr
            arr.forEach(function(element){
                console.log(element)
            })
        }
    }
}
