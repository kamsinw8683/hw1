#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cassert>

#include "ulliststr.h"

// Helper function to print test result
void printTestResult(const std::string& testName, bool passed) {
    std::cout << testName << ": " << (passed ? "PASSED" : "FAILED") << std::endl;
}

// Test basic push_back functionality
void testPushBack() {
    std::cout << "Running Push Back Tests..." << std::endl;
    
    // Test pushing to an empty list
    {
        ULListStr list;
        list.push_back("first");
        assert(list.size() == 1);
        assert(list.front() == "first");
        assert(list.back() == "first");
        printTestResult("Push Back to Empty List", true);
    }
    
    // Test pushing multiple elements
    {
        ULListStr list;
        for (int i = 0; i < 15; ++i) {
            list.push_back(std::to_string(i));
        }
        assert(list.size() == 15);
        assert(list.front() == "0");
        assert(list.back() == "14");
        printTestResult("Push Back Multiple Elements", true);
    }
    
    // Test pushing beyond single array capacity
    {
        ULListStr list;
        for (int i = 0; i < 25; ++i) {
            list.push_back(std::to_string(i));
        }
        assert(list.size() == 25);
        assert(list.front() == "0");
        assert(list.back() == "24");
        printTestResult("Push Back Multiple Nodes", true);
    }
}

// Test basic push_front functionality
void testPushFront() {
    std::cout << "Running Push Front Tests..." << std::endl;
    
    // Test pushing to an empty list
    {
        ULListStr list;
        list.push_front("first");
        assert(list.size() == 1);
        assert(list.front() == "first");
        assert(list.back() == "first");
        printTestResult("Push Front to Empty List", true);
    }
    
    // Test pushing multiple elements
    {
        ULListStr list;
        for (int i = 0; i < 15; ++i) {
            list.push_front(std::to_string(i));
        }
        assert(list.size() == 15);
        assert(list.front() == "14");
        assert(list.back() == "0");
        printTestResult("Push Front Multiple Elements", true);
    }
    
    // Test pushing beyond single array capacity
    {
        ULListStr list;
        for (int i = 0; i < 25; ++i) {
            list.push_front(std::to_string(i));
        }
        assert(list.size() == 25);
        assert(list.front() == "24");
        assert(list.back() == "0");
        printTestResult("Push Front Multiple Nodes", true);
    }
}

// Test pop_back functionality
void testPopBack() {
    std::cout << "Running Pop Back Tests..." << std::endl;
    
    // Test popping from a single-element list
    {
        ULListStr list;
        list.push_back("single");
        list.pop_back();
        assert(list.size() == 0);
        printTestResult("Pop Back Single Element", true);
    }
    
    // Test popping multiple elements
    {
        ULListStr list;
        for (int i = 0; i < 15; ++i) {
            list.push_back(std::to_string(i));
        }
        for (int i = 14; i >= 0; --i) {
            assert(list.back() == std::to_string(i));
            list.pop_back();
        }
        assert(list.size() == 0);
        printTestResult("Pop Back Multiple Elements", true);
    }
}

// Test pop_front functionality
void testPopFront() {
    std::cout << "Running Pop Front Tests..." << std::endl;
    
    // Test popping from a single-element list
    {
        ULListStr list;
        list.push_front("single");
        list.pop_front();
        assert(list.size() == 0);
        printTestResult("Pop Front Single Element", true);
    }
    
    // Test popping multiple elements
    {
        ULListStr list;
        for (int i = 0; i < 15; ++i) {
            list.push_front(std::to_string(i));
        }
        for (int i = 14; i >= 0; --i) {
            assert(list.front() == std::to_string(i));
            list.pop_front();
        }
        assert(list.size() == 0);
        printTestResult("Pop Front Multiple Elements", true);
    }
}

// Test get functionality
void testGet() {
    std::cout << "Running Get Tests..." << std::endl;
    
    // Test getting elements
    {
        ULListStr list;
        for (int i = 0; i < 25; ++i) {
            list.push_back(std::to_string(i));
        }
        
        for (int i = 0; i < 25; ++i) {
            assert(list.get(i) == std::to_string(i));
        }
        printTestResult("Get Elements", true);
    }
}

// Test mixed operations
void testMixedOperations() {
    std::cout << "Running Mixed Operations Tests..." << std::endl;
    
    // Test mix of push and pop
    {
        ULListStr list;
        list.push_back("A");
        list.push_front("B");
        assert(list.front() == "B");
        assert(list.back() == "A");
        assert(list.size() == 2);
        
        list.pop_back();
        assert(list.front() == "B");
        assert(list.back() == "B");
        assert(list.size() == 1);
        
        list.pop_front();
        assert(list.size() == 0);
        printTestResult("Mixed Push and Pop", true);
    }
}

int main() {
    try {
        testPushBack();
        testPushFront();
        testPopBack();
        testPopFront();
        testGet();
        testMixedOperations();
        
        std::cout << "All ULListStr tests passed successfully!" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
