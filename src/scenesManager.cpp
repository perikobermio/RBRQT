#include "./../include/scenesManager.h"

#include <QDebug>

ScenesManager::ScenesManager(QWidget *parent) : QStackedWidget(parent) {
    
    showFullScreen();

    this->setStyleSheet(
            "background-image: url(':/src/images/bg.jpeg');"
            "background-repeat: no-repeat;"
            "background-position: center;"
    );

    SceneMain *sceneMain        = new SceneMain();
    SceneHotlaps *sceneHotlaps  = new SceneHotlaps();

    scenes["main"]              = sceneMain;
    scenes["hotlaps"]           = sceneHotlaps;

    addWidget(sceneMain);
    addWidget(sceneHotlaps);

    connect(sceneMain, &SceneMain::sceneChanged, this, &ScenesManager::switchScene);
    connect(sceneHotlaps, &SceneHotlaps::sceneChanged, this, &ScenesManager::switchScene);

    setCurrentWidget(sceneMain);
}

void ScenesManager::switchScene(QString origin, QString destiny) {
    if (scenes.contains(origin) && scenes.contains(destiny)) {
        Scene *prevScene = scenes[origin];
        Scene *nextScene = scenes[destiny];
        nextScene->preSwitch(prevScene, nextScene);
        setCurrentWidget(nextScene);
    }
}
