#include<bits/stdc++.h>
using namespace std;

struct Node
{
    char ch;
    Node * next;
    Node(char cha)
    {
        ch = cha;
        next = NULL;
    }
};
Node * head = NULL;

void insert_Stack(char ch)
{
    Node * temp = new Node(ch);
    temp->next = head;
    head = temp;

}

char getTop()
{
   if(head == NULL)
    return NULL;
   char ch = head->ch;
   Node * temp = head;
   head= head->next;
   delete temp;
   return ch;
}

bool arePair(char opening, char closing)
{
    if(opening=='[' && closing == ']') return true;
    if(opening=='{' && closing == '}') return true;
    if(opening=='(' && closing == ')') return true;

    return false;
}


bool areParenthesisBalanced(string exp)
{
    int length =  exp.length();
    for(int i=0;i<length;i++)
    {
        if(exp[i]=='[' || exp[i]=='{' || exp[i]=='(' )
        {
            insert_Stack(exp[i]);

        }
        else if(exp[i]==']' || exp[i]=='}' || exp[i]==')')
        {
            char opening = getTop();
            if(opening==NULL)
                return false;
            if(!arePair(opening,exp[i])) return false;
        }
    }
    if(getTop()!=NULL) return false;

    return true;
}

int main()
{

    string expression;
    cout<<"Please enter a expression : \n";
    cin>>expression;

    if(areParenthesisBalanced(expression))
        cout<<"Balanced";
    else
        cout<<"Not Balanced";
    return 0;
}


/*

[(a+b)+{d}]

[(a+b)+{d}*(a+b)+{d}]

*/
