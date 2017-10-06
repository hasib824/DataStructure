#include<bits/stdc++.h>
using namespace std;


void maxHeap(int A[],int pos,int n)
{
    int big = pos;
    int left = pos*2; int right = pos*2+1;
    if(left<=n && A[big] < A[left])
        big = left;
    if(right <=n && A[big] < A[right])
        big = right;
    if(big!=pos)
    {
        swap(A[big],A[pos]);
        maxHeap(A,big,n);
    }

}

void heapify(int A[],int n)
{
    for(int i=n/2;i>0;i--)
        maxHeap(A,i,n);
}

void heapSort(int A[],int n)
{
    int B[n+1];
    for(int i=1;i<=n;i++) B[i]=A[i];
    int* sorted = new int[n+1];
    int l = n;
    sorted[0]= B[1];
    for(int i=1;i<n;i++)
    {
        B[1] = B[l];
        maxHeap(B,1,--l);
        sorted[i] = B[1];
    }
    for(int i=0;i<n;i++)
    {
        printf("%d, ",sorted[i]);
    }
  //  return sorted;
}

void printHeap(int A[],int n)
{
    for(int i=1;i<=n;i++)
    {
        printf("\n\n       root %d \nleft %d        right %d",A[i],A[i*2],A[i*2+1]);
    }
}

// Adjusting the Heap property After popping the max
void adjust(int A[],int n)
{
    if(n<2) return;
    if(A[n/2]<A[n])
    {
        swap(A[n],A[n/2]);
        adjust(A,n/2);
    }

}

void insertPriorityQueue(int A[],int n,int data)
{
    A[n] = data;
    adjust(A,n); // Adjusting the Heap property After popping the max
}

int PopTop(int A[],int n)
{
   int to = A[1];
   A[1] = A[n];
   maxHeap(A,1,--n);
   return to;
}
int main()
{
    printf("How Many Numbers : ");
    int n; scanf("%d",&n);
    int A[n*n];
    for(int i=1;i<=n;i++)
        scanf("%d",&A[i]);
    //printHeap(A,n);
    heapify(A,n);

    //printf("After Heapify\n");
    //printHeap(A,n);
    int* sorted = new int[n+1];

    printf("\nSorted datas are : ");h
    heapSort(A,n);
    while(1)
    {
        printf("\n\nWhich Operation Do you want ? \n1.Insert\n2.Priority dequeu\n");
        int op; scanf("%d",&op);
        switch(op)
        {
            case 1 :
                int data; printf("\nPlease enter data : ");scanf("%d",&data);
                insertPriorityQueue(A,++n,data);break;
            case 2 : printf("\nTop : %d",PopTop(A,n)); n--;break;
        }
    }

    return 0;
}
/*
11
12 7 6 15 9 13 5 4 18 11 3

*/
