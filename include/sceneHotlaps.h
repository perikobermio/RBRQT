#ifndef SCENEHOTLAPS_H
#define SCENEHOTLAPS_H

#include "./scene.h"
#include <QListWidget>
#include <QVBoxLayout>

class SceneHotlaps : public Scene {
    Q_OBJECT
public:
    explicit SceneHotlaps(QWidget *parent = nullptr);

    void preSwitch(Scene* origin, Scene* destiny) override;

    QListWidget *listWidget;

signals:
    void sceneChanged(QString origin, QString destiny);
    
};

#endif // SCENEHOTLAPS_H
