import QtQuick 2.6
import QtQuick.Controls 1.5

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Html Parse")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    TextField {
        id: txtUrl
        x: 95
        y: 23
        width: 467
        height: 22
        placeholderText: qsTr("Text Field")
    }

    Label {
        id: label1
        x: 29
        y: 26
        text: qsTr("URL:")
    }

    Button {
        id: btGET
        x: 574
        y: 21
        text: qsTr("GET")
        onClicked: {
            txtResult.text = tools.getResult("test.html")
        }
    }

    TextArea {
        id: txtResult
        x: 29
        y: 76
        width: 595
        height: 380
    }
}
