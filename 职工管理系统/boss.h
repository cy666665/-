#pragma once
#include<iostream>
#include"worker.h"
#include<string>
using namespace std;
//�ϰ���
class Boss :public Worker
{
public:
	//���캯��
	Boss(int id, string name, int deptid, int salary);
	//��ʾ������Ϣ
	virtual void ShowInfo();
	//��ȡ��λ����
	virtual string GetDeptName();
};
