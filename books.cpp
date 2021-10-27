#include<iostream>

#include<vector>
#include<array>
using namespace std;
#define N 6
class Book
{
public:
	Book() = default;
	Book(std::string name, std::string author,int year, std::string publish,  int price ) :
		name(name), author(author), year(year), publish(publish), price(price) {}
	int getPrice() const { return price; }
	std::string name;
	std::string author;
	int year=0;
	std::string publish;
	int price=0;
};

class Node
{
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
	void Insert(Node*& r, Node* newNode);
	void InorderTraversal() const;
	void ShowRecords( const Node* r) const;
	void FindRecord(const Node* r, int key) const;
	void DeleteRecord(const Node* r, int key) const;
	void FindbyKey() const;
private:
	Node* root;
	void InorderTraversal(const Node* r) const;
};


BinaryTreeBook::BinaryTreeBook() : root(nullptr) {}



void BinaryTreeBook::Insert(Book& thisBook) {
	Node* newNode = new Node;
	newNode->data = &thisBook;
	Insert(root, newNode);
}
void BinaryTreeBook::Insert(Node*& r, Node* newNode)
{
	if (r == nullptr)
		r = newNode;
	else if (r->data->getPrice() < newNode->data->getPrice())
		Insert(r->left, newNode);
	else
		Insert(r->right, newNode);
}


void BinaryTreeBook::ShowRecords(const Node* r) const
{
	cout << r->data->name <<" " << r->data->author << " " << r->data->year <<" "<< r->data->publish << " " << r->data->getPrice() << "\n";
}
void  BinaryTreeBook::FindRecord(const Node* r, int key) const
{
	if (r == nullptr)
	{
		cout << "Key not found";
		return;
	}
	if (r->data->getPrice() == key)
	{
		cout << "\n Record found: ";
		ShowRecords(r);
	}

	if (r->data->getPrice() < key)
	{
		FindRecord(r->left, key);
	}
	else if (r->data->getPrice() > key)
	{
		FindRecord(r->right, key);
	}
}
void  BinaryTreeBook::DeleteRecord(const Node* r, int key) const
{
	if (r == nullptr)
	{
		cout << "Key not found";
		return;
	}
	if (r->data->getPrice() < key)
	{
		DeleteRecord(r->left, key);
	}
	else if (r->data->getPrice() > key)
	{
		DeleteRecord(r->right, key);
	}else
	if (r->data->getPrice() == key)
	{
		cout << "\n Record found: ";
		ShowRecords(r);
		if (r->left == nullptr && r->right == nullptr)// if a leaf node
		{
			r = NULL;
		}
	}

}
void  BinaryTreeBook::FindbyKey() const
{
	int key;
	std::cout << " Enter key(price): ";
	std::cin >> key;
	FindRecord(root, key);
	DeleteRecord(root, 170);
}

void BinaryTreeBook::InorderTraversal() const {
	if (root == nullptr)
		cerr << "There is no record";
	else
		InorderTraversal(root);
}
void BinaryTreeBook::InorderTraversal(const Node* r) const
{
	if (r != nullptr) {
		InorderTraversal(r->left);
		ShowRecords(r);
		InorderTraversal(r->right);
	}
}

void addRecord()
{
	BinaryTreeBook info;
	std::string name1, author1, publish1;
	int year1, price1;
	cout << " Enter name:";
	cin >> name1;
	cout << " Enter author's name:";
	cin >> author1;
	cout << " Enter year of publishment:";
	cin >> year1;
	cout << " Enter publishing house:";
	cin >> publish1;
	cout << " Enter price:";
	cin >> price1;
	Book bookRec(name1, author1, year1, publish1, price1);
	info.Insert(bookRec);
}

int main()
{
	BinaryTreeBook info;
	Book rec;
	Book bookRec("Traceback", "Kevin", 2003, "Jills", 250);
	Book bookRec1("Rodeo", "Mike", 2000, "Greats", 200);
	Book bookRec2("Mystery", "Gary", 2010, "Linderson", 150);
	Book bookRec3("Jellybeans", "Stacy", 2011, "Heroes", 170);
	Book bookRec4("Blinds", "Aaron", 2013, "Camera", 280);
	Book bookRec5("Ferry", "Leo", 2001, "Kingston", 210);
	info.Insert(bookRec);
	info.Insert(bookRec1);
	info.Insert(bookRec2);
	info.Insert(bookRec3);
	info.Insert(bookRec4);
	info.Insert(bookRec5);
	//std::string name1, author1, publish1;
	//int year1, price1;
	//cout << " Enter name:";
	//cin >> name1;
	//cout << " Enter author's name:";
	//cin >> author1;
	//cout << " Enter year of publishment:";
	//cin >> year1;
	//cout << " Enter publishing house:";
	//cin >> publish1;
	//cout << " Enter price:";
	//cin >> price1;
	//Book bookRecNew(name1, author1, year1, publish1, price1);
	//info.Insert(bookRecNew);
	//addRecord();
	info.InorderTraversal();
	info.FindbyKey();
	info.InorderTraversal();
	return 0;
}
