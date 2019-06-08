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

queue<token> interpetator::translate(){
	istringstream str(work_line);
	stack<double> st;
	stack<token> tokens;
	queue<token> result;
	token buff;
	string line;
	while(!str.eof()) {
		if (str.peek())break;
		str >> line;
		try
		{
			buff=line;
		}
		catch (const string&)
		{
			throw exceptions("fail in interpretator:translate");
		}
		
	}
}