#pragma once

#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <stack>
#include "token.h"
using namespace std;

class interpetator {
private:
	string work_line;
public:
	interpetator();
	interpetator(fstream&);
	interpetator(const string&);
	interpetator(const char*);
	const string translate();
	const string calculate();
};