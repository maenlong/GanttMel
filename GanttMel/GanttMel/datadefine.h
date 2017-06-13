#ifndef DATADEFINE
#define DATADEFINE

#include <QRect>
#include <QColor>
#include <QDateTime>

// 精度类型
enum AccuracyType
{
	e_Day = 0,                         // 天
	e_Week = 1,                      // 周
	e_Month = 2,                     // 月
	e_AccuracyCount = 3         // 总数
};

// 连线类型
enum ArrowType
{
	e_NoLine = 0,                  // 无线
	e_StraightLine = 1,           // 直线
	e_BrokenLine = 2,            // 折线
	e_ArrowCount = 3           // 总数
};

//绘图设置
struct PaintSetting
{
	int dayWidth;		    //一天宽度
	int weekWidth;	        //一周宽度
	int monthWidth;		//一月宽度

	int lineHeight;		    //一行高度
	int taskBarHeight;	    //任务条高度
	int taskTipSpacing;	//任务条提示间距

	QColor titleBgColor;		//标题栏背景色
	QColor taskBarColor;	//任务条颜色
	QColor taskHoverColor;//任务条颜色
	QColor taskTipColor;		//任务描述颜色

	AccuracyType accuracyType;//精度类型
	ArrowType arrowType;//连线类型
	bool bNeedDivider;//分割线

	PaintSetting()
	{
		dayWidth = 20;
		weekWidth = dayWidth * 7;
		monthWidth = weekWidth * 4;

		lineHeight = 30;
		taskBarHeight = 20;
		taskTipSpacing = 10;

		titleBgColor.setRgb(240, 240, 240);
		taskBarColor.setRgb(0, 255, 0);
		taskHoverColor.setRgb(255, 155, 55);
		taskTipColor.setRgb(0, 0, 0);

		accuracyType = e_Day;
		arrowType = e_NoLine;
		bNeedDivider = false;
	}
};
Q_DECLARE_METATYPE(PaintSetting)


// 通知类型
enum NotifyType
{
	e_None = 0,                  // 无对象
	e_Form = 1,                  // 表格
	e_Chart = 2,                  // 图表
	e_Both = 3,                   // 全部
	e_NotifyCount = 3        // 总数
};


struct TaskInfo
{
	QDateTime		m_StartDate;				//开始日期
	QDateTime		m_EndDate;				//结束日期
	qint64				m_nTakeCycle;			//任务周期
	QString				m_sTaskName;			//任务名称
	QString				m_sUserName;			//负责人名称

	qint64				m_nTaskIndex;			//任务序号
	qint64				m_nTaskLevel;			//任务级别
	QString				m_sTaskID;				//任务ID
	QString				m_sFrontTaskID;			//前置任务ID
	QString				m_sParentTaskID;		//父类任务ID
	QRect				m_Rect;						//绘图区域

	TaskInfo()
	{
		m_StartDate;
		m_EndDate;
		m_nTakeCycle = 0;
		m_sTaskName = QStringLiteral("");
		m_sUserName = QStringLiteral("");

		m_nTaskIndex = 0;
		m_nTaskLevel = 0;
		m_sTaskID = QStringLiteral("");
		m_sFrontTaskID = QStringLiteral("");
		m_sParentTaskID = QStringLiteral("");
		m_Rect;
	}
};
Q_DECLARE_METATYPE(TaskInfo)





#endif   //DATADEFINE