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

private slots:
    void switchScene(QWidget *scene);
    QWidget* sceneMain();

private:
    QStackedWidget *stack;
    QWidget *main;
    QWidget *hotlaps;
};;

#endif // SCENES_H
