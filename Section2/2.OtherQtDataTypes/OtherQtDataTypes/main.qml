import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("String, Date, Time")

    property string mValue: "Clicked %1 times, double is %2"
    property int clickCount: 0

    Connections{
        target: CppClass

        onSendDateTime:{
            console.log("Qml: Received datatime: ", dateTimeParam)
            console.log("Qml: Year: ", dateTimeParam.getFullYear())
            console.log("Qml: ....", dateTimeParam.toGMTString())
        }

        onSendTime:{
            console.log("Qml: Received time: ", timeParam)
        }
    }

    Button{
        id: mButton
        text: "点我"
        onClicked:{
            // QML调用cpp方法，然后接受这方法中发出的信号
            // CppClass.cppSlot()

            // QML传参数到Cpp
            var date = new Date()   // 当前时间
            CppClass.timeSlot(date);
            CppClass.dateTimeSlot(date);

            clickCount++
            mButton.text = mValue.arg(clickCount).arg(clickCount * 2)
        }
    }

    Component.objectName: {
        var mDate = new Date()
        // 1.toLocaleString(only contains date)
        print(mDate.toLocaleDateString())
        print(mDate.toLocaleDateString(Qt.locale("ja_JA"))) // 不同语言显示日期 日语
        print(mDate.toLocaleDateString(Qt.locale("zh_CN"), "yyyy-MMMM-dd")) // 不同字母个数代表不同data formating

        // 2.toLocaleString(contains date and time)
        print(mDate.toLocaleString(Qt.locale("en_US"), "yyyy-MMMM-dd --HH:mm:ss"))

        // 3.toLocaleTimeString(only contains time)
        print(mDate.toLocaleString(Qt.locale("en_US"), "HH:mm:ss"))

        // 4.fromLocaleDateString
        // 2020-01-14
        // yyy-MM-dd--HH:mm:ss ,    locale: zh_CN
        var myDate = Date.fromLocaleDateString(Qt.locale("zh_CN"), "2020-九月-14", "yyyy-MMMM-dd")  // 多出连个MM
        print("Date is : " + myDate)
        var myCNDate = Date.fromLocaleDateString(Qt.locale("zh_CN"), "2020-01-14", "yyyy-MM-dd")
        print("China Date is : " + myCNDate)

        // 5.fromLocaleString
        myDate = Date.fromLocaleString(Qt.locale("en_US"), "2020-01-14 --01:17:30", "yyyy-MM-dd --HH:mm:ss")
        print("DateTime is : " + myDate)

        // 6.fromLocaleTimeString
        myDate = Date.fromLocaleTimeString(Qt.locale("en_US"), "01:17:30", "HH:mm:ss")
        print("Time is : " + myDate)

        // 7.数值转换为时间
        var mLocale = Qt.locale("de_DE")    // 可以改变语言显示,德语支持下面显示
        var d = Number.fromLocaleString(mLocale, "1234,56")
        print("d is : " + d)
        //d = Number.fromLocaleString(mLocale, "1234.56")    // 错误格式
        //print("d is : " + d)
        d = Number.fromLocaleString(mLocale, "1.234,56")    // 注意逗号、点
        print("d is : " + d)

        // 7.Currency output 货币输出
        mLocale = Qt.locale("en_US")
        var number = Number("123.00")
        var outStr = number.toLocaleCurrencyString(mLocale, mLocale.currencySymbol(Locale.CurrencySymbol))
        print("currenty is: " + outStr)

        // 8.精度位
        mLocale = Qt.locale("en_US")
        var numberPrecison = Number("123.00")
        outStr = numberPrecison.toLocaleString(mLocale, 'f', 4)
        print("precision number is: " + outStr)
    }
}
