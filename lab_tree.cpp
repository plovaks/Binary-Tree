#include <iostream>
using namespace std;


struct Node
{
	int inf;
	Node* left;
	Node* right;
};
class BinaryTree
{
private:
	Node* root;
	int maxlength;
	Node* createnode(int data)
	{
		Node* newnode = new Node;
		newnode->inf = data;
		newnode->left = nullptr;
		newnode->right = nullptr;
		return newnode;
	}
	Node* insertnode(Node* node, int data)
	{
		if (node == nullptr)
		{
			return createnode(data);
		}
		if (data < node->inf)
		{
			node->left = insertnode(node->left, data);
		}
		else if (data > node->inf)
		{
			node->right = insertnode(node->right, data);
		}
		return node;
	}
	void mirror(Node* node)
	{
		if (node == nullptr)
		{
			return;
		}
		mirror(node->left);
		mirror(node->right);
		Node* temp = node->left;
		node->left = node->right;
		node->right = temp;
	}
	void findmaxelement(Node* node, int pathlength) {
		if (node == nullptr)
		{
			return;
		}
		pathlength++;
		if (pathlength > maxlength)
		{
			maxlength = pathlength;
		}
		findmaxelement(node->left, pathlength);
		findmaxelement(node->right, pathlength);
	}
public:
	BinaryTree()
	{
		root = nullptr;
		maxlength = 0;
	}
	void insert(int data)
	{
		root = insertnode(root, data);
	}
	int findmaxlengthandmirror()
	{
		mirror(root);
		findmaxelement(root, 0);
		mirror(root);
		return maxlength;
	}

};
int main()
{
	BinaryTree tree;
	int data;

	cout << "Введите данные для вставки в дерево (для завершения введите -1): ";

	while (true)
	{
		cin >> data;

		if (data == -1)
			break;

		tree.insert(data);
	}

	int maxLength = tree.findmaxlengthandmirror();

	cout << "Максимальная длина пути: " << maxLength << endl;

	return 0;
}