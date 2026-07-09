#include <stdio.h>
#include <stdlib.h>
#include "main.h"

//不及格超过2科学生名单
void Failed(struct node* L)
{
	struct node* p = L->next;
	int i = 0;
	int flag = 0;
	
	printf("* 不及格超过2科学生名单 *\n\n"); 
	while (p != NULL)
	{
		if (p->data.math < 60)
		{
			i++;
		}
		if (p->data.english < 60)
		{
			i++;
		}
		if (p->data.cs < 60)
		{
			i++;
		}
		
		if (i >= 2)
		{
			printf("学号：%s\t姓名：%s\n\n", p->data.number, p->data.name);
			flag = 1;
		}
		
		i = 0;
		p = p->next;
	}
	
	if (flag == 0)
	{
		printf("   * 无！*\n");
	}
	
	system("pause");
	system("cls");
} 
