/**
 * InfectStatistic
 * TODO
 *
 * @author 陈文婷
 * @version xxx
 * @since xxx
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
char cmd[30][20];
short patient[32][4]={0};
char Province[32][7]={"全国","安徽","北京","重庆","福建","甘肃","广东","广西","贵州","海南","河北","河南","黑龙江","湖北","湖南",
"吉林","江苏","江西","辽宁","内蒙古","宁夏","青海","山东","山西","陕西","上海","四川","天津","西藏","新疆","云南","浙江"};
int type[4]={0};//type命令输出情况
short province[32]={0};//用于存放需要输出省份的序号
char *logpath,*outpath;
void Get_log(int i)//获取日志目录路径
{
	logpath=cmd[i];
}
void Output(int i)//获取输出路径
{
	outpath=cmd[i];
}
void Get_date(int i)//获取文件名
{
	strcat(cmd[i],".log.txt");
}
int Get_type(int i)
{
	int temp=0,n=0;//n用来统计需要type命令后有几个参数
	if (strcmp(cmd[i],"ip")!=0&&
		strcmp(cmd[i],"sp")!=0&&
		strcmp(cmd[i],"cure")!=0&&
		strcmp(cmd[i],"dead")!=0)
	{
		for (temp=0;temp<4;temp++)//type后面没有参数则默认输出所有情况
			type[temp]=1;
	}
	else
	{
		for (temp=0;temp<4;temp++)
		{
			if (strcmp(cmd[i+temp],"ip")==0)//列出感染患者情况
			{
				type[0]=1;
				n++;
			}
			else if (strcmp(cmd[i+temp],"sp")==0)//列出疑似患者情况
			{
				type[1]=1;
				n++;
			}
			else if (strcmp(cmd[i+temp],"cure")==0)//治愈患者情况
			{
				type[2]=1;
				n++;
			}
			else if (strcmp(cmd[i+temp],"dead")==0)//死亡患者情况
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
	int temp=0,n=0;//n用来统计输出几个省的情况
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
	if (n==0)//province命令后面没有参数，则输出全国以及所有省份的情况
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
		if (strcmp(cmd[i],"-log")==0)//获取日志目录位置
		{
			i++;
			Get_log(i);
		}
		else if (strcmp(cmd[i],"-out")==0)//输出结果路径
		{
			i++;
			Output(i);
		}
		else if (strcmp(cmd[i],"-date")==0)//获取指定日期
		{
			i++;
			Get_date(i);
		}
		else if (strcmp(cmd[i],"-type")==0)//获取所要查看患者类型
		{
			i++;
			i=i+Get_type(i);
		}
		else if (strcmp(cmd[i],"-province")==0)//获取指定列出的省
		{
			i++;
			i=i+Get_province(i);
		}
	}
	return 0;
}
