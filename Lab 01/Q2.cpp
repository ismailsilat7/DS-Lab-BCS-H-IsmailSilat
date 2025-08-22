#include <iostream>
#include <cstring>
using namespace std;

class Exam {
    private:
        char* studentName;
        char* examDate;
        int score;
    public:

        Exam(const char* name, const char* date, int s) : score(s) {
            studentName = new char[strlen(name) + 1];
            strcpy(studentName, name);

            examDate = new char[strlen(date) + 1];
            strcpy(examDate, date);
        }


        ~Exam() {
            delete[] studentName;
            delete[] examDate;
            cout << "Destructor called, memory freed!" << endl;
        }

        /*
        Exam(const Exam& other) {
            score = other.score;

            studentName = new char[strlen(other.studentName) + 1];
            strcpy(studentName, other.studentName);

            examDate = new char[strlen(other.examDate) + 1];
            strcpy(examDate, other.examDate);
        }
        Exam& operator=(const Exam& other) {
            if (this != &other) {
                delete[] studentName;
                delete[] examDate;

                score = other.score;

                studentName = new char[strlen(other.studentName) + 1];
                strcpy(studentName, other.studentName);

                examDate = new char[strlen(other.examDate) + 1];
                strcpy(examDate, other.examDate);
            }
            return *this;
        }
        */
        void setStudentName(const char* name) {
            delete[] studentName;
            studentName = new char[strlen(name) + 1];
            strcpy(studentName, name);
        }

        void setExamDate(const char* date) {
            delete[] examDate;
            examDate = new char[strlen(date) + 1];
            strcpy(examDate, date);
        }

        void setScore(int s) {
            score = s;
        }

        void display() const {
            cout << "Student: " << studentName << endl << "Date: " << examDate << endl << "Score: " << score << endl;
        }
};

int main() {
    Exam exam1("Ismail", "2025-08-22", 95);
    cout << "Original Exam" << endl;
    exam1.display();

    Exam exam2 = exam1;
    cout << "Copied Exam (Shallow Copy)" << endl;
    exam2.display();

    // since both objects share the same memory, dangling pointer issue will arise
}