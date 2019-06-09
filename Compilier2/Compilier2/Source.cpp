#include "interpretator.h"
int main() {
	string p("1+2+3");
	interpetator l(p);
	l.translate();
	return 0;
}