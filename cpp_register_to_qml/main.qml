import QtQuick 2.15
import QtQuick.Window 2.15
import CPPRegister 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    CPPRegister {
        objectName: "cpp_register"
        stringType: "Hello World"
    }
}
