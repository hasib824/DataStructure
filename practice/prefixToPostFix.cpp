#include<bits/stdc++.h>
using namespace std;
struct Node
{
    char ch;
    Node *next;

    Node(char cha)
    {
        ch = cha;
        next = NULL;
    }
};

Node * head= NULL;

void insert_stack(char ch)
{
    Node * temp = new Node(ch);
    temp->next = head;
    head = temp;
}

char getTop()
{
    if (head==NULL) return NULL;
    return head->ch;
}

void removeTop()
{
    Node * temp = head;
    head= head->next;

    delete temp;
}

int getPrecedence(char ch)
{
    if(ch == '+' || ch == '-') return 0;
    return 1;
}
string convertToPostFix(string exp)
{
    int length = exp.length();
    string postfix;

    for(int i=0;i<length;i++)
    {
        if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/')
        {
            char ch = getTop();
            while(ch!=NULL && getPrecedence(ch)>= getPrecedence(exp[i]))
            {
                 removeTop();
                 postfix.push_back(ch);
                 ch = getTop();
            }
           insert_stack(exp[i]);
        }
        else
            postfix.push_back(exp[i]);
    }


            while(getTop()!=NULL)
            {
                 postfix.push_back(getTop());
                 removeTop();

            }

    return postfix;
}

int main()
{
    string exp;
    cout<<"Please enter a Expression\n";
    cin>>exp;

    cout<<"PostFix : "<<convertToPostFix(exp);
    return 0;
}

/*

5+5*6/2*9+7*3

*/
