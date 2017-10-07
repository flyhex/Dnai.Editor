import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.2
import QtQuick.Dialogs 1.2
import QtCharts 2.2
import CustomGeometry 1.0

import "Resources/Components"

ApplicationWindow {


    visible: true
    width: 1280
    height: 720
    minimumHeight: 150
    minimumWidth: 300
    title: qsTr("Duly")
    Material.theme: Material.Dark
    Material.accent: Material.color(Material.DeepOrange, Material.Shade400)
    property double factor : 1.5
    id: root
    property ApplicationWindow appWindow : root
    property ToolBarHeader toolBarHeader: toolBar

    header: ToolBarHeader {
        id: toolBar
    }

    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        onWheel: {
            if (wheel.modifiers & Qt.ControlModifier) {
                canvas.scaleFactor += 0.1 * wheel.angleDelta.y / 120;
            }
        }
        onClicked: {
            if (mouse.button === Qt.RightButton)
            {
                contextMenu.open()
                contextMenu.x = mouseX;
                contextMenu.y = mouseY;
            }
        }
        Menu {
            id: contextMenu
            Label {
                text: "Create node"
                horizontalAlignment: Text.AlignHCenter
            }
            MenuSeparator {}
            MenuItem {
                text: "Operations"
                hoverEnabled: true
                onHoveredChanged: {
                    if (hovered)
                    {
                        ope.open()
                        func.close()
                        if (contextMenu.width + contextMenu.x + ope.width < root.width)
                        {
                            ope.x = contextMenu.width
                        }
                        else if (contextMenu.width + contextMenu.x + ope.width > root.width)
                        {
                            ope.x = -contextMenu.width
                        }
                    }
                }
                Label {
                    text: "►"
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.rightMargin: 15
                }

                Menu {
                    id: ope
                    title: "Operations"
                    MenuItem {
                        id: add
                        text: "Add"
                    }
                    MenuItem {
                        text: "Substract"
                    }
                    MenuItem {
                        text: "Multiply"
                    }
                    MenuItem {
                        text: "Divide"
                    }
                }
            }
            MenuItem {
                text: "Functions"
                hoverEnabled: true
                onHoveredChanged: {
                    if (hovered)
                    {
                        func.open()
                        ope.close()
                        if (contextMenu.width + contextMenu.x + func.width < root.width)
                        {
                            func.x = contextMenu.width
                        }
                        else if (contextMenu.width + contextMenu.x + func.width > root.width)
                        {
                            func.x = -contextMenu.width
                        }
                    }
                }
                Label {
                    text: "►"
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.rightMargin: 15
                }

                Menu {
                    id: func
                    MenuItem {
                        text: "Path finding"
                    }
                    MenuItem {
                        text: "Obstacle detection"
                    }
                    MenuItem {
                        text: "Alpha Go"
                    }
                    MenuItem {
                        text: "Open AI"
                    }
                }
            }
        }
    }

    DulyCanvas {
        id: canvas
        width: root.width
        height: root.height - toolBar.heightButton
        y: toolBar.heightButton
        gridStep: 15
        gridColor: toolBar.menuEditRef.settingRef.themeTabRef.gridColorRef.colorSetting
        accentGridStep: 150
        accentGridColor: toolBar.menuEditRef.settingRef.themeTabRef.accentGridColorRef.colorSetting
        backgroundColor: toolBar.menuEditRef.settingRef.themeTabRef.backgroudColorRef.colorSetting

//        Flow {
//            radius: 100
//            borderWidth: 15
//            x: parent.width / 2
//            y: parent.height / 2
//        }

        AddNode {
           x: 700
           y: 500
        }

        AddNode {
           x: 200
           y: 200
        }

        AddNode {
           x: 200
           y: 400
        }
    }

}
