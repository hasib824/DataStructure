#include<bits/stdc++.h>
using namespace std;
int A[100];

// Building the tree while Scanning the Tree;
void buildTree(int n)
{
   for(int i=(n/2);i<n;i++)
   {
       int a,b;
       scanf("%d%d",&a,&b);
       A[i*2] = a; // left child insertion
       A[i*2+1] = b; // Right child insertion
       A[i]=a+b;    //  Adding the addition to root;
   }
   for(int i=n/2-1;i>0;i--)
   {
       A[i] = A[i*2] + A[i*2+1];
   }
}


<<<<<<< HEAD
void printTree()
{
    //for(int i=nmbrOfData-1;i>0;i--)
       // printf("Parent : %d \n left: %d ,  Right : %d\n",i,tree[i*2],tree[i*2+1]);
       for(int i=0;i<2*nmbrOfData;i++) printf("%d, ",tree[i]);
}

void build()
{
    for(int i=nmbrOfData-1;i>0;i--) tree[i]=tree[i*2]+tree[i*2+1];
    printTree();

=======
int RangeSum(int left,int right)
{   printf("Left %d , right %d\n",left,right);
    int sum=0;
    while(left<=right)
    {
       if(left%2==1)
       {
         printf("Left %d , value %d \n",left,A[left]);
         sum+= A[left++];
       }
       if(right%2==0)
       {
           printf("right %d , value %d\n",right,A[right]);
          sum+= A[right--];
       }

       left/=2; right/=2;
    }

    return sum;
>>>>>>> origin/master
}

void update(int pos,int data)
{
<<<<<<< HEAD
   tree[position] = number;
   for(int i=position;i>0;i=i/2) tree[i/2] = tree[i]+tree[i^1] ; // if I is odd then i^1 gets even and If I is Even then i^1 gets odd
=======
   A[pos] = data;
   while(pos>1)
   {
        pos=pos/2;
        A[pos] = A[pos*2]+A[pos*2+1];
   }

>>>>>>> origin/master
}


void printTree(int n)
{
    for(int i=0;i<n*2;i++) printf("%d , ",A[i]);
}
int main()
{
    printf("How many Numbers : \n");
    int n; scanf("%d",&n);
    buildTree(n);  printTree(n);
    printf("\nPlease enter range query : from 0 to %d\n",n-1);
    int left , right;
    scanf("%d%d",&left,&right);
    printf("\nSum is : %d\n",RangeSum(n+left,n+right));
    printf("Value and position to update : \n");
    int pos,data; scanf("%d%d",&pos,&data);
    update(pos+n,data);
    printTree(n);
    return 0;
}

<<<<<<< HEAD
/* 93, 42, 51, 18, 24, 26, 25, 5, 13, 18, 6, 17, 9, 11, 14, 2, 3, 5, 8, 11, 7, 0, 0, 13, 4, 0,
   93, 68, 25, 32, 36, 17, 8, 19, 13, 17, 19, 15, 2, 3, 5, 8, 11, 7, 6, 13, 4, 9, 10, 1, 14,
   2,3,5,8,11,7,6,13,4,9,10,1,14
13sssssssswssssss
=======

/*
12
>>>>>>> origin/master
2
4
5
7
9
8
13
11
6
15
3
1
2
8

7
23

*/

// 9,7,8, 2, 3, 15, 12, 19, 17, 23, 10, 11, 21, 6, 7, 15, 24, 22, 1
//  for(int i=0;i<n;i++) scanf("%d",in[i]);

