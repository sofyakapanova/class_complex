#include <iostream>
#include "complex.h"
using namespace std;
int main() {
	complex a(-3, 2);
	complex b(2, 2);
	complex c(17, 10);
    
	cout << "a =" << a.getre() << " + i" << a.getmn() << endl;
	a = c;

	complex d(c);
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
		cout << "Vvedi complex chiclo: " << endl; cin >> a; cout << a << endl;
		cout << "Vvedi complex chiclo: " << endl; cin >> b; cout << b << endl;
		d = a * b;
		cout << d << endl;
		d = a / b;
		cout << d << endl;
		cout << "esho chitat?" << endl;
		cin >> str;
	}
}
