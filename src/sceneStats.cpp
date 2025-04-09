#include "./../include/sceneStats.h"

#include <QDebug>
#include <QLabel>
#include <QListWidget>

SceneStats::SceneStats(QWidget *parent) : Scene(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel("Stats go here", this);
    label->setStyleSheet("color: white;");
    layout->addWidget(label);
    this->setLayout(layout);
}

void SceneStats::preSwitch(Scene* origin, Scene* self) {
    Q_UNUSED(origin)
    Q_UNUSED(self)

    //this->listMenu->setCurrentItem(this->listMenu->item(0));
}
