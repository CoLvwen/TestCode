#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Max_Name 20
#define Max_Age 4
#define Max_Sex 4
#define Max_Tele 15
#define Max_Addr 20
#define MAX 1000

#define Begin 20
#define ADD 10

typedef struct Men
{
	char name[Max_Name];
	char age[Max_Age];
	char sex[Max_Sex];
	char tele[Max_Tele];
	char addr[Max_Addr];
}Men;

typedef struct Contact
{
	Men* data;
	int sz;
	int capacity;
}Contact;

void IniContact(Contact* p);
void AddContact(Contact* p);
void DelContact(Contact* p);
void ModContact(Contact* p);
void SeaContact(Contact* p);
void SorContact(Contact* p);
void PriContact(Contact* p);
void DestoryContact(Contact* p);
void SaveContact(Contact* p);