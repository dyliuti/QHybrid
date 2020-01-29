import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.11
import QtQuick.Dialogs 1.3

Window {
    visible: true
    width: 400
    height: 600
    minimumWidth: 400
    minimumHeight: 600
    title: qsTr("Hello World")


    ColumnLayout{
        anchors.fill: parent
        ListView{
            id : mListView
            Layout.fillWidth: true
            Layout.fillHeight: true

            model : myModel
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
                        /* 区别在这里 */
                        myDataSource.addPerson(personNames, personAge)
                    }
                }
            }
            Button{
                Layout.fillWidth: true
                height: 50
                text : "Remove Last";
                onClicked: {
                    /* 区别在这里 */
                    myDataSource.removeLastPerson()
                }
            }
        }
    }

}
