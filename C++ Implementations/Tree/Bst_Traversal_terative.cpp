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


// Implementating Stack
struct stackNode
{
    Node* treeNode;
    stackNode* next;
    stackNode(Node* a)
    {
        treeNode = a;
        next = NULL;
    }
};
stackNode* stackHead = NULL;

void stackPush(Node* treeNode)
{
  stackNode* temp = new stackNode(treeNode);
  temp->next = stackHead;
  stackHead = temp;
}

Node* stackTop()
{
    return stackHead->treeNode;
}

Node* stackPop()
{
   stackNode * temp = stackHead;
   stackHead = stackHead->next;
   Node* treeNode = temp->treeNode;
   delete temp;
   return treeNode;
}

bool isEmpty()
{
  return stackHead == NULL;
}  // End Of Stack Operations


// Iterative Traversal

void preorderTraversal(Node* treeRoot)
{
    stackPush(treeRoot);
    Node * t = stackTop();
   // stack<Node*> myStack ;  // Library stack
    printf("\nPreorder Traversal : ");
    while(!isEmpty())
    {
        treeRoot = stackPop();
        printf("%d , ",treeRoot->data);
        if( treeRoot->right != NULL )
            stackPush(treeRoot->right);
        if( treeRoot->left != NULL )
            stackPush(treeRoot->left);
    }
    printf("\n");
}


void inOrderTraversal(Node * treeRoot)
{
    printf("\nInorder Traversal : ");
    while(1)
    {
           if(treeRoot != NULL)
           {
                stackPush(treeRoot);
                treeRoot = treeRoot->left;
           }
           else
           {
               if(isEmpty()) return;
               treeRoot = stackPop();
               printf("%d ,",treeRoot->data);
               treeRoot = treeRoot->right;
           }
    }
}


void postOrderTraversal(Node* treeNode)
{
        printf("\nPostOrder Traversal : ");
        stackPush(treeNode);
        treeNode= treeNode->left;
        while(!isEmpty())
        {
            if(treeNode != NULL)
            {
                stackPush(treeNode);
                treeNode = treeNode->left;
            }
            else
            {
                Node* temp = stackTop()->right;
                if(temp==NULL)
                {
                    temp = stackPop();
                    printf("%d, ",temp->data);
                    while(!isEmpty() && temp == stackTop()->right)
                    {
                        temp = stackPop();
                        printf("%d, ",temp->data);
                    }
                }
                else
                    treeNode = temp;

            }
        }
}

// Adding the BST Nodes
Node* addNode(Node *head,int data)
{
    if(head == NULL) return new Node(data);
    if(data<head->data)
        head->left = addNode(head->left,data);
    else
        head->right = addNode(head->right,data);
    return head;
}


int main()
{

    printf("How many Nodes : ? ");
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int a;
        scanf("%d",&a);
        root = addNode(root,a);
    }
    preorderTraversal(root);
    inOrderTraversal(root);
    printf("\n");
    postOrderTraversal(root);
    printf("\n");
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
