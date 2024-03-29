#include "token.h"

/*constructors tokens, make priority and associativity*/
token::token(const string& in) {
	if ((priority1.find(in) != priority1.end())and((in=="+")||(in=="-"))) {
		symbol = in;
		type = unary_operator;
		assoc = right_assoc;
		priority = 5;
	}
	if ((priority1.find(in) != priority1.end()) and (in == "^")) {
		symbol = in;
		type = binary_operator;
		assoc = right_assoc;
		priority = 5;
	}
	 if (priority2.find(in) != priority2.end()) {
		symbol = in;
		type = binary_operator;
		assoc = right_assoc;
		priority = 4;
		}
	 if (priority3.find(in) != priority3.end()) {
		symbol = in;
		type = binary_operator;
		assoc = left_assoc;
		priority = 3;
		}
	 if (priority4.find(in) != priority4.end()) {
		symbol = in;
		type = binary_operator;
		assoc = right_assoc;
		priority = 2;
		}
	 if (priority5.find(in) != priority5.end()) {
		symbol = in;
		type = binary_operator;
		assoc = left_assoc;
		priority = 1;
		}
	 if (priority6.find(in) != priority6.end()) {
		symbol = in;
		type = punctuation;
		assoc = left_assoc;
		priority = 0;
		}
	if(operators.find(in)==operators.end()) {
		try 
		{
			stod(in);
		//	cout << in;
			type = number;
			symbol = in;
		}
		catch (const string&) {
			throw exceptions("unknown token, error in token::token ");
		}
	}
}
token::token(const string& operand, const bool& prev_number) {
	if ((priority1.find(operand) != priority1.end()) and ((operand=="+") or (operand=="-") or (operand=="^"))) {
		if (prev_number or operand=="^") {
			symbol = operand;
			type = binary_operator;
			assoc = left_assoc;
			priority = 3;
		}
		else {
			symbol = operand;
			type = unary_operator;
			assoc = right_assoc;
			priority = 5;
		}
	}
	if (priority2.find(operand) != priority2.end()) {
		symbol = operand;
		type = binary_operator;
		assoc = right_assoc;
		priority = 4;
	}
	if (priority3.find(operand) != priority3.end()) {
		symbol = operand;
		type = binary_operator;
		assoc = left_assoc;
		priority = 3;
	}
	if (priority4.find(operand) != priority4.end()) {
		symbol = operand;
		type = binary_operator;
		assoc = right_assoc;
		priority = 2;
	}
	if (priority5.find(operand) != priority5.end()) {
		symbol = operand;
		type = binary_operator;
		assoc = left_assoc;
		priority = 1;
	}
	if (priority6.find(operand) != priority6.end()) {
		symbol = operand;
		type = punctuation;
		assoc = left_assoc;
		priority = 0;
	}
	if (operators.find(operand) == operators.end()) {
		try
		{
			stod(operand);
			//	cout << in;
			type = number;
			symbol = operand;
		}
		catch (const string&) {
			throw exceptions("unknown token, error in token::token ");
		}
	}
	/*if ((priority1.find(operand) != priority1.end()) and (operand == "^")) {
		if (prev_number) {
			symbol = operand;
			type = binary_operator;
			assoc = right_assoc;
			priority = 5;
		}
	}*/
}
token::token(pair<const string,const bool> in) {
	*this = *(new token(in.first, in.second));
}


token token::operator=(pair<const string, const bool> in) {
	*this = *(new token(in.first, in.second));
	return *this;
}
token token::operator=(token& in) {
	type = in.type;
	symbol = in.symbol;
	assoc = in.assoc;
	priority = in.priority;
	return *this;
}
token token::operator=(const string& in) {
	*this = *(new token(in));
	return *this;
}

/*operators tokens*/
const bool token::operator==(const string& in) {
	return symbol == in;
}
const bool token::operator==(const int& in) {
	return priority == in;
}
const bool token::operator==(token& in) {
	return priority = in.priority;
}
const bool token::operator<(token& in) {
	return priority < in.priority;
}
const bool token::operator<(const int& in) {
	return priority < in;
}
const bool token::operator>(token& in) {
	return priority > in.priority;
}
const bool token::operator>(const int& in) {
	return priority > in;
}
const bool token::operator<=(token& in) {
	return priority <= in.priority;
}
const bool token::operator<=(const int& in) {
	return priority <= in;
}
const bool token::operator>=(token& in) {
	return priority >= in.priority;
}
const bool token::operator>=(const int& in) {
	return priority >= in;
}
const bool token::is_binary() {
	return type == binary_operator;
}
const bool token::is_unary() {
	return type == unary_operator;
}
const bool token::is_left_assoc() {
	return assoc == left_assoc;
}
const bool token::is_right_assoc() {
	return assoc == right_assoc;
}
const bool token::is_closed_token() {
	return symbol == ")";
}
const bool token::is_open_token() {
	return symbol == "(";
}
const bool token::is_end_operand() {
	return symbol == ";";
}
const bool token::is_number() {
	return type == number;
}
const bool token::is_punctuation() {
	return type == punctuation;
}
const bool token::is_function() {
	return type == function;
}
const string token::get_assoc() {
	return assoc;
}
const string token::get_type() {
	return type;
}
const string token::get_operand() {
	return symbol;
}
const int token::get_priority() {
	return priority;
}