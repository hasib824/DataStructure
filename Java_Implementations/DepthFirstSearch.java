package dfs;
import java.util.*;


public class DFs {
    static Graph<Integer> graph ;  
    static Scanner sc;
     
    public static void main(String[] args) {     
       inputGraph(); 
       printGraph();
      
       System.out.println("Please enter a source : ");
       int source = sc.nextInt();
       
       Graph.Results results = graph.dfs(source);
        HashMap<Integer, Integer> distance = results.getDistance();
        HashMap<Integer, Integer> visit_time = results.getVisit_time();
        HashMap<Integer, Integer> finish_time = results.getFinish_time();
        
        Set<Integer> keySet = distance.keySet();
        for(int key: keySet)
        {
            System.out.println("Node "+key+" : "+" visit : "+visit_time.get(key)+" finish : "+ finish_time.get(key));
        }
       
       
       
       
    }
    
    static void inputGraph()
    {
        int vertexes, edges; 
        int vertex1, vertex2;
        sc= new Scanner(System.in);
        System.out.println("Please enter the number of Vertex : ");
        vertexes  = sc.nextInt();
        System.out.println("Please enter the number of edges");
        edges = sc.nextInt();
        graph = new Graph(vertexes,edges);
        
        System.out.println("Please enter the connections : ");
        
        for(byte i=0; i<edges; i++)
        {   
            vertex1 = sc.nextInt(); 
            vertex2 = sc.nextInt();
            graph.add(vertex1,vertex2);
            if(i==edges-1) break;
            System.out.println((edges-1-i)+" more :");
           // System.out.println(" :: "+ i);
        }
        
        
    }
    
    static void printGraph()
    {  
       HashMap<Integer, LinkedList<Integer>> graph1 = graph.getGraph();
       Set<Integer> keySet = graph1.keySet();
       for(Integer key : keySet)
       {   
           System.out.print("Connections of "+key +" is : ");
           LinkedList<Integer> get = graph1.get(key);
           for(int g: get)
           {
               System.out.print(g+ ",");
           }
           System.out.println("");
       }       
    }    
}

class Graph<T>
{   
    private int vertexes, edges ;
    private Results results ;
    private int time=0;
    private HashMap< T, LinkedList<T> > graph = new HashMap();
    private Set<T> keySet;
    HashMap<T, Boolean> color = new HashMap();
   
    Graph(int vertexes,int edges)
    {
        this.vertexes = vertexes ; 
        this.edges = edges ;
        
    }
    
    public class Results
    {
       private HashMap<T,Integer> distance ;
       private HashMap<T,Integer> visit_time ;
       private HashMap<T,Integer> finish_time ;
       
       private Results()
       {
            distance = new HashMap();
            visit_time = new HashMap();
            finish_time = new HashMap();
       }

        public HashMap<T, Integer> getDistance() {
            return distance;
        }

        public HashMap<T, Integer> getVisit_time() {
            return visit_time;
        }

        public HashMap<T, Integer> getFinish_time() {
            return finish_time;
        }
            
    }

    void add(T vertex1, T vertex2) // vertex1 is parent Node and vertex2 is child node
    {   
        if(!graph.containsKey(vertex1))
        {  
           graph.put(vertex1, new LinkedList<>(Arrays.asList(vertex2))) ;
        }
         else
        {
            graph.get(vertex1).add(vertex2);
        }
       if(!graph.containsKey(vertex2))
        {  
           graph.put(vertex2, new LinkedList<>(Arrays.asList(vertex1))) ;
        }
        else
        {
            graph.get(vertex2).add(vertex1);
        }
       
        
    }
    
   HashMap< T, LinkedList<T> > getGraph()
    {
        return graph;
    }
   
   
   Results dfs(T source)
   {   
       results = new Results();
       color = new HashMap<>();      
       keySet = graph.keySet();
       
      // System.out.println("Keyset : "+ keySet.toString());
       for(T key : keySet)
       { 
        // System.out.println("Node : "+ key);
         color.put(key, false);
         //  System.out.println("Color : "+ color.get(key));
         results.visit_time.put(key, 0) ;
         results.finish_time.put(key, 0) ;
         results.distance.put(key, 0) ;
         
       }
       
       results.distance.put(source, 0) ;
       color.put(source, true) ;
       results.visit_time.put(source, 1);
       dfsRecur(source);
       
       for(T key : keySet)
       {   
          // System.out.println("Keyset calling dfs : "+ keySet.toString());
           if(color.get(key).equals(false))
           {   
               dfsRecur(key);
           }
       }
       
       return results;
   }
   
  void dfsRecur(T source)
   {
       
       LinkedList<T> get = graph.get(source);
       color.put(source, true);
       results.visit_time.put(source, ++time);
       for(T child : get)
       {  

          // System.out.print("Source : "+ source + " Child: "+ child);
           if(color.get(child).equals(false))
           {   
               
              Integer get1 = results.distance.get(source);
              results.distance.replace(child, ++get1) ;
            //  System.out.println(" Child :" + child);              
              dfsRecur(child);             
              
           }
           
       }
       results.finish_time.put(source, ++time) ;
       
   }
   
}


// zoomshaper 
// junior designer 
// 
/*
6
7
1 2
1 4
2 4
2 5
3 4
4 5
4 6
*/
