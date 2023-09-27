#pragma once
#include <string>
using namespace std;
class Book
{
	string title;
	double price;
public:
	Book(string s, double d)
	{
		title = s;
		price = d;
	}

	string getTitle() { return title; }
	double getPrice() { return price; }
};

