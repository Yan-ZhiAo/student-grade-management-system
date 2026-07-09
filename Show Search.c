#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

//显示学生信息
void Show(struct node* L)
{
	struct node* p = L->next;

	while (p != NULL)
	{
		printf("学号：%s\t\t姓名：%s\t数学成绩：%lf\t英语成绩：%lf\t专业成绩：%lf\n\n", p->data.number, p->data.name, p->data.math, p->data.english, p->data.cs);
		p = p->next;
	}
	
	system("pause");
	system("cls");
} 

//查询学生成绩
void Search(struct node* L)
{
	struct node* p = L->next;
	char id[20];

	printf("请输入所要查询学生成绩的学号：\n");
	scanf("%s", id);
	
	while (p != NULL)
	{
		if (strcmp(id, p->data.number) == 0)
		{
			printf("学号：%s\t姓名：%s\t数学成绩：%lf\t英语成绩：%lf\t专业成绩：%lf\n", p->data.number, p->data.name, p->data.math, p->data.english, p->data.cs); 
			
			system("pause");
	        system("cls");
			return;
		}
		p = p->next;
	}
	
	printf("* 未查询到该学生成绩，请重新输入 *\n");

	system("pause");
	system("cls");
} 
