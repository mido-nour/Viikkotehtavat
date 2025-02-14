#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int age;

    void printStudentInfo() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};



int main ()
{
    int selection =0;
    vector<Student>studentList;

    do
    {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
        case 0: {
            Student uusiopiskelja;
           cout << "luoda opiskeljan nimi: ";
           cin >> uusiopiskelja.name;
           cout << " luoda opiskelijan ika: ";
           cin>>uusiopiskelja.age;
           studentList.push_back(uusiopiskelja);
            cout << "Opiskelija on lisatty systemin ;) \n";
            break;
        }
        case 1: {
            cout << "Opiskeljan tiedot ;D\n";
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;
        }
        case 2: {
            sort(studentList.begin(), studentList.end(),
                 [](const Student& a, const Student& b) {
                     return a.name < b.name;
                 });
            cout << "Opiskelijat jarjestetty A-Z mukaisesti:\n";
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;
        }
        case 3: {
            sort(studentList.begin(), studentList.end(),
                 [](const Student& a, const Student& b) {
                     return a.age < b.age;
                 });
            cout << "Opiskelijat jarjestetty pienesta isomaksi:\n";
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;
        }
        case 4: {
            string searchopiskelja;
            cout << "Anna etsittavan opiskelijan nimi: ";
            cin>>searchopiskelja;

            auto it = find_if(studentList.begin(), studentList.end(),
            [&searchopiskelja](const Student& s) {
            return s.name == searchopiskelja;
            });

            if (it != studentList.end()) {
                cout << "Opiskelija loytyi;) :\n";
                it->printStudentInfo();
            } else {
                cout << "nimi joka kirjoitat ei olemassa yrtia uudelen;( \n";
            }
            break;
        }
        default:
            cout << "Vaara valinta, yrita uudelleen...\n";
            break;
        }
    } while (selection != 5);

    return 0;
}




