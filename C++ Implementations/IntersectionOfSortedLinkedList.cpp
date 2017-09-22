#include<bits/stdc++.h>

using namespace std;

struct Node
   {
       Node *prev;
       int data;
       Node *next;
       Node(int a,Node *head)
       {
           data = a;
           prev= NULL; next = head;
       }

   };

// Implementing Doubly Linked List
class LinkedList
{
   public:
   Node *head = NULL ;
   Node *tail = NULL ;
    void add(int a)
    {
        Node *temp = new Node(a,head);
        if(head==NULL) head=tail = temp;
        head->prev = temp;
        head = temp;
    }
    void printer()
    {
        Node * temp = head;
        printf("Printing from front : ");
        while(temp != NULL)
        {
          printf("%d, ",temp->data);
          temp = temp->next;
        }
        temp = tail;
       /* printf("\nPrinting Reversly : ");
        while(temp!=NULL)
        {
            printf("%d, ",temp->data);
            temp = temp->prev;
        }
        */
    }

};


// Sorting
void swapping(Node* first,Node* second)
{
        int data = first->data;
        first->data = second->data;
        second->data= data;
}

Node* partitioning(Node *head, Node* tail)
{
    Node* pNode = head;
    Node* traverser = head;
    int data = tail->data;
    while( traverser!= tail)
    {
        if(traverser->data<data)
        {
           swapping(pNode,traverser);
           pNode = pNode->next;
        }
        traverser = traverser->next;
    }
    swapping(pNode,tail);

    return pNode;
}
int i=0;

void Quicksort(Node *head, Node* tail)
{
    if(head!=tail)
    {
        Node *pivot = partitioning(head,tail);
        if(pivot != head)
            Quicksort(head,pivot->prev);
        if(pivot != tail)
            Quicksort(pivot->next,tail);

    }

}

int main()
{
    printf("How many datas : ");
    int n; scanf("%d",&n);
    LinkedList ll ;
    for(int i=0;i<n;i++)
    {
         int a; scanf("%d",&a);
         ll.add(a);
    }
    printf("\n");
    ll.printer();

    Quicksort(ll.head,ll.tail);

    printf("\nSorted data ") ;ll.printer();
    return 0;
}


/*

10
45
7
87
65
98
23
14
4
62
15




*/
