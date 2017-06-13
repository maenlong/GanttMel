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
	void savePaintSetting(const PaintSetting &setting);					//±£¥ÊªÊÕº≈‰÷√
	void getPaintSetting(PaintSetting &setting);								//∂¡»°ªÊÕº≈‰÷√
	void setPaintSetting(const PaintSetting &setting);						//…Ë÷√ªÊÕº≈‰÷√

signals:
	void sig_updatePaintSetting(PaintSetting setting);

private:
	QSettings *m_settings;
};

#endif // GANTTSETTING_H
