#include "Header.h"


string SetNameOfFile() {
    string name;
    cout << "Enter name of file: ";
    cin >> name;
    return name;
}

void OpenFile(string name) {
    ifstream fileif;
    char mode;
    string text;
    vector <Student> Students;
    cout << "Would you like to append your input?If so,enter 'a'.Otherwise enter 'w'" << endl;
    cin >> mode;
    while (true) {
        if (mode == 'a') {
            char letter;
            fileif.open(name, ios::binary);
            while (fileif.read((char*)&letter, sizeof(char))) {
                if (fileif.is_open()) {
                    if (letter == '\n') {
                        Students.push_back(text);
                        text = "";
                    }
                    else { text += letter; };
                }
            }
            fileif.close();
            break;
        }
        else if (mode == 'w') {
            break;
        }
        while (mode != 'a' && mode != 'w') {
            cout << "Enter correct letter: ";
            cin >> mode;
        }
    }
    ofstream fileof(name, ios::binary);
    string line;
    cout << "Enter the student information as \n Surname Initials Day.Month.Year(of birth) Group-Flow EducationForm AverageGrade \n Example: Ivaniv I. I. 15.12.2003 IK-9 day 89 \n To end the line | press ---> ENTER\n To end the input | input ---> 'end'" << endl;
    cin.ignore();
    getline(cin, line);
    while (line != "end") {
        Student stud(line);
        Students.push_back(stud);
        getline(cin, line);
    }
    for (int i = 0; i < Students.size(); i++) {
        fileof.write(Students[i].text.c_str(), Students[i].text.length());
    }
    fileof.close();
}

void output(string name) {
    ifstream fileif(name, ios::binary);
    char letter;
    while (fileif.read((char*)&letter, sizeof(char))) {
        cout << letter;
    }
    fileif.close();
}

vector <string> Student::split(string line, char del) {
    string elem = "";
    vector <string> elements;
    line += del;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == del) {
            if (elem.length() > 0) {
                elements.push_back(elem);
            }
            elem = "";
        }
        else elem += line[i];
    }
    return elements;
}

void min_marks(string name) {
    ifstream fileif(name, ios::binary);
    vector<string> flowList;
    vector<Student> minMark;
    vector<Student> students;
    char letter;
    string line;
    while (fileif.read((char*)&letter, sizeof(char))) {
        if (letter == '\n') {
            Student stud(line);
            students.push_back(stud);
            line = "";
        }
        line += letter;
    }
    for (int i = 0; i < students.size(); i++) {
        int index = 0;
        string flow = students[i].flow;
        float min = students[i].average;
        if (!inBase(flowList, flow)) {
            for (int j = i; j < students.size(); j++) {
                if (flow == students[j].flow) {
                    if (min >= students[j].average) {
                        min = students[j].average;
                        index = j;
                    }
                }
            }
            flowList.push_back(flow);
            minMark.push_back(students[index]);

        }
    }
    for (int i = 0; i < minMark.size(); i++) {
        cout << "Student with the smallest mark on the \"" << minMark[i].flow << "\" flow: " << minMark[i].PIB << " Group:" << minMark[i].group << " Mark:" << minMark[i].average << endl;
    }
}


bool inBase(vector<string> base, string line) {
    for (int i = 0; i < base.size(); i++) {
        if (base[i] == line)
            return true;
    }
    return false;
}


void FormFinalFile(string name) {
    ifstream fileif(name, ios::binary);
    float bal;
    char letter;
    string line = "";
    vector<Student> forsort;
    vector<Student> students;
    vector<Student> sorted;
    while (fileif.read((char*)&letter, sizeof(char))) {
        if (letter == '\n') {
            Student stud(line);
            students.push_back(stud);
            line = "";
        }
        else {
            line += letter;
        }
    }
    cout << "Enter min average mark: ";
    cin >> bal;
    for (int i = 0; i < students.size(); i++) {
        if ((stoi(students[i].group) / 10 == 4) && (students[i].edForm == "day") && (students[i].average >= bal)) {
            forsort.push_back(students[i]);
        }
    }
    if (forsort.size() == 0) {
        cout << "No students with searched parameters";
    }
    sorted = AlphabetSort(forsort);
    ofstream fileof("out_file.txt", ios::binary);
    for (int i = 0; i < sorted.size(); i++) {
        fileof.write(sorted[i].text.c_str(), sorted[i].text.length());
    }
    fileof.close();
    fileif.close();
}


vector <Student> AlphabetSort(vector<Student> forsort) {
    for (int i = 0; i < forsort.size(); i++) {
        for (int j = i + 1; j < forsort.size(); j++) {
            char* mass_i = new char[forsort[i].PIB.size() + 1];
            strcpy(mass_i, forsort[i].PIB.c_str());
            char* mass_j = new char[forsort[j].PIB.size() + 1];
            strcpy(mass_j, forsort[j].PIB.c_str());
            if (strcmp(mass_i, mass_j) > 0) {
                Student tmp = forsort[i];
                forsort[i] = forsort[j];
                forsort[j] = tmp;
            }
        }
    }
    return forsort;
}