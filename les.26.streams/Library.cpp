#include "Library.h"

int Library::count = 0;

Library::Library()
	:
	title("title"),
	autor("autor"),
	date(0)
{}

int Library::getCount()
{
	return count;
}

void Library::input()
{
	cout << "enter book title: ";
	cin.getline(title, sizeof(title));

	cout << "enter autor's name: ";
	cin.getline(autor, sizeof(autor));

	cout << "enter date of publishing: ";
	cin >> date;
	cin.ignore();

	if (cin.fail() || date < 0)
	{
		const char* error = "Error! Invalid input date! Please retry!";

		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		throw error;
	}

	system("cls");
}

void Library::output() const
{
	cout << "-------------------" << endl;
	cout << "title: " << title << endl;
	cout << "autor: " << autor << endl;
	cout << "date: " << date << endl;
	cout << "-------------------" << endl;
}

void Library::add(Library*& library)
{
	Library book;

	book.input();

	Library* temp = new Library[count + 1];

	for (int i = 0; i < count; i++)
	{
		temp[i] = library[i];
	}

	temp[count] = book;
	count++;

	delete[]library;
	library = temp;
}

void Library::save(const string filename, Library*& library) const
{
	ofstream save(filename, ios::binary);

	if (!save)
	{
		const char* error = "Error: Cannot open file for writing.";
		throw error;
	}

	save.write(reinterpret_cast<const char*>(&count), sizeof(int));

	for (int i = 0; i < count; i++)
	{
		save.write(reinterpret_cast<const char*>(&library[i]), sizeof(Library));
	}

	cout << "Data saved to " << filename << " successfully." << endl;

	save.close();
}

void Library::load(const string filename, Library*& library)
{
	ifstream load(filename, ios::binary);

	if (!load.is_open())
	{
		const char* error = "Error: Cannot open file for reading.";
		throw error;
	}

	load.read(reinterpret_cast<char*>(&count), sizeof(int));

	library = new Library[count];

	for (int i = 0; i < count; i++)
	{
		load.read(reinterpret_cast<char*>(&library[i]), sizeof(Library));
	}

	cout << "Data loaded from '" << filename << "' successfully." << endl;

	load.close();
}
