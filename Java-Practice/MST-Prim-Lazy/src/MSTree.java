import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;
public class MSTree 
{
	Set<Edge> mySet = new HashSet <Edge>();
	void ShowMST()
	{
		System.out.print("MST edges are ");
		for(Edge myEdge : mySet)
		{
			System.out.print(myEdge.Either()+"->"+myEdge.Other(myEdge.Either())+" with weight "+myEdge.weight+" ");
		}
	}
}
