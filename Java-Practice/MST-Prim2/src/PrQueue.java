import java.util.Comparator;
import java.util.Map;
import java.util.Map.Entry;
import java.util.PriorityQueue;
import java.util.Set;

import javax.swing.text.html.HTMLDocument.Iterator;

public class PrQueue 
{
	PriorityQueue<Edge> myQueue = new PriorityQueue<Edge>();
	Edge[] myArray = {null, null, null, null, null, null, null, null};
	boolean[] myMarkArray = {false, false, false, false, false, false, false, false};
	
	void CreateMST(MSTree myMSTree, int index, Map<Integer, Set<Edge> > myMap)
	{
		myMarkArray[index]=true;
		while(myMSTree.mySet.size()!=7)
		{
			for(Edge myEdge : myMap.get(index))
			{
				if(myMarkArray[myEdge.Other(index)])
					continue;
				if(myArray[myEdge.Other(index)] == null)
				{
					System.out.println("Array null, adding "+myEdge.Other(index));
					myArray[myEdge.Other(index)]=myEdge;
					myQueue.add(myEdge);
				}
				else
				{
					if(myArray[myEdge.Other(index)].weight>myEdge.weight)
					{
						//System.out.println("Size smaller, updating "+myEdge.Other(index));
						myArray[myEdge.Other(index)]=myEdge;
						myQueue.remove(myArray[myEdge.Other(index)]);
						myQueue.add(myEdge);
					}
				}
			}
			Edge myEdge = myQueue.poll();
			while(myMarkArray[myEdge.Either()] && myMarkArray[myEdge.Other(myEdge.Either())])
				myEdge=myQueue.poll();
			if(myMarkArray[myEdge.Either()])
				index = myEdge.Other(myEdge.Either());
			else
				index = myEdge.Either();
			//System.out.println("Indexex are " + myEdge.Either()+" "+myEdge.Other(myEdge.Either())+" with index set as "+index);
			myMSTree.mySet.add(myEdge);
			myMarkArray[index]=true;
		}
	}	
}