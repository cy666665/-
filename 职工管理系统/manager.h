#pragma once
#include<iostream>
#include"worker.h"
#include<string>
using namespace std;
//������
class Manager :public Worker
{
public:
	//���캯��
	Manager(int id, string name, int deptid, int salary);
	//��ʾ������Ϣ
	virtual void ShowInfo();
	//��ȡ��λ����
	virtual string GetDeptName();
};
