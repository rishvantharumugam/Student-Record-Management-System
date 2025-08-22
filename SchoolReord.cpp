
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    int roll;
    char name[30];
    int marks;
    struct node *next;
};
struct node *create(){
    struct node *head=(struct node *)malloc(sizeof(struct node));
    struct node *first=(struct node *)malloc(sizeof(struct node));
    struct node *second=(struct node *)malloc(sizeof(struct node));
    struct node *third=(struct node *)malloc(sizeof(struct node));
    struct node *fourth=(struct node *)malloc(sizeof(struct node));
    struct node *fifth=(struct node *)malloc(sizeof(struct node));
    struct node *sixth=(struct node *)malloc(sizeof(struct node));
    head->next=first;
    first->roll=120;
    strcpy(first->name,"Jack");
    first->marks=487;
    first->next=second;
    second->roll=115;
    strcpy(second->name,"Lily");
    second->marks=476;
    second->next=third;
    third->roll=114;
    strcpy(third->name,"Tom");
    third->marks=485;
    third->next=fourth;
    fourth->roll=113;
    strcpy(fourth->name,"Joe");
    fourth->marks=406;
    fourth->next=fifth;
    fifth->roll=112;
    strcpy(fifth->name,"Jerry");
    fifth->marks=498;
    fifth->next=sixth;
    sixth->roll=111;
    strcpy(sixth->name,"Reo");
    sixth->marks=389;
    sixth->next=NULL;
    return head;
}
struct node *insertAtBeginning(struct node *head,int r,char *nam,int mark)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->roll=r;
    strcpy(newnode->name,nam);
    newnode->marks=mark;
    newnode->next=head->next;
    head->next=newnode;
    return head;
}
struct node *insertAtEnd(struct node *head,int r,char *nam,int mark){
    struct node *temp=head;
    int i=0;
    while(temp->next!=NULL){
        temp=temp->next;
        i++;
    }
    if(temp!=NULL){
        struct node *newnode=(struct node *)malloc(sizeof(struct node));
        newnode->roll=r;
        strcpy(newnode->name,nam);
        newnode->marks=mark;
        newnode->next=temp->next;
        temp->next=newnode;
    }
    return head;
}
struct node *deleterecord(struct node *head,int val){
    struct node *pre=NULL;
    struct node *temp=head;
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
struct node *searchStudent(struct node *head,int r){
    struct node*temp=head;
    int i=0,flag=0;
    while(temp!=NULL){
        if(temp->roll==r){
           flag=1;
           break;
        }
        i++;
        temp=temp->next;
    }
    if(flag==1){
        printf("Roll Number %d is Present in the list\n",r);
    }
    else{
        printf("Roll Number %d is Not Present in the list\n",r);
    }
}
struct node *updatestudentroll(struct node *head,int oldno,int newno){
    struct node *temp=head->next;
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

    return head;
}
struct node *updatestudentname(struct node *head,char *oldnam,char *newnam){
    struct node *temp=head->next;
    while(temp!=NULL && strcmp(temp->name,oldnam)!=0)
    {
        temp=temp->next;
    }
    if(temp==NULL){
    	printf("\n");
		printf("Name not found! Update Failed.!");
		printf("\n");
    	return head;
	}
    strcpy(temp->name,newnam);
    printf("\n");
    printf("Name Updated Successfully!\n");
    return head;
}
struct node *updatestudentmark(struct node *head,int oldmark,int newmark){
    struct node *temp=head->next;
    while(temp!=NULL && temp->marks!=oldmark)
    {
        temp=temp->next;
    }
	if(temp==NULL){
    	printf("\n");
		printf("Mark not found! Update Failed.!");
		printf("\n");
    	return head;
	}
    temp->marks=newmark;
    printf("\n");
    printf("Mark Updated Successfully!\n");
    return head;
}
struct node *sort(struct node *head){
	struct node *i,*j;
	for(i=head->next;i!=NULL;i=i->next){
		for(j=i->next;j!=NULL;j=j->next){
			if(i->roll<j->roll){
				int troll=i->roll;
				i->roll=j->roll;
				j->roll=troll;
				char tname[50];
				strcpy(tname,i->name);
				strcpy(i->name,j->name);
				strcpy(j->name,tname);
				int tmark=i->marks;
				i->marks=j->marks;
				j->marks=tmark;
			}
		}
	}
	return head;
}
void display(struct node*head){
    struct node *temp=head->next;
    int i=0;
    while(temp!=NULL){
        printf("%d",temp->roll);
        printf(" %s ",temp->name);
        printf("%d ",temp->marks);
        temp=temp->next;
        if(temp!=NULL){
        	printf("-> ");
		}
    }
}


int main()
{
    struct node *head=create();
	while(1){
    printf("<-----Student Record Management System----->\n");
    printf("\n");
    printf("1.Add student record at Beginning\n");
    printf("2.Add student record at End\n");
    printf("3.Delete a Student Record\n");
    printf("4.Search a Student Record\n");
    printf("5.Update Student Information\n");
    printf("6.Display Students Records\n");
    printf("7.Exit\n");
    int n;
    printf("\n");
    printf("Choose Your Choice:");
    scanf("%d",&n);
    int r,mark;
    char nam[30];
    switch(n){
        case 1:
        	printf("\n");
        	display(head);
        	printf("\n");
        	printf("\n");
            printf("Enter Roll no:");
            scanf("%d",&r);
            printf("Enter Name:");
            scanf("%s",&nam);
            printf("Enter Marks:");
            scanf("%d",&mark);
            head=insertAtBeginning(head,r,nam,mark);
            printf("\n");
            printf("Record Added to the List Successfully!\n");
            printf("\n");
            display(head);
            printf("\n");
            printf("\n");
            break;
        case 2:
        	printf("\n");
        	display(head);
        	printf("\n");
        	printf("\n");
            printf("Enter Roll no:");
            scanf("%d",&r);
            printf("Enter Name:");
            scanf("%s",&nam);
            printf("Enter Marks:");
            scanf("%d",&mark);
            head=insertAtEnd(head,r,nam,mark);
            printf("\n");
            printf("Record Added to the List Successfully!\n");
            printf("\n");
            display(head);
            printf("\n");
            printf("\n");
            break;
        case 3:
        	printf("\n");
        	display(head);
        	printf("\n");
        	printf("\n");
            printf("Enter the Rollno should be Deleted:");
            int val;
            scanf("%d",&val);
            head=deleterecord(head,val);
            printf("\n");
            display(head);
            printf("\n");
            printf("\n");
            break;
        case 4:
        	printf("\n");
            printf("Enter Roll no:");
            scanf("%d",&r);
            printf("\n");
            searchStudent(head,r);
            printf("\n");
            display(head);
            printf("\n");
            printf("\n");
            break;
        case 5:
        	printf("\n");
        	display(head);
        	printf("\n");
        	printf("\n");
            printf("Select which Data Should be Updated?\n");
            printf("\n");
            printf("1.Roll Number\n");
            printf("2.Name\n");
            printf("3.Mark\n");
            int no,oldno,newno;
            printf("\n");
            printf("Enter the Data No to Be Updated:");
            scanf("%d",&no);
            switch(no){
                case 1:
                printf("\n");
                printf("Enter the Roll no to be Updated:");
                scanf("%d",&oldno);
                printf("Roll to be Updated to:");
                scanf("%d",&newno);
                head=updatestudentroll(head,oldno,newno);
                printf("\n");
                display(head);
                printf("\n");
                printf("\n");
                break;
            case 2:
                printf("\n");
				char oldnam[30],newnam[30];
                printf("Enter the Name to be Updated:");
                scanf("%s",&oldnam);
                printf("Name to be updated to:");
                scanf("%s",&newnam);
                head=updatestudentname(head,oldnam,newnam);
                printf("\n");
                display(head);
                printf("\n");
                printf("\n");
                break;
            case 3:
            	printf("\n");
                int oldmark,newmark;
                printf("Enter the Mark to be Updated:");
                scanf(" %d",&oldmark);
                printf("Mark to be Updated to:");
                scanf(" %d",&newmark);
                head=updatestudentmark(head,oldmark,newmark);
                printf("\n");
                display(head);
                printf("\n");
                printf("\n");
                break;    
            }
            break;
        case 6:
        	printf("\n");
        	head=sort(head);
            display(head);
            printf("\n");
            printf("\n");
            break;
        case 7:
        	printf("\n");
        	printf("Program Exited Successfully");
        	exit(0);
        default:
            printf("Invalid Choice!");
    }
}
}

