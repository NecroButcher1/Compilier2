#pragma once
#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED
#include <iostream>
class exceptions{
private:
	size_t position_error;
	const char* messages;
public:
	exceptions(const char* _messages, size_t _position_error) :messages(_messages), position_error(_position_error) {
		std::cout << messages << " :" << position_error << std::endl;
	}
	exceptions(const char* _messages) :messages(_messages) {
		std::cout << messages << std::endl;
	}
};
#endif //EXCEPTIONS_H_INCLUDED
