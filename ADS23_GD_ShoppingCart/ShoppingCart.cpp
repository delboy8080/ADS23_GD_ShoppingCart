#include "ShoppingCart.h"

bool ShoppingCart::addBook(Book* b)
{
	if (b != nullptr)
	{
		books.push_back(b);
		return true;
	}
	return false;
}
int ShoppingCart::addAll(list<Book*>bks)
{
	int c = 0;
	for (Book* b : bks)
	{
		if (this->addBook(b))
		{
			c++;
		}
	}
	return c;
}
bool ShoppingCart::removeBook(Book* b)
{
	if (b != nullptr)
	{
		for (list<Book*>::iterator iter = books.begin(); iter != books.end(); iter++)
		{
			if ((*iter)->getTitle() == b->getTitle() && (*iter)->getPrice() == b->getPrice())
			{
				books.erase(iter);
				return true;
			}
		}
	}
	return false;
}

int ShoppingCart::size()
{
	return books.size();
}

double ShoppingCart::getSubtotal()
{
	double value = 0;
	for (Book* b : books)
	{
		value += b->getPrice();
	}
	return value;
}

bool ShoppingCart::checkout()
{
	return false;
}