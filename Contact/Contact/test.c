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
	IniContact(&con);//数据初始化
	void (*Con[6])(Contact*) = { 0 };
	Con[0] = &AddContact;	//添加
	Con[1] = &DelContact;	//删除
	Con[2] = &ModContact;	//修改
	Con[3] = &SeaContact;	//搜索
	Con[4] = &SorContact;	//排序
	Con[5] = &PriContact;	//打印
	do
	{
		menu();
		printf("请输入：");
		scanf("%d", &input);
		if (input <= Print && input > 0)
		{
			Con[input-1](&con); 
		}
		else if (input != 0)
		{
			printf("输入错误。\n");
		}
		//switch (input)
		//{
		//case Add:
		//	AddContact(&con);   //添加联系人
		//	break;
		//case Delete:
		//	DelContact(&con);	//删除联系人
		//	break;
		//case Modify:
		//	ModContact(&con);	//修改联系人
		//	break;
		//case Search:
		//	SeaContact(&con);	//搜索联系人
		//	break;
		//case Sort:
		//	SorContact(&con);	//排序联系人
		//	break;
		//case Print:
		//	PriContact(&con);	//输出联系人列表
		//	break;
		//case Exit:
		//	break;
		//default:
		//	printf("输入错误。\n请重新输入：");
		//	break;
		//}
	} while (input);
	printf("程序退出。");
	DestoryContact(&con);
	return 0;
}