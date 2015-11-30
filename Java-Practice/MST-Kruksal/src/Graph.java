import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class Graph 
{
	Map<Integer, Set<Edge>> myMap = new HashMap <Integer, Set<Edge>>();
	void Insert(int v, int w, double weight)
	{
		Edge myEdge = new Edge(v, w, weight);
		if(myMap.get(v)==null)
		{
			Set<Edge> mySet = new HashSet();
			mySet.add(myEdge);
			myMap.put(v, mySet);			
		}
		else
		{
			myMap.get(v).add(myEdge);
		}
		if(myMap.get(w)==null)
		{
			Set<Edge> mySet = new HashSet();
			mySet.add(myEdge);
			myMap.put(w, mySet);			
		}
		else
		{
			myMap.get(w).add(myEdge);
		}
	}
}
