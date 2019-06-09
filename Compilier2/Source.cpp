#include "interpretator.h"
#include <cstdlib>
using namespace std;
void menu() { cout << "1.from keyboard excpression" << endl << "2.from file excpression" << endl << "3.see excpression" << endl << "4.calculate and translate excpression" << endl << "5.exit" << endl; }
int main() {
	int check(0);
	interpetator curr;
	string input;
	while (check != 5) {
		menu();
		cin >> check;
		while ((check < 1) || (check > 5)||(!cin)) {
			cin.clear();
			cin.ignore(32767, '\n');
			system("cls");
			menu();
			cin >> check;
		}
		if (check == 1) {
			system("cls");
			cout << "press excpression" << endl;
			cin >> input;
			curr = input;
			check = 0;
		}
		if (check == 2) {

		}
		if (check == 3) {
			system("cls");
			cout << *curr << endl;
			check = 0;
		}
		if (check == 4) {
			system("cls");
			queue<token> out=curr.translate();
			while (!out.empty()) {
				cout << out.front().get_operand();
				out.pop();
			}
			cout << endl;
		}
	}
	return 0;
}