#pragma once
#include <iostream>
#include <fstream>
#include <exception>

using namespace std;

class Library
{
	char title[20];
	char autor[20];
	int date;

	static int count;

public:
	Library();

	static int getCount();

	void input();
	void output() const;

	void add(Library*& library);

	void save(const string filename, Library*& library) const;
	void load(const string filename, Library*& library);
};

