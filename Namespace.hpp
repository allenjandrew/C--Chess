#ifndef NAMESPACE_HPP
#define NAMESPACE_HPP

#include <string>

namespace MyNamespace1
{
    // Variable declarations
    extern std::string myString1;
    extern int myInt1;

    // Function declarations
    void printDetails1();
    void setDetails1(const std::string &str, int num);
}

namespace MyNamespace2
{
    // Variable declarations
    extern std::string myString2;
    extern int myInt2;

    // Function declarations
    void printDetails2();
    void setDetails2(const std::string &str, int num);
}

#endif // NAMESPACE_HPP