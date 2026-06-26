

import java.util.Scanner;

class Node {
    
    int data;
    Node left;
    Node right;


    public Node (int data)
    {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}


class BuildTree {

    // Build tree
    public static Node buildTree(Scanner sc) {

        System.out.print("Enter root node data: ");
        int data = sc.nextInt();
        if (data == -1) {
            return null;
        }

        Node root = new Node(data);

        System.out.println("Enter left node data: " + root.data);
        root.left = buildTree(sc);
        
        System.out.println("Enter right node data: " + root.data);
        root.right = buildTree(sc);

        return root;

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Node root = buildTree(sc);
        sc.close();
    }
}