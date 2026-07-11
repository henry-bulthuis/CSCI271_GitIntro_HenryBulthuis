//
//  main.cpp
//  lab9_Henry.cpp
//
//  Created by Henry Bulthuis on 7/10/26.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Student Data
struct Student {
    string id;
    string name;
    string major;
    string hobby;
    double gpa;
    string email;
    string city;
};

// Step 2: Write to file

void savetoFile(Student s[], int n, const string& filename) {
    ofstream out(filename);
    
    if (!out) {
        cout << "File open error!" << endl;
        return;
    }
    
    for (int i = 0; i < n; i++) {
        out << s[i].id << " "
        << s[i].name << " "
        << s[i].major << " "
        << s[i].hobby << " "
        << s[i].gpa << " "
        << s[i].email << " "
        << s[i].city << endl;
    }
    
    out.close();
    
    cout << "[1] Data saved to " << filename << endl;
    }


// Step 3: Read from file
int loadFromFile(Student s[], int maxSize, const string& filename) {
    ifstream in(filename);
    
    if (!in) {
        cout << "File open error!" << endl;
        return 0;
    }
    
    int count = 0;
    
    while (count < maxSize &&
           in >> s[count].id
           >> s[count].name
           >> s[count].major
           >> s[count].hobby
           >> s[count].gpa
           >> s[count].email
           >> s[count].city) {
        
        count++;
    }
    
    in.close();
    
    cout << "[2] Loaded " << count<< " students from " << filename << endl;
    
    return count;
}

// Step 4: Display All Students
void displayALL(Student s[], int n) {
    
    cout << endl;
    cout << "[3] Displaying all students:" << endl;
    cout << "-----------------------------------------" << endl;
    
    for (int i = 0; i < n; i++) {
        cout << s[i].id << " "
        << s[i].name
        << " (" << s[i].major << ") - "
        << s[i].city
        << " - GPA: " << s[i].gpa
        << endl;
    }
}

// Step 5: Count Students with GPA >= 3.0
int countHighGPA(Student s[], int n) {
    
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (s[i].gpa >= 3.0) {
            count++;
        }
    }
    
    return count;
}

// Step 6: Query Students by City
void queryByCity(Student s[], int n, const string& city) {
    
    cout << endl;
    cout << "[5] Students from " << city << ":" << endl;
    
    bool found = false;
    
    for (int i = 0; i < n; i++) {
        
        if (s[i].city == city) {
            
            cout << s[i].name
            << " (" << s[i].major
            << ", GPA " << s[i].gpa
            << ")" << endl;
            
            found = true;
        }
    }
    
    if (!found) {
        cout << "No students found in that city." << endl;
    }
}

// Main

int main() {
    
    Student students[100];
    
    int n = 3;
    
    // Step 1:
    
    students[0] = {
        "S01",
        "Tom",
        "MATH",
        "Football",
        2.8,
        "tom@google.com",
        "Modesto"
    };
    
    students[1] = {
        "S02",
        "Alice",
        "CS",
        "Reading",
        3.5,
        "alice@google.com",
        "Modesto"
    };
    
    students[2] = {
        "S03",
        "Scott",
        "CS",
        "Basketball",
        3.2,
        "scott@google.com",
        "SanJose"
    };
    
    savetoFile(students, n, "students.txt");
    
    Student loaded[100];
    
    int count = loadFromFile(
    loaded,
    100,
    "students.txt"
                             );
    
    displayALL(loaded, count);
    
    cout << endl;
    cout << "[4] Students with GPA >= 3.0: "
    << countHighGPA(loaded, count)
    << endl;
    
    queryByCity(loaded, count, "Modesto");
    
    cout << endl;
    cout << "Program finished." << endl;
                    

    return 0;
}
