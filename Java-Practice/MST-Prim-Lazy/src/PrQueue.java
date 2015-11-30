import java.util.Comparator;
import java.util.Map;
import java.util.Map.Entry;
import java.util.PriorityQueue;
import java.util.Set;

import javax.swing.text.html.HTMLDocument.Iterator;

public class PrQueue 
{
	PriorityQueue<Edge> myQueue = new PriorityQueue<Edge>();
	int[] myArray = {-1, -1, -1, -1, -1, -1, -1, -1};
	
	void CreateMST(MSTree myMSTree, int index, Map<Integer, Set<Edge> > myMap)
	{
		while(myMSTree.mySet.size()!=7)
		{
			for(Edge myEdge : myMap.get(index))
			{
				if(myArray[myEdge.Other(index)]==-1)
				{
					
					if(!myQueue.contains(myEdge))
					{
						myQueue.add(myEdge);
						//System.out.println("For index " + index + " Adding "+myEdge.Other(index));
					}
				}
				myArray[index]=1;
			}
			Edge myEdge = myQueue.poll();
			while(myArray[myEdge.Either()]==1 && myArray[myEdge.Other(myEdge.Either())]==1)
			{
				myEdge = myQueue.poll();
			}
			myMSTree.mySet.add(myEdge);
			//System.out.println("Adding edge with weight "+ myEdge.weight);
			//System.out.println("For index "+myEdge.Either() +" other index is "+ myEdge.Other(myEdge.Either()));
			if(myArray[myEdge.Either()]==1)
				index = myEdge.Other(myEdge.Either());
			else
				index=myEdge.Either();
		}
	}	
}