#include "./../include/scenes.h"
#include "./../include/sceneMain.h"
#include "./../include/sceneHotlaps.h"

#include <iostream>
#include <QWidget>
#include <QLabel>
#include <QListWidget>

Scenes::Scenes(QWidget *parent) : QMainWindow(parent) {
    stack = new QStackedWidget(this);
    showFullScreen();

    SceneMain       SceneMain;
    SceneHotlaps    SceneHotlaps;

    main            = SceneMain.get(this);
    hotlaps         = SceneHotlaps.get(this);

    stack->addWidget(main);
    stack->addWidget(hotlaps);

    setCentralWidget(stack);
}

Scenes::~Scenes() {}

////////////////////////////////////////////////////////////////////

QWidget* Scenes::windowPreset() {
    QWidget* window = new QWidget(nullptr);
    window->setStyleSheet("background-image: url(':/src/images/bg.jpeg'); background-repeat: no-repeat; background-position: center;");

    return window;
}

QLabel* Scenes::bgPreset(QWidget* window) {
    QLabel* imageLabel = new QLabel(window);
    QPixmap pixmap(":/src/images/rbr_logo.png");
    pixmap = pixmap.scaled(500, 500, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    imageLabel->setPixmap(pixmap);
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setStyleSheet("background: transparent;");

    return imageLabel;
}

QListWidget* Scenes::listPreset(QListWidget* list) {
    list->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    list->setStyleSheet(
        "QListWidget { background: rgba(46, 102, 109, 0.5); margin: 0px; padding: 10px; alignment: left; border-radius: 10px; }"
        "QListWidget::item { padding: 10px; font-size: 18px; font-weight: bold; border-radius: 5px; color: white;}"
        "QListWidget::item:selected { background-color: rgba(24, 54, 58, 0.5); color:rgb(204, 206, 211); }"
        "QListWidget::item:hover { background-color: rgba(30, 70, 75, 0.7); color: rgb(220, 220, 220); }"
        "QListWidget::item:focus { outline: none; }"
        "QListWidget::focus { border: none; outline: none; }"
    );
    return list;
}