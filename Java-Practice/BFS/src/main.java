import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class main
{
	public static void main(String[] args)
	{
		Map<Integer, Set<Integer>> myMap = new HashMap<Integer, Set<Integer>>();
		Graph myGraph = new Graph(myMap);
		myGraph.Insert(0,1);
		myGraph.Insert(0,2);
		myGraph.Insert(1,0);
		myGraph.Insert(2,0);
		myGraph.Insert(0,6);
		myGraph.Insert(0,5);
		myGraph.Insert(6,4);
		myGraph.Insert(4,3);
		myGraph.Insert(4,5);
		myGraph.Insert(5,3);
		myGraph.Insert(5,4);
		myGraph.Insert(5,0);
		myGraph.Insert(6,0);
		myGraph.Insert(4,6);
		myGraph.Insert(3,4);
		myGraph.Insert(3,5);
		myGraph.bfs(0);
		myGraph.PathTo(6); //Will show shortest path from 6 to 0 in reverse order
	}
}
