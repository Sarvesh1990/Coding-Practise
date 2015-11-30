import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;
import java.util.Stack;

public class Graph 
{
	Map<Integer, Set<Integer> > myMap;
	boolean cycle=false;
	int[] myArray = {-1, -1, -1, -1, -1, -1, -1};
	Stack<Integer> myStack = new Stack <Integer> ();

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
		if(myMap.get(a)==null)
		{
			myStack.add(a);
			return;
		}
		for(Integer myVal : myMap.get(a))
		{
			if(myArray[myVal]>=0 || myArray[myVal]==-2)
			{
				if(!myStack.contains(myVal))
				{
					System.out.println("Cycle exists at "+ myVal +" , can't create topological order");
					cycle=true;
				}				//System.out.println("Returning because "+ myVal + " already checked");
			}
			else
			{
				myArray[myVal]=a;
				//System.out.println("Calling dfs for "+myVal+ " with myArray value set as "+a);
				dfs(myVal);
			}
		}
		myStack.add(a);
	}
	
	void IterateTopo()
	{
		Iterator <Integer> myStackIt =myStack.iterator();
		while(myStackIt.hasNext())
		{
			System.out.println(myStackIt.next());
		}
	}
	
	Graph Invert()
	{
		Map<Integer, Set<Integer>> myMap = new HashMap<Integer, Set<Integer>>();
		Graph myInvGraph = new Graph(myMap);
		for (Integer key : this.myMap.keySet())
		{
		    for(Integer myVal : this.myMap.get(key))
		    {
		    	if(myInvGraph.myMap.get(myVal)==null)
		    	{
		    		Set <Integer> myInvSet= new HashSet<Integer>();
					myInvSet.add(key);		
					myInvGraph.myMap.put(myVal, myInvSet);
		    	}
		    	else
				{
					myInvGraph.myMap.get(myVal).add(key);
				}
		    }
		}
		return myInvGraph;
	}
}
