#include "./../include/sceneMain.h"
#include "./../include/sceneStats.h"
#include "./../include/scene.h"

#include <QApplication>
#include <QDebug>
#include <QLabel>

SceneMain::SceneMain(QWidget *parent) : Scene(parent) {
    QHBoxLayout *layout     = new QHBoxLayout(this);
    listMenu                = new QListWidget(this);
    rightPanel              = new QWidget(this);

    rightPanel->setStyleSheet(
        "background: rgba(33, 38, 39, 0.5); margin: 0 0 0 20px; alignment: left; border-radius: 10px;"
    );

    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    listMenu->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    listMenu->setStyleSheet(
        "QListWidget { background: rgba(46, 102, 109, 0.5); margin: 0px; padding: 10px; alignment: left; border-radius: 10px; }"
        "QListWidget::item { padding: 10px; font-size: 18px; font-weight: bold; border-radius: 5px; color: white;}"
        "QListWidget::item:selected { background-color: rgba(24, 54, 58, 0.5); color:rgb(204, 206, 211); }"
        "QListWidget::item:hover { background-color: rgba(30, 70, 75, 0.7); color: rgb(220, 220, 220); }"
        "QListWidget::item:focus { outline: none; }"
        "QListWidget::focus { border: none; outline: none; }"
    );

    QListWidgetItem* hot_laps       = new QListWidgetItem("Hot laps", listMenu);
    QListWidgetItem* tournaments    = new QListWidgetItem("Tournaments", listMenu);
    QListWidgetItem* stats          = new QListWidgetItem("Stats", listMenu);
    QListWidgetItem* options        = new QListWidgetItem("Options", listMenu);
    QListWidgetItem* spacerItem     = new QListWidgetItem("", listMenu);
    QListWidgetItem* exitItem       = new QListWidgetItem("Exit", listMenu);
    spacerItem->setFlags(Qt::NoItemFlags); // Make the spacer non-interactive

    
    stackLayout     = new QStackedLayout(rightPanel);
    rightPanel->setLayout(stackLayout);

    sceneStats      = new SceneStats();
    sceneOptions    = new SceneOptions();

    stackLayout->addWidget(new QWidget());
    stackLayout->addWidget(sceneStats);
    stackLayout->addWidget(sceneOptions);

    layout->addWidget(listMenu, 1);
    layout->addWidget(rightPanel, 4);

    this->setLayout(layout);

    QObject::connect(listMenu, &QListWidget::itemClicked, [=](QListWidgetItem* item) {
        if (item == hot_laps) {
            emit sceneChanged("main", "hotlaps");
        }
        if (item == tournaments) {
            
        }
        if (item == stats) {
            stackLayout->setCurrentWidget(sceneStats);
        }
        if (item == options) {
            stackLayout->setCurrentWidget(sceneOptions);
        }
        if (item == exitItem) {
            QApplication::quit();
        }
    });
}

void SceneMain::preSwitch(Scene* origin, Scene* self) {
    Q_UNUSED(origin)
    Q_UNUSED(self)

    this->listMenu->clearSelection();
    this->listMenu->setCurrentItem(nullptr);
}
