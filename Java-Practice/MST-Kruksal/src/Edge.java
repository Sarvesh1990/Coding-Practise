public class Edge implements Comparable <Edge> 
{
	double weight;
	int v;
	int w;
	Edge(int first, int second, double myWeight)
	{
		v=first;
		w=second;
		weight=myWeight;
	}
	int Either()
	{
		return v;
	}
	int Other (int a)
	{
		if(a==v)
			return w;
		else
			return v;
	}
	@Override
	public int compareTo(Edge myEdge)
	{
		 if((this.weight - myEdge.weight)>0)
			 return 1;
		 else if((this.weight - myEdge.weight)==0)
			 return 0;
		 else
			 return -1;
			 
	}
}
