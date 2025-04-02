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
    SceneMain(QWidget *parent = nullptr);

    QWidget* get(Scenes *parentScene);
};

#endif // SCENEMAIN_H
