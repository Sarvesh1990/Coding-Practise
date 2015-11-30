public class SymbolTable {
	LinkedList[] myArray = new LinkedList[5];
	public void insert(String field, String person)
	{
		int i= (field.hashCode() & 0x7fffffff)% myArray.length;
		System.out.println("Hash code is " + i);
		if(myArray[i] == null)
		{
			LinkedList node = new LinkedList();
			node.field=field;
			node.persons.add(person);
			myArray[i]=node;
		}
		else
		{
			LinkedList head=myArray[i];
			while(head.next!=null)
			{
				if(head.field.equals(field))
				{
					head.persons.add(person);
					break;
				}
				else
				{
					head=head.next;
				}
			}
			if(head.field.equals(field))
			{
				head.persons.add(person);
			}
			else
			{
				LinkedList node = new LinkedList();
				node.field=field;
				node.persons.add(person);
				head.next=node;
			}		
		}
	}
	
	public void search (String field)
	{
		int i= (field.hashCode() & 0x7fffffff)% myArray.length;
		LinkedList head = myArray[i];
		boolean flag = false;
		while(head!=null)
		{
			if(head.field.equals(field))
			{
				for(String s : head.persons)
				{
					System.out.println(s);
					flag=true;
				}
				break;
			}
			else
			{
				head=head.next;
			}
		}
		if(!flag)
		{
			System.out.println("Search miss");
		}
	}
}
