#include <ostream>
#include <istream>
#include<string>
using namespace std;

// делим стр на слова в сл-е раздел-й + и -
void del_str_to_words(string st, string zn, string* w, int& k) {
	k = 0; w[0] = "";
	for (int i = 0; i < st.length(); ++i) {
		int l = zn.find(st[i]);
		if (l < 0) { w[k] += st[i]; }
		else {
			if (w[k].length() > 0) { w[++k] = ""; }
			if (st[i] != ' ') { w[k] += st[i]; }
		     }
	} k++;
}

// начало обьявл-я класса
class Complex {
private: int re; int mn; // спецификатор доступа 
public:
	Complex(int re_ = 0, int mn_ = 0) { re = re_; mn = mn_; }
	
        Complex(const Complex& temp) { re = temp.re; mn = temp.mn; }
	
        Complex& operator=(Complex temp) {
		re = temp.re;
		mn = temp.mn;
		return *this; }

	~Complex() { }; // деструктор

	void setre(int a) { re = a; }
	void setmn(int b) { mn = b; }
	int getre() { return re; }
	int getmn() { return mn; }

        // перегрузка вывода
	friend ostream& operator<< (ostream& out, Complex tmp) {
		out << tmp.re << " + i " << tmp.mn;
		return out; };
        // перегрузка ввода
	friend istream& operator>> (istream& in, Complex& tmp) {
		int k; string str;
		in >> str;
		string w[3];
		del_str_to_words(str, " +-", w, k);
		tmp.re = 0; tmp.mn = 0;
		// делаем из строки, к-ю ввел польз-ль, число (в пониманиии комп-а)
		for (int i = 0; i < k; i++) {
			int l = w[i].find("i");
			if (l >= 0) {
				w[i].erase(l, 1);
				if ((w[i] == "") or (w[i] == "-") or (w[i] == "+")) { w[i] = w[i] + "1"; }
				tmp.mn = stoi(w[i]); // stoi преоб-т str в int (для "10" stoi возвр целочисл зн-е 10)
			} else { tmp.re = stoi(w[i]); }
		}
		return in; };

        // перегрузка операций
	Complex operator + (Complex tmp) {
		Complex res;
		res.re = re + tmp.re; res.mn = mn + tmp.mn;
		return res; }
	Complex operator - (Complex tmp) {
		Complex res;
		res.re = re - tmp.re; res.mn = mn - tmp.mn;
		return res; }
	Complex operator * (Complex tmp) {
		Complex res;
		res.re = (re * tmp.re) - (mn * tmp.mn);
		res.mn = (mn * tmp.re + re * tmp.mn);
		return res; }
	Complex operator / (Complex tmp) {
		Complex res;
		res.re = (re * tmp.re + mn * tmp.mn) / (tmp.re * tmp.re + tmp.mn * tmp.mn);
		res.mn = (mn * tmp.re - re * tmp.mn) / (tmp.re * tmp.re + tmp.mn * tmp.mn);
		return res; }
}; // конец обьяв-я класса



