#include<iostream>
#include<queue>
#include<vector>
#include<array>
using namespace std;
#define N 6
class Book
{
public:

	//Book() = default;
	//Book(std::string, std::string, int, std::string, int);
	Book(std::string name, std::string author,int year, std::string publish,  int price ) :
		name(name), author(author), year(year), publish(publish), price(price) {}
	int getPrice() const { return price; }
private:
	std::string name;
	std::string author;
	int year=0;
	std::string publish;
	int price=0;
};
class Node
{
	friend class BST;
	Book *data;
	Node* left;
	Node* right;
public:
	//Node(Book& data) {
	//	this->data = data;
	//	this->left = nullptr;
	//	this->right = nullptr;
	//}
public:
	Node() : data(data), right(nullptr), left(nullptr) {}
	~Node() {}

};

class BST {
public:
	BST();
	void insert(Book& data);
	void insert(Node*& p, Node* newNode);
	void preorderTraversal() const;
private:
	Node* root;
	void preorderTraversal(const Node* p) const;
	};
	BST::BST() : root(nullptr) {}
	void BST::insert(Book& thisPacket) {
		Node* newNode = new Node;
		newNode->data = &thisPacket;
		insert(root, newNode);
	}
	void BST::insert(Node*& p, Node* newNode)
	{
		if (p == nullptr)
			p = newNode;
		else if (p->data->getPrice() < newNode->data->getPrice())
			insert(p->left, newNode);
		else
			insert(p->right, newNode);
	}

	void BST::preorderTraversal() const {
		if (root == nullptr)
			cerr << "There is no tree.";
		else
		{
			preorderTraversal(root);
		}
	}

	void BST::preorderTraversal(const Node* p) const {
		if (root == nullptr)
			cerr << "There is no tree.";
		else
		{
			if (p != nullptr) {
				cout << p->data->getPrice() << " ";
				preorderTraversal(p->left);
				preorderTraversal(p->right);
			}
		}
		
	}
	int main()
	{
		BST test1;
		Book bookTest("Traceback", "Kevin", 2003, "Jills", 250);
		Book bookTest1("Rodeo", "Mike", 2000, "Greats", 200);
		Book bookTest2("Mystery", "Gary", 2010, "Linderson", 150);
		Book bookTest3("Jellybeans", "Stacy", 2011, "Heroes", 170);
		Book bookTest4("Blinds", "Aaron", 2013, "Camera", 280);
		Book bookTest5("Ferry", "Leo", 2001, "Kingston", 210);
		test1.insert(bookTest);
		test1.insert(bookTest1);
		test1.insert(bookTest2);
		test1.insert(bookTest3);
		test1.insert(bookTest4);
		test1.insert(bookTest5);
		test1.preorderTraversal();

		//cout << "Enter number be searched: ";
		//cin >> number;

		//if (search(root, number)) {
		//	cout << "Found !" << endl;
		//	Node* successor = getInorderSuccessor(root, number);
		//	cout << "Inorder successor of " << number << " is: " << successor->data << endl;
		//}
		//else cout << "Not Found !" << endl;
	}
