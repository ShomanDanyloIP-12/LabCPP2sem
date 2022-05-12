#include "Header.h"

void input_text(const string name)
{
    char mode;
    cout << "If you want to append ur input,press q.Otherwise press w "; cin >> mode;

    ofstream file_out;

    switch (mode)
    {
    case 'q':
        file_out.open(name, ios::app);
        break;

    case 'w':
        file_out.open(name);
        break;

    default:
        file_out.open(name);
        break;
    }

    if (file_out.is_open()) { cout << endl << "Start file is successfully opened!" << endl << endl; }
    else { cout << "Error! Could not open the start file!" << endl; exit(0); }

    string line;
    cin.ignore();
    cout << "Enter text:\n Next line ---> press ENTER \n Close file ---> press Ctrl + X " << endl;
    while (true)
    {
        getline(cin, line);
        line[0] = tolower(line[0]);

        if ((int)line[0] != 24) { file_out << line << endl; }
        else { break; }
    }

    file_out.close();
}

void print_file(const string name)
{
    ifstream file_in(name);

    if (!file_in.is_open()) { cout << "Error! Could not open the file!" << endl; exit(0); }

    string line;

    while (!file_in.eof())
    {
        getline(file_in, line);
        cout << line << endl;
    }

    file_in.close();
}

vector<string> create_linesArray(const string name)
{
    ifstream file_in(name);

    if (!file_in.is_open()) { cout << "Error! Could not open the file!" << endl; }

    vector<string> lines_array;
    string line;

    while (!file_in.eof())
    {
        getline(file_in, line);

        if (line == "") { continue; }
        else { lines_array.push_back(line); }
    }

    file_in.close();

    return lines_array;
}

void distribute_strings(const string start_file, const string first_file, const string second_file)
{
    ifstream start_file_in(start_file);
    ofstream first_file_out(first_file),
        second_file_out(second_file);

    if (!start_file_in.is_open() || !first_file_out.is_open() || !second_file_out.is_open())
    {
        cout << "Error! File could not open, cannot distribute strings!";
        exit(0);
    }

    vector<string> lines_array = create_linesArray(start_file);

    for (int i = 0; i < lines_array.size(); i++)
    {
        if (i % 2 == 0) { first_file_out << lines_array[i] << endl; }
        else { second_file_out << lines_array[i] << endl; }
    }

    start_file_in.close();
    first_file_out.close();
    second_file_out.close();
}

void sort_lines(const string name)
{
    fstream file_out_in(name, fstream::out | fstream::in);

    if (!file_out_in.is_open())
    {
        cout << "Error! Could not open the file for sorting!" << endl;
        exit(0);
    }

    vector<string> lines_array = create_linesArray(name);

    int N;
    cout << "Enter N(can`t be higher than " << lines_array.size() << " ): "; cin >> N;

    while (N > lines_array.size())
    {
        cout << "Attention! N can`t be higher than " << lines_array.size() << ". Enter again: "; cin >> N;
    }

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if (lines_array[j] > lines_array[j + 1])
            {
                swap(lines_array[j], lines_array[j + 1]);
            }
        }
    }

    for (int i = 0; i < lines_array.size(); i++)
    {
        file_out_in << lines_array[i] << endl;
    }

    file_out_in.close();
}