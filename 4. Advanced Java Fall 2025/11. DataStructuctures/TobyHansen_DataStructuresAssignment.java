/*=========================================
| Toby Hansen, December 12 2025.          |
| Data Structures Assignment, CSC-285-201 |
| This program orders an unordered array  |
| and counts the leaves of a binary tree.  |
=========================================*/

package edu.bhcc.entrypoint;

import java.util.*;
import java.io.*;

public class DataStructuresAssignment {
	
	// This is the main function.
	public static void main(String[] args) {
        Random r = new Random();
		
		// The cwd and code banner is printed before the code is run.
		System.out.println(System.getProperty("user.dir")+"\n"
				+"/*=========================================\n"
				+"| Toby Hansen, December 12 2025.          |\n"
				+"| Data Structures Assignment, CSC-285-201 |\n"
				+"| This program orders an unordered array  |\n"
				+"| and counts the leaves of a binary tree.  |\n"
				+"=========================================*/\n");

		// This section prepares an unordered array with 10 random ints from 0-99.
        int[] intArray = new int[10];
        for (int i = 0; i < intArray.length; i++) { intArray[i] = r.nextInt(100); }
        System.out.print("Unordered Array: ");
        for (int i : intArray) { System.out.print(i + " "); }
        
        // This section orders and then prints the unordered array.
        int temp;
        for (int i = 0; i < intArray.length; i++) {
        	for (int j = 0; j < intArray.length - 1; j++) {
        		if (intArray[j] > intArray[j+1]) {
        			temp = intArray[j];
        			intArray[j] = intArray[j+1];
        			intArray[j+1] =  temp;
        		}
        	}
        }
        System.out.print("\n  Ordered Array: ");
        for (int i : intArray) { System.out.print(i + " "); }
        
    	// This section prepares a random binary tree of 8-15 nodes.
    	int newNodeCount = r.nextInt(8) + 8;
    	Set<Integer> hashTreeVals = new HashSet<>();
        while (hashTreeVals.size() < newNodeCount) { hashTreeVals.add(r.nextInt(100)); }
        List<Integer> treeVals = new ArrayList<>(hashTreeVals);
    	Node root = new Node(treeVals.get(0));
        for (int i = 1; i < newNodeCount; i++) { root = insert(root, treeVals.get(i)); }
        
        
        // This section displays the count of leaves in the generated binary tree.
        System.out.println("\n\nIn a tree with the following insert order:");
        for (int i : treeVals) { System.out.print(i + " "); }
        System.out.println("\nThere are a total of " + countLeaves(root) + " leaf nodes.");
	}
    
    // This recursive insert function is for building the binary tree.
    private static Node insert(Node currentNode, int val) {
        if (currentNode == null) { return new Node(val);
    	} else if (val < currentNode.data) { currentNode.left = insert(currentNode.left, val);
        } else if (val > currentNode.data) { currentNode.right = insert(currentNode.right, val); }
    	return currentNode;
    }
    
    // This recursive leaf counting function is for determining the amount of leaf nodes in the binary tree.
    public static int countLeaves(Node currentNode) {
        if (currentNode == null) { return 0; } // If there is no node, don't increment
        if (currentNode.left == null && currentNode.right == null) { return 1; } // If the node is a leaf, increment.
        return countLeaves(currentNode.left) + countLeaves(currentNode.right); // Return the left and right branches' sum.
    }
}

// POJO class for nodes.
class Node {
	int data;
    Node left, right;
    Node(int i) { 
    	data = i;
    	left = null;
    	right = null; 
    }
}