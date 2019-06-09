#include "interpretator.h"
int main() {
	string p("1+4-6/5+99--1");
	interpetator l(p);
	l.translate();
	return 0;
}