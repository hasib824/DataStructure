// Creates a New LinkedList from the common values of two Sorted LinkedList

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

// Getting the intersection of two List
LinkedList intersection(LinkedList llOne,LinkedList llTwo)
{
    Node *llOneHead = llOne.head;
    Node *llTwoHead = llTwo.head;
    LinkedList commonList ;
    while(llOneHead != NULL && llTwoHead != NULL)
    {
        if(llOneHead->data == llTwoHead->data)
        {
            commonList.add(llOneHead->data);
            llOneHead = llOneHead->next;
            llTwoHead = llTwoHead->next;
        }
        else if(llOneHead->data < llTwoHead->data) llOneHead = llOneHead->next;
        else llTwoHead = llTwoHead->next;

    }

    return commonList;
}


int main()
{
    int j=0;
    printf("How many LinkedList ? ");
    int numberOfLinkedList; scanf("%d",&numberOfLinkedList);
    LinkedList ll[numberOfLinkedList];
    while(j<numberOfLinkedList)
    {
        printf("\nHow many datas for list : ");
        int n; scanf("%d",&n);
        printf("Enter datas for list : ");
        for(int i=0;i<n;i++)
         {
             int a; scanf("%d",&a);
             ll[j].add(a);
         }
        printf("\n");
        ll[j].printer();
        Quicksort(ll[j].head,ll[j].tail);
        printf("\nSorted data ") ;ll[j].printer();
        j++;

    }

    // Check for Intersection of the linkedLists

        LinkedList commonList = intersection(ll[0],ll[1]);
        printf("\n\nNew List is : ");
        commonList.printer();
        printf("\n");

    return 0;
}


/*
2

10
45
7
54
65
98
23
63
74
62
100

13
4
71
45
23
89
12
98
65
48
15
74
91
46




*/
