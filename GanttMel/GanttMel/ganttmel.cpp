#include "ganttmel.h"
#include <QColorDialog>

GanttMel::GanttMel(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	initVariable();//初始化变量
	initConnect();//初始化链接

	addTestTaskInfo();
}

GanttMel::~GanttMel()
{

}

void GanttMel::initVariable()
{
	PaintSetting setting;
	GanttSetting::instance()->getPaintSetting(setting);

	if (setting.accuracyType == e_Day)
		ui.AccuracyCombobox->setCurrentText(QStringLiteral("天"));
	else if (setting.accuracyType == e_Week)
		ui.AccuracyCombobox->setCurrentText(QStringLiteral("周"));
	else if (setting.accuracyType == e_Month)
		ui.AccuracyCombobox->setCurrentText(QStringLiteral("月"));

	ui.DividerCheckBox->setChecked(setting.bNeedDivider);

	if (setting.arrowType == e_NoLine)
		ui.ArrowCombobox->setCurrentText(QStringLiteral("无线"));
	else if (setting.arrowType == e_StraightLine)
		ui.ArrowCombobox->setCurrentText(QStringLiteral("直线"));
	else if (setting.arrowType == e_BrokenLine)
		ui.ArrowCombobox->setCurrentText(QStringLiteral("折线"));

	QColor color = setting.taskBarColor;
	ui.TaskBgColorBtn->setStyleSheet(QStringLiteral("border:1px solid ;background-color:rgba(%1,%2,%3);")
		.arg(color.red()).arg(color.green()).arg(color.blue()));

	GanttSetting::instance()->savePaintSetting(setting);
}

void GanttMel::initConnect()
{
	connect(ui.AccuracyCombobox, SIGNAL(currentIndexChanged(QString)), this, SLOT(slot_changeAccuracy(QString)));
	connect(ui.DividerCheckBox, SIGNAL(stateChanged(int)), this, SLOT(slot_changeNeedDivider(int)));
	connect(ui.ArrowCombobox, SIGNAL(currentIndexChanged(QString)), this, SLOT(slot_changeArrow(QString)));
	connect(ui.TaskBgColorBtn, SIGNAL(clicked()), this, SLOT(slot_showColorDialog()));
}

void GanttMel::slot_changeAccuracy(QString sText)
{
	PaintSetting setting;
	GanttSetting::instance()->getPaintSetting(setting);

	if (sText == QStringLiteral("月"))
		setting.accuracyType = e_Month;
	else if (sText == QStringLiteral("周"))
		setting.accuracyType = e_Week;
	else if (sText == QStringLiteral("天"))
		setting.accuracyType = e_Day;
	
	GanttSetting::instance()->savePaintSetting(setting);
}

void GanttMel::slot_changeNeedDivider(int nState)
{
	PaintSetting setting;
	GanttSetting::instance()->getPaintSetting(setting);

	if (nState == 0)
		setting.bNeedDivider = false;
	else if (nState == 2)
		setting.bNeedDivider = true;

	GanttSetting::instance()->savePaintSetting(setting);
}

void GanttMel::slot_changeArrow(QString sText)
{
	PaintSetting setting;
	GanttSetting::instance()->getPaintSetting(setting);

	if (sText == QStringLiteral("无线"))
		setting.arrowType = e_NoLine;
	else if (sText == QStringLiteral("直线"))
		setting.arrowType = e_StraightLine;
	else if (sText == QStringLiteral("折线"))
		setting.arrowType = e_BrokenLine;

	GanttSetting::instance()->savePaintSetting(setting);
}

void GanttMel::slot_showColorDialog()
{
	QColor color = QColorDialog::getColor(Qt::green, this);
	ui.TaskBgColorBtn->setStyleSheet(QStringLiteral("border:1px solid ;background-color:rgba(%1,%2,%3);")
														.arg(color.red()).arg(color.green()).arg(color.blue()));

	PaintSetting setting;
	GanttSetting::instance()->getPaintSetting(setting);
	setting.taskBarColor = color;
	GanttSetting::instance()->savePaintSetting(setting);
}

void GanttMel::addTestTaskInfo()
{
	QDateTime cacheDate = QDateTime::currentDateTime();
	for (int a = 1; a < 500; a++)
	{
		TaskInfo info;

		info.m_StartDate = cacheDate;
		info.m_EndDate = info.m_StartDate.addDays(a/2);
		cacheDate = info.m_EndDate;
		//info.m_nTakeCycle = 5;
		info.m_sTaskName = QStringLiteral("测试任务_%1").arg((a+1)*1111);
		info.m_sUserName = QStringLiteral("MEL");

		info.m_nTaskIndex = a*2;
		//info.m_nTaskLevel = 1;
		info.m_sTaskID = QString::number(a);
		//info.m_sFrontTaskID = QStringLiteral("0");
		//info.m_sParentTaskID = QStringLiteral("0");

		DataCenterMgr::instance()->addTaskInfo(info, e_Chart);
	}
}