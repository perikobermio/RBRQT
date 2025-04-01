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
    void showPage1();
    void showPage2();
    QWidget* sceneMain();

private:
    QStackedWidget *stack;
    QWidget *page1;
    QWidget *page2;
};

#endif // SCENES_H
