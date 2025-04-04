#include "./../include/scene.h"
#include "./../include/scenes.h"
#include "./../include/sceneMain.h"
#include "./../include/sceneHotlaps.h"

#include <iostream>

#include <QWidget>
#include <QDebug>
#include <QListWidget>

Scene::Scene(Scenes *parent, const char* type) : QWidget(parent) {
    type = type;

    if (strcmp(type, "main") == 0) {  
        SceneMain* _widget = new SceneMain(); 
        widget = _widget->get(parent); 
    } else if (strcmp(type, "hotlaps") == 0) {  
        SceneHotlaps* _widget = new SceneHotlaps(); 
        widget = _widget->get(parent); 
    }
}
