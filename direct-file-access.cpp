/*To implement Direct Access File */

#include <iostream>
#include <iomanip>
using namespace std;
#define max 10

struct employee
{
    string name;
    string designation;
    long int employee_id;
    int salary;
};

int num = -1;
employee emp[max];

void insert()
{
    if (num < max)
    {
        num++;
        cout << "Enter Employee Name: " << endl;
        cin >> emp[num].name;
        cout << "Enter Employee ID: " << endl;
        cin >> emp[num].employee_id;
        cout << "Enter Employee Designation: " << endl;
        cin >> emp[num].designation;
        cout << "Enter Employee Salary: " << endl;
        cin >> emp[num].salary;
    }
    else
    {
        cout << "\nEmployee Table Full\n";
    }
}

void deleteIndex(int i)
{
    for (int j = i; j < num; j++)
    {
        emp[j].name = emp[j + 1].name;
        emp[j].employee_id = emp[j + 1].employee_id;
        emp[j].designation = emp[j + 1].designation;
        emp[j].salary = emp[j + 1].salary;
    }
    return;
}

void displayAllRecords()
{
    if (num == -1)
    {
        cout << "Employee Table is Empty";
    }
    else
    {
        cout << endl
             << setw(5) << "Employee Id" << setw(10) << "Employee Name" << setw(18) << "Designation" << setw(10) << "Salary\n";
        for (int i = 0; i < num + 1; i++)
        {
            cout << setw(5) << emp[i].employee_id << setw(10) << emp[i].name << setw(18) << emp[i].designation << setw(10) << emp[i].salary << endl;
        }
    }
}

void deleteRecord()
{
    int employee_id;
    cout << "\n Enter Employee Id to Delete the Record: ";
    cin >> employee_id;

    for (int i = 0; i < num + 1; i++)
    {
        if (emp[i].employee_id == employee_id)
        {
            deleteIndex(i);
            num--;
            break;
        }
    }
}

void searchRecord()
{
    int employee_id;
    cout << "\n Enter Employee Id whose record to be searched: ";
    cin >> employee_id;

    for (int i = 0; i < num + 1; i++)
    {
        if (emp[i].employee_id == employee_id)
        {
            cout << endl
                 << setw(5) << "Employee Id" << setw(10) << "Employee Name" << setw(18) << "Designation" << setw(10) << "Salary\n";
            cout << setw(5) << emp[i].employee_id << setw(10) << emp[i].name << setw(18) << emp[i].designation << setw(10) << emp[i].salary << endl;
            return;
        }
    }
    cout << "\n Employee Record not found";
}

int main()
{
    int option = 0;
    while (option != 5)
    {
        cout << "\n *************************** Employee Management System **********************\n ";
        cout << "\n 1. Insert Record";
        cout << "\n 2. Display All Records";
        cout << "\n 3. Delete a Record using employee ID";
        cout << "\n 4. Search for a Record using Employee ID";
        cout << "\n 5. Exit";

        cout << "\n\n Choose a correct Option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            insert();
            break;
        case 2:
            displayAllRecords();
            break;
        case 3:
            deleteRecord();
            break;
        case 4:
            searchRecord();
            break;
        case 5:
            cout << "Successfully Exited";
            break;
        default:
            cout << "Enter valid option";
            break;
        }
    }
    return 0;
}