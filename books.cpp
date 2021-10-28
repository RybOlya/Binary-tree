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
	int getPrice() const { return price; }
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
	void FindRecord() const;
	Node* DeleteRecord(Node* root, int key)const;
	void FindbyKey(const Node* r, int key) const;
	void FindbyPublish(const Node* r, std::string publ) const;
	void deletDeepest(struct Node* root, struct Node* d_node)const;
	void DeleteTree(const Node* root) const;
	void del();
	void search(Node*& cur, std::string item, Node*& parent);
	Node* getmin(Node* root) const;
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
	std::cout << r->data->name << " " << r->data->author << " " << r->data->year << " " << r->data->publish << " " << r->data->getPrice() << "\n";
}
void  BinaryTreeBook::FindbyKey(const Node* r, int key) const
{
	if (r == nullptr)
	{
		std::cout << "Key not found\n";
		return;
	}
	if (r->data->getPrice() == key)
	{
		std::cout << "\n Records found:";
		ShowRecords(r);
		std::cout << "\n";
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
void  BinaryTreeBook::FindbyPublish(const Node* r, std::string publ) const
{
	int key = 0;
	if (r != nullptr) {
		if (r->data->publish == publ)
		{
			key = r->data->getPrice();
		}
		if (r->data->getPrice() == key)
		{
			std::cout << "\n Records found:";
			ShowRecords(r);

			std::cout << "\n";
			root == r;
		}

		if (r->data->getPrice() < key)
		{
			FindbyPublish(r->left, publ);
		}
		else if (r->data->getPrice() > key)
		{
			FindbyPublish(r->right, publ);
		}
		//FindbyPublish(root, publ);
	}
}
void BinaryTreeBook::deletDeepest(struct Node* root, struct Node* r)const
{
	std::queue<Node*> q;
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

Node* BinaryTreeBook::getmin(Node* root) const
{
	Node* curr = root;

	while (curr && curr->left) {
		curr = curr->left;
	}

	return curr;
}

Node* BinaryTreeBook::DeleteRecord(Node* root, int key) const
{
	if (root == NULL)
		return root;

	if (key < root->data->getPrice())
		root->left = DeleteRecord(root->left, key);

	else if (key > root->data->getPrice())
		root->right = DeleteRecord(root->right, key);
	else if (key == root->data->getPrice()) 
	{
		if (root->left == NULL) {
			Node* temp = root->right;
			delete(root);
			return temp;
		}
		else if (root->right == NULL) {
			Node* temp = root->left;
			delete(root);
			return temp;
		}

		Node* temp = getmin(root->right);

		root->data->getPrice() == temp->data->getPrice();
		root->right = DeleteRecord(root->right,temp->data->getPrice());
	}
	return root;
}

void  BinaryTreeBook::FindRecord() const
{
	int key;
	std::string publ;
	std::cout << " Enter key(price): ";
	//std::cin >> key;
	FindbyKey(root, 210);
	//std::cin >> key;

	//std::cin >> publ;
	FindbyPublish(root, "Jills");

}
void  BinaryTreeBook::del()
{	
	//DeleteRecord(root, 280);
	DeleteTree(root);
}
int main()
{
	BinaryTreeBook info;
	Book rec;
	Book bookRec("Traceback", "Kevin", 2003, "Huston", 250);
	Book bookRec1("Rodeo", "Mike", 2000, "Greats", 200);
	Book bookRec2("Mystery", "Gary", 2010, "Jills", 150);
	Book bookRec3("Jellybeans", "Stacy", 2011, "Jills", 180);
	Book bookRec4("Blinds", "Aaron", 2013, "Frames", 280);
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
	info.del();
	//info.InorderTraversal();


	return 0;
}