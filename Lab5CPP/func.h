#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Classes.h"
using namespace std;

void input(int& val);
TIntNumber* InputBinNumbers(int);
TIntNumber* InputOctNumbers(int);
void PrintArrayAll(TIntNumber*, TIntNumber*, int, int);
void PrintArray(TIntNumber*, int);
int FindTheSmallestDecNumber(TIntNumber*, TIntNumber*, int, int);
void Operations(TIntNumber*, TIntNumber*, int, int);
