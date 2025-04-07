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

signals:
    void sceneChanged();

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
        QListWidgetItem* hot_laps       = new QListWidgetItem("Hot laps", listMenu);
        QListWidgetItem* tournaments    = new QListWidgetItem("Tournaments", listMenu);
        QListWidgetItem* options        = new QListWidgetItem("Options", listMenu);
        QListWidgetItem* spacerItem     = new QListWidgetItem("", listMenu);
        QListWidgetItem* exitItem       = new QListWidgetItem("Exit", listMenu);
        spacerItem->setFlags(Qt::NoItemFlags); // Make the spacer non-interactive

        QObject::connect(listMenu, &QListWidget::itemClicked, [=](QListWidgetItem* item) {
            listMenu->setCurrentItem(nullptr);

            if (item == hot_laps) {
                parentScene->stack->setCurrentWidget(parentScene->hotlaps->widget);
            }
            if (item == tournaments) {
                emit sceneChanged();
            }
            if (item == options) {
                
            }
            if (item == exitItem) {
                QApplication::quit();
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

#endif // SCENEMAIN_H
