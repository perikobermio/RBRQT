#include <QApplication>
#include <QWidget>
#include <QLabel>

QWidget* scene_main(QWidget* parent = nullptr) {
    QWidget* window = new QWidget(parent);

    window->setStyleSheet("background-image: url(':/src/images/bg.jpeg'); background-repeat: no-repeat; background-position: center;");
    window->showFullScreen();

    return window;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    QWidget* window = scene_main();
    window->show();

    return app.exec();
}
