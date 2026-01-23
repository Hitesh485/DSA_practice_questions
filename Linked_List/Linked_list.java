public class Linked_list
{
    public static class Node
    {
        int data;
        Node next;

        Node(int data)
        {
            this.data = data;
            this.next = null;
        }
    }

    static void print(Node first)
    {
        Node temp = first;

        while (temp != null)
        {
            System.out.print(temp.data+ " ");
            temp = temp.next;
        }
        System.out.print("\n");
    }

    public static void main(String[] args)
    {
        Node first = new Node(10);
        Node second = new Node(20);
        Node third = new Node(30);
        Node fourth = new Node(40);

        first.next = second;
        second.next = third;
        third.next = fourth;

        print(first);


    }
}