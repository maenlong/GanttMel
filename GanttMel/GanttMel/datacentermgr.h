#ifndef DATACENTERMGR_H
#define DATACENTERMGR_H

#include <QObject>
#include "datadefine.h"
#include <QDebug>
#include <QMutex>

class DataCenterMgr : public QObject
{
	Q_OBJECT

public:
	~DataCenterMgr();
	static DataCenterMgr* instance();

	bool addTaskInfo(TaskInfo info, NotifyType type = e_None);
	bool delTaskInfo(TaskInfo info, NotifyType type = e_None);
	bool updateTaskInfo(TaskInfo info, NotifyType type = e_None);
	bool clearTaskInfo(TaskInfo info, NotifyType type = e_None);
	TaskInfo findTaskInfo(qint64 key);

private:
	DataCenterMgr();

signals:
	void sig_addTaskInfo(TaskInfo info, NotifyType type);
	void sig_delTaskInfo(TaskInfo info, NotifyType type);
	void sig_updateTaskInfo(TaskInfo info, NotifyType type);
	void sig_clearTaskInfo(TaskInfo info, NotifyType type);

private:
	static DataCenterMgr* m_pInstance;
	QMap<qint64, TaskInfo> m_TaskInfoMap;
	QMutex m_MutexData;
};

#endif // DATACENTERMGR_H
