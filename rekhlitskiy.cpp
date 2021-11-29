#include "Source.h"

using namespace std;

const short int maxEl = 10;
salary N[maxEl];
fileStruct f;

int main() {
    short int ans, structSize = 0;
    cout << "Hello! ";
    do {

        cout << "You're in main menu. Here's your options:\n[1] dataInput\n[2] dataOutput\n[3] inputInFile\n[4] readFile\n[5] editFile\n[6] set fileName\n>> ";
        cin >> ans;
        switch (ans) {
            case 1: structSize = dataInput(); break;
            case 2: dataOutput(structSize); break;
            case 3: inputInFile(structSize); break;
            case 4: structSize = readFile(); break;
            case 5: editFile(); break;
            case 6: setFileName(); break;
            default: cout << "Wrong answer!\n";
        }
        cout << "\n"; endLine(); cout << "To close the program type 0\n>> "; cin >> ans;
        endLine(0);
    } while (ans != 0);

    return 0;
}


int dataInput() {
    short int n;
    cout << "Enter number of lines you wanted to input:\n>> "; cin >> n;
    for (short int i = 0; i < n; i++) {

        cout << "\n\n########\n[" << i + 1 << "] line\n########\n\n";
        cout << "Fio:\n>> "; cin >> N[i].T;
        cout << "salary:\n>> "; cin >> N[i].RP;
        cout << "tax:\n>> "; cin >> N[i].PR;
        cout << "Final Salary :\n>> ";  N[i].PT = N[i].RP - N[i].PR; cout << N[i].PT;
    }
    return n;
}

void dataOutput(short int structSize = 0) {
    if (structSize == 0) cout << "You should put some data in here to see it!";

    else {
        float S1 = 0, S2 = 0, S3 = 0;
        tableHeader();
        for (int i = 0; i < structSize; i++) {
            cout << fixed;
            cout.precision(2);
            cout << "| " << i + 1 << " | " << N[i].T << "\t\t\t\t| " << N[i].RP << "\t\t| " << N[i].PR << "\t\t| " << N[i].PT;
            cout << endl;
            S1 += N[i].RP;
            S3 += N[i].PT;
        }

        cout << "| X | Average values\t| " << S1 << "\t\t\t| " << S3;

    }
}

int inputInFile(short int structSize = 0) {

    if (structSize == 0) { cout << "You should input some data to see it here!"; return -1; }
    fstream file;
    file.open(f.fileName);
    if (!file) {
        cout << "Can`t read filename, try another one! (press any key to continue)";

        system("cls");
        main();
    }
    file.close();
    bool ans = 0;
    if (!f.isEmpty) {
        cout << "File " << f.fileName << " is not empty, do you want to replace it or append new information in it? (0 - replace, 1 - app)\n>> ";
        cin >> ans;
    }
    short int n;
    switch (ans) {
        case 0: {
            file.open(f.fileName, ofstream::out | ofstream::trunc);
            cout << "Replacing all data...\n"; n = 1; break; }
        default: {file.open(f.fileName, ios_base::app); cout << "Adding new " << structSize << " line('s) in " << f.fileName << ".\n"; n = f.nOfLines + 1; file << endl; }
    }
    for (int i = 0; i < structSize; i++) {
        file << i + n << N[i].T << " " << N[i].RP << " " << N[i].PR << " " << N[i].FP << " " << N[i].PT;
        if (i < structSize - 1) file << endl;
    }
    cout << "Successful operation! All data were written in " << f.fileName << "!";
    file.close();

    return 0;
}

int readFile() {
    fstream file;
    file.open(f.fileName);
    if (!file) {
        cout << "Can`t read filename, try another one! (press any key to continue)";
        system("cls");
        main();
    }
    tableHeader();
    short int i = 0, pn = 0;
    while (true) {
        file >> pn >> N[i].T >> N[i].RP >> N[i].PR >> N[i].FP >> N[i].PT;
        cout << fixed;
        cout.precision(2);
        cout << "| " << pn << " | " << N[i].T << "\t\t\t| " << N[i].RP << "\t\t| " << N[i].PR << "\t\t\t| " << N[i].FP << "\t\t\t| " << N[i].PT;
        cout << endl;
        i++;
        if (file.tellg() == -1) break;
    }
    endLine(0);
    cout << "\nThe end of the file " << f.fileName << "!"; endLine;
    file.close();
    return i;
}

void editFile() {
    if (!f.fileName > 0) setFileName();
    ifstream file;
    file.open(f.fileName);
    if (!file) {
        cout << "Can`t read filename, try another one! (press any key to continue)";
        system("cls");
        main();
    }
    short int i = 0, pn;
    tableHeader();
    while (true) {
        if (file.tellg() == -1) { endLine(); cout << "The end of " << f.fileName << ".\n"; break; }
        file >> pn >> N[i].T >> N[i].RP >> N[i].PR >> N[i].FP >> N[i].PT;
        cout << fixed;
        cout.precision(2);
        cout << "| " << pn << " | " << N[i].T << "\t\t\t| " << N[i].RP << "\t\t\t| " << N[i].PR << "\t\t\t| " << N[i].FP << "\t\t\t| " << N[i].PT;
        cout << endl;
        i++;
    }

    short int line, row;
    cout << "Enter number of line you want to edit:\n>> "; cin >> line; line--;
    while (true)
        if (line > i || line < 0) { cout << "Error! This line is unspecified. Enter valid number:\n>> "; cin >> line; line--; }
        else
            break;
    cout << "Enter number of row you want to edit:\n>> "; cin >> row;
    cout << "Input new value for '";
    switch (row) {
        case 1: {cout << row << "'.\n[!]You can`t edit index!"; break; }
        case 2: {cout << N[line].T << "':\n>> "; cin >> N[line].T; break; }
        case 3: {cout << N[line].RP << "':\n>> "; cin >> N[line].RP; break; }
        case 4: {cout << N[line].PR << "':\n>> "; cin >> N[line].PR; break; }
        case 5: {cout << N[line].FP << "':\n>> "; cin >> N[line].FP; break; }
        case 6: {cout << N[line].PT << "'\nRecalculations for " << line << " line...";
            N[line].PT = N[i].RP - N[i].PR;
            cout << "\nNew value: " << N[line].PT << "UAH";
        }
        default: cout << "\n[!] Unexpected error.";
    }
    file.close();
    cout << "Your value successfully edited! You can save it in file through inputInFile\n";
}

void setFileName() {
    cout << "\nPlease, enter a fileName!\n>> "; cin >> f.fileName;
    ifstream file;
    file.open(f.fileName);
    f.isEmpty = false;
    if (!file) {
        short int ans;
        cout << "Is that new file?\n[1] Yes\n[2] No\n>> "; cin >> ans;
        switch (ans) {
            case 1: { ofstream file; file.open(f.fileName); f.isEmpty = true; f.nOfLines = 0; break; }
            case 2: {fstream file; file.open(f.fileName); f.isEmpty = false; break; }
            default: cout << "Error #101. Could`nt open file.";
        }
    }
    else {
        cout << "\nFile successfully opened!";
        string line;
        f.nOfLines = 0;
        while (!file.eof()) {
            getline(file, line);
            f.nOfLines++;
        }
        cout << "(" << f.nOfLines << " lines)";
    }
    file.close();
}
