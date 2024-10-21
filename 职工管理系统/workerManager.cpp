#include"workerManager.h"

//���캯��
WorkerManager::WorkerManager()
{
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		//��ʼ������
		//��ʼ����¼����Ϊ0
		this->m_EmpNum = 0;
		//��ʼ������ָ��Ϊ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.�ļ����� ����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//��ʼ������
		//��ʼ����¼����Ϊ0
		this->m_EmpNum = 0;
		//��ʼ������ָ��Ϊ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
	}
	//3.�ļ����ڲ�Ϊ��
	int num = this->Get_EmpNum();
	this->m_EmpNum = num;
	//���ٿռ䣬���ļ��е����ݴ浽������
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->Init_Emp();

}
//չʾ�˵�
void WorkerManager::Show_Menu()
{
	
	cout << "******************************" << endl;
	cout << "*****��ӭʹ��ְ������ϵͳ*****" << endl;
	cout << "*******0-�˳��������*********" << endl;
	cout << "*******1-����ְ����Ϣ*********" << endl;
	cout << "*******2-��ʾְ����Ϣ*********" << endl;
	cout << "*******3-ɾ����ְְ��*********" << endl;
	cout << "*******4-�޸�ְ����Ϣ*********" << endl;
	cout << "*******5-����ְ����Ϣ*********" << endl;
	cout << "*******6-���ձ������*********" << endl;
	cout << "*******7-��������ĵ�*********" << endl;
	cout << "*******8-�޸ĵ�¼����*********" << endl;
	cout << "******************************" << endl;
}
//�˳�ϵͳ
void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	//�˳��ĺ���
	exit(0);
}
//���ְ��
void WorkerManager::AddEmp()
{
	cout << "���������ְ��������" << endl;
	int addnum = 0;//�����û����������
	cin >> addnum;
	if (addnum > 0)
	{
		//������������¿ռ�Ĵ�С
		int NewSize = this->m_EmpNum + addnum;//���������������ԭ����+����ӵ�
		//�����¿ռ䡪����̬����
		Worker** NewSpace = new Worker * [NewSize];
		//��ԭ���ռ��µ����ݿ������¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				NewSpace[i] = this->m_EmpArray[i];
			}
		}
		//����µ�����
		for (int i = 0; i < addnum; i++)
		{
			int id = 0;//ְ�����
			string name;//ְ������
			int dselect;//����ѡ��
			int salary;//ְԱн��
			cout << "�������" << i + 1 << "����ְ���ı��" << endl;
			/*
				������ж������ظ�����ȱ�ݵģ���������Ҫ���2����Ա�����������ĵڶ����˺͵�һ���˵ı��һ����
				�������жϲ������ظ��ˣ�
			*/
			while (cin >> id)
			{
				int adjust = 0;
				for (int j = 0; j < this->m_EmpNum; j++)
				{
					if (id == this->m_EmpArray[j]->m_Id)
					{
						cout << "�˱���Ѵ���!����������" << endl;
						adjust = 1;
					}
				}
				if (adjust == 0)
				{
					break;
				}
			}
			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dselect;
			cout << "�������ְԱ��н��" << endl;
			cin >> salary;
			Worker* worker = NULL;
			switch (dselect)
			{
			case 1:
				worker = new Employee(id, name, 1,salary);
				break;
			case 2:
				worker = new Manager(id, name, 2, salary);
				break;
			case 3:
				worker = new Boss(id, name, 3, salary);
				break;
			default:
				break;
			}

			//��������ְ��ָ�룬���浽�����У���Ҫָ�����ڵ����һ��ְ��
			NewSpace[this->m_EmpNum + i] = worker;
		}
		//�ͷ�ԭ�еĿռ�
		delete[] this->m_EmpArray;
		//�����¿ռ��ָ��
		this->m_EmpArray = NewSpace;
		//����ְ������
		this->m_EmpNum = NewSize;
		//����ְ����Ϊ�յı�־
		this->m_FileIsEmpty = false;
		//��ʾ
		cout << "�ɹ����" << addnum << "����ְ��" << endl;
		//�������ݵ��ļ���
		this->SaveFile();
	}
	else
	{
		cout << "��������" << endl;
	}
	//�������������
	system("pause");
	system("cls");
}
//�����ļ�
void WorkerManager::SaveFile()
{
	ofstream ofs;
	ofs.open("test.txt", ios::out);//�������ʽ���ļ�����д�ļ�
	//��ÿ���˵�����д�뵽�ļ�
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<<this->m_EmpArray[i]->m_salary<<" "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
}
//ͳ������
int WorkerManager::Get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�
	int id;
	string name;
	int did;
	int salary;
	//������
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did&&ifs>>salary)
	{
		num++;
	}
	return num;
}
//��ʼ��ְ��
void WorkerManager::Init_Emp()
{
	//���ļ���������ݶ�����
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;
	int salary;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did&& ifs>>salary)
	{
		Worker* worker = NULL;
		if (did == 1)
		{
			worker = new Employee(id, name, did, salary);
		}
		else if (did == 2)
		{
			worker = new Manager(id, name, did, salary);
		}
		else
		{
			worker = new Boss(id, name, did, salary);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}
//��ʾְ��
void WorkerManager::Show_Emp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//���ö������ó���ӿ�
			this->m_EmpArray[i]->ShowInfo();
		}
	}
	//�������������
	system("pause");
	system("cls");
}
//�ж�ְ���Ƿ����
int WorkerManager::IsExist(int id)
{
	int index = -1;//һ��ʼ�϶�������
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			//�ҵ�ְ��
			index = i;
			break;
		}
	}
	return index;
}
//ɾ��ְ��
void  WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		//����ְ���ı����ɾ��ְ��
		cout << "������Ҫɾ��ְ���ı��" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)//����-ɾ��
		{
			//��������ɾ�����ݱ����Ͼ�������ǰ��
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//���������м�¼��Ա����
			this->m_EmpNum--;
			//����ͬ�����µ��ļ���
			this->SaveFile();
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���Ա��" << endl;
		}
		//�����������
		system("pause");
		system("cls");
	}
}
//�޸�ְ��
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�ְ�����" << endl;
		int id = 0;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//���ҵ���
			delete this->m_EmpArray[ret];//ɾ���ɵģ������µ�
			int newid = 0;;
			string newname = " ";
			int newselect = 0;
			int newsalary=0;
			cout << "���ҵ��˱��Ϊ" << id << "�����ְ��," << "�������µ�ְ����" << endl;
			cin >> newid;
			cout << "�������µ�����" << endl;
			cin >> newname;
			cout << "�������µĸ�λ" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> newselect;
			cout << "�������µ�н��" << endl;
			cin >> newsalary;
			Worker* worker = NULL;
			switch (newselect)
			{
			case 1:
				worker = new Employee(newid, newname, newselect,newsalary);
				break;
			case 2:
				worker = new Manager(newid, newname, newselect, newsalary);
				break;
			case 3:
				worker = new Boss(newid, newname, newselect, newsalary);
				break;
			default:
				break;
			}
			//�������ݵ�������
			this->m_EmpArray[ret] = worker;
			cout << "�޸ĳɹ�!" << endl;
			this->SaveFile();//���浽�ļ���
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴��ˡ�" << endl;
		}
	}
	system("pause");
	system("cls");
}
//����ְ��
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ" << endl;
		cout << "1.��ְ����Ų���" << endl;
		cout << "2.��ְ����������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//���ձ�Ų�
			int id;
			cout << "��������ҵ�ְ�����" << endl;
			cin >> id;
			int ret = this->IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ������Ϣ����:" << endl;
				this->m_EmpArray[ret]->ShowInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���!" << endl;
			}
		}
		else if (select == 2)
		{
			//������������
			string name;
			cout << "������Ҫ���ҵ�����" << endl;
			cin >> name;
			//�����ж��Ƿ�鵽�ı�־
			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ�,ְ�����Ϊ" << this->m_EmpArray[i]->m_Id << "��ְ����������Ϣ����:" << endl;
					this->m_EmpArray[i]->ShowInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else
		{
			cout << "����ѡ������" << endl;
		}
		//�����������
		system("pause");
		system("cls");
	}
}
//Ա������
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		system("system");
		system("clsf");
	}
	else
	{
		cout << "��ѡ������ʽ" << endl;
		cout << "1.����ְ���Ž�������" << endl;
		cout << "2.����ְ���Ž��н���" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int MinOrMax = i;//�������ֵ����Сֵ�±�
			for (int j = i + 1; j < this->m_EmpNum; j++)//��Ҫ�Ƚ����Դ�1��ʼ
			{
				if (select == 1)
				{
					//����
					if (this->m_EmpArray[MinOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						MinOrMax = j;
					}
				}
				else
				{
					//����
					if (this->m_EmpArray[MinOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						MinOrMax = j;
					}
				}
			}
			//�ж�һ��ʼ�϶������ֵ����Сֵ�ǲ��Ǽ�������ֵ����Сֵ��������Ǿͽ���
			if (i != MinOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[MinOrMax];
				this->m_EmpArray[MinOrMax] = temp;
			}
		}
		cout << "����ɹ��������Ľ��Ϊ:" << endl;
		this->SaveFile();//�������Ľ�����浽�ļ���
		this->Show_Emp();//չʾ����ְ��
	}
}
//�޸�����1
 void WorkerManager::setPassword(const string & password) {
ofstream file("password.txt");
if (file.is_open()) {
	file << password;
	file.close();
	cout << "�ɹ���������." << endl;
}
else {
	cout << "δ�ܳɹ����ļ�." << endl;
}
	}
 //�޸�����2
  bool WorkerManager::checkPassword(const string& password) {
 ifstream file("password.txt");
 if (file.is_open()) {
	 string storedPassword;
	 file >> storedPassword;
	 file.close();
	 return (password == storedPassword);
 }
 else {
	 cout << "δ�ܳɹ����ļ�." << endl;
	 return false;
 }
}
//�޸�����3
void WorkerManager::chng_code() {
	cout << "������ԭ����" << endl;
	string a;
	cin >> a;
	if (checkPassword(a)) {
		cout << "������ȷ" << endl;
		cout << "������Ҫ�޸ĵ�����" << endl;
		string b;
		cin >> b;
		cout << "���ٴ���������" << endl;
		string c;
		cin >> c;
		if (b == c) {
			setPassword(b);
			system("pause");
		}
		else { cout << "���벻һ�£��޷��޸�" << endl; system("pause"); }
	}
	else { cout << "�������" << endl; system("pause"); }
	system("cls");
}
//����ļ�
void WorkerManager::Clean_File()
{
	cout << "ȷ�������?" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.ȡ��" << endl;
	int select = 0;;
	cin >> select;
	if (select == 1)
	{
		//����ļ�
		ofstream ofs(FILENAME, ios::trunc);
		ofstream ofs1(FILENAME1, ios::trunc);
		ofs.close(); ofs1.close();
		if (this->m_EmpArray != NULL)
		{
			//ɾ��������ÿ������
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
			}
			//ɾ����������ָ��
			delete this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ���" << endl;

	}
	ExitSystem();
	system("pause");
	system("cls");
}
//��������
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			delete this->m_EmpArray[i];
		}
		delete this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
