#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

struct Student {
    string PIB, edForm, group, flow, birth, text;
    int average;
    vector <string> split(string line, char del);
    Student(string line) {
        text = line + '\n';
        vector<string> elements = split(line, ' ');
        PIB = elements[0] + " " + elements[1] + " " + elements[2];
        birth = elements[3];
        group = split(elements[4], '-')[1];
        flow = split(elements[4], '-')[0];
        edForm = elements[5];
        average = stof(elements[6]);
   }
};

string SetNameOfFile();
void OpenFile(string);
void output(string);
void min_marks(string);
bool inBase(vector<string>, string);
void FormFinalFile(string);
vector <Student> AlphabetSort(vector<Student>);
