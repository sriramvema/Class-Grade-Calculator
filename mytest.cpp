#include "section.h"
// Author: Sriram Vema
// Date: 2/15/2022
// Section:5
// File: mytest.cpp
// Description: Tester file that tests different cases for section class
class Tester{
    public:
    // the following is implemented as an example of measurement
    bool measureInsertionTime(int numTrials, int inputSize);
    // the following is implemented as a test case example

    bool measureCopyingTime(int numTrials, int inputSize);

    bool testStudentAveErrorCase();

    bool testStudentAveEdgeCase();
    
    bool testQuizAveErrorCase();

    bool testQuizAveEdgeCase();

    bool testConstructorNormalCase();

    bool testConstructorErrorCase();

    bool testCopyConstructor();

    bool testCopyConstructorEdge();

    bool testAssignmentOperator();

    bool testAssignmentOperatorEdge();


    /******************************************
    * Test function declarations go here! *
    ******************************************/
};

int main() {
    Tester tester;
        // measuring the running time of insertion
    cout << "\nMeasuring the performance of insertion function:\n\n";
        // measuring the insertion of 100x100 grades, and 200x200 grades
        // the 100x100 grades is determined by 100 items times 100 students
    bool result = tester.measureInsertionTime(2,100);
    cout << "\nMeasuring the performance of copy constructor:\n\n";
    result = tester.measureCopyingTime(2, 100);

    if (tester.testStudentAveErrorCase() == true) {
        cout << "\tError case (student index does not exist) of studentAverage() passed!\n";
    } else {
        cout << "\tError case (student index does not exist) of studentAverage() failed!\n";
    }

    if (tester.testStudentAveEdgeCase() == true) {
        cout << "\tEdge case (empty section class) of studentAverage() passed!\n";
    } else {
        cout << "\tEdge case (empty section class) of studentAverage() failed!\n";
    }

    if (tester.testQuizAveErrorCase() == true) {
        cout << "\tError case (quiz index does not exist) of quizAverage() passed!\n";
    } else {
        cout << "\tError case (quiz index does not exist) of quizAverage() failed!\n";
    }

    if (tester.testQuizAveEdgeCase() == true) {
        cout << "\tEdge case (empty section class) of quizAverage() passed!\n";
    } else {
        cout << "\tEdge case (empty section class) of quizAverage() failed!\n";
    }

    if (tester.testConstructorNormalCase()== true) {
        cout << "\tNormal case of constructor passed!\n";
    } else {
        cout << "\tNormal case of constructor failed!\n";
    }

    if (tester.testConstructorErrorCase()== true) {
        cout << "\tError case (creating section object with negative values) of constructor passed!\n";
    } else {
        cout << "\tError case (creating section object with negative values) of constructor failed!\n";
    }

    if (tester.testCopyConstructor()== true) {
        cout << "\tNormal case of copy constructor passed!\n";
    } else {
        cout << "\tNormal case of copy constructor failed!\n";
    }

    if (tester.testCopyConstructorEdge() == true) {
        cout << "\tEdge case (empty section class copied) of copy constructor passed!\n";
    } else {
        cout << "\tEdge case (empty section class copied) of copy constructor failed!\n";
    }

    if (tester.testAssignmentOperator()== true) {
        cout << "\tError case of assignment operator passed!\n";
    } else {
        cout << "\tError case of assignment operator failed!\n";
    }

    if (tester.testAssignmentOperatorEdge()== true) {
        cout << "\tEdge case (empty section class copied) of assignment operator passed!\n";
    } else {
        cout << "\tEdge case (empty section class copied) of assignment operator failed!\n";
    }
    

}
// Precondition: numTrials and inputSize
// Postcondition: boolean to make sure the time is valid
// Description: Measures the time it takes to insert into a section object
bool Tester::measureInsertionTime(int numTrials, int inputSize)
{
    //Measuring the efficiency of insertion algorithm with system clock ticks
    //Clock ticks are units of time of a constant but system-specific length, as those returned by function clock().
    //Dividing a count of clock ticks by CLOCKS_PER_SEC yields the number of seconds.
    const int a = 2;//scaling factor for input size
    double T = 0.0;//to store running times
    clock_t start, stop;//stores the clock ticks while running the program
    for (int k=0;k<numTrials;k++)
    {
        Section testObject(inputSize,inputSize);
        start = clock();
        testObject.insert();//the algorithm to be analyzed for efficiency
        stop = clock();
        T = stop - start;//number of clock ticks the algorithm took
        cout << "\tInserting " << inputSize * inputSize << " members took " << T << " clock ticks ("<< T/CLOCKS_PER_SEC << " seconds)!" << endl;
        inputSize = inputSize * a;//increase the input size by the scaling factor
    }
    if (T > 0) {
        return true;
    } else {
        return false;
    }
}
// Precondition: numTrials and inputSize
// Postcondition: boolean to make sure the time is valid
// Description: Measures the time it takes to copy into a section object
bool Tester::measureCopyingTime(int numTrials, int inputSize) {
    const int a = 2;//scaling factor for input size
    double T = 0.0;//to store running times
    clock_t start, stop;//stores the clock ticks while running the program
    for (int k=0;k<numTrials;k++)
    {
        Section testObject(inputSize,inputSize);
        start = clock();
        Section copiedObject(testObject);//the algorithm to be analyzed for efficiency
        stop = clock();
        T = stop - start;//number of clock ticks the algorithm took
        cout << "\tCopying " << inputSize * inputSize << " members took " << T << " clock ticks ("<< T/CLOCKS_PER_SEC << " seconds)!" << endl;
        inputSize = inputSize * a;//increase the input size by the scaling factor
    }
    if (T > 0) {
        return true;
    } else {
        return false;
    }
}
// Precondition: None
// Postcondition: Returns True or False
// Description: Checks if the student average returns 0 if the parameter is invalid (out of index)
bool Tester::testStudentAveErrorCase(){
    bool result = true;
    // create an object with 1 student and 10 grading items
    Section testObject(10,1);
    testObject.insert();
    double average = testObject.studentAverage(1);// out of range index
    if (average == 0.0)
        result = true;
    else
        result = false;
    return result;
}
// Precondition: None
// Postcondition: Returns True or False
// Description: Checks if the student average returns 0 if the parameter is invalid (empty object)
bool Tester::testStudentAveEdgeCase(){
    bool result = true;
    // create an object with 1 student and 10 grading items
    Section testObject;
    testObject.insert();
    double average = testObject.studentAverage(0);// out of range index
    if (average == 0.0)
        result = true;
    else
        result = false;
    return result;
}

// Precondition: None
// Postcondition: Returns True or False
// Description: Checks if the quiz average returns 0 if the parameter is invalid (out of index)
bool Tester::testQuizAveErrorCase() {
    bool result = true;
    // create an object with 1 student and 10 grading items
    Section testObject(10,1);
    testObject.insert();
    double average = testObject.quizAverage(10);// out of range index
    if (average == 0.0)
        result = true;
    else
        result = false;
    return result;
}

// Precondition: None
// Postcondition: Returns true or false
// Description: Checks if the quiz average returns 0 if the parameter is invalid (empty object)
bool Tester::testQuizAveEdgeCase() {
    bool result = true;
    // create an object with 1 student and 10 grading items
    Section testObject;
    testObject.insert();
    double average = testObject.quizAverage(0);// out of range index
    if (average == 0.0)
        result = true;
    else
        result = false;
    return result;
}

// Precondition: None
// Postcondition: Returns true or false
// Description: Checks if the constructor creates an empty object if the parameters are invalid
bool Tester::testConstructorErrorCase() {
    Section testObject(-1, -5); //Create an object with negative parameters and make sure it returns an empty class
    if (testObject.m_numGradingItems == 0 && testObject.m_numStudents == 0) {
        return true;
    } else {
        return false;
    }
}
// Precondition: None
// Postcondition: Returns true or false
// Description: Checks if the copied object is the same as the original object but with different memory addresses
bool Tester::testConstructorNormalCase() {
    Section testObject(3, 5); //Creates a normal class and make sure the parameters were passed properly
    if (testObject.m_numGradingItems == 3 && testObject.m_numStudents == 5) {
        return true;
    } else {
        return false;
    }
}
// Precondition: None
// Postcondition: Returns true or false
// Description: Checks if the copied object is the same as the original object but with different memory addresses
bool Tester::testCopyConstructor() {
    bool result = true; 
    Section testObject(3, 5); 
    testObject.insert();
    Section copiedObject(testObject);
    if (testObject.m_grades != copiedObject.m_grades) {
        if (copiedObject.m_numGradingItems == testObject.m_numGradingItems && copiedObject.m_numStudents == testObject.m_numStudents) {
            if (copiedObject.classAverage() == testObject.classAverage()) {
                result = true;
            }
        } else {
            return false;
        }        
    } else {
        return false;
    }
    return result;
}

// Precondition: None
// Postcondition: Returns true or false
// Description: Checks if the copied object is the same as the original object but with different memory addresses
bool Tester::testCopyConstructorEdge() {
    bool result = true;
    Section testObject; 
    testObject.insert();
    Section copiedObject(testObject);
    if (testObject.m_grades != copiedObject.m_grades) {
        if (copiedObject.m_numGradingItems == testObject.m_numGradingItems && copiedObject.m_numStudents == testObject.m_numStudents && copiedObject.classAverage() == testObject.classAverage()) {
            result = true;
        } else {
            return false;
        }        
    } else {
        return false;
    }
    return result; 
}
// Precondition: None
// Postcondition: Returns true or false
// Description: Checks if the copied object is the same as the original object but with different memory addresses
bool Tester::testAssignmentOperator() {
    bool result = true;
    Section testObject(3, 3); 
    Section copiedObject(4, 4);
    testObject = copiedObject;
    if (testObject.m_grades != copiedObject.m_grades) {
        if (copiedObject.m_numGradingItems == testObject.m_numGradingItems && copiedObject.m_numStudents == testObject.m_numStudents && copiedObject.classAverage() == testObject.classAverage()) {
            result = true;
        } else {
            return false;
        }        
    } else {
        return false;
    }
    return result; 
}
// Precondition: None
// Postcondition: Returns true or false
// Description: Checks if the copied object is the same as the original object but with different memory addresses
bool Tester::testAssignmentOperatorEdge() {
    bool result = true;
    Section testObject;
    testObject.insert(); 
    Section copiedObject;
    testObject = copiedObject;
    if (testObject.m_grades != copiedObject.m_grades) {
        if (copiedObject.m_numGradingItems == testObject.m_numGradingItems && copiedObject.m_numStudents == testObject.m_numStudents && copiedObject.classAverage() == testObject.classAverage()) {
            result = true;
        } else {
            return false;
        }        
    } else {
        return false;
    }
    return result; 
}