#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "main.h"

//修改学生信息
void Modify(struct node* L)
{
	char id[20];
	char choice; 
	char option; 
	struct node* p = L;
	
	printf("是否修改学生信息？  是请按1，否请按0\n\n"); 
	
	while (option != '0')
	{ 
	    option = _getch();
	    
	    if (option == '1')
	    {
			printf("请输入所要修改学生信息的学号:\n");
			scanf("%s", id);
		
			while (p->next != NULL)
			{
				if (strcmp(id, p->next->data.number) == 0)
				{
					printf("学号：%s\t姓名：%s\t数学成绩：%lf\t英语成绩：%lf\t专业成绩：%lf\n", p->next->data.number, p->next->data.name, p->next->data.math, p->next->data.english, p->next->data.cs);
				    printf("\n请选择您所要修改的项目：\n学生学号请按1，学生姓名请按2，数学成绩请按3，英语成绩请按4，专业成绩请按5，退出请按0\n\n");
					
					while (choice != '0')
					{
						choice = _getch();
						
						switch (choice)
						{
							case '1':
								printf("请输入修改后的学生学号：\n");
								scanf("%s", p->next->data.number);
								break;
							case '2':
								printf("请输入修改后的学生姓名：\n");
								scanf("%s", p->next->data.name);
								break;
							case '3':
								printf("请输入修改后的数学成绩：\n");
								scanf("%lf", &p->next->data.math);
								
								if ((p->next->data.math<0) || (p->next->data.math>100))
								{
									printf("* 数学成绩输入范围错误，请重新输入 *\n");
									return;
								}
								 
								break;
							case '4':
								printf("请输入修改后的英语成绩：\n");
								scanf("%lf", &p->next->data.english);
								
								if ((p->next->data.english<0) || (p->next->data.english>100))
								{
									printf("* 英语成绩输入范围错误，请重新输入 *\n");
									return;
								}
								 
								break;
							case '5':
								printf("请输入修改后的专业成绩：\n");
								scanf("%lf", &p->next->data.cs);
								
								if ((p->next->data.cs<0) || (p->next->data.cs>100))
								{
									printf("* 专业成绩输入范围错误，请重新输入 *\n");
									return;
								}
								
								break;
							case '0':
							    SaveFile(L);
								
								printf("* 已修改信息 *\n");
								 
								system("pause");
			                    system("cls");
								return;
							default:
								printf("* 输入有误，请输入正确的选项 *\n");
								break;
						}
				    }
				}
				p = p->next;
		    }
		
			printf("* 未找到学生信息 *\n");
			
			system("pause");
	        system("cls");
	        return;
	    }
	    else if (option == '0')
	    {
			printf("* 已退出 *\n");
			
			system("pause");
			system("cls");
	    	return;
		}
		else
		{
			printf("* 输入错误，请重新输入 *\n\n");
		}
    }
}
