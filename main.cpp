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
    QVBoxLayout* layout = new QVBoxLayout(window);

    // Create a transparent widget with 100% height and 20% width
    QWidget* transparentWidget = new QWidget(window);
    transparentWidget->setStyleSheet("background: rgba(46, 102, 109, 0.5); margin: 0px; padding: 0px;");
    transparentWidget->setFixedWidth(window->width() * 0.5);
    transparentWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

    // Add items to the list widget
    QListWidget *listWidget = new QListWidget();
    listWidget->addItem("🚀 Option 1");
    listWidget->addItem("🔥 Option 2");
    listWidget->addItem("💡 Option 3");
    listWidget->addItem("🌟 Option 4");
    listWidget->addItem("⚡ Option 5");

    // Create a layout for the transparent widget
    QVBoxLayout* transparentLayout = new QVBoxLayout(transparentWidget);
    //transparentLayout->setContentsMargins(0, 0, 0, 0);

    // Add the list widget to the transparent layout
    transparentLayout->addWidget(listWidget);

    // Add the transparent widget to the main layout
    layout->addWidget(transparentWidget);

    window->setLayout(layout);
    window->show();

    return window;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    scene_main(app);

    return app.exec();
}
