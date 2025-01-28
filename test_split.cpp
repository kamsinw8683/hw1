/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include <cassert>
#include "split.h"
#include <iostream>
// Helper function to create a linked list from an array
Node* createList(int arr[], int size) {
    Node* head = nullptr;
    for (int i = size - 1; i >= 0; --i) {
        head = new Node(arr[i], head);
    }
    return head;
}

// Helper function to verify list contents
bool verifyList(Node* list, int expected[], int size) {
    for (int i = 0; i < size; i++) {
        if (list == nullptr || list->value != expected[i]) {
            return false;
        }
        list = list->next;
    }
    return list == nullptr;
}
void printList(Node*list, int size)
{
    for(int i =0; i < size; i++)
    {
        std::cout << list->value << std::endl;
        list = list->next;
    }
}

// Helper function to free memory
void freeList(Node* list) {
    while (list != nullptr) {
        Node* temp = list;
        list = list->next;
        delete temp;
    }
}

void testEmptyList() {
    Node* in = nullptr;
    Node* odds = nullptr;
    Node* evens = nullptr;
    
    split(in, odds, evens);
    
    assert(in == nullptr);
    assert(odds == nullptr);
    assert(evens == nullptr);
    
    std::cout << "Empty list test passed" << std::endl;
}

void testAllOddList() {
    int arr[] = {1, 3, 5, 7, 9};
    Node* in = createList(arr, 5);
    Node* odds = nullptr;
    Node* evens = nullptr;
    
    split(in, odds, evens);
    
    assert(in == nullptr);
    assert(evens == nullptr);
    assert(verifyList(odds, arr, 5));
    
    freeList(odds);
    std::cout << "All odd list test passed" << std::endl;
}

void testAllEvenList() {
    int arr[] = {2, 4, 6, 8, 10};
    Node* in = createList(arr, 5);
    Node* odds = nullptr;
    Node* evens = nullptr;
    
    split(in, odds, evens);
    
    assert(in == nullptr);
    assert(odds == nullptr);
    assert(verifyList(evens, arr, 5));
    
    freeList(evens);
    std::cout << "All even list test passed" << std::endl;
}

void testMixedList() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* in = createList(arr, 10);
    Node* odds = nullptr;
    Node* evens = nullptr;
    
    split(in, odds, evens);
    
    assert(in == nullptr);
    
    int expectedOdds[] = {1, 3, 5, 7, 9};
    int expectedEvens[] = {2, 4, 6, 8, 10};
    printList(evens,5);
    assert(verifyList(odds, expectedOdds, 5));
    assert(verifyList(evens, expectedEvens, 5));
    
    freeList(odds);
    freeList(evens);
    freelist(in);
    std::cout << "Mixed list test passed" << std::endl;
}

void testSingleElementList() {
    // Odd single element
    {
        int arr[] = {1};
        Node* in = createList(arr, 1);
        Node* odds = nullptr;
        Node* evens = nullptr;
        
        split(in, odds, evens);
        
        assert(in == nullptr);
        assert(evens == nullptr);
        assert(verifyList(odds, arr, 1));
        
        freeList(odds);
    }
    
    // Even single element
    {
        int arr[] = {2};
        Node* in = createList(arr, 1);
        Node* odds = nullptr;
        Node* evens = nullptr;
        
        split(in, odds, evens);
        
        assert(in == nullptr);
        assert(odds == nullptr);
        assert(verifyList(evens, arr, 1));
        
        freeList(evens);
    }
    
    std::cout << "Single element list test passed" << std::endl;
}

int main() {
    testEmptyList();
    testAllOddList();
    testAllEvenList();
    testMixedList();
    testSingleElementList();
    
    std::cout << "All split tests passed!" << std::endl;
    return 0;
}
