#include "./../include/sceneStats.h"

#include <QDebug>
#include <QLabel>
#include <QListWidget>

SceneStats::SceneStats(QWidget *parent) : Scene(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);  // Importante para evitar dobles márgenes
    layout->setSpacing(10);

    QLabel *label = new QLabel("Stats go here");
    label->setStyleSheet("color: white; font-size: 16px;");
    layout->addWidget(label);
}

void SceneStats::preSwitch(Scene* origin, Scene* self) {
    Q_UNUSED(origin)
    Q_UNUSED(self)

    //this->listMenu->setCurrentItem(this->listMenu->item(0));
}
