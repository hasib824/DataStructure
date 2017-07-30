#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node* child[60];
    bool border;
    bool presence;

    Node()
    {
        for(int i=0; i<60; i++) child[i] = NULL;
        border = 0;
        presence = 0 ; // border 0 means in this node no word can make
        // presence 0 means there is no child in this 27 child array
    }
};
Node* head=NULL;

void buildTrie(char *str,int length)
{
    Node* temp = head;
    for(int i=0; i<length; i++)
    {
        int index = str[i]-'A';
        if(temp->child[index]==NULL)
        {
            temp->child[index] = new Node;
            temp->presence = 1; // there is at least one child in the parent
        }
        temp = temp->child[index];
    }
    temp->border = 1; // end of the word
}


char strings[55];
int l=0;
void printTrie(Node* head)
{
    Node* temp = head;
    if(temp->border == 1) printf("%s\n",strings);
    if(temp->presence==1)  // If other words have from this node
    {
        for(int i=0; i<57; i++)
        {
            if(temp->child[i]!=NULL)
            {
                strings[l++] = 'A'+i;
                strings[l] = '\0';
                printTrie(temp->child[i]);
            }
        }
    }
    strings[--l]='\0';
    return;
}

int main()
{
    int tc;
    printf("How many test case : ");
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++)
    {
        head = new Node();
        int nmbrOfString;printf("How many strings  : ");
        scanf("%d",&nmbrOfString);
        for(int i=0; i<nmbrOfString; i++)
        {
            char str[55];
            scanf("%s",str);
            buildTrie(str,strlen(str));
        }
        printf("Printing the Trie : \n");
        printTrie(head);

    }
    return 0;
}

/*
1
5
hasib
shakib
shakil
Allah
Rasul
*/
