#include<iostream>
#include"workerManager.h"
#include"worker.h"
#include"employee.h"   
#include"manager.h"
#include"boss.h"
using namespace std;

int main(void)
{
	WorkerManager wm;
	string code;
	ifstream ifs;
	ifs.open("password.txt", ios::in);
	char a;
	ifs >> a;
	if (ifs.eof()) {
		cout << "�����ó�ʼ����" << endl;
		cin >> code;
		wm.setPassword(code);
		cout << "��ʼ�������óɹ�!" << endl;
	}
	cout << "�����������¼" << endl;
		string m_code;
		cin >> m_code;
		while (1) {
			if (wm.checkPassword(m_code)) {
				cout << "��¼�ɹ���" << endl;
				break;
			}
			else { cout << "�������" << endl; cin >> m_code;
			}
		}
	
	//ʵ����һ�������ߵĶ���
	
	int choice = 0;//�����洢�û���ѡ��
	while (1)
	{
		//��ʾ�˵�
		wm.Show_Menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1://���ְ��
			wm.AddEmp();
			break;
		case 2://��ʾְ��
			wm.Show_Emp();
			break;
		case 3://ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4://�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5://����ְ��
			wm.Find_Emp();
			break;
		case 6://����ְ��
			wm.Sort_Emp();
			break;
		case 7://����ļ�
			wm.Clean_File();
			break;
		case 8://�޸�����
			wm.chng_code();
			break;
		default:
			system("cls");//����
			break;
		}

	}
	system("pause");
	return 0;
}

