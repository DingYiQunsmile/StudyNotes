#include "stdio.h"
#include "stdlib.h"
# define MAXSIZE 100

//˳�򴮵�ͷ�ļ�
typedef struct{
	char str[MAXSIZE];
	int length;
}seqstring;

//˳�򴮵Ĳ���
void strinsert(seqstring *S,int i,seqstring T)
{
	int k;
	if(i < 1 || i > S->length + 1 || S->length + T.length > MAXSIZE -1)/*�Ƿ��ж�*/
		printf("�ַ����������޷����룡\n");
	else
	{
		//�ӵ�i��Ԫ�ؿ�ʼ����
		for(k = S->length; k >= i - 1;k --)
			S->str[T.length + k] = S->str[k];
		//��Tд��S�еĵ�i���ַ�����ʼ��λ��
		for(k = 0;k < T.length; k ++)
			S->str[i + k - 1] = T.str[k];
		S->length = S->length + T.length;
		S->str[S->length] = '\0';

	}
}

//�ַ�����ɾ��
void strdelete(seqstring *S,int i,int len)
{
	int k;
	if(i < 1 || i > S->length || i + len - 1 > S->length) /*�Ƿ�����Ĵ���*/
		printf("�޷������ַ�����");
	else
	{
		for(k = i + len - 1; k < S->length; k ++)
			//s�д��±�Ϊi + len - 1��ʼ��Ԫ��ǰ��
			S->str[k - len] = S->str[k];
		S->length = S->length - len;
		S->str[S->length] = '\0';
	}
}

//�ַ���������
seqstring *strconcat(seqstring S1,seqstring S2)
{
	int i;
	seqstring *r;
	//�����ַ�������ռ䲻��ʹ�õ����
	if(S1.length + S2.length > MAXSIZE - 1)
	{
		printf("�޷������ַ�����\n");
		return (NULL);
	}
	else
	{
		r = (seqstring *) malloc(sizeof(seqstring));
		//��s1���Ƶ�r�ַ�����ǰ��
		for(i = 0;i < S1.length;i ++)
			r->str[i] = S1.str[i];
		//��s2���Ƶ�r�ַ����ĺ��
		for(i = 0;i < S2.length;i ++)
			r->str[S1.length  + i] = S2.str[i];
		r->length = S1.length + S2.length;
		r->str[r->length] = '\0';
	}
	return (r);
}

//������ַ������Ӵ�
seqstring *substring(seqstring S,int i,int len)
{
	int k;
	seqstring *r;
	//����Ƿ����
	if(i < 1 || i > S.length || i + len - 1 > S.length)
	{
		printf("����\n");
		return (NULL);
	}
	else
	{
		r = (seqstring *) malloc(sizeof(seqstring));
		for(k = 0;k < len;k ++)
			r->str[k] = S.str[i + k - 1];
		r->length =len;
		r->str[r->length] = '\0';
	}
	return (r);
}


int main()
{

	return 0;
}
