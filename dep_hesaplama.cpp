//Code for calculating the DEP score and determining whether the university student is eligible to apply for transfer applications.

#include <iostream> 
using namespace std; 

#define threshold_score 3.25 // score that DEP score must be greater than or equal to

class Node { 
public: 
    double student_score; 
	double uni_score;
	float GPA;
	Node* next; 

	// Default constructor 
	Node() 
	{ 
		student_score = uni_score = GPA = 0; 
		next = NULL; 
	} 
}; 

class Linkedlist { 
	Node* head; 

public: 
	Linkedlist() { 
		head = NULL; 
	} 
	                        //bool isEligible;
	void insertNode(); 
	double calculateDEP();
	void printList(); 
};

void Linkedlist::insertNode() 
{ 
	Node* newNode = new Node(); 
	cout << "Ogrencinin universiteye kayit oldugu merkezi yerlestirme puani: ";
	cin >> newNode->student_score;

	cout << "Yatay gecis icin basvurulan programin, ogrencinin kayit oldugu yildaki, merkezi yerlestirme taban puani: ";
	cin >> newNode->uni_score;

	cout << "Ortalamaniz (gpa): ";
	cin >> newNode->GPA;
	cout << "\n";

	if (head == NULL) { 
		head = newNode; 
		return; 
	} 

	// Traverse till end of list 
	Node* temp = head; 
	while (temp->next != NULL) { 
		temp = temp->next; 
	} 

	temp->next = newNode; 
}

double Linkedlist::calculateDEP(){ 
	double DEP = (double)(head->student_score / head->uni_score) * (double)head->GPA;
	return DEP;
}

void Linkedlist::printList() 
{ 
	Node* temp = head; 

	// Check for empty list. 
	if (head == NULL) { 
		cout << "List empty" << endl; 
		return; 
	} 

	// Traverse the list. 
	while (temp != NULL) { 
		int *a = new int(1);
		cout << "Student "<< *a << ": " << temp->student_score << " " << temp->uni_score << temp->GPA << "\n"; 
		(*a)++;
		temp = temp->next; 
	} 
}

int main() 
{ 
	Linkedlist list; 

	char control;
	while(true){
		cout << "\nPress 'x' to exit, anything to go on: ";
		cin >> control;
		if(control == 'x' || control == 'X')
			break;

		list.insertNode();
		if (list.calculateDEP() >= threshold_score)
			cout << "Eligible to apply for transfer applications.\n";

		else
			cout << "Rejected.\n";
	}

	list.printList();

	return 0; 
}
/*
if (list.calculateDEP() >= threshold_score)
	list.isEligible = 1;
*/