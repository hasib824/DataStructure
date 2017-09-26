/*

Checking if the tree is Binary tree or not
Used Iterative approch and normal traversal
Reference : https://www.programcreek.com/2012/12/leetcode-validate-binary-search-tree-java/

*/

#include<bits/stdc++.h>
#include <stack>

using namespace std;

struct Node
{
    Node* left;
    int data;
    Node* right;
    Node(int a)
    {
        left = NULL;
        data = a;
        right = NULL;
    }
};
Node * root = NULL;

Node* addNode(Node *root,int data)
{
    if(root==NULL) return new Node(data);
    if(data< root->data)
        root->left = addNode(root->left,data);
    else
        root->right = addNode(root->right,data);
    return root;
}


// Iterating over All Nodes And checking The BSt IS Valid
bool checkBst(Node* root)
{
    if(root == NULL) return true;
   stack<Node *> st;
   st.push(root);
   while(!st.empty())
   {
         Node* temp = st.top(); st.pop();
        if(temp->left)
        {
            if(temp->data< temp->left->data) return false;
            st.push(temp->left);
        }
        if(temp->right)
        {
            if(temp->data > temp->right->data) return false;
            st.push(temp->right);
        }

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
    if(checkBst(root)) printf("The Tree is BST\n");
    else printf("The tree is not BST\n");

    printf("Inserting 15 at left of 14\n");
    root->left->left->data = 15 ;

    if(checkBst(root)) printf("Now The Tree is BST\n");
    else printf("Now The tree is not BST\n");
    return 0;
}

/*
10
14
25
3
69
8
74
52
32
19
23

12
14
25
3
19
69
8
23
52
74
32
2
1



*/
