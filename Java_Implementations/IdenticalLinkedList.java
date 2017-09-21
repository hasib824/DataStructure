// Checks if two given Lists are Same of each other
import java.util.Scanner;

public class IdenticalLinkedList
{
		public static void main(String ...args)
		{
			System.out.println("How many datas  for first List ? : ");
			int n; Scanner sc= new Scanner(System.in);
			n= sc.nextInt(); 
			System.out.println("Please enter datas for 1st list: ");
			MyIdenticalLinkedList mill = new MyIdenticalLinkedList();
			MyIdenticalLinkedList mill2 = new MyIdenticalLinkedList();
			for(int i=0;i<n;i++)
			{
				mill.push(sc.nextInt());
			}
			System.out.println("How many datas  for 2nd List ? : ");
			n= sc.nextInt(); 
			System.out.println("Please enter datas for 2nd list: ");
			for(int i=0;i<n;i++)
			{
				mill2.push(sc.nextInt());
			}
			
			mill.printList();
			mill2.printList();
			
			if(mill.checkIdentical(mill2)) System.out.println("Lists are Identical");
			else System.out.println("Lists are Not Identical");
			
		}
	
}

class MyIdenticalLinkedList
{   
	private class Node{
		int a; 
		Node next;
		Node(int a) { this.a = a; }
		Node(Node next) { this.next = next;}
		Node(int a,Node next) { this.a = a ; this.next = next;}
	}
	private Node head=null;

	void push(int num)
	{   
	    Node temp = new Node(num,head);
		head = temp ; 
	}
	
	void printList()
	{
		Node printer = this.head;
		System.out.print("The list is : ");
		while(printer != null)
		{   
			System.out.print(printer.a+", ");
			printer = printer.next;
		}
	    System.out.println("\n");
	}
	
	boolean checkIdentical(MyIdenticalLinkedList mill)
	{
        Node temp1 = this.head ;
        Node temp2 = mill.head;
		
		while(temp1 !=null && temp2 != null)
		{
			if(temp1.a!=temp2.a) return false;
			temp1 = temp1.next; temp2 = temp2.next;
		}
		
		return temp1 == null && temp2 == null; 
		
	}
}


/*
I:
cd github\DataStructure\Java_Implementations
javac IdenticalLinkedList.java
java IdenticalLinkedList
10
12
14
25
65
78
9
45
87
96
32

10
12
14
5
65
78
9
45
87
96
32


*/