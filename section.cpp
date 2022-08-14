// UMBC - CMSC 341 - Spring 2022 - Proj0
// Author: Sriram Vema
// Date: 2/15/2022
// Section:5
// File: section.cpp
// Description: Holds the section class functions for students and grades
#include "section.h"

//Precondition: None
//Postcondition: Private variables are initialized
//Description: Sets the variables with empty values
Section::Section(){
    m_numGradingItems= 0;
    m_numStudents = 0;
    m_grades = nullptr;
}
// Precondition: Items and students values
// Postcondition: Creates a section class with the passed values
// Description: Checks if the parameters are valid before it creates the object. Creates an array of pointers for m_grades. Makes each pointer point to an array with the size of items
Section::Section(int items, int students){
    if (items >= 0 && students >= 0) { // Checks if the parameters are valid before it creates the object
        m_numGradingItems= items;
        m_numStudents = students;
        m_grades = new double *[m_numStudents]; // Creates an array of pointers for m_grades
        for(int i = 0; i < m_numStudents; i ++) {
            m_grades[i] = new double [m_numGradingItems]; // Makes each pointer point to an array with the size of items
            for(int n = 0; n < m_numGradingItems; n ++) {
                m_grades[i][n] = 0;
            } 
        }        
    } else {
        m_numGradingItems= 0;  // If the parameters are not valid, it creates an empty class
        m_numStudents = 0;
        m_grades = nullptr; 
    }

}
// Precondition: None
// Postcondition: Deallocates all memory
// Description: Calls the clear function to prevent memory leaks
Section::~Section(){
    clear();
}
// Precondition: None
// Postcondition: Empties the section object
// Description: Deletes each pointer in the array and then deletes m_grades pointer
void Section::clear(){
    for(int i = 0; i < m_numStudents; i ++) {
        delete [] m_grades[i];  
    }
    delete m_grades;         
    m_numGradingItems= 0; 
}
// Precondition: None
// Postcondition: Fills the arrays with graded items
// Description: Iterates through each array and adds a random real number for each index
void Section::insert(){
    Random rand(0, 100, UNIFORMREAL);
    for(int i = 0; i < m_numStudents; i ++) {
        for(int n = 0; n < m_numGradingItems; n ++) { // Iterates through each array an fills it with real numbers between 0 and 100
            m_grades[i][n] = rand.getRealRandNum();
        }
    } 
}
// Precondition: Index for student
// Postcondition: Returns student average
// Description: Calculates the average for a single student with all of his grading items
double Section::studentAverage(int student){
    double sum = 0.0;
    if (student < m_numStudents) { // Checks if the parameter is valid
        for(int n = 0; n < m_numGradingItems; n ++) {
            sum = sum + m_grades[student][n];  // Calculates the 
        }
        return sum/m_numGradingItems;
    } else {
        return 0.0;
    }
}
// Precondition: Index for quiz
// Postcondition: Returns quiz average
// Description: Iterates through each student and returns the average of the quiz grades for a single quiz
double Section::quizAverage(int quiz){
    double sum = 0;
    if (quiz < m_numGradingItems) {
        for(int i = 0; i < m_numStudents; i ++) {
            sum = sum + m_grades[i][quiz];
        }
        return sum/m_numStudents;        
    } else {
        return 0.0;
    }

}
// Precondition: None
// Postcondition: Returns the class average
// Description: Takes the average between each student and calculates the average of that number
double Section::classAverage(){
    int sum;
    if (m_numStudents > 0) {
        for(int i = 0; i < m_numStudents; i ++) {
            sum = sum + studentAverage(i);
        }

        return sum/m_numStudents;
    } else {
        return 0.0;
    }  

}
// Precondition: section object is passed into function
// Postcondition: Copies the section object into the current object
// Description: Checks if the objects have the same memory address and if not, it does a deep copy of the passed object
Section::Section(const Section& rhs){
    m_numGradingItems = rhs.m_numGradingItems;
    m_numStudents = rhs.m_numStudents;
    m_grades = new double *[rhs.m_numStudents];
    for(int i = 0; i < m_numStudents; i ++) {
        m_grades[i] = new double [rhs.m_numGradingItems];
        for(int n = 0; n < m_numGradingItems; n ++) {
            m_grades[i][n]= rhs.m_grades[i][n]; 
        }
    } 
}
// Precondition: section object is passed into function
// Postcondition: Copies the section object into the current object
// Description: Checks if the objects have the same memory address and if not, it does a deep copy of the passed object
const Section& Section::operator=(const Section& rhs){
    if (this != &rhs) {
        clear();
        m_numGradingItems = rhs.m_numGradingItems;
        m_numStudents = rhs.m_numStudents;
        m_grades = new double *[m_numStudents];
        for(int i = 0; i < m_numStudents; i ++) {
            m_grades[i] = new double [m_numGradingItems];
        }
        for(int i = 0; i < m_numStudents; i ++) {
            for(int n = 0; n < m_numGradingItems; n ++) {
                m_grades[i][n]= rhs.m_grades[i][n]; 
            }
        }
    }
    return *this;
}

void Section::dump(){
    if (m_numGradingItems > 0 && m_numStudents > 0 && m_grades != nullptr){
        cout << setw(8) << "        ";
        for (int a=1;a<=m_numGradingItems;a++)
            cout << setw(8) << "Quiz" << a;
        cout << endl;
        for (int i=1;i <= m_numStudents;i++){
            cout << setw(8) << "Student" << i << " ";
            for (int j=1;j<=m_numGradingItems;j++){
                cout << setw(8) << m_grades[i-1][j-1] << " ";
            }
            cout << endl;
        }
    }
}