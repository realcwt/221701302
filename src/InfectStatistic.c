/**
 * InfectStatistic
 * TODO
 *
 * @author ������
 * @version xxx
 * @since xxx
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
char cmd[30][20];
short patient[32][4]={0};
char Province[32][7]={"ȫ��","����","����","����","����","����","�㶫","����","����","����","�ӱ�","����","������","����","����",
"����","����","����","����","���ɹ�","����","�ຣ","ɽ��","ɽ��","����","�Ϻ�","�Ĵ�","���","����","�½�","����","�㽭"};
int type[4]={0};//type����������
short province[32]={0};//���ڴ����Ҫ���ʡ�ݵ����
char *logpath,*outpath;
void Get_log(int i)//��ȡ��־Ŀ¼·��
{
	logpath=cmd[i];
}
void Output(int i)//��ȡ���·��
{
	outpath=cmd[i];
}
void Get_date(int i)//��ȡ�ļ���
{
	strcat(cmd[i],".log.txt");
}
int Get_type(int i)
{
	int temp=0,n=0;//n����ͳ����Ҫtype������м�������
	if (strcmp(cmd[i],"ip")!=0&&
		strcmp(cmd[i],"sp")!=0&&
		strcmp(cmd[i],"cure")!=0&&
		strcmp(cmd[i],"dead")!=0)
	{
		for (temp=0;temp<4;temp++)//type����û�в�����Ĭ������������
			type[temp]=1;
	}
	else
	{
		for (temp=0;temp<4;temp++)
		{
			if (strcmp(cmd[i+temp],"ip")==0)//�г���Ⱦ�������
			{
				type[0]=1;
				n++;
			}
			else if (strcmp(cmd[i+temp],"sp")==0)//�г����ƻ������
			{
				type[1]=1;
				n++;
			}
			else if (strcmp(cmd[i+temp],"cure")==0)//�����������
			{
				type[2]=1;
				n++;
			}
			else if (strcmp(cmd[i+temp],"dead")==0)//�����������
			{
				type[3]=1;
				n++;
			}
		}
	}
	return n;
}
int Get_province(int i)
{
	int temp=0,n=0;//n����ͳ���������ʡ�����
	while (i<30)
	{
		for (temp=0;temp<32;temp++)
		{
			if (strcmp(cmd[i],Province[temp])==0)
			{
				province[temp]=1;
				n++;
			}
		}
		i++;
	}
	if (n==0)//province�������û�в����������ȫ���Լ�����ʡ�ݵ����
	{
		for (temp=0;temp<32;temp++)
		{
			province[temp]=1;
		}
	}
	return n;
}



int main (void)
{
	int i=0;
	while (gets(cmd[i]))
	{
		i++;
	}
	for (i=1;i<20;i++)
	{
		if (strcmp(cmd[i],"-log")==0)//��ȡ��־Ŀ¼λ��
		{
			i++;
			Get_log(i);
		}
		else if (strcmp(cmd[i],"-out")==0)//������·��
		{
			i++;
			Output(i);
		}
		else if (strcmp(cmd[i],"-date")==0)//��ȡָ������
		{
			i++;
			Get_date(i);
		}
		else if (strcmp(cmd[i],"-type")==0)//��ȡ��Ҫ�鿴��������
		{
			i++;
			i=i+Get_type(i);
		}
		else if (strcmp(cmd[i],"-province")==0)//��ȡָ���г���ʡ
		{
			i++;
			i=i+Get_province(i);
		}
	}
	return 0;
}
