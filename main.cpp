#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QListWidget>
#include <QVBoxLayout>


QWidget* scene_main([[maybe_unused]] QApplication& app) {
    QWidget* window = new QWidget(nullptr);

    window->setStyleSheet("background-image: url(':/src/images/bg.jpeg'); background-repeat: no-repeat; background-position: center;");
    window->showFullScreen();

    // Create and set layout for the window
    QHBoxLayout* layout = new QHBoxLayout(window);

    // Create the list widget
    QListWidget* listWidget = new QListWidget(window);
    listWidget->setStyleSheet("background: rgba(46, 102, 109, 0.5); margin: 0px; padding: 10px; alignment: left; border-radius: 10px;");
    listWidget->setFixedWidth(window->width() * 0.7);
    listWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

    QListWidgetItem* item1 = new QListWidgetItem("Option 1");
    item1->setTextAlignment(Qt::AlignCenter);
    item1->setBackground(QColor(46, 102, 109, 128)); // Semi-transparent background
    item1->setForeground(Qt::white); // Text color
    
    listWidget->addItem(item1);
    listWidget->addItem("Option 2");
    listWidget->addItem("Option 3");
    listWidget->addItem("Option 4");
    listWidget->addItem("Option 5");
    layout->addWidget(listWidget, 0, Qt::AlignLeft);
        
    // Add a spacer to push the list widget to the left
    layout->addStretch(1);

    window->setLayout(layout);
    window->show();

    return window;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    scene_main(app);

    return app.exec();
}
