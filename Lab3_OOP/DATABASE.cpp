#include "DATABASE.h"
#include <iostream>
#include <iomanip>

Database::Database() {
    database = new TICKET[database_length];
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
        std::cout << "\tWelcome to the ticket database\n";
        std::cout << "Hello, select the action: \n";
        std::cout << "'view' - to print the entire database \n";
        std::cout << "'add' - to add a new elements \n";
        std::cout << "'destination' - to find all tickets of a destination\n";
        std::cout << "'sort' - to sort by departure point \n";
        std::cout << "'exit' - to finish working with the program and save data\n";
        std::cout << "Number of entries: " << top << "\n";
        std::cin >> command;

        if (compare_lines(command, (char*)"view")) { show_database(); continue; }
        else if (compare_lines(command, (char*)"add")) { add_entry(); continue; }
        else if (compare_lines(command, (char*)"destination")) { find_destination(); continue; }
        else if (compare_lines(command, (char*)"sort")) { alphabet_sort(); continue; }
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
    TICKET in;
    in.get_data_from_stream(file);
    TICKET* p = database;
    while (!in.is_empty()) {
        *p = in;
        p++;
        top++;
        in.clear();
        in.get_data_from_stream(file);
    }
    file.close();
}

void Database::show_database() {
    //alphabet_sort();
    TICKET* p = database;
    std::cout << std::setw(10) << "First name" << std::setw(20) << "Last name"
        << std::setw(20) << "Patronymic" << std::setw(20) << "Departure" << std::setw(20) 
        << "Arrival" << std::setw(20) << "Ticket" << std::endl;
    for (int i = 0; i < 110; i++, std::cout << '-');
    std::cout << "\n";
    while (!p->is_empty()) {
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
    TICKET* p = database;
    while (!p->is_empty()) {
        p->send_data_to_stream(file);
        p++;
    }
    file.close();
}

void Database::add_entry() {
    TICKET* p = database + top;
    std::cin >> *p;
    top++;
}

void Database::find_destination() {
    char* destination = new char[160];
    std::cout << ("Enter the passenger's destination \n");
    std::cin >> destination;
    TICKET* p = database;
    std::cout << std::setw(10) << "First name" << std::setw(20) << "Last name"
        << std::setw(20) << "Patronymic" << std::setw(20) << "Departure" << std::setw(20)
        << "Arrival" << std::setw(20) << "Ticket price" << std::endl;
    for (int i = 0; i < 110; i++, std::cout << '-');
    std::cout << "\n";
    while (!p->is_empty()) {
        if (compare_lines((*p).get_destination(), destination))
            p->show_data();
        p++;
    }
}

void Database::alphabet_sort() {
    TICKET* p = database;
    int length = top;
    for (int i = 0; i < length; i++)
        for (int j = 0; j < length - 1; j++) {
            if (*(p + j) < *(p + j + 1)) {
                TICKET temp;
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