/*
1��ʵ��Ŀ��
ͨ����ʵ�飬�������Ա���ʽ�洢�ṹ�Ļ���ԭ��ͻ��������Լ���ʵ�������е�Ӧ�á�
2��ʵ������                                                      
  ����ĳ��ѧ����ͨѶ¼��Ҫ��������洢��
  ���幦�ܰ�����
��1������ʵ�ֲ���һ��ͬѧ��ͨѶ¼��¼��
 	��2���ܹ�ɾ��ĳλͬѧ��ͨѶ¼��
  	��3����ͨѶ¼��ӡ�����
3��ʵ��Ҫ��
��1������ͨѶ¼���ݵĽṹ�壻
��2�������洢ͨѶ¼������ṹ����ʼ����                                                 
��3��������������
       1������¼�뺯�������������棩
       2���������뺯�������������棩
       3������ɾ�����������������棩
       4����������ʹ�ӡ���������������棩
            I��ͨ��ѭ�������г�Ա��¼���
           II�����ָ��������ĳ��ͬѧ��ͨѶ¼��¼
       5���˳� 
*/


#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/**************************/
/*****�������ͷ�ļ�*******/
/**************************/
typedef struct link_node{
	char *info[10]; //ѧ��
	char name[12];  // ����
	char *phone[12]; //ͨѶ¼��¼;
	struct link_node *next;
}node;



//�Զ����������ݺ��� 
node *my_scanf(node *head)
{
	node *p = NULL,*q = NULL;
	char info[10] = {0};
	int n = 0;
	char m[10] = {0};
	printf("���������ݵĸ�����\n");
	scanf("%d",&n);
	for(int a = 1;a <= n;a ++)
	{
		printf("�������%d����ϵ�˵�ͨѶ¼��Ϣ��\n",a);
		p = (node *)malloc(sizeof(node));
		printf("������ѧ��: \n");
		scanf("%s",p->info);
		printf("����������: \n");
		scanf("%s",p->name);
		printf("��������룺\n");
		scanf("%s",p->phone);
		p->next = NULL;
		if(a == 1)
		{
			head = p;
			q = p;
		}
		else
		{
			q->next = p;
			q = p;
		}
	}
	return head;
}

/****************************/
/****����һ���յĵ�����******/
/****************************/
node *init()
{
	return NULL;
}

/**********************************/
/****����������и����ڵ��ֵ******/
/**********************************/
void display(node *head)
{
	printf("%12s%16s%18s","ѧ��","����","ͨѶ¼��¼\n");
	node *p;
	p = head;
	if(!p)
		printf("\n�����ǿյģ�");
	else
	{
		while(p)
		{
			printf("%15s%15s%15s\n",p->info,p->name,p->phone);
			p = p->next;
		}
	}
	printf("\n");
}


node *find(node *head,int i)
{
	int j = 1;
	node *p = head;
	if(i < 0)
		printf("�绰����û�и����ݣ�\n");
	while(p && j != i)
	{
		p = p->next;
		j ++;
	}
	return p;
}

/********************************************/
/****�������i���������ֵΪx���½��******/
/********************************************/
node *insert(node *head,int i)
{
	
	node *p,*q;
	q = find(head,i);
	//���ҵ�i�����
	if(!q && i < 0)
		printf("\n�Ҳ�����%d�����",i);
	else
	{
		//Ϊp����һ���ռ�
		p = (node *)malloc(sizeof(node));
		printf("���������ڵ����ݣ�\n");
		//�����½ڵ������
		printf("������ѧ�ţ�\n"); 
		scanf("%s",p->info);
		printf("������������\n") ;
		scanf("%s",p->name);
		printf("������绰��\n"); 
		scanf("%s",p->phone);
		//�������Ľ���ǵ�����ĵ�һ�����
		if(i == 0)
		{
			p->next = head;
			head = p;
		}
		else
		{
			p->next = q->next;
			q->next = p;
		}
	}
	return head;
}


node *dele(node *head)
{
	int id = 0;
	int j = 1;
	printf("��������Ҫɾ����ͨѶ¼��λ�ã�\n");
	scanf("%d",&id);
	node *pre = NULL,*p;
	if(!head)
	{
		printf("�������ǿյģ�");
		return head;
	}
	p = head;
	//ָ��ָ�����ݴ��ڲ���û���ҵ����ϵ�����
	while(p && (id != j));
	{
		pre = p;
		p = p->next;
		j ++;
	}
	if(p)
	{
		//ǰ����㲻���ڣ�����Ҫɾ����һ������
		if(!pre)
			head = head->next;
		else
			pre->next = p->next;
		free(p);
	}
	return head;
}

void print(node *head)
{
	char name[12];
	printf("��������Ҫ���ҵ�ѧ��������\n");
	scanf("%s",name);
	node *p = head;
	if(!head)
		printf("����Ϊ�գ��޷���ѯ��"); 
	//ָ��ָ�����ݴ��ڲ���û���ҵ����ϵ�����
	while(p && (strcmp(name,p->name) != 0))
		p = p->next;
	printf("\n\t���ҳɹ���\n\t��ѧ������ϢΪ��\n");
	printf("%12s%16s%18s","ѧ��","����","ͨѶ¼��¼\n");
	printf("%15s%15s%15s\n",p->info,p->name,p->phone);
}

void interface()
{
	printf("\t\t------------------------------------\n");
	printf("\t\t******����ѧ��ͨѶ¼******\n\n");
	printf("\t\t0.����\n");
	printf("\t\t1.¼����ϵ����Ϣ\n");
	printf("\t\t2.������ϵ����Ϣ\n");
	printf("\t\t3.ɾ����ϵ����Ϣ\n");
	printf("\t\t4.��ӡ������ϵ����Ϣ\n");
	printf("\t\t5.����ѧ����������ͨѶ¼��¼����ӡ\n");
	printf("\t\t6.�˳�\n");
	printf("\t\t------------------------------------\n");
}


int main()
{
	int i = 0,j = 0;
	node *head,*p;
	head = init();
	interface();
	while(1)
	{
		printf("���빦�ܱ��:\n");
		scanf("%d",&i);
		switch(i)
		{
			case 0:
				system("cls");
				break;
			case 1:{
				head = my_scanf(head);
				printf("\t\t¼��ɹ�!\n"); 
				printf("------------------------------------\n");
				break;
			}
			case 2:{
				printf("��ͨѶ¼���в������ݣ�\n");
				printf("��������Ҫ�����λ�ã�\n");
				scanf("%d",&j); 
				head = insert(head,j);
				printf("\n�������ͨѶ¼��\n");
				display(head);
				printf("------------------------------------\n");
				break;
			}
			case 3:{
				head = dele(head);
				printf("ɾ�����ͨѶ¼��\n");
				display(head);
				printf("------------------------------------\n");
				break;
			}
			case 4:{
				printf("\t\nͨѶ¼�еļ�¼��\n\n");
				display(head);
				printf("------------------------------------\n");
				break;
			}
			case 5:{
				print(head);
				printf("------------------------------------\n");
				break;
			}
			case 6:
				exit(0);
				break;
			default:
				printf("\t->��������,��������<-\n");
				break;
		}
	}
	return 0;
}


