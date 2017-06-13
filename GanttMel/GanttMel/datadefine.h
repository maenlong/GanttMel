#ifndef DATADEFINE
#define DATADEFINE

#include <QRect>
#include <QColor>
#include <QDateTime>

// ��������
enum AccuracyType
{
	e_Day = 0,                         // ��
	e_Week = 1,                      // ��
	e_Month = 2,                     // ��
	e_AccuracyCount = 3         // ����
};

// ��������
enum ArrowType
{
	e_NoLine = 0,                  // ����
	e_StraightLine = 1,           // ֱ��
	e_BrokenLine = 2,            // ����
	e_ArrowCount = 3           // ����
};

//��ͼ����
struct PaintSetting
{
	int dayWidth;		    //һ����
	int weekWidth;	        //һ�ܿ��
	int monthWidth;		//һ�¿��

	int lineHeight;		    //һ�и߶�
	int taskBarHeight;	    //�������߶�
	int taskTipSpacing;	//��������ʾ���

	QColor titleBgColor;		//����������ɫ
	QColor taskBarColor;	//��������ɫ
	QColor taskHoverColor;//��������ɫ
	QColor taskTipColor;		//����������ɫ

	AccuracyType accuracyType;//��������
	ArrowType arrowType;//��������
	bool bNeedDivider;//�ָ���

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


// ֪ͨ����
enum NotifyType
{
	e_None = 0,                  // �޶���
	e_Form = 1,                  // ���
	e_Chart = 2,                  // ͼ��
	e_Both = 3,                   // ȫ��
	e_NotifyCount = 3        // ����
};


struct TaskInfo
{
	QDateTime		m_StartDate;				//��ʼ����
	QDateTime		m_EndDate;				//��������
	qint64				m_nTakeCycle;			//��������
	QString				m_sTaskName;			//��������
	QString				m_sUserName;			//����������

	qint64				m_nTaskIndex;			//�������
	qint64				m_nTaskLevel;			//���񼶱�
	QString				m_sTaskID;				//����ID
	QString				m_sFrontTaskID;			//ǰ������ID
	QString				m_sParentTaskID;		//��������ID
	QRect				m_Rect;						//��ͼ����

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