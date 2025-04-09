#ifndef SCENEMAIN_H
#define SCENEMAIN_H

#include "./scene.h"
#include "./sceneStats.h"
#include "./sceneOptions.h"
#include <QListWidget>
#include <QVBoxLayout>
#include <QStackedLayout>

class SceneMain : public Scene {
    Q_OBJECT
public:
    explicit SceneMain(QWidget *parent = nullptr);

    void preSwitch(Scene* origin, Scene* destiny) override;  // Se ejecuta cuando cambiamos a esta escena

signals:
    void sceneChanged(QString origin, QString destiny);

private:
    QListWidget         *listMenu;
    QWidget             *rightPanel;
    QStackedLayout      *stackLayout;

    SceneStats          *sceneStats;
    SceneOptions        *sceneOptions;
};

#endif // SCENEMAIN_H
