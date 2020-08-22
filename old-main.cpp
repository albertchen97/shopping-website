#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib> // For getenv()
#include <vector>
#include <iomanip> // For setw()
#include "Item.h"

std::string getStrWanted(std::istringstream& inputSS);
// To get the std::string (first name, last name, seller or buyer) from the homepage.html
// Precondiition: inputSS = "var1Name=var1Value&var2Name=var2Value&..."
// Postcondition: inputSS = "var2Name=var2Value&...", return(var1Value)

void processH1(std::istringstream& inputSS);
void processB3(std::istringstream& inputSS);

void openS2(std::string firstName, std::string lastName);

void openB3(std::string firstName, std::string lastName);
void openB4(std::vector<Item>& searchList, std::string bFirstName, std::string bLastName);

void readInventory(std::vector<Item>& invList);
void search(std::vector<Item>& invList, std::vector<Item>& searchList, std::string gender, std::string color, int size, double priceMin, double priceMax);

int main()
{  
	std::string firstName, lastName;
	int htmlNo;
	std::string data = getenv("QUERY_STRING"); // Get data from html file
	if (data != " ") //To make sure there is no passing data error
	{
		std::istringstream inputSS(data);
		std::string a = getStrWanted(inputSS);//a="int"
		std::istringstream(a) >> htmlNo;//convert std::string a to int htmlNo
		switch (htmlNo)
		{
		case 1://storefront1.html
			processH1(inputSS);
			break;
		case 2:
			//processH2(inputSS);
			break;
		case 3:
			processB3(inputSS);
			break;
		case 4:
			//processH4(inputSS);
			break;
		}

	}
	return 0;
}

std::string getStrWanted(std::istringstream& inputSS)
{
	std::string strTemp;
	getline(inputSS, strTemp, '&'); // strTemp="name=strWanted", discard '&'
	std::size_t found = strTemp.find('=');
	return(strTemp.substr(found + 1));
}

void processH1(std::istringstream& inputSS)
{
	std::string firstName, lastName, user;
	firstName = getStrWanted(inputSS);
	lastName = getStrWanted(inputSS);
	user = getStrWanted(inputSS);
	if (user == "s")
	{
		openS2(firstName, lastName);
	}
	else if (user == "b")
	{
		openB3(firstName, lastName);
	}
	else
		std::cout << "user input error" << std::endl;
}

void openS2(std::string firstName, std::string lastName)
{
	std::cout << "<html>" << std::endl;
	std::cout << "<title> seller's </title>" << std::endl;
	std::cout << "<h3> seller's </h3>";
	std::cout << "<body>" << std::endl;
	std::cout << "<p> The seller's first name = " << firstName << "<br>" << std::endl;
	std::cout << " The seller's last name = " << lastName << "</p >" << std::endl;
	std::cout << "</html>" << std::endl;
}

//albert: changed the previous code to html file
void openB3(std::string firstName, std::string lastName)
{
	std::cout << "<html>" << std::endl;
	std::cout << "<form>" << std::endl;
	std::cout << "<form acton='/openB3.html/'" << std::endl;
	std::cout << "</form>" << std::endl;
	std::cout << "</html>" << std::endl;
}

void processB3(std::istringstream& inputSS)
{//gender=m&color=black&size=10&priceMin= &priceMax=
	int size;
	double priceMin, priceMax;
	std::string bFirstName, bLastName, gender, color, strTemp;
	bFirstName = getStrWanted(inputSS);
	bLastName = getStrWanted(inputSS);
	gender = getStrWanted(inputSS);
	color = getStrWanted(inputSS);
	strTemp = getStrWanted(inputSS);//"size"
	std::istringstream(strTemp) >> size;//convert "size" to int type
	strTemp = getStrWanted(inputSS); //"priceMin"
	std::istringstream(strTemp) >> priceMin;//convert "priceMin" to double type
	strTemp = getStrWanted(inputSS);//"priceMax"
	std::istringstream(strTemp) >> priceMax; //convert "priceMax" to double type

//    std::cout <<bFirstName <<bLastName <<"gender= "<<gender<<"; color= " <<color<<" ; size= " <<size<<" ; priceMin= "
  //      <<priceMin <<priceMax<<std::endl;

	std::vector<Item> invList, searchList;// invList, an object array, stores data from inventory.txt
		//searchList, an object array, stores the search result
	readInventory(invList); //read data from inventory.txt to invList, an object array
	search(invList, searchList, gender, color, size, priceMin, priceMax);
	//search inventory and return the search result in object array searchList
/*for (unsigned int i=0;i<searchList.size();i++)
	std::cout <<std::left <<std::setw(15)<<searchList[i].getGender()
		<<std::setw(15)<<searchList[i].getColor()
		<<std::setw(15)<<searchList[i].getSize()
		<<std::setw(15)<<searchList[i].getPrice()<< std::endl;
*/
	openB4(searchList, bFirstName, bLastName);
}

void readInventory(std::vector<Item>& invList)
{
	std::string sFirstName, sLastName, gender, color, strTemp;
	int size, quantities;
	double price;
	std::ifstream inputStream;//using library fstream
	inputStream.open("inventory.txt");
	while (!inputStream.eof())
	{
		getline(inputStream, strTemp);
		std::istringstream ss(strTemp);
		if (ss >> sFirstName >> sLastName//if strTemp is not null,
			>> gender >> color >> size >> price >> quantities)//put values to variables
		{
			invList.push_back(Item(sFirstName, sLastName, gender, color, size,
				price, quantities));//call the constructor to generate an object
				//and use push to add the object to vector invlist
		}
	}
	inputStream.close();
}

void search(std::vector<Item>& invList, std::vector<Item>& searchList, std::string gender,
	std::string color, int size, double priceMin, double priceMax)
{
	for (unsigned i = 0; i < invList.size(); i++)
	{
		if (color == "any")
		{
			if ((invList[i].getGender() == gender)
				&& (invList[i].getSize() == size)
				&& (invList[i].getPrice() > priceMin && invList[i].getPrice() < priceMax))
			{
				searchList.push_back(invList[i]);
			}
		}
		else if ((invList[i].getGender() == gender)
			&& (invList[i].getColor() == color)
			&& (invList[i].getSize() == size)
			&& (invList[i].getPrice() > priceMin && invList[i].getPrice() < priceMax))
		{
			searchList.push_back(invList[i]);
		}
	}
}

void openB4(std::vector<Item>& searchList, std::string bFirstName, std::string bLastName)
{
	std::cout << "<html>" << std::endl;
	std::cout << "<head>" << std::endl;
	std::cout << "<title>Leopard Nike shoe store</title>" << std::endl;
	std::cout << "</head>" << std::endl;
	std::cout << "<body style='background-color:powderblue'>" << std::endl;
	std::cout << "<H1>Leopard Nike Shoe Store</H1> " << std::endl;
	std::cout << "<H2>From CS102 Spring 2018</H2> " << std::endl;
	std::cout << "<H3>Albert Chen & Haixia Li</H3> " << std::endl;
	std::cout << "<H2>Welcome to our shoe store.</H2><br>" << std::endl;
	std::cout << "<H3><Your search result is:</H3>" << std::endl;
	std::cout << "<form action='/cgi-bin/storefront1.cgi'>" << std::endl;
	std::cout << "<input type='hidden' name='htmlNo' value='4'>" << std::endl;
	for (unsigned i = 0; i < searchList.size(); i++)
	{
		std::cout << "<input type='checkbox' name='searchListNo' value='" << i << "'>";
		std::cout << std::left << std::setw(25) << searchList[i].getGender()
			<< std::setw(25) << searchList[i].getColor()
			<< std::setw(25) << searchList[i].getSize()
			<< std::setw(25) << searchList[i].getPrice()
			<< "<br>" << std::endl;
	}
	std::cout << "<input type='submit'>" << std::endl;
}
