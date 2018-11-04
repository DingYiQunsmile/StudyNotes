#include "stdio.h"
#include "stdlib.h"

//��������ʽ����Ľṹ�� 
typedef struct node{
	int data;
	struct node *lchild,*rchild;
}bintnode;
//ȫ�ֱ��� 
bintnode *root;  /*ָ�������������ָ��*/ 

//˳��ջ��ͷ�ļ�
typedef struct stack
{
	bintnode *data[100];  
	int tag[100]; /*Ϊջ�е�ÿ��Ԫ�����õı��*/
	int top; /*ջ��ָ��*/ 
} seqstack; 

//�������ĵݹ��㷨

//ǰ�����
void preorder(bintnode *t)
{
	if(t)
	{
		printf("%c ",t->data);
		preorder(t->lchild);
		preorder(t->rchild);
	}
 } 
 
//�������
void inorder(bintnode *t)
{
 	if(t)
 	{
 		inorder(t->lchild);
 		printf("%c ",t->data);
 		inorder(t->rchild);
	 }
}

//�������
void postorder(bintnode *t)
{
	if(t)
	{
		postorder(t->lchild);
		postorder(t->rchild);
		printf("%c ",t->data);
	}
}

//�������ķǵݹ�ʵ��
void push(seqstack *s,bintnode *t)  /*��ջ*/
{
	s->data[s->top] = t;
	s->top ++; 
}

bintnode *pop(seqstack *s)
{
	if(s->top != 0)
	{
		s->top --;
		return (s->data[s->top]);
	}
	else
		return NULL;
}

//������ǰ������ķǵݹ�ʵ��
void preorder1(bintnode *t)
{
	seqstack s;
	s.top = 0;
	while((t) || (s.top != 0))
	{
		if(t)
		{
			printf("%c ",t->data);
			push(&s,t);
			t = t->lchild;
		}
		else
		{
			t = pop(&s);
			t = t->rchild;
		}
	}
} 

//��������������ķǵݹ�ʵ��
void inorder1(bintnode *t)
{
	seqstack s;
	s.top = 0;
	while((t != NULL) || (s.top != 0))
	{
		if(t)
		{
			push(&s,t);
			t = t->lchild; 
		}
		else
		{
			t = pop(&s);
			printf("%c ",t->data);
			t = t->rchild;
		}
	}
}

//��������������ķǵݹ�ʵ��
void postorder1(bintnode *t)
{
	seqstack s;
	s.top = 0;
	while((t) || (s.top != 0))
	{
		if(t)
		{
			s.data[s.top] = t;
			s.tag[s.top] = 0;
			s.top ++;
			t = t->lchild;
		}
		else
		{
			if(s.tag[s.top - 1] == 1)
			{
				s.top --;
				t = s.data[s.top];
				printf("%c ",t->data);
				t = NULL;
			}
			else
			{
				t = s.data[s.top - 1];
				s.tag[s.top - 1] = 1;
				t = t->rchild;
				
				
			}
		}
	}
} 

//����ǰ���������һ�ö����� 
bintnode *createbintree()
{
	char ch;
	bintnode *t;
	if((ch = getchar())== '#')
		t = NULL;
	else
	{
		t = (bintnode *)malloc(sizeof(bintnode));
		t->data = ch;
		t->lchild = createbintree();
		t->rchild = createbintree();
	}
	return t;
}

//���������������һ�Ŷ����� 
bintnode *createbintree1()
{
	char ch;
	bintnode *t;
	if((ch = getchar()) == '#')
		t = NULL;
	else
	{ 
		t = (bintnode *)malloc(sizeof(bintnode));
		t->lchild = createbintree();
		t->data = ch;
		t->rchild = createbintree(); 
	}
	return t; 
}


int main()
{
	printf("ǰ�������ʽ����һ�Ŷ�������\n");
	root = createbintree();
	printf("ǰ������ݹ������Ŷ�������\n");
	preorder(root);
	printf("\nǰ������ǵݹ������Ŷ�������\n");
	preorder1(root);
	printf("\n��������ݹ������Ŷ�������\n");
	inorder(root);
	printf("\n��������ǵݹ������Ŷ�������\n");
	inorder1(root); 
	printf("\n��������ݹ������Ŷ�������\n");
	postorder(root);
	printf("\n��������ǵݹ������Ŷ�������\n");
	postorder(root); 
	printf("\n");
	system("pause");
	return 0;
}
//cba###de#gf##h###
