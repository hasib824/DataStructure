#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left; Node* right;
    int height ;
    Node(int n)
    {
        data = n; height = 0;
        left= NULL; right= NULL;
    }
};
Node* root = NULL;

int setHeight(Node* root)
{
    int left;int right;
    if(root->left == NULL )
        left = -1;
    else
        left = root->left->height;
    if(root->right == NULL)
        right = -1;
    else
        right = root->right->height;
       int ma =  max(left,right)+1;
       if(root->data == 14 ) printf("14 : %d\n",ma);
    return ma;
}

void balance(Node* temp)
{
    if(temp->left!=NULL)
        temp->left->height = setHeight(temp->left);
    if(temp->right!=NULL)
        temp->right->height = setHeight(temp->right);
    temp->height = setHeight(temp);

}
Node* leftRotate(Node* root)
{
    Node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    balance(temp);
    return temp;
}
Node* rightRotate(Node* root)
{
    Node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    balance(temp);
    return temp;
}



Node* insert_avl(Node* root ,int i)
{
    if(root==NULL) return new Node(i);
    if( i< root->data )
        root->left = insert_avl(root->left,i);
    else if(i> root->data)
        root->right = insert_avl(root->right,i);

    int lefth,righth;

    if(root->left !=NULL) lefth = root->left->height;
    else lefth = -1;

    if(root->right !=NULL) righth = root->right->height;
    else righth = -1;


    if(lefth - righth > 1)
    {   //printf("oita");
        int left,right;
        if(root->left->left !=NULL) left = root->left->left->height;
        else left = -1;
        if(root->left->right !=NULL) right = root->left->right->height;
        else right = -1;

        if(left < right)
        {
            root->left = leftRotate(root->left);
            root = rightRotate(root);
        }
        else root = rightRotate(root);

    }
    else if(lefth - righth < -1)
    {   //printf("Aita");
        int left,right;
        if(root->right->left !=NULL) left = root->right->left->height;
        else left = -1;
        if(root->right->right !=NULL) right = root->right->right->height;
        else right = -1;

        if(left > right)
        {
            root->right = rightRotate(root->right);
           root = leftRotate(root);
        }
        else root=leftRotate(root);

    }
    else
        root->height = setHeight(root);

    return root;
}

void printTree(Node* root)
{
    if(root == NULL ) return;
    printf("\n  root %d\n",root->data);
    if(root->left != NULL ) printf("left %d,",root->left->data);
    if(root->right != NULL ) printf("    Right %d",root->right->data);
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        root=insert_avl(root,a);
    }
    printTree(root);
    return 0;
}

/*
13
21 26 30 9 4 14 28 18 15 10 2 3 7

6
5 6 3 4 2 1

6
5 3 7 6 8 9

6
8 3 9 2 4 5

7
5 4 8 7 9 6 10

*/
