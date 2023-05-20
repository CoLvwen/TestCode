 #define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
#define MAX 1000
void menu()
{
	printf("**************************\n");
	printf("****1.ADD        2.DEL****\n");
	printf("****3.MOD 0.EXIT 4.SEA****\n");
	printf("****5.SOR        6.PRI****\n");
	printf("**************************\n");
}
enum Option
{
	Exit,
	Add,
	Delete,
	Modify,
	Search,
	Sort,
	Print
};

int main()
{
	int input = 0;
	Contact con;
	IniContact(&con);//���ݳ�ʼ��
	void (*Con[6])(Contact*) = { 0 };
	Con[0] = &AddContact;	//���
	Con[1] = &DelContact;	//ɾ��
	Con[2] = &ModContact;	//�޸�
	Con[3] = &SeaContact;	//����
	Con[4] = &SorContact;	//����
	Con[5] = &PriContact;	//��ӡ
	do
	{
		menu();
		printf("�����룺");
		scanf("%d", &input);
		if (input <= Print && input > 0)
		{
			Con[input-1](&con); 
		}
		else if (input != 0)
		{
			printf("�������\n");
		}
		//switch (input)
		//{
		//case Add:
		//	AddContact(&con);   //�����ϵ��
		//	break;
		//case Delete:
		//	DelContact(&con);	//ɾ����ϵ��
		//	break;
		//case Modify:
		//	ModContact(&con);	//�޸���ϵ��
		//	break;
		//case Search:
		//	SeaContact(&con);	//������ϵ��
		//	break;
		//case Sort:
		//	SorContact(&con);	//������ϵ��
		//	break;
		//case Print:
		//	PriContact(&con);	//�����ϵ���б�
		//	break;
		//case Exit:
		//	break;
		//default:
		//	printf("�������\n���������룺");
		//	break;
		//}
	} while (input);
	printf("�����˳���");
	DestoryContact(&con);
	return 0;
}