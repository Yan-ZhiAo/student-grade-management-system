#include <stdio.h>
#include <stdlib.h>
#include "main.h"

//保存学生信息
void SaveFile(struct node* L)
{
	FILE* file = fopen("Student.sys" , "w");
	
	if (file == NULL)
	{
		printf("\t* 打开文件失败 *\n");
		return;
	}
	
	struct node* p = L->next;
	
	while (p != NULL)
	{
		if (fwrite(&p->data, sizeof(struct student), 1, file) != 1)
		{
			printf("\t* 保存%s的信息时出现错误 *\n", p->data.name);
		}
		p = p->next;
	}
	
	fclose(file);
}

//读取学生信息
void ReadFile(struct node* L)
{
	FILE* file = fopen("Student.sys" , "r");
	
	if (file == NULL)
	{
		printf("\t\t* 未找到学生文件，跳过读取 *\n");
		return;
	}
	
	struct node* rear = L;
	struct node* Tmpcell;
	
	Tmpcell = (struct node*)malloc(sizeof(struct node));
	Tmpcell->next = NULL;
	
	while (fread(&Tmpcell->data, sizeof(struct student), 1, file) == 1)
	{
	    rear->next = Tmpcell;
		rear = Tmpcell;
		Tmpcell = (struct node*)malloc(sizeof(struct node));
		Tmpcell->next = NULL;
	}
	free(Tmpcell); 
	
	fclose(file);
	printf("\t\t\t* 已读取文件 *\n");
}
