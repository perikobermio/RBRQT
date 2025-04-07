#ifndef SCENEHOTLAPS_H
#define SCENEHOTLAPS_H

#include "./scenes.h"
#include <QDebug>
#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>

class SceneHotlaps : public QMainWindow {
    Q_OBJECT

public:

    QWidget* get(Scenes *parentScene) {
        QWidget* window     = parentScene->windowPreset();
        QHBoxLayout* layout = new QHBoxLayout(window);
        QLabel* imageLabel  = parentScene->bgPreset(window);

        // Create the list widget
        QListWidget* listMenu = new QListWidget(window);
        listMenu->setFixedWidth(window->width() * 0.7);
        listMenu = parentScene->listPreset(listMenu);

        //new QListWidgetItem(QIcon(":/src/images/exit.png"), "Option 1", listWidget);
        QListWidgetItem* race           = new QListWidgetItem("Race", listMenu);
        QListWidgetItem* car            = new QListWidgetItem("Car", listMenu);
        QListWidgetItem* options        = new QListWidgetItem("Options", listMenu);
        QListWidgetItem* spacerItem     = new QListWidgetItem("", listMenu);
        QListWidgetItem* back           = new QListWidgetItem("Back", listMenu);
        spacerItem->setFlags(Qt::NoItemFlags); // Make the spacer non-interactive

        QObject::connect(listMenu, &QListWidget::itemClicked, [=](QListWidgetItem* item) {
            if (item == race) {
                
            }
            if (item == car) {
                
            }
            if (item == options) {
                
            }
            if (item == back) {
                parentScene->stack->setCurrentWidget(parentScene->main->widget);
            }
        });
        
        layout->addWidget(listMenu, 0, Qt::AlignLeft);
        layout->addWidget(imageLabel, 0, Qt::AlignTop | Qt::AlignHCenter);
            
        // Add a spacer to push the list widget to the left
        layout->addStretch(1);

        window->setLayout(layout);
        window->show();

        return window;
    }
};

#endif // SCENEHOTLAPS_H
