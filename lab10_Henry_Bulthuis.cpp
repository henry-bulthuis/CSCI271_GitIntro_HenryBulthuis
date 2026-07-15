//
//  main.cpp
//  lab10_Henry_Bulthuis.cpp
//
//  Created by Henry Bulthuis on 7/14/26.
//

#include <iostream>
# include <string>
using namespace std;


class CPU {
private:
    string id;
    int ff, mf, cof, cot;
    double cmips;
    
    void computerMIPS() {
        cmips = cof * 2.0;
    }
    
public:
    // Write Constructor(s)
    CPU(string cpuID, int fundFreq, int maxFreq, int curFreq, int temp) {
        id = cpuID;
        ff = fundFreq;
        mf = maxFreq;
        cof = curFreq;
        cot = temp;
        computerMIPS();
    }
    
    // Display() function
    void display() {
        cout << "ID: " << id
        << "  FF: " << ff
        << "  MF: " << mf
        << "  COF: " << cof
        << "  Temp: " << cot
        << "  MIPS: " << cmips << endl;
    }
    
    // write setTemperature() function
    void setTemperature(int temp) {
        cot = temp;
        
        if (cot < 176) {
            cof += 200;
            if (cof > mf)
                cof = mf;
        }
        else if (cot > 176) {
            cof -= 200;
            if (cof < ff)
                cof = ff;
        }
        computerMIPS();
    }
    
    
    // write getMIPS() function
    double getMIPS() {
        return cmips;
    }
};
    
    // Main Program
    
int main() {
    const int N = 4;
    
    CPU cluster[N] = {
        CPU("001", 2000, 4800, 2800, 132),
        CPU("002", 2200, 5000, 3200, 131),
        CPU("003", 2100, 4900, 3400, 142),
        CPU("004", 2500, 4500, 3700, 144)
    };
    
    int choice;
    
    do {
        cout << "\n===== CPU Cluster Menu =====\n";
        cout << "1. Display all CPUs\n";
        cout << "2. Display one CPU\n";
        cout << "3. Set temperature of one CPU\n";
        cout << "4. Display total MIPS of cluster\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 1) {
            for (int i = 0; i < N; i++) {
                cluster[i].display();
            }
        }
        else if (choice == 2) {
            int index;
            cout << "Enter CPU index (0-3): ";
            cin >> index;
            
            if (index >= 0 && index < N)
                cluster[index].display();
            else cout << "Invalid index.\n";
        }
        else if (choice == 3) {
            int index, temp;
            
            cout << "Enter CPU index (0-3): ";
            cin >> index;
            
            if (index >= 0 && index < N) {
                cout << "Enter new temperature: ";
                cin >> temp;
                
                cluster[index].setTemperature(temp);
                
                cout << "Updated CPU:\n";
                cluster[index].display();
            }
            else {
                cout << "Invalid index.\n";
            }
        }
        else if (choice == 4) {
            double total = 0;
            
            for (int i = 0; i < N; i++) {
                total += cluster[i].getMIPS();
            }
            cout << "Total CLuster MIPS: " << total << endl;
        }
        
    } while (choice != 5);
    
    cout << "Program exited." << endl;
    
    return 0;
}
