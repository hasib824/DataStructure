package dijakstra;
import java.util.*;
public class MyComparator implements Comparator
{
	public int compare(Object t1,Object t2)
	{
		Datas data1 = (Datas)t1;
		Datas data2 = (Datas)t2;
		
		return data1.dist-data2.dist;
	}
}