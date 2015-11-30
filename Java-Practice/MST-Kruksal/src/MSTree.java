import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;
public class MSTree 
{
	int[] myArray = {-1, -1, -1, -1, -1, -1, -1, -1};
	Set<Edge> mySet = new HashSet <Edge>();
	
	boolean CreatesCyclic(Edge myEdge)
	{
		if(getRoot(myEdge.Either())==getRoot(myEdge.Other(myEdge.Either())))
		{
			return true;
		}
		else
		{
			//System.out.println("First root is "+getRoot(myEdge.Either())+" and second is "+getRoot(myEdge.Other(myEdge.Either())));
			myArray[getRoot(myEdge.Either())]=getRoot(myEdge.Other(myEdge.Either()));
			//System.out.println("For key 7 root is "+getRoot(7));
			//System.out.println("For key "+myEdge.Either()+" root is "+getRoot(myEdge.Either()));
			return false;
		}
	}
	
	int getRoot(int a)
	{
		if(myArray[a]>=0)
		{
			//System.out.println("For key "+a+" array is "+myArray[a]);
			a=getRoot(myArray[a]);
		}
		return a;
	}
	
	void ShowMST()
	{
		System.out.print("MST edges are ");
		for(Edge myEdge : mySet)
		{
			System.out.print(myEdge.Either()+"->"+myEdge.Other(myEdge.Either())+" with weight "+myEdge.weight+" ");
		}
	}
	
}
