#include "Header.h"
const string name = "text";
const string start_file = "text";
const string first_file = "first_file";
const string second_file = "second_file";

int main() {
	vector<string> lines_array;
	input_text(name);
	print_file(name);
	distribute_strings(start_file, first_file, second_file);
	cout << "Parnyi file: " << endl;
	print_file(second_file);
	cout << "Neparnyi file before sorting: " << endl;
	print_file(first_file);
	sort_lines(first_file);
	cout << "Parnyi file: " << endl;
	print_file(second_file);
	cout << "Neparnyi file: " << endl;
	print_file(first_file);
}