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

using namespace std;

int main()
{
    cout << "<html>" << endl;
    cout << "<head>" << endl;
    cout << "<title>Buyer's order @ Leopard Nike shoe store</title>" << endl;
    cout << "</head>" << endl;
    cout << "<body style='background-color:powderblue'>" << endl;
    cout << "<H1>Leopard Nike Shoe Store</H1> " << endl;
    cout << "<H2>From CS102 Spring 2018</H2> " << endl;
    cout << "<H3>Albert Chen & Haixia Li</H3> " << endl;
    cout << "<H2>Welcome to our shoes store.</H2>" << endl;
    cout << "<form action='/teamproject/seller-albert.html' method='get'>" << endl;
    cout << "<p>You are all set!</p >" << endl;
    cout << "<div><input type='submit' value='Click here to go back'></div>" << endl;
    cout << "</form>" << endl;
    cout << "</body>" << endl;
    cout << "</html>" << endl;


	//std::ofstream write;
	//write.open("../data/user.txt", std::ios::app);
	//std::cout << "Writting data into user.txt\n";
	//std::string query_string =  getenv("QUERY_STRING"); // To get the query string from URL.
	//write << query_string;
	//write.close();

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
