public class ReverseLinkedList {
	public static void main(String[] args) {
		int[] listElements = {10,12,4,18,5};
		LinkedList head = generateLinkedList(listElements);
		LinkedList reverseListHead = reverseLinkedList(head);
		System.out.println(reverseListHead.next.value);
		// TODO Auto-generated method stub
	}
	
	public static LinkedList generateLinkedList(int[] listElements){
		LinkedList list = new LinkedList(listElements[0]);
		LinkedList head = list;
		for(int i=1; i<listElements.length; i++){
			LinkedList next = new LinkedList(listElements[i]);
			list.next = next;
			list = next;
		}
		return head;
	}
	
	public static LinkedList reverseLinkedList(LinkedList actualList){
		LinkedList prev = null;
		LinkedList current = actualList;
		while(current != null){
			LinkedList temp = current.next;
			current.next = prev;
			prev = current;
			current = temp;
		}
		return prev;
	}
}
