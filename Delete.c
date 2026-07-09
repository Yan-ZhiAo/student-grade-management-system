#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "main.h"

//删除学生信息 
void Delete(struct node* L)
{
	char id[20];
	char choice;
	int flag = 0;
	struct node* p = L;
	struct node* temp;

    printf("是否删除学生信息？  是请按1，否请按0\n\n"); 
   
    while (choice != '0')
	{
		choice = _getch();
		
		if (choice == '1')
		{
			printf("请输入所要删除学生信息的学号：\n");
			scanf("%s", id);
		    
		    p = L;
		    flag = 0;
		    
			while (p->next != NULL)
			{
				if (strcmp(id, p->next->data.number) == 0)
				{
					temp = p->next;
					p->next = p->next->next;
					free(temp);
					
					flag = 1;	
					SaveFile(L);
					
					printf("* 已删除学生信息 *\n");
					
					break;
				}
				p = p->next;
		    }
				
			if (flag == 0)
			{ 
				printf("* 未找到学生信息 *\n");
		    }
	    }
	    else if (choice == '0')
	    {
	    	printf("* 已退出 *\n");
			
			system("pause");
			system("cls");
	    	return;
		}
		else
		{
			printf("* 输入有误，请重新输入 *\n");
		}
		
		printf("\n是否继续删除学生信息？  是请按1，否请按0\n\n");  
    }
}
