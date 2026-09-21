import java.util.ArrayList;
class reverseLists{
	static class Node{
		int val;
		Node next;
		Node(int val){
			this.val = val;
			this.next = null;
		}
	}
	public static Node reverse(Node head){
		if(head == null || head.next == null){
			return head;
		}
		Node newHead = reverse(head.next);
		head.next.next = head;
		head.next = null;
		return newHead;
	}
	public static void main(String[] args){
		ArrayList<Node> list = new ArrayList<>();
		for(int i = 0;i < 5;i++){
			list.add(new Node(i));
		}
		for(int i = 0;i < list.size() - 1;i++){
			list.get(i).next = list.get(i+1);
		}
		Node head = list.get(0);
		Node temp = head;
		while(temp != null){
			System.out.print(temp.val+"->");
			temp = temp.next;
		}
		head = reverse(head);
		temp = head;
		System.out.println();
		while(temp != null){
			System.out.print(temp.val+"->");
			temp = temp.next;
		}
		System.out.println();

	}
}
