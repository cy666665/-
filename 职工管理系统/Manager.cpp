#include"manager.h"
//���캯��
Manager::Manager(int id, string name, int deptid, int salary)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptid;
	this->m_salary = salary;
}
//��ʾ������Ϣ
void Manager::ShowInfo()
{
	cout << "ְ�����:" << this->m_Id
		<< "\tְ������:" << this->m_Name
		<< "\t��λ:" << this->GetDeptName()
		<< "\tн�ʣ�" << this->m_salary
		<< "\t��λְ��:����ϰ彻�����񣬲����·��������ͨԱ��" << endl;
}
//��ȡ��λ����
string Manager::GetDeptName()
{
	return string("����");
}
