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
        "QListWidget::item:focus { outline: none; }"
        "QListWidget::focus { border: none; outline: none; }"
    );

    //new QListWidgetItem(QIcon(":/src/images/exit.png"), "Option 1", listWidget);
    listWidget->addItem("Hot laps");
    listWidget->addItem("Tournaments");
    listWidget->addItem("Options");
    QListWidgetItem* spacerItem = new QListWidgetItem(listWidget);
    spacerItem->setFlags(spacerItem->flags() & ~Qt::ItemIsSelectable); // Make it non-selectable
    listWidget->addItem("Exit");
    
    layout->addWidget(listWidget, 0, Qt::AlignLeft);
    layout->addWidget(imageLabel, 0, Qt::AlignTop | Qt::AlignHCenter);
        
    // Add a spacer to push the list widget to the left
    layout->addStretch(1);

    window->setLayout(layout);
    window->show();

    return window;
}
