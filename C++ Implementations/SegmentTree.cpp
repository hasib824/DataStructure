#include<stdio.h>
using namespace std;

const int N = 1e5;
int tree[2*N];

int  nmbrOfData; // user decided number


void printTree()
{
    for(int i=nmbrOfData-1;i>0;i--)
        printf("Parent : %d \n left: %d ,  Right : %d\n",i,tree[i*2],tree[i*2+1]);
}

void build()
{
    for(int i=nmbrOfData-1;i>0;i--) tree[i]=tree[i*2]+tree[i*2+1];
    printTree();
}

void update(int number,int position)
{
   tree[position] = number;
   for(int i=position;i>0;i=i/2) tree[i/2] = tree[i]+tree[i^1] ; // if I is odd then i^1 gets even and If I is Odd then i^1 gets odd
}

void RmQ(int left,int right)
{
  int res=0; left+=nmbrOfData; right+=nmbrOfData;
  while(left<=right)
  {
      if(left&1) res += tree[left++];
      if(!(right&1)) res+= tree[right--];
      left/= 2; right/=2;
  }
  printf("\nThe result is : %d",res);

}
int main()
{
    scanf("%d",&nmbrOfData);
    int limit = 2*nmbrOfData;
    for(int i=nmbrOfData; i<limit ;i++) scanf("%d",&tree[i]);
    build();
    int number, position ;
    //printf("Please enter number and position to update : ");scanf("%d %d", &number, &position);
   // update(number,position+nmbrOfData);
   // printTree();
    int left,right;
    printf("Please enter range to calculate sum : ");scanf("%d %d", &left, &right);
    RmQ(left,right);
    return 0;
}

/*
13
2
3
5
8
11
7
6
13
4
9
10
1
14

3 9
*/
