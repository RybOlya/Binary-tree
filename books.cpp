#include<iostream>
#include "Book.h"
#include "BinaryTreeBook.h"
#define N 6


int main()
{
	BinaryTreeBook info;
	Book bookRec("Traceback", "Kevin", 2003, "Huston", 250);
	Book bookRec1("Rodeo", "Lucas", 2000, "Jills", 200);
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