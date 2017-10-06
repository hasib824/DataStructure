#include<bits/stdc++.h>

using namespace std;

struct Node
{
    Node* left;
    Node* right;
    int data;
    Node(int a)
    {
        data = a;
        left= NULL;
        right= NULL;
    }
};
Node* root = NULL;
Node* addNode(Node* root,int data)
{
    if(root == NULL)
        return new Node(data);
    if(root->data > data)
        root->left = addNode(root->left,data);
    else
        root->right = addNode(root->right,data);
    return root;
}

bool ancestor(Node* root,int data)
{
    if(root == NULL) return false;
    if(root->data == data)
        return true;
    if(root->data > data)
    {
        if(ancestor(root->left,data))
        {
          printf("%d, ",root->data);
          return true;
        }
    }
    else
        if(ancestor(root->right,data))
        {
          printf("%d, ",root->data);
          return true;
        }
}
int main()
{

    printf("How many Nodes : ? ");
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int data;
        scanf("%d",&data);
        root = addNode(root,data);
    }

    printf("Please enter data to find : ");
    int data; scanf("%d",&data);
    ancestor(root,data);
    return 0;
}

/*

10
10 7 12 3 8 11 13 2 4 9

*/
