#include<iostream>
#include "BinaryTreeBook.h"

BinaryTreeBook::BinaryTreeBook() : root(nullptr) {}

void BinaryTreeBook::Insert(Book& thisBook) {
	Node* newNode = new Node;
	newNode->data = &thisBook;
	Insert(root, newNode);
}

void BinaryTreeBook::Insert(Node*& rt, Node* newNode)
{
	if (rt == nullptr)
		rt = newNode;
	else if (rt->data->price > newNode->data->price)
		Insert(rt->left, newNode);
	else
		Insert(rt->right, newNode);
}


void BinaryTreeBook::ShowRecords(const Node* rt)
{
	std::cout << rt->data->name << " " << rt->data->author << " " << rt->data->year << " " << rt->data->publish << " " << rt->data->price << "\n";
}

void BinaryTreeBook::InorderTraversal() {
	if (root == nullptr)
		std::cout << "There is no record";
	else
		InorderTraversal(root);
}
void BinaryTreeBook::InorderTraversal(Node* rt)
{
	if (rt != nullptr) {
		InorderTraversal(rt->left);
		ShowRecords(rt);
		InorderTraversal(rt->right);
	}
}
Node* BinaryTreeBook::DeleteRecord(Node* rt, int key) const
{
	if (rt == NULL)
		return rt;
	if (key == rt->data->price)
	{
		Node* temp;
		if (rt->right == NULL)
			temp = rt->left;
		else {
			Node* ptr = rt->right;
			if (rt->left == NULL)
			{
				ptr->left = rt->left;
				temp = ptr;
			}
			else
			{
				Node* ptrmin = ptr->left;
				while (ptrmin != NULL)
				{
					ptr = ptrmin;
					ptrmin = ptr->left;
				}
				ptr->left = ptrmin->right;
				ptrmin->left = rt->left;
				ptrmin->right = rt->right;
				temp = ptrmin;
			}
		}

		delete rt;
		return temp;
	}
	else if (key < rt->data->price)
		rt->left = DeleteRecord(rt->left, key);
	else
		rt->right = DeleteRecord(rt->right, key);
	return rt;
}

void BinaryTreeBook::FindbyKey(Node* rt, int key)
{
	if (rt == nullptr)
	{
		std::cout << "Key not found\n";
		return;
	}
	if (rt->data->price == key)
	{
		std::cout << "\n Records found:";
		ShowRecords(rt);
		std::cout << "\n";
	}

	if (rt->data->price > key)
	{
		FindbyKey(rt->left, key);
	}
	else if (rt->data->price < key)
	{
		FindbyKey(rt->right, key);
	}
}
void BinaryTreeBook::DelbyAuthor(const Node* rt, std::string auth)
{
	int key = 0;
	if (rt == nullptr)
		return;
	if (auth == rt->data->author)
	{
		std::cout << " Record to delete is:\n";
		ShowRecords(rt);
		key = rt->data->price;
		std::cout << "\n";
		DeleteRecord(root, key);
		return;
	}
	else
		DelbyAuthor(rt->left, auth);
	DelbyAuthor(rt->right, auth);



}
void BinaryTreeBook::FindbyPublish(Node* rt, std::string publ)
{
	int key = 0;
	if (rt == nullptr)
		return;
	if (publ == rt->data->publish)
	{
		std::cout << " Books by made by " << publ << " publishment are:";
		ShowRecords(rt);
		return;
	}
	else

		FindbyPublish(rt->left, publ);
	FindbyPublish(rt->right, publ);
}
void BinaryTreeBook::find()
{
	int c, key;
	std::string publ;
	std::cout << "_______Navigation bar_______\n Find menu:\n    1 - Show record by key(price)\n    2 - Show all records from publishment\n    3 - Back to menu\n  Your choice:";
	std::cin >> c;
	switch (c)
	{
	case 1:
		std::cout << " Enter key(price): ";
		std::cin >> key;
		FindbyKey(root, key);
		break;

	case 2:
		std::cout << " Enter name of publishment: ";
		std::cin >> publ;
		FindbyPublish(root, publ);
		break;
	case 3:
		break;

	}
}
void BinaryTreeBook::DeleteTree(Node* rt)
{
	if (!rt) return;
	DeleteTree(rt->left);
	DeleteTree(rt->right);
	delete rt;
	std::cout << "\nRecord is deleted";
	return;

}

void BinaryTreeBook::del()
{
	int c, key;
	char des;
	std::string toDelete;
	std::cout << "_______Navigation bar_______\n Delete menu:\n    1 - Delete record by key(price)\n    2 - Delete all records by author\n    3 - Delete all records\n    4 - Back to menu \n  Your choice:";
	std::cin >> c;
	switch (c)
	{
	case 1:
		std::cout << " Enter record price: ";
		std::cin >> key;
		DeleteRecord(root, key);
		break;

	case 2:
		std::cout << " Enter authors name to delete: ";
		std::cin >> toDelete;
		DelbyAuthor(root, toDelete);
		break;
	case 3:
		std::cout << " Are you sure you want to delete everything?(y/n)";
		std::cin >> des;
		if (des == 'y')
			DeleteTree(root);
		break;

	default:
		return;
	}
}