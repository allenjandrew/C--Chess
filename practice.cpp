#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

// Function declarations
string myFunction(string country = "Norway");
void swapNums(int &x, int &y);
void modifyStr(string &str);

// Function overloading
int myFunction(int x);
float myFunction(float x);
double myFunction(double x, double y);

// Global variable
int MYGLOBALVAR = 15;
string FILENAME = "test.txt";

int main()
{

    string input;

    getline(cin, input);

    cout << "You typed: " << input << endl;

    // Creating an array
    string cars[4] = {"Volvo", "BMW", "Ford", "Mazda"};
    // Creating a vector - a dynamic array
    vector<string> cars2 = {"Volvo", "BMW", "Ford"};
    // Adding an element to a vector
    cars2.push_back("Tesla");

    // Getting the size of various data structures
    int x = input.size();
    int y = sizeof(cars) / sizeof(cars[0]);
    int z = cars2.size();

    // Basic for-each loop
    for (string car : cars)
    {
        cout << car << endl;
    }

    struct
    {                    // Structure declaration
        int myNum;       // Member (int variable)
        string myString; // Member (string variable)
    } myStructure;       // Structure variable

    enum Level
    {
        LOW,
        MEDIUM,
        HIGH
    };
    enum Level myVar = MEDIUM;

    string food = "Pizza"; // food variable
    string &meal = food;   // reference to food
    cout << &food << "\n"; // Outputs hexadecimal memory address of food
    string *ptr = &food;   // A pointer variable that stores the address of food
    // Dereference: Output the value of food with the pointer (Pizza)
    cout << *ptr << "\n";

    // Function call
    string country = myFunction();

    MyClass myObj; // Create an object of MyClass

    // Access attributes and set values
    myObj.myNum = 15;
    myObj.myString = "Some text";

    // Create and open a text file
    ofstream MyFile(FILENAME);
    // Write to the file
    MyFile << "Files can be tricky, but it is fun enough!";
    // Close the file
    MyFile.close();

    // Create a text string, which is used to output the text file
    string myText;
    // Read from the text file
    ifstream MyReadFile("filename.txt");
    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, myText))
    {
        // Output the text from the file
        cout << myText;
    }
    // Close the file
    MyReadFile.close();

    try
    {
        // Block of code to try
        throw myText; // Throw an exception when a problem arise
    }
    catch (string error) // or catch (...) to catch all exceptions
    {
        // Block of code to handle errors
    }

    // Get the timestamp for the current date and time
    time_t timestamp;
    time(&timestamp);
    // or use this:
    timestamp = time(NULL);
    // Display the date and time represented by the timestamp
    cout << ctime(&timestamp);

    // Always return 0
    return 0;
}

// Function definitions
string myFunction(string country = "Norway")
{
    cout << "I just got executed!";
    return country;
}

void swapNums(int &x, int &y)
{
    int z = x;
    x = y;
    y = z;
}

void modifyStr(string &str)
{
    str += " World!";
}

// Class declaration
class MyClass
{                     // The class
public:               // Access specifier
    int myNum;        // Attribute (int variable)
    string myString;  // Attribute (string variable)
    void myMethod();  // Method/function declaration
    MyClass() {}      // Constructor (note: no return type)
private:              // Access specifier
    int myPrivateNum; // Private attribute
};

// Method/function definition outside the class
void MyClass::myMethod()
{
    cout << "Hello World!";
}

class SecondClass : public MyClass
{
protected:
    int salary;
};

// Derived class from multiple base classes
class ThirdClass : public SecondClass, public MyClass
{
    void setSalary(int s)
    {
        salary = s;
    }
    int getSalary()
    {
        return salary;
    }
};