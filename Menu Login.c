#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "main.h"

//界面菜单
void Menu()
{
	printf("\t\t\t+==============================================+\n");
	printf("\t\t\t|                                              |\n");
	printf("\t\t\t|          欢迎来到学生成绩管理系统            |\n");
	printf("\t\t\t|                                              |\n");
	printf("\t\t\t|==============================================|\n");
	printf("\t\t\t|              请选择功能选项                  |\n");
	printf("\t\t\t|----------------------------------------------|\n");
	printf("\t\t\t|                                              |\n");
	printf("\t\t\t|            1.录入学生信息                    |\n");
	printf("\t\t\t|            2.增加学生信息                    |\n");
	printf("\t\t\t|            3.删除学生信息                    |\n");
	printf("\t\t\t|            4.修改学生信息                    |\n");
	printf("\t\t\t|            5.显示学生信息                    |\n");
	printf("\t\t\t|            6.查询单科成绩排名                |\n");
	printf("\t\t\t|            7.查询某学生各科成绩              |\n");
	printf("\t\t\t|            8.不及格科目超过2科的学生名单     |\n");
	printf("\t\t\t|            9.退出系统                        |\n");
	printf("\t\t\t|                                              |\n");
	printf("\t\t\t+==============================================+\n");
	printf("\n");
}

//登录密码
int Login()
{
    char key[20] = "123";
	char password[20];
	char input;
	int i = 0;
	
	printf("\t\t\t      ----------------------------------\n");
	printf("\t\t\t     |     欢迎使用学生成绩管理系统     |\n"); 
	printf("\t\t\t      ----------------------------------\n");
	printf("\n请输入管理员密码：");

	while ((input = _getch()) != '\r')
	{
		if (input == '\b')
		{
			i--;
			printf("\b \b");
		}	
		else
		{
			password[i++] = input;
			printf("*");
		}		
	}
	
	if (strcmp(key, password) == 0)
	{ 
		return 1;
	} 
	else 
	{
		return 0;
	}
} 
