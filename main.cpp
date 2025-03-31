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
    listWidget->setFixedWidth(window->width() * 0.7);
    listWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    listWidget->setStyleSheet(
        "QListWidget { background: rgba(46, 102, 109, 0.5); margin: 0px; padding: 10px; alignment: left; border-radius: 10px; }"
        "QListWidget::item { padding: 10px; font-size: 16px; border-radius: 5px; color: white;}"
        "QListWidget::item:selected { background-color: rgba(24, 54, 58, 0.5); color: #ECEFF4; }"
        "QListWidget::item:focus { outline: none; }"
        "QListWidget::focus { border: none; outline: none; }"
    );

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
