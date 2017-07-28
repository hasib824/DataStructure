import java.util.Scanner;
import java.util.*;

public class BinaryIndexedTree{
	
	public static void main(String ...args)
	{
	   Scanner sc= new  Scanner(System.in);
	   System.out.println("How many numbers : ");
	   int n; 
	   n= sc.nextInt(); int A[] = new int[n+1];
	   for(int i=1;i<=n;i++) A[i] = sc.nextInt();
	   Tree bit = new Tree();
	   bit.build(A,n);
	   System.out.println("Result : "+ bit.query(12));
	   bit.update(7,7);
	   System.out.println("Result : "+ bit.query(12));
	   
	}
   
   
}

class Tree
{  
    private int bit[]; int n;
    Tree()
	{
	  
	}
	void build(int A[],int size)
	{ 
	  this.n= size+1;
	  bit = new int[size+1];
	  for(int i : bit) bit[i]=0;
	  
	  for(int i=1;i<=size;i++) 
	  {
	     bit[i] += A[i] ;
		 int j = getNext(i);
         while(j<=n)
		 {
		   bit[j] += A[i];
		   j= getNext(j) ;
		 }
          
	  }
	  for(int i=1 ; i<n ; i++) System.out.println(i+ " : "+ bit[i]);	
	}
	  
	  int query(int i) 
	  {
		 int sum= 0;
		 while(i>0)
		 {
		   sum+= bit[i] ;
		   i= getParent(i);
		 }
		 return sum;
	  }
	  
	  int query(int a,int b)
	  {
	      return query(b)-query(a) ;
	  
	  }
      
      void update(int pos,int i)
	  {   
		  int change = i - bit[pos];
		  while(pos<=n)
		  {
		     bit[pos] += change;
			 pos = getNext(pos);
		  }
	  }
  
	  int getNext(int i) { return i+(i&-i); } 
	  int getParent(int i) { return i-(i&-i); }

}

/*

12
9
12
5
4
3
1
2
5
4
7
9
8

*/