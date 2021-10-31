#pragma once
#include<iostream>
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