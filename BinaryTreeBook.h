#pragma once
#include "Book.h"
struct Node
{
private:
	friend class BinaryTreeBook;
	Book* data;
	Node* left;
	Node* right;
public:
	Node() : data(data), right(nullptr), left(nullptr) {}
	~Node() {}
};

class BinaryTreeBook
{
public:
	friend class Book;
	BinaryTreeBook();
	void Insert(Book& data);
	void Insert(Node*& rt, Node* newNode);
	void InorderTraversal();
	void ShowRecords(const Node* rt);
	void find();
	void FindbyKey(Node* rt, int key);
	void FindbyPublish(Node* rt, std::string publ);
	void DeleteTree(Node* root);
	void DelbyAuthor(const Node* rt, std::string auth);
	Node* DeleteRecord(Node* root, int key)const;
	void del();
private:
	Node* root;
	void InorderTraversal(Node* rt);
};
