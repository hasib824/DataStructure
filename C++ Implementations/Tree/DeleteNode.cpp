#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* left;Node* right;
    Node(int a)
    {
       left = NULL; right = NULL;
       data = a;
    }
};

Node* root= NULL;

Node* addNode(Node* root,int data)
{
    if(root == NULL ) return new Node(data);
    if(data < root->data)
        root->left = addNode(root->left,data);
    else
        root->right = addNode(root->right,data);
    return root;
}

void preorder(Node * root)
{
    if(root == NULL) return;
    printf("\n\n      Root %d , ",root->data);
    if(root->left != NULL) printf("\nLeft %d , ",root->left->data);
    if(root->right != NULL) printf(" right %d , ",root->right->data);
    preorder(root->left);
    preorder(root->right);
}

int findMin(Node* root)
{
   if(root->left == NULL ) return root->data;
   return findMin(root->left);
}

Node* deleteNode(Node* root,int data)
{
  if(root == NULL) return NULL;
  if(data< root->data)
    root->left = deleteNode(root->left,data);
  else if(data > root->data)
    root->right = deleteNode(root->right,data);
  else  // Data found
  {
     if(root->left == NULL && root->right == NULL) // If no child
     {
          delete root;
          return NULL;
     }
     // If Only One Child
     if(root->left == NULL && root->right != NULL)
     {
         Node * temp = root;
         delete temp;
         root = root->right;
     }
     if(root->right == NULL && root->left != NULL)
     {
          Node * temp = root;
         delete temp;
         root = root->left;
     }

     // if have both childs
     if(root->right != NULL && root->left != NULL)
     {
         int data = findMin(root->right); // Finding Min of0 the Right Child, so that BSt property remains
         root->data = data;
         root->right = deleteNode(root->right,data);
     }
     return root;
  }
}

int main()
{

  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
      int data;
      scanf("%d",&data);
      root = addNode(root,data);
  }
  preorder(root);
  int data;
  while(1)
  {
    printf("Enter data to delete : ");
    scanf("%d",&data);
    deleteNode(root,data);
    preorder(root);
  }

  return 0;
}

/*

19
35 30 40 25 33 38 42 23 27 32 34 36 39 41 43 22 26 31 35
*/
