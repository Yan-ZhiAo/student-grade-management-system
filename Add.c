#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "main.h"

//增加学生信息
void Add(struct node* L)
{
	struct node* rear = L;
	struct node* Tmpcell;
	char choice;
	 
	while (rear->next != NULL)
	{
		rear = rear->next;
	} 
	
	printf("是否增加学生信息？  是请按1，否请按0\n\n"); 
	
	while (choice != '0')
	{	
		choice = _getch();
		
		if (choice == '1')
		{
			Tmpcell = (struct node*)malloc(sizeof(struct node));
			Tmpcell->next = NULL;
			
			printf("请输入学生的学号，姓名，数学成绩，英语成绩，专业成绩：\n");
			scanf("%s", Tmpcell->data.number);
			scanf("%s", Tmpcell->data.name);
			
			scanf("%lf", &Tmpcell->data.math); 
			if ((Tmpcell->data.math<0) || (Tmpcell->data.math>100))
			{
				printf("* 数学成绩输入范围错误，请重新输入 *\n");
				return;
			} 
		    
			scanf("%lf", &Tmpcell->data.english);
			if ((Tmpcell->data.english<0) || (Tmpcell->data.english>100))
			{
				printf("* 英语成绩输入范围错误，请重新输入 *\n");
				return;
			} 
			
		    scanf("%lf", &Tmpcell->data.cs);
		    if ((Tmpcell->data.cs<0) || (Tmpcell->data.cs>100))
			{
				printf("* 专业成绩输入范围错误，请重新输入 *\n");
				return;
			} 
		    
		    rear->next = Tmpcell;
		    rear = Tmpcell;
	    }
	    else if (choice == '0')
	    {
			SaveFile(L);
			
			printf("* 已退出 *\n");
			
			system("pause");
			system("cls");
			return;
	    }
	    else
	    {
			printf("* 输入有误，请重新输入 *\n");
		}
		
		printf("\n是否继续增加学生信息？  是请按1，否请按0\n\n"); 
    }
}
