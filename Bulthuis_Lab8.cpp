//
//  main.cpp
//  Henry_Bulthuis_Lab8.cpp
//
//  Created by Henry Bulthuis on 7/1/26.
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX = 5;
const int COURSE_COUNT = 3;

// Functions
void calculateStudent(int i, double Score[][3], double &total, double &average);
void displayALL(int n, string NameArr[], double Score[][3]);
int findTopStudent(int n, double Score[][3]);

int main()
{
    // insert code here...
    // Test Data Setup
    int n = 3;
    
    // Data Storage
    string NameArr[MAX] = {"Alice", "Bob", "Carl"};
    
    double Score[MAX][3] = {
        {90, 85, 95},
        {70, 80, 75},
        {88, 92, 84}
    };
    
    cout << fixed << setprecision(2);
    
    // Title
    cout << "=== Student Grade Report ===" << endl;
    
    // Display ALL
    displayALL(n, NameArr, Score);
    
    // find top student
    int topIndex = findTopStudent(n, Score);
    
    // Calculate top student
    double total, average;
    calculateStudent(topIndex, Score, total, average);
    
    // Top Student
    cout << endl;
    cout << "Top student: " << NameArr[topIndex];
    cout << " | Total = " << total;
    cout << " | Average = " << average << endl;
    
    return 0;
}

// Calculate total and average for student
void calculateStudent(int i, double Score[][3], double &total, double &average)
{
    total = 0;
    
    for (int j = 0; j < COURSE_COUNT; j++)
    {
        total += Score[i][j];
    }
    
    average = total / COURSE_COUNT;
}
    
    // Display student info
    void displayALL(int n, string NameArr[], double Score[][3])
    {
        for (int i = 0; i < n; i++)
        {
            double total, average;
            
            calculateStudent(i, Score, total, average);
            
            cout << NameArr[i]
            << " | Math = " << Score[i][0]
            << " | C Programming = " << Score[i][1]
            << " | Operating Systems = " << Score[i][2]
            << " | Total = " << total
            << " | Average = " << average
            << endl;
        }
    }
    
    // Find index of student with highest score total
    int findTopStudent(int n, double Score[][3])
    {
        int topIndex = 0;
        double highestTotal, average;
        
        calculateStudent(0, Score, highestTotal, average);
        
        for (int i = 1; i < n; i++)
        {
            double total;
            
            calculateStudent(i, Score, total, average);
            
            if (total > highestTotal)
            {
                highestTotal = total;
                topIndex = i;
            }
        }
        
        return topIndex;
    
}
