package dijakstra;
import java.io.BufferedInputStream;
import java.io.*;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;
import java.util.logging.Level;
import java.util.logging.Logger;
public class Dijakstra {
  
    public static void main(String ... args) throws IOException 
    {    
        FileReader fileReader = null;
        try {
                System.out.println("How many Nodes ? ");
                int nodes=0;
                fileReader = new FileReader("I:\\github\\DataStructure\\Java_Implementations\\Graph\\Dijakstra\\inputs.txt");
                BufferedReader bufferedReader = new BufferedReader(fileReader);
                nodes = Integer.parseInt(bufferedReader.readLine());
                MyHashTable<String,ArrayList<Datas>> myHashTable = new MyHashTable(nodes);
                ArrayList<String> str = new ArrayList();
                for(int i=0;i<nodes;i++)
                 {   
                    System.out.println("Please enter sourceCity : ");
                    String sourceCity = bufferedReader.readLine();
                    str.add(sourceCity);
                    System.out.println("How many connection of "+ sourceCity + " ? ");
                    int connections;
                    connections = Integer.parseInt(bufferedReader.readLine());
                    ArrayList<Datas> connectedCityList = new ArrayList();
                    for(int j=0;j<connections;j++)
                     {
                        System.out.println("Enter connected city and distance of "+ sourceCity);
                        Datas data = new Datas(bufferedReader.readLine(),Float.parseFloat(bufferedReader.readLine())); // 
                        connectedCityList.add(data);
                     }
                    myHashTable.put(sourceCity,connectedCityList); 
                    //bufferedReader.readLine(); // Receives the gap between two cities information
                 }   
                System.out.println("Please enter Source and Destination city : ");
                findMinDistance(myHashTable,str,"shaymoli","gulisthan",nodes);
                //printGraph(myHashTable,str);
        } catch (FileNotFoundException ex) {
            
        } 
    }
    
    // Implements DijaksTra Algorithm
    static float findMinDistance(MyHashTable<String,ArrayList<Datas>> myHashTable,ArrayList<String> str,String source,String destination,int nodes)
    {   
        String ss = source;
        MyHashTable<String,Integer> visited = new MyHashTable(nodes+1);
        MyHashTable<String,Float> distance = new MyHashTable(nodes+1);
        MyHashTable<String,String> parents = new MyHashTable(nodes+1);
        for(String s :str)
        {
            visited.put(s, 0);
            distance.put(s, Float.MAX_VALUE);
        }
        distance.replace(source, 0.0f);
        MyPriorityQueue<Datas> pQ = new MyPriorityQueue(new MyComparator());
        pQ.push(new Datas(source,0.0f));
        while(!pQ.isEmpty())
        {   source = pQ.top().connectedCity; 
            float dd = pQ.top().dist;
            //System.out.println("Top : "+source+" Dist : "+ pQ.top().dist);
            pQ.pop();
            visited.replace(source,1);
            ArrayList<Datas> datas = myHashTable.get(source);
            for(int j=0;j<datas.size();j++)
            {   Datas child = datas.get(j);
                
                if(visited.get(child.connectedCity).equals(0))
                {   
                  // System.out.println("Child connected city : "+child.connectedCity+" , "+ (dd+child.dist));
                    if(distance.get(source)+child.dist< distance.get(child.connectedCity))
                    {   
                        if(parents.get(child.connectedCity)==null)
                            parents.put(child.connectedCity, source);
                        else 
                            parents.replace(child.connectedCity, source);
                        distance.replace(child.connectedCity, (dd+child.dist));
                        pQ.push(new Datas(child.connectedCity, (dd+child.dist)));
                        
                        
                    }
                        
                }
            }
        }
       // for(String s :str)
            System.out.println("\nMin distance of "+ss+" to "+ destination +" is : "+distance.get(destination));
             System.out.print("The path is : ");
            printPath(parents,ss,destination);
        return distance.get(destination);
    }
    static void printPath(MyHashTable<String,String> mm,String source,String destination)
    {   
        if(!source.equals(destination)) 
            printPath(mm,source,mm.get(destination));
        System.out.print(destination+ " -> ");      
    }
    static void  printGraph(MyHashTable<String,ArrayList<Datas>> myHashTable,ArrayList<String> str)
    {
       for(String s : str)
       {   
           System.out.println("\nSource : "+s);
           System.out.print("Connections : ");
           ArrayList<Datas> datas = myHashTable.get(s);
           for (Datas data : datas) {
               System.out.print(data.connectedCity+", " );
           }
       }
    }
}
/*
Input file 
https://paste.ubuntu.com/25812878/
*/