#include "database.h"
#include <iostream>
#include <iomanip>

const int database_length = 1000;
int compare_lines(char* str1, char* str2);

Database::Database() {
    database = new Student[database_length];
    if (nullptr == database) {
        std::cout << "Allocation error!";
        exit(1);
    }
    top = 0;
}

void Database::main_menu() {
    char* command = new char[160];

    while (1) {
        std::cout << '\n';
        std::cout << "\tWelcome to the student accounting system\n";
        std::cout << "Hello, select the action: \n";
        std::cout << "'view' - to print the entire database \n";
        std::cout << "'add' - to add a new elements \n";
        std::cout << "'group' - to find all students of a given group\n";
        std::cout << "'surname' - to find a student by last name \n";
        std::cout << "'exit' - to finish working with the program and save data\n";
        std::cout << "Number of entries: " << top << "\n";
        std::cin >> command;

        if (compare_lines(command, (char*)"view")) { show_database(); continue; }
        else if (compare_lines(command, (char*)"add")) { add_entry(); continue; }
        else if (compare_lines(command, (char*)"group")) { find_group(); continue; }
        else if (compare_lines(command, (char*)"surname")) { find_surname(); continue; }
        else if (compare_lines(command, (char*)"exit")) { write_file(); exit(1); }
        else {
            std::cout << "Not a command \n";
            std::cout << "\n";
            std::cout << "\n";
            continue;
        }

        delete[] command;
    }
}

void Database::read_file() {
    file.open("d:\\database.txt");
    if (!file) {
        std::cout << "file error!" << std::endl;
        exit(1);
    }
	Student in;
    in.get_data_from_stream(file);
    Student* p = database;
    while (in.get_group()) {
        *p = in;
        p++;
        top++;
        in.clear();
        in.get_data_from_stream(file);
    }
    file.close();
}

void Database::show_database() {
    alphabet_sort();
    Student* p = database;
    std::cout << std::setw(10) << "First name" << std::setw(20) << "Last name"
        << std::setw(20) << "Faculty" << std::setw(20) << "Group" << std::endl;
    for (int i = 0; i < 80; i++, std::cout << '-');
    std::cout << "\n";
    while (p->get_group()) {
        p->show_data();
        p++;
    }
}

void Database::write_file() {
    alphabet_sort();
    file.open("d:\\database.txt");
    if (!file) {
        std::cout << "file error!" << std::endl;
        exit(1);
    }
    Student* p = database;
    while (p->get_group()) {
        p->send_data_to_stream(file);
        p++;
    }
    file.close();
}

void Database::add_entry() {
    Student* p = database + top;
    p->get_data();
    top++;
}

void Database::find_group() {
    int group = 0;
    std::cout << ("Enter the student's group \n");
    std::cin >> group;
    Student* p = database;
    std::cout << std::setw(10) << "First name" << std::setw(20) << "Last name"
        << std::setw(20) << "Faculty" << std::setw(20) << "Group" << std::endl;
    for (int i = 0; i < 80; i++, std::cout << '-');
    std::cout << "\n";
    while (p->get_group()) {
        if (p->get_group() == group)
            p->show_data();
        p++;
    }
}

void Database::find_surname() {
    char* surname = new char[160];
    std::cout << ("Enter the student's surname \n");
    std::cin >> surname;
    Student* p = database;
    std::cout << std::setw(10) << "First name" << std::setw(20) << "Last name"
        << std::setw(20) << "Faculty" << std::setw(20) << "Group" << std::endl;
    for (int i = 0; i < 80; i++, std::cout << '-');
    std::cout << "\n";
    while (p->get_group()) {
        if (compare_lines(p->get_surname(),surname))
            p->show_data();
        p++;
    }
    delete[] surname;
}

void Database::alphabet_sort() {
    Student* p = database;
    int length = top;
    for (int i = 0; i < length; i++)
        for (int j = 0; j < length - 1; j++) {
            if (*(p+j) < *(p+j+1)) {
                Student temp;
                temp = *(p + j);
                *(p + j) = *(p + j + 1);
                *(p + j + 1) = temp;
            }
        }
}

Database::~Database() {
    delete[] database;
}

int compare_lines(char* str1, char* str2) {
    if (strlen(str1) != strlen(str2))
        return 0;
    else
    {
        for (int i = 0; i < (int)strlen(str2); i++)
            if (*(str1 + i) != *(str2 + i))
                return 0;
        return 1;
    }
}