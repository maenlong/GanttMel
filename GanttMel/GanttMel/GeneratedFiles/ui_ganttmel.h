/********************************************************************************
** Form generated from reading UI file 'ganttmel.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GANTTMEL_H
#define UI_GANTTMEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "ganttcanvaswgt.h"

QT_BEGIN_NAMESPACE

class Ui_GanttMelClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollWgt;
    QGridLayout *gridLayout_3;
    GanttCanvasWgt *ganttWgt;
    QTableWidget *tableWidget;
    QWidget *ToolBarWgt;
    QGridLayout *gridLayout_2;
    QLabel *AccuracyTipLbl;
    QSpacerItem *horizontalSpacer;
    QLabel *DividerTipLbl;
    QComboBox *AccuracyCombobox;
    QLabel *ArrowTipLbl;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *DividerCheckBox;
    QComboBox *ArrowCombobox;
    QSpacerItem *verticalSpacer;
    QLabel *TaskBgColorTIp;
    QPushButton *TaskBgColorBtn;
    QSpacerItem *horizontalSpacer_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GanttMelClass)
    {
        if (GanttMelClass->objectName().isEmpty())
            GanttMelClass->setObjectName(QStringLiteral("GanttMelClass"));
        GanttMelClass->resize(1060, 724);
        centralWidget = new QWidget(GanttMelClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollWgt = new QWidget();
        scrollWgt->setObjectName(QStringLiteral("scrollWgt"));
        scrollWgt->setGeometry(QRect(0, 0, 658, 465));
        scrollWgt->setMinimumSize(QSize(0, 0));
        gridLayout_3 = new QGridLayout(scrollWgt);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        ganttWgt = new GanttCanvasWgt(scrollWgt);
        ganttWgt->setObjectName(QStringLiteral("ganttWgt"));

        gridLayout_3->addWidget(ganttWgt, 0, 0, 1, 1);

        scrollArea->setWidget(scrollWgt);

        gridLayout->addWidget(scrollArea, 1, 1, 1, 1);

        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidget->rowCount() < 8)
            tableWidget->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem10);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setMinimumSize(QSize(400, 400));
        tableWidget->setMaximumSize(QSize(400, 16777215));
        tableWidget->horizontalHeader()->setMinimumSectionSize(30);
        tableWidget->verticalHeader()->setMinimumSectionSize(30);

        gridLayout->addWidget(tableWidget, 1, 0, 1, 1);

        ToolBarWgt = new QWidget(centralWidget);
        ToolBarWgt->setObjectName(QStringLiteral("ToolBarWgt"));
        ToolBarWgt->setMinimumSize(QSize(0, 200));
        ToolBarWgt->setMaximumSize(QSize(16777215, 200));
        gridLayout_2 = new QGridLayout(ToolBarWgt);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        AccuracyTipLbl = new QLabel(ToolBarWgt);
        AccuracyTipLbl->setObjectName(QStringLiteral("AccuracyTipLbl"));

        gridLayout_2->addWidget(AccuracyTipLbl, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 3, 1, 1);

        DividerTipLbl = new QLabel(ToolBarWgt);
        DividerTipLbl->setObjectName(QStringLiteral("DividerTipLbl"));

        gridLayout_2->addWidget(DividerTipLbl, 1, 0, 1, 1);

        AccuracyCombobox = new QComboBox(ToolBarWgt);
        AccuracyCombobox->setObjectName(QStringLiteral("AccuracyCombobox"));

        gridLayout_2->addWidget(AccuracyCombobox, 0, 1, 1, 1);

        ArrowTipLbl = new QLabel(ToolBarWgt);
        ArrowTipLbl->setObjectName(QStringLiteral("ArrowTipLbl"));

        gridLayout_2->addWidget(ArrowTipLbl, 2, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 2, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        DividerCheckBox = new QCheckBox(ToolBarWgt);
        DividerCheckBox->setObjectName(QStringLiteral("DividerCheckBox"));

        gridLayout_2->addWidget(DividerCheckBox, 1, 1, 1, 1);

        ArrowCombobox = new QComboBox(ToolBarWgt);
        ArrowCombobox->setObjectName(QStringLiteral("ArrowCombobox"));

        gridLayout_2->addWidget(ArrowCombobox, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 4, 0, 1, 1);

        TaskBgColorTIp = new QLabel(ToolBarWgt);
        TaskBgColorTIp->setObjectName(QStringLiteral("TaskBgColorTIp"));

        gridLayout_2->addWidget(TaskBgColorTIp, 3, 0, 1, 1);

        TaskBgColorBtn = new QPushButton(ToolBarWgt);
        TaskBgColorBtn->setObjectName(QStringLiteral("TaskBgColorBtn"));
        TaskBgColorBtn->setMinimumSize(QSize(0, 30));
        TaskBgColorBtn->setStyleSheet(QStringLiteral("border:1px solid;"));

        gridLayout_2->addWidget(TaskBgColorBtn, 3, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 3, 3, 1, 1);


        gridLayout->addWidget(ToolBarWgt, 0, 0, 1, 2);

        GanttMelClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GanttMelClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1060, 23));
        GanttMelClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GanttMelClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GanttMelClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GanttMelClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GanttMelClass->setStatusBar(statusBar);

        retranslateUi(GanttMelClass);

        QMetaObject::connectSlotsByName(GanttMelClass);
    } // setupUi

    void retranslateUi(QMainWindow *GanttMelClass)
    {
        GanttMelClass->setWindowTitle(QApplication::translate("GanttMelClass", "GanttMel", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("GanttMelClass", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("GanttMelClass", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("GanttMelClass", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("GanttMelClass", "\346\226\260\345\273\272\350\241\214", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("GanttMelClass", "\346\226\260\345\273\272\350\241\214", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("GanttMelClass", "\346\226\260\345\273\272\350\241\214", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("GanttMelClass", "\346\226\260\345\273\272\350\241\214", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem7->setText(QApplication::translate("GanttMelClass", "\346\226\260\345\273\272\350\241\214", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem8->setText(QApplication::translate("GanttMelClass", "\346\226\260\345\273\272\350\241\214", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem9->setText(QApplication::translate("GanttMelClass", "\346\226\260\345\273\272\350\241\214", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem10->setText(QApplication::translate("GanttMelClass", "\346\226\260\345\273\272\350\241\214", 0));
        AccuracyTipLbl->setText(QApplication::translate("GanttMelClass", "\346\227\266\351\227\264\347\262\276\345\272\246\357\274\232", 0));
        DividerTipLbl->setText(QApplication::translate("GanttMelClass", "\351\234\200\350\246\201\345\210\206\345\211\262\357\274\232", 0));
        AccuracyCombobox->clear();
        AccuracyCombobox->insertItems(0, QStringList()
         << QApplication::translate("GanttMelClass", "\346\234\210", 0)
         << QApplication::translate("GanttMelClass", "\345\221\250", 0)
         << QApplication::translate("GanttMelClass", "\345\244\251", 0)
        );
        ArrowTipLbl->setText(QApplication::translate("GanttMelClass", "\350\277\236\346\216\245\346\240\267\345\274\217\357\274\232", 0));
        DividerCheckBox->setText(QString());
        ArrowCombobox->clear();
        ArrowCombobox->insertItems(0, QStringList()
         << QApplication::translate("GanttMelClass", "\346\227\240\347\272\277", 0)
         << QApplication::translate("GanttMelClass", "\347\233\264\347\272\277", 0)
         << QApplication::translate("GanttMelClass", "\346\212\230\347\272\277", 0)
        );
        TaskBgColorTIp->setText(QApplication::translate("GanttMelClass", "\351\242\234\350\211\262\351\200\211\346\213\251\357\274\232", 0));
        TaskBgColorBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GanttMelClass: public Ui_GanttMelClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GANTTMEL_H
