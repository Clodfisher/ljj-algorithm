package BinarySearchTree;

public class BinarySearchTree {
	public static class Node {
		private int data;
		private Node left;
		private Node right;
		
		public Node(int data) {
			this.data = data;
		}
	}
	
	private static Node tree;
	
	public Node find(int data) {
		Node p = tree;
		while (null != p) {
			if (p.data > data) {
				p = p.left;
			}else if (p.data < data) {
				p = p.right;
			}else {
				return p;
			}
		}
		return null;
	}
	
	public void insert(int data) {
		if (null == tree) {
			tree = new Node(data);
			return;
		}
		Node p = tree;
		while (null != p)
		{
			if (p.data > data) {
				if (null == p.left) {
					p.left = new Node(data);
					return;
				}
				p = p.left;
			}else if (p.data < data) {
				if (null == p.right) {
					p.right = new Node(data);
					return;
				}
				p = p.right;
			}
		}
	}
	
	public void inOrder(Node p) {
		if (null == p) return;
		
		inOrder(p.left);
		System.out.format("%d ", p.data);
		inOrder(p.right);
	}
	
	public void deleteTree(int data) {
		Node p = tree;
		Node pp = null;
		
		while (null != p && p.data != data) {
			pp = p;
			if (p.data > data) p = p.left;
			else p = p.right;
		}
		if (null == p) return;
		
		if ( null != p.left && null != p.right) {
			Node minPP = p;
			Node minP = p.right;
			while (null != minP.left)
			{
				minPP = minP;
				minP = minP.left;
			}
			p.data = minP.data;
			pp = minPP;
			p = minP;
		}
		
		Node child = null;
		if (null != p.left) child = p.left;
		else child = p.right;
		
		if (null == pp) 
		{
			tree = child;
			return;
		}
		
		if (p == pp.left) pp.left = child;
		else pp.right = child;	
	}
	
	public Node findMin() {
		if (null == tree) {return null;}
		Node p = tree;
		while (null != p.left) {
			p = p.left;
		}
		return p;
	}
	
	public Node findMax() {
		if (null == tree) {return null;}
		Node p = tree;
		while (null != p.right) {
			p = p.right;
		}
		return p;
	}
	
	public static void main(String[] args)
	{
		BinarySearchTree searchtree = new BinarySearchTree();
		int[] arr = {2,4,6,9,8,10};
		for (int i =0; i < arr.length; i++) {
			searchtree.insert(arr[i]);
		}
		searchtree.inOrder(tree);
		System.out.println();
	
		for (int i = 0; i < arr.length; i++)
		{
			searchtree.deleteTree(arr[i]);
			searchtree.inOrder(tree);
			System.out.println();
		}
	}
	
}
