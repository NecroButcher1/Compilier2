#include "interpretator.h"

/**
*	use "Exceptions.h"
*	constructors interpretators 
*/
interpetator::interpetator():work_line(""){
	exceptions("empty arguments");
}
interpetator::interpetator(fstream& input) {
	getline(input, work_line);
	work_line.erase(remove(work_line.begin(), work_line.end(), ' '), work_line.end());
	if (work_line.empty())exceptions("empty arguments");
}
interpetator::interpetator(const string& input):work_line(input) {
	work_line.erase(remove(work_line.begin(), work_line.end(), ' '), work_line.end());
	if (work_line.empty())exceptions("empty arguments");
}
interpetator::interpetator(const char* input) : work_line(input) {
	work_line.erase(remove(work_line.begin(), work_line.end(), ' '), work_line.end());
	if (work_line.empty())exceptions("empty arguments");
}

/*translate to RPN*/

const string interpetator::translate() {
	istringstream str(work_line);
	stack<double> st;
	stack<token> tokens;
	token buff;
	string line;
	while(!str.eof()) {
		if (str.peek())break;
		str >> line;
		try
		{
			buff=line;
		}
		catch (string&)
		{
			throw exceptions("fail in interpretator:translate");
		}
	}
}

double interpetator::calculate(queue<token> b)
{
	if (b.empty()) {
		throw exceptions("Empty RPN");
	}
	else if (b.size < 2) {
		throw exceptions("Small size ");
	}
	else {
		token temp; 
		b.pop(temp);
		


	}
	return string();
}
