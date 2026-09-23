class search_in_linked_lists{
	static class Node{
		int val;
		Node next;
		Node(int val){
			this.val = val;
		}
	}
	public static boolean isPresent(Node head1,Node head2){
		if(head1 == null){
			return true;
		}
		Node curr2 = head2;
		while(curr2 != null){
			Node p1 = head1;
			Node p2 = curr2;
			while(p1 != null && p2 != null && p1.val == p2.val){
				p1 = p1.next;
				p2 = p2.next;
			}
			if(p1 == null){
				return true;
			}
			curr2 = curr2.next;
		}
		return false;
	}
	public static void main(String[] args){
		Node head1 = new Node(1);
		head1.next = new Node(2);
		head1.next.next = new Node(3);
		head1.next.next.next = new Node(4);
		Node head2 = new Node(1);
		head2.next = new Node(2);
		head2.next.next = new Node(2);
		head2.next.next.next = new Node(1);
		head2.next.next.next.next = new Node(2);
		head2.next.next.next.next.next = new Node(3);
		boolean found = isPresent(head1,head2);
		if(found){
			System.out.println("Yes");
		}
		else{
			System.out.println("No");
		}
	}
}
