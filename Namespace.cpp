#include "Namespace.hpp"
#include <iostream>

// Definitions for MyNamespace1
namespace MyNamespace1
{
    std::string myString1 = "Default String 1";
    int myInt1 = 0;

    void printDetails1()
    {
        std::cout << "Namespace1 - String: " << myString1 << ", Integer: " << myInt1 << std::endl;
    }

    void setDetails1(const std::string &str, int num)
    {
        myString1 = str;
        myInt1 = num;
    }
}

// Definitions for MyNamespace2
namespace MyNamespace2
{
    std::string myString2 = "Default String 2";
    int myInt2 = 0;

    void printDetails2()
    {
        std::cout << "Namespace2 - String: " << myString2 << ", Integer: " << myInt2 << std::endl;
    }

    void setDetails2(const std::string &str, int num)
    {
        myString2 = str;
        myInt2 = num;
    }
}