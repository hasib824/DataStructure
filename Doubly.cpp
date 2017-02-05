#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node * prev ;
    int data;
    Node * next ;
};
Node * head = NULL;
Node * tail = NULL;


void addFirst(int n)
{
    Node * temp = (Node*)malloc(sizeof(Node));
    if(head== NULL && tail == NULL)
    {
        tail = temp ;
    }
    else
    {
        head->prev = temp;
    }
    temp->data = n ;
    temp->next = head;
    head=temp ;
    temp->prev = NULL ;
}

void addlast(int n)
{
    if(tail == NULL)
    {
        addFirst(n);
    }
    else
    {
       Node *temp = (Node*)malloc(sizeof(Node));
       tail->next = temp ;
       temp->data = n ;
       temp->next = NULL;
       temp->prev = tail ;
       tail = temp ;
    }

}


int getFirst()
{
    return head->data;
}

int getLast()
{
  return tail->data;
}

void removeFisrt()
{
   Node* temp = head->next ;
   free(head);
   temp->prev = NULL ;
   head = temp ;

}

void removeLast()
{
    Node* temp = tail->prev ;
    free(tail);
    temp->next = NULL ;
    tail = temp ;

}

void removeItem(int n)
{
    Node* temp = tail ;
    if(temp->data == n )
    {
        removeLast(); return ;
    }
    temp= head ;
    if(temp->data == n )
    {
        removeFisrt();
        return ;
    }

    while(temp!=NULL)
    {
        if(temp->data == n)
        {
          Node* temp1 = temp->prev;
          Node* temp2= temp->next ;
          free(temp);

          temp1->next = temp2;
          temp2->prev = temp1 ;

        }
        temp= temp->next ;
    }

}

void insertInto(int p, int n)
{
    Node * temp = head ;
    for(int i=1;i<p;i++)
    {
       temp = temp->next;
    }
    if(p==0)
    {
        addFirst(n); return;
    }
    else if(temp->next == NULL)
    {
        addlast(n); return;
    }
    Node* temp1= (Node*)malloc(sizeof(Node));
    temp1->data = n ;
    temp1->prev = temp;
    temp1->next = temp->next;
    temp->next = temp1;

}
 void printStack()
{
    Node * temp = head ;
    while(temp != NULL)
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("\n");

}

void printQueue()
{
   Node * temp = tail ;
    while(temp !=NULL)
    {
        printf("%d, ", temp->data);
        temp = temp->prev;
    }
    printf("\n");

}


void printBoth()
{
    printf("Printing the Stack : ");
    printStack();

    printf("Printing the Queue : ");
    printQueue();

}

void operation()
{   int n;
    printf("\nWhich Operation you want ? : \n1.Add First ? \n2.Add Last ?\n3.removeFirst\n4.removeLast\n6.insert \n7. remove\n");
      char ch ; scanf("%c",&ch);
     switch(ch)
     {
        case '1' : printf("please enter number : ");
                   scanf("%d",&n); addFirst(n); printBoth(); break ;
        case '2' : printf("please enter  number : ");
                   scanf("%d", &n); addlast(n); printBoth(); break ;;
        case '3' : removeFisrt(); printBoth(); break ;
        case '4' : removeLast(); printBoth(); break ;
        case '5' : removeLast(); printBoth(); break ;
        case '6' : printf("please enter position and number : ");
                   int p ; scanf("%d %d",&p, &n); insertInto(p-1,n); printBoth(); break ;
        case '7' : printf("please enter the number : ");
                   scanf("%d",&n); removeItem(n); printBoth(); break ;

     }
}




int main()
{
int i=0;int n;
     while(i<5)
     {
         printf("Please enter number : ");
         scanf("%d",&n);
         addFirst(n);
         i++;
     }


     printBoth();

    while(1)
    {
      char ch;
      scanf("%c",&ch);
      operation();
    }

}


/*
4
5
6
7
8

*/
