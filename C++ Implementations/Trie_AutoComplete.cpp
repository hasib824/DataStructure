#include<bits/stdc++.h>

using namespace std;

struct Node
{
    Node *parent; int pIndex;
    Node *childrens[26];
    bool flag;
    bool presence; bool auton;

};
Node *root = new Node();

void insert(char *ch,int length)
{
    Node *temp = root;
    for(int i=0;i<length;i++)
    {    int index = ch[i]-'a' ;
         if(temp->childrens[index] == NULL)
            {  temp->presence = true; // The Node have at least One data. to decrease the loop while serching for AutoComplete
               Node *temp1= new Node();
               temp1->parent = temp; // assigning parent
               temp1->pIndex = index; // assigning parent Index
               temp->childrens[index] = temp1;
               temp1=NULL;
               free(temp1);
            }

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
// AutoComplete
void autocomplete(char *ch,int length)
{   char *str = new char();
    Node* temp = root; bool flag=true;
    for(int i=0;i<length;i++)
    {   int index = ch[i]-'a'; str[i] = ch[i];
        if(temp->childrens[index]==NULL) {  flag= false;  break;}
        temp=temp->childrens[index];
    }
    if(flag == true)
    {  temp->auton = true ; str[length] = '\0';
       if(temp->flag == true) printf("str %s : \n",str);
       for(int i=0;i<26;i++)
       {
         if(temp->childrens[i]!=NULL)
         {
           str[length++] = i + 'a'; str[length] = '\0';
           temp= temp->childrens[i]; i=-1; // so can start searching from the  0 index of the new Discovered Node
           if(temp->flag == true) printf("str : %s\n",str);
         }
         else if(temp->presence!=true  && temp->auton == true) break; // if No Data is avilable

         /* If the current Node is searched completely then go back to the previous parent Node to
         check if further data is available */
         if( (i==25 && temp->auton != true)  || (temp->presence!=true && temp->auton != true ))
            { i = temp->pIndex;  temp = temp->parent;  str[--length] = '\0';}
        // else if(i==25 && temp->auton == true) break; // If the First Parent Node is Serched Completely, Terminate  the serch
       }


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

  printf("AutoComplete Facility\n");

  char *c = new char(); scanf("%s",c);
  autocomplete(c,strlen(c));
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

  sha


  10
  finish
  find
  fingure
  final
  finding
  top
  today
  hasib
  tonmoy
  shakil

    10
  finishy
  find
  fingure
  final
  finding
  top
  today
  hasib
  tonmoy
  shakil

  hasib

    10
  finish
  find
  fingure
  final
  finding
  top
  today
  hasib
  tonmoy
  shakil

  to




*/

