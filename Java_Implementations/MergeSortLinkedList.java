// this is a programme for Sorting a LinkedList . Stating time 1:15 am ,  24/2/2017

import java.util.*;

public class MergeSortLinkedList
{
	public static void main(String ...args)
	{
		System.out.println("Hasibuzzaman Chowdhury");
		MyLinkedList<Integer> ll= new MyLinkedList();
		ll.add(10); ll.add(12); ll.add(8); ll.add(15); ll.add(6);
		ll.add(32); ll.add(49); ll.add(21); ll.add(29); ll.add(4);
		ll.add(3); ll.add(22); ll.add(28); ll.add(35); ll.add(2);		
		ll.print();
        
		MergeSort<Integer> mgst=new MergeSort();
		mgst.sort(ll,15);
		ll.print();
		 
        		
	}

}


class MergeSort<E extends Comparable<E>>
{
    void sort(MyLinkedList<E> ll,int size)
	{   
	    if(size <2) return;
        int mid= size/2;
        MyLinkedList<E> leftll= new MyLinkedList();
        MyLinkedList<E> rightll= new MyLinkedList();
		Node<E> llhead= ll.getHead();
		for(int i=0;i<mid;i++)
		{   
		    leftll.add(llhead.data); llhead = llhead.next; 
			
		}
		for(int i=mid;i<size;i++)
		{   
		    rightll.add(llhead.data); llhead = llhead.next; 
		}
		
		sort(leftll,mid); sort(rightll,size-mid);
		merge(ll,leftll,rightll);
         		
	}
	
	void merge(MyLinkedList<E> ll,MyLinkedList<E> leftll,MyLinkedList<E> rightll)
	{   
	    Node<E> mainHead = ll.getHead();
	    Node<E> leftHead = leftll.getHead();
	    Node<E> rightHead = rightll.getHead();
		while(leftHead !=null && rightHead!=null)
		{
            if(leftHead.data.compareTo(rightHead.data) <= 0)
			{
				mainHead.data = leftHead.data;
				mainHead = mainHead.next;
				leftHead = leftHead.next ;
			}	            
           else
			{
				mainHead.data = rightHead.data;
				mainHead = mainHead.next;
				rightHead = rightHead.next ;
			}
		}
		
		while(leftHead !=null)
		{
			mainHead.data = leftHead.data;
		    mainHead = mainHead.next;
		    leftHead = leftHead.next ;
		}
		
		while(rightHead !=null)
		{
			mainHead.data = rightHead.data;
			mainHead = mainHead.next;
			rightHead = rightHead.next ;
		}
		
		leftll=rightll=null;
	}

}

class Node<T extends Comparable<T>>
{
	   T data;
	   Node next;
}
class MyLinkedList<T extends Comparable<T>>
{  
   private Node<T> head; 
   private Node<T> tail; 
   MyLinkedList(){head=tail=null;}

   Node<T> getHead()
   {
	   return head;
   }
   // list goes from left to right . Head is the First Data And Tail is the last Data 
   void add(T data) // Add a new Node to the Linked list 
   {
       Node<T> temp = new Node();
	   if(head==null) tail=head=temp;
	   temp.data = data;
       tail.next = temp;
	   tail=temp;
	   tail.next=null;
   }
  void print() // Priting the linkedList
  {
	  Node<T> temp = head;
	  System.out.print("Printing the LinkedList : ");
	  while(temp!=null)
	  {
		  System.out.print(temp.data+" , "); temp = temp.next;
	  }
	  System.out.println();
  }
}