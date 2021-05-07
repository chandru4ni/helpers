/* 
 * A C++ program to read data of an employee and compute the net salary of the employee
 * including the components - basic salary, EPF and SOCSO
*/

#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <string>
#include <list>
#include <iterator>
#include <iomanip>
using namespace std;
//#include<conio.h>


class Employee
{
    char emp_name[30], emp_scheme;
    float basic_salary, epf, socso, gross_salary;
    map <char, vector<float>> schemeSalaryMap;

    public:

    // Constructor for the class
    Employee()
    {

        basic_salary = 0.0;
        epf = 0.0;
        socso = 0.0;
        gross_salary = 0.0;

        schemeSalaryMap.insert(pair<char, vector<float>>('A', {11, 5}));
        schemeSalaryMap.insert(pair<char, vector<float>>('B', {10, 4.5}));
        schemeSalaryMap.insert(pair<char, vector<float>>('C', {9, 4}));
        schemeSalaryMap.insert(pair<char, vector<float>>('D', {8, 4}));
    }

    void displaySchemeDetails()
    {
        for(auto& pair : schemeSalaryMap) 
        {
            std::cout << pair.first << ":";
            cout << pair.second[0] << " " << pair.second[1];
            std::cout << "\n";
        }
    }

    float calcEPF(char emp_scheme, float basic_salary)
    {
        for(auto& pair : schemeSalaryMap) 
        {
            if (emp_scheme == pair.first)
            {
                epf = basic_salary * (pair.second[0] / 100);
            }
        }
    return epf;
    }

    float calcSOCSO(char emp_scheme, float basic_salary)
    {
        for(auto& pair : schemeSalaryMap) 
        {
            if (emp_scheme == pair.first)
            {
                socso = basic_salary * (pair.second[1] / 100);
            }
        }
    return socso;
    }

    float find_gross_salary()
    {
        gross_salary = basic_salary + epf + socso;
        return gross_salary;
    }

    void display_emp_details()
    {
        cout<<"\n\nEmployee Details:\n";
        cout<<"\nEmployee Name: "<<emp_name;
        cout << "\nBasic Salary: "<<basic_salary;
        cout << "\nEPF: "<<epf;
        cout << "\nSOCSO: "<<socso;
        cout<<"\nNet Salary: "<<gross_salary;
        cout<<"\n--------------------------\n";
    }

    void read_emp_details()
    {
        cout << "\n\nEnter Employee Details:";
        cout << "\nEmployee Name: ";
        cin.getline(emp_name,sizeof(emp_name));
        cout <<"Basic Salary: ";
        cin >> basic_salary;
        cout << "Employee Scheme (A/B/C/D): ";
        cin >> emp_scheme;
    }

    float getEmpScheme()
    {
        return emp_scheme;
    }
    float getBasicSalary()
    {
        return basic_salary;
    }

    float getEPF()
    {
        return epf;
    }

    float getSOCSO()
    {
        return socso;
    }
};


int main()
{
    class Employee emp;
    std::cout << std::fixed;
    std::cout << std::setprecision(2);

    //emp.displaySchemeDetails();

    emp.read_emp_details();

    float basicSalary = emp.getBasicSalary();
    char empScheme = emp.getEmpScheme();
    float empEPF = emp.calcEPF(empScheme, basicSalary);
    float empSOCSO = emp.calcSOCSO(empScheme, basicSalary);

    emp.find_gross_salary();

    emp.display_emp_details();

    return 0;
}
