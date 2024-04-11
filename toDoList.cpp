#include <iostream>
#include <fstream>
#include<string>
#include <cstdlib>

using namespace std;
int ID;

struct todo {
    int id;
    string task;
};


void addtodo() {
  
    todo todo;
    cout << "\n\tEnter new task: ";
    cin.get();
    getline(cin, todo.task);
    ID++;

    ofstream write;
    write.open("todo.txt", ios::app);
    write << "\n" << ID;
    write << "\n" << todo.task ;
    write.close();


    write.open("id.txt");
    write << ID;
    write.close();
cout << "\n\tTask has been added successfully";
        return;
}


void print(todo s) {
    cout << "\n\tID is : " << s.id;
    cout << "\n\tTask is : " << s.task;
}


void readData() {
    todo todo;
    ifstream read;
    read.open("todo.txt");
    cout << "\n\tYour current Tasks in the list";

    while (!read.eof()) {
        read >> todo.id;
        read.ignore();
        getline(read, todo.task);
        print(todo);
    }
    read.close();
}


int searchData() {
   
    int id;
    cout << "\n\tEnter task id: ";
    cin >> id;
    todo todo;
    ifstream read;
    read.open("todo.txt");

    while (!read.eof()) {
        read >> todo.id;
        read.ignore();
        getline(read, todo.task);
        if (todo.id == id) {
            print(todo);
            return id;
        }
    }
}

void deleteData() {
   
    int id = searchData();
    cout << "\n\tDo you want to delete this task (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        todo todo;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("todo.txt");

        while (!read.eof()) {
            read >> todo.id;
            read.ignore();
            getline(read, todo.task);
            if (todo.id != id) {
                tempFile << "\n" << todo.id;
                tempFile << "\n" << todo.task;
            }
        }
        read.close();
        tempFile.close();
        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        cout << "\n\tTask deleted successfuly";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
}


int main()
{
   
    ifstream read;
    read.open("id.txt");
    if (!read.fail()) {
        read >> ID;
    }
    else {
        ID = 0;
    }
    read.close();

    while (true) {
        cout<<endl;
        cout << "\n\t1.Add Task";
        cout << "\n\t2.Display Task";
        cout << "\n\t3.Search Task";
        cout << "\n\t4.Delete Task";

        int choice;
        cout << "\n\n\tEnter choice : ";
        cin >> choice;
        switch (choice) {
        case 1:
            addtodo();
            break;
        case 2:
            readData();
            break;
        case 3:
            searchData();
            break;
        case 4:
            deleteData();
            break;
        default:
            cout<<"enter correct option";
            break;
        }
    }

}
