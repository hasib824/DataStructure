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

// Reversing the LinkedList Using Recursion

// Also have a nice approach in MYCODESCHOOL code
void reverseNode(Node *prev,Node *heady) // prev is the previous node and heady is the current node
{
    if(heady->next!=NULL) reverseNode(heady,heady->next); // Getting to the last node
    else head = heady; // If it is the last node, making it as head

    heady->next= prev;
    prev->next = NULL; // So that the New Last node's next pointer will be NULL .
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


void freeNodes(Node *head)  // Freeing the Dynamically allocated memory
{
   if(head->next!=NULL) freeNodes(head->next);
   delete head; head=NULL;
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
    reverseNode(head,head->next);  printList();

    freeNodes(head);
    return 0;
}


/*

8
14 54 26 35 8 47 25 36

*/

