#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct student{
    int standard;
	int roll;
    char name[30];
    int marks;
    struct student *next;
};
struct student *create(){
    struct student *head=(struct student *)malloc(sizeof(struct student));
    head->next=NULL;
    return head;
}
struct student *insertAtBeginning(struct student *head,int s,int r,char *nam,int mark)
{
    struct student *newnode=(struct student *)malloc(sizeof(struct student));
    newnode->standard=s;
	newnode->roll=r;
    strcpy(newnode->name,nam);
    newnode->marks=mark;
    newnode->next=head->next;
    head->next=newnode;
    return head;
}
struct student *insertAtEnd(struct student *head,int s,int r,char *nam,int mark){
    struct student *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    if(temp!=NULL){
        struct student *newnode=(struct student *)malloc(sizeof(struct student));
        newnode->standard=s;
		newnode->roll=r;
        strcpy(newnode->name,nam);
        newnode->marks=mark;
        newnode->next=temp->next;
        temp->next=newnode;
    }
    return head;
}
int primaryrollno(struct student *head,int r){
	struct student *temp=head->next;
	while(temp!=NULL){
		if(temp->roll==r){
			return 0;
		}
		temp=temp->next;
	}
	return 1;
}
struct student *deleterecord(struct student *head,int val){
    struct student *pre=head;
    struct student *temp=head->next;
	while(temp!=NULL && temp->roll!=val){
        pre=temp;
        temp=temp->next;
    }
    if(temp==NULL){
    	printf("\n");
        printf("Invalid Roll No!");
        printf("\n");
        return head;
    }
    pre->next=temp->next;
    free(temp);
    printf("\n");
    printf("Roll No %d Record Have been Deleted Successfully!\n",val);
    return head;
}
void searchStudent(struct student *head,int r){
    struct student*temp=head;
    int flag=0;
    while(temp!=NULL){
        if(temp->roll==r){
           flag=1;
           break;
        }
        temp=temp->next;
    }
    if(flag==1){
        printf("Roll Number %d is Present in the list\n",r);
    }
    else{
        printf("Roll Number %d is Not Present in the list\n",r);
    }
}
struct student* updatestudentstandard(struct student *head,int r,int newst){
    struct student *temp=head->next;
    while(temp!=NULL && temp->roll!=r){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("\nRoll No not found! Update Failed.\n");
        return head;
    }
    temp->standard=newst;
    printf("\nStandard Updated Successfully.\n");
    return head;
}
struct student *updatestudentroll(struct student *head,int oldno,int newno){
    struct student *temp=head->next;
    while(temp!=NULL && temp->roll!=oldno)
    {
        temp=temp->next;
    }
    if(temp==NULL){
    	printf("\n");
		printf("Roll No not found! Update Failed.!");
		printf("\n");
    	return head;
	}
    temp->roll=newno;
	printf("\nRoll No Updated Successfully.\n");
    return head;
}
struct student* updatestudentname(struct student *head,int r,char *newnam){
    struct student *temp=head->next;
    while(temp!=NULL && temp->roll!=r){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("\nRoll No not found!Update Failed.\n");
        return head;
    }
    strcpy(temp->name,newnam);
    printf("\nName Updated Successfully.\n");
    return head;
}
struct student* updatestudentmark(struct student *head,int r,int newmark){
    struct student *temp=head->next;
    while(temp!=NULL && temp->roll!=r){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("\nRoll No not found!Update Failed.\n");
        return head;
    }
    temp->marks=newmark;
    printf("\nMarks Updated Successfully.\n");
    return head;
}
void sortstandard(struct student *head){
	struct student *i,*j;
	int changestandard;
	int changeroll;
    char changename[50];
    int changemarks;
    for(i=head->next;i!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(i->standard > j->standard)
			{
                changestandard=i->standard;
                i->standard=j->standard;
                j->standard=changestandard;
				changeroll=i->roll;
                i->roll=j->roll;
                j->roll=changeroll;
                strcpy(changename,i->name);
                strcpy(i->name,j->name);
                strcpy(j->name,changename);
                changemarks=i->marks;
                i->marks=j->marks;
                j->marks=changemarks;
            }
        }
    }
    printf("\n");
    struct student *temp=head->next;
	printf("%-8s %-8s %-20s %-8s\n","Class","RollNo","Name","Marks");
    while(temp!=NULL){
    	printf("%-8d %-8d %-20s %-8d\n",temp->standard,temp->roll,temp->name,temp->marks);
    	temp=temp->next;
	}
    printf("\n");
}
void sortroll(struct student *head){
	struct student *i,*j;
	int changestandard;
	int changeroll;
    char changename[50];
    int changemarks;
    for(i=head->next;i!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(i->roll > j->roll)
			{
                changestandard=i->standard;
                i->standard=j->standard;
                j->standard=changestandard;
				changeroll=i->roll;
                i->roll=j->roll;
                j->roll=changeroll;
                strcpy(changename,i->name);
                strcpy(i->name,j->name);
                strcpy(j->name,changename);
                changemarks=i->marks;
                i->marks=j->marks;
                j->marks=changemarks;
            }
        }
    }
    printf("\n");
    struct student *temp=head->next;
	printf("%-8s %-8s %-20s %-8s\n","Class","RollNo","Name","Marks");
   	while(temp!=NULL){
    	printf("%-8d %-8d %-20s %-8d\n",temp->standard,temp->roll,temp->name,temp->marks);
    	temp=temp->next;
	}
    printf("\n");
}
void sortname(struct student *head){
	struct student *i,*j;
	int changestandard;
	int changeroll;
    char changename[50];
    int changemarks;
    for(i=head->next;i!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(strcmp(i->name,j->name) > 0)
			{
                changestandard=i->standard;
                i->standard=j->standard;
                j->standard=changestandard;
				changeroll=i->roll;
                i->roll=j->roll;
                j->roll=changeroll;
                strcpy(changename,i->name);
                strcpy(i->name,j->name);
                strcpy(j->name,changename);
                changemarks=i->marks;
                i->marks=j->marks;
                j->marks=changemarks;
            }
        }
    }
    printf("\n");
    struct student *temp=head->next;
	printf("%-8s %-8s %-20s %-8s\n","Class","RollNo","Name","Marks");
    while(temp!=NULL){
    	printf("%-8d %-8d %-20s %-8d\n",temp->standard,temp->roll,temp->name,temp->marks);
    	temp=temp->next;
	}
    printf("\n");
}
void sortmark(struct student *head){
	struct student *i,*j;
	int changestandard;
	int changeroll;
    char changename[50];
    int changemarks;
    for(i=head->next;i!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(i->marks > j->marks)
			{
                changestandard=i->standard;
                i->standard=j->standard;
                j->standard=changestandard;
				changeroll=i->roll;
                i->roll=j->roll;
                j->roll=changeroll;
                strcpy(changename,i->name);
                strcpy(i->name,j->name);
                strcpy(j->name,changename);
                changemarks=i->marks;
                i->marks=j->marks;
                j->marks=changemarks;
            }
        }
    }
    printf("\n");
    struct student *temp=head->next;
	printf("%-8s %-8s %-20s %-8s\n","Class","RollNo","Name","Marks");
    while(temp!=NULL){
    	printf("%-8d %-8d %-20s %-8d\n",temp->standard,temp->roll,temp->name,temp->marks);
    	temp=temp->next;
	}
    printf("\n");
}
void liststandard(struct student *head,int t){
	struct student *temp=head->next;
	int flag3=0;
	while(temp!=NULL){
		if(temp->standard==t){
			if(flag3==0){
				printf("\n%-8s %-8s %-20s %-8s\n","Class","RollNo","Name","Marks");
			}
			printf("%-8d %-8d %-20s %-8d\n",temp->standard,temp->roll,temp->name,temp->marks);
    		flag3=1;
		}
		temp=temp->next;
	}
	if(flag3==0){
		printf("\nThere are no Students in Standard %d\n",t);
	}
}
void rankmark(struct student *head,int t){
	struct student *i,*j;
	int changestandard;
	int changeroll;
    char changename[50];
    int changemarks;
    for(i=head->next;i!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(i->marks < j->marks)
			{
                changestandard=i->standard;
                i->standard=j->standard;
                j->standard=changestandard;
				changeroll=i->roll;
                i->roll=j->roll;
                j->roll=changeroll;
                strcpy(changename,i->name);
                strcpy(i->name,j->name);
                strcpy(j->name,changename);
                changemarks=i->marks;
                i->marks=j->marks;
                j->marks=changemarks;
            }
        }
    }
    printf("\n");
    struct student *temp=head->next;
	printf("%-8s %-8s %-20s %-8s\n","Class","RollNo","Name","Marks");
	int r=0;
    while(temp!=NULL && r<t){
    	printf("%-8d %-8d %-20s %-8d\n",temp->standard,temp->roll,temp->name,temp->marks);
    	temp=temp->next;
    	r+=1;
	}
    printf("\n");
}
int total(struct student *head){
	struct student *temp=head->next;
	int count=0;
	while(temp!=NULL){
		count+=1;
		temp=temp->next;
	}
	return count;
}
void rankByMarks(struct student *head,int st){
    struct student *temp=head->next;
    struct student *rank[100];  
    int count=0;
    while(temp!=NULL){
        if(temp->standard==st){
            rank[count]=temp;
            ++count;
        }
        temp=temp->next;
    }
    if(count==0){
        printf("\nNo students found in Standard %d.\n",st);
        return;
    }
    for(int i=0;i<count-1;i++){
        for(int j=i+1;j<count;j++){
            if(rank[i]->marks < rank[j]->marks){
                struct student *changerankmark=rank[i];
                rank[i]=rank[j];
                rank[j]=changerankmark;
            }
        }
    }
    printf("\n%-5s %-8s %-20s %-8s\n","Rank","RollNo","Name","Marks");
    for(int i=0;i<count;i++){
        printf("%-5d %-8d %-20s %-8d\n",i+1,rank[i]->roll,rank[i]->name,rank[i]->marks);
    }
}
void display(struct student*head){
	struct student *temp=head->next;
    printf("%-8s %-8s %-20s %-8s\n","Class","RollNo","Name","Marks");
	while(temp!=NULL){
    	printf("%-8d %-8d %-20s %-8d\n",temp->standard,temp->roll,temp->name,temp->marks);
    	temp=temp->next;
	}
}
int main()
{
    struct student *head=create();
    while(1){
    printf("\n");
    printf("<-----Student Record Management System----->\n");
    printf("\n");
    printf("1.Add student record at Beginning\n");
    printf("2.Add student record at End\n");
    printf("3.Delete a Student Record\n");
    printf("4.Search a Student Record\n");
    printf("5.Update Student Records\n");
    printf("6.Display All Students Records\n");
	printf("7.Display Sorted Student Records\n");
    printf("8.Display Students Standard wise\n");
	printf("9.Display Top Students Rank\n");
    printf("10.Exit\n");
    int n;
    printf("\n");
    printf("Choose Your Choice:");
    scanf("%d",&n);
    int s,r,mark;
    char nam[30];
    switch(n)
    {
        case 1:
    	{
        	int n4,error=1;
        	printf("Enter No of Datas to be Inserted:");
        	scanf("%d",&n4);
        	for(int i=1;i<=n4;i++){
        		printf("\n");
        		printf("Enter Standard:");
            	scanf("%d",&s);
            	printf("Enter Roll no:");
            	scanf("%d",&r);
            	printf("Enter Name:");
            	scanf("%s",&nam);
            	printf("Enter Marks:");
            	scanf("%d",&mark);
            	int Roll=primaryrollno(head,r);
            	if(Roll==0){
            		error=0;
					printf("\nDuplicate Roll No! Roll No Already Exist.");
            		printf("\n");
            		break;
				}
				else if(s<1 || s>12){
					error=0;
					printf("\nInvalid Standard! Enter Standard Between (1-12).\n");
				}
				else{
					for(int i=0;i<strlen(nam);i++){
						if(!isalpha(nam[i])){
							error=0;
							printf("\nInvalid Name! Enter Only Alphabets.\n");
							break;
						}
					}
				}
				if(error!=0){
					if(mark>=0 && mark<=500){
            			head=insertAtBeginning(head,s,r,nam,mark);
        			}
        			else{
						error=0;
						printf("\nInvalid Mark! Enter Mark Between (1-500).");
        				printf("\n");
        				break;
					}
				}
			}
			printf("\n");
			if(error==1){
				printf("\nRecord Added to the List Successfully.\n");
            }
			break;
		}
        case 2:
		{
        	int n3,error=1;
        	printf("Enter No of Datas to be Inserted:");
        	scanf("%d",&n3);
        	for(int i=1;i<=n3;i++){
        		printf("\n");
        		printf("Enter Standard:");
            	scanf("%d",&s);
            	printf("Enter Roll no:");
            	scanf("%d",&r);
            	printf("Enter Name:");
            	scanf("%s",&nam);
            	printf("Enter Marks:");
            	scanf("%d",&mark);
            	int Roll=primaryrollno(head,r);
            	if(Roll==0){
            		error=0;
					printf("\nDuplicate Roll No! Roll No Already Exist.");
            		printf("\n");
            		break;
				}
				else if(s<1 || s>12){
					error=0;
					printf("\nInvalid Standard! Enter Standard Between (1-12).\n");
				}
				else{
					for(int i=0;i<strlen(nam);i++){
						if(!isalpha(nam[i])){
							error=0;
							printf("\nInvalid Name! Enter Only Alphabets.\n");
							break;
						}
					}
				}
				if(error!=0){
					if(mark>=0 && mark<=500){
            			head=insertAtEnd(head,s,r,nam,mark);
        			}
        			else{
						error=0;
						printf("\nInvalid Mark! Enter Mark Between (1-500).");
        				printf("\n");
        				break;
					}
				}
			}
			printf("\n");
			if(error!=0){
				printf("Record Added to the List Successfully.\n");
            }
			break;
		}
        case 3:
        {
			if(head->next==NULL){
        		printf("\nList is Empty! Insert The Records First.\n");
        		break;
			}
        	printf("\n");
            printf("Enter the Rollno should be Deleted:");
            int val;
            scanf("%d",&val);
            head=deleterecord(head,val);
            break;
        }
        case 4:
        {
			if(head->next==NULL){
        		printf("\nList is Empty! Insert The Records First.\n");
        		break;
			}
        	printf("\n");
            printf("Enter Roll no:");
            scanf("%d",&r);
            printf("\n");
            searchStudent(head,r);
            break;
        }
        case 5:
    		if(head->next==NULL){
        		printf("\nList is Empty! Insert The Records First.\n");
        		break;
    		}
    		printf("\nSelect which Data Should be Updated?\n");
   			printf("1.Standard\n");
    		printf("2.Roll Number\n");
    		printf("3.Name\n");
    		printf("4.Mark\n");
			int no;
    		printf("\nEnter the Data No to Be Updated:");
    		scanf("%d",&no);
    		switch(no){
        	case 1:
        	{
            	int r1,newst;
            	printf("\nEnter the Roll No:");
            	scanf("%d",&r1);
            	printf("Standard to be Updated to:");
            	scanf("%d",&newst);
            	if(newst>=1 && newst<=12){
                	head=updatestudentstandard(head,r1,newst);
            	}
				else{
                	printf("\nInvalid Standard! Enter Standard Between (1-12).\n");
            	}
            	break;
        	}
        	case 2: 
        	{
            	int oldno,newno,error=1;
            	printf("\nEnter the Roll No to be Updated:");
            	scanf("%d",&oldno);
            	printf("Roll to be Updated to:");
            	scanf("%d",&newno);
            	int Roll=primaryrollno(head,newno);
            	if(Roll==0){
                	error=0;
                	printf("\nDuplicate Roll No! Roll No Already Exist.\n");
                	break;
            	}
            	if(error){
                	head=updatestudentroll(head,oldno,newno);
            	}
            	break;
        	}
    	    case 3:
        	{
            	char newnam[30];
            	int r2,error=1;
            	printf("\nEnter the Roll No:");
            	scanf("%d",&r2);
            	printf("Name to be updated to:");
            	scanf("%s",newnam);
            	for(int i=0;i<strlen(newnam);i++){
                	if(!isalpha(newnam[i])){
                    	error=0;
                    	printf("\nInvalid Name! Enter Only Alphabets.\n");
                    	break;
                	}
            	}
				if(error){
                	head=updatestudentname(head,r2,newnam);
            	}
            	break;
        	}
        	case 4: 
        	{
            	int r3,newmark;
            	printf("\nEnter the Roll No:");
            	scanf("%d",&r3);
            	printf("Mark to be Updated to:");
            	scanf("%d",&newmark);
				if(newmark>=0 && newmark<=500) {
                	head=updatestudentmark(head,r3,newmark);
            	}
				else{
                	printf("\nInvalid Mark! Enter Mark Between (0-500).\n");
            	}
            	break;
        	}
        	default:
            	printf("\nInvalid Choice! Choose Between (1-4).\n");
            	break;
    		}
   	 	break;
	    case 6:
        {
			if(head->next==NULL){
        		printf("\nList is Empty! Insert The Records First.\n");
        		break;
			}
        	printf("\n");
            display(head);
            printf("\n");
            break;
     	}
		case 7:
        {
			if(head->next==NULL){
        		printf("\nList is Empty! Insert The Records First.\n");
        		break;
			}
        	printf("\n");
            printf("Select in which Data Order Should be Sorted\n");
            printf("\n");
            printf("1.Standard\n");
            printf("2.Roll\n");
            printf("3.Name\n");
            printf("4.Mark\n");
            printf("\n");
            printf("Select your Choice:");
            int choice1;
            scanf("%d",&choice1);
            switch(choice1){
            	case 1:{
            		sortstandard(head);
            		break;
            	}
				case 2:{
					sortroll(head);
					break;
				}
                case 3:{
                	sortname(head);
					break;
				}
            	case 4:{
            		sortmark(head);
					break;
				}
            	default:
            		printf("\nInvalid Choice! Choose Your Choice Between (1-4).\n");
            		break;
        	}
        	printf("\n");
        	break;
    	}
        case 8:
		{
        	int t;
        	printf("Enter the Standard:");
        	scanf("%d",&t);
        	if(t>=1 && t<=12){
        		liststandard(head,t);
			}
        	else{
				printf("\nInvalid Standard! Enter Standard Between (1-12).\n");
			}
			break;
		}
		case 9:
		{
			int t,st;
        	printf("Enter Standard:");
        	scanf("%d",&st);
        	if(st>=1 && st<=12){
        		rankByMarks(head,st);
			}
        	else{
				printf("\nInvalid Standard! Enter Standard from (1-12).\n");
			}
			break;
		}
        case 10:
		{	
        	printf("\n");
        	printf("Program Exited Successfully.");
        	exit(0);
        }
        default:
            printf("\nInvalid Choice! Choose Choice Between (1-4)\n");
            break;
    }
}
}
