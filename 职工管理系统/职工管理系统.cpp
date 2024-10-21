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
		cout << "请设置初始密码" << endl;
		cin >> code;
		wm.setPassword(code);
		cout << "初始密码设置成功!" << endl;
	}
	cout << "请输入密码登录" << endl;
		string m_code;
		cin >> m_code;
		while (1) {
			if (wm.checkPassword(m_code)) {
				cout << "登录成功！" << endl;
				break;
			}
			else { cout << "密码错误" << endl; cin >> m_code;
			}
		}
	
	//实例化一个管理者的对象
	
	int choice = 0;//用来存储用户的选择
	while (1)
	{
		//显示菜单
		wm.Show_Menu();
		cout << "请输入你的选择" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://退出系统
			wm.ExitSystem();
			break;
		case 1://添加职工
			wm.AddEmp();
			break;
		case 2://显示职工
			wm.Show_Emp();
			break;
		case 3://删除职工
			wm.Del_Emp();
			break;
		case 4://修改职工
			wm.Mod_Emp();
			break;
		case 5://查找职工
			wm.Find_Emp();
			break;
		case 6://排序职工
			wm.Sort_Emp();
			break;
		case 7://清空文件
			wm.Clean_File();
			break;
		case 8://修改密码
			wm.chng_code();
			break;
		default:
			system("cls");//清屏
			break;
		}

	}
	system("pause");
	return 0;
}

