#include <iostream>
#include "Complex.h"
using namespace std;
int main() {
	// задаем зн-я для тестера
	Complex a(-3, 2);
	Complex b(2, 2);
	Complex c(17, 10);

	// смотрим вывод а
	cout << "a =" << a.getre() << " + i" << a.getmn() << endl;
	a = c;
	cout << "a =" << a.getre() << " + i " << a.getmn() << endl;
	// b и c
	cout << "b =" << b.getre() << " + i " << b.getmn() << endl;
	cout << "c =" << c.getre() << " + i " << c.getmn() << endl;

	// задали d
	Complex d(c);
	// смотрим d
	cout << "d =" << d.getre() << " + i " << d.getmn() << endl;

	// смотрим операции над 4 перем-ми, к-е задали
	cout << "a+b= " << (a + b).getre() << " + i " << (a + b).getmn() << endl;
	cout << "b-a= " << (b - a).getre() << " + i " << (b - a).getmn() << endl;
	cout << "a*d= " << (a * d).getre() << " + i " << (a * d).getmn() << endl;
	cout << "c/a= " << (c / a).getre() << " + i " << (c / a).getmn() << endl;

	// делаем цикл для пользователького ввода чисел: польз-ль вводит 2 к.ч., прога выводит рез-т их умн-я и дел-я
	string str = " ";
	while (str != "no") {
		cout << "Vvedi Complex chiclo: " << endl; cin >> a; cout << a << endl;
		cout << "Vvedi Complex chiclo: " << endl; cin >> b; cout << b << endl;
		cout << a * b << endl; cout << a / b << endl;
		cout << "continue?" << endl; // прога спрашивает продолжать ли работу if польз-ль ответит no, прога завершится, else что-то другое (например yes), прога запросит 2 новых к.ч и выполнит над ними умн-е и дел-е 
		cin >> str; // if польз-ль ответит no, прога завершится, else что-то другое (например yes), прога запросит 2 новых к.ч и выполнит над ними умн-е и дел-е 

	}
}
