import QtQuick 2.11
import QtQuick.Window 2.11
import com.dyliuti.errorlevel 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Enum demo")

    Component.onCompleted: {
        console.log(ErrorLevel.DEBUG);
    }
}
