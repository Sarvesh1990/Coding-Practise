import java.util.Comparator;
import java.util.Map;
import java.util.Map.Entry;
import java.util.PriorityQueue;
import java.util.Set;

import javax.swing.text.html.HTMLDocument.Iterator;

public class PrQueue 
{
	PriorityQueue<Edge> myQueue = new PriorityQueue<Edge>();
	
	void Initialize(Map<Integer, Set<Edge>> myMap)
	{
		for(Map.Entry<Integer, Set<Edge>> entry : myMap.entrySet())
		{
			for(Edge myEdge : myMap.get(entry.getKey()))
			{
				if(!myQueue.contains(myEdge))
					myQueue.add(myEdge);
			}
		}
	}
	
	void CreateMST(MSTree myMSTree)
	{
		while(myMSTree.mySet.size()!=7)
		{
			Edge myEdge = myQueue.poll();
			if(!myMSTree.CreatesCyclic(myEdge))
			{
				myMSTree.mySet.add(myEdge);
				System.out.println("Adding edge with weight "+ myEdge.weight);
			}
		}
	}	
}