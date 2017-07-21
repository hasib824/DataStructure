#include<bits/stdc++.h>
using namespace std;

int data[110000];
struct Node
{
    Node* prev;
    int a;
    Node* next;
    Node()
    {
        prev = NULL;
        a=0;
        next = NULL ;
    }
};

Node* head=NULL;
Node* tail=NULL;

void push(int a)
{
   if(head==NULL)
   {
       head = new Node(); head->a = a;
       tail = head; return;
   }
   Node* temp = new Node;
   temp->prev = tail ;
   tail->next = temp;
   tail = tail->next;
   tail->a = a ;
}
bool dq_empty()
{
    return head==NULL ;
}

int dq_front()
{
    return head->a;
}

int dq_end()
{
    return tail->a;
}

void dq_pop_front()
{
    head = head->next ;
    delete head->prev; head->prev = NULL ;
}

void dq_pop_end()
{
   tail = tail->prev;
   delete tail->next; tail->next= NULL;

}


void dq_free(Node* dqHead)
{
  if(dqHead->next== NULL) { delete dqHead; return;}
  dq_free(dqHead->next);
  delete dqHead; dqHead = NULL;
}

int main()
{
  int tc;
  scanf("%d",&tc);
  for(int t=1;t<=tc;t++)
  {
     int totalNmbr;
     scanf("%d",&totalNmbr);
     cout<<"if empty : "<<dq_empty()<<"\n";
     for(int i=0;i<totalNmbr;i++)
     {
         scanf("%d",&data[i]);
         push(data[i]);
     }
     cout<<"if empty : "<<dq_empty()<<"\n";
     printf("front : %d back %d\n",dq_front(),dq_end());
     dq_pop_front(); dq_pop_end();
     printf("front : %d back %d\n",dq_front(),dq_end());
     dq_free(head); head = NULL; tail = NULL;
     cout<<"Freeing DQ \n"<<"if empty : "<<dq_empty()<<"\n";

  }
  return 0;
}



/*
1
7

3
4
5
6
7
12
4

*/
