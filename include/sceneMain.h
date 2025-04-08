#ifndef SCENEMAIN_H
#define SCENEMAIN_H

#include "./scene.h"
#include <QListWidget>
#include <QVBoxLayout>

class SceneMain : public Scene {
    Q_OBJECT
public:
    explicit SceneMain(QWidget *parent = nullptr);

    void preSwitch(Scene* origin, Scene* destiny) override;  // Se ejecuta cuando cambiamos a esta escena

signals:
    void sceneChanged(QString origin, QString destiny);

private:
    QListWidget *listMenu;
};

#endif // SCENEMAIN_H
