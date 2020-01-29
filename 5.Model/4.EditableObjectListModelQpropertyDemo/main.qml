import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.11

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ListView{
        id : mListView
        anchors.fill: parent
        model : Wrapper.mypersons
        delegate: Rectangle {
            height: 90
            radius: 10
//            color : favoriteColor
//            color : model.modelData.favoriteColor
//            color : model.favoriteColor
//            color : modelData.favoriteColor
            color : "gray"
            border.color: "cyan"
            width: parent.width
            RowLayout{
                anchors.fill: parent
                anchors.margins: 20
                TextField{
                    // text : names
                    // text : modelData.names
                    // 其实加上前缀1.便于阅读，知道从哪里来；2.属性名重复时可分辨
                    text : modelData.names
                    Layout.fillWidth: true
                    onEditingFinished: {
                        Wrapper.setNames(index,text)
                    }
                }
                SpinBox{
                    editable: true
                    //value : age //
                    value : modelData.age
                    Layout.fillWidth: true
                    onValueChanged: {
                        if( value === model.age){

                        }
                        else{
                            Wrapper.setAge(index,value)
                        }
                    }
                }
                Rectangle{
                    width : 50
                    height: 50
                    // color: model.modelData.favoriteColor
                    // color: modelData.favoriteColor
                    // 下面这种形式只对于在qml中定义的model起作用
                    color: modelData.favoriteColor
                }
            }
        }
    }

    Button{
        id : mButton
        width: parent.width
        anchors.bottom: parent.bottom
        height: 50
        text : "Add Person"
        onClicked: {
            Wrapper.addPerson()
        }
    }
}
