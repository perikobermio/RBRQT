#include <QApplication>
#include "./include/scenes.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Scenes scene;
    scene.show();

    app.exec();
    return 0;
}
