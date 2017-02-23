import java.util.*;

public class BST
{
	public static void main(String ...args)
	{
	  Scanner sc = new Scanner(System.in);
	  MyBst<Integer> bst= new MyBst();
	  
	  bst.insert(10);  bst.insert(2);  bst.insert(12);bst.insert(11);bst.insert(8);bst.insert(15);bst.insert(6);  bst.insert(1);bst.insert(9); 
	  System.out.println("Please enter a Number to search : ");  
	  System.out.println("Data found : "+ bst.search(sc.nextInt()));
	  HashMap<Integer,Integer> distance = bst.BfTraversal();
	  Set<Integer> keySet = distance.keySet();
	  int maxLevel = bst.getMaxLevel();
	    
	  System.out.println();
	  for(int i=0;i<=maxLevel;i++)
	  {  
          System.out.print("Level "+i+" : ");
	     for(Integer key: keySet)
	     {  
	       
	       if(distance.get(key) == i)
		   {
		      System.out.print(key+", ");   
		   }
		   
	     }
		 System.out.println("");
	  }
	  
	  System.out.println("\nMin : "+ bst.getMin()+" Max : "+bst.getMax()); 
	  
	  
	  
	}
}

class Queue<T>
{
    private QNode head;
    private QNode tail;

   Queue()
   {
      head = tail = null;
   }

    private class QNode
	{
	    T treeNode;
		QNode next;
	}
	
	void push(T treeNode)
	{   
        QNode temp = new QNode();
        if(tail == null) 
		{
     		head  = temp; 
			tail = temp;
		}
		else
		{
			head.next = temp;
		}
		temp.treeNode = treeNode;
		head = temp ;
        head.next = null;	
        //printQueue();		
	}
	
    void printQueue()
	{
	    QNode temp = tail;
		System.out.print("\nPrinting the queue : ");
		while(temp!=null)
		{
			System.out.print(temp.treeNode); temp= temp.next;
		}
	}
	
	T pop()
	{
	   T treeNode = tail.treeNode;
	   tail = tail.next ; 
	   if(tail == null) head = null; 
	   return treeNode ;
	   
	}
	
	boolean isEmpty()
	{
       return (tail == null);	   
	}
	

}	
class MyBst<T extends Comparable<T>>
{  
   private BstNode root;
   private HashMap<T,Integer> distance;
   private int maxLevel;
   MyBst()
   {
      root = null; maxLevel =0;
   }
     int getMaxLevel() // Tree Height 
	{
	  return maxLevel;
	}
	

    private class BstNode
	{
	    BstNode left;	T data; BstNode right;
	}
	
	
	T getMax()
	{    
	    BstNode max,temp; max=temp= root;
		while(temp!=null)
		{   max= temp;
			temp= temp.right;
		}
		return max.data;
	}
	
	T getMin()
	{
		BstNode min,temp; min=temp= root;
		while(temp!=null)
		{   min  = temp;
			temp= temp.left;
		}
		return min.data;
		
	}
    
	boolean search(T data) // Searching the data If it is exist on Tree 
	{
        BstNode temp = root;
        while(temp != null)
        {
           if(data.compareTo(temp.data) == 0) return true;
		   else if(data.compareTo(temp.data) <= 0) temp= temp.left;
		   else temp= temp.right;
		}
       return false;		
	}
	
	HashMap<T,Integer> BfTraversal()
	{
	   Queue<BstNode> Q = new Queue(); distance = new HashMap();
	   Q.push(root);
	   distance.put(root.data,0);
	   while(!Q.isEmpty())
	   {
	       BstNode parent = Q.pop();
		   int i = distance.get(parent.data) + 1;
           System.out.print("Parent : " + parent.data +" : "+"Child :");		   
		   if(parent.left != null)
		   {            
              distance.put(parent.left.data, i ); if( i>maxLevel ) maxLevel = i;	   
	          Q.push(parent.left);
		      System.out.print(parent.left.data + ", ");
		   }
		   if(parent.right != null)
		   {   
	          distance.put(parent.right.data, i ); if( i>maxLevel ) maxLevel = i;	  
	          Q.push(parent.right);
		      System.out.print(parent.right.data+", ");
		   }
		   System.out.println("");
		   
	   }
	   return distance;
	}
	
	void insert(T data)
	{   
		if(root == null) // If the Tree is null 
		{    root = new BstNode();  insertData(root,data);	// Actually insertig data here 	 
		}
		else
		{ 
	      BstNode temp1 = root;  BstNode parentToInsert = root;
		  while(temp1 != null) // Finding the position where to insert the data
		  {  
	        parentToInsert = temp1;
			if(data.compareTo(temp1.data)<= 0) temp1 = temp1.left;  // If the incomming data is Less or Equal to parent
		    else temp1 = temp1.right; 	// If the incomming data is greater than parent		  
		  }
		  
		  // Insertingthe data into it's position where it supposed to be
		  if(data.compareTo(parentToInsert.data)<= 0) // If the incomming data is Less or Equal to parent
		    {
		  	  parentToInsert.left = new BstNode(); 
			  insertData(parentToInsert.left,data);		   
		    }
		    else
		    {
			  parentToInsert.right = new BstNode(); 
			  insertData(parentToInsert.right,data);
		    }  	
		  
		}
	}
	
	void insertData(BstNode temp,T data)
	{    
	    temp.left= null;  temp.data = data;  temp.right = null; 	   
	}
    	
}