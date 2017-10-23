package dijakstra;
import java.util.*;
public class MyHashTable<T>
{   
	Conflict hashTable[];
	int size;
	MyHashTable(int size)
	{
		hashTable = new Conflict[size];
		for(int i=0;i<size;i++)
			hashTable[i] = null;
	}
	
	void put(String sourceCityname,ArrayList<T> connectedCities)
	{
		int key = getKey(sourceCityname);
		Conflict temp = hashTable[key];
		if(temp==null)
			hashTable[key] = new Conflict(sourceCityname,connectedCities);
		else
		{
			while(temp.next != null)
				temp = temp.next;
			temp.next = new Conflict(sourceCityname,connectedCities);
		}
		
	}
	
	ArrayList<T> get(String sourceCityname,ArrayList<T> connectedCities)
	{
		int key = getKey(sourceCityname);
		Conflict temp = hashTable[key];
		while(temp!=null && temp.sourceCityname!=sourceCityname)
				temp = temp.next;
		if(temp.sourceCityname==sourceCityname)
			return temp.connectedCities;
		else 
			return null;
		
	}
	
	int getKey(String sourceCityname)
	{	
		char cityname[] = sourceCityname.toCharArray();
		int l = cityname.length;
		long hash=1315423911;
		for(int i=0;i<l; i++)
		{
			hash = hash^(hash<<5)+(cityname[i]+ (hash>>2));
		}
		return (int)hash%size;
	}
	
	private class Conflict<T>
	{
		String sourceCityname;
		Conflict next; // Points to the conflicted city information
		private ArrayList<T> connectedCities;
		
		Conflict(String sourceCityname,ArrayList<T> connectedCities)
		{
			this.sourceCityname = sourceCityname;
			this.connectedCities = connectedCities;
			this.next = null;
		}
	}
}

