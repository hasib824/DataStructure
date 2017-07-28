#include<bits/stdc++.h>

using namespace std;

int data[100];
int sparse[100][100];

void initialize()
{
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            sparse[i][j]= -1;
        }
    }
}
void makeSparseTable(int n)
{
  for(int i=0;i<n;i++) sparse[i][0]=i;
  for(int j=1;(1<<j)<=n;j++)
  {
      for(int i=0; i+(1<<j)-1<n; i++)
      {
          int x = sparse[i][j-1];
          int y = sparse[i+(1<<j-1)][j-1];
          if(data[x]<data[y]) sparse[i][j]= x;
          else sparse[i][j] = y ;
      }
  }
}


int rmq(int low,int high)
{
    int nmbrOfData= (high-low)+1;
    int pow = log2(nmbrOfData);

    int x = sparse[low][pow];
    int y = sparse[high-(1<<pow)+1][pow];

    if(data[x]<data[y]) return data[x];
    else return data[y];
}
void printTree(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0; (1<<j)<=n;j++)
        {   if(sparse[i][j]!=-1)
                printf("%d , ",sparse[i][j]);
        }
        printf("\n");
    }
}

int main()
{   initialize();
    printf("How many datas : ");
    int n; scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&data[i]);
    makeSparseTable(n);
    printTree(n);
    printf("\n\n");
    printf("RmQ 0->6 : %d\n",rmq(0,6));
    printf("RmQ 8->10 : %d\n",rmq(8,10));
    printf("RmQ 4->7 : %d\n",rmq(4,7));
    printf("RmQ 2->11 : %d\n",rmq(2,11));
    printf("RmQ 0->11 : %d\n",rmq(0,11));
    printf("RmQ 3->5 : %d\n",rmq(3,5));
    return 0;
}

/*
12
3
7
2
5
11
9
4
6
13
8
10
5


*/
