import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    function onTrigger() {
        console.log("onTrigger()")
        CPP_Register.setString("Hello!")
        console.log(CPP_Register.getString())
    }

    function onTrigger2() {
        console.log("onTrigger2()")
        CPP_Register.setString("World")
        console.log(CPP_Register.getString())
    }

    Component.onCompleted: {
        // 建立信号和槽的连接
        CPP_Register.tiggerOnce.connect(onTrigger);
        CPP_Register.tiggerOnce.connect(window.onTrigger2);
    }
}
