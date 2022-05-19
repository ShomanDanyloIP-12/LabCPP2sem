#include "Header.h"

bool getRows(vector<string>& rows)
{
    string row;
    rows.clear();
    bool more = true;
    char worq;
    cout << "Enter the text. Enter Ctrl+X to finish text\n";
    while (more)
    {
        getline(cin, row);
        if (row == "end")
        {
            more = false;
        }
        else if (row != "")
        {
            if (row.back() == '\x18')
            {
                more = false;
                row = row.substr(0, row.length() - 1);
            }
            rows.push_back(row);
        }
    }
    cout << "Enter another text - q, finish entering - w) ";
    cin >> worq;
    if (worq == 'w') return true;
    else if (worq == 'q') return false;
    else return true;
}

void getTexts(vector<Text>& texts)
{
    vector<string> rows;
    bool more;
    do
    {
        more = getRows(rows);
        if (rows.size() > 0)
        {
            Text currText(rows.size(), rows);
            texts.push_back(currText);
        }
    } while (more);
}

void extendTexts(vector<Text>& texts)
{
    string row;
    bool more = true;
    string strInput;
    int textInd;
    do
    {
        cout << "Enter index of the text to extend it, or Ctrl+X to quit\n";
        cin >> strInput;
        if (strInput == "\x18")
        {
            more = false;
        }
        else
        {
            textInd = stoi(strInput);
            if (textInd >= texts.size())
            {
                cout << "Error: text index is too big";
            }
            else
            {
                cout << "Enter the row\n";
                cin.ignore();
                getline(cin, row);
                texts[textInd].add(row);
            }
        }
    } while (more);
}

void printText(vector<Text> texts)
{
    vector<string> currText;
    for (int i = 0; i < texts.size(); i++)
    {
        cout << "\nText " << i << ":\n";
        currText = texts[i].getText();
        for (int j = 0; j < currText.size(); j++)
        {
            cout << currText[j] << '\n';
        }
        currText.clear();
    }
}

void textWithMaxVowelLetters(vector<Text> texts)
{
    int maxTextIndex = 0;
    int maxVowel = 0;
    for (int i = 0; i < texts.size(); i++)
    {
        if (texts[i].getVowelAmount() > maxVowel)
        {
            maxTextIndex = i;
            maxVowel = texts[i].getVowelAmount();
        }
    }
    cout << "\nMaximal amount of vowels:\n" << maxVowel << "\n";
    cout << "Found in text: " << maxTextIndex << '\n';
}