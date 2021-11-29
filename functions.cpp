#include "Source.h"

using namespace std;

void tableHeader() {
    cout << "| # |   Fio\t         |Salary\t| Podatok\t| Do vidach\t|\n";
}
void endLine(bool endL) {
    if(endL) cout << endl;
    for (short int i = 0; i < 160; i++) cout << "#";
    cout << endl;
}