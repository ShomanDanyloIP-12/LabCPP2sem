#include "Header.h"
#include "Ring.h"

bool isNumber(string str)
{
    return str.find_first_not_of("0123456789 -") == string::npos;
}

bool isInterval(string str)
{
    return str.find_first_not_of("0123456789[], -") == string::npos;
}


vector <string> split(string line, char del) {
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


bool ifPossible(int num1, int num2) {
    return num1 < num2;
}

int Ring::ifPossible(int num1, int num2) {
    if (num1 < num2) {
        return (num1 + 1);
    }
    else {
        cout << "Operation can`t be done" << '\n';
        return num1;
    }
}


Ring createRing(string num)
{
    cout << "num: " << num << endl;
    if (num.empty())
    {
        cout << "std method accepted" << endl;
        return Ring();
    }
    else if (isNumber(num))
    {
        cout << "1 2 3 4 method accepted" << endl;
        if (stoi(split(num, ' ')[2]) >= 0 && stoi(split(num, ' ')[3]) >= 0 && ifPossible(stoi(split(num, ' ')[2]), stoi(split(num, ' ')[3]))) {
            return Ring(num);
        }
        else {
            cout << "Invalid input. Creating a default ring\n";
            return Ring();
        }
    }
    else if (isInterval(num))
    {
        cout << "[1,3], [5,8] method accepted" << endl;
        vector <int> nums = IntervaltoForm(num);
        if (ifPossible(nums[0], nums[1]) && ifPossible(nums[2], nums[3]) && nums[2] >= 0 && nums[3] >= 0) {
            return Ring(nums[0], nums[1], nums[2], nums[3]);      
        }
        else {
            cout << "Invalid input. Creating a default ring\n";
            return Ring();
        }
    }
    else
    {
        cout << "Invalid input. Creating a default ring";
        return Ring();
    }
}

vector <int> IntervaltoForm(string num) {
    vector <int> outnums;
    cout << "converting '" << num << "' to int" << endl;
    outnums.push_back(stoi((split((split((split((split(num, ', '))[0], '[')[0]), ']')[0]), ','))[0]));
    outnums.push_back(stoi((split((split((split((split(num, ', '))[0], '[')[0]), ']')[0]), ','))[1]));
    outnums.push_back(stoi((split((split((split((split(num, ', '))[1], '[')[0]), ']')[0]), ','))[0]));
    outnums.push_back(stoi((split((split((split((split(num, ', '))[1], '[')[0]), ']')[0]), ','))[1]));
    cout << "converted '" << outnums[0] << " " << outnums[1] << " " << outnums[2] << " " << outnums[3] << endl;
    return outnums;
}