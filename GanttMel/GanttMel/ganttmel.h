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
	void slot_changeAccuracy(QString sText);//�ı侫��
	void slot_changeNeedDivider(int nState);//�Ƿ���ʾ�ָ���
	void slot_changeArrow(QString sText);//�ı���������ʽ
	void slot_showColorDialog();//�ı���ɫ

private:
	void initVariable();//��ʼ������
	void initConnect();//��ʼ������
	void addTestTaskInfo();//���Ժ���

private:
	Ui::GanttMelClass ui;
};

#endif // GANTTMEL_H
