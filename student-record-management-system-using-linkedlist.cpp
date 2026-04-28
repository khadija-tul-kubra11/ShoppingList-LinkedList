#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
    Student* next;
};

class StudentList {
private:
    Student* head;

public:
    StudentList() {
        head = nullptr;
    }

    // Add new student
    void addStudent(int rollNo, string name, float marks) {
        Student* newStudent = new Student{rollNo, name, marks, nullptr};

        if (head == nullptr) {
            head = newStudent;
        } else {
            Student* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newStudent;
        }
        cout << "Student added successfully.\n";
    }

    // Display all students
    void displayStudents() {
        if (head == nullptr) {
            cout << "No records to display.\n";
            return;
        }

        Student* temp = head;
        while (temp != nullptr) {
            cout << "Roll No: " << temp->rollNo << ", Name: " << temp->name << ", Marks: " << temp->marks << "\n";
            temp = temp->next;
        }
    }

    // Delete student by roll no
    void deleteStudent(int rollNo) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (head->rollNo == rollNo) {
            Student* toDelete = head;
            head = head->next;
            delete toDelete;
            cout << "Student deleted.\n";
            return;
        }

        Student* temp = head;
        while (temp->next != nullptr && temp->next->rollNo != rollNo) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Student not found.\n";
        } else {
            Student* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            cout << "Student deleted.\n";
        }
    }

    // Search student by roll no
    void searchStudent(int rollNo) {
        Student* temp = head;
        while (temp != nullptr) {
            if (temp->rollNo == rollNo) {
                cout << "Found: Roll No: " << temp->rollNo << ", Name: " << temp->name << ", Marks: " << temp->marks << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Student not found.\n";
    }
};

int main() {
    StudentList sl;
    int choice;
    do {
        cout << "\n--- Student Record System (Linked List) ---\n";
        cout << "1. Add Student\n2. Display Students\n3. Delete Student\n4. Search Student\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int roll;
            string name;
            float marks;
            cout << "Enter Roll No: ";
            cin >> roll;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Marks: ";
            cin >> marks;
            sl.addStudent(roll, name, marks);
        } else if (choice == 2) {
            sl.displayStudents();
        } else if (choice == 3) {
            int roll;
            cout << "Enter Roll No to delete: ";
            cin >> roll;
            sl.deleteStudent(roll);
        } else if (choice == 4) {
            int roll;
            cout << "Enter Roll No to search: ";
            cin >> roll;
            sl.searchStudent(roll);
        }

    } while (choice != 0);

    return 0;
}
