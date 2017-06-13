#ifndef GANTTMEL_H
#define GANTTMEL_H

#include <QtWidgets/QMainWindow>
#include "datacentermgr.h"
#include "ui_ganttmel.h"

class GanttMel : public QMainWindow
{
	Q_OBJECT

public:
	GanttMel(QWidget *parent = 0);
	~GanttMel();

private slots:
	void slot_changeAccuracy(QString sText);//改变精度
	void slot_changeNeedDivider(int nState);//是否显示分割线
	void slot_changeArrow(QString sText);//改变连接线样式
	void slot_showColorDialog();//改变颜色

private:
	void initVariable();//初始化变量
	void initConnect();//初始化链接
	void addTestTaskInfo();//测试函数

private:
	Ui::GanttMelClass ui;
};

#endif // GANTTMEL_H
