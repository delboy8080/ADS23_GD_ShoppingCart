#include "pch.h"
#include "CppUnitTest.h"
#include "..\ADS23_GD_ShoppingCart\ShoppingCart.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ShoppingCartTest
{
	TEST_CLASS(ShoppingCartTest)
	{
		Book* b1, * b2, * b3;
		TEST_METHOD_INITIALIZE(setup)
		{
			b1 = new Book("The Partner", 9.99);
			b2 = new Book("The Associate", 12.99);
			b3 = new Book("Camino Winds", 0.99);

		}
		TEST_METHOD_CLEANUP(teardown)
		{
			delete b1, b2, b3;
		}
	public:
		TEST_METHOD(testAddBook)
		{
			ShoppingCart cart;
			Assert::IsTrue(cart.addBook(b1));
		}

		TEST_METHOD(testAddNoBook)
		{
			ShoppingCart cart;
			Assert::IsFalse(cart.addBook(nullptr));
		}

		TEST_METHOD(testAddAllWithnullptrInList)
		{
			ShoppingCart cart;
			list<Book*> bks;
			bks.push_back(nullptr);
			bks.push_back(b1);
			bks.push_back(b2);
			Assert::AreEqual(0, cart.size(), L"Wrong number of books in Cart at start");
			Assert::AreEqual(2, cart.addAll(bks), L"Wrong number of books added");
			Assert::AreEqual(2, cart.size(), L"Wrong number of books in Cart");



		}
		TEST_METHOD(testAddAllWithBooksList)
		{
			ShoppingCart cart;
			list<Book*> bks;
			bks.push_back(b3);
			bks.push_back(b1);
			bks.push_back(b2);

			Assert::AreEqual(0, cart.size(), L"Wrong number of books in Cart at start");
			Assert::AreEqual(3, cart.addAll(bks), L"Wrong number of books added");
			Assert::AreEqual(3, cart.size(), L"Wrong number of books in Cart");
		}
		TEST_METHOD(testAddAllEmptyList)
		{
			ShoppingCart cart;
			list<Book*> bks;
			Assert::AreEqual(0, cart.addAll(bks), L"Wrong number of books added");
			Assert::AreEqual(0, cart.size(), L"Wrong number of books in Cart");
		}

		TEST_METHOD(testRemoveNull)
		{
			ShoppingCart cart;
			cart.addBook(b1);
			cart.addBook(b2);
			Assert::AreEqual(2, cart.size());
			Assert::IsFalse(cart.removeBook(nullptr), L"Nullptr removed from cart");
			Assert::AreEqual(2, cart.size());
		}
		TEST_METHOD(testRemoveBook)
		{
			ShoppingCart cart;
			cart.addBook(b1);
			cart.addBook(b2);
			Assert::AreEqual(2, cart.size());
			Assert::IsTrue(cart.removeBook(b1), L"Book not removed");
			Assert::AreEqual(1, cart.size());
		}
		TEST_METHOD(testRemoveBookNotFound)
		{
			ShoppingCart cart;
			cart.addBook(b1);
			cart.addBook(b2);
			Assert::AreEqual(2, cart.size());
			Assert::IsFalse(cart.removeBook(b3), L"Wrong book removed");
			Assert::AreEqual(2, cart.size());
		}
		TEST_METHOD(testSubtotalNoBooks)
		{
			ShoppingCart cart;
			Assert::AreEqual(0, cart.size());
			Assert::AreEqual(0.00, cart.getSubtotal(), 0.01);
		}
		TEST_METHOD(testSubtotalOneBook)
		{
			ShoppingCart cart;
			cart.addBook(b1);
			Assert::AreEqual(1, cart.size());
			Assert::AreEqual(9.99, cart.getSubtotal(), 0.01);
		}
		TEST_METHOD(testSubtotalTwoBooks)
		{
			ShoppingCart cart;

			cart.addBook(b1);
			cart.addBook(b2);
			Assert::AreEqual(2, cart.size());
			Assert::AreEqual(22.98, cart.getSubtotal(), 0.01);
		}
		TEST_METHOD(testCheckoutNoItems)
		{
			ShoppingCart cart;
			auto func = [&cart] {cart.checkout(); };
			Assert::ExpectException<logic_error>(func, L"Exception to Thrown");

		}
		TEST_METHOD(testCheckoutOneItem)
		{
			ShoppingCart cart;
			cart.addBook(b1);
			Assert::AreEqual(1, cart.size());

			cart.checkout(); ;
			Assert::AreEqual(0, cart.size());
		}

	};
}
