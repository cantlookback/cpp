#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Student{
public:
    Student(string m_FIO, vector<int> m_marks) : 
        marks(m_marks), FIO(m_FIO) {}

    friend ostream& operator<<(ostream& out, vector<Student> students);

private:
    vector<int> marks;
    string FIO;
};

class Group{
public:
    Group(int m_doneSemesters, string m_groupCode, vector<Student> m_students) : 
        amountOfStudents(m_students.size()), doneSemesters(m_doneSemesters), groupCode(m_groupCode)
    {
        for (Student student : m_students){
            students.push_back(student);
        }
    }

    void addStudent(Student newStudent){
        students.push_back(newStudent);
    }

    friend class University; 

private:
    vector<Student> students;
    string groupCode;
    int amountOfStudents, doneSemesters;
};

class University{
public:
    University(){}

    University(vector<Group> m_groups){
        for (Group group : m_groups){
            groups.push_back(group);
        }
    }

    void printGroup(){
        for (Group group : groups){
            cout << "Группа: " << group.groupCode << endl;
            cout << "Кол-во студентов: " << group.amountOfStudents << endl;
            cout << "Закончено семестров: " << group.doneSemesters << endl;
            cout << group.students << endl;
        }
        
    }

    void addGroup(Group newGroup){
        groups.push_back(newGroup);
    }


private:
    vector<Group> groups;
};

ostream& operator<<(ostream& out, vector<Student> students){

    for (Student student : students){
        out << student.FIO << endl << "Оценки: ";
        for (int mark : student.marks){
            out << mark << " ";
        }
        cout << endl;
    }

    return out;
}

int main(){
    ofstream output;
    ifstream input;
    input.open("database.txt", ofstream::app);

    string groupCode, FIO;
    int doneSemesters, amountOfStudents;

    vector<int> marks;
    vector<Student> students;

    University NSTU;

    while (!input.eof()){
        input >> groupCode;
        input >> amountOfStudents;
        input >> doneSemesters; 

         for (unsigned i = 0; i < amountOfStudents; i++){
             input.ignore();
             getline(input, FIO);
             for (unsigned k = 0; k < 5; k++){
                 int m;
                input >> m;
                marks.push_back(m);
            }
            students.push_back(Student(FIO, marks));
            marks.clear();
        }
        NSTU.addGroup(Group(doneSemesters, groupCode, students));
        students.clear();
    }

    NSTU.printGroup();

    return 0;
}