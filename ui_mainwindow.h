/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QGridLayout *gridLayout;
    QTreeWidget *patterns;
    QPushButton *save_filters;
    QPushButton *set_button;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *clear;
    QSpacerItem *verticalSpacer;
    QPushButton *close_filters;
    QPushButton *open_filters;
    QPushButton *copy_button;
    QGraphicsView *graphics_view;
    QTreeWidget *filters_information;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *delete_button;
    QListWidget *filters;
    QPushButton *calculate;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QPushButton *save_pattern;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuRun;
    QMenu *menuTools;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1055, 631);
        action_open = new QAction(MainWindow);
        action_open->setObjectName("action_open");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/tools/image/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_open->setIcon(icon);
        action_save = new QAction(MainWindow);
        action_save->setObjectName("action_save");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/tools/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_save->setIcon(icon1);
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName("actionSave_as");
        actionSave_as->setIcon(icon1);
        action_print = new QAction(MainWindow);
        action_print->setObjectName("action_print");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/tools/image/print.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_print->setIcon(icon2);
        action_settings = new QAction(MainWindow);
        action_settings->setObjectName("action_settings");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/tools/image/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_settings->setIcon(icon3);
        action_next = new QAction(MainWindow);
        action_next->setObjectName("action_next");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/tools/image/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_next->setIcon(icon4);
        action_back = new QAction(MainWindow);
        action_back->setObjectName("action_back");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/tools/image/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_back->setIcon(icon5);
        actionGuide = new QAction(MainWindow);
        actionGuide->setObjectName("actionGuide");
        action_remove = new QAction(MainWindow);
        action_remove->setObjectName("action_remove");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/tools/image/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_remove->setIcon(icon6);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        patterns = new QTreeWidget(centralwidget);
        patterns->setObjectName("patterns");

        gridLayout->addWidget(patterns, 5, 1, 3, 5);

        save_filters = new QPushButton(centralwidget);
        save_filters->setObjectName("save_filters");

        gridLayout->addWidget(save_filters, 7, 6, 1, 1);

        set_button = new QPushButton(centralwidget);
        set_button->setObjectName("set_button");

        gridLayout->addWidget(set_button, 4, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 6, 1, 2);

        clear = new QPushButton(centralwidget);
        clear->setObjectName("clear");
        clear->setMinimumSize(QSize(0, 90));

        gridLayout->addWidget(clear, 7, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 8, 1, 1);

        close_filters = new QPushButton(centralwidget);
        close_filters->setObjectName("close_filters");

        gridLayout->addWidget(close_filters, 7, 7, 1, 1);

        open_filters = new QPushButton(centralwidget);
        open_filters->setObjectName("open_filters");

        gridLayout->addWidget(open_filters, 4, 3, 1, 1);

        copy_button = new QPushButton(centralwidget);
        copy_button->setObjectName("copy_button");

        gridLayout->addWidget(copy_button, 4, 0, 1, 1);

        graphics_view = new QGraphicsView(centralwidget);
        graphics_view->setObjectName("graphics_view");

        gridLayout->addWidget(graphics_view, 2, 0, 2, 6);

        filters_information = new QTreeWidget(centralwidget);
        QFont font;
        font.setBold(true);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(filters_information);
        __qtreewidgetitem->setFont(0, font);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(filters_information);
        __qtreewidgetitem1->setFont(0, font);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(filters_information);
        __qtreewidgetitem2->setFont(0, font);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(filters_information);
        __qtreewidgetitem3->setFont(0, font);
        filters_information->setObjectName("filters_information");
        filters_information->setMaximumSize(QSize(16777215, 206));
        filters_information->setLayoutDirection(Qt::LeftToRight);
        filters_information->setAutoFillBackground(false);

        gridLayout->addWidget(filters_information, 2, 6, 2, 2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 4, 5, 1, 1);

        delete_button = new QPushButton(centralwidget);
        delete_button->setObjectName("delete_button");

        gridLayout->addWidget(delete_button, 4, 1, 1, 1);

        filters = new QListWidget(centralwidget);
        filters->setObjectName("filters");

        gridLayout->addWidget(filters, 4, 6, 3, 2);

        calculate = new QPushButton(centralwidget);
        calculate->setObjectName("calculate");
        calculate->setMinimumSize(QSize(0, 90));

        gridLayout->addWidget(calculate, 5, 0, 2, 1);

        horizontalSpacer = new QSpacerItem(764, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 6);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 4, 8, 4, 1);

        save_pattern = new QPushButton(centralwidget);
        save_pattern->setObjectName("save_pattern");

        gridLayout->addWidget(save_pattern, 4, 4, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1055, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName("menuEdit");
        menuView = new QMenu(menubar);
        menuView->setObjectName("menuView");
        menuRun = new QMenu(menubar);
        menuRun->setObjectName("menuRun");
        menuTools = new QMenu(menubar);
        menuTools->setObjectName("menuTools");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

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
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_open->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        action_save->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionSave_as->setText(QCoreApplication::translate("MainWindow", "Save as", nullptr));
        action_print->setText(QCoreApplication::translate("MainWindow", "Print", nullptr));
        action_settings->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        action_next->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        action_back->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        actionGuide->setText(QCoreApplication::translate("MainWindow", "Guide", nullptr));
        action_remove->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = patterns->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "\320\250\320\260\320\261\320\273\320\276\320\275\321\213", nullptr));
        save_filters->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        set_button->setText(QCoreApplication::translate("MainWindow", "\320\222\321\201\321\202\320\260\320\262\320\270\321\202\321\214", nullptr));
        clear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        close_filters->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        open_filters->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \321\204\320\270\320\273\321\214\321\202\321\200", nullptr));
        copy_button->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\277\320\270\321\217", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = filters_information->headerItem();
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\277\321\200\320\265\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\320\275\320\270\321\217\321\205", nullptr));

        const bool __sortingEnabled = filters_information->isSortingEnabled();
        filters_information->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem2 = filters_information->topLevelItem(0);
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("MainWindow", "\320\236\320\263\321\200\320\260\320\275\320\270\321\207\320\265\320\275\320\270\320\265 \320\260\320\274\320\277\320\273\320\270\321\202\321\203\320\264\321\213", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = filters_information->topLevelItem(1);
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("MainWindow", "\320\241\321\202\321\217\320\275\321\203\321\202\321\214 \320\272 \320\276\321\201\320\270", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = filters_information->topLevelItem(2);
        ___qtreewidgetitem4->setText(0, QCoreApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200 1", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = filters_information->topLevelItem(3);
        ___qtreewidgetitem5->setText(0, QCoreApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200 2", nullptr));
        filters_information->setSortingEnabled(__sortingEnabled);

        delete_button->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        calculate->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
        save_pattern->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        menuRun->setTitle(QCoreApplication::translate("MainWindow", "Run", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
