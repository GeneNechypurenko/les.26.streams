#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <exception>

#include "Library.h"

using namespace std;

int main()
{
    string filename = "save.bin";

    Library* lib = nullptr;

    try
    {
        lib->load(filename, lib);
    }
    catch (const char* error_read_from_file)
    {
        cout << endl << error_read_from_file << endl << endl;
    }

    system("pause");

    int select = 0;

    const char* menu[] = { "1. Add", "2. Print", "3. Exit" };

    while (true)
    {
        system("cls");

        for (int i = 0; i < 3; i++)
        {
            cout << menu[i] << endl;
        }

        select = _getch();

        switch (select)
        {
        case '1':

            system("cls");
            try
            {
                lib->add(lib);
            }
            catch (const char* error_input)
            {
                cout << endl << error_input << endl << endl;
            }
            system("pause");

            break;

        case '2':

            system("cls");
            for (int i = 0; i < Library::getCount(); i++)
            {
                lib[i].output();
            }
            system("pause");

            break;

        case '3':

            system("cls");
            try
            {
                lib->save(filename, lib);
            }
            catch (const char* error_write_to_file)
            {
                cout << endl << error_write_to_file << endl << endl;
            }
            system("pause");

            delete[] lib;

            return 0;
        }
    }
    return 0;
}
