#ifndef SCENEMAIN_H
#define SCENEMAIN_H

#include "./scenes.h"
#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>

class SceneMain : public QMainWindow {
    Q_OBJECT

public:
    QWidget* get(Scenes *parentScene);
    void preSwitch();
};

#endif // SCENEMAIN_H
