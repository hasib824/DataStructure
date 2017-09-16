#include<stdio.h>
using namespace std;

struct Node
{
    int a;
    Node *prev;
    Node *next;

    Node(int n)
    {   a=n;
        prev = NULL;
        next = NULL;
    }

};
Node *head = NULL;
Node *tail = NULL;

void insertNode(int a)
{
    Node *temp = new Node(a);
    if(tail==NULL) tail = temp;
    else head->prev = temp;
    temp->next = head;
    head = temp;

}

// Reversing the LinkedList

void deleteNode(int pos)
{   int i=0; Node *temp = head;
    while(i++<pos) temp = temp->next;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp; temp = NULL;

}


void printList()
{
    Node *temp = head ;
    printf("The datas are : ");
    while(temp->next!=NULL)
    {
        printf("%d, ",temp->a);
        temp = temp->next;
    }
     printf("%d \n",temp->a);
}

void printReversly()
{
    Node * temp = tail ;
    while(temp->prev !=NULL)
    {
       printf("%d, ",temp->a);
        temp = temp->prev;
    }
    printf("%d \n",temp->a);
}
int main()
{
    printf("How many datas : ? ");
    int n; scanf("%d",&n);
    for(int i=0;i<n;i++)
    {   int a; scanf("%d",&a);
        insertNode(a);
    }
    printList();

    printf("Printing reversly \n");
    printReversly();

    int d; scanf("%d",&d);
    deleteNode(d);
    printList();
    printf("Printing reversly \n");
    printReversly();
    return 0;
}

/*

8
14 54 26 35 8 47 25 36

3

*/
