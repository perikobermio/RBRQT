#include <QApplication>
#include "./include/scenesManager.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ScenesManager scene;
    scene.show();

    scene.showFullScreen();

    app.exec();
    return 0;
}
