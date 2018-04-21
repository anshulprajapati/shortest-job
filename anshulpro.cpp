#include<stdio.h>
#include<stdlib.h>
struct node
{
	int processno;
	int time;
	int arrival;
	int ct;
	int tat;
	int wt;
	struct node *next;
}*head=NULL;
struct node *newnode, *temp ,*minfind; int min=10000; int max=1; struct node *p,*q,*r,*s; int z;int a; int total=0; int h=1;
int waitt=0; int tatt=0;
void create()
{
	

	if(head==NULL)
	{
		head=(struct node*)malloc(sizeof(struct node));
		printf("Enter the process no \n");
		scanf("%d",&head->processno);
		printf("Enter the time required to solve\n");
		scanf("%d",&head->time);
		head->arrival=h;
		total=total+head->time;
		head->ct=total;
		head->tat=head->ct-head->arrival;
		head->wt=head->tat-head->time;
		waitt=waitt+head->wt;
		tatt=tatt+head->tat;
	//	if(head->arrival<min)
	//	min=head->arrival;
	//	if(head->arrival>max)
	//	max=head->arrival;
		head->next=NULL;
		temp=head;
		h++;
	}
	else
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter the process no \n");
		scanf("%d",&newnode->processno);
		printf("Enter the time required to solve the query in minutes should be within 10 min\n");
		scanf("%d",&newnode->time);
		newnode->arrival=h;
		total=total+newnode->time;
		newnode->ct=total;
		newnode->tat=newnode->ct-newnode->arrival;
		newnode->wt=newnode->tat-newnode->time;
		waitt=waitt+newnode->wt;
		tatt=tatt+newnode->tat;
	//	if(newnode->arrival<min)
	//	min=newnode->arrival;
	//	if(newnode->arrival>max)
	//	max=newnode->arrival;
	h++;
		newnode->next=NULL;
		temp->next=newnode;
		temp=newnode;
	}
}
int minfun()
{
	p=head;
	while(p!=NULL)
	{
		if(p->arrival>0 && p->arrival<min )
		min=p->arrival;
		p=p->next;
	}
	return min;
}
int maxfun()
{
	q=head;
	while(q!=NULL)
	{
		if(q->arrival>max)
		max=q->arrival;
		q=q->next;
	}
	return max;
}
void disp1()
{ 
s=head;
printf("PID\tBT\tAT\tCT\tTAT\tWT\n");
	while(s!=NULL)
	{
		printf("%d\t %d\t %d\t %d\t %d\t %d\t\n",s->processno,s->time,s->arrival,s->ct,s->tat,s->wt);
	s=s->next;}	
	
}
void sjf()
{
	r=head; 
	for(int i=0;i<a;i++)
	{
	z=minfun(); 
		while(r!=NULL)
		{
			if(r->arrival == z)
			{
				r->arrival=0;
				r->processno=0;
				r->time=0;
				min=10000;
			}
			r=r->next;
		}
	}
}
int main()
{
	  int x; int y; 
	printf("Enter the number of process required \n");
	scanf("%d",&a);
	int ar;
	for(int i=0;i<a;i++)
	{
		create();
	}
	disp1();
	x=minfun(); y=maxfun();
	printf(" The first arrival time is %d\n",x);
	printf("The last arrival time is %d\n",y);
	sjf();
	printf("All queries processed \n");
	printf("Total time taken to process all queries %d\n",total);
	waitt=waitt/a;
	tatt=tatt/a;
	printf("Average Turn Around Time is :%d\n",tatt);
	printf("Average Wait for each process is :%d\n",waitt);
    
	return 0;
}
