#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
typedef struct
	{		
		int time;
		int startf;
		int gof;
	}Instruct;//����һ���ṹ��������ʾ���ݽ��յ���ָ�time��ʾ����ʱ��starf��ʾ��ʼ¥��gof��ʾȥ��¥�� 

typedef struct
	{
		int time;
		int floor;
	}Lift;//����һ���ṹ������ʾ���ݵ�״̬��time��ʾ��ǰ��ʱ�̣�floor��ʾ��ǰ¥�� 

void Print(int a,int b,FILE * fp)
	{
		fprintf(fp,"%dʱ��ͣ����%d¥\n",a,b);
	}//�ú���������� 

void Exchange(Instruct * a,Instruct * b)
	{
		int t;
		
		t=a->time;
 		a->time=b->time;
 		b->time=t;
 		
 		t=a->startf;
 		a->startf=b->startf;
 		b->startf=t;
 		
 		t=a->gof;
 		a->gof=b->gof;
 		b->gof=t;
	}//�ú���������������ָ�� 
int Compare(Instruct a,Instruct b)
{
	int flag=0;
	if(a.time==b.time)
		flag+=1;
	if(a.startf==b.startf)
		flag+=1;
	if(a.gof==b.gof)
		flag+=1;
	if(flag==3)
		return 1;
	else
		return 0;
 } //�����ж�����ָ���Ƿ����,��ȷ���1������ȷ���0 
 
 void taximode(Instruct a,Lift * p)
	{	
		FILE * out;//����һ���ļ�ָ�룬����Print�����Ĳ��� 
		if((out=fopen("./output.txt","a"))==NULL)
		{
			printf("�޷��򿪴��ļ�\n");
			exit(0);
		 } 
		if(p->time<a.time)
	 		{
			 	p->time=a.time;
			}
 		p->time+=abs(a.startf-p->floor);
		p->time+=1;
		p->time+=abs(a.gof-a.startf);
		p->floor=a.gof;
		Print(p->time,p->floor,out);
		p->time+=1;
		fclose(out);	
	}//���⳵ģ�ͣ���ֱ�Ӱѳ˿��͵�Ŀ�ĵأ�;�в�����Ӧ�����˿͵�����  
	
int main()
{	
	int n=5,i,j,totaltime=0;//nΪָ��˿ͣ���Ŀ�����Ժ�䶯 
	Instruct a[5],* pa,* pb;//���������������������������ָ�� 
	Lift b={0,1};//������һ������b���������ʼ״̬ 
	Lift * p;//����һ��ָ�������ں����иı���ݵ�״̬
	FILE * in;
	p=&b;
	if((in=fopen("./input.txt","r"))==NULL)
		{
			printf("�޷��򿪴��ļ�\n");
			exit(0);
		}
	for(i=0;i<n;i++)
		fscanf(in,"%d %d %d/n",&a[i].time,&a[i].startf,&a[i].gof);//�ļ������� 
	fclose(in); 
	for(i=0;i<n;i++)
		if(a[i].gof==0)
			a[i].gof=10;//��ȥ��¥���0ת��Ϊ10������ʹ�� 
	for(j=0;j<=n-2;j++)
		{	
			for(i=0;i<=n-2-j;i++)
				if(a[i].time>a[i+1].time)
					{
						pa=&a[i];
						pb=&a[i+1];				
						Exchange(pa,pb);
					}
		}//ð������ 
	taximode(a[0],p);
	for(i=1;i<n;i++)
	{ 	
		if(Compare(a[i],a[i-1]))
			{
				continue;
			}		
		taximode(a[i],p);
	} //�����ظ����� 
	return 0;
 } 
 

