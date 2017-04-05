import java.util.Scanner;

public class BSt_level_wise_traversal {
    
    public static void main(String[] args) {
        int n=0;
        Scanner sc = new Scanner(System.in);
        System.out.println("How many datas : ");
        n= sc.nextInt() ;
        BinaryTree bt = new BinaryTree();
        for(int i=0;i<n;i++)
        {   
            System.out.println("Please enter a data : ");
            bt.addData(sc.nextInt());
        }      
        bt.treeTraverse();
    }
}


class Node
{
    Integer data ;
    Node left;
    Node right;
}


class MyQ
{   
    Nodes top = null ;
    Nodes tail = null ;
    class Nodes
    {
        Node node;
        Nodes next ;
    }
    
    void push(Node node)
    {
        if(top == null)
        {
            top = new Nodes();
            top.node = node ;
            top.next = null ;
            tail = top ;
        }
        else
        {
            Nodes temp = new Nodes();
            temp.node = node ;
            temp.next = null;
            tail.next = temp ;
            tail = temp ;
            
        }
    }
    
    Node top()
    {
        return top.node ;
    }
    
    void pop()
    {
        top = top.next ;
    }
    
    boolean IsEmpty()
    {
        return top == null;
    }
}

class BinaryTree
{
    private Node root=null;
    private Node parent=null;
    private Node point=null;
   
    void addData(Integer number)
    {
        if(root==null)
        {
            root = new Node();
            root.data = number;
            root.left = root.right = null ;
        }
        
        else 
        {
            point = root ;            
            while(point != null)
            {
               parent = point ;
               if(number<= point.data) point = point.left ;
               else point = point.right ;
            }
         if(number<= parent.data)
        {
            parent.left = new Node();
            parent.left.data = number ;
        }
        
        else
        {
            parent.right = new Node();
            parent.right.data = number;
        } 
      }     
    } // end of addData
    
    void treeTraverse()
    {
        MyQ Q= new MyQ();
        Q.push(root);
        
        while(!Q.IsEmpty())
        {
            Node node = Q.top(); Q.pop();
            System.out.println("Parent : "+ node.data);
            if(node.left != null ) 
            {
                System.out.println("Left child : " + node.left.data); Q.push(node.left);
            }
            if(node.right != null )
            {
                System.out.println("Right child : " + node.right.data); Q.push(node.right);
            }
            System.out.println("");
             
        }
    }
}
