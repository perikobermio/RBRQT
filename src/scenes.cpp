#include "./../include/scenes.h"
#include "./../include/sceneMain.h"

#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QListWidget>
#include <QVBoxLayout>

Scenes::Scenes(QWidget *parent) : QMainWindow(parent) {
    stack = new QStackedWidget(this);
    showFullScreen();

    // --- Page 1 ---
    main = sceneMain(this);
    
    // --- Page 2 ---
    hotlaps = new QWidget();
    QPushButton *btnGoToPage1 = new QPushButton("Go to Page 1");
    QVBoxLayout *layout2 = new QVBoxLayout(hotlaps);
    layout2->addWidget(btnGoToPage1);

    // Add pages to stack
    stack->addWidget(main);
    stack->addWidget(hotlaps);

    // Set the stack as the main widget
    setCentralWidget(stack);

    // --- Connect buttons ---
    connect(btnGoToPage1, &QPushButton::clicked, this, [=]() { switchScene(main); });
}

Scenes::~Scenes() {}

void Scenes::switchScene(QWidget *scene) {
    stack->setCurrentWidget(scene);
}