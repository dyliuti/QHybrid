import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Data Conversion: Basic Types")

    Connections{
        target: CppClass
        onSendInt:{
            console.log("Received int: " + param + " , type is :" + typeof param)
        }

        onSendDouble:{
            console.log("Received double: " + param + " , type is :" + typeof param)
        }

        onSendBoolRealFloat:{
            console.log("Received bool: " + bParam + " , type is :" + typeof bParam)
            console.log("Received real: " + realParam + " , type is :" + typeof realParam)
            console.log("Received float: " + floatParam + " , type is :" + typeof floatParam)
        }

        onSendStringUrl:{
            console.log("Received QString: " + stringParm + " , type is :" + typeof stringParm)
            console.log("Received QUrl: " + urlParam + " , type is :" + typeof urlParam)
        }

        onSendColorFont:{
            console.log("Received QColor: " + colorParm + " , type is :" + typeof colorParm)
            console.log("Received QFont: " + fontParam + " , type is :" + typeof fontParam)
            mRect.color = colorParm
            // fontParam.r
            // fontParam.family   bold
        }

        onSendDate:{
            console.log("Received QDate: " + dateParam + " , type is :" + typeof dateParam)
        }

        onSendPoint:{
            console.log("Received QPoint: " + pointParam + " , type is :" + typeof pointParam)
            console.log("Received QPointF: " + pointfParam + " , type is :" + typeof pointfParam)
        }

        onSendSize:{
            console.log("Received QSize: " + sizeParam + " , type is :" + typeof sizeParam)
            console.log("Received QSizeF: " + sizefParam + " , type is :" + typeof sizefParam)
        }

        onSendRect:{
            console.log("Received QRect: " + rectParam + " , type is :" + typeof rectParam)
            console.log("Received QRectF: " + rectfParam + " , type is :" + typeof rectfParam)
        }

    }

    Rectangle{
        id: mRect
        width: 200
        height: 200
        color: "black"
        radius: 20
    }

    Button{
        id: mButton
        anchors.top: mRect.bottom
        text: "点我"
        onClicked:{
            // Cpp到Qml
            CppClass.cppSlot()
            // QML到Cpp
            CppClass.receivePoint(Qt.point(2, 3))
            CppClass.receiveRect(Qt.rect(4, 4, 8, 8))
        }
    }
}
