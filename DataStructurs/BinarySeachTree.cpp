#include<iostream>

using namespace std;

struct node {
	int data;
	int index;
	node *left, *right;
	node () {
		data = 0;
		index = 1;
		left = right = NULL;
	}
};

class BST {
	private:
		node *root;
		int tree_size;
	public:
		BST() {
			tree_size = 0;
			root = new node();
		}

		int search (node *subroot, int value) {
			if (value == subroot->data)
				return subroot->index;
			else if (value > subroot->data) {
				if (subroot->right == NULL) return -1;
				search (subroot->right, value);
			}
			else if(value < subroot->data) {
				if (subroot->left == NULL) return -1;
				search (subroot->left, value);
			}
		}

		bool insert(int value) {
			if (tree_size == 0) {
				root->data = value;
				tree_size ++;
				return true;
			}
			if (search(root, value) != -1) return false;
			tree_size++;
			return insert_node(root, value);
		}
		
		bool insert_node (node *subroot, int value) {
		       if (value > subroot->data)
	     			if (subroot->right == NULL) {
					subroot->right = new node();
					subroot->right->data = value;
					subroot->right->index = subroot->index  * 2 + 1;
					return true;
				}
	       			else insert_node(subroot->right, value);
			else if (value < subroot->data)
		 		if (subroot->left == NULL) {
					subroot->left = new node();
					subroot->left->data = value;
					subroot->left->index = subroot->index * 2;
					return true;
				}
				else insert_node(subroot->left, value);		

		}
		node* get_root() {return root;}
		int get_size() {return tree_size;}
		void inorder (node *subroot) {
			if (subroot == NULL) return;
			inorder (subroot->left);
			cout << subroot->data << ' ';
			inorder (subroot->right);
		}

};

int main () {
	BST *mytree = new BST();
	mytree->insert(5);
	mytree->insert(6);
	mytree->insert(3);
	cout << mytree->get_size() << endl;
	node *root = mytree->get_root();
	cout << root->data  << endl;
	mytree->inorder(root);
	return 0;	
}
	
