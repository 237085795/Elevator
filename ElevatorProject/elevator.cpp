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
	}Lift;

void Print(int a,int b,FILE * fp)
	{
		fprintf(fp,"%dʱ��ͣ����%d¥\n",a,b);
	}

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
	}

 void taximode(Instruct a,Lift * p)
	{	
		FILE * out;
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
	}
	
int main()
{	
	int n=5,i,j,totaltime=0;
	Instruct a[5],* pa,* pb;
	Lift b={0,1};
	Lift * p;	
	FILE * in;
	p=&b;
	if((in=fopen("./input.txt","r"))==NULL)
		{
			printf("�޷��򿪴��ļ�\n");
			exit(0);
		}
	for(i=0;i<n;i++)
		fscanf(in,"%d %d %d/n",&a[i].time,&a[i].startf,&a[i].gof);
	for(i=0;i<n;i++)
		if(a[i].gof==0)
			a[i].gof=10;
	for(j=0;j<=n-2;j++)
		{	
			for(i=0;i<=n-2-j;i++)
				if(a[i].time>a[i+1].time)
					{
						pa=&a[i];
						pb=&a[i+1];				
						Exchange(pa,pb);
					}
		}
	for(i=0;i<n;i++)
		taximode(a[i],p);
	return 0;
 } 
 

