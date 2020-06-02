#include <iostream>

using namespace std;
struct BstNode {
	int data;
	BstNode* left;  //ADDRESS OF LEFT CHILD
	BstNode* right; //ADDRESS OF  RIGHT CHILD
};
BstNode* root = NULL;
 
BstNode* rootPtr; //TO STORE ADDRESS OF ROOT

BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

BstNode* Insert(BstNode* root, int data) {		//ADDRESS OF ROOT AND DATA TO INSERT
	if (root == NULL) {
		root = GetNewNode(data);

	}
	else if (data <= root->data) {
		root->left=Insert(root->left, data);
	}
	else {
		root->right=Insert(root->right, data);
	}
	return root;
}
bool Search(BstNode* root, int data) {
	if (root == NULL) return false;
	else if (root->data == data) return true;
	else if (data <= root->data) return Search(root->left, data);
	else return Search(root->right, data);
}


int main() {
	BstNode* root = NULL; //CREATING EMPTY TREE
	root = Insert(root, 15);root = Insert(root, 10);root = Insert(root, 20);
	root = Insert(root, 25);root = Insert(root, 8);root = Insert(root, 12);
	int number;
	cout << "Enter number: \n";
	cin >> number;
	if (Search(root, number) == true) cout << "Found\n";
	else cout << "Not Found\n";
}
