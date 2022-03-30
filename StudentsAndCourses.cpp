#include "StudentsAndCourses.h"

#include <iostream>
#include <cstring>


// THIS IS THE BEIGGINING OF THE STUDENT CLASS


Student::Student()
{
    Name = new char[10];
    classification = ' ';
    Major = new char[10];
    StudentID = 0;

}

Student::Student(char* c_name, char c_classification, char* c_major, int c_studentID)
{
    SetName(c_name);
    SetClassification(c_classification);
    SetMajor(c_major);
    SetStudentID(c_studentID);
}

void Student::SetName(const char *User_Name)
{
    int size = 0;

    //finds the size of the character array
    size = strlen(User_Name);

    // allocating space for the charecter array
    Name = new char[size+1];

    // copying the users input into the new allocated space
    strcpy(Name,User_Name);
}

void Student::SetClassification(char User_Classification)
{
    classification = User_Classification;
}

void Student::SetMajor(const char* User_Major)
{
    int size = 0;

    //finds the size of the character array
    size = strlen(User_Major);

    // allocating space for the charecter array and its null terminator
    Major = new char[size+1];

    // copying the users input into the new allocated space
    strcpy(Major,User_Major);
}

void Student::SetStudentID(int User_StudentID)
{
    StudentID = User_StudentID;
}

char* Student::GetName() const
{
    return Name;
}

char Student::GetClassification() const
{
    return classification;
}

char* Student::GetMajor() const
{
    return Major;
}

int Student::GetStudentID() const
{
    return StudentID;
}

ostream& operator<<(ostream& s, const Student& t)
{
    s << t.GetName() << " - " << t.GetMajor() << " - " << - t.GetClassification() << " - " << t.GetStudentID();
    return s;
}

Student& Student::operator=(const Student& t)
{
    classification = t.classification;
    StudentID = t.StudentID;

    delete [] Name;
    delete [] Major;

    Name = new char[strlen(t.Name) + 1];
    Major = new char[strlen(t.Major) + 1];

    strcpy(Name, t.Name);
    strcpy(Major, t.Major);

    return *this;
}

// THIS IS THE END OF THE STUDENT CLASS





// THIS IS THE BEGGINING OF THE COURSE CLASS

ostream& operator<<(ostream& s, const Course& t)
{
    s << t.GetName() << " - " << t.GetCourseCode() << " - " << t.GetLocation();
    return s;
}

Course& Course::operator=(const Course& t)
{
    for (int i = 0; i < 7; i++)
    {
        CourseCode[i] = t.CourseCode[i];
    }

    for (int i = 0; i < 10; i++)
    {
        CourseLocation[i] = t.CourseLocation[i];
    }

    StudentCount = t.StudentCount;
    CurrentStudentCount = t.CurrentStudentCount;

    delete [] CourseName;
    delete [] Roster;

    CourseName = new char[strlen(t.CourseName) + 1];
    Roster = new Student[StudentCount];

    strcpy(CourseName,t.CourseName);

    for (int i = 0; i < StudentCount; i++)
    {
        Roster[i] = t.Roster[i];
    }

    return *this;
}

Course::Course()
{
    StudentCount = 2;
    CurrentStudentCount = 0;
    Roster = new Student[StudentCount];

    strcpy(CourseCode," ");
    strcpy(CourseLocation," ");
    CourseName = new char[10];
}

Course::~Course()
{
    delete [] CourseName;
    delete [] Roster;
}

void Course::SetCourseName(const char* User_CourseName)
{
    int size = 0;

    //finds the size of the character array
    size = strlen(User_CourseName);

    // allocating space for the charecter array
    CourseName = new char[size+1];

    // copying the users input into the new allocated space
    strcpy(CourseName,User_CourseName);
}

void Course::SetCourseCode(const char User_CourseCode[7])
{
    strcpy(CourseCode,User_CourseCode);
}

void Course::SetCourseLocation(const char User_CourseLocation[10])
{
    strcpy(CourseLocation,User_CourseLocation);
}

char* Course::GetName() const
{
    return CourseName;
}

char* Course::GetCourseCode() const
{
    char* code = new char[7];
    strcpy(code, CourseCode);
    return code;
}

char* Course::GetLocation() const
{
    char* location = new char[10];
    strcpy(location, CourseLocation);
    return location;
}

void Course::AddStudent(const Student& User_Student)
{
    // checking to see if the roster has enough space to add a student
    if (CurrentStudentCount == StudentCount)
    {
        // Making a new roster with 1 more spcae
        int NewStudentCount = StudentCount + 10;
        Student* NewRoster = new Student[NewStudentCount];

        // copying the original Roster to the NewRoster via deep copy
        for (int i = 0; i < CurrentStudentCount; i++)
        {
            NewRoster[i] = Roster[i];
        }

        //deleting the old Roster
        delete [] Roster;

        // setting the class variable to the NewRoster pointer
        Roster = NewRoster;

        // setting that new size to the list size
        StudentCount = NewStudentCount;
    }

    // Adding the user inputed Student into the Roster
    Roster[CurrentStudentCount] = User_Student;
    // increasing the counter
    CurrentStudentCount++;
}

int Course::GetStudentCount() const
{
    return StudentCount;
}

Student& Course::GetStudent(int index)
{
    return Roster[index];
}

int Course::FindStudentByID(const int User_StudentID)
{
    // iterating threw the roster to find a matching id
    for (int i = 0; i < CurrentStudentCount; i++)
    {
        // compares the ID of the iteration VS the id entered
        if (Roster[i].GetStudentID() == User_StudentID)
        {
            // returns the Student at that position its found
            return i;
        }
        else
        {
            return 999;
        }
    }
}

int Course::FindStudentByName(const char* StudentName)
{
    // iterates threw the roster to find a matching name
    for (int i = 0; i < CurrentStudentCount; i++)
    {
        // compares the name of the iteration to the name to be found
        if (strcmp(Roster[i].GetName(),StudentName) == 0)
        {
            //returns the Student at that position its found
            return i;
        }
        else
        {
            return 999;
        }
    }
}




// THIS IS THE END OF THE COURSE CLASS






// THIS IS THE START OF THE MANAGMENT CLASS

Managment::Managment()
{
    CurrentListSize = 0;
    ListSize = 2;
    CourseList = new Course[ListSize];
}

Course* Managment::GetCourses() const
{
    return CourseList;
}

int Managment::GetCourseCount() const
{
    return CurrentListSize;
}

void Managment::AddCourse(const Course& User_Course)
{
    // checking to see if the array has enough space
    if (CurrentListSize == ListSize)
    {
        // allocating a new array with enough space
        int Newsize = ListSize + 1;
        Course* NewList = new Course[Newsize];

        // copying via deep copy to the new list
        for (int i = 0; i < CurrentListSize; i++)
        {
            NewList[i] = CourseList[i];
        }

        //deleting the old list
        delete [] CourseList;

        // seting the newlist to original variable
        CourseList = NewList;

        // seting that new size to the list size
        ListSize = Newsize;
    }

    // Adding the users Course into the new updated sized list
    CourseList[CurrentListSize] = User_Course;
    // increasing the counter
    CurrentListSize++;
}

Course& Managment::GetCourse(int index)
{
    return CourseList[index];
}

int Managment::FindWithName(const char* Coursename)
{
    // iterates threw the list to find a matching name
    for (int i = 0; i < CurrentListSize; i++)
    {
        // compares the name of the iteration to the name to be found
        if (strcmp(CourseList[i].GetName(), Coursename) == 0)
        {
            //returns the course at that position if found
            return i;
        }
        else
        {
            return 999;
        }
    }

}

int Managment::FindWithCourseCode(const char CourseCode[7])
{
    // iterates threw the list to find a matching name
    for (int i = 0; i < CurrentListSize; i++)
    {
        // compares the name of the iteration to the name to be found
        if (strcmp(CourseList[i].GetCourseCode(), CourseCode) == 0)
        {
            //returns the course at that position if found
            return i;
        }
        else
        {
            return 999;
        }
    }
}

int Managment::FindwithLocation(const char Location[10])
{
    // iterates threw the list to find a matching name
    for (int i = 0; i < CurrentListSize; i++)
    {
        // compares the name of the iteration to the name to be found
        if (strcmp(CourseList[i].GetLocation(), Location) == 0)
        {
            //returns the course at that position if found
            return i;
        }
        else
        {
            return 999;
        }
    }
}

void Managment::RemoveCourse(int index)
{
    for(int i = index; i < CurrentListSize - 1; i++)
    {
        CourseList[i] = CourseList[i + 1];
    }

    CurrentListSize--;
}