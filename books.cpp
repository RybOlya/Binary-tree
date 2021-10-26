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
	/*Book addRecord();*/
//	
//private:
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
	void insert(Book& data);
	void insert(Node*& r, Node* newNode);
	void inorderTraversal() const;
	void showRecords( const Node* root) const;
private:
	Node* root;
	void inorderTraversal(const Node* r) const;
};


BinaryTreeBook::BinaryTreeBook() : root(nullptr) {}

void BinaryTreeBook::insert(Book& thisPacket) {
	Node* newNode = new Node;
	newNode->data = &thisPacket;
	insert(root, newNode);
}
void BinaryTreeBook::insert(Node*& r, Node* newNode)
{
	if (r == nullptr)
		r = newNode;
	else if (r->data->getPrice() < newNode->data->getPrice())
		insert(r->left, newNode);
	else
		insert(r->right, newNode);
}

void BinaryTreeBook::inorderTraversal() const {
	if (root == nullptr)
		cerr << "There is no tree.";
	else
	{
		inorderTraversal(root);
	}
}
void BinaryTreeBook::showRecords(const Node* r) const
{
	cout << r->data->name <<" " << r->data->author << " " << r->data->year <<" "<< r->data->publish << " " << r->data->getPrice() << "\n";
}
void BinaryTreeBook::inorderTraversal(const Node* r) const
{

	if (r == nullptr)
		cerr << "There is no tree.";
	else
	{
		if (root != nullptr) {
			inorderTraversal(r->left);
			showRecords(r);
			inorderTraversal(r->right);
		}
	}
		
}
Book addRecord()
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
	info.insert(bookRec);
	return bookRec;
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
	info.insert(bookRec);
	info.insert(bookRec1);
	info.insert(bookRec2);
	info.insert(bookRec3);
	info.insert(bookRec4);
	info.insert(bookRec5);
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
	//info.insert(bookRecNew);
	//info.insert(addRecord());
	info.inorderTraversal();
	return 0;
}
