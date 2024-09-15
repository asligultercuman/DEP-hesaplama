#include <iostream>
using namespace std;

#define threshold_score 3.25 // score that DEP score must be greater than or equal to

class Student {
public:
    double student_score;
    double uni_score;
    float GPA;
    bool isEligible;
    Student* next;

    //Student() : student_score(0), uni_score(0), GPA(0), isEligible(false), next(nullptr) {}
	Student(){ 
		student_score = 0;
		uni_score = 0;
		GPA = 0;
		isEligible = false;
		next = nullptr; 
	}

    void insertStudent(Student*& head);
    void calculateDEP();
    void printList(Student* head);
};

void Student::insertStudent(Student*& head) {
    Student* newStudent = new Student();

    cout << "Student's university entrance exam score: ";
    cin >> newStudent->student_score;

    cout << "Minimum entrance score for the transfer program: ";
    cin >> newStudent->uni_score;

    cout << "Your GPA: ";
    cin >> newStudent->GPA;
    cout << "\n";

    newStudent->calculateDEP();

    if (head == nullptr) {
        head = newStudent;
    } else {
        Student* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}

void Student::calculateDEP() {
    double DEP = (student_score / uni_score) * GPA;
    isEligible = (DEP >= threshold_score);
}

void Student::printList(Student* head) {
    if (head == nullptr) {
        cout << "List empty" << endl;
        return;
    }

    Student* temp = head;
    int studentNumber = 1;

    while (temp != nullptr) {
        cout << "Student " << studentNumber << ": " << temp->student_score << " " << temp->uni_score << " " << temp->GPA << "\n";
        if (temp->isEligible)
            cout << "Eligible to apply for transfer applications.\n";
        else
            cout << "Rejected.\n";

        temp = temp->next;
        studentNumber++;
    }
}

int main() {
    Student* head = nullptr;

    char control;
    while (true) {
        cout << "\nPress 'x' to exit, anything to go on: ";
        cin >> control;
        if (control == 'x' || control == 'X')
            break;

        head->insertStudent(head);
    }

    head->printList(head);

    return 0;
}