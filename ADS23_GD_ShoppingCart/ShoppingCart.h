#pragma once
#include <list>
#include "Book.h"
class ShoppingCart
{
	list<Book*> books;
public:
	bool addBook(Book* b);
	int addAll(list<Book*>bks);
	bool removeBook(Book* b);
	int size();
	double getSubtotal();
	bool checkout();
};

