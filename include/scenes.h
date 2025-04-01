#ifndef SCENES_H
#define SCENES_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class Scenes : public QMainWindow {
    Q_OBJECT

public:
    Scenes(QWidget *parent = nullptr);
    ~Scenes();

    QWidget *main;
    QWidget *hotlaps;
    void switchScene(QWidget *scene);

private:
    QStackedWidget *stack;
};

#endif // SCENES_H
