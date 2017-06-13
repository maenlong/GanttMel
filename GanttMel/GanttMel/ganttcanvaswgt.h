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

	void initVariable();//��ʼ������
	void initConnect();//��ʼ������
	
	void calcMonthRect();//�����·ݱ���
	void calcWeekRect();//�����ܱ���
	void calcDayRect();//�����ձ���
	void calcDividerRect();//����ָ���
	void calcArrowRect();//����������
	QRect calcTaskInfoRect(TaskInfo info);//��������������

	void showMenu(QRect rect);

private:
	Ui::GanttCanvasWgt ui;

	QDateTime m_StartDate;	//����ʼʱ��
	QDateTime m_EndDate;	//�������ʱ��
	QPoint m_CurPos;//���ָ��λ��

	QList <QRect> m_lMonthRectList;
	QList <QRect> m_lWeekRectList;
	QList <QRect> m_lDayRectList;
	QList <QRect> m_lDividerList;
	QList <QRect> m_lArrowList;

	QMap<qint64, TaskInfo> m_TaskInfoMap;
	PaintSetting m_paintSetting;//��ͼ����
};

#endif // GANTTCANVASWGT_H
