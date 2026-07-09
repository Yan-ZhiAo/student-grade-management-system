#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "main.h"

int main(int argc, char** argv) 
{
	struct node* L;
	char choice;
	
	L = (struct node*)malloc(sizeof(struct node));
	L->next = NULL;
	
	if (Login())
	{
		ReadFile(L);
		
		while (choice != '9')
		{
			Menu();
					
			choice = _getch();
			
			switch (choice)        
			{
				case '1':            //录入学生信息
					Input(L);
					break;
				case '2':            //增加学生信息
					Add(L);
					break;
				case '3':            //删除学生信息 
					Delete(L);
					break;
				case '4':            //修改学生信息
					Modify(L);
					break;
				case '5':            //显示学生信息
					Show(L);
					break;
				case '6':            //查询单科成绩排名
					Grade(L);
					break;
				case '7':            //查询某学生各科成绩
					Search(L);
					break;
				case '8':            //不及格科目超过2科的学生名单
					Failed(L);
					break;
			    case '9':            //退出系统 
			    	system("cls");
			    	printf("* 感谢您的使用，已退出系统 *\n");
			    	exit(0);
				default:
					printf("* 输入有误，请选择正确的功能选项 *\n"); 
					system("pause");
					system("cls");
			        break;
			}
	    }
    }
    else
    {
    	printf("\n* 密码错误，请重新输入 *\n");
    	system("pause");
    	system("cls");
    	exit(0);
	}
	
	return 0;
}
