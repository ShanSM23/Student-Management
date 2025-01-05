#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;
class Student
{
private:
    string firstname, lastname, branch;
    int rollNo;

public:
    Student(string firstName, string lastName, int RollNo, string Branch)
    {
        firstname = firstName;
        lastname = lastName;
        rollNo = RollNo;
        branch = Branch;
    }
    void setfirstName(string fn)
    {
        firstname = fn;
    }
    void setlastName(string ln)
    {
        lastname = ln;
    }
    void setRollNo(int r)
    {
        rollNo = r;
    }
    void setBranch(string s)
    {
        branch = s;
    }
    string getName()
    {
        string fullname = firstname + " " + lastname;
        return fullname;
    }
    int getRollNo()
    {
        return rollNo;
    }
    string getBranch()
    {
        return branch;
    }
};

class College
{
private:
    vector<Student> vec;

public:
    void add(string firstName, string lastName, int RollNo, string Branch)
    {
        Student student(firstName, lastName, RollNo, Branch);
        vec.push_back(student);
    }
    void display()
    {
        if (vec.empty())
        {
            cout << "\n************** NO STUDENT IS ENROLLED ****************" << endl
                 << endl;
        }
        for (int i = 0; i < vec.size(); i++)
        {

            cout << "Name: " << vec[i].getName() << endl;
            cout << "Roll No: " << vec[i].getRollNo() << endl;
            cout << "Branch: " << vec[i].getBranch() << endl
                 << endl;
        }
    }

    void update()
    {
        if (vec.empty())
        {
            cout << "\n****************** NO INFO TO UPDATE ***************" << endl
                 << endl;
            return;
        }
        int rn;
        cout << "Enter Roll No for search and update: ";
        cin >> rn;
        bool found = false;
        for (int i = 0; i < vec.size(); i++)
        {
            if (rn == vec[i].getRollNo())
            {
                cout << "<--------- Old Records --------->" << endl
                     << endl;
                cout << "Name: " << vec[i].getName() << endl;
                cout << "RollNo: " << vec[i].getRollNo() << endl;
                cout << "Branch: " << vec[i].getBranch() << endl
                     << endl;
                cout << "<--------- Update --------->" << endl
                     << endl;
                int r;
                string s;
                cout << "Enter New Roll No: ";
                // cin >> r;
                if (!(cin >> r))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\n*********** Invalid Input ************ \n <-------- Please enter a number -------->." << endl
                         << endl;
                    continue;
                }
                vec[i].setRollNo(r);
                cout << "Enter New Branch: ";
                cin >> s;
                
                vec[i].setBranch(s);
                cout << "\n<---------- STUDENT INFO UPDATED -------> " << endl
                     << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "\n******** No student found with Roll No: " << rn << " ************" << endl;
        }
    }
};
int main()
{
    College college;
    string fisrtName, lastName, Branch;
    int RollNo;
    cout << "\n*********** College Management System ************" << endl
         << endl;
    int value;
    while (true)
    {
        cout << "Enter 1 for add student:" << endl;
        cout << "Enter 2 for display students:" << endl;
        cout << "Enter 3 for update record:" << endl;
        cout << "Enter 0 for exit from program:" << endl
             << endl;
        cout << "Enter Choice: ";

        if (!(cin >> value))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n*********** Invalid Input ************ \n <-------- Please enter a number -------->." << endl
                 << endl;
            continue;
        }
        // cin >> value;
        if (value == 1)
        {
            system("cls");
            cout << "Enter First Name: ";
            cin >> fisrtName;
            
            cout << "Enter Last Name: ";
            cin >> lastName;
            cout << "Enter Roll No: ";
            // cin >> RollNo;
            if (!(cin >> RollNo))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\n*********** Invalid Input ************ \n <-------- Please enter a number -------->." << endl
                     << endl;
                continue;
            }
            cout << "Enter Branch: ";
            cin >> Branch;
            
            college.add(fisrtName, lastName, RollNo, Branch);
            cout << endl
                 << endl;
        }
        else if (value == 2)
        {
            system("cls");
            college.display();
        }
        else if (value == 3)
        {
            system("cls");
            college.update();
        }
        else if (value == 0)
        {
            exit(0);
        }
        else
        {
            system("cls");
            cout << "\n********* Invalid Input **********" << endl
                 << endl;
        }
    }
}