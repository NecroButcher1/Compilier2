#include "token.h"

/*constructors tokens, make priority and associativity*/
token::token(const string& in) {
	if (priority1.find(in) != priority1.end()) {
		type = unary_operator;
		assoc = right_assoc;
		priority = 5;
	}
	else if (priority2.find(in) != priority2.end()) {
		type = binary_operator;
		assoc = right_assoc;
		priority = 4;
	}
	else if (priority3.find(in) != priority3.end()) {
		type = binary_operator;
		assoc = left_assoc;
		priority = 3;
	}
	else if (priority4.find(in) != priority4.end()) {
		type = binary_operator;
		assoc = right_assoc;
		priority = 2;
	}
	else if (priority5.find(in) != priority5.end()) {
		type = binary_operator;
		assoc = left_assoc;
		priority = 1;
	}
	else if (priority6.find(in) != priority6.end()) {
		type = punctuation;
		assoc = left_assoc;
		priority = 0;
	}
	else {
		try 
		{
			stod(in);
			type = number;
		}
		catch (string&) {
			throw exceptions("unknown token, error in token::token ");
		}
	}
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