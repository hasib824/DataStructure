package dijakstra;
import static java.lang.Math.toIntExact;
import java.util.*;
public class MyHashTable<T,E>
{   
	Values hashTable[];
        int size;
	MyHashTable(int size)
	{       this.size = size;
		hashTable = new Values[size];
		for(int i=0;i<size;i++)
			hashTable[i] = null;
	}
	
	void put(T key,E value)
	{
		int hashKey = getKey(key);
		Values<T,E> temp = hashTable[hashKey];
		if(temp==null)
			hashTable[hashKey] = new Values(key,value);
		else
		{
                    while(temp.next != null)
			temp = temp.next;
                    temp.next = new Values(key,value);
		}		
	}
	
	E get(T key)
	{
		int hashKey = getKey(key);
                
		Values<T,E> temp = hashTable[hashKey];
                if(temp == null ) return null;
		while(temp.next !=null && !temp.key.equals(""+(String)key))
			temp = temp.next;
		if(temp.key.equals(""+(String)key))
			return temp.value;
		else 
                    return null;
		
	}
        
        void replace(T key,E value)
        {   int hashKey = getKey(key);
            Values<T,E> temp = hashTable[hashKey];
            while(!temp.key.equals(""+(String)key))
                temp = temp.next;
            temp.value = value;
        }   
	
	int getKey(T key)
	{	String s = ""+(String)key;
		long hash = 1315423911;
		for(int i=0;i<s.length(); i++)
		{
                     hash ^= (((hash << 5)% (size<<2)) + (s.charAt(i)*(i+1)) + (hash >> 2));
		}
		return (int)(hash%(size-1));
	}
	
	private class Values<T,E>
	{       
            
		String key;
		Values next; // Points to the conflicted city information
		E value;		
		Values(T sourceCityname,E value)
		{
                    this.key = ""+(String)sourceCityname;
                    this.value = value;
                    this.next = null;
		}
	}
}

