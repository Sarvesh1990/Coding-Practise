import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.HashMap;
import java.util.Queue;
import java.util.Set;

public class Graph 
{
	Map<Integer, Set<Integer> > myMap;
	boolean isQueueInit = false;
	int[] myEdge = {-2, -1, -1, -1, -1, -1, -1};
	int[] myDist = {0, 0, 0, 0, 0, 0, 0};

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
	
	
	Queue<Integer> myQueue = new LinkedList <Integer>();
	void initializeQueue(int a)
	{
		myQueue.add(a);
	}
	
	void bfs (int a)
	{
		if(!isQueueInit)
		{
			initializeQueue(a);
			isQueueInit=true;
		}
		while(!myQueue.isEmpty())
		{
			for(Integer myInt : myMap.get(a))
			{
				if(myEdge[myInt]>=0 || myEdge[myInt]==-2)
					continue;
				myQueue.add(myInt);
				myEdge[myInt]=a;
				myDist[myInt]=myDist[a]+1;
			}
			myQueue.remove();
			if(!myQueue.isEmpty())
			{
				bfs(myQueue.peek());
			}			
		}
	}
	
	void PathTo(int a)
	{
		if(myEdge[a]>=0)
		{
			System.out.println(myEdge[a]);
			PathTo(myEdge[a]);
		}
	}
}
