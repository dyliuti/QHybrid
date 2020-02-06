import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.3

Window {
    visible: true
    width: 640
    height: 480
    objectName: "ROOT OBJECT"
    title: qsTr("Hello World")

    signal qmlSignal(string value, variant mVar);

    QtObject{
        id : mPayload
        property string mProp: "QML payload data"
    }

    Button{
        id : mButton;
        text : "Button1"
        objectName: "button1"

        onClicked: {
            // emit the signal
            qmlSignal("QML parameter",mPayload)
        }
    }
}
