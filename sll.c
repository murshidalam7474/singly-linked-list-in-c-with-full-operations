#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node *next;
}*head;
void create(int n);
void display();
int search(int key);
int delete_ra();
int count();
void insert_pos(int);
int sum();
void delSLL();
int chsorte();
int getend();
int occurence();
void Asortt();
//void Dsortt();
void revr();
void dupl();
int getnode();
int detectandremov();
void swapNodes();
void swap();
void pairwiseswap();
int main()
{
    int i,n,t,s,ch,data,keyse,index,pos;
    int postail,sf,x,y;
    int chh;
    char ask;
    printf("\t\tsingly linked list by mohammed murshid alam\n");
    while(1)
    {
       printf("\n1.create\n2.display\n3.count\n4.Sum of all nodes\n5.Any where insert\n6.search an element\n7.DEL OPTION\n8.Check Sort\n9.remove duplicate\n10.To Reverse\n11Get node data\n12check for cycle detection");
        printf("\n13.getnode\n14get node from end\n15.occurence of data\n16.swap nodes in alinked list\n17.pairwise swap\n");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("enter number of nodes: ");
                    scanf("%d",&n);
                    create(n);
                    break;
            case 2: printf("The nodes are:\n");
                    display();
                    break;
            case 3: t=count();
                    printf("\n The length of node:%d\n",t);
                    break;
            case 4: s=sum();
                    printf("The sum of all elements in a linked list is : %d\n",s);
                    break;
            case 5:printf("\nenter the item to be inserted: ");
                    scanf("%d",&data);
                    insert_pos(data);
                    break;
            case 6: printf("enter element to search: ");
                    scanf("%d",&keyse);
                    index=search(keyse);
                    if(index>=0)
                        printf("\n%d found at position %d\n",keyse,index+1);
                    else
                    printf("Notttt founddd\n");
                    break;
            case 7:

                printf("1.DEL a NODE\n2.DEL a LL\n");
                printf("enter your choice: ");
                scanf("%d",&chh);
                if(chh==1)
                    delete_ra();
                else
                    delSLL();

                break;
            case 8:
                    if (chsorte(head))
                    {
                        printf("\n....sorted...\n");
                    }
                    else
                    {
                        printf("......not sorted.....\n");
                        printf("\nDO you want a sorted list(y/n): ");
                        scanf("%s",&ask);
                        if(ask=='y')
                        {

                               printf("\n\t.....After sorting the SLL in asscending.... \n");
                                Asortt();
                                display();
                        }
                        else
                        {
                            printf("\n");
                        }

                    }
                break;
            case 9:dupl();
                    break;
            case 10: revr();
                    display();
                    break;
            case 11: 
                    printf("enter position of node to get Data: ");
                    scanf("%d",&index);
                    getnode(head,index);
                    printf("Nth Node data of LinkedList i: %d\n", getnode(head, index));
                    break;
            case 12:detectandremov();
                    break;
            case 13:printf("enter a position to get a value: ");
                        scanf("%d",&index);
                    getnode(head,index);
                    printf("the data is %d ",getnode(head,index-1));
                    break;
            case 14:printf("enter a position from rev to get a value: ");
                    scanf("%d",&pos);
                    getend(head,pos);
                    break;
            case 15:printf("enter the data to see its freq: ");
                    scanf("%d",&sf);
                    occurence(head,sf);
                    printf("count of %d is %d",sf,occurence(head, sf));
                    break;
            case 16:printf("enter the number to be swapped : ");
                    scanf("%d %d",&x,&y); 
                    printf("before swapping\n");
                    display();
                    swapNodes(&head,x, y);
                    printf("after swapping\n");
                    display();
                    break;
            case 17: printf("before swapping\n");
                    display();
                    printf("\nafter pairwise swapping\n");
                    pairwiseswap(head);
                    display();
                    break;
            default:printf("INVALID CHOICE");
            exit(0);
        }
    }

    return 0;
}
void create(int n)
{

    struct node *newnode, *temp;
    int data,i;
    head=(struct node *)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("\n memory cannot allocate");
        //exit(0);
    }
    else
    {
        printf("Enter the data of node 1: ");
        scanf("%d",&data);
        head->data=data;
        head->next=NULL;
        temp=head;
        for(i=2;i<=n;i++)
        {
            //temp=head;
            newnode=(struct node*)malloc(sizeof(struct node));
            if (newnode==NULL)
            {
                 printf("\n memory cannot allocate");

            }
            else
            {
                printf("Enter the data of node %d: ",i);
                scanf("%d",&data);
                newnode->data=data;
                newnode->next=NULL;
                temp->next=newnode;
                temp=temp->next;
            }
        }
    }
}
void display()
{
    struct node *temp=head;
    if (head==NULL)
    {
        printf("LIST is EMPTY\n\n");
    }
    while(temp!=NULL)
    {
        printf("\nDATA IS ->%d\n",temp->data);
        temp=temp->next;
    }

}
int count()
{
    struct node *temp=head;
    int c=0;
    while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
    return (c);
}
int sum()
{
    struct node *temp=head;
    int sum=0;
    while(temp!=NULL)
    {
        sum=sum+temp->data;
        temp=temp->next;
    }
    return (sum);
}
void insert_pos(int data)
{
    struct node *temp,*newnode=(struct node *)malloc(sizeof(struct node));
    int i,pos;
    printf("enter pos to be inserted: ");
    scanf("%d",&pos);
    if(newnode==NULL)
    {
        printf("underflowww");
    }
    if(pos==1)
    {
       newnode->data=data;
       newnode->next=head;
       head=newnode;
       printf("\nNODE INSERTED\n");

    }
    else
    {
        newnode->data=data;
        temp=head;
        for(i=0;i<pos-1;i++)
        {
            temp=temp->next;
            if(temp==NULL)
            {
                printf("\ncant insert");
                return ;
            }
        }
        newnode->next=temp->next;
        temp->next=newnode;
        printf("\nNODE INSERTED\n");
    }
}
int search(int key)
{
    int index;
    struct node *p;
    index=0;
    p=head;
    while(p!=NULL&&p->data!=key)
    {
        index++;
        p=p->next;
    }
    //return (curnode!=NULL);
    return (index);
}
int delete_ra()
{

    struct node *p=head,*q=NULL;
    int i,pos,x;
    printf("enter pos to be del: ");
    scanf("%d",&pos);
    if(pos==1)
    {
        q=head;
        head=head->next;
        printf("%d deleted\n",p);
        free(q);

    }
    else if (head==NULL)
    {
        printf("list is empty\n");
    }
    else if(pos<1 || pos >count(p))
    {
        printf("invalid positon\n");

    }
    else
    {
        for(i=0;i<pos-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        free(p);
        printf("node succefully deleted\n");
    }
}
void delSLL()
{
    struct node*p;
    while(head!=NULL)
    {
        p=head;
        head=head->next;
        free(p);
    }
    printf("succesfully deleted all nodes\n");
}
int chsorte()
{
    struct node*p=head;
    int x=-32768;
    while(p!=NULL)
    {
        if (p->data<x)
            return 0;
        x=p->data;
        p=p->next;

    }
    return 1;


}
void dupl()
{
     struct node *current = head, *index = NULL, *temp = NULL;

    if(head == NULL) {
        return;
    }
    else {
        while(current != NULL){
            temp = current;

            index = current->next;

            while(index != NULL) {

                if(current->data == index->data) {


                    temp->next = index->next;
                }
                else {

                    temp = index;
                }
                index = index->next;
            }
            current = current->next;

        }
        printf("\nDuplicate succefully removed\n");
    }
}
void Asortt()
{
    struct node *p=head,*q;
    int temp;
    while(p->next!=NULL)
    {
        q=p->next;
        while(q!=NULL)
        {
            if(p->data>q->data)
            {
                temp=p->data;
                p->data=q->data;
                q->data=temp;
            }
            q=q->next;
        }
        p=p->next;
    }
}
/*void Dsortt()
{
    struct node *p=head,*q;
    int temp;
    while(p->next!=NULL)
    {
        q=p->next;
        while(q!=NULL)
        {
            if(p->data<q->data)
            {
                temp=p->data;
                p->data=q->data;
                q->data=temp;
            }
            q=q->next;
        }
        p=p->next;
    }
}*/
void revr()
{
    struct node*p=head;
    int i=0,A[10000];
    while(p!=NULL)
    {
        A[i]=p->data;
        p=p->next;
        i++;
    }
    p=head;
    i--;
    while(p!=NULL)
    {
        p->data=A[i--];
        p=p->next;
    }

}
int getnode(struct node*head,int index)
{
   struct node *currentPointer = head;
    int length = 0;
    while (currentPointer != NULL) {
            if (length == index)
                return (currentPointer->data);
            length++;
            currentPointer = currentPointer->next;
    }
    return -1;
    //printf(" %d",current->data);
}
int detectandremov(struct node*head)
{
    struct node*slow=head,*fast=head;
    while(slow&&fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            removeloop(slow,head);
            printf("cycle detected");
            return 1;
        }
    }
    printf("No cycle detected");
    return 0;
}
void removeloop(struct node *loop_node,struct node*head)
{
    struct node*p1,*p2;
    p1=head;
    while(1)
    {
        p2=loop_node;
        while(p2->next!=loop_node&&p2 ->next!=p1)
        {
            p2=p2->next;
        }
        if(p2->next==p1)
        break;
        p1=p1->next;
    }
    p2->next=NULL;
    
}
int getend(struct node *head,int pos)
{
    int len=0,i;
    struct node*p=head;
    while(p!=NULL)
    {
        p=p->next;
        len++;
    }
    if(len<pos)
    {
        printf("out of range of value");
        return;
    }
    p=head;
    for (i=1;i<len-pos+1;i++)
    {
        p=p->next;
    }
    printf("%d is the data",p->data);
    return;
}
int occurence(struct node*head,int sf)
{
    struct node*p=head;
    int c=0;
    while (p) {
    if(p->data==sf)
    {
        c++;
    }
    p=p->next;
    }
    return c;
}
void swapNodes(struct node** head_ref, int x, int y)
{
	// Nothing to do if x and y are same
	if (x == y)
		return;

	// Search for x (keep track of prevX and CurrX
	struct node *prevX = NULL, *currX = *head_ref;
	while (currX && currX->data != x) {
		prevX = currX;
		currX = currX->next;
	}

	// Search for y (keep track of prevY and CurrY
	struct node *prevY = NULL, *currY = *head_ref;
	while (currY && currY->data != y) {
		prevY = currY;
		currY = currY->next;
	}

	// If either x or y is not present, nothing to do
	if (currX == NULL || currY == NULL)
		return;

	// If x is not head of linked list
	if (prevX != NULL)
		prevX->next = currY;
	else // Else make y as new head
		*head_ref = currY;

	// If y is not head of linked list
	if (prevY != NULL)
		prevY->next = currX;
	else // Else make x as new head
		*head_ref = currX;

	// Swap next pointers
	struct node* temp = currY->next;
	currY->next = currX->next;
	currX->next = temp;
}
void swap(int *a,int*b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void pairwiseswap(struct node*head)
{
    struct node*p=head;
    while (p!=NULL && p->next!=NULL) {
        swap(&p->data, &p->next->data);
        p=p->next->next;
    }
}
