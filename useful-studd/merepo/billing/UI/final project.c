
			/*MINI PROJECT ON HARDWARE SHOP*/

			/*MADE BY:NIKITA SHAHA-2373
				  JYOTI VARPE-2374
				  KALYANI N. KULKARNI-2375
				  ADITI SARKAR-2376
				  AKANKSHA PATIL-2380*/

			/*HEADER FILES*/
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<string.h>
#define MAX 30

			/*STRUCTURE DECLARATION*/

//CUSTOMER DETAILS MODULE
typedef struct CUSTOMER
{
	int id,age,contact[10];
	char name[20],place[20];
	struct CUSTOMER *next;
}CUSTOMER;

//EQUIPMENT DETAILS MODULE
typedef struct EQUIP
{
  char material[MAX],brand[MAX],type[MAX];
  int quantity,cost,id;
  struct EQUIP*next;
}EQUIP;


//BILL MODULE
typedef struct BILL
{
	int Billno,Qua,Cost,Totcost;
	char Custname[MAX],Mat[MAX];
	struct BILL *next;
}BILL;

			/*FUNCTION DECLARATION*/

//FOR CUSTOMER DETAILS MODULE
CUSTOMER *getnode1();
CUSTOMER *insert1();
CUSTOMER *del1(CUSTOMER *,int);
void modify1(CUSTOMER *,int);
void search1(CUSTOMER *);
char search4(CUSTOMER *,int);
void display1(CUSTOMER *);
void sort1(CUSTOMER *);
int countnodes1(CUSTOMER *);

//FOR EQUIPMENT DETAILS MODULE
EQUIP *getnode2();
EQUIP *create2(EQUIP *);
void insert2(EQUIP *);
void display2(EQUIP *);
void search2(EQUIP *);
char search5(EQUIP *,char []);
EQUIP *delete2(EQUIP *);
void modify2(EQUIP *);

//FOR BILL MODULE
BILL *getnode3(EQUIP *);
BILL *create3(BILL*, EQUIP *);
void display3(BILL*,char []);
int countnodes3(BILL*);
void insert3(BILL*, EQUIP *);
BILL *delete3(BILL*);
void search3(BILL*);
void modify3(BILL *);
int j=111;

			/*BODY OF MAIN FUNCTION*/

void main()
{
	int x,ch1,ch2,n,ch3,username,id;
	char z,cd,c2,c3,Custname[MAX],name[MAX],name1[MAX],decision='d';
	char password, loginflag='n', relogin, searchflag;
	CUSTOMER *head1=NULL;
	EQUIP *head2=NULL;
	BILL *head3=NULL;
	clrscr();
	do
	{
		clrscr();
		flushall();
		printf("\n\t\t------****** ORIENTEL HARDWARE STORE ******------\n");
		printf("\t\t       Shop no:884,Karvenagar,\n\t\t       Pune-411 052");
		printf("\n\t\t       Phone no.:(020)24282883,(020)24282783");

		printf("\n\n\n *****ENTER YOUR LOGIN CREDENTIALS*****");
		printf("\n\n USERNAME: ");
		flushall();
		scanf("%d",&username);
		printf("\n PASSWORD: ");
		flushall();
                scanf("%c",&password);
		if((username==2373 && password=='n')||(username==2374 && password=='j')||(username==2375 && password=='k')||(username==2376 && password=='a')||(username==2380 && password=='a'))
		   loginflag='s';
		else
		{
		   loginflag='f';
		   printf("\n Login Unsuccessful! USERNAME or PASSWORD Incorrect");
		   printf("\n\n PRESS 'y' to RE-LOGIN or 'n' to EXIT: ");
		   flushall();
		   scanf("%c", &relogin);
		}
	}while(loginflag=='f' && (relogin=='y'||relogin=='\n'));

	if(loginflag=='s')
	{
	  do
	  {
		clrscr();
		printf("\n\t\t------****** ORIENTEL HARDWARE STORE ******------\n");
		printf("\t\t       Shop no:884,Karvenagar,\n\t\t       Pune-411 052");
		printf("\n\t\t       Phone no.:(020)24282883,(020)24282783");

		printf("\n\n\n\t\t\t\t***MENU***");
		printf("\n\n1. CUSTOMER DETAILS") ;
		printf("\n2. EQUIPMENT DETAILS");
		printf("\n3. BILL DETAILS");
		printf("\n4. LOGOUT");
		printf("\n\n");
		printf("\t\t\t---*-*END OF MENU*-*---");
		printf("\n\nENTER YOUR CHIOICE(1/2/3/4) :\t");
		scanf("%d",&x);

		switch(x)
		{
			case 1:
				clrscr();
				do
				{
					clrscr();
					printf("\n\n\t\t|| CUSTOMER DETAILS ||");
					printf("\n1.INSERT");
					printf("\n2.DISPLAY");
					printf("\n3.DELETE");
					printf("\n4.SEARCH");
					printf("\n5.MODIFY");
					printf("\n\nENTER YOUR CHOICE :  ");
					scanf("%d",&ch1);

					switch(ch1)
					{
						case 1:
							clrscr();
							head1=insert1(head1);
							break;

						case 2:
							clrscr();
							sort1(head1);
							display1(head1);
							break;

						case 3:
							clrscr();
							printf("\nENTER THE ID TO BE DELETED :  ");
							flushall();
							scanf("%d",&id);
							head1=del1(head1,id);
							break;

						case 4:
							clrscr();
							search1(head1);
							break;

						case 5:
							clrscr();
							printf("\nENTER THE ID OF THE RECORD TO BE MODIFIED :  ");
							flushall();
							scanf("%d",&id);
							modify1(head1,id);
							break;

						default:
							printf("\nWRONG CHOICE!!!");
							break;
					}

					printf("\n\nDO YOU WANT TO CONTINUE?(Y/N) :  ");
					flushall();
					scanf("%c",&cd);
				}while(cd=='y' || cd=='Y');
				break;

			case 2:
				do
				{
					clrscr();
					printf("\n\n\t\t|| EQUIPMENT CHOICES ||\n\n");
					printf("\n1.CREATE DATABASE") ;
					printf("\n2.DISPLAY DATABASE" );
					printf("\n3.INSERT RECORD");
					printf("\n4.SEARCH RECORD");
					printf("\n5.DELETE");
					printf("\n6.MODIFY\n");
					printf("\n\nENTER YOUR CHOICE :  ");
					scanf("%d",&ch2);

					switch(ch2)
					{
						case 1:
							clrscr();
							head2=create2(head2);
							break;

						case 2:
							clrscr();
							display2(head2);
							break;

						case 3:
							clrscr();
							insert2(head2);
							break;

						case 4:
							clrscr();
							search2(head2);
							break;

						case 5:
							clrscr();
							head2=delete2(head2);
							break;

						case 6:
							clrscr();
							modify2(head2);
							break;

						default:
							clrscr();
							printf("\nINVALID CHOICE!!!\n");
							break;

					}

					printf("\n\nDO YOU WANT TO CONTINUE?(y/n) :  ");
					flushall();
					scanf("%c",&c2);

					}while(c2=='Y'||c2=='y');
				break;

			case 3:
				clrscr();
				if(head1!=NULL)//check if any customer present
				{
					sort1(head1);
					display1(head1);
					printf("\n\nENTER ID OF THE CUSTOMER NAME :  ");
					scanf("%d",&id);
					searchflag=search4(head1,id);
					getch();
				}
				else
				{
					printf("\n\nNO RECORD FOUND... PLEASE FIRST ADD CUSTOMER DETAILS TO DATABASE\n");
					getch();
					break;
				}
				if(searchflag=='s')//check if customer present
				{
				  do
				  {
					clrscr();
					printf("\n\n\t\t|| BILLING CHOICES||\n");
					printf("\n1.CREATE ");
					printf("\n2.DISPLAY");
					printf("\n3.INSERT");
					printf("\n4.DELETE");
					printf("\n5.MODIFY");
					printf("\n6.SEARCH");
					printf("\nENTER YOUR CHOICE(1-6) :  ");
					scanf("%d",&ch3);
					clrscr();

					switch(ch3)
					{
						case 1:
							clrscr();
							if(head2!=NULL)//check if any Stock present
							{
							     display2(head2); //display available stock details
							     head3=create3(head3,head2);
							     break;
							}
							else
							{
							     printf("\n\nNO RECORD FOUND... PLEASE FIRST ADD EQUIPMENT DETAILS TO DATABASE\n");
							     getch();
							     break;
							}

						case 2:
							clrscr();
							display3(head3,Custname);
							break;

						case 3:
							clrscr();
							if(head2!=NULL)//check if any Stock present
							{
							     display2(head2); //display available stock details
							     insert3(head3,head2);
							     display3(head3,Custname);
							     break;
							}
							else
							{
							     printf("\n\nNO RECORD FOUND... PLEASE FIRST ADD EQUIPMENT DETAILS TO DATABASE\n");
							     getch();
							     break;
							}


						case 4:
							clrscr();
							delete3(head3);
							display3(head3,Custname);
							break;

						case 5:
							clrscr();
							modify3(head3);
							display3(head3,Custname);
							break;

						case 6:
							clrscr();
							search3(head3);
							break;

						default:
							clrscr();
							printf("\nINVALID CHOICE!!!\n");
							break;
					}

					printf("\nDO YOU WANT TO CONTINUE?(y/n):  ");
					flushall();
					scanf("%c",&c3);
				  }while(c3=='y'||c3=='Y');
			       }
			       break;

			case 4:
				clrscr();
				printf("\nARE YOU SURE YOU WANT TO LOGOUT?(y/n) :  ");
				flushall();
				scanf("%s",&decision);
				if(decision=='y'||decision=='Y'||decision=='n'||decision=='N')
				 break;
				else
				clrscr();
				printf("\n!!!INVALID INPUT!!!");
				break;

			default:
				clrscr();
				printf("\n!!!INVALID INPUT!!!");
				break;
		}
		if(decision=='y'||decision=='Y')
		  z='N';
		else if(decision=='n'||decision=='N')
		{
		  z='Y';
		  decision='d'; //set to default value
		}
		else
		{
			printf("\nWOULD YOU LIKE TO GO TO MAIN MENU AGAIN?(y/n) :  ");
			flushall();
			scanf("%c",&z);
			clrscr();
		}
	  }while(z=='Y' || z=='y');
	}
}

/* ======================================================================== *\

		/*FUNCTION DEFINITION FOR CUSTOMER DETAILS MODULE */

//NODE CREATION
CUSTOMER *getnode1()
{
	int length=0;
	CUSTOMER *temp=NULL;
	temp=(CUSTOMER*)malloc(sizeof(CUSTOMER));

	if(temp==NULL)
		printf("\nMEMORY ALLOCATION ERROR...");
	else
	{
		printf("\nENTER THE AGE :  ");
		scanf("%d",&temp->age);
		while(temp->age<0 || temp->age>100)
		{
			if(temp->age<0 || temp->age>100)
			{
				printf("\nINVALID AGE...");
				printf("\nENTER THE AGE AGAIN :  ");
				scanf("%d",&temp->age);
			}
		}

		printf("\nENTER THE MOBILE NUMBER :  ");
		flushall();
		scanf("%s",temp->contact);

		length=strlen(temp->contact);
		while(length!=10)
		{
			if(length!=10)
			{
				printf("\nINVALID MOBILE NUMBER....");
				printf("\nENTER THE 10 DIGIT MOBILE NUMBER AGAIN:  ");
				scanf("%s",temp->contact);
				length=strlen(temp->contact);
			}
		}

		printf("\nENTER THE NAME :  ");
		flushall();
		gets(temp->name);

		printf("\nENTER THE PLACE :  ");
		flushall();
		gets(temp->place);
		temp->next=NULL;
	}

	return(temp);
}

//ADDITION OF RECORD
CUSTOMER *insert1(CUSTOMER *head1)
{
	CUSTOMER *temp=NULL,*ptr=NULL;
	char ans;

	do
	{
		temp=getnode1();

		if(head1==NULL)
			head1=temp;
		else
		{
			ptr=head1;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=temp;
		}

		printf("\nDO YOU WANT TO ADD ANOTHER RECORD ?(Y/N) :  ");
		flushall();
		scanf("%c",&ans);
		clrscr();
	}while(ans=='y' || ans=='Y');
	return(head1);
}

//DISPLAY OF RECORD
void display1(CUSTOMER *head1)
{
	int id=0;
	CUSTOMER *ptr=NULL;
	ptr=head1;
	printf("\n\n\t\t\t|| DETAILS OF CUSTOMER ||\n\n");
	printf("|-------|--------------------|-------|---------------|-------------|\n");
	printf("|ID     | NAME               | AGE   |  MOBILE       | PLACE       |\n");
	printf("|       |                    |       |  NUMBER       |             |\n");
	printf("|-------|--------------------|------ |---------------|-------------|\n");

	while(ptr!=NULL)
	{
		id++;
		printf("|%5d  ",id);
		flushall();

		printf("|%20s|%7d|%15s|%13s|\n",ptr->name,ptr->age,ptr->contact,ptr->place);
		ptr=ptr->next;
	}

	printf("|-------|--------------------|-------|---------------|-------------|");
}

//SEARCH A RECORD
void search1(CUSTOMER *head1)
{
	int id,k=0;
	CUSTOMER *ptr=NULL;
	printf("\nENTER ID WHICH IS TO BE SEARCHED:");
	scanf("%d",&id);
	if(head1==NULL)
	{
		printf("\nNO MATERIAL PURCHESED!!!");
	}
	else
	{

		ptr=head1;//initially ptr points to head
		while(ptr!=NULL)
		{
			k++;
			if(id==k)
			{
				break; //come out of loop if match is found
			}
			else
			{
				ptr=ptr->next;//increments ptr till match is found
			}
		}
		if(ptr==NULL)
		{
			printf("NOT FOUND\n");
		}
		else

		{
			printf("\nFOUND  AT POSITION :\t%d",k);
			printf("\n\n\t\t\t|| DETAILS OF CUSTOMER ||\n\t");
			printf("\nID :  %d",id);
			printf("\nNAME OF CUSTOMER :  %s",ptr->name);
			printf("\nAGE :  %d",ptr->age);
			printf("\nMOBILE NUMBER :  %s",ptr->contact);
			printf("\nPLACE :  %s",ptr->place);
		}
	}

}


//CHECK A CUSTOMER RECORD FOR BILL DETAILS
char search4(CUSTOMER *head1,int id)
{
	int k=0;
	char flag='d';
	CUSTOMER *ptr=NULL;
	if(head1==NULL)
	{
		printf("\nNO MATERIAL PURCHESED!!!");
	}
	else
	{

		ptr=head1;//initially ptr points to head
		while(ptr!=NULL)
		{
			k++;
			if(id==k)
			{
				break; //come out of loop if match is found
			}
			else
			{
				ptr=ptr->next;//increments ptr till match is found
			}
		}
		if(ptr==NULL)
		{
			printf("NOT FOUND\n");
			//printf("\nPLEASE INSERT THE NEW RECORD...");
			flag='f';
		}
		else

		{
			printf("\nFOUND...");
			printf("\n\n\t\t\t|| DETAILS OF CUSTOMER ||\n\t");
			printf("\nID :  %d",id);
			printf("\nNAME OF CUSTOMER :  %s",ptr->name);
			printf("\nAGE :  %d",ptr->age);
			printf("\nMOBILE NUMBER :  %s",ptr->contact);
			printf("\nPLACE :  %s",ptr->place);
			flag='s';
		}
	}
	return flag;

}


//DELETING A RECORD
CUSTOMER *del1(CUSTOMER *head1,int id)
{
	CUSTOMER *ptr=NULL,*ptr1=NULL;
	int pos,count=0,i;
	if(head1==NULL)
		printf("\nNO RECORDS ARE PRESENT IN THE LIST...");
	else
	{
		count=countnodes1(head1);
		ptr=head1;

		if(id>=1 && id<=count)
		{
			if(id==1)
			{
				head1=head1->next;
				free(ptr);
				ptr=head1;
			}
			else
			{
				for(i=1;i<id;i++)
				{
					ptr1=ptr;
					ptr=ptr->next;
				}
				ptr1->next=ptr->next;
				free(ptr);
			}
			printf("\nRECORD DELETED...");
		}
		else
		{
			printf("\nINVALID ID...");
		}

	}
	return(head1);
}

int countnodes1(CUSTOMER *head1)
{
	int count=0;
	CUSTOMER *ptr=NULL;
	ptr=head1;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->next;
	}
	return(count);
}


//MODIFY A RECORD
void modify1(CUSTOMER *head1,int id)
{
	CUSTOMER *ptr=NULL;
	char ans1;
	int choice,cnt=0,length=0;

	if(head1==NULL)
	{
		printf("\nRecord is empty...");

	}
	else
	{
		ptr=head1;
		while(ptr!=NULL)
		{
			cnt++;
			if(cnt==id)
			{
				break;
			}
			ptr=ptr->next;
		}
		if(ptr==NULL)
		{
			printf("\n\nID not found...");

		}
		else
		{
			printf("\n\nID found!!!");

			do
			{
				printf("\n\nWHAT TO MODIFY FROM THE FOLLOWING :  ");
				printf("\n1.NAME");
				printf("\n2.AGE");
				printf("\n3.PLACE");
				printf("\n4.MOBILE NUMBER");
				printf("\n\nENTER YOUR CHOICE(1-4) :  ");
				scanf("%d",&choice);

				switch(choice)
				{
					case 1:
						printf("\nENTER THE NEW NAME :  ");
						flushall();
						gets(ptr->name);
						break;

					case 2:
						printf("\nENTER THE AGE :  ");
						scanf("%d",&ptr->age);
						while(ptr->age<0 || ptr->age>100)
						{
							if(ptr->age<0 || ptr->age>100)
							{
								printf("\nINVALID AGE...");
								printf("\nENTER THE AGE AGAIN :  ");
								scanf("%d",&ptr->age);
							}
						}
						break;


					case 3:
						printf("\nENTER THE NEW PLACE :  ");
						flushall();
						gets(ptr->place);
						break;

					case 4:
						printf("\nENTER THE NEW MOBILE NUMBER :  ");
						flushall();
						scanf("%s",ptr->contact);

						length=strlen(ptr->contact);
						while(length!=10)
						{
							if(length!=10)
							{
								printf("\nINVALID MOBILE NUMBER....");
								printf("\nENTER THE 10 DIGIT MOBILE NUMBER AGAIN:  ");
								scanf("%s",ptr->contact);
								length=strlen(ptr->contact);
							}
						}

						break;


					default:
						printf("\nINVALID CHOICE!!!");
						break;
				}

				printf("\nDO YOU WANT TO MODIFY ANY OTHER RECORD?(Y/N) :  ");
				flushall();
				scanf("%c",&ans1);
			}while(ans1=='y' || ans1=='Y');
			getch();
		}
		sort1(head1);
		display1(head1);
	}
}


//SORT THE RECORD
void sort1(CUSTOMER *head1)
{
	int i,j,n;
	char temp[MAX]={'\0'};
	CUSTOMER *p;

	for(n=0,p=head1;p!=NULL;p=p->next)
		n++;

	for(i=1;i<n;i++)
	{
		p=head1;

		for(j=0;j<n-i;j++)
		{
			if(strcmp(p->name, p->next->name)>0)
			{
				 strcpy(temp,p->name);
				 strcpy(p->name,p->next->name);
				 strcpy(p->next->name,temp);
			}
			p=p->next;
		}
	}
}

/* ======================================================================== */

/*FUNCTION DEFINITIONS FOR EQUIPMENT DETAILS MODULE*/

//NODE CREATION
EQUIP *getnode2()
{

	EQUIP *temp;
	temp=(EQUIP*)malloc(sizeof(EQUIP));
	temp->id=j;

	if (temp==NULL)
		printf("\nMEMORY ALLOCATION ERROR!!!");
	else
	{
		printf("\nENTER MATERIAL NAME :  ");
		scanf("%s",temp->material);

		printf("\n MATERIAL ID :  %d",temp->id);
		j=j+111;

		printf("\nENTER BRAND OF MATERIAL :  ");
		scanf("%s",temp->brand);

		printf("\nENTER TYPE OF MATERIAL :  ");
		scanf("%s",temp->type);

		printf("\nENTER QUANTITY OF MATERIAL:  ");
		scanf("%d",&temp->quantity);

		printf("\nENTER THE COST OF MATERIAL:  ");
		scanf("%d",&temp->cost);
		temp->next=NULL;
	}
	return (temp);
}

//ADDITION OF RECORD
void insert2(EQUIP *head2)
{
	EQUIP *temp=NULL;
	EQUIP *last=NULL;

	if(head2==NULL)
		printf("\nMATERIAL STOCK IS EMPTY...\n");
	else
	{
		temp=getnode2();
		last=head2;

		while(last->next!=NULL)
			last=last->next;

		last->next=temp;
		display2(head2);
	}

}

//CREATE RECORD
EQUIP *create2(EQUIP *head2)
{
	EQUIP *last,*temp;
	int n,i=0;
	char choice5;
	do
	{
		clrscr();
		i++;
		printf("FOR MATERIAL %d\n",i);


		temp=getnode2();

		if(head2==NULL)
			head2=temp;
		else
		{
			last=head2;
			while(last->next!=NULL)
				last=last->next;
			last->next=temp;
		}

		printf("\n\nDO YOU WANT TO ADD MORE MATERIAL TO THE LIST?(Y/N)");
		flushall();
		scanf("%c",&choice5);
	}while(choice5=='y'||choice5=='Y');


	return (head2);
}

//DISPLAY RECORD
void display2(EQUIP *head2)
{
	int k=0;
	EQUIP *ptr=NULL;
	ptr=head2;

	printf("\n\n\t\t\t||STOCK DETAILS||\n");
	printf("|----------|----------|----------|----------|-----------|-----------|----------|\n");
	printf("|          |          |          |          |           |           |          | \n");
	printf("|Sr no.    |Id no.    |Material  | Brand    | Type      |Quantity   | Cost     |\n");
	printf("|          |          |          |          |           |(kg/lit/no)| (Rs.)    |\n");
	printf("|----------|----------|----------|----------|-----------|-----------|----------|\n");

	while(ptr!=NULL)
	{
		k++;
		printf("|%10d",k);
		printf("|%10d|%10s|%10s| %10s| %10d|%10d|\n",ptr->id,ptr->material,ptr->brand,ptr->type,ptr->quantity,ptr->cost);
		ptr=ptr->next;


	}
	printf("|----------|----------|----------|----------|-----------|-----------|----------|\n");
}

//SEARCHING OF DATA
void search2(EQUIP *head2)
{
	int id;
	EQUIP *ptr1=NULL;
	int k=0;
	printf("\nENTER ID OF MATERIAL  WHICH IS TO BE SEARCHED : ");
	scanf("%d",&id);

	if(head2==NULL)
		printf("\nMATERIAL STOCK IS EMPTY...\n");
	else
	{
		ptr1=head2;

		while(ptr1!=NULL)
		{
			k++;

			if(ptr1->id==id)
				break;
			else
				ptr1=ptr1->next;
		}

		if(ptr1==NULL)
			printf("NOT FOUND...\n");
		else
		{
			printf("\n\nFOUND  AT POSITION :  %d",k);
			printf("\n\nMATERIAL NAME:  %s",ptr1->material);
			printf("\n\nMATERIAL ID:  %d",ptr1->id);
			printf("\n\nBRAND NAME:  %s",ptr1->brand);
			printf("\n\nTYPE OF MATERIAL:  %s",ptr1->type);
			printf("\n\nQUANTITY OF MATERIAL:  %d",ptr1->quantity);
			printf("\n\nCOST OF MATERIAL:  %d",ptr1->cost);
		}
	}
}

//CHECKING IF MATERIAL Present during Billing
char search5(EQUIP *head2, char name[20])
{
	EQUIP *ptr1=NULL;
	int k=0;
	char flag='d';
	if(head2==NULL)
		printf("\nMATERIAL STOCK IS EMPTY...\n");
	else
	{
		ptr1=head2;

		while(ptr1!=NULL)
		{
			k++;

			if(strcmp(ptr1->material,name)==0)
				break;
			else
				ptr1=ptr1->next;
		}

		if(ptr1==NULL)
		{
		 flag='f';
		 printf("\nMATERIAL NOT PRESENT IN STOCK LIST...PLEASE RE-ENTER\n");
		}
		else
		 flag='s';
		return(flag);
	}
	return(flag);
}

//DELETING A RECORD
EQUIP *delete2(EQUIP *head2)
{

	int k=0,id;
	EQUIP *ptr1=NULL,*ptr2;
	printf("\nENTER MATERIAL ID WHICH IS TO BE DELETED :  ");
	scanf("%d",&id);
	ptr1=head2;

	while(ptr1!=NULL)
	{
		if(head2->id==id)
		{
			k++;
			head2=head2->next;
			free(ptr1);
			ptr1=head2;
		}
		else
		{
			if(ptr1->id==id)
			{
				k++;
				ptr2->next=ptr1->next;
				free(ptr1);
				ptr1=head2;
			}
			ptr2=ptr1;
			ptr1=ptr1->next;
		}

	}
		if(k==0)
		{
			printf("\nMATERIAL NOT FOUND...");
		}
	display2(head2);
	return head2;
}

//MODIFYING A RECORD
void modify2(EQUIP *head2)
{
	EQUIP *ptr=head2;
	char ans1 ;
	int ch2,id;
	printf("ENTER THE ID OF MATERIAL YOU WANT TO MODIFY :  ");
	scanf("%d",&id);

	while(ptr!=NULL &&(ptr->id!=id))
	{
		ptr=ptr->next;
	}

	if(ptr->id==id)
	{
		do
		{
			printf("\n\nWHAT DO YOU WANT TO WANT TO MODIFY :  ");
			printf("\n1.MATERIAL NAME");
			printf("\n2.MATERIAL ID");
			printf("\n3.BRAND");
			printf("\n4.TYPE");
			printf("\n5.QUANTITY");
			printf("\n6.COST");
			printf("\n\nENTER YOUR CHOICE :  ");
			scanf("%d",&ch2);

			switch(ch2)
			{

				case 1:
					printf("\nENTER NEW NAME OF MATERIAL :  ");
					flushall();
					scanf("%s",ptr->material);
					break;
				case 2:
					printf("\nENTER NEW ID OF MATERIAL:  ");
					scanf("%d",ptr->id);
					break;

				case 3:
					printf("\nENTER THE NEW BRAND :  ");
					flushall();
					scanf("%s",ptr->brand);
					break;

				case 4:
					printf("\nENTER THE TYPE :  ");
					flushall();
					scanf("%s",ptr->type);
					break;

				case 5:
					printf("\nENTER THE QUANTITY :  ");
					scanf("%d",&ptr->quantity);
					break;

				case 6:
					printf("\nENTER THE NEW COST :  ");
					scanf("%d",&ptr->cost);
					break;

				default:
					printf("\nINVALID CHOICE!!!");
					break;
			}

			printf("\nDO YOU WANT TO MODIFY ANY OTHER RECORD?(Y/N) :  ");
			flushall();
			scanf("%c",&ans1);
		}while(ans1=='y' || ans1=='Y');
	}
	else
		printf("\nNO SUCH MATERIAL IS PRESENT IN THE LIST.....");
		display2(head2);
}



/* ======================================================================== */

	/*FUNCTION DEFINITIONS FOR BILL MODULE*/

//CREATION OF BILL
BILL *create3(BILL *head3,EQUIP *head2)
{
	BILL *last,*temp;
	char c;

	do
	{
		temp=getnode3(head2);

		if(head3==NULL)
			head3=temp;
		else
		{
			last=head3;

			while(last->next!=NULL)
			{
				last=last->next;
			}
			last->next=temp;
		}

		clrscr();
		printf("\nDO YOU WANT TO ADD MORE ENTRY?(y/n) :  ");
		flushall();
		scanf("%c",&c);
	}while(c=='y'||c=='Y');
	return(head3);
}

//NODE CREATION
BILL *getnode3(EQUIP *head2)
{
	BILL *temp;
	int q,c,totcost;
	char flag='d';
	temp=(BILL*)malloc(sizeof(BILL));

	do
	{
		printf("\nMATERIAL :  ");
		scanf("%s",temp->Mat);
		flag=search5(head2,temp->Mat);
	}while(flag=='f' || flag=='d');

	printf("\nQUANTITY :  ");
	scanf("%d",&temp->Qua);

	printf("\nCOST PER MATERIAL :  ");
	scanf("%d",&temp->Cost);

	q=temp->Qua;
	c=temp->Cost;
	totcost = c * q;
	temp->Totcost=totcost;

	printf("\nTOTAL COST :  %d",totcost);
	getch();
	temp->next=NULL;

	return(temp);
}

//DISPLAY
void display3(BILL *head3,char Custname[MAX])
{
	BILL *ptr=NULL;
	int k=1,bill=0;

	if(head3==NULL)
		printf("\nNOTHING IS PURCHASED\n");
	else
	{
		printf("\n\t\t---*** ORIENTEL HARDWARE STORE ***---\n");
		printf("\t\t       Shop no:884,Karvenagar,");
		printf("\n\t\t       Pune-52");
		printf("\n\t\t       Ph no:(020)24282883,(020)24282783");

		printf("\n\nCUSTOMER NAME :\t%s\n",Custname);

		printf("|-------|---------------|---------------|---------------|---------|\n");
		printf("|SRNO\t|MATERIAL\t|QUANTITY\t|COST/\t\t|TOTAL\t  |");
		printf("\n|\t|NAME\t\t|\t\t|MATERIAL\t|COST\t  |\n");
		printf("|-------|---------------|---------------|---------------|---------|\n");

		for(ptr=head3;ptr!=NULL;ptr=ptr->next)
		{
			printf("|%d\t|%s\t\t|%d\t\t|%d\t\t|%d\t  |\n",k,ptr->Mat,ptr->Qua,ptr->Cost,ptr->Totcost);
			k++;
			bill=bill+ptr->Totcost;
		}

		printf("|-------|---------------|---------------|---------------|---------|\n");
		printf("|\t\tTOTAL BILL\t\t\t\t|%d\t  |\n",bill);
		printf("|-------|---------------|---------------|---------------|---------|\n");
	}
}

//MODIFYING
void modify3(BILL *head3)
{
	BILL *ptr=head3;

	char ans1;
	int ch2,k=1,srno=0,q,c,totcost;
	printf("ENTER THE SERIAL NO. YOU WANT TO MODIFY :  ");
	scanf("%d",&srno);

	while(ptr!=NULL &&srno!=k)
	{
		k++;
		ptr=ptr->next;
	}

	if(srno==k)
	{
        	printf("\nENTER THE NEW QUANTITY :  ");
                scanf("%d",&ptr->Qua);
	    /*	do
		{
			printf("\n\nWHAT DO YOU WANT TO WANT TO MODIFY :  ");
			printf("\n1.MATERIAL NAME");
			printf("\n2.COST/MATERIAL");
			printf("\n3.QUANTITY");
			printf("\n\nENTER YOUR CHOICE :  ");
			scanf("%d",&ch2);

			switch(ch2)
			{
				case 1:
					printf("\nENTER NEW NAME OF MATERIAL :  ");
					flushall();
					scanf("%s",ptr->Mat);
					break;

				case 2:
					printf("\nENTER THE NEW COST/MATERIAL :  ");
					scanf("%d",&ptr->Cost);
					break;

				case 3:
					printf("\nENTER THE NEW QUANTITY :  ");
					scanf("%d",&ptr->Qua);
					break;

				default:
					printf("\nINVALID CHOICE!!!");
					break;
			}    */

		q=ptr->Qua;
		c=ptr->Cost;
		totcost = c * q;
		ptr->Totcost=totcost;

	     	printf("\nTOTAL COST :  %d",totcost);
	     /*		printf("\nDO YOU WANT TO MODIFY ANY OTHER RECORD?(Y/N) :  ");
	     		flushall();
			scanf("%c",&ans1);
	      }while(ans1=='y' || ans1=='Y');     */

	}
	else
		printf("\nNO SUCH MATERIAL IS PRESENT IN THE LIST...");
}

//COUNTING OF NODES
int countnodes3(BILL *head3)
{
	int cnt=0;
	BILL *last=NULL;

	if(head3==NULL)
	{
		printf("\nNOTHING IS PURCHESED...");
		return 0;
	}
	else
	{
		last=head3;

		while(last!=NULL)
		{
			cnt++;
			last=last->next;
		}

		return cnt;
	}
}

//INSERTION
void insert3(BILL *head3,EQUIP *head2)
{
	BILL *temp,*last=NULL;

	if(head3==NULL)
		printf("\nNOTHING IS PURCHESED...");
	else
	{
		temp=getnode3(head2);
		printf("\n");
		last=head3;

		while(last->next!=NULL)
			last=last->next;
		last->next=temp;
	}
	//modify2(head3); //check if this is required
}


//DELITION
BILL *delete3(BILL *head3)
{
	BILL *last=NULL,*temp=NULL;
	int cnt=0 ,i=0,srno;
	printf("ENTER SR.NO YOU WANT TO DELETE :  ");
	scanf("%d",&srno);

	if(head3==NULL)
		printf("\nNOTHING IS PURCHESED...");
	else
	{
		cnt=countnodes3(head3);

		if(srno>=1&&srno<=cnt)
		{
			last=head3;

			for(i=1;i<srno-1;i++)
				last=last->next;

			temp=last->next;
			last->next=temp->next;
			free(temp);
		}
	}
	return (head3);
}

//SEARCHING
void search3(BILL *head3)
{
	int srno,c,q,totcost,k=0;
	BILL *ptr=NULL;
	printf("\nENTER SERIAL NO. WHICH IS TO BE SEARCHED :  ");
	scanf("%d",&srno);

	if(head3==NULL)
		printf("\nNO MATERIAL PURCHESED!!!");
	else
	{

		ptr=head3;

		while(ptr!=NULL)
		{
			k++;
			if(srno==k)
				break;
			else
				ptr=ptr->next;
		}

		if(ptr==NULL)
			printf("NOT FOUND...\n");
		else
		{
			printf("\nFOUND  AT POSITION :  %d",k);
			printf("\nMATERIAL NAME :  %10s",ptr->Mat);
			printf("\nCOST/MATERIAL :  %d",ptr->Cost);
			printf("\nQUANTITY :  %d",ptr->Qua);

			c=ptr->Cost;
			q=ptr->Qua;
			totcost=q*c;

			printf("\nTOTAL COST :  %d",totcost);
		}
	}
}