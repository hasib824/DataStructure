import java.util.*;

public class InfixToPostfix
{
   public static void main(String ...args)
   {
      Scanner sc = new Scanner(System.in);
      MyStack mst= new MyStack();
      
	  // Checking if stack is working fine
     for(int i=0;i<10;i++) mst.push(Integer.toString(i));  
     while(!mst.isEmpty())
	 {
		 System.out.println(mst.top()); mst.pop();
	 }
	  System.out.println("Please enter a String");
	  String exp = sc.nextLine();
	  PostfixConverter pstC= new PostfixConverter();
      ArrayList<String> postfix = pstC.convert(exp);	
     // System.out.println("So the postfix is : "+ postfix);	
	 System.out.println("Postfix : ");	
      for(String str : postfix)
	  {
          System.out.print(str);	  
	  }
      
      System.out.println("");
	  
	  PostfixToCalculation pstc= new PostfixToCalculation();
	  System.out.println(pstc.calculate(postfix));
	  
   }

}

class PostfixToCalculation
{
     LinkedList<Integer> ll;
	 PostfixToCalculation()
	 {
	   this.ll = new LinkedList();
	 }
	 
	 Integer calculate(ArrayList<String> exp)
 	 {  
	    Integer result = 0;
        for(String s: exp)
		{
			if( !s.equals("+") && !s.equals("-") && !s.equals("*") && !s.equals("/") &&  !s.equals(","))
			{
			   ll.add(Integer.parseInt(s));
			}
			else if(s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/"))
			{
			   Integer op2 = ll.getLast(); ll.removeLast(); Integer op1 = ll.getLast(); ll.removeLast();
			   result = perform(op2,s,op1);
			   ll.add(result);
			}
		}			
	 
	   return result;
	 }
	 
	 Integer perform(Integer op2,String s,Integer op1)
	 {    Integer res=0;
	     switch(s)
		 {  
		   
		    case "+" : res= op2+op1; break; 
		    case "-" : res= op1-op2; break; 
		    case "*" : res= op2*op1; break; 
		    case "/" : res= op1/op2; break; 
		   
		 }
		 
		 return res;
	 }
}

 class PostfixConverter
 {   
  private MyStack stack;
     PostfixConverter()
	 {
	   stack = new MyStack();
	 }	 
  private int precedence(String c)
   { 
     int prece;
     switch(c)
	 {
	    case "+" : prece = 1 ; break;
	    case "-" : prece = 1 ; break;
	    case "*" : prece = 2 ; break;
	    case "/" : prece = 2 ; break;
		default : prece = 0;
 	 }
	 return prece;
   }
  
  ArrayList<String> convert(String exp)
  { 
    ArrayList<String> postfix = new ArrayList();
    for(int i=0;i<exp.length();i++)
	{ 
      char c = exp.charAt(i); int number = 0 ;
	  if(c == Constants.FIRST_STARTING || c == Constants.SECOND_STARTING || c == Constants.THIRD_STARTING) stack.push(c+"");
	  else if(c >= 48 && c<=57)
	  {
	     number = c - '0' ; i++; // can also be done by Integer.parseInt(c)         
		 while(i< exp.length() && exp.charAt(i)>= 48 && exp.charAt(i)<=57)
		 {
		    number = number*10+ (exp.charAt(i) - '0');
			i++;
		 }
          String temp = Integer.toString(number);		 
          postfix.add(temp); 
		  postfix.add(",");
		  i--;

	
	
		  //stack.push(temp);
	  }
	 
      // System.out.println("number "+i +" : "+ number);
	 else if( (i< exp.length()) && (exp.charAt(i)== Constants.ADD || exp.charAt(i) == Constants.SUB || exp.charAt(i)== Constants.MUL || exp.charAt(i) == Constants.DIV  ) )
	 {
	     while( !stack.isEmpty() && (precedence(stack.top()) >=  precedence(exp.charAt(i)+"")) ) 
		 {
		    postfix.add(stack.top()); 
			postfix.add(","); 
			stack.pop();
		 }
		 stack.push(exp.charAt(i)+"");
		// System.out.println("Operator In : "+ stack.top());
	 }
	 
	  else if( (i< exp.length()) && (exp.charAt(i)== Constants.FIRST_CLOSING || exp.charAt(i) == Constants.SECOND_CLOSING || exp.charAt(i)== Constants.THIRD_CLOSING ) )
	 {
	     while(!stack.top().equals(pair(exp.charAt(i))+""))
		 {
		    postfix.add(stack.top()); 
 	        postfix.add(","); 
			stack.pop(); 
		 }
		 stack.pop();
	 }
	 
	}
	 while(!stack.isEmpty())
	 {
	   postfix.add(stack.top()); 
 	   postfix.add(",");
	   stack.pop();
	 }	
	
	return postfix ;
  }
  
  private char pair(char c)
  {    
     char ch;
      switch(c)
	  {
	    case Constants.FIRST_CLOSING  : ch = Constants.FIRST_STARTING ; break ; 
	    case Constants.SECOND_CLOSING : ch = Constants.SECOND_STARTING ; break ; 
	    case Constants.THIRD_CLOSING  : ch = Constants.THIRD_STARTING ; break ; 
		default : ch= 'a' ; 
	  }
	  return ch;
  }
  
 }
 
 class MyStack
 {  
    private Node head;
	MyStack()
	{
	   this.head = null;
	}
	
	private class Node
	{  
	   Node next ; 
	   String data;
	}
    void push(String data)
	 {
		 Node temp = new Node();
		 temp.data = data; 
		 temp.next = head;
		 head = temp;
	    
	 } 
    String top()
	 {
	   return head.data;
	 }
	 
	 void pop()
	 {
	   head = head.next ;
	 }
	 
	boolean isEmpty()
	 {
	   return head == null;
	 }
 }
 
 
 class Constants
 {

  // starting brackets
   static final char FIRST_STARTING = '(';
   static final char SECOND_STARTING = '{';
   static final char THIRD_STARTING = '[';
  // closing brackets
   static final char FIRST_CLOSING = ')';
   static final char SECOND_CLOSING = '}';
   static final char THIRD_CLOSING = ']';
  // operators
   static final char ADD = '+';
   static final char SUB = '-';
   static final char MUL = '*';
   static final char DIV = '/';
 
 }