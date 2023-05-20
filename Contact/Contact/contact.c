#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"

enum data
{
	Exit,
	name,
	age,
	sex,
	addr
};

void Print(const Contact* p, int i)
{
	printf("%-10s\t%-4s\t%-4s\t%-15s\t%-20s\t\n",
		p->data[i].name,
		p->data[i].age,
		p->data[i].sex,
		p->data[i].tele,
		p->data[i].addr);
}
void Search(char* p,char* pc,int i,const Contact* p1)
{
	int tmp = 0;
	for (int i = 0; i < p1->sz; i++)
	{
		if (memcmp(pc,p+i*sizeof(Men), i) == 0)
		{
			if (tmp == 0)
			{
				printf("%-10s\t%-4s\t%-4s\t%-15s\t%-20s\t\n", "名字", "年龄", "性别", "电话", "地址");
				tmp++;
			}
			Print(p1,i);
		}
	}
	if (tmp == 0)
	{
		printf("不存在此人。\n请再次选择。\n");
	}
}
void Add(Contact* p)
{
	Men* tmp = (Men*)realloc(p->data, (p->capacity + ADD) * sizeof(Men));
	if (tmp != NULL)
	{
		p->capacity += ADD;
		p->data = tmp;
	}
	else
	{
		perror("Add");
	}
}
void menu1()
{
	printf("************************\n");
	printf("****1.名字    2.年龄****\n");
	printf("****3.性别    4.电话****\n");
	printf("****5.住址    0.退出****\n");
	printf("************************\n");
}
int  CmpName(const void* p1, const void* p2)
{
	Men* pc1 = (Men*)p1;
	Men* pc2 = (Men*)p2;
	return strcmp(pc1->name, pc2->name);
}
int  CmpAge(const void* p1, const void* p2)
{
	Men* pc1 = (Men*)p1;
	Men* pc2 = (Men*)p2;
	return strcmp(pc1->age, pc2->age);
}
int  CmpSex(const void* p1, const void* p2)
{
	Men* pc1 = (Men*)p1;
	Men* pc2 = (Men*)p2;
	return strcmp(pc1->sex, pc2->sex);
}
int  CmpAddr(const void* p1, const void* p2)
{
	Men* pc1 = (Men*)p1;
	Men* pc2 = (Men*)p2;
	return strcmp(pc1->addr, pc2->addr);
}

void IniContact(Contact* p)
{
	/*memset(p->data,0,sizeof(p->data));
	p->sz = 0;*/
	p->data = (Men*)malloc(Begin * sizeof(Men));
	if (p->data == NULL)
	{
		perror("IniContact");
		return;
	}
	p->sz = 0;
	p->capacity = Begin;
	FILE* pf = fopen("Contact.dat", "a");
	fclose(pf);
	pf = fopen("Contact.dat", "r");
	if (pf == NULL)
	{
		perror("IniContact");
		return 1;
	}
	Men tmp = { 0 };
	while (fread(&tmp, sizeof(Men), 1, pf))
	{
		if (p->sz == p->capacity)
		{
			Add(p);
		}
		p->data[p->sz] = tmp;
		p->sz++;
	}
	fclose(pf);
	pf = NULL;
}
void AddContact(Contact* p)
{
	//int input = 0;
	//do
	//{
	if (p->sz == p->capacity)
	{
		Add(p);
	}
	printf("请输入名字：");
	scanf("%s", p->data[p->sz].name);
	printf("请输入年龄：");
	scanf("%s", p->data[p->sz].age);
	printf("请输入性别：");
	scanf("%s", p->data[p->sz].sex);
	printf("请输入电话：");
	scanf("%s", p->data[p->sz].tele);
	printf("请输入地址：");
	scanf("%s", p->data[p->sz].addr);
	p->sz++;
	printf("添加成功。\n");
	PriContact(p);
	SaveContact(p);
	//	printf("1.继续添加    0.退出\n");
	//	printf("请输入：");
	//	scanf("%d", &input);
	//} while (input);
	system("cls");
}
void DelContact(Contact* p)
{
	int input = 0;
	int a = 0;
	PriContact(p);
	do
	{
		if (p->sz == 0)
		{
			printf("通讯录已清空。");
			break;
		}
		printf("请输入名字：");
		char tmp[Max_Name] = { 0 };
		scanf("%s", tmp);
		for (int i = 0; i < p->sz; i++)
		{
			if (!strcmp(p->data[i].name, tmp))
			{
				for (int j = i; j < p->sz; j++)
				{
					p->data[j] = p->data[j + 1];
				}
				p->sz--;
				a++;
				i = 0;
			}
		}
		if (a)
		{
			printf("删除成功。\n");
			PriContact(p);
		}
		else
		{
			printf("找不到此人。\n");
		}
		printf("1.继续删除    0.退出\n");
		printf("请输入：");
		scanf("%d", &input);
		SaveContact(p);
	} while (input);
	system("cls");
}
void ModContact(Contact* p)
{
	int input = 0;
	int a = 0;
	PriContact(p);
	do
	{
		if (p->sz == 0)
		{
			printf("通讯录为空。");
			break;
		}
		printf("请输入修改人的名字：");
		char tmp[Max_Name] = { 0 };
		scanf("%s", tmp);
		for (int i = 0; i < p->sz; i++)
		{
			if (!strcmp(p->data[i].name, tmp))
			{
				printf("请输入名字：");
				scanf("%s", p->data[i].name);
				printf("请输入年龄：");
				scanf("%s", p->data[i].age);
				printf("请输入性别：");
				scanf("%s", p->data[i].sex);
				printf("请输入电话：");
				scanf("%s", p->data[i].tele);
				printf("请输入地址：");
				scanf("%s", p->data[i].addr);
				a++;
			}
		}
		if (a)
		{
			printf("修改成功。\n");
			PriContact(p);
		}
		else
		{
			printf("找不到此人。\n");
		}
		printf("1.继续修改    0.退出\n");
		printf("请输入：");
		scanf("%d", &input);
		SaveContact(p);
	} while (input);
	system("cls");
}
void SeaContact(Contact* p)
{
	char tmp[20] = { 0 };
	int input = 0;
	do
	{
		menu1();
		printf("请选择查找内容：");
		scanf("%d", &input);
		if (input == 0)
			break;
		printf("请输入查找内容：");
		scanf("%s", tmp);
		switch (input)
		{
		case name:
			Search(p->data[0].name, tmp, Max_Name,p);
			break;
		case age:
			Search(p->data[0].age, tmp, Max_Age, p);
			break;
		case sex:
			Search(p->data[0].sex, tmp, Max_Sex, p);
			break;
		case addr:
			Search(p->data[0].addr, tmp, Max_Addr, p);
			break;
		case Exit:
			break;
		default:
			break;
		}
	} while (input);
	printf("退出搜索");
	system("cls");
}
void SorContact(Contact* p)
{
	int input=0;
	int (*cmp[5])(const void*,const void*) = {0};
	cmp[0] = &CmpName;
	cmp[1] = &CmpAge;
	cmp[2] = &CmpSex;
	cmp[3] = &CmpAddr;
	//qsort(p->data, p->sz, sizeof(p->data[0]),cmp[input]);
	do
	{
		menu1();
		printf("请选择排序内容：");
		scanf("%d", &input);
		switch (input)
		{
		case name:
			qsort(p->data, p->sz, sizeof(p->data[0]), cmp[input-1]);
			break;
		case age:
			qsort(p->data, p->sz, sizeof(p->data[0]), cmp[input-1]);
			break;
		case sex:
			qsort(p->data, p->sz, sizeof(p->data[0]), cmp[input-1]);
			break;
		case addr:
			qsort(p->data, p->sz, sizeof(p->data[0]), cmp[input-1]);
			break;
		case Exit:
			break;
		default:
			break;
		}
		PriContact(p);
	} while (input);
	printf("退出排序");
	system("cls");
}
void PriContact(Contact* p)
{
	printf("\n%-10s\t%-4s\t%-4s\t%-15s\t%-20s\t\n", "名字", "年龄", "性别", "电话", "地址");
	for (int i = 0; i < p->sz; i++)
	{
		printf("%-10s\t%-4s\t%-4s\t%-15s\t%-20s\t\n",
			p->data[i].name,
			p->data[i].age,
			p->data[i].sex,
			p->data[i].tele,
			p->data[i].addr);
	}
	system("pause");
}

void SaveContact(Contact* p)
{
	FILE* pf = fopen("Contact.dat", "w");
	if (pf == NULL)
	{
		perror("SaveContact");
		return 1;
	}
	for (int i = 0; i < p->sz; i++)
	{
		fwrite(p->data+i, sizeof(Men), 1, pf);
	}
	fclose(pf);
	pf = NULL;
}
void DestoryContact(Contact* p)
{
	free(p->data);
	p->data = NULL;
	p->capacity = 0;
	p->sz = 0;
}