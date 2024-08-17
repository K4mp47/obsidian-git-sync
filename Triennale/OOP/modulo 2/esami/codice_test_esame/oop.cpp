#include <iostream>

using namespace std;

class Employee
{

private:
    // attributes
    string name;
    string Company;
    int Age;

public:
    static int count; // static attribute

    Employee(string name, string Company, int Age)
    {
        this->name = name;
        this->Company = Company;
        this->Age = Age;
        count++;
    }

    void introduceYourself()
    {
        cout << "Name - " << name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
    }
};

int Employee::count = 0; // static attribute initialization

int main()
{
    Employee employee1 = Employee("John", "Google", 35); // classe istanziata nella stack

    employee1.introduceYourself(); // richiamo il metodo pubblico della classe
    Employee employee2 = Employee("Alice", "Amazon", 25);
    Employee employee3 = Employee("Bob", "Facebook", 45);

    cout << "Number of employees: " << Employee::count << endl; // richiamo l'attributo statico della classe
    return 0;
}