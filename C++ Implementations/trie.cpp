#include<bits/stdc++.h>

using namespace std;

struct Node
{
    Node *childrens[26];
    bool flag;

};
Node *root = new Node();

void insert(char *ch,int length)
{
    Node *temp = root;
    for(int i=0;i<length;i++)
    {    int index = ch[i]-'a' ;
         if(temp->childrens[index] == NULL)
            temp->childrens[index] = new Node();
         temp = temp->childrens[index];
    }
    temp->flag = true ;
}


void deletee (char *ch,int length)
{
    Node *temp = root;
    for(int i=0;i<length;i++)
    {
        int index = ch[i]-'a' ;
        if(temp->childrens[index] == NULL ) return ;
        temp = temp->childrens[index];
    }
    temp->flag = false ;
}
bool search(char *ch,int length)
{
    Node *temp=root ;
    for(int i=0;i<length;i++)
    {  int index = ch[i]-'a';
       if(temp->childrens[index] == NULL) return false;
       temp=temp->childrens[index];
    }
    if(temp->flag) return true;
    else  return false;
}




void searching()
{
  int sc; printf("How many datas ? : ");
  scanf("%d ",&sc);
  for(int t=1;t<=sc;t++)
  {
     char *ch = new char();
     scanf("%s",ch);
     if(search(ch,strlen(ch))) puts("found");
     else puts("Not found");
     //printf("Length %d :",l);
  }
}
int main()
{

  int n; printf("How many datas ? : ");
  scanf("%d ",&n);
  for(int t=1;t<=n;t++)
  {
     char *ch = new char();
     scanf("%s",ch);
     insert(ch,strlen(ch));
     //printf("Length %d :",l);
  }

  searching();
  printf("Deleting : ");
  char *ch=new char(); scanf("%s",ch);
  deletee(ch,strlen(ch));
  searching();
  return 0;
}

/* inputs

  5
  hasib
  shakib
  shakil
  marof
  jual

  5
  hasib
  saimor
  shakib
  jual
  sonet

  hasib

  5
  hasib
  saimor
  shakib
  jual
  sonet


*/

