#include <iostream>
#include "Complex.h"
using namespace std;
int main() {
	Complex a(-3, 2);
	Complex b(2, 2);
	Complex c(17, 10);
    
	cout << "a =" << a.getre() << " + i" << a.getmn() << endl;
	a = c;

	Complex d(c);
	cout << "a =" << a.getre() << " + i " << a.getmn() << endl;
	cout << "b =" << b.getre() << " + i " << b.getmn() << endl;
	cout << "c =" << c.getre() << " + i " << c.getmn() << endl;
	cout << "d =" << d.getre() << " + i " << d.getmn() << endl;
	cout << "a =" << a << endl;
	cout << "a+b= " << (a + b).getre() << " + i " << (a + b).getmn() << endl;
	cout << "b-a= " << (b - a).getre() << " + i " << (b - a).getmn() << endl;
	cout << "a*d= " << (a * d).getre() << " + i " << (a * d).getmn() << endl;
	cout << "c/a= " << (c / a).getre() << " + i " << (c / a).getmn() << endl;
	string str = " ";
	while (str != "no") {
		cout << "Vvedi Complex chiclo: " << endl; cin >> a; cout << a << endl;
		cout << "Vvedi Complex chiclo: " << endl; cin >> b; cout << b << endl;
		d = a * b;
		cout << d << endl;
		d = a / b;
		cout << d << endl;
		cout << "esho chitat?" << endl;
		cin >> str;
	}
}
