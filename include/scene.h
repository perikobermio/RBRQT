#ifndef SCENE_H
#define SCENE_H

#include <QWidget>

class Scenes;
class Scene : public QWidget {
    Q_OBJECT

public:
    Scene(Scenes *parent = nullptr, const char* type = "main");

    QWidget*    widget = nullptr;
    QWidget*    get(Scenes *parent);
    char*       type = nullptr;
    int lala = 88;
    
};

#endif // SCENE_H
