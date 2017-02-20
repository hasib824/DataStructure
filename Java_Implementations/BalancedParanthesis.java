import java.util.*;

public class BalancedParanthesis
{
    public static void main(String args[])
	{
	   System.out.println("Hello world");
	   Scanner sc= new Scanner(System.in);
	   System.out.println("Please enter a String");	   
	   String str = sc.nextLine();   
	   CheckParanthesis checkP = new CheckParanthesis();
	   checkP.check(str);
       	   
	}
}

class CheckParanthesis
{
  private MyStack stack;
  // starting brackets
  private static final char FIRST_STARTING = '(';
  private static final char SECOND_STARTING = '{';
  private static final char THIRD_STARTING = '[';
  // closing brackets
  private static final char FIRST_CLOSING = ')';
  private static final char SECOND_CLOSING = '}';
  private static final char THIRD_CLOSING = ']';
  // operators
  private static final char ADD = '+';
  private static final char SUB = '-';
  private static final char MUL = '*';
  private static final char DIV = '/';
  

  CheckParanthesis()
  {
     stack = new MyStack();  
  }
  
  void check(String s)
  {
      String str = s;
	  
	  for(int i=0;i<str.length();i++)
	  {
		char c = str.charAt(i);
	    if(c == FIRST_CLOSING || c == SECOND_CLOSING || c == THIRD_CLOSING )
		 {
		     if(stack.isEmpty())
			 {
				 System.out.println("Not a balanced paranthesis 1");
				 return;
			 }
             else
			 {
			     char cb= stack.top();
				 if(  (c == FIRST_CLOSING && cb == FIRST_STARTING ) || (c == SECOND_CLOSING && cb == SECOND_STARTING ) ||  (c == THIRD_CLOSING && cb == THIRD_STARTING ))
				 {
				   stack.pop();
				 }
				 else
				 {
				   System.out.println("Not a balanced paranthesis 2");
				   return;
				 }
			 }				 
		 }
		 
		 else if(c == FIRST_STARTING || c == SECOND_STARTING || c == THIRD_STARTING )
		 {
		    stack.push(c);
		 }
	  
	  }
	  if(stack.isEmpty())
	  {
	    System.out.println("Balanced paranthesis");
	  }
	  else System.out.println("Not balanced paranthesis 3");
	  
	  
  
  }
  
}

class MyStack
{  
   private Node head;
   MyStack()
   {
      head = null ;
   }
   private class Node
   {
       Node next;
	   char data;
   }
   
   public void push(char c)
   {
       Node temp = new Node();
	   temp.data = c ;
	   temp.next = head ;
	   head = temp ;
   }
   
   char top()
   {  
	  return head.data;
   }
   
   void pop()
   {
     head = head.next;
   }
   boolean isEmpty()
   {        
	  return head == null;
   }
   
   
}