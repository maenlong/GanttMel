#ifndef GANTTSETTING_H
#define GANTTSETTING_H

#include <QSettings>
#include "datacentermgr.h"


class GanttSetting : public QObject
{
	Q_OBJECT

public:
	static GanttSetting* instance();
	~GanttSetting();

private:
	GanttSetting(QObject *parent = 0);
	static GanttSetting* m_pInstance;

public:
	void savePaintSetting(const PaintSetting &setting);					//�����ͼ����
	void getPaintSetting(PaintSetting &setting);								//��ȡ��ͼ����
	void setPaintSetting(const PaintSetting &setting);						//���û�ͼ����

signals:
	void sig_updatePaintSetting(PaintSetting setting);

private:
	QSettings *m_settings;
};

#endif // GANTTSETTING_H
