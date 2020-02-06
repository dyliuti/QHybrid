import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.11
import QtQuick.Dialogs 1.3
import com.dyliuti.models 1.0

Window {
    visible: true
    width: 400
    height: 600
    minimumWidth: 400
    minimumHeight: 600
    title: qsTr("Hello World")

    /* 在QML中初始化自定义Cpp类的model */
    PersonModel{
        id : mModeId
        Person{
            names: "Steve Barker"
            favoriteColor: "blue"
            age : 34
        }
        Person{
            names: "John Snow"
            favoriteColor: "yellow"
            age : 33
        }
        Person{
            names: "Daniel Gakwaya"
            favoriteColor: "green"
            age : 23
        }

        /*
        persons: [
            Person{
                names: "Daniel Gakwaya"
                favoriteColor: "yellow"
                age : 34
            },
            Person{
                names: "Gwiza Luna"
                favoriteColor: "blue"
                age : 1
            },
            Person{
                names: "Steve Barker"
                favoriteColor: "yellowgreen"
                age : 22
            }
        ]
        */
    }


    ColumnLayout{
        anchors.fill: parent
        ListView{
            id : mListView
            Layout.fillWidth: true
            Layout.fillHeight: true

            model : mModeId
            delegate: Rectangle {
                height: 90
                radius: 10
                color : "gray"
                border.color: "cyan"
                width: parent.width
                RowLayout{
                    anchors.fill: parent
                    anchors.margins: 20

                    TextField{
                        text : names
                        Layout.fillWidth: true
                        onEditingFinished: {
                            console.log("Editing finished, new text is :"+ text + " at index :" + index)
                            model.names = text

                        }
                    }

                    SpinBox{
                        id : mSpinbox
                        editable: true
                        Layout.fillWidth: true
                        onValueChanged: {
                            model.age = value;
                        }
                        Component.onCompleted: {
                            mSpinbox.value = model.age
                        }
                    }
                    Rectangle{
                        width : 50
                        height: 50
                        color: model.favoriteColor
                        MouseArea{
                            anchors.fill: parent
                            ColorDialog{
                                id: colorDialog
                                title: "Please choose a color"
                                onAccepted: {
                                    console.log("You chose: " + colorDialog.color)
                                    model.favoriteColor = color
                                }
                                onRejected: {
                                    console.log("Canceled")
                                }
                            }

                            onClicked: {
                                colorDialog.open()
                            }
                        }
                    }
                }
            }
        }

        RowLayout{
            width : parent.width

            Button{
                Layout.fillWidth: true
                height: 50
                text : "Add Person";
                onClicked: {
                    input.openDialog()
                }
                InputDialog{
                    id : input
                    onInputDialogAccepted: {
                        console.log("Here in main, dialog accepted");
                        console.log( " names : " + personNames + " age :" + personAge)
                        mModeId.addPerson(personNames,"yellowgreen",personAge)
                    }
                }

            }
            Button{
                Layout.fillWidth: true
                height: 50
                text : "Remove Last";
                onClicked: {
                    mModeId.removeLastItem()
                }
            }
        }
    }

}
