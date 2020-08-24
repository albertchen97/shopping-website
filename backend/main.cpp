// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

//	1. Get the type of user (buyer/seller) from homepage (index.htm).
//	2. Open corresponding web page.

#define _CRT_SECURE_NO_WARNINGS	// Must define to use getenv()
#include <iostream>
#include <string>
#include <cstdlib> // For getenv()
#include "Product.h"
#include "User.h"
#include "Buyer.h"
#include <fstream>

int main()
{
	std::ofstream write;
	write.open("../data/user.txt", std::ios::app);

	//std::string query_string = "";
	//query_string = getenv("QUERY_STRING"); // To get the query string from URL.

	write << "Test";
	write.close();
	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
