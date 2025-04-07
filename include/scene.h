#ifndef SCENE_H
#define SCENE_H

#include <QWidget>
#include <QMap>
#include <QString>
#include <QVariant>

class Scene : public QWidget {
    Q_OBJECT
public:
    explicit Scene(QWidget *parent = nullptr);
    virtual ~Scene() {}
    virtual void preSwitch(Scene* origin, Scene* destiny) = 0;  // Método que se ejecuta al cambiar de escena
};

#endif // SCENE_H
