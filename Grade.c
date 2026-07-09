#include <stdio.h>
#include <stdlib.h>
#include "main.h"

//封装排名 
void Grade(struct node* L)
{
	MathGrade(L);
    EnglishGrade(L);
    CsGrade(L);
    
    system("pause");
    system("cls");
}

//数学成绩排序 
void MathGrade(struct node* L)
{
	struct node* p = NULL;
	struct node* q = NULL;
	struct student temp;
	
	for (p=L->next; p->next!=NULL; p=p->next)
	{
		for (q=L->next; q->next!=NULL; q=q->next)
		{
			if (q->data.math < q->next->data.math)
			{
				temp = q->data;
				q->data = q->next->data;
				q->next->data = temp;
			}
		}
	}
	
	ShowMath(L); 
}

void ShowMath(struct node* L)
{
	struct node* p = L->next;
	int i = 1;
	
	printf("\t\t* 数学成绩排名 *\n\n");
	printf("排名\t学号\t\t姓名\t\t成绩\n");
	printf("-------------------------------------------------\n");
	
	while (p != NULL)
	{
		printf("%d\t%s\t\t%s\t\t%lf\n", i, p->data.number, p->data.name, p->data.math);
		i++;
		p = p->next;
	}
} 

//英语成绩排序 
void EnglishGrade(struct node* L)
{
    struct node* p = NULL;
	struct node* q = NULL;
	struct student temp;
	
	for (p=L->next; p->next!=NULL; p=p->next)
	{
		for (q=L->next; q->next!=NULL; q=q->next)
		{
			if (q->data.english < q->next->data.english)
			{
				temp = q->data;
				q->data = q->next->data;
				q->next->data = temp;
			}
		}
	}
	
	ShowEnglish(L);
}

void ShowEnglish(struct node* L)
{
	struct node* p = L->next;
	int i = 1;
	
	printf("\n\t\t* 英语成绩排名 *\n\n");
	printf("排名\t学号\t\t姓名\t\t成绩\n");
	printf("-------------------------------------------------\n");
	
	while (p != NULL)
	{
		printf("%d\t%s\t\t%s\t\t%lf\n", i, p->data.number, p->data.name, p->data.english);
		i++;
		p = p->next;
	}
} 

//专业成绩排序 
void CsGrade(struct node* L)
{
    struct node* p = NULL;
	struct node* q = NULL;
	struct student temp;
	
	for (p=L->next; p->next!=NULL; p=p->next)
	{
		for (q=L->next; q->next!=NULL; q=q->next)
		{
			if (q->data.cs < q->next->data.cs)
			{
				temp = q->data;
				q->data = q->next->data;
				q->next->data = temp;
			}
		}
	}

	ShowCs(L); 
}
 
void ShowCs(struct node* L)
{
	struct node* p = L->next;
	int i = 1;
	
	printf("\n\t\t* 专业成绩排名 *\n\n"); 
	printf("排名\t学号\t\t姓名\t\t成绩\n");
    printf("-------------------------------------------------\n");

	while (p != NULL)
	{
		printf("%d\t%s\t\t%s\t\t%lf\n", i, p->data.number, p->data.name, p->data.cs);
		i++;
		p = p->next;
	}
}
