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

void printlink()
{
    Node * temp = head;
    while(temp != NULL)
    {
      printf("%d , ",temp->data);
      temp = temp->next ;
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

    printf("\nWhich Operation you want ? : \n1.Add \n2.insert\n3.remove\n");
      scanf("%c",&ch);
     switch(ch)
     {
        case '1' : printf("please enter number : ");
                   scanf("%d, ",&n); Add(n); printlink(); break ;
        case '2' :break;
        case '3' : printf("please enter number : ");
                   scanf("%d, ",&n); removeItem(n);  printlink(); break ;

     }


}

/*
4
5
6
7
8

*/
