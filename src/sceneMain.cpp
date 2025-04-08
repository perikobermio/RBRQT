#include "./../include/sceneMain.h"
#include "./../include/scene.h"

#include <QApplication>
#include <QDebug>
#include <QLabel>

SceneMain::SceneMain(QWidget *parent) : Scene(parent) {
    QVBoxLayout *layout     = new QVBoxLayout(this);
    listMenu                = new QListWidget(this);

    listMenu->setFixedWidth(this->width() * 0.7);
    listMenu->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    listMenu->setStyleSheet(
        "QListWidget { background: rgba(46, 102, 109, 0.5); margin: 0px; padding: 10px; alignment: left; border-radius: 10px; }"
        "QListWidget::item { padding: 10px; font-size: 18px; font-weight: bold; border-radius: 5px; color: white;}"
        "QListWidget::item:selected { background-color: rgba(24, 54, 58, 0.5); color:rgb(204, 206, 211); }"
        "QListWidget::item:hover { background-color: rgba(30, 70, 75, 0.7); color: rgb(220, 220, 220); }"
        "QListWidget::item:focus { outline: none; }"
        "QListWidget::focus { border: none; outline: none; }"
    );

    QListWidgetItem* hot_laps       = new QListWidgetItem("Hot laps", listMenu);
    QListWidgetItem* tournaments    = new QListWidgetItem("Tournaments", listMenu);
    QListWidgetItem* options        = new QListWidgetItem("Options", listMenu);
    QListWidgetItem* spacerItem     = new QListWidgetItem("", listMenu);
    QListWidgetItem* exitItem       = new QListWidgetItem("Exit", listMenu);
    spacerItem->setFlags(Qt::NoItemFlags); // Make the spacer non-interactive

    QObject::connect(listMenu, &QListWidget::itemClicked, [=](QListWidgetItem* item) {
        if (item == hot_laps) {
            emit sceneChanged("main", "hotlaps");
        }
        if (item == tournaments) {
            
        }
        if (item == options) {
            
        }
        if (item == exitItem) {
            QApplication::quit();
        }
    });
    
    layout->addWidget(listMenu, 0, Qt::AlignLeft);

    this->setLayout(layout);
}

void SceneMain::preSwitch(Scene* origin, Scene* self) {
    Q_UNUSED(origin)
    Q_UNUSED(self)

    this->listMenu->clearSelection();
    this->listMenu->setCurrentItem(nullptr);
}
