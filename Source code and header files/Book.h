#pragma once
#include <iostream>
using namespace std;

class Book
{
private:
	int ID;
	string title;
	string author;
	int pageCount;
	int freePage;
	int serialNumber;
	string category;
	int visibility;
public:
	static int latestSerialNumber;
	Book();
	Book(int, string);
	Book(int, string, string, int, int, int, string, int);
	~Book();
	void setID(int);
	void setTitle(string);
	void setAuthor(string);
	void setPageCount(int);
	void setFreePage(int);
	void setSerialNumber(int);
	void setCategory(string);
	void setVisibility(int);
	int getID();
	string getTitle();
	string getAuthor();
	int getPageCount();
	int getFreePage();
	int getSerialNumber();
	string getCategory();
	int getVisibility();
	void display();
};

