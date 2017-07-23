/*
Lazy Propagation segment Tree Range Sum
link of the practices on Khata are given below
https://drive.google.com/drive/folders/0Bzr6_EXSM9kIY3VsNTNBcmVZdVE?usp=sharing
*/

#include<bits/stdc++.h>
using namespace std;
int *datas = new int[1000];
int *tree = new int[3000]; // 3 times more memory needed for the segment tree
int *lazy = new int[3000];


int initialize(int n) // Initializnge the arrays so that No garbage remain
{
    for(int i=0;i<=n;i++) { tree[i]=0; lazy[i]=0; }
}

void buildTree(int low , int high, int pos)
{
     if(low==high) { tree[pos] = datas[low]; return; } // if it's a leaf node then insert the data
     int mid=(high-low)/2+low;
     buildTree(low,mid,pos*2+1); // recursion for the left child
     buildTree(mid+1,high,pos*2+2); // recursion for the right child
     tree[pos] = tree[pos*2+1]+ tree[pos*2+2]; // addition of the childs are adding to parent
}

void update(int low,int high, int pos,int idx,int value)
{
    if(low>idx || high<idx) return; // No overlap
    if(low==high && high==idx) { tree[pos] = value; return; } // if the desired node found
    int mid= (high-low)/2+low;
    update(low,mid,pos*2+1,idx,value);
    update(mid+1,high,pos*2+2,idx,value);
    tree[pos]= tree[pos*2+1]+tree[pos*2+2];
}

void lazyHelper(int low,int high,int pos) // Helper method to maintain the Lazy and main tree
{    //printf("Called \n");
    tree[pos]+=(high-low+1)*lazy[pos];
    if(low!=high)  // If not a Leaf Node , making childs not updted yet
    {
        lazy[pos*2+1]+=lazy[pos];
        lazy[pos*2+2]+=lazy[pos];
    }
    lazy[pos]=0;
}

void lazyUpdate(int low,int high,int pos,int updateLowIdx,int updateHighIdx,int increaseValue )
{
        if(lazy[pos]!=0) lazyHelper(low,high,pos); // If the index is not up to date, then make it update

        if(high<updateLowIdx || low>updateHighIdx) return ; // No Overlap
        if(updateLowIdx<=low && high<=updateHighIdx) // Total overlap
        {
            tree[pos]+=(high-low+1)*increaseValue; //
            printf("Low %d, high %d, pos  %d\n",low,high,pos);
            if(low!=high)  // If not a Leaf Node , making childs not updated yet
            {
                lazy[pos*2+1]+=increaseValue;
                lazy[pos*2+2]+=increaseValue;
            }
            return ;
        }
        int mid=(low+high)/2;
        lazyUpdate(low,mid,pos*2+1,updateLowIdx,updateHighIdx,increaseValue );
        lazyUpdate(mid+1,high,pos*2+2,updateLowIdx,updateHighIdx,increaseValue );
        tree[pos]= tree[pos*2+1] + tree[pos*2+2];

}

int queryLazy(int low,int high,int pos,int queryLowIdx,int queryHighIdx)
{
    if(lazy[pos]!=0) // If the index is not up to date, then make it update
        lazyHelper(low,high,pos);

    if(high<queryLowIdx || low>queryHighIdx) return 0;  // No overlap
    if(queryLowIdx<=low && high<=queryHighIdx)
    {
         printf("Low %d, high %d, pos  %d value %d\n",low,high,pos,tree[pos]);
         return tree[pos];  // Total Overlap
    }
    int mid= (high-low)/2+low;
    int left = queryLazy(low,mid,pos*2+1,queryLowIdx,queryHighIdx);
    int right = queryLazy(mid+1,high,pos*2+2,queryLowIdx,queryHighIdx);
    return left+right;
}

void printTree(int l)
{
   for(int i=0;i<l;i++) printf("%d : %d\n",i,tree[i]);
}

int main()
{
    printf("How many datas ? : ");
    int n; scanf("%d",&n); initialize(n);
    for(int i=0;i<n;i++) scanf("%d",(datas+i));
    buildTree(0,n-1,0); printTree(n*3);
    while(1)
    {
        printf("\n\nOperations   :\n1.Single Update\n2.Query Lazy\n3.Range update\n");
        int op;
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            printf("Please enter value and position to single update: \n");
            int value;int idx ;
            scanf("%d %d",&value,&idx);
            update(0,n-1,0,idx,value);printTree(n*3);
            break;
        case 2:
            printf("Please enter range of query : \n");
            int queryLowIdx;int queryHighIdx ;
            scanf("%d %d",&queryLowIdx,&queryHighIdx);
            printf("Query Result : %d\n",queryLazy(0,n-1,0,queryLowIdx,queryHighIdx));
            break;
        case 3:
            printf("Please enter value and range to update: \n");
            int increaseValue; int updateLowIdx;int updateHighIdx ;
            scanf("%d %d %d",&increaseValue,&updateLowIdx,&updateHighIdx);
            lazyUpdate(0,n-1,0,updateLowIdx,updateHighIdx,increaseValue);
            printTree(n*3);
            break;
        default :
            printf("Please select right operation\n");

        }
    }

    return 0;
}


/*
Test Cases Are from the practices exercises , their link is below
https://drive.google.com/drive/folders/0Bzr6_EXSM9kIY3VsNTNBcmVZdVE?usp=sharing

13
2 3 5 8 11 7 6 13 4 9 10 1 14

2
2 6

1
7 3

3
5
2 6

2nd case

19
9 7 8 2 3 15 12 19 17 23 10 11 21 6 7 15 24 22 1

2
10 14


3
5
2 18

3
2
10 14


2
10 14

2
17 17


2
2 15

1
27 11

3
5
10 18

2
11 13



3rd case

10
0 0 0 0 0 0 0 0 0 0

3
10
0 9

2
5 7

*/
