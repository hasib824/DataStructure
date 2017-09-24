#include<bits/stdc++.h>

using namespace std;

struct Node
{
    Node* left; int data; Node* right;
    Node(int a)
    {
        left=NULL;  data=a;  right=NULL;
    }
};

Node* root=NULL;
int tree[1000] = { 0 }; // Initializes all values with 0
int n;


// Recursive Insertion
Node* insert_RecursiveLL(Node* head,int a)
{
    if(head==NULL)
        return new Node(a);  // If the tree is empty, return a new node
    if(head->data > a)
        head->left = insert_RecursiveLL(head->left,a); // Going deep of the left
    else
        head->right = insert_RecursiveLL(head->right,a); // Going deep of the Right
    return head;
}



// Iterative Insertion
void insert_IterativeLL(int a)
{
    Node *temp = root;
    Node *parent = temp;
    if(root == NULL )
    {
        root = new Node(a);
        return;
    }
    while(temp!=NULL)
    {
        parent = temp;
        if( a< temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if(parent->data > a )
        parent->left = new Node(a);
    else
        parent->right = new Node(a);

}

// Based on Preorder traversel
void printTreeLL(Node* head)
{
    if(head == NULL)  return;
    printf("head %d \n",head->data);

    if(head->left!= NULL)
      //  printf("left %d , ",head->left->data);

    if(head->right!= NULL)
      //  printf("right %d ",head->right->data);

    printf("\n");
    printTreeLL(head->left);
    printTreeLL(head->right);
}


// Array Based Works
// Iterative array Insertion
void insert_iterativeArray(int a)
{
    int i=0;
    while(tree[i]!=0)
    {

      if(a<tree[i]) i=(i*2)+1;
      else i= (i*2)+2;
    }
    tree[i] = a;
}

// Recursive array Insertion
void insert_recursiveArray(int i,int a)
{
    if(tree[i]==0)
    {
        tree[i] = a; return ;
    }
    if(a<tree[i]) insert_recursiveArray(i*2+1,a);
    else insert_recursiveArray(i*2+2,a);
}

// Printing the tree that Implemented on Array
void prinTreeArray()
{
    for(int i=0;i<n*10;i++)
    {
       if(tree[i]!=0)
       {
          printf("head %d\n",tree[i]);
          if(tree[i*2+1] !=0) printf("left %d, ",tree[i*2+1]);
          if(tree[i*2+2] !=0) printf(" right %d",tree[i*2+2]);
           printf("\n");
       }

    }
}

// Finding Height

// Recursive Find height on LinkedList based BST

int findHeight_recur_ll(Node *root)
{
    if(root == NULL) return -1;
    int left = findHeight_recur_ll(root->left);
    int right = findHeight_recur_ll(root->right);
    return max(left,right)+1;
}


int main()
{

    printf("How many Nodes : ? ");
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        int a;
        scanf("%d",&a);
        // LinkedList Insertion
        //insert_IterativeLL(a);
        root = insert_RecursiveLL(root,a);

        // Array Insertion
        //insert_iterativeArray(a);
        //insert_recursiveArray(0,a);
    }

    printTreeLL(root);
   // prinTreeArray();

    printf("Height of the tree is : %d\n",findHeight_recur_ll(root));

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

10
14
25
33
69
89
98
108
321
325



*/
