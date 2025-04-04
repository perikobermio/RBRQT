#ifndef SCENEHOTLAPS_H
#define SCENEHOTLAPS_H

#include "./scenes.h"
#include <QMainWindow>
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
        QListWidget* listWidget = new QListWidget(window);
        listWidget->setFixedWidth(window->width() * 0.7);
        listWidget = parentScene->listPreset(listWidget);

        //new QListWidgetItem(QIcon(":/src/images/exit.png"), "Option 1", listWidget);
        QListWidgetItem* race           = new QListWidgetItem("Race", listWidget);
        QListWidgetItem* car            = new QListWidgetItem("Car", listWidget);
        QListWidgetItem* options        = new QListWidgetItem("Options", listWidget);
        QListWidgetItem* spacerItem     = new QListWidgetItem("", listWidget);
        QListWidgetItem* back           = new QListWidgetItem("Back", listWidget);
        spacerItem->setFlags(Qt::NoItemFlags); // Make the spacer non-interactive

        QObject::connect(listWidget, &QListWidget::itemClicked, [=](QListWidgetItem* item) {
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
        
        layout->addWidget(listWidget, 0, Qt::AlignLeft);
        layout->addWidget(imageLabel, 0, Qt::AlignTop | Qt::AlignHCenter);
            
        // Add a spacer to push the list widget to the left
        layout->addStretch(1);

        window->setLayout(layout);
        window->show();

        return window;
    }
};

#endif // SCENEHOTLAPS_H
