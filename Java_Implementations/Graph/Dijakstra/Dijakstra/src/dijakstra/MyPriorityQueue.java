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
		while(l>0)
		{	
                    T child = datas.get(l);
                    T parent = datas.get(l/2);
			if(0>comparator.compare(child,parent))
			{
                            datas.set(l/2, child);
                            datas.set(l,parent);
			}
                        l=l/2;
		}
	}
	T top()
	{
            return datas.get(0);
	}
	
        boolean isEmpty()
        {
            return datas.isEmpty();
        }
	void pop()
	{   
            datas.set(0, datas.get(datas.size()-1));
            datas.remove(datas.size()-1);
             for(int i = 0; i<datas.size();i++)
            {   Datas d = (Datas)datas.get(i);
               // System.out.println("Age City "+d.connectedCity + " Distance "+ d.dist);
            }
            if(!datas.isEmpty())
                heapify(0);
            for(int i = 0; i<datas.size();i++)
            {   Datas d = (Datas)datas.get(i);
               // System.out.println("pore City "+d.connectedCity + " Distance "+ d.dist);
            }
	}
	
	void heapify(int pos)
	{	
            if(pos*2+1>=datas.size()) return;
            T parent = datas.get(pos);
            int l=pos;
            if(pos*2+1 < datas.size() && 0<comparator.compare(datas.get(l),datas.get(pos*2+1)))
                l = pos*2+1;
            if(pos*2+2 < datas.size() && 0<comparator.compare(datas.get(l),datas.get(pos*2+2)))
		l = pos*2+2;
            if(l!=pos)
            {
                datas.set(pos,datas.get(l));
                datas.set(l,parent);
                heapify(l);
            }
	}	
}
