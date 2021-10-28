#include<iostream>
#include<queue>
#include<vector>
#include<array>
#define N 6
class Book
{
public:
	Book() = default;
	Book(std::string name, std::string author, int year, std::string publish, int price) :
		name(name), author(author), year(year), publish(publish), price(price) {}
	std::string name;
	std::string author;
	int year = 0;
	std::string publish;
	int price = 0;
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
	void ShowRecords(const Node* r) const;
	void FindRecord() ;
	void FindbyAuthor(const Node* r, std::string auth);
	Node* DeleteRecord(Node* root, int key)const;
	void FindbyKey(const Node* r, int key) const;
	void FindbyPublish(const Node* r, std::string publ);
	void DeleteTree(const Node* root) const;
	void del();
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
	else if (r->data->price < newNode->data->price)
		Insert(r->left, newNode);
	else
		Insert(r->right, newNode);
}


void BinaryTreeBook::ShowRecords(const Node* r) const
{
	std::cout << r->data->name << " " << r->data->author << " " << r->data->year << " " << r->data->publish << " " << r->data->price << "\n";
}
void  BinaryTreeBook::FindbyKey(const Node* r, int key) const
{
	if (r == nullptr)
	{
		std::cout << "Key not found\n";
		return;
	}
	if (r->data->price == key)
	{
		std::cout << "\n Records found:";
		ShowRecords(r);
		std::cout << "\n";
	}

	if (r->data->price < key)
	{
		FindbyKey(r->left, key);
	}
	else if (r->data->price > key)
	{
		FindbyKey(r->right, key);
	}
}
void addRecord()
{
	BinaryTreeBook info;
	std::string name1, author1, publish1;
	int year1, price1;
	std::cout << " Enter name:";
	std::cin >> name1;
	std::cout << " Enter author's name:";
	std::cin >> author1;
	std::cout << " Enter year of publishment:";
	std::cin >> year1;
	std::cout << " Enter publishing house:";
	std::cin >> publish1;
	std::cout << " Enter price:";
	std::cin >> price1;
	Book bookRec(name1, author1, year1, publish1, price1);
	info.Insert(bookRec);
}
void  BinaryTreeBook::FindbyPublish(const Node* r, std::string publ)
{
	int key = 0;
	if (r == nullptr)
		return;
	if (publ == r->data->publish)
	{
		std::cout << " Books by made by "<< publ<<" publishment are:";
		ShowRecords(r);
		return;
	}
	else

	FindbyPublish(r->left, publ);
	FindbyPublish(r->right, publ);
}


void  BinaryTreeBook::DeleteTree(const Node* r) const
{
	if (!r) return;
	DeleteTree(r->left);
	DeleteTree(r->right);
	delete r;
	std::cout << "\nRecord is deleted";
	return;

}
void BinaryTreeBook::InorderTraversal() const {
	if (root == nullptr)
		std::cerr << "There is no record";
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
Node* BinaryTreeBook::DeleteRecord(Node* r, int key) const
{
	if (r == NULL)
		return r;
	if (key == r->data->price)
	{
		Node* temp;
		if (r->right == NULL)
			temp = r->left;
		else {
			Node* ptr = r->right;
			if (r->left == NULL)
			{
				ptr->left = r->left;
				temp = ptr;
			}
			else
			{
				Node* ptrmin = ptr->left;
				while (ptrmin->left != NULL)
				{
					ptr = ptrmin;
					ptrmin = ptr->left;
				}
				ptr->left = ptrmin->right;
				ptrmin->left = r->left;
				ptrmin->right = r->right;
				temp = ptrmin;
			}
		}
		delete r;
		return temp;
	}
	else if (key > r->data->price)
		r->left = DeleteRecord(r->left, key);
	else
		r->right = DeleteRecord(r->right, key);
	return r;
}

void  BinaryTreeBook::FindRecord()
{
	int key;
	std::string publ;
	std::cout << " Enter key(price): ";
	//std::cin >> key;
	FindbyKey(root, 210);
	//std::cin >> publ;
	FindbyPublish(root, "Jills");
}

void  BinaryTreeBook::FindbyAuthor(const Node* r, std::string auth)
{
	int key = 0;
	if (r == nullptr)
		return;
	if (auth == r->data->author)
	{
		std::cout << " Record to delete is:\n";
		ShowRecords(r);
		key = r->data->price;
		std::cout << "\n";
		DeleteRecord(root, key);
		return;
	}
	else
	
		FindbyAuthor(r->left, auth);
		FindbyAuthor(r->right, auth);
	
}
void  BinaryTreeBook::del()
{	
	std::string toDelete;
	std::cout << " Enter authors name to delete: ";
	std::cin >> toDelete;
	FindbyAuthor(root, toDelete);
	int key;
	std::cout << " Enter record you want to delete: ";
	std::cin >> key;
	DeleteRecord(root, key);

	InorderTraversal();
	//DeleteTree(root);
}
int main()
{
	BinaryTreeBook info;
	Book rec;
	Book bookRec("Traceback", "Kevin", 2003, "Huston", 250);
	Book bookRec1("Rodeo", "Mike", 2000, "Greats", 200);
	Book bookRec2("Mystery", "Leo", 2010, "Jills", 150);
	Book bookRec3("Jellybeans", "Stacy", 2011, "Jills", 180);
	Book bookRec4("Blinds", "Aaron", 2013, "Jills", 280);
	Book bookRec5("Ferry", "Leo", 2001, "Kingston", 210);
	info.Insert(bookRec);
	info.Insert(bookRec1);
	info.Insert(bookRec2);
	info.Insert(bookRec3);
	info.Insert(bookRec4);
	info.Insert(bookRec5);
	std::string name1, author1, publish1;
	int year1, price1;
	std::cout << " Enter name:";
	std::cin >> name1;
	std::cout << " Enter author's name:";
	std::cin >> author1;
	std::cout << " Enter year of publishment:";
	std::cin >> year1;
	std::cout << " Enter publishing house:";
	std::cin >> publish1;
	std::cout << " Enter price:";
	std::cin >> price1;
	Book bookRecNew(name1, author1, year1, publish1, price1);
	info.Insert(bookRecNew);
	//addRecord();
	info.InorderTraversal();

	info.FindRecord();
	
	info.del();
	//info.InorderTraversal();


	return 0;
}