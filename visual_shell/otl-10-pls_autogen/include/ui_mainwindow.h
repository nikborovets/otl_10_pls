/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_open;
    QAction *action_save;
    QAction *actionSave_as;
    QAction *action_print;
    QAction *action_settings;
    QAction *action_next;
    QAction *action_back;
    QAction *actionGuide;
    QAction *action_remove;
    QWidget *centralwidget;
    QGridLayout *gridLayout_5;
    QGraphicsView *graphics_view;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuRun;
    QMenu *menuTools;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QDockWidget *InformationBoard;
    QWidget *dockWidgetContents_4;
    QGridLayout *gridLayout_2;
    QTreeWidget *tree_widget;
    QPushButton *add_pattern;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1396, 992);
        action_open = new QAction(MainWindow);
        action_open->setObjectName(QString::fromUtf8("action_open"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/tools/image/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_open->setIcon(icon);
        action_save = new QAction(MainWindow);
        action_save->setObjectName(QString::fromUtf8("action_save"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/tools/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_save->setIcon(icon1);
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionSave_as->setIcon(icon1);
        action_print = new QAction(MainWindow);
        action_print->setObjectName(QString::fromUtf8("action_print"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/tools/image/print.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_print->setIcon(icon2);
        action_settings = new QAction(MainWindow);
        action_settings->setObjectName(QString::fromUtf8("action_settings"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/tools/image/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_settings->setIcon(icon3);
        action_next = new QAction(MainWindow);
        action_next->setObjectName(QString::fromUtf8("action_next"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/tools/image/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_next->setIcon(icon4);
        action_back = new QAction(MainWindow);
        action_back->setObjectName(QString::fromUtf8("action_back"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/tools/image/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_back->setIcon(icon5);
        actionGuide = new QAction(MainWindow);
        actionGuide->setObjectName(QString::fromUtf8("actionGuide"));
        action_remove = new QAction(MainWindow);
        action_remove->setObjectName(QString::fromUtf8("action_remove"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/tools/image/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_remove->setIcon(icon6);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        gridLayout_5 = new QGridLayout(centralwidget);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        graphics_view = new QGraphicsView(centralwidget);
        graphics_view->setObjectName(QString::fromUtf8("graphics_view"));

        gridLayout_5->addWidget(graphics_view, 0, 0, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_5->addWidget(pushButton, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1396, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuRun = new QMenu(menubar);
        menuRun->setObjectName(QString::fromUtf8("menuRun"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        InformationBoard = new QDockWidget(MainWindow);
        InformationBoard->setObjectName(QString::fromUtf8("InformationBoard"));
        InformationBoard->setMinimumSize(QSize(373, 836));
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QString::fromUtf8("dockWidgetContents_4"));
        gridLayout_2 = new QGridLayout(dockWidgetContents_4);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tree_widget = new QTreeWidget(dockWidgetContents_4);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(tree_widget);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(tree_widget);
        tree_widget->setObjectName(QString::fromUtf8("tree_widget"));
        tree_widget->setMinimumSize(QSize(0, 768));

        gridLayout_2->addWidget(tree_widget, 0, 0, 1, 1);

        add_pattern = new QPushButton(dockWidgetContents_4);
        add_pattern->setObjectName(QString::fromUtf8("add_pattern"));

        gridLayout_2->addWidget(add_pattern, 1, 0, 1, 1);

        InformationBoard->setWidget(dockWidgetContents_4);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), InformationBoard);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuRun->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(action_open);
        menuFile->addAction(action_save);
        menuFile->addAction(actionSave_as);
        menuFile->addAction(action_print);
        menuEdit->addAction(action_next);
        menuEdit->addAction(action_back);
        menuTools->addAction(action_settings);
        menuTools->addAction(action_remove);
        menuHelp->addAction(actionGuide);
        toolBar->addAction(action_open);
        toolBar->addAction(action_save);
        toolBar->addAction(action_print);
        toolBar->addAction(action_back);
        toolBar->addAction(action_next);
        toolBar->addAction(action_settings);
        toolBar->addAction(action_remove);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        action_open->setText(QApplication::translate("MainWindow", "Open", nullptr));
        action_save->setText(QApplication::translate("MainWindow", "Save", nullptr));
        actionSave_as->setText(QApplication::translate("MainWindow", "Save as", nullptr));
        action_print->setText(QApplication::translate("MainWindow", "Print", nullptr));
        action_settings->setText(QApplication::translate("MainWindow", "Settings", nullptr));
        action_next->setText(QApplication::translate("MainWindow", "Next", nullptr));
        action_back->setText(QApplication::translate("MainWindow", "Back", nullptr));
        actionGuide->setText(QApplication::translate("MainWindow", "Guide", nullptr));
        action_remove->setText(QApplication::translate("MainWindow", "Remove", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", nullptr));
        menuView->setTitle(QApplication::translate("MainWindow", "View", nullptr));
        menuRun->setTitle(QApplication::translate("MainWindow", "Run", nullptr));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = tree_widget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\277\321\200\320\265\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\320\275\320\270\321\217\321\205", nullptr));

        const bool __sortingEnabled = tree_widget->isSortingEnabled();
        tree_widget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = tree_widget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "\320\247\320\260\321\201\321\202\320\276\321\202\320\260", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("MainWindow", "\320\235\320\265 \320\273\320\265\320\267\321\214 \321\201\321\216\320\264\320\260", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = tree_widget->topLevelItem(1);
        ___qtreewidgetitem3->setText(0, QApplication::translate("MainWindow", "\320\247\321\202\320\276 \321\202\321\213 \321\205\320\276\321\207\320\265\321\210\321\214 \321\203\320\267\320\275\320\260\321\202\321\214 \320\265\321\211\320\265, \321\200\320\260\320\267\320\262\320\265\321\200\320\275\320\270  \321\207\320\260\321\201\321\202\320\276\321\202\321\203", nullptr));
        tree_widget->setSortingEnabled(__sortingEnabled);

        add_pattern->setText(QApplication::translate("MainWindow", "add pattern", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
