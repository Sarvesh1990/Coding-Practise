public class main 
{
	public static void main(String[] args) 
	{
		PrQueue myPrQueue = new PrQueue ();
		Graph myGraph = new Graph();
		MSTree myMSTree = new MSTree();
		myGraph.Insert(0, 7, 0.16);
		myGraph.Insert(0, 2, 0.89);
		myGraph.Insert(0, 4, 0.38);
		myGraph.Insert(1, 3, 0.29);
		myGraph.Insert(1, 7, 0.19);
		myGraph.Insert(1, 5, 0.32);
		myGraph.Insert(1, 2, 0.36);
		myGraph.Insert(2, 3, 0.17);
		myGraph.Insert(2, 7, 0.34);
		myGraph.Insert(3, 6, 0.52);
		myGraph.Insert(4, 5, 0.35);
		myGraph.Insert(4, 7, 0.37);
		myGraph.Insert(5, 7, 0.28);
		myGraph.Insert(6, 2, 0.40);
		myGraph.Insert(6, 0, 0.58);
		myGraph.Insert(6, 4, 0.93);
		myPrQueue.Initialize(myGraph.myMap);
		myPrQueue.CreateMST(myMSTree);
		myMSTree.ShowMST();
	}
}
