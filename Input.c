#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "main.h"
 
//录入学生信息
void Input(struct node* L)
{
	char choice;
	 
	while (choice != '0')
	{
		printf("录入基本信息请按1，录入单科成绩请按2，退出请按0\n\n");
		choice = _getch();
	
		switch (choice)
		{	
			case '1':
				Basic(L);
				break;
			case '2':
				Score(L);
				break;
			case '0':
				printf("* 已退出 *\n");
				
				system("pause");
				system("cls");
				return;
			default:
				printf("* 输入有误，请重新输入 *\n");
				break;
		}
	}
} 

//录入学生基本信息
void Basic(struct node* L)
{
	int num;
	int i = 0;
	char choice;
	char input[20];
	struct node* rear = L;
	struct node* Tmpcell;
	
	printf("需录入多少个学生信息\n");
	scanf("%s", input);

    while (input[i] != '\0')
	{
		if ((input[i]<'0') || (input[i]>'9'))
		{
			printf("* 输入有误，请输入数字 *\n");
			
			system("pause");
			system("cls");
			return;
		}
		
		i++;
	} 
	
	num = atoi(input);
	
	printf("\n您将输入%d个学生信息\n\n", num);
	
	for (i=0; i<num; i++)
	{
		Tmpcell = (struct node*)malloc(sizeof(struct node));
		Tmpcell->next = NULL;
		
		printf("请输入学生的学号，姓名：\n");
		scanf("%s", Tmpcell->data.number);
		scanf("%s", Tmpcell->data.name);
		Tmpcell->data.math = 0;
		Tmpcell->data.english = 0;
		Tmpcell->data.cs = 0;
		
		rear->next = Tmpcell;
	    rear = Tmpcell;
	}
	
	SaveFile(L);
	
	printf("\n* 已完成 *\n");
	
	return;
    
}

//录入学生单科成绩信息
void Score(struct node* L)
{
	int num;
	int i = 0;
	char choice;
	char input[20];
	struct node* p = L;
	
    if (p->next == NULL)
    {
    	printf("* 无基本信息录入，请先录入学生基本信息 *\n\n");
    	return;
	}
	
    printf("请选择你所要输入的成绩，数学成绩请按1，英语成绩请按2，专业成绩请按3，退出请按0\n\n");	
    
    while (choice != '0')
	{ 
		choice = _getch();
		
		switch (choice)
		{
			case '1':
				p = L;
				
				while (p->next != NULL)
				{	
					printf("请输入%s %s的数学成绩：\n", p->next->data.number, p->next->data.name);
					scanf("%lf", &p->next->data.math);
					
					if ((p->next->data.math<0) || (p->next->data.math>100))
					{
						printf("* 数学成绩输入范围错误，请重新输入 *\n");
						return;
					} 
					
					p = p->next;
				}
				
				break;
			case '2':
				p = L;
				
				while (p->next != NULL)
				{	
					printf("请输入%s %s的英语成绩：\n", p->next->data.number, p->next->data.name);
					scanf("%lf", &p->next->data.english);
					
					if ((p->next->data.english<0) || (p->next->data.english>100))
					{
						printf("* 英语成绩输入范围错误，请重新输入 *\n");
						return;
					} 
					
					p = p->next;
				}
	
				break;
			case '3':
				p = L;
				
				while (p->next != NULL)
				{	
					printf("请输入%s %s的专业成绩：\n", p->next->data.number, p->next->data.name);
					scanf("%lf", &p->next->data.cs);
					
					if ((p->next->data.cs<0) || (p->next->data.cs>100))
					{
						printf("* 专业成绩输入范围错误，请重新输入 *\n");
						return;
					} 
					
					p = p->next;
				}
				
				break;
			case '0':
				SaveFile(L);
	
				printf("\n* 已完成 *\n");
				
				return;
			default:
				printf("* 输入有误，请重新输入 *\n");
				break;
		}		
	}
}
