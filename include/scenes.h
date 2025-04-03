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

    QStackedWidget *stack;
    QWidget *main;
    QWidget *hotlaps;

    QWidget*        windowPreset();
    QLabel*         bgPreset(QWidget* window);
    QListWidget*    listPreset(QListWidget* list);
    
};

#endif // SCENES_H
