package graphdfs;

import java.util.*;


public class LinkedListJava {
    static Linkedlist_c<Integer> doubly ;
   static Scanner sc ;
   
    public static void main(String[] args) {
          doubly = new Linkedlist_c();       
          sc = new Scanner(System.in);
          System.out.println("Please enter  numbers : ");
          for(int i=0;i<5;i++)
          {            
              doubly.addFirst(sc.nextInt());
          }          
         
         doubly.printStack();  
         doubly.printQueue();
         
         while(true)
         {
             operation();
         }
         
       

    }
    
  static  void operation()
    {
         int n;
    System.out.println("\nWhich Operation you want ? : \n1.Add First ? \n2.Add Last ?\n3.removeFirst\n4.removeLast\n5.peekFirst \n6.peekLast\n");
     byte ch = sc.nextByte();; 
     
     switch(ch)
     {
        case 1 :  System.out.println("please enter number : ");
                    doubly.addFirst(sc.nextInt()); doubly.printStack(); 
                    doubly.printQueue();break ;
        case 2 :  System.out.println("please enter  number : ");
                    doubly.addLast(sc.nextInt()); doubly.printStack(); 
                    doubly.printQueue();break ;
        case 3 :  doubly.popFirst();doubly.printStack(); 
                    doubly.printQueue();break ;
        case 4 :  doubly.popLast();doubly.printStack(); 
                    doubly.printQueue();break ;
        case 5 :  System.out.println("PeekFirst : "+ doubly.peekFirst());doubly.printStack(); 
                    doubly.printQueue();break ;
        case 6 :  System.out.println("PeekLast : "+ doubly.peekLast()); doubly.printStack(); 
                    doubly.printQueue();break ;
       

     }
         
    }
    
}

class Linkedlist_c<T>
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
           firstT=temp;
       }
       else{
         lastH.prev = temp ;
       }
       temp.data= n;
       temp.Next = lastH;
       lastH = temp;
       temp.prev = null ;
                                                        
    }
    void addLast(T n)
    {
        Node temp1 = new Node();
        if(lastH == null && firstT == null)
        {
           lastH= temp1;
        }
        else
        {
             temp1.prev = firstT ;
             firstT.Next = temp1 ;
        }
        
        temp1.data = n; 
        temp1.Next = null ;
        firstT = temp1 ;
            
    }
    
   void push(T n)
    {
       Node temp = new Node();
       if(firstT == null && lastH== null)
       {
           firstT=temp;
       }
       else{
         lastH.prev = temp ;
       }
       temp.data= n;
       temp.Next = lastH;
       lastH = temp;
       temp.prev = null ;
        
    }
   
   T peekFirst()
   {
     return firstT.data;   
   }
   
   
   T peekLast()
   {
     return lastH.data;   
   }
   
   void popFirst()
   {
       Node temp1 = firstT.prev;
       temp1.Next= null;       
       firstT= null ;    
       firstT = temp1;       
       System.gc(); 
       
   }
    
   void popLast()
   {
       Node temp = lastH.Next ; 
       temp.prev = null; 
       lastH.Next = null; 
       lastH.Next = temp;      
       System.gc();
       
   }
   void printQueue()
   {  
      System.out.println("\nPrinting the Queue : ");
      Node temp = firstT ;
      while(temp != null)
      {
          System.out.print(temp.data+ ", ");
          temp= temp.prev;
      }
   }
   
   void printStack()
   {   
       System.out.println("\nPrinting the Stack : ");
       Node temp = lastH ;
       while(temp != null)
       {
           System.out.print(temp.data+ ", ");
           temp = temp.Next;
       }
   }
}
