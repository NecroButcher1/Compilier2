#pragma once
#ifndef TOKEN_H_INCLUDED
#define TOKEN_H_INCLUDED
#include <set>
#include <string>
#include "exceptions.h"
using namespace std;

/* operators and priority operators*/
const set<string> operators({ "^~+-*/&<>=#!;)(" }); 
const set<string> priority1({ "^~+-" });
const set<string> priority2({ "*/&" });
const set<string> priority3({ "+-" });
const set<string> priority4({ "<>=#" });
const set<string> priority5({ "!" });
const set<string> priority6({ "();" });

/*what is it?*/
const string number("number");
const string function("function");
const string left_assoc("left");
const string right_assoc("right");
const string unary_operator("unary");
const string binary_operator("binary");
const string punctuation("punctuation");

class token {
private:
	string symbol, type, assoc;
	int priority;
public:
	token(const string&);
	token() :symbol("null"), type(unary_operator), assoc(left_assoc) {};
	token operator=(const string&);
	token operator=(token&);
	const bool operator==(const string&);
	const bool operator==(token&);
	const bool operator==(const int&);
	const bool operator<(token&);
	const bool operator<(const int&);
	const bool operator>(token&);
	const bool operator>(const int&);
	const bool operator<=(token&);
	const bool operator<=(const int&);
	const bool operator>=(token&);
	const bool operator>=(const int&);
	const bool is_unary();
	const bool is_binary();
	const bool is_right_assoc();
	const bool is_left_assoc();
	const bool is_open_token();
	const bool is_closed_token();
	const bool is_end_operand();
	const bool is_number();
	const bool is_function();
	const bool is_punctuation();
	const string get_operand();
	const string get_type();
	const string get_assoc();
	const int get_priority();
	~token() = default;
};
#endif // TOKEN_H_INCLUDED