import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.2
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("QVariantList and map")

    function arrayObjectFunc(array, object){
        console.log("----Printing array------")
        array.forEach(function(element){
            console.log("Array item :" + element)
        })

        console.log("----Printing object------")
        for(var mKey in object){
            console.log("Object[" + mKey + "] :" + object[mKey])
        }
    }

    Button{
        id: button1
        text: "Pass data to Cpp"
        onClicked:{
            var arr = ['Africa', 'Asia', 'Europe']
            var obj = {
                firstName: "John",
                lastName: "Doe",
                location: "Earth"
            }

            CppClass.passFromQmlToCpp(arr, obj)
        }
    }

    Button{
        id: button2
        anchors.top: button1.bottom
        text: "GetVariantListFromCpp"
        onClicked:{
            var arr = CppClass.getVariantListFromCpp()
            arr.forEach(function(element){
                console.log("Array item :" + element)
            })
        }
    }

    Button{
        id: button3
        anchors.top: button2.bottom
        text: "GetVariantMapFromCpp"
        onClicked:{
            var map_obj = CppClass.getVariantMapFromCpp()
            for(var mKey in map_obj){
                console.log("Object[" + mKey + "] :" + map_obj[mKey])
            }
        }
    }

    Button{
        id: button4
        anchors.top: button3.bottom
        text: "TriggerJSCall"
        onClicked:{
            CppClass.triggerJSCall();
        }
    }
}
