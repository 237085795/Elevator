#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
typedef struct
	{		
		int time;
		int startf;
		int gof;
	}Instruct;//定义一个结构体用来表示电梯接收到的指令，time表示请求时刻starf表示起始楼层gof表示去往楼层 

typedef struct
	{
		int time;
		int floor;
	}Lift;

void Print(int a,int b,FILE * fp)
	{
		fprintf(fp,"%d时，停靠在%d楼\n",a,b);
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
			printf("无法打开此文件\n");
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
			printf("无法打开此文件\n");
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
 

