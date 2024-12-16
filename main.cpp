#include <iostream>
#include "Namespace.hpp"

int main()
{
    // Use functions and variables from MyNamespace1
    MyNamespace1::printDetails1();
    MyNamespace1::setDetails1("Hello from Namespace1", 100);
    MyNamespace1::printDetails1();

    // Use functions and variables from MyNamespace2
    MyNamespace2::printDetails2();
    MyNamespace2::setDetails2("Hello from Namespace2", 200);
    MyNamespace2::printDetails2();

    return 0;
}