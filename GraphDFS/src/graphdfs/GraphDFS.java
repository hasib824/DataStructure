package graphdfs;


public class GraphDFS {

   
    public static void main(String[] args) {
        
    }
    
}

class Linkedlist<T>
{
   private Node firstT = null;
   private Node lastH = null;
    
    private class Node
    {
        Node prev; 
        T data;
        Node Next;
    }
    
    
    void addFirst(T n)
    {
       Node temp = new Node();
       if(firstT == null && lastH== null)
       {
           firstT=lastH=temp;
       }
       else{
         lastH.prev = temp ;
       }
       temp.data= n ;
       temp.Next = lastH;
       lastH = temp;
       temp.prev = null ;
                                                        
    }
    
    
}
