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
	stringstream str(work_line);
	stack<double> st;
	stack<token> tokens;
	queue<token> result;
	token buff;
	string line,line2;
	size_t i = 0;
	while(!str.eof()) {
		if (str.peek()==EOF)break;
		str >> line;
		try
		{

			line2 = "";
			if (isalnum(line[i])) {
				while (isalnum(line[i])) {
					line2 = line2 + line[i];
					i++;
				}
			}
			else line2 = line[i];
			cout << line2;
			buff=line2;
		}
		catch (const string&)
		{
			throw exceptions("fail in interpretator:translate");
		}
		if (buff.is_number()) {
			result.push(buff);
		}
		else {
			if (buff.is_unary()) {
				tokens.push(buff);
			}
			if (buff.is_open_token()) {
				tokens.push(buff);
			}
			if (buff.is_closed_token()) {
				while (!tokens.top().is_open_token()) {
					result.push(tokens.top());
					try
					{
						tokens.pop();
					}
					catch (const string&) {
						throw exceptions("unblalanced line :fail in interpetator:translate");
					}
				}
				tokens.pop();

			}
			if (buff.is_binary()) {
				while (!tokens.empty() && (tokens.top().is_unary() || tokens.top() > buff || (tokens.top() == buff && tokens.top().is_left_assoc()))) {
					result.push(tokens.top());
					tokens.pop();
				}
				tokens.push(buff);
			}
		}
		i++;
	}
	while (!tokens.empty()) {
		result.push(tokens.top());
		cout << tokens.top().get_operand();
		tokens.pop();
	}
	return result;
}