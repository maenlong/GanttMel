#include "ganttcanvaswgt.h"
#include <QPainter>
#include <QDateTime>
#include <QMouseEvent>
#include <QMenu>
#include <QDebug>

GanttCanvasWgt::GanttCanvasWgt(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setMouseTracking(true);

	initVariable();//初始化变量
	initConnect();//初始化链接
}

GanttCanvasWgt::~GanttCanvasWgt()
{

}

void GanttCanvasWgt::initVariable()
{
	m_StartDate = QDateTime::currentDateTime();
	m_EndDate = QDateTime::currentDateTime().addYears(1);

	GanttSetting::instance()->getPaintSetting(m_paintSetting);
	this->setMinimumSize(m_paintSetting.lineHeight*1000,m_paintSetting.dayWidth *1000);
}

void GanttCanvasWgt::initConnect()
{
	connect(DataCenterMgr::instance(), SIGNAL(sig_addTaskInfo(TaskInfo, NotifyType)),
		this, SLOT(slot_addTaskInfo(TaskInfo, NotifyType)));

	connect(DataCenterMgr::instance(), SIGNAL(sig_delTaskInfo(TaskInfo, NotifyType)),
		this, SLOT(slot_delTaskInfo(TaskInfo, NotifyType)));

	connect(DataCenterMgr::instance(), SIGNAL(sig_updateTaskInfo(TaskInfo, NotifyType)),
		this, SLOT(slot_updateTaskInfo(TaskInfo, NotifyType)));

	connect(DataCenterMgr::instance(), SIGNAL(sig_clearTaskInfo(TaskInfo, NotifyType)),
		this, SLOT(slot_clearTaskInfo(TaskInfo, NotifyType)));

	connect(GanttSetting::instance(), SIGNAL(sig_updatePaintSetting(PaintSetting)),
		this, SLOT(slot_updatePaintSetting(PaintSetting)));
}

void GanttCanvasWgt::slot_addTaskInfo(TaskInfo info, NotifyType type)
{
	if (type == e_Chart || type == e_Both)
	{
		info.m_Rect = calcTaskInfoRect(info);
		m_TaskInfoMap[info.m_nTaskIndex] = info;
		calcArrowRect();
		this->update();
	}
}

void GanttCanvasWgt::slot_delTaskInfo(TaskInfo info, NotifyType type)
{
	if (type == e_Chart || type == e_Both)
	{
		m_TaskInfoMap.remove(info.m_nTaskIndex);
		this->update();
	}
}

void GanttCanvasWgt::slot_updateTaskInfo(TaskInfo info, NotifyType type)
{
	if (type == e_Chart || type == e_Both)
	{
		TaskInfo cacheInfo = m_TaskInfoMap.find(info.m_nTaskIndex).value();
		if (cacheInfo.m_nTaskIndex == info.m_nTaskIndex)
		{
			cacheInfo.m_StartDate = info.m_StartDate;
			cacheInfo.m_EndDate = info.m_EndDate;
			cacheInfo.m_nTakeCycle = info.m_nTakeCycle;
			cacheInfo.m_sTaskName = info.m_sTaskName;
			cacheInfo.m_sUserName = info.m_sUserName;

			cacheInfo.m_nTaskIndex = info.m_nTaskIndex;
			cacheInfo.m_nTaskLevel = info.m_nTaskLevel;
			cacheInfo.m_nTaskIndex = info.m_nTaskIndex;
			cacheInfo.m_sFrontTaskID = info.m_sFrontTaskID;
			cacheInfo.m_sParentTaskID = info.m_sParentTaskID;
			cacheInfo.m_Rect = info.m_Rect;
		}
		this->update();
	}
}

void GanttCanvasWgt::slot_clearTaskInfo(TaskInfo info, NotifyType type)
{
	if (type == e_Chart || type == e_Both)
	{
		m_TaskInfoMap.clear();
		this->update();
	}
}

void GanttCanvasWgt::slot_updatePaintSetting(PaintSetting setting)
{
	m_paintSetting = setting;

	if (m_paintSetting.accuracyType == e_Month)
		calcMonthRect();
	else if (m_paintSetting.accuracyType == e_Week)
		calcWeekRect();
	else if (m_paintSetting.accuracyType == e_Day)
		calcDayRect();

	calcDividerRect();
	calcArrowRect();

	this->update();
}

void GanttCanvasWgt::calcMonthRect()
{
	m_lMonthRectList.clear();
	for (int a = 0; a <= 12; a++)
	{
		QRect cacheRect = QRect((a - 1)*m_paintSetting.monthWidth, 0, m_paintSetting.monthWidth, m_paintSetting.lineHeight*2);
		m_lMonthRectList.append(cacheRect);
	}

	m_lWeekRectList.clear();
	m_lDayRectList.clear();
}

void GanttCanvasWgt::calcWeekRect()
{
	m_lMonthRectList.clear();
	for (int a = 0; a <= 12; a++)
	{
		QRect cacheRect = QRect((a - 1)*m_paintSetting.monthWidth, 0, m_paintSetting.monthWidth, m_paintSetting.lineHeight);
		m_lMonthRectList.append(cacheRect);
	}

	m_lWeekRectList.clear();
	for (int a = 0; a < 12 * 4; a++)
	{
		QRect cacheRect = QRect((a - 1)*m_paintSetting.weekWidth, m_paintSetting.lineHeight, m_paintSetting.weekWidth, m_paintSetting.lineHeight);
		m_lWeekRectList.append(cacheRect);
	}

	m_lDayRectList.clear();
}

void GanttCanvasWgt::calcDayRect()
{
	m_lMonthRectList.clear();
	for (int a = 0; a <= 12; a++)
	{
		QRect cacheRect = QRect((a - 1)*m_paintSetting.monthWidth, 0, m_paintSetting.monthWidth, m_paintSetting.lineHeight);
		m_lMonthRectList.append(cacheRect);
	}

	m_lWeekRectList.clear();

	m_lDayRectList.clear();
	for (int a = 0; a < 12 * 4 * 7; a++)
	{
		QRect cacheRect = QRect((a - 1)*m_paintSetting.dayWidth, m_paintSetting.lineHeight, m_paintSetting.dayWidth, m_paintSetting.lineHeight);
		m_lDayRectList.append(cacheRect);
	}
}

void GanttCanvasWgt::calcDividerRect()
{
	m_lDividerList.clear();

	if (m_paintSetting.bNeedDivider)
	{
		if (m_paintSetting.accuracyType == e_Month)
		{
			for (int a = 0; a < m_lMonthRectList.count(); a++)
			{
				QRect cacheRect = m_lMonthRectList.at(a);
				cacheRect.setY(m_paintSetting.lineHeight * 2);
				m_lDividerList.append(cacheRect);
			}
		}
		else if (m_paintSetting.accuracyType == e_Week)
		{
			for (int a = 0; a < m_lWeekRectList.count(); a++)
			{
				QRect cacheRect = m_lWeekRectList.at(a);
				cacheRect.setY(m_paintSetting.lineHeight * 2);
				m_lDividerList.append(cacheRect);
			}
		}
		else if (m_paintSetting.accuracyType == e_Day)
		{
			for (int a = 0; a < m_lDayRectList.count(); a++)
			{
				QRect cacheRect = m_lDayRectList.at(a);
				cacheRect.setY(m_paintSetting.lineHeight * 2);
				m_lDividerList.append(cacheRect);
			}
		}
	}
}

void GanttCanvasWgt::calcArrowRect()
{
	m_lArrowList.clear();

	QList<TaskInfo> cacheInfoList;
	QMap<qint64, TaskInfo>::const_iterator item;
	for (item = m_TaskInfoMap.constBegin(); item != m_TaskInfoMap.constEnd(); ++item)
	{
		TaskInfo cacheInfo = item.value();
		cacheInfoList << cacheInfo;
	}

	for (int a = 1; a < cacheInfoList.count(); a++)
	{
		if (cacheInfoList.at(a).m_nTaskIndex - cacheInfoList.at(a - 1).m_nTaskIndex != 1)
		{
			QRect cacheRect;
			cacheRect.setX(cacheInfoList.at(a - 1).m_Rect.x() + cacheInfoList.at(a - 1).m_Rect.width());
			cacheRect.setY(cacheInfoList.at(a - 1).m_Rect.y() + cacheInfoList.at(a - 1).m_Rect.height());
			cacheRect.setWidth(cacheInfoList.at(a).m_Rect.x());
			cacheRect.setHeight(cacheInfoList.at(a).m_Rect.y());
			m_lArrowList << cacheRect;
		}
	}

	cacheInfoList.clear();
}

QRect GanttCanvasWgt::calcTaskInfoRect(TaskInfo info)
{
	QRect cacheRect;
	int nStartX = m_StartDate.daysTo(info.m_StartDate);
	int nStartY = info.m_nTaskIndex;
	int nWidth = info.m_StartDate.daysTo(info.m_EndDate);
	int nHeight = 1;
	
	cacheRect = QRect(
		m_paintSetting.dayWidth * nStartX,
		m_paintSetting.lineHeight * 2 + m_paintSetting.lineHeight * nStartY + (m_paintSetting.lineHeight - m_paintSetting.taskBarHeight) / 2,
		m_paintSetting.dayWidth * nWidth,
		m_paintSetting.taskBarHeight * nHeight);

	qDebug() << "Task_Rect : " << cacheRect;

	return cacheRect;
}

void GanttCanvasWgt::paintEvent(QPaintEvent *event)
{
	Q_UNUSED(event);
	QPainter painter(this);

	// 设置字体：微软雅黑、点大小10
	QFont font;
	font.setFamily("Microsoft YaHei");
	font.setPointSize(10);
	//font.setItalic(true);//斜体

	//painter.begin(this);
	painter.setFont(font);
	painter.setPen(m_paintSetting.taskTipColor);
	painter.setBrush(m_paintSetting.titleBgColor);

	for (int a = 0; a < m_lMonthRectList.count(); a++)
	{
		painter.setPen(QPen(m_paintSetting.taskTipColor, 1, Qt::SolidLine));//设置画笔形式 
		painter.drawRect(m_lMonthRectList.at(a));
		painter.drawText(m_lMonthRectList.at(a), Qt::AlignCenter, m_StartDate.date().addMonths(a).toString("MM/yyyy"));
	}

	for (int a = 0; a < m_lWeekRectList.count(); a++)
	{
		painter.setPen(QPen(m_paintSetting.taskTipColor, 1, Qt::SolidLine));//设置画笔形式 
		painter.drawRect(m_lWeekRectList.at(a));
		if (a % 4 != 0)
			painter.drawText(m_lWeekRectList.at(a), Qt::AlignCenter, QStringLiteral("第%1周").arg(a % 4));
		else
			painter.drawText(m_lWeekRectList.at(a), Qt::AlignCenter, QStringLiteral("第4周"));
	}


	for (int a = 0; a < m_lDayRectList.count(); a++)
	{
		painter.setPen(QPen(m_paintSetting.taskTipColor, 1, Qt::SolidLine));//设置画笔形式 
		painter.drawRect(m_lDayRectList.at(a));
		painter.drawText(m_lDayRectList.at(a), Qt::AlignCenter, m_StartDate.date().addDays(a).toString("dddd").right(1));
	}

	for (int a = 0; a < m_lDividerList.count(); a++)
	{
		painter.setPen(QPen(m_paintSetting.taskTipColor, 1, Qt::DashLine));//设置画笔形式 
		painter.drawLine(QPointF(m_lDividerList.at(a).x(), m_lDividerList.at(a).y()), QPointF(m_lDividerList.at(a).x(), this->height()));
	}

	QMap<qint64, TaskInfo>::const_iterator item;
	for (item = m_TaskInfoMap.constBegin(); item != m_TaskInfoMap.constEnd(); ++item)
	{
		TaskInfo info = item.value();
		QRect cacheRect = item.value().m_Rect;
		painter.setPen(QPen(m_paintSetting.taskTipColor, 1, Qt::SolidLine));//设置画笔形式 
		if (cacheRect.contains(m_CurPos))
			painter.setBrush(m_paintSetting.taskHoverColor);
		else
			painter.setBrush(m_paintSetting.taskBarColor);
		painter.drawRect(cacheRect);

		if (cacheRect.contains(m_CurPos))
		{
			QRect tipRect = item.value().m_Rect;
			tipRect.setX(tipRect.x() + 2 * m_paintSetting.taskTipSpacing);
			tipRect.setY(tipRect.y() - m_paintSetting.lineHeight);
			tipRect.setWidth(150);
			tipRect.setHeight(m_paintSetting.lineHeight);

			painter.setPen(QPen(m_paintSetting.taskTipColor, 1, Qt::SolidLine));//设置画笔形式 
			painter.setBrush(m_paintSetting.titleBgColor);
			painter.drawRect(tipRect);
			painter.setPen(QPen(m_paintSetting.taskTipColor, 1, Qt::SolidLine));//设置画笔形式 
			painter.drawText(tipRect, Qt::AlignLeft | Qt::AlignVCenter, QStringLiteral(" ") + item->m_sTaskName + QStringLiteral(" ") + item->m_sUserName);
		}

		QRect textRect = item.value().m_Rect;
		textRect.setX(textRect.x() + textRect.width() + m_paintSetting.taskTipSpacing * 2);
		textRect.setY(textRect.y() - (m_paintSetting.lineHeight - m_paintSetting.taskBarHeight) / 2);
		textRect.setWidth(500);
		textRect.setHeight(m_paintSetting.lineHeight);
		painter.drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter, item->m_sTaskName + QStringLiteral(" ") + item->m_sUserName);
	}

	for (int a = 0; a < m_lArrowList.count(); a++)
	{
		painter.setPen(QPen(m_paintSetting.taskTipColor, 1, Qt::SolidLine));//设置画笔形式 
		painter.setBrush(m_paintSetting.taskTipColor);

		if (m_paintSetting.arrowType == e_NoLine)
		{

		}
		else if (m_paintSetting.arrowType == e_StraightLine)
		{
			painter.drawLine(QPointF(m_lArrowList.at(a).x(), m_lArrowList.at(a).y()), 
										QPointF(m_lArrowList.at(a).width(), m_lArrowList.at(a).height()));

			QPointF points[3] = { 
				QPointF(m_lArrowList.at(a).width() - 5, m_lArrowList.at(a).height() - 5), 
				QPointF(m_lArrowList.at(a).width(), m_lArrowList.at(a).height()),
				QPointF(m_lArrowList.at(a).width() + 5, m_lArrowList.at(a).height() - 5) };
			// 绘制箭头
			painter.drawPolygon(points, 3);
		}
		else if (m_paintSetting.arrowType == e_BrokenLine)
		{
			painter.drawLine(QPointF(m_lArrowList.at(a).x(), 
				m_lArrowList.at(a).y() - m_paintSetting.taskBarHeight / 2),
				QPointF(m_lArrowList.at(a).x() + m_paintSetting.taskTipSpacing,
				m_lArrowList.at(a).y() - m_paintSetting.taskBarHeight / 2));

			painter.drawLine(QPointF(m_lArrowList.at(a).x() + m_paintSetting.taskTipSpacing,
				m_lArrowList.at(a).y() - m_paintSetting.taskBarHeight / 2),
				QPointF(m_lArrowList.at(a).x() + m_paintSetting.taskTipSpacing,
				(m_lArrowList.at(a).height() + m_lArrowList.at(a).y()) / 2));

			painter.drawLine(QPointF(m_lArrowList.at(a).width() - m_paintSetting.taskTipSpacing,
				(m_lArrowList.at(a).height() + m_lArrowList.at(a).y()) / 2),
				QPointF(m_lArrowList.at(a).x() + m_paintSetting.taskTipSpacing,
				(m_lArrowList.at(a).height() + m_lArrowList.at(a).y()) / 2));

			painter.drawLine(QPointF(m_lArrowList.at(a).width() - m_paintSetting.taskTipSpacing,
				(m_lArrowList.at(a).height() + m_lArrowList.at(a).y()) / 2),
				QPointF(m_lArrowList.at(a).width() - m_paintSetting.taskTipSpacing,
				m_lArrowList.at(a).height() + m_paintSetting.taskBarHeight / 2));

			painter.drawLine(QPointF(m_lArrowList.at(a).width() - m_paintSetting.taskTipSpacing, 
				m_lArrowList.at(a).height() + m_paintSetting.taskBarHeight / 2),
				QPointF(m_lArrowList.at(a).width(), 
				m_lArrowList.at(a).height() + m_paintSetting.taskBarHeight / 2));

			QPointF points[3] = {
				QPointF(m_lArrowList.at(a).width() - 5, m_lArrowList.at(a).height() + m_paintSetting.taskBarHeight / 2 - 5),
				QPointF(m_lArrowList.at(a).width(), m_lArrowList.at(a).height() + m_paintSetting.taskBarHeight / 2),
				QPointF(m_lArrowList.at(a).width() - 5, m_lArrowList.at(a).height() + m_paintSetting.taskBarHeight / 2 + 5) };
			// 绘制箭头
			painter.drawPolygon(points, 3);
		}
	}

	painter.setRenderHint(QPainter::Antialiasing, false);//图片抗锯齿

	//painter.end();
}

void GanttCanvasWgt::mouseMoveEvent(QMouseEvent *event)
{
	QWidget::mouseMoveEvent(event);
	m_CurPos = event->pos();

	QMap<qint64, TaskInfo>::const_iterator item;
	for (item = m_TaskInfoMap.constBegin(); item != m_TaskInfoMap.constEnd(); ++item)
	{
		QRect cacheRect = item.value().m_Rect;
		if (cacheRect.contains(m_CurPos))
		{
			this->setCursor(QCursor(Qt::PointingHandCursor));
			this->update();
			return;
		}
	}

	this->setCursor(QCursor(Qt::ArrowCursor));
	this->update();
}

void GanttCanvasWgt::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::RightButton)
	{
		QMap<qint64, TaskInfo>::const_iterator item;
		for (item = m_TaskInfoMap.constBegin(); item != m_TaskInfoMap.constEnd(); ++item)
		{
			QRect cacheRect = item.value().m_Rect;
			if (cacheRect.contains(m_CurPos))
			{
				showMenu(cacheRect);
			}
		}
	}
}

void GanttCanvasWgt::showMenu(QRect rect)
{
	//tipRect.setX(tipRect.x() + 2 * m_paintSetting.taskTipSpacing);
	//tipRect.setY(tipRect.y() - m_paintSetting.lineHeight);

	QMenu *pMenu = new QMenu(this);
	QAction* pAction_0 = new QAction(QStringLiteral("操作1"), this);
	pMenu->addAction(pAction_0);
	QAction* pAction_1 = new QAction(QStringLiteral("操作2"), this);
	pMenu->addAction(pAction_1);
	QAction* pAction_2 = new QAction(QStringLiteral("操作3"), this);
	pMenu->addAction(pAction_2);
	pMenu->move(mapToGlobal(QPoint(rect.x() + 2 * m_paintSetting.taskTipSpacing, rect.y())));
	pMenu->show();
}