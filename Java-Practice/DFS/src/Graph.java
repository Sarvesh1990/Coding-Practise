import java.util.ArrayList;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class Graph 
{
	Map<Integer, Set<Integer> > myMap;
	int[] myArray = {0, -1, -1, -1, -1, -1, -1};

	Graph(Map<Integer, Set<Integer>> map)
	{
		myMap=map;
	}
	void Insert(int a, int b)
	{
		if(myMap.get(a)==null)
		{
			Set <Integer> mySet= new HashSet<Integer>();
			mySet.add(b);		
			myMap.put(a, mySet);
		}
		else
		{
			myMap.get(a).add(b);
		}
	}
	void dfs(int a)
	{
		for(Integer myVal : myMap.get(a))
		{
			if(myArray[myVal]>=0)
			{
				System.out.println("Returning because "+ myVal + " already checked");
			}
			else
			{
				myArray[myVal]=a;
				System.out.println("Calling dfs for "+myVal+ " with myArray value set as "+a);
				dfs(myVal);				
			}
		}
	}
	
	void Path(int a)
	{
		for(Integer myTest : myMap.get(a))
		{
			System.out.println("For value "+ myTest + " key is "+ myArray[myTest]);
		}
	}
}
