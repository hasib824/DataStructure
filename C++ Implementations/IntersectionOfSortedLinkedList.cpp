#include<bits/stdc++.h>

using namespace std;



class LinkedList
{

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

   Node *head = NULL ;
   Node *tail = NULL ;

   public:
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
        printf("\nPrinting Reversly : ");
        while(temp!=NULL)
        {
            printf("%d, ",temp->data);
            temp = temp->prev;
        }
    }

};


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

    ll.printer();

    return 0;
}


/*

10
8
7
5
6
4
23
7
8
9
46



*/
