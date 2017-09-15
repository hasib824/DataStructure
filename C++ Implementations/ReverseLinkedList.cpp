#include<stdio.h>

using namespace std;

struct Node
{
    int a;
    Node *next;
    Node()
    {
        next = NULL;
    }

};

Node * head = NULL ; // Head will contain the First inserted data , Queue implementation
Node * next= NULL;
void insertNode(int a)
{
    Node *temp = new Node();
    if(head == NULL) head =next= temp;
    temp->a = a;
    next->next = temp;
    next=temp;
}

void reverseNode(Node *heady)
{
   Node *prev,*next;
   prev = heady; heady = heady->next;
   prev->next = NULL;
   while(heady->next!=NULL)
   {
     next = heady->next;
     heady->next = prev;
     prev = heady;
     heady = next;
   }
   heady->next = prev ;
   head = heady;
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
int main()
{
    printf("How many datas : ? ");
    int n; scanf("%d",&n);
    for(int i=0;i<n;i++)
    {   int a; scanf("%d",&a);
        insertNode(a);
    }
    printList();

    printf("Reversed linked list \n");
    reverseNode(head);  printList();
    return 0;
}


/*

8
14 54 26 35 8 47 25 36

*/
