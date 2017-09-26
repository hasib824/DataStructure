#include<bits/stdc++.h>

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

// Max Min

int BST_max(Node* root)
{
     if(root==NULL) return 0;
     while(root->right != NULL)
     {
         root = root->right;
     }
     return root->data;
}

int BST_min(Node* root)
{
     if(root==NULL) return 0;
     while(root->left != NULL)
     {
         root = root->left;
     }
     return root->data;
}


// Traversal
void preOrder_recursive(Node* root)
{
    if(root == NULL) return;
    printf("%d, ",root->data);
    preOrder_recursive(root->left);
    preOrder_recursive(root->right);
}

bool flag = true;
void checkBst(Node* root)
{
    if(root == NULL) return ;
    if((root->left!=NULL && root->left->data > root->data )|| ( root->right != NULL && root->right->data < root->data))
        flag = false ;
    checkBst(root->left);
    checkBst(root->right);
}

void inOrder_recursive(Node* root)
{
    if(root == NULL) return;
    inOrder_recursive(root->left);
    printf("%d, ",root->data);
    inOrder_recursive(root->right);
}


void postOrder_recursive(Node* root)
{
    if(root == NULL) return;
    postOrder_recursive(root->left);
    postOrder_recursive(root->right);
    printf("%d, ",root->data);
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
    printf("Preorder Traversal : ");
    preOrder_recursive(root);
    printf("\n\nInorder Traversal : ");
    inOrder_recursive(root);
    printf("\n\nPostOrder Traversal : ");
    postOrder_recursive(root);
    printf("\n");

    printf("Max element is : %d\n",BST_max(root));
    printf("Min element is : %d\n",BST_min(root));
    checkBst(root);
    if(flag) printf("The Tree is BST\n");
    else printf("The tree is not BST\n");

    printf("Inserting 15 at left of 14\n");
    root->left->left->data = 15 ;

    checkBst(root);
    if(flag) printf("Now The Tree is BST\n");
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
