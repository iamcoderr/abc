#include<stdio.h>
#include<stdlib.h>
struct node *create();
void show(struct node *start);
struct node *addpoly(struct node *start1,struct node *start2);
struct node
{
	int exp,coeff;
	struct node *link;
};
int main()
{
	struct node *start1=NULL,*start2=NULL,*start3=NULL;
	printf("Data for 1st POLY\n");
	start1=create();
	printf("Data for 2nd POLY\n");
	start2=create();
	start3=addpoly(start1,start2);
	show(start1);
	show(start2);
	show(start3);
}
struct node *create()
{
	char c;
	int co,e;
	printf("Eneter the power(0 coefficient is LAST) & coefficient:\n");
	scanf("%d %d",&e,&co);
	struct node *temp=NULL,*k;
	if(e==-1)
	 return temp;
	temp=(struct node *)malloc(sizeof(node));
	k=temp; 
	k->link=temp;                                     
	while(e!=-1)
	{
		if(k==temp&&k->link!=NULL)
		{
			k->exp=e;
			k->coeff=co;
			k->link=NULL;
		}
		else
		{
			k->link=(struct node *)malloc(sizeof(node));
			k->link->coeff=co;
			k->link->exp=e;
			k->link->link=NULL;
			k=k->link;
		}
		scanf("%d %d",&e,&co);
	}
	return temp;
}
void show(struct node *start)
{
	while(start!=NULL)
	{
		printf("%d*x^(%d)  ",start->coeff,start->exp);
		start=start->link;
	}
	printf("\n");
}
struct node *addpoly(struct node *start1,struct node *start2)
{
	struct node *start3,*k;
	if(start1==NULL&&start2==NULL)
	 return start1;
	else if(start1==NULL)
	 return start2;
	else if(start2==NULL)
	 return start1;
	else
	{
		k=(struct node *)malloc(sizeof(node));
		start3=k;
		k->link=start3;                               //so that initially k->link wont be NULL!!
		while(start1!=NULL&&start2!=NULL)
		{
	      	if(start1->exp>start2->exp)
		    {
		        if(k==start3&&k->link!=NULL)
		        {
		        	k->coeff=start1->coeff;
		        	k->exp=start1->exp;
		        	k->link=NULL;
				}
				else
				{
					k->link=(struct node *)malloc(sizeof(node));
					k->link->coeff=start1->coeff;
					k->link->exp=start1->exp;
					k->link->link=NULL;
					k=k->link;
				}
		        start1=start1->link;
	        }
          	else if(start2->exp>start1->exp) 
	        {
		        if(k==start3&&k->link!=NULL)
		        {
		        	k->coeff=start2->coeff;
		        	k->exp=start2->exp;
		        	k->link=NULL;
				}
				else
				{
					k->link=(struct node *)malloc(sizeof(node));
					k->link->coeff=start2->coeff;
					k->link->exp=start2->exp;
					k->link->link=NULL;
					k=k->link;
				}
		        start2=start2->link;
	        }
	        else
	        {
	        	if(k==start3&&k->link!=NULL)
		        {
		        	if(start1->coeff+start2->coeff!=0)
		        	{
		        	k->coeff=start1->coeff+start2->coeff;
		        	k->exp=start1->exp;
		        	k->link=NULL;
		            }
				}
				else
				{
					if(start1->coeff+start2->coeff!=0)
					{
					k->link=(struct node *)malloc(sizeof(node));
					k->link->coeff=start1->coeff+start2->coeff;
					k->link->exp=start1->exp;
					k->link->link=NULL;
					k=k->link;
				    }
				}
	        	start1=start1->link;
	        	start2=start2->link;
			}
	    }
	    while(start1!=NULL)
	    {
	    	if(k==start3&&k->link!=NULL)
		        {
		        	k->coeff=start1->coeff;
		        	k->exp=start1->exp;
		        	k->link=NULL;
				}
				else
				{
					k->link=(struct node *)malloc(sizeof(node));
					k->link->coeff=start1->coeff;
					k->link->exp=start1->exp;
					k->link->link=NULL;
					k=k->link;
				}
	    	start1=start1->link;
		}
		while(start2!=NULL)
		{
			if(k==start3&&k->link!=NULL)
		        {
		        	k->coeff=start2->coeff;
		        	k->exp=start2->exp;
		        	k->link=NULL;
				}
				else
				{
					k->link=(struct node *)malloc(sizeof(node));
					k->link->coeff=start2->coeff;
					k->link->exp=start2->exp;
					k->link->link=NULL;
					k=k->link;
				}
			start2=start2->link;
		}
		k->link=NULL;
		if(k==start3&&k->link==NULL)
		{
			k=NULL;
			return k;
		}
		return start3;
    }
}
