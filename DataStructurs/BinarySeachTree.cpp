#include<iostream>

struct node {
	int data;
	node *left, *right;
};

class BST {
	private:
		node root;
		int tree_size;
	public:
		node search (node *subtoor, int value) {
			if (value == subroot->data)
				return subroot;
			else if (value > subroot->data)
				if (subroot->right == NULL) return NULL;
				search (subroot->right, value);
			else if(value < subroot->data)
				if (subroot->left == NULL) return NULL;
				search (subroot->left, value);
		}
		bool insert(value) {
			if (search(*root, value)) return false;
			return insert_node(*root, value);
		}
		bool insert_node (node *subroot, int value) {
		       if (value > subroot->data)
	     			if (subroot->right == NULL) {
					subroot->right->data = value;
					return true;
				}
	       			else insert(subroot->right, value);
			else if (value < subroot->data)
		 		if (subroot->left == NULL) {
					subroot->left->data = value;
					return true;
				}		
		}

}
