#include "./../include/scenemain.h"
#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QListWidget>
#include <QVBoxLayout>


QWidget* scenemain::show() {
    QWidget* window = new QWidget(nullptr);

    window->setStyleSheet("background-image: url(':/src/images/bg.jpeg'); background-repeat: no-repeat; background-position: center;");
    window->showFullScreen();

    // Create and set layout for the window
    QHBoxLayout* layout = new QHBoxLayout(window);

    // Create a QLabel to display the image
    QLabel* imageLabel = new QLabel(window);
    QPixmap pixmap(":/src/images/rbr_logo.png");
    pixmap = pixmap.scaled(500, 500, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    imageLabel->setPixmap(pixmap);
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setStyleSheet("background: transparent;");

    // Create the list widget
    QListWidget* listWidget = new QListWidget(window);
    listWidget->setFixedWidth(window->width() * 0.7);
    listWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    listWidget->setStyleSheet(
        "QListWidget { background: rgba(46, 102, 109, 0.5); margin: 0px; padding: 10px; alignment: left; border-radius: 10px; }"
        "QListWidget::item { padding: 10px; font-size: 18px; font-weight: bold; border-radius: 5px; color: white;}"
        "QListWidget::item:selected { background-color: rgba(24, 54, 58, 0.5); color:rgb(204, 206, 211); }"
        "QListWidget::item:hover { background-color: rgba(30, 70, 75, 0.7); color: rgb(220, 220, 220); }"
        "QListWidget::item:focus { outline: none; }"
        "QListWidget::focus { border: none; outline: none; }"
    );

    //new QListWidgetItem(QIcon(":/src/images/exit.png"), "Option 1", listWidget);
    QListWidgetItem* hot_laps       = new QListWidgetItem("Hot laps", listWidget);
    QListWidgetItem* tournaments    = new QListWidgetItem("Tournaments", listWidget);
    QListWidgetItem* options        = new QListWidgetItem("Options", listWidget);
    QListWidgetItem* spacerItem     = new QListWidgetItem("", listWidget);
    QListWidgetItem* exitItem       = new QListWidgetItem("Exit", listWidget);
    spacerItem->setFlags(Qt::NoItemFlags); // Make the spacer non-interactive

    QObject::connect(listWidget, &QListWidget::itemClicked, [=](QListWidgetItem* item) {
        if (item == exitItem) {
            QApplication::quit();
        }
        if (item == tournaments) {
            QApplication::quit();
        }
        if (item == options) {
            QApplication::quit();
        }
        if (item == hot_laps) {
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
