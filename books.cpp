#include<iostream>
#include<queue>
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
	void Insert(Node*& r, Node* newNode);
	void InorderTraversal() const;
	void ShowRecords( const Node* r) const;
	void FindRecord() const;
	void DeleteRecord(const Node* r, int key)const;
	void FindbyKey(const Node* r, int key) const;
	void Deallocate(const Node* r)const;
	void deletDeepest(struct Node* root, struct Node* d_node)const;
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
void  BinaryTreeBook::FindbyKey(const Node* r, int key) const
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
		FindbyKey(r->left, key);
	}
	else if (r->data->getPrice() > key)
	{
		FindbyKey(r->right, key);
	}
}
void BinaryTreeBook::Deallocate(const Node* r) const
{
	if (r == NULL)
		return;
	Deallocate(r->right);
	Deallocate(r->left);

	free(r->data);
}
void BinaryTreeBook::deletDeepest(struct Node* root,struct Node* r)const
{
	queue<Node*> q;
	q.push(root);
	Node* temp = r;
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		if (temp == r)
		{
			temp = NULL;
			delete(r);
			return;
		}
		if (temp->right)
		{
			if (temp->right == r)
			{
				temp->right = NULL;
				delete(r);
				return;
			}
			else
				q.push(temp->right);
		}

		if (temp->left)
		{
			if (temp->left == r)
			{
				temp->left = NULL;
				delete(r);
				return;
			}
			else
				q.push(temp->left);
		}
	}
}

void  BinaryTreeBook::DeleteRecord(const Node* r, int key) const
{
	/*if (r == nullptr)
	{
		cout << "Book not found";
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
		if (r->left == nullptr && r->right == nullptr)
		{
			r == nullptr;
			Deallocate(r);
		}
	}*/
	queue<struct Node*> q;
	q.push(root);

	Node* temp = NULL;
	Node* key_node = NULL;
	while (!q.empty())
	{
		temp = q.front();
		q.pop();

		if (temp->data->getPrice() == key)
			key_node = temp;

		if (temp->left)
			q.push(temp->left);

		if (temp->right)
			q.push(temp->right);
	}
	//deletDeepest(root, temp);
	//int x = temp->data->getPrice();
	deletDeepest(root, temp);
	//key_node->data->getPrice() == x;
}

void  BinaryTreeBook::FindRecord() const
{
	int key;
	std::cout << " Enter key(price): ";
	std::cin >> key;
	FindbyKey(root, key);
	std::cin >> key;
	DeleteRecord(root, key);
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
	Book bookRec3("Jellybeans", "Stacy", 2011, "Heroes", 380);
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
	info.FindRecord();
	info.InorderTraversal();
	return 0;
}
