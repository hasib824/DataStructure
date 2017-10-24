
package dijakstra;


public class Dijakstra {

   
    public static void main(String[] args) {
       MyPriorityQueue pq = new MyPriorityQueue(new MyComparator());
       pq.push(new Datas(5,10));
       pq.push(new Datas(8,12));
       pq.push(new Datas(12,9));
       pq.push(new Datas(3,5));
       
        Datas top = (Datas)pq.top();
        System.out.println("Data "+top.dist+ " Node : "+top.node);
    }
    
}
