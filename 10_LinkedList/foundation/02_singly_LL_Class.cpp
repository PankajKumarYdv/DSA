#include <iostream>
using namespace std;

// Linked list
class Student {
public:
    int rollNo;
    string name;
    float marks;
    Student* next;

    Student(int rollNo, string name, float marks) {
        this->rollNo = rollNo;
        this->name = name;
        this->marks = marks;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Student* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert at Beginning
    void insertAtBeginning(int rollNo, string name, float marks) {
        Student* newStudent = new Student(rollNo, name, marks);

        newStudent->next = head;
        head = newStudent;
    }

    // Insert at End
    void insertAtEnd(int rollNo, string name, float marks) {
        Student* newStudent = new Student(rollNo, name, marks);

        if (head == nullptr) {
            head = newStudent;
            return;
        }

        Student* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newStudent;
    }

    // Insert at Position (1-based indexing)
    void insertAtPosition(int pos, int rollNo, string name, float marks) {

        if (pos == 1) {
            insertAtBeginning(rollNo, name, marks);
            return;
        }

        Student* newStudent = new Student(rollNo, name, marks);

        Student* temp = head;

        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid Position\n";
            delete newStudent;
            return;
        }

        newStudent->next = temp->next;
        temp->next = newStudent;
    }

    // Delete from Beginning
    void deleteFromBeginning() {

        if (head == nullptr) {
            cout << "List is Empty\n";
            return;
        }

        Student* temp = head;
        head = head->next;

        delete temp;
    }

    // Delete from End
    void deleteFromEnd() {

        if (head == nullptr) {
            cout << "List is Empty\n";
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Student* temp = head;

        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    // Delete from Position
    void deleteFromPosition(int pos) {

        if (head == nullptr) {
            cout << "List is Empty\n";
            return;
        }

        if (pos == 1) {
            deleteFromBeginning();
            return;
        }

        Student* temp = head;

        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Invalid Position\n";
            return;
        }

        Student* nodeToDelete = temp->next;

        temp->next = nodeToDelete->next;

        delete nodeToDelete;
    }

    // Display List
    void display() {

        if (head == nullptr) {
            cout << "List is Empty\n";
            return;
        }

        Student* temp = head;

        while (temp != nullptr) {
            cout << "Roll No: " << temp->rollNo
                 << ", Name: " << temp->name
                 << ", Marks: " << temp->marks
                 << endl;

            temp = temp->next;
        }
    }
};

int main() {

    LinkedList list;

    list.insertAtEnd(101, "Pankaj", 85.5);
    list.insertAtEnd(102, "Rahul", 90);

    list.insertAtBeginning(100, "Aman", 75);

    list.insertAtPosition(2, 111, "Priya", 88);

    cout << "Students:\n";
    list.display();

    list.deleteFromBeginning();

    cout << "\nAfter Delete Beginning:\n";
    list.display();

    list.deleteFromEnd();

    cout << "\nAfter Delete End:\n";
    list.display();

    list.deleteFromPosition(2);

    cout << "\nAfter Delete Position 2:\n";
    list.display();

    return 0;
}