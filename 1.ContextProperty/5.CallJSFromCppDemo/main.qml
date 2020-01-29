import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.4

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("在C++调用JS函数")

    // 函数名已经在Cpp中定义了
    function qmlJSFunction(param){
        console.log("这里是QML，调用我的参数： " + param + "返回结果给Cpp.")
    }

    Button{
        id: mButton
        text: "在C++中调用qml的js函数"
        onClicked:{
            QmlJsCaller.cppMethod("QML Calling...我是参数。")
        }
    }
}

// qml调用cpp方法，然后cpp方法中调用了qml中的JS函数
