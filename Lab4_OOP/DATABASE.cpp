#include "DATABASE.h"
#include "STOCK.h"
#include "STORAGE.h"
#include <iostream>
#include <iomanip>

Database::Database(classes flag) {
    type_flag = flag;
    if (flag == storage) {
        database_storage = new STORAGE[database_length];
        if (nullptr == database_storage) {
            std::cout << "Allocation error!";
            exit(1);
        }
        database_stock = nullptr;
    }
    else if (flag == stock) {
        database_stock = new STOCK[database_length];
        if (nullptr == database_stock) {
            std::cout << "Allocation error!";
            exit(1);
        }
        database_storage = nullptr;
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
        std::cout << "'sort' - to sort by departure point (patronymic for stock) \n";
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
    if (type_flag == storage) {
        file.open("storage.txt");
        if (!file) {
            std::cout << "file error!" << std::endl;
            exit(1);
        }
        STORAGE in;
        in.get_data_from_stream(file);
        STORAGE* p = database_storage;
        while (!in.is_empty()) {
            *p = in;
            p++;
            top++;
            in.clear();
            in.get_data_from_stream(file);
        }
    }
    else if (type_flag == stock) {
        file.open("stock.txt");
        if (!file) {
            std::cout << "file error!" << std::endl;
            exit(1);
        }
        STOCK in;
        in.get_data_from_stream(file);
        STOCK* p = database_stock;
        while (!in.is_empty()) {
            *p = in;
            p++;
            top++;
            in.clear();
            in.get_data_from_stream(file);
        }
    }
    file.close();
}

void Database::show_database() {
    //alphabet_sort();
    if (type_flag == storage) {
        STORAGE* p = database_storage;
        std::cout << std::setw(10) << "First name" << std::setw(10) << "Last name"
            << std::setw(15) << "Patronymic" << std::setw(10) << "Departure" << std::setw(10)
            << "Arrival" << std::setw(10) << "Ticket" << std::endl;
        for (int i = 0; i < 80; i++, std::cout << '-');
        std::cout << "\n";
        while (!p->is_empty()) {
            p->show_data();
            p++;
        }
    }
    if (type_flag == stock) {
        STOCK* p = database_stock;
        std::cout << std::setw(10) << "First name" << std::setw(10) << "Last name"
            << std::setw(15) << "Patronymic" << std::setw(20) << "Wagon number" << std::setw(20)
            << "Seat number" << std::setw(10) << "Ticket" << std::endl;
        for (int i = 0; i < 80; i++, std::cout << '-');
        std::cout << "\n";
        while (!p->is_empty()) {
            p->show_data();
            p++;
        }
    }
}

void Database::write_file() {
    alphabet_sort();
    if (type_flag == storage) {
        file.open("storage.txt");
        if (!file) {
            std::cout << "file error!" << std::endl;
            exit(1);
        }
        STORAGE* p = database_storage;
        while (!p->is_empty()) {
            p->send_data_to_stream(file);
            p++;
        }
    }
    if (type_flag == stock) {
        file.open("stock.txt");
        if (!file) {
            std::cout << "file error!" << std::endl;
            exit(1);
        }
        STOCK* p = database_stock;
        while (!p->is_empty()) {
            p->send_data_to_stream(file);
            p++;
        }
    }

    file.close();
}

void Database::add_entry() {
    if (type_flag == storage) {
        std::cout << std::setw(10) << "First name" << std::setw(10) << "Last name"
            << std::setw(15) << "Patronymic" << std::setw(10) << "Departure" << std::setw(10)
            << "Arrival" << std::setw(10) << "Ticket" << std::endl;
        STORAGE* p = database_storage + top;
        std::cin >> *p;
    }
    if (type_flag == stock) {
        std::cout << std::setw(10) << "First name" << std::setw(10) << "Last name"
            << std::setw(15) << "Patronymic" << std::setw(20) << "Wagon number" << std::setw(20)
            << "Seat number" << std::setw(10) << "Ticket" << std::endl;
        STOCK* p = database_stock + top;
        std::cin >> *p;
    }
   
    top++;
}

void Database::find_destination() {
    if (type_flag == storage) {
        char* destination = new char[160];
        std::cout << ("Enter the passenger's destination \n");
        std::cin >> destination;
        STORAGE* p = database_storage;
        std::cout << std::setw(10) << "First name" << std::setw(10) << "Last name"
            << std::setw(20) << "Patronymic" << std::setw(10) << "Departure" << std::setw(10)
            << "Arrival" << std::setw(10) << "Ticket price" << std::endl;
        for (int i = 0; i < 80; i++, std::cout << '-');
        std::cout << "\n";
        while (!p->is_empty()) {
            if (compare_lines((*p).get_destination(), destination))
                p->show_data();
            p++;
        }
    }
    if (type_flag == stock) {
        std::cout << "There is no such field";
    }
}

void Database::alphabet_sort() {
    if (type_flag == storage) {
        STORAGE* p = database_storage;
        int length = top;
        for (int i = 0; i < length; i++)
            for (int j = 0; j < length - 1; j++) {
                if (*(p + j) < *(p + j + 1)) {
                    STORAGE temp;
                    temp = *(p + j);
                    *(p + j) = *(p + j + 1);
                    *(p + j + 1) = temp;
                }
            }
    }
    if (type_flag == stock) {
        STOCK* p = database_stock;
        int length = top;
        for (int i = 0; i < length; i++)
            for (int j = 0; j < length - 1; j++) {
                if (*(p + j) < *(p + j + 1)) {
                    STOCK temp;
                    temp = *(p + j);
                    *(p + j) = *(p + j + 1);
                    *(p + j + 1) = temp;
                }
            }
    }
}

Database::~Database() {
    delete[] database_stock;
    delete[] database_storage;
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