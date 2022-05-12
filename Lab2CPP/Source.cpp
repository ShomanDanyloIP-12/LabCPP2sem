#include "Header.h"

int main() {
    string FileName = SetNameOfFile();
    OpenFile(FileName);
    cout << "List of students:\n";
    output(FileName);
    min_marks(FileName);
    FormFinalFile(FileName);
    output("out_file.txt");
}
