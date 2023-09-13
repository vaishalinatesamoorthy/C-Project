#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<malloc.h>
struct node			
{
char data[100];
struct node *link;
};
void create(struct node *head)
{
int c=1;
do
 {
  struct node *p,*q;
  p=((struct node *)malloc(sizeof(struct node)));
   printf("Enter data\n");
  scanf("%s",&p->data);
  p->link=NULL;
  if(head->link==NULL)
  {
  head->link=p;
  q=p;
  }
  else
  {
  q->link=p;
  q=p;
  }
 printf("Enter 1 for continue and 0 to stop : ");
 scanf("%d",&c);
 }while(c!=0);
}
void search(struct node *head,int s,char *output[])
{
	struct node *p;
int sec=0,trigger=20000;
    int points=0,i;
	p=head->link;
	while(p!= NULL)
	{
		for(i=0;i<s;i++)
		{
			if(strcmp(p->data,output[i])==0)
			{
				points++;
				break;
			}
		}
		p=p->link;
	}
system("CLS");
	if(points==0)
{
	printf("\n \t -----------YOU LOSE----------\t");
}
else if(points==s)
{
 	printf("\n \t ------- YOU WON---------\t");	
}
else
{
	printf("\n\t--------YOUR SCORE :%d-------\n\t------STILL %d MORE WORDS TO BE FOUND---\n\t\n\t-------BETTER LUCK NEXT TIME--------",points,s-points);
}
clock_t before=clock();
do {

  clock_t difference=clock()-before;
  sec=difference * 1000 / CLOCKS_PER_SEC;

} while (sec<trigger);
}
int main()
{
char *output[]={"quiz","deer","ear","red","dear",'\0'};
char word[3][3]={{'d','i','z'},{'u','e','r'},{'q','a','e'}};
int sec=0,trigger=20000;
int i,j,size = 0;
struct node *head;
head=(struct node *)malloc(sizeof(struct node));
head->link=NULL;
while(output[++size]!='\0');
printf("\n\t--------WORD PUZZLE----------\n");
for(i=0;i<3;i++)
{
	for(j=0;j<3;j++)
	{
	printf("%c\t",word[i][j]);
}
printf("\n");
	}
printf("your time starts now");
clock_t before=clock();
do {

  clock_t difference=clock()-before;
  sec=difference * 1000 / CLOCKS_PER_SEC;

} while (sec<trigger);
system ("CLS");
printf("\nEnter the words you found\n");
create(head);	
search(head,size,output);
return 0;
}                      

