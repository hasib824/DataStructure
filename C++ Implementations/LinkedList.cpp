#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

};

Node* head = NULL;

void Add(int n)
{
   Node* temp = (Node*)malloc(sizeof(Node));
   temp->data= n ;
   temp->next = head ;
   head = temp ;
  // free(temp);

}

void removeItem(int n)
{
    Node * temp = head ;
    Node * prev; int i= 1;
    while(temp != NULL)
    {
      if(temp->data == n && i==1 )
      {
          head = head->next;
          free(temp); break;
      }
      else if(temp->data == n && i>1)
      {
          prev->next = temp->next ;
          free(temp); break;
      }

       prev = temp ; temp = temp->next ;
      i++;
    }

}

void insertInto(int p, int n)
{
   int i=1; Node* temp = head;
   p=p-1;
   while(i<p)
   {
     temp = temp->next ;
     i++;
   }
   Node* temp1 = (Node*)malloc(sizeof(Node));
   temp1->data = n; temp1->next = temp->next ;
   temp->next = temp1;


}

void printlink()
{
    Node * temp = head;
    while(temp != NULL)
    {
      printf("%d , ",temp->data);
      temp = temp->next ;
    }


}

void operation()
{   int n;
    printf("\nWhich Operation you want ? : \n1.Add \n2.insert\n3.remove\n");
      char ch ; scanf("%c",&ch);
     switch(ch)
     {
        case '1' : printf("please enter number : ");
                   scanf("%d, ",&n); Add(n); printlink(); break ;
        case '2' :printf("please enter position and number : ");
                   int p ; scanf("%d %d",&p, &n); insertInto(p,n); printlink(); break ;;
        case '3' : printf("please enter number : ");
                   scanf("%d, ",&n); removeItem(n);  printlink(); break ;

     }
}
int main()
{
     int i=0;int n;
     while(i<5)
     {
         printf("Please enter number : ");
         scanf("%d",&n);
         Add(n);
         i++;
     }

     char ch;scanf("%c",&ch);


    printf("Printing the arrays : ");
    printlink();

    while(1)
    {
        char ch;scanf("%c",&ch);
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
