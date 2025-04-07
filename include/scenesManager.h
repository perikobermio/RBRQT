#ifndef SCENESMANAGER_H
#define SCENESMANAGER_H

#include <QStackedWidget>
#include <QMap>
#include "sceneMain.h"
#include "sceneHotlaps.h"

class ScenesManager : public QStackedWidget {
    Q_OBJECT
public:
    explicit ScenesManager(QWidget *parent = nullptr);
    void switchScene(QString origin, QString destiny);

private:
    QMap<QString, Scene*> scenes;
};

#endif // SCENESMANAGER_H
