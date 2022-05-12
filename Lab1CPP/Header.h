#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


void input_text(const string name);
void print_file(const string name);
vector<string> create_linesArray(const string name);
void distribute_strings(const string start_file, const string first_file, const string second_file);
void sort_lines(const string name);