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
	void InorderTraversal();
	void ShowRecords(const Node* r);
	void find();
	void FindbyKey(  Node* r, int key)  ;
	void FindbyPublish(  Node* r, std::string publ);
	void DeleteTree(Node* root);
	void DelbyAuthor(const Node* r, std::string auth);
	Node* DeleteRecord(Node* root, int key)const;
	void del();
private:
	Node* root;
	void InorderTraversal(Node* r);
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
	else if (r->data->price > newNode->data->price)
		Insert(r->left, newNode);
	else
		Insert(r->right, newNode);
}


void BinaryTreeBook::ShowRecords(const Node* r)
{
	std::cout << r->data->name << " " << r->data->author << " " << r->data->year << " " << r->data->publish << " " << r->data->price << "\n";
}

void BinaryTreeBook::InorderTraversal() {
	if (root == nullptr)
		std::cerr << "There is no record";
	else
		InorderTraversal(root);
}
void BinaryTreeBook::InorderTraversal(Node* r) 
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
				while (ptrmin != NULL)
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
	else if (key < r->data->price)
		r->left = DeleteRecord(r->left, key);
	else
		r->right = DeleteRecord(r->right, key);
	return r;
}

void BinaryTreeBook::FindbyKey(  Node* r, int key)  
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

	if (r->data->price > key)
	{
		FindbyKey(r->left, key);
	}
	else if (r->data->price < key)
	{
		FindbyKey(r->right, key);
	}
}
void BinaryTreeBook::DelbyAuthor( const Node* r, std::string auth)
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
		DelbyAuthor(r->left, auth);
		DelbyAuthor(r->right, auth);


	
}
void BinaryTreeBook::FindbyPublish(  Node* r, std::string publ)
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
void BinaryTreeBook::DeleteTree(  Node* r)  
{
	if (!r) return;
	DeleteTree(r->left);
	DeleteTree(r->right);
	delete r;
	std::cout << "\nRecord is deleted";
	return;

}

void BinaryTreeBook::del()
{
	int c,key;
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
		if(des == 'y')
			DeleteTree(root);
		break;

	default:
		return;
	}
}
int main()
{
	BinaryTreeBook info;
	Book bookRec("Traceback", "Kevin", 2003, "Huston", 250);
	Book bookRec1("Rodeo", "Mike", 2000, "Jills", 200);
	Book bookRec2("Mystery", "Leo", 2010, "Great", 150);
	Book bookRec3("Jellybeans", "Stacy", 2011, "Camera", 170);
	Book bookRec4("Blinds", "Mike", 2013, "Jills", 280);
	Book bookRec5("Ferry", "Leo", 2001, "Kingston", 210);
	std::string name1, author1, publish1;
	int year1, price1, c;
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

	info.Insert(bookRec);
	info.Insert(bookRec1);
	info.Insert(bookRec2);
	info.Insert(bookRec3);
	info.Insert(bookRec4);
	info.Insert(bookRec5);
	info.Insert(bookRecNew);
	info.InorderTraversal();
	do
	{
		std::cout << "\n_______Navigation bar_______\n Menu:\n    1 - Show all records inorder\n    2 - Find menu\n    3 - Delete menu\n    4 - Quit\n  Your choice:";
		std::cin >> c;

		switch (c)
		{
		case 1:
			info.InorderTraversal();
			break;
		case 2:
			info.find();
			break;
		case 3:
			info.del();
			break;
		default:
			break;
		}
	} while (c != 4);
	return 0;
}