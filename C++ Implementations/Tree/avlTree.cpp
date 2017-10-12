#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    int height ;
    Node(int n)
    {
        data = n;
        height = 0;
        left= NULL;
        right= NULL;
    }
};
Node* root = NULL;

int getHeight(Node* temp)
{
    if(temp==NULL) return -1;
    return temp->height;
}

int setHeight(Node* root)
{
    return  max(getHeight(root->left),getHeight(root->right))+1;;
}
void adjustHeight(Node* temp)
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
    adjustHeight(temp);
    return temp;
}
Node* rightRotate(Node* root)
{
    Node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    adjustHeight(temp);
    return temp;
}

Node* balancer(Node* root)
{
    if(root == NULL ) return NULL;
    int lefth = getHeight(root->left);
    int righth= getHeight(root->right);

    if(lefth - righth > 1)
    {
        if(getHeight(root->left->left) < getHeight(root->left->right))
            root->left = leftRotate(root->left);
        root = rightRotate(root);
    }
    else if(lefth - righth < -1)
    {
        if(getHeight(root->right->left) > getHeight(root->right->right))
            root->right = rightRotate(root->right);
        root=leftRotate(root);
    }
    else
        root->height = setHeight(root);
    return root;
}

Node* insert_avl(Node* root,int i)
{
    if(root==NULL) return new Node(i);
    if( i< root->data )
        root->left = insert_avl(root->left,i);
    else if(i> root->data)
        root->right = insert_avl(root->right,i);

    return balancer(root);
}

int getMax(Node* root)
{
    if(root->right == NULL)
        return root->data;
    return getMax(root->right);
}

Node* deleteNode(Node* root,int data)
{
    if(root == NULL) return NULL;
    if(data < root->data)
        root->left = deleteNode(root->left,data);
    else if(data > root->data)
        root->right = deleteNode(root->right,data);
    else // Enters if the data is found
    {
        //Node with No child
        if(root->left == NULL && root->right == NULL)
        {
            delete root; root = NULL;
        }

        // Node with single child
        else if(root->left != NULL && root->right==NULL) // Node with left child
        {
            Node* temp = root->left;
            delete root; root = root->left;
        }
       else if(root->right != NULL && root->left==NULL) // Node with Right Child
        {
            Node* temp = root->right;
            delete root; root = root->right;
        }

        // Node with Two Child
       else if(root->left != NULL && root->right != NULL)
        {
            int data = getMax(root->left);
            root->data = data;
            root->left = deleteNode(root->left,data);
        }
    }

    return balancer(root); // Returning the Root After Balancing
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
    for(int i=0; i<n; i++)
    {
        int a;
        scanf("%d",&a);
        root=insert_avl(root,a);
    }
    root = deleteNode(root,21);
    root =deleteNode(root,18);
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
