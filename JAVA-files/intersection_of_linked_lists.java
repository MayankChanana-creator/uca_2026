class intersection_of_linked_lists{
	static class Node{
		int val;
		Node next;
		Node(int val){
			this.val = val;
			this.next = null;
		}
	}
	public static Node intersection(Node head1,Node head2){
		Node p1 = head1;
		Node p2 = head2;
		Node dummy = new Node(0);
		Node tail = dummy;
		while(p1 != null && p2 != null){
			if(p1.val < p2.val){
				p1 = p1.next;
			}
			else if(p1.val > p2.val){
				p2 = p2.next;
			}
			else{
				tail.next = new Node(p1.val);
				tail = tail.next;
				p1 = p1.next;
				p2 = p2.next;
			}
		}
		return dummy.next;
	}
	public static void main(String[] args){
		Node head1 = new Node(1);
		head1.next = new Node(2);
		head1.next.next = new Node(3);
		head1.next.next.next = new Node(4);
		head1.next.next.next.next = new Node(6);
		Node head2 = new Node(2);
		head2.next = new Node(4);
		head2.next.next = new Node(6);
		head2.next.next.next = new Node(8);
		Node result = intersection(head1,head2);
		while(result != null){
			if(result.next != null){
				System.out.print(result.val+" -> ");
			}
			else{
				System.out.print(result.val);
			}
			result = result.next;
		}
		System.out.println();
	}
}
