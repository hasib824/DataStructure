package dijakstra;
import java.util.*;
public class MyComparator implements Comparator
{
	public int compare(Object t1,Object t2)
	{
		Datas data1 = (Datas)t1;
		Datas data2 = (Datas)t2;
		float res = data1.dist-data2.dist; 
                if(res<0.0f) 
                    return -1;
                else if(res>0.0f)
                    return 1;
                return 0;
	}
}