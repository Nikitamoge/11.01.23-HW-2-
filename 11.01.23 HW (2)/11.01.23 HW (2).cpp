#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

//Task 1 func
const int SIZE = 10; 

void transp(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}


//Task 2 func
struct Contact {
    string name;
    string phone;
};

Contact* add(Contact* contacts, int& size, const string& name, const string& phone) {
    Contact* new_contact = new Contact[size + 1];
    for (int i = 0; i < size; i++) {
        new_contact[i] = contacts[i];
    }
    new_contact[size].name = name;
    new_contact[size].phone = phone;
    delete[] contacts;
    size++;
    return new_contact;
}

void search_by_name(Contact* contacts, int size, const string& name) {
    for (int i = 0; i < size; i++) {
        if (contacts[i].name == name) {
            cout << "Person was found: " << contacts[i].name << ", " << contacts[i].phone << endl;
            return;
        }
    }
    cout << "Person was not found." << endl;
}

void search_by_phone(Contact* contacts, int size, const string& phone) {
    for (int i = 0; i < size; i++) {
        if (contacts[i].phone == phone) {
            cout << "Person was found: " << contacts[i].name << ", " << contacts[i].phone << endl;
            return;
        }
    }
    cout << "Person was not found." << endl;
}

int main() {
    //Task 1
    srand(time(0));

    int matrix[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % 100;
            cout << matrix[i][j] << "  |  ";
        }
        cout << endl;
    }

    cout << endl;

    transp(matrix);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << matrix[i][j] << "  |  ";
        }
        cout << endl;
    }


    //Task 2
    int size = 0;
    Contact* contacts = nullptr;

    contacts = add(contacts, size, "Max", "+380986573269");
    contacts = add(contacts, size, "Xam", "+380962375689");

    search_by_name(contacts, size, "Xam");

    search_by_phone(contacts, size, "+3809865269");

    delete[] contacts;
}


