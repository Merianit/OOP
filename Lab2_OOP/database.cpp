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