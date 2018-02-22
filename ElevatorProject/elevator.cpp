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
	}Lift;//定义一个结构体来表示电梯的状态，time表示当前的时刻，floor表示当前楼层 

void Print(int a,int b,FILE * fp)
	{
		fprintf(fp,"%d时，停靠在%d楼\n",a,b);
	}//该函数用来输出 

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
	}//该函数用来交换两条指令 
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
 } //用来判断两条指令是否相等,相等返回1，不相等返回0 
 
 void taximode(Instruct a,Lift * p)
	{	
		FILE * out;//定义一个文件指针，用作Print函数的参数 
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
		fclose(out);	
	}//出租车模型，就直接把乘客送到目的地，途中不再响应其他乘客的需求  
	
int main()
{	
	int n=5,i,j,totaltime=0;//n为指令（乘客）数目方便以后变动 
	Instruct a[5],* pa,* pb;//定义五条命令和两个用来交换的指针 
	Lift b={0,1};//定义了一个电梯b，并赋予初始状态 
	Lift * p;//定义一个指针用来在函数中改变电梯的状态
	FILE * in;
	p=&b;
	if((in=fopen("./input.txt","r"))==NULL)
		{
			printf("无法打开此文件\n");
			exit(0);
		}
	for(i=0;i<n;i++)
		fscanf(in,"%d %d %d/n",&a[i].time,&a[i].startf,&a[i].gof);//文件的输入 
	fclose(in); 
	for(i=0;i<n;i++)
		if(a[i].gof==0)
			a[i].gof=10;//将去往楼层的0转换为10，方便使用 
	for(j=0;j<=n-2;j++)
		{	
			for(i=0;i<=n-2-j;i++)
				if(a[i].time>a[i+1].time)
					{
						pa=&a[i];
						pb=&a[i+1];				
						Exchange(pa,pb);
					}
		}//冒泡排序 
	taximode(a[0],p);
	for(i=1;i<n;i++)
	{ 	
		if(Compare(a[i],a[i-1]))
			{
				continue;
			}		
		taximode(a[i],p);
	} //过滤重复命令 
	return 0;
 } 
 

