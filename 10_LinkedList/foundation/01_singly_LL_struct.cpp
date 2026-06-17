#include <iostream> 
#include <bits/stdc++.h> 
using namespace std; 

// Student  Singly linked List 
struct Student{
    int rollNo; 
    string name; 
    float marks; 
};

// create Node; 
struct Node{
    Student data; 
    Node* next; 
}; 

// Creating a node 
Node* createNode(int rollNo, string name, float marks){
    Node* newNode = new Node; // Created new node same as malloc in C 

    // Inserting data into the node; 
    newNode->data.rollNo = rollNo; 
    newNode->data.name = name; 
    newNode->data.marks = marks; 
    newNode->next = nullptr; 

    return newNode; 
}

// insert at Beginning 
void insertAtBeginning(Node*& head, int rollNo, string name, float marks){
    Node* newNode = createNode(rollNo, name, marks); 
    newNode->next = head; 
    head = newNode; 
}

// Insert at End 
void insertAtEnd(Node*& head, int rollNo, string name, float marks){
    Node* newNode = createNode(rollNo, name, marks); 

    if(head == nullptr){
        head = newNode; 
        return; 
    }

    Node* temp = head; 

    while(temp->next != nullptr){
        temp = temp->next; 
    }

    temp->next = newNode; 
}


// Insert At Given Position 
void insertAtPosition(Node*& head, int pos, int rollNo, string name, float marks){
    if(pos == 1){
        insertAtBeginning(head, rollNo, name, marks); 
        return; 
    }

    Node* newNode = createNode(rollNo, name, marks); 

    Node* temp = head; 
    for(int i = 1; i < pos-1 && temp != nullptr; i++){
        temp = temp->next; 
    }

    if(temp == nullptr){
        cout << "Invalid position" << endl; 
        delete newNode; // free memory location like free in C
        return; 
    }

    newNode->next = temp->next; 
    temp->next = newNode; 
}

// Delete from Beginning 
void deleteFromBeginning(Node*& head){
    if(head == nullptr){
        cout << "List is Empty" << endl; 
        return; 
    }

    Node* temp = head; 
    head = head->next; 

    delete temp; 
}

// Delete from End
void deleteFromEnd(Node*& head){
    if(head == nullptr){
        cout << "List is Empty" << endl; 
        return; 
    }

    if(head->next == nullptr){
        delete head; 
        head = nullptr; 
        return; 
    }

    Node* temp = head; 

    while(temp->next->next != nullptr){
        temp = temp->next; 
    }

    delete temp->next; 
    temp->next = nullptr; 
}


// Delete from Given Position 
void deleteFromPosition(Node*& head, int pos) {

    if (head == nullptr) {
        cout << "List is Empty\n";
        return;
    }

    if (pos == 1) {
        deleteFromBeginning(head);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Invalid Position\n";
        return;
    }

    Node* nodeToDelete = temp->next;

    temp->next = nodeToDelete->next;

    delete nodeToDelete;
}

// Display All Students 
void display(Node* head) {

    if (head == nullptr) {
        cout << "List is Empty\n";
        return;
    }

    Node* temp = head;

    while (temp != nullptr) {

        cout << "Roll No: " << temp->data.rollNo
             << ", Name: " << temp->data.name
             << ", Marks: " << temp->data.marks
             << endl;

        temp = temp->next;
    }
}

int main() {

    Node* head = nullptr;

    insertAtEnd(head, 101, "Pankaj", 85.5);
    insertAtEnd(head, 102, "Rahul", 90);
    insertAtBeginning(head, 100, "Aman", 75);

    insertAtPosition(head, 2, 111, "Priya", 88);

    cout << "Students:\n";
    display(head);

    deleteFromBeginning(head);

    cout << "\nAfter Delete Beginning:\n";
    display(head);

    deleteFromEnd(head);

    cout << "\nAfter Delete End:\n";
    display(head);

    deleteFromPosition(head, 2);

    cout << "\nAfter Delete Position 2:\n";
    display(head);

    return 0;
}

