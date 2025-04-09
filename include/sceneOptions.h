#ifndef SCENEOPTIONS_H
#define SCENEOPTIONS_H

#include "./scene.h"
#include <QListWidget>
#include <QVBoxLayout>

class SceneOptions : public Scene {
    Q_OBJECT
public:
    explicit SceneOptions(QWidget *parent = nullptr);

    void preSwitch(Scene* origin, Scene* destiny) override;

signals:
    void sceneChanged(QString origin, QString destiny);
};

#endif // SCENEOPTIONS_H
