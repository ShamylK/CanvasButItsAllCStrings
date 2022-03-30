#ifndef CLASSESANDSTUDENTS_CLION_STUDENTSANDCOURSES_H
#define CLASSESANDSTUDENTS_CLION_STUDENTSANDCOURSES_H

#include <iostream>
#include <cstring>

using namespace std;

class Student;
class Course;

class Student
{
public:
    friend ostream& operator<<(ostream& s, const Student& t);
    //constructor
    Student();
    Student(char* c_name, char c_classification, char* c_major, int c_studentID);

    // getters and setters
    char* GetName() const;
    char GetClassification() const;
    char* GetMajor() const;
    int GetStudentID() const;

    void SetName(const char* User_Name);
    void SetClassification(char User_Classification);
    void SetMajor(const char* User_Major);
    void SetStudentID(int User_StudentID);
    Student& operator=(const Student& t);

private:
    //Private data members;
    char* Name;
    char classification;
    char* Major;
    int StudentID;
};

class Course
{
public:
    friend ostream& operator<<(ostream& s, const Course& t);

    //Default Constructor
    Course();
    ~Course();

    //getters and setters
    char* GetName() const;
    char* GetCourseCode() const;
    char* GetLocation() const;
    int GetStudentCount() const;


    void SetCourseName(const char* User_CourseName);
    void SetCourseCode(const char User_CourseCode[7]);
    void SetCourseLocation(const char User_CourseLocation[10]);
    void AddStudent(const Student& User_Student);
    int FindStudentByID(const int User_StudentID);
    int FindStudentByName(const char* StudentName);
    Course& operator=(const Course& t);
    Student& GetStudent(int index);


private:

    // Private data members
    char* CourseName;
    char CourseCode[7];
    char CourseLocation[10];

    Student* Roster;
    int StudentCount;
    int CurrentStudentCount;
};

class Managment
{
public:
    Managment();

    Course* GetCourses() const;
    Course& GetCourse(int index);
    void AddCourse(const Course& User_Course);
    int GetCourseCount() const;
    void RemoveCourse(int index);

    int FindWithName(const char* Coursename);
    int FindWithCourseCode(const char CourseCode[7]);
    int FindwithLocation(const char Location[10]);

private:

    Course* CourseList;
    int ListSize;
    int CurrentListSize;

};

#endif //CLASSESANDSTUDENTS_CLION_STUDENTSANDCOURSES_H
