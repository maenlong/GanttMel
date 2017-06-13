#include "datacentermgr.h"
#include <QDebug>

DataCenterMgr* DataCenterMgr::m_pInstance = NULL;

DataCenterMgr::DataCenterMgr()
{

}

DataCenterMgr::~DataCenterMgr()
{

}

DataCenterMgr* DataCenterMgr::instance()
{
	if (m_pInstance == NULL)
	{
		m_pInstance = new DataCenterMgr;
	}
	return m_pInstance;
}

bool DataCenterMgr::addTaskInfo(TaskInfo info, NotifyType type)
{
	bool ret = false;
	m_MutexData.lock();

	QMap<qint64, TaskInfo>::const_iterator item;
	for (item = m_TaskInfoMap.constBegin(); item != m_TaskInfoMap.constEnd(); ++item)
	{
		TaskInfo cacheInfo = item.value();
		if (cacheInfo.m_nTaskIndex == info.m_nTaskIndex)
		{
			m_MutexData.unlock();
			return false;
		}
	}

	m_TaskInfoMap.insert(info.m_nTaskIndex, info);
	ret = true;

	m_MutexData.unlock();

	if (ret == true)
		emit sig_addTaskInfo(info,type);

	return ret;
}

bool DataCenterMgr::delTaskInfo(TaskInfo info, NotifyType type)
{
	bool ret = false;
	m_MutexData.lock();

	QMap<qint64, TaskInfo>::const_iterator item;
	for (item = m_TaskInfoMap.constBegin(); item != m_TaskInfoMap.constEnd(); ++item)
	{
		TaskInfo cacheInfo = item.value();
		if (cacheInfo.m_nTaskIndex == info.m_nTaskIndex)
		{
			m_TaskInfoMap.remove(info.m_nTaskIndex);
			ret = true;
		}
	}

	if (ret == true)
		emit sig_delTaskInfo(info, type);

	m_MutexData.unlock();
	return ret;
}

bool DataCenterMgr::updateTaskInfo(TaskInfo info, NotifyType type)
{
	bool ret = false;
	m_MutexData.lock();

	QMap<qint64, TaskInfo>::const_iterator item;
	for (item = m_TaskInfoMap.constBegin(); item != m_TaskInfoMap.constEnd(); ++item)
	{
		TaskInfo cacheInfo = item.value();
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

			ret = true;
		}
	}

	if (ret == true)
		emit sig_updateTaskInfo(info, type);

	m_MutexData.unlock();
	return ret;
}

bool DataCenterMgr::clearTaskInfo(TaskInfo info, NotifyType type)
{
	bool ret = false;
	m_MutexData.lock();

	m_TaskInfoMap.clear();
	ret = true;

	if (ret == true)
		emit sig_clearTaskInfo(info, type);

	m_MutexData.unlock();
	return ret;
}

TaskInfo DataCenterMgr::findTaskInfo(qint64 key)
{
	m_MutexData.lock();
	TaskInfo cacheInfo = m_TaskInfoMap.find(key).value();
	m_MutexData.unlock();
	return cacheInfo;
}
