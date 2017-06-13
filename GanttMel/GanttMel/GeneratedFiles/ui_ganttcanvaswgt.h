/********************************************************************************
** Form generated from reading UI file 'ganttcanvaswgt.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GANTTCANVASWGT_H
#define UI_GANTTCANVASWGT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GanttCanvasWgt
{
public:

    void setupUi(QWidget *GanttCanvasWgt)
    {
        if (GanttCanvasWgt->objectName().isEmpty())
            GanttCanvasWgt->setObjectName(QStringLiteral("GanttCanvasWgt"));
        GanttCanvasWgt->resize(400, 300);

        retranslateUi(GanttCanvasWgt);

        QMetaObject::connectSlotsByName(GanttCanvasWgt);
    } // setupUi

    void retranslateUi(QWidget *GanttCanvasWgt)
    {
        GanttCanvasWgt->setWindowTitle(QApplication::translate("GanttCanvasWgt", "GanttCanvasWgt", 0));
    } // retranslateUi

};

namespace Ui {
    class GanttCanvasWgt: public Ui_GanttCanvasWgt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GANTTCANVASWGT_H
