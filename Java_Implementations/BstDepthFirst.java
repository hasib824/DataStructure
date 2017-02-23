// input 13 19 15 18 6 5 14 73 62 45 32 13 17 9  
import java.util.*;

public class BstDepthFirst
{
   public static void main(String ... args) 
   {   
       Scanner sc = new Scanner(System.in);
	   Bst<Integer> bst= new Bst();
	   System.out.println("How many data : "); 
	   int n= sc.nextInt();
	   for(int i=0;i<n;i++)
	   {
		   bst.add(sc.nextInt());
	   }
	    
		
	    Dfs<Integer> dfs = new Dfs(bst.getRoot());
		dfs.travarse();
	    HashMap<Integer,Integer> distance = dfs.getDistance();
		int height = dfs.getHeight();
		Set<Integer> keySet = distance.keySet();
		
		 for(int i=0;i<=height;i++)
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
   }

}

class Dfs<E extends Comparable<E>>
{
  private HashMap<E,Integer> distance;
  private int height; 
  private Bst.TreeNode root;
  Dfs(Bst.TreeNode root)
  {
	 distance= new HashMap(); 
	 height = 0; 
	 this.root = root; 
	 distance.put((E)root.data,0);
  }
  
  void travarse()
  {
	  doTravarse(root);
  }
  
  void doTravarse(Bst.TreeNode root)
  {
	  int dist = distance.get(root.data)+1; 
	  if(root.left!=null)
	  {   
          distance.put((E)root.left.data,dist); if(dist>height) height= dist ;
		  doTravarse(root.left); 
	  }
	  if(root.right !=null)
	  {
	      distance.put((E)root.right.data,dist); if(dist>height) height= dist ;
		  doTravarse(root.right); 
	  }
  }
  HashMap<E,Integer> getDistance()
  {
	  return distance;
  }
  int getHeight()
   {
	   return height;
   }   
}

class Bst<T extends Comparable<T>>
{
	TreeNode root;
	Bst(){ root = null; } 	
	class TreeNode
	{
		TreeNode left; T data; TreeNode right;
	}
	
	TreeNode getRoot()
	{
		return root;
	}
	void add(T data)
	{
		if(root == null) 
		{
			root=new TreeNode();
		    insert(root,data);
        }
		else
		{			
		    TreeNode temp,parent;
		    temp=parent=root;
			while(temp!=null)
			{
				parent = temp ;
			    if(data.compareTo(temp.data)<=0) temp=temp.left;
				else temp=temp.right;		
			}
			if(data.compareTo(parent.data)<=0)
			{
				parent.left= new TreeNode();
				insert(parent.left,data);
			}
			else
			{
				parent.right = new TreeNode();
				insert(parent.right,data);
			}
		}			
		
	}
	
	void insert(TreeNode parent,T data)
	{
		parent.data = data; parent.left=parent.right= null;
		//System.out.println("Inserted");
	}
	
}


