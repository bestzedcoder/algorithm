/*
Description
Perform a sequence of operations over a stack, each element is an integer:
PUSH v: push a value v into the stack
POP: remove an element out of the stack and print this element to stdout (print NULL if the stack is empty)
Input
Each line contains a command (operration) of type 
PUSH  v
POP
Output
Write the results of POP operations (each result is written in a line)
Example
Input
PUSH 1
PUSH 2
PUSH 3
POP
POP
PUSH 4
PUSH 5
POP
#
Output
3
2
5
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* next;
};


Node* PUSH(Node* head, int value) {
    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = nullptr;

    if (head == nullptr) return newNode; 
    newNode->next = head;
    return newNode;
}

Node* POP(Node* head) {
    if (head == nullptr) {
        cout << "NULL\n";
        return nullptr;
    }
    Node* res = head->next;
    cout << head->value << "\n";  
    delete head;
    return res;
}

int main() {
    Node* head = nullptr; 
    string s;

    while (true) {
        cin >> s;
        if (s == "PUSH") {
            int value;
            cin >> value;
            head = PUSH(head, value);
        } else if (s == "POP") {
            head = POP(head);
        } else if (s == "#") {
            break;
        }
    }
    return 0;
}