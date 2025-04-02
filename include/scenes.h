#ifndef SCENES_H
#define SCENES_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QListWidget>

class Scenes : public QMainWindow {
    Q_OBJECT

public:
    Scenes(QWidget *parent = nullptr);
    ~Scenes();

    QWidget *main;
    QWidget *hotlaps;
    void switchScene(QWidget *scene);

    QWidget*        windowPreset();
    QLabel*         bgPreset(QWidget* window);
    QListWidget*    listPreset(QListWidget* list);

private:
    QStackedWidget *stack;
};;

#endif // SCENES_H
