#include "./../include/sceneHotlaps.h"

#include <QDebug>
#include <QLabel>
#include <QListWidget>

SceneHotlaps::SceneHotlaps(QWidget *parent) : Scene(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Create the list widget
    listMenu = new QListWidget(this);
    listMenu->setFixedWidth(this->width() * 0.7);
    listMenu->setStyleSheet(
        "QListWidget { background: rgba(46, 102, 109, 0.5); margin: 0px; padding: 10px; alignment: left; border-radius: 10px; }"
        "QListWidget::item { padding: 10px; font-size: 18px; font-weight: bold; border-radius: 5px; color: white;}"
        "QListWidget::item:selected { background-color: rgba(24, 54, 58, 0.5); color:rgb(204, 206, 211); }"
        "QListWidget::item:hover { background-color: rgba(30, 70, 75, 0.7); color: rgb(220, 220, 220); }"
        "QListWidget::item:focus { outline: none; }"
        "QListWidget::focus { border: none; outline: none; }"
    );

    //new QListWidgetItem(QIcon(":/src/images/exit.png"), "Option 1", listWidget);
    QListWidgetItem* race           = new QListWidgetItem("Race", listMenu);
    QListWidgetItem* car            = new QListWidgetItem("Car", listMenu);
    QListWidgetItem* options        = new QListWidgetItem("Options", listMenu);
    QListWidgetItem* spacerItem     = new QListWidgetItem("", listMenu);
    QListWidgetItem* back           = new QListWidgetItem("Back", listMenu);
    spacerItem->setFlags(Qt::NoItemFlags); // Make the spacer non-interactive

    QObject::connect(listMenu, &QListWidget::itemClicked, [=](QListWidgetItem* item) {

        if (item == race) {
            
        }
        if (item == car) {
            
        }
        if (item == options) {
            
        }
        if (item == back) {
            emit sceneChanged("hotlaps", "main");
        }
    });

    layout->addWidget(listMenu, 0, Qt::AlignLeft);

    setLayout(layout);
}

void SceneHotlaps::preSwitch(Scene* origin, Scene* self) {
    Q_UNUSED(origin)
    Q_UNUSED(self)

    this->listMenu->setCurrentItem(this->listMenu->item(0));
}
