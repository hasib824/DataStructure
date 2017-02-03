#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

};

Node* head = NULL;

void insertlink(int n)
{
   Node* temp = (Node*)malloc(sizeof(Node));
   temp->data= n ;
   temp->next = head ;
   head = temp ;
  // free(temp);


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
     int i=0;
     while(i<5)
     {
         int n;
         printf("Please enter number : ");
         scanf("%d",&n);
         insertlink(n);



         i++;
     }
      printf("Printing the arrays : ");
         printlink();

}
