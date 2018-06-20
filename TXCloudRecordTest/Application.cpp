#include "Application.h"
#include "log.h"
#include "TXCloudRecordCmd.h"

Application::Application()
{
}

Application::~Application()
{
}

Application& Application::instance()
{
    static Application uniqueInstance;
    return uniqueInstance;
}

int Application::run(int &argc, char **argv)
{
    LOGGER;
	RecordData recordData;

	strcpy_s(recordData.recordExe, "xxx"); //��¼��Ӧ�ó������� ����chrome.exe
	strcpy_s(recordData.recordUrl, "xxx"); //��Ҫ��Ϊ������ַ
	strcpy_s(recordData.recordPath, "F:\\"); //����·������û����mp4��β�����Զ�����Ϊ·��+yyyy_mm_dd_hh_mm_ss.mp4��ʽ
	recordData.recordType = RecordScreenToBoth;
	recordData.sliceTime = 60; //�����ļ���Ƭʱ�����Է���Ϊ��λ
	recordData.winID = -1;     //��¼�ƴ��ھ��

	TXCloudRecordCmd::instance().runAndRecord(recordData);
	system("pause");

	TXCloudRecordCmd::instance().stop();
	system("pause");
	
	recordData.recordType = RecordScreenToClient;
	TXCloudRecordCmd::instance().update(recordData);
	system("pause");

	TXCloudRecordCmd::instance().start();
	system("pause");

	TXCloudRecordCmd::instance().exit();
	system("pause");
    return 0;
}