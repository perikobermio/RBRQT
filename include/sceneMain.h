#ifndef SCENEMAIN_H
#define SCENEMAIN_H

#include "./scenes.h"
#include <QDebug>
#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>

class SceneMain : public QMainWindow {
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
        QListWidgetItem* hot_laps       = new QListWidgetItem("Hot laps", listWidget);
        QListWidgetItem* tournaments    = new QListWidgetItem("Tournaments", listWidget);
        QListWidgetItem* options        = new QListWidgetItem("Options", listWidget);
        QListWidgetItem* spacerItem     = new QListWidgetItem("", listWidget);
        QListWidgetItem* exitItem       = new QListWidgetItem("Exit", listWidget);
        spacerItem->setFlags(Qt::NoItemFlags); // Make the spacer non-interactive

        QObject::connect(listWidget, &QListWidget::itemClicked, [=](QListWidgetItem* item) {
            if (item == hot_laps) {
                parentScene->stack->setCurrentWidget(parentScene->hotlaps->widget);
            }
            if (item == tournaments) {
                
            }
            if (item == options) {
                
            }
            if (item == exitItem) {
                QApplication::quit();
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

#endif // SCENEMAIN_H
