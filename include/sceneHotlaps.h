#ifndef SCENEHOTLAPS_H
#define SCENEHOTLAPS_H

#include "./scenes.h"
#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>

class SceneHotlaps : public QMainWindow {
    Q_OBJECT

public:
    QWidget* get(Scenes *parentScene);
};

#endif // SCENEHOTLAPS_H
