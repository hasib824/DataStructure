package dijakstra;
import java.util.*;

public class MyPriorityQueue<T>
{   
	Comparator comparator;
        ArrayList<T> datas;
        int size = 0;
	MyPriorityQueue(Comparator mycomparator)
	{
		this.comparator = mycomparator;
		datas = new ArrayList<T>();
	}
	
	void push(T data)
	{       
		datas.add(data);
                size = datas.size()-1;
		int l = size;
		while(l>=0)
		{	T child = datas.get(l);
			T parent = datas.get(l);
			if(0>comparator.compare(child,parent))
			{
                            datas.set(l/2, child);
                            datas.set(l,parent);
			}
		}
	}
	T top()
	{
            return datas.get(size);
	}
	
	void pop()
	{
            datas.set(0, datas.get(size));
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
                datas.set(pos,datas.get(l));
                datas.set(l,parent);
                heapify(l,size);
            }
	}	
}
