#include <QApplication>
#include "./include/scenemain.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    scenemain scene;
    scene.show();

    return app.exec();
}
