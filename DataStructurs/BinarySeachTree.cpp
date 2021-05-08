#include<iostream>

using namespace std;

/*
	Disc: a struct to hold binary tree nodes
	left=> left child
	right=> right child
	data=> an integet ro hold node's data
	*/
struct Node {
	int	data;
	int index;
	Node *Left, *Right;
	Node () {
		data = 0;
		index = 1;
		Left = Right = NULL;
	}
};

class BST {
	private:
		Node *root;
		int tree_size;
	public:
		BST() {
			tree_size = 0;
			root = new Node();
		}
		
		Node* search (Node *node, int value) {
			if (value == node->data)
				return node;
			else if (value > node->data) {
				if (node->Right == NULL) return NULL;
				return search (node->Right, value);
			}
			else if(value < node->data) {
				if (node->Left == NULL) return NULL;
				return search (node->Left, value);
			}
		}

		bool insert(int value) {
			if (tree_size == 0) {
				root->data = value;
				tree_size ++;
				return true;
			}
			if (search(root, value) != NULL) return false;
			tree_size++;
			return insert_Node(root, value);
		}
		
		bool insert_Node (Node *node, int value) {
		       if (value > node->data) {
	     			if (node->Right == NULL) {
						node->Right = new Node();
						node->Right->data = value;
						node->Right->index = node->index  * 2 + 1;
						return true;
				}
	       			else return insert_Node(node->Right, value);
			   	}
			else if (value < node->data) {
		 		if (node->Left == NULL) {
						node->Left = new Node();
						node->Left->data = value;
						node->Left->index = node->index * 2;
						return true;
				}
				else return insert_Node(node->Left, value);
			}		

		}
		
		bool is_leaf (Node *v) {
			return (v->Left == NULL && v->Right == NULL);
		}
		Node *extract_min (Node *v) {
			while (v->Left != NULL)
				v = v->Left;
			return v;
		}
		Node* remove (Node *node, int value) {
			if (node == NULL) return node;
			if (value < node->data)
				node->Left = remove(node->Left, value);
			else if (value > node->data)
				node->Right = remove(node->Right, value);
			else {
				if (is_leaf(node)) return NULL;
				else if (node->Left == NULL) {
					Node* v = node->Right;
					delete node;
					tree_size--;
					return v;
				}
				else if(node->Right == NULL) {
					Node *v = node->Left;
					delete node;
					tree_size--;
					return v;
				}

				Node *v = extract_min(node);
				node->data = v->data;
				node->Right = remove(node->Right, v->data);
			}
			return node;
			
		}

		Node* get_root() {return root;}
		int get_size() {return tree_size;}
		void inorder (Node *node) {
			if (node == NULL) return;
			inorder (node->Left);
			cout << node->data << ' ';
			inorder (node->Right);
		}

};

int main () {
	BST *T = new BST();
	T->insert(12);
	T->insert(20);
	T->insert(10);
	T->insert(50);
	T->insert(15);
	T->insert(8);
	T->insert(9);
	T->insert(11);
	T->insert(100);
	Node *root = T->get_root();
	cout << "Root of the tree: "  << root->data << endl;
	cout << "Size of the tree: " << T->get_size() << endl;
	cout << "Inorder travel: ";
	T->inorder(root);
	cout << endl;
	T->remove(root, 10);
	T->remove(root, 12);
	root = T->get_root();
	cout << "Inorder travel: ";
	T->inorder(root);
	cout << endl;
	return 0;	
}
	
