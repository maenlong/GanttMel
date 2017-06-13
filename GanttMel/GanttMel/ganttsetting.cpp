#include "ganttsetting.h"
#include <QApplication>

GanttSetting* GanttSetting::m_pInstance = NULL;
const QString strConfigFile = QStringLiteral("");

GanttSetting::GanttSetting(QObject *parent)
: QObject(parent)
{
	QString strIniPath = QCoreApplication::applicationDirPath()+"/GanttSetting.ini";
	m_settings = new QSettings(strIniPath, QSettings::IniFormat);
}

GanttSetting* GanttSetting::instance()
{
	if (m_pInstance == NULL)
	{
		m_pInstance = new GanttSetting();
	}
	return m_pInstance;
}

GanttSetting::~GanttSetting()
{

}

// ±£¥ÊªÊÕº≈‰÷√
void GanttSetting::savePaintSetting(const PaintSetting &setting)
{
	m_settings->setValue("PaintSetting/dayWidth", setting.dayWidth);
	m_settings->setValue("PaintSetting/weekWidth", setting.weekWidth);
	m_settings->setValue("PaintSetting/monthWidth", setting.monthWidth);

	m_settings->setValue("PaintSetting/lineHeight", setting.lineHeight);
	m_settings->setValue("PaintSetting/taskBarHeight", setting.taskBarHeight);
	m_settings->setValue("PaintSetting/taskTipSpacing", setting.taskTipSpacing);

	m_settings->setValue("PaintSetting/titleBgColor", setting.titleBgColor);
	m_settings->setValue("PaintSetting/taskBarColor", setting.taskBarColor);
	m_settings->setValue("PaintSetting/taskHoverColor", setting.taskHoverColor);
	m_settings->setValue("PaintSetting/taskTipColor", setting.taskTipColor);

	m_settings->setValue("PaintSetting/accuracyType", (int)setting.accuracyType);
	m_settings->setValue("PaintSetting/arrowType", (int)setting.arrowType);
	m_settings->setValue("PaintSetting/needDivider", (int)setting.bNeedDivider);

	emit sig_updatePaintSetting(setting);
}

// ∂¡»°ªÊÕº≈‰÷√
void GanttSetting::getPaintSetting(PaintSetting &setting)
{
	setting.dayWidth = m_settings->value("PaintSetting/dayWidth", 20).toInt();
	setting.weekWidth = m_settings->value("PaintSetting/weekWidth", 20*7).toInt();
	setting.monthWidth = m_settings->value("PaintSetting/monthWidth", 20*7*4).toInt();

	setting.lineHeight = m_settings->value("PaintSetting/lineHeight", 30).toInt();
	setting.taskBarHeight = m_settings->value("PaintSetting/taskBarHeight", 20).toInt();
	setting.taskTipSpacing = m_settings->value("PaintSetting/taskTipSpacing", 10).toInt();

	setting.titleBgColor = m_settings->value("PaintSetting/titleBgColor", "").toString();
	setting.taskBarColor = m_settings->value("PaintSetting/taskBarColor", "").toString();
	setting.taskHoverColor = m_settings->value("PaintSetting/taskHoverColor", "").toString();
	setting.taskTipColor = m_settings->value("PaintSetting/taskTipColor", "").toString();

	setting.accuracyType = (AccuracyType)m_settings->value("PaintSetting/accuracyType", 20).toInt();
	setting.arrowType = (ArrowType)m_settings->value("PaintSetting/arrowType", 20).toInt();
	setting.bNeedDivider = m_settings->value("PaintSetting/needDivider", 20).toInt();
}

//…Ë÷√ªÊÕº≈‰÷√
void GanttSetting::setPaintSetting(const PaintSetting &audioInfo)
{

}