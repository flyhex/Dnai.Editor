import QtQuick 2.4
import QtQuick.Dialogs 1.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

RowLayout {
    property alias fileDialog: fileDialog
    property alias chooseBtn: chooseBtn
    property alias uploadBtn: uploadBtn
    property alias filesModel: filesModel

    width: 500
    height: 100
    anchors.leftMargin: 20
    anchors.rightMargin: 20

    FileDialog {
        id: fileDialog
        title: "Please choose a project"
        selectMultiple: true
        nameFilters: ["DNAI project (*.dnaisolution)"]
    }

    ListModel {
        id: filesModel
    }

    Button {
        id: chooseBtn
        text: qsTr("Choose")
    }

    ScrollView {
        padding: 10
        Layout.fillHeight: true
        Layout.fillWidth: true
        ListView {
            Layout.fillWidth: true
            spacing: 4
            Layout.fillHeight: true
            model: filesModel
            clip: true
            delegate: Text {
                text: filename
            }
        }
    }

    Button {
        id: uploadBtn
        text: qsTr("Upload")
        padding: 6
        Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
    }
}
