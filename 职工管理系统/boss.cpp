#include"boss.h"
//���캯��
Boss::Boss(int id, string name, int deptid, int salary)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptid;
	this->m_salary = salary;
}
//��ʾ������Ϣ
void Boss::ShowInfo()
{
	cout << "ְ�����:" << this->m_Id
		<< "\tְ������:" << this->m_Name
		<< "\t��λ:" << this->GetDeptName()
		<< "\tн�ʣ�" << this->m_salary
		<< "\t��λְ��:����˾���е�����" << endl;
}
//��ȡ��λ����
string Boss::GetDeptName()
{
	return string("�ϰ�");
}
