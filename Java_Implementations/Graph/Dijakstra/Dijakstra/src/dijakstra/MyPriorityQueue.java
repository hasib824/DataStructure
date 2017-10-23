package dijakstra;
import java.util.*;

public class MyPriorityQueue<T>
{   
	Comparator comparator;
        ArrayList<T> datas;
        int size = -1;
	MyPriorityQueue(int numberOfNodes,Comparator mycomparator)
	{
		this.comparator = mycomparator;
		this.datas = new ArrayList();
	}
	
	void push(T data)
	{
		datas.add(++size, data);
		int l = size;
		while(l>=0)
		{	T child = datas.get(l);
			T parent = datas.get(l);
			if(0>comparator.compare(child,parent))
			{
                            datas.add(l/2, child);
                            datas.add(l,parent);
			}
		}
	}
	T top()
	{
            return datas.get(size);
	}
	
	void pop()
	{
            datas.add(0, datas.get(size));
            heapify(0,size);
	}
	
	void heapify(int pos,int size)
	{	
            if(pos*2+1>size) return;
            T parent = datas.get(size);
            int l=pos;
            if(pos*2+1 <= size && 0<comparator.compare(parent,datas.get(pos*2+1)))
            l = pos*2+1;
            if(pos*2+2 <= size && 0<comparator.compare(parent,datas.get(pos*2+2)))
		l = pos*2+2;
            if(l!=pos)
            {
                datas.add(pos,datas.get(l));
                datas.add(l,parent);
                heapify(l,size);
            }
	}	
}












