#ifndef GANTTCANVASWGT_H
#define GANTTCANVASWGT_H

#include <QWidget>
#include "ui_ganttcanvaswgt.h"
#include "datacentermgr.h"
#include "ganttsetting.h"

class GanttCanvasWgt : public QWidget
{
	Q_OBJECT

public:
	GanttCanvasWgt(QWidget *parent = 0);
	~GanttCanvasWgt();

private slots:
	void slot_addTaskInfo(TaskInfo info, NotifyType type);
	void slot_delTaskInfo(TaskInfo info, NotifyType type);
	void slot_updateTaskInfo(TaskInfo info, NotifyType type);
	void slot_clearTaskInfo(TaskInfo info, NotifyType type);
	void slot_updatePaintSetting(PaintSetting setting);

private:
	void paintEvent(QPaintEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);

	void initVariable();//初始化变量
	void initConnect();//初始化链接
	
	void calcMonthRect();//计算月份标题
	void calcWeekRect();//计算周标题
	void calcDayRect();//计算日标题
	void calcDividerRect();//计算分割线
	void calcArrowRect();//计算连接线
	QRect calcTaskInfoRect(TaskInfo info);//计算任务条区域

	void showMenu(QRect rect);

private:
	Ui::GanttCanvasWgt ui;

	QDateTime m_StartDate;	//任务开始时间
	QDateTime m_EndDate;	//任务结束时间
	QPoint m_CurPos;//鼠标指针位置

	QList <QRect> m_lMonthRectList;
	QList <QRect> m_lWeekRectList;
	QList <QRect> m_lDayRectList;
	QList <QRect> m_lDividerList;
	QList <QRect> m_lArrowList;

	QMap<qint64, TaskInfo> m_TaskInfoMap;
	PaintSetting m_paintSetting;//绘图配置
};

#endif // GANTTCANVASWGT_H
