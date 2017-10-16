#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int a)
    {
        data = a;
        left = NULL;
        right = NULL;
    }
};

Node* root = NULL;

Node* insert_bst(Node* root,int data)
{
    if(root == NULL )
        return new Node(data);
    if(data < root->data)
        root->left = insert_bst(root->left,data);
    else if(data > root->data)
        root->right = insert_bst(root->right,data);
    return root;
}

int lca_bst(Node* root,int leftdata,int rightdata)
{
    if(root == NULL) return -1;
    if(leftdata < root->data && rightdata < root->data) // If both n1 and n2 are smaller than root, then LCA lies in left
       return lca_bst(root->left,leftdata,rightdata);

    else if(leftdata > root->data && rightdata > root->data)  // If both n1 and n2 are greater than root, then LCA lies in right
        return lca_bst(root->right,leftdata,rightdata);
    return root->data;
}

void print_tree(Node* root)
{
    if(root == NULL) return;
    printf(" %d, ", root->data);
    print_tree(root->left);
    print_tree(root->right);
}

int main()
{
    printf("How many datas ? : ");
    int n; scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a;  scanf("%d",&a);
        root = insert_bst(root,a);
    }
    //print_tree(root);
    int leftdata; int rightdata;
    while(1)
    {
        printf("Please enter left and right childs : ");
        scanf("%d %d",&leftdata,&rightdata);
        int ancestor = lca_bst(root,leftdata,rightdata);
        printf("The Ancestor is : %d\n",ancestor);

    }

    return 0;
}

/*
35
100 50 120 25 55 110 150 15 28 52 60 105 115 145 160 5 20 27 35 51 53 58 62 103 107 114 117 142 148 159 166 26 54 113 118


*/
