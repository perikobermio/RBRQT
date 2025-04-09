#ifndef SCENESTATS_H
#define SCENESTATS_H

#include "./scene.h"
#include <QListWidget>
#include <QVBoxLayout>

class SceneStats : public Scene {
    Q_OBJECT
public:
    explicit SceneStats(QWidget *parent = nullptr);

    void preSwitch(Scene* origin, Scene* destiny) override;

signals:
    void sceneChanged(QString origin, QString destiny);
};

#endif // SCENESTATS_H
