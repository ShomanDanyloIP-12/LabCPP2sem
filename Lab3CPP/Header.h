#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Text
{
	int textSize;
	int vowelAmount;
	vector<string> text;

public:
	Text(int size, vector<string> rows)
	{
		textSize = size;
		text = rows;
		vowelAmount = 0;
		for (int i = 0; i < textSize; i++)
		{
			for (int j = 0; j < text[i].length(); j++) {
				if (text[i][j] == 'A' || text[i][j] == 'a' || text[i][j] == 'O' || text[i][j] == 'o' || text[i][j] == 'u' || text[i][j] == 'U' || text[i][j] == 'I' || text[i][j] == 'i' || text[i][j] == 'E' || text[i][j] == 'e' || text[i][j] == 'y' || text[i][j] == 'Y') {
					vowelAmount++;
				}
			}
		}
		cout << "Vowel amount - " << vowelAmount << endl;
	}

	void add(string row)
	{
		text.push_back(row);
		textSize += 1;
	}

	vector<string> getText()
	{
		return text;
	}

	int getSize()
	{
		return textSize;
	}

	int getVowelAmount()
	{
		return vowelAmount;
	}
};

bool getRows(vector<string>& rows);
void getTexts(vector<Text>& texts);
void extendTexts(vector<Text>& texts);
void printText(vector<Text> texts);
void textWithMaxVowelLetters(vector<Text> texts);