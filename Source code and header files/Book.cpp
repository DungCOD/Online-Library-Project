#include "Book.h"

int Book::latestSerialNumber = 100000;

Book::Book() {
	ID = 0;
	title = " ";
	author = " ";
	pageCount = 0;
	freePage = 0;
	serialNumber = latestSerialNumber;
	latestSerialNumber++;
	category = " ";
	visibility = 1;
}

Book::Book(int id, string t) {
	ID = id;
	title = t;
	serialNumber = latestSerialNumber;
	latestSerialNumber++;
	visibility = 1;
}

Book::Book(int id, string t, string a, int p, int f, int s, string c, int v) {
	ID = id;
	title = t;
	author = a;
	pageCount = p;
	freePage = f;
	serialNumber = s;
	category = c;
	visibility = v;
}

Book::~Book() {

}

void Book::setID(int id) {
	ID = id;
}

void Book::setTitle(string t) {
	title = t;
}

void Book::setAuthor(string a) {
	author = a;
}

void Book::setPageCount(int p) {
	pageCount = p;
}

void Book::setFreePage(int f) {
	freePage = f;
}

void Book::setSerialNumber(int s) {
	serialNumber = s;
}

void Book::setCategory(string c) {
	category = c;
}

void Book::setVisibility(int v) {
	visibility = v;
}

int Book::getID() {
	return ID;
}

string Book::getTitle() {
	return title;
}

string Book::getAuthor() {
	return author;
}

int Book::getPageCount() {
	return pageCount;
}

int Book::getFreePage() {
	return freePage;
}

int Book::getSerialNumber() {
	return serialNumber;
}

string Book::getCategory() {
	return category;
}

int Book::getVisibility() {
	return visibility;
}

void Book::display() {
	cout << "Title: " << title << endl;
	cout << "Serial:" << serialNumber << endl;
}

