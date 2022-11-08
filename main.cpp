#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <math.h>
#include <sstream>
using namespace std;

int main() {
    string dataTitle, c1Head, c2Head, fullLine;
    int passes, commas;
    vector<string> names;
    vector<int> novels;

    cout << "Enter a title for the data:" << endl;
    getline(cin, dataTitle);
    cout << "You entered: " << dataTitle << endl;

    cout << "Enter the column 1 header:" << endl;
    getline(cin, c1Head);
    cout << "You entered: " << c1Head << endl;

    cout << "Enter the column 2 header:" << endl;
    getline(cin, c2Head);
    cout << "You entered: " << c2Head << endl;

    passes = 0;
    do {
        try {
            string tempData, tempDigit;
            commas = 0;
            cout << "Enter a data point (-1 to stop input):" << endl;
            getline(cin, fullLine);
            if (fullLine == "-1")
                break;
            for (int x = 0; (unsigned)x < fullLine.length(); x++) {
                if (fullLine[x] == ',') {
                    tempData = fullLine.substr(0, x);
                    tempDigit = fullLine.substr(x + 2, fullLine.length());
                    commas++;
                }
            }
            if (commas == 0)
                throw runtime_error("Error: No comma in string.");

            else if (commas > 1)
                throw runtime_error("Error: Too many commas in input.");

            else if (!((tempDigit.substr(0, 1) == "1") || (tempDigit.substr(0, 1) == "2") || (tempDigit.substr(0, 1) == "3") || (tempDigit.substr(0, 1) == "4") || (tempDigit.substr(0, 1) == "5") || (tempDigit.substr(0, 1) == "6") || (tempDigit.substr(0, 1) == "7") || (tempDigit.substr(0, 1) == "8") || (tempDigit.substr(0, 1) == "9") || (tempDigit.substr(0, 1) == "0"))) {
                throw runtime_error("Error: Comma not followed by an integer.");
            }

            else {
                names.push_back(tempData);
                novels.push_back(stoi(tempDigit));
                cout << "Data string: " << names[passes] << endl;
                cout << "Data integer: " << novels[passes] << endl;
                passes++;
            }
        }
        catch (runtime_error& excpt) {
            cout << excpt.what() << endl;
        }
    } while (true);


    cout << endl << right << setw(33) << dataTitle << endl;
    cout << left << setw(20) << c1Head << "|" << right << setw(23) << c2Head << endl;
    for (int x = 0; x <= 43; x++) {
        cout << "-";
    }
    cout << endl;
    for (int x = 0; x <= passes - 1; x++) {
        cout << left << setw(20) << names[x] << "|" << right << setw(23) << novels[x] << endl;
    }
    cout << endl;

    for (int x = 0; (unsigned)x < names.size(); x++) {
        cout << right << setw(20) << names[x] << " ";
        for (int y = 0; y < novels[x]; y++) {
            cout << "*";
        }
        cout << endl;
    }
}