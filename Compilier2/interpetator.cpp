#include "interpretator.h"

/**
*	use "Exceptions.h"
*	constructors interpretators 
0*/
interpetator::interpetator():work_line(""){
	//exceptions("empty arguments");
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

/*operators for lol and kek */
interpetator interpetator::operator=(const string& input) {
	*this = *(new interpetator(input));
	return *this;
}
interpetator interpetator::operator=(fstream& input) {
	*this = *(new interpetator(input));
	return *this;
}
const string interpetator::operator*() {
	return work_line;
}
/*translate to RPN*/

queue<token> interpetator::translate(){
	stringstream str(work_line);
	stack<token> tokens;
	queue<token> result;
	token buff;
	string line,line2;
	size_t i = 0;
	str >> line;
	while(i<line.length()){
		try
		{
			line2 = "";
			line2 = line[i];
			if ((line[i] >= '0') && (line[i] <= '9'))
			{
				line2 = "";
				while ((line[i] >= '0') && (line[i] <= '9')) {
					line2 = line2 + line[i];
					++i;
				}
				--i;
			}
			buff=line2;
			//cout << buff.get_operand();
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
		tokens.pop();
	}
	return result;
}
const double interpetator::calculate() {
	queue<token> result;
	try
	{
		result = this->translate();
	}
	catch (const string&)
	{
		throw exceptions("fail in calculate :interpretator:calculate");
	}
	stack<double> buff;
	if (result.empty()) {
		throw exceptions("empty result queue");
	}
	while (!result.empty()) {
		if (result.front().is_number()) {
			buff.push(stod(result.front().get_operand()));
			result.pop();
		}
		if (!result.empty() and result.front().get_operand() =="+" and result.front().is_binary()) {
			if (buff.size() >= 2) {
				double temp = buff.top();
				buff.pop();
				temp += buff.top();
				buff.pop();
				buff.push(temp);
				result.pop();
			}
			else throw exceptions("variables not enought ");
		}
		if (!result.empty() and result.front().get_operand() == "-" and result.front().is_binary()) {
			if (buff.size() >= 2) {
				double t1 = buff.top();
				buff.pop();
				double t2 = buff.top();
				buff.pop();
				 t2 = t2 - t1;
				buff.push(t2);
				result.pop();
			}
			else throw exceptions("variables not enought ");
		}
		if (!result.empty() and result.front().get_operand() == "-" and result.front().is_unary()) {
			if (buff.size() > 0) {
				double temp = buff.top();
				buff.pop();
				temp = temp*(-1);
				buff.push(temp);
				result.pop();
			}
			else throw exceptions("variables not enought ");
		}
		if (!result.empty() and result.front().get_operand() == "+" and result.front().is_unary()) {
			if (buff.size() > 0) {
				double temp = buff.top();
				buff.pop();
				buff.push(temp);
				result.pop();
			}
			else throw exceptions("variables not enought ");
		}
		if (!result.empty() and result.front().get_operand() == "*" and result.front().is_binary()) {
			if (buff.size() >= 2) {
				double t1 = buff.top();
				buff.pop();
				double t2 = buff.top();
				buff.pop();
				t2 = t2 * t1;
				buff.push(t2);
				result.pop();
			}
			else throw exceptions("variables not enought ");
		}
		if (!result.empty() and result.front().get_operand() == "/" and result.front().is_binary()) {
			if (buff.size() >= 2) {
				double t1 = buff.top();
				buff.pop();
				double t2 = buff.top();
				buff.pop();
				t2 = t2 / t1;
				buff.push(t2);
				result.pop();
			}
			else throw exceptions("variables not enought ");
		}
		if (!result.empty() and result.front().get_operand() == "^" and result.front().is_binary()) {
			if (buff.size() >= 2) {
				double t1 = buff.top();
				buff.pop();
				double t2 = buff.top();
				buff.pop();
				t2 = pow(t2,t1);
				buff.push(t2);
				result.pop();
			}
			else throw exceptions("variables not enought ");
		}
	}
	double result1 = 0;
	while (!buff.empty()) {
		result1 += buff.top();
		buff.pop();
	}
	return result1;
}