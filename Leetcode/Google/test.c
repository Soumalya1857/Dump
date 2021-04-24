#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void insert_at_begin();
void insert_at_end();
void insert_at_position();
void delete_from_begin();
void delete_from_end();
void delete_from_position();
void reverse();

struct node
{
    int data;
    struct node *next,*prev;
};
struct node *head = NULL,*newnode,*temp,*tail;
int count=0;

void main()
{
    int n=1,choice;
    while(n==1)
    {
        printf("*******MENU*******\n");
        printf("Press 1 for create a node\n");
        printf("Press 2 for display the list\n");
        printf("Press 3 for insert a node at beginning\n");
        printf("Press 4 for insert a node at end\n");
        printf("Press 5 for insert a node at any position\n");
        printf("Press 6 for delete a node from beginning\n");
        printf("Press 7 for delete a node from end\n");
        printf("Press 8 for delete a node from any position\n");
        printf("Press 9 for reverse the list\n");
        printf("Press 10 for EXIT the program\n");
        printf("Enter Your Choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                create();
                break;
            }
            case 2:
            {
                display();
                break;
            }
            case 3:
            {
                insert_at_begin();
                break;
            }
            case 4:
            {
                insert_at_end();
                break;
            }
            case 5:
            {
                insert_at_position();
                break;
            }
            case 6:
            {
                delete_from_begin();
                break;
            }
            case 7:
            {
                delete_from_end();
                break;
            }
            case 8:
            {
                delete_from_position();
                break;
            }
            case 9:
            {
                reverse();
                break;
            }
            case 10:
            {
                exit(0);
                break;
            }
            default:
            {
                printf("wrong choice\n");
            }
        }
    }
}

void create()
{
    //head=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));
    if (newnode==NULL)
    {
        printf("Memory allocation failed\n");
    }
    else
    {
        printf("enter data: ");
        int data;
        scanf("%d",&data);
        newnode->data = data;

        newnode->prev=NULL;
        newnode->next=NULL;
        if (head==NULL)
        {
            head=newnode;
            tail = newnode;
        }
        else
        {
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
            count++;
        }
    }
    printf("\nnode created successfully\n");
}

void display()
{
    temp=head;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("node displayed successfully\n");
}

void insert_at_begin()
{
    if (newnode==0)
    {
        printf("Memory allocation failed\n");
    }
    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter data\n");
        scanf("%d",&newnode->data);
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
        count++;
    }
    printf("node insertion at beginning successful\n");
}

void insert_at_end()
{
    if (newnode==0)
    {
        printf("Memory allocation failed\n");
    }
    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter data\n");
        scanf("%d",&newnode->data); 
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
        count++;
    }
    printf("node insertion at end successful\n");
}

void insert_at_position()
{
    if (newnode==0)
    {
        printf("Memory allocation failed\n");
    }
    else
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter data\n");
        scanf("%d",&newnode->data);
        int i=1,pos;
        printf("Enter position\n");
        scanf("%d",&pos);
        if (pos<=0||pos>count)
        {
            printf("invalid position\n");
        }
        else if (pos==1)
        {
            insert_at_begin();
        }
        else
        {
            temp=head;
            while (i<pos-1)
            {
                temp=temp->next;
                i++;
            }
            newnode->prev=temp;
            newnode->next=temp->next;
            temp->next=newnode;
            newnode->next->prev=newnode;
            count++;
        }
        printf("node insertion at %d position is successful\n",pos);
    }
}

void delete_from_begin()
{
    if (head==0)
    {
        printf("list is empty\n");
    }
    else
    {
        temp=head;
        head=head->next;
        head->prev=0;
        free (temp);
        count--;
    }
    printf("node deletion from beginning successful\n");
}

void delete_from_end()
{
    if (head==0)
    {
        printf("list is empty\n");
    }
    else
    {
        temp=tail;
        tail=tail->prev;
        tail->next=0;
        free (temp);
        count--;
    }
    printf("node deletion from end successful\n");
}

void delete_from_position()
{
    if (head==0)
    {
        printf("list is empty\n");
    }
    else
    {
        int i=1,pos;
        printf("enter position\n");
        scanf("%d",&pos);
        if(pos<=0||pos>count)
        {
            printf("invaild position\n");
        }
        else if (pos==1)
        {
            delete_from_begin();
        }
        else
        {
            temp=head;
            while (i<pos)
            {
                temp=temp->next;
                i++;
            }
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free (temp);
            count--;
        }
        printf("node deletion from %d position successful\n",pos);
    }
}

void reverse()
{
    struct node *current,*nextnode;
    current=head;
    while (nextnode!=0)
    {
        nextnode=current->next;
        current->next=current->prev;
        current->prev=nextnode;
        current=nextnode;
    }
    current=head;
    head=tail;
    tail=current;
    printf("list has been reversed\n");
}



// #include<stdio.h>
// #include<stdlib.h>
// int *assign(int* x, int val)
// {
//     *x = val;
//     return x;
// }
// void main()
// {
//     int* x = malloc(sizeof(int));
//     if(NULL == x) return;
//     x = assign(x,10);

//     if(x)
//     {
//         x = (int*)malloc(sizeof(int));
//         if(NULL == x) return;
//         x = assign(x,10);
//     }

//     printf("%d\n",*x);
// }