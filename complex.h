#include <ostream>
#include <istream>
#include<string>
using namespace std;

void razdel(string st, string zn, string* w, int& k) {
	k = 0;
	w[0] = "";
	for (int i = 0; i < st.length(); ++i) {
		int l = zn.find(st[i]);
		if (l < 0) { w[k] += st[i]; }
		else {
			if (w[k].length() > 0) { w[++k] = ""; }
			if (st[i] != ' ') { w[k] += st[i]; }
		     }
	} k++;
}
class complex {
private: int re; int mn;
public:
	complex(int re_ = 0, int mn_ = 0) { re = re_; mn = mn_; }
	complex(const complex& temp) { re = temp.re; mn = temp.mn; }
	complex& operator=(complex temp) {
		re = temp.re;
		mn = temp.mn;
		return *this; }
	~complex() { };
	void setre(int a) { re = a; }
	void setmn(int b) { mn = b; }
	int getre() { return re; }
	int getmn() { return mn; }

	friend ostream& operator<< (ostream& out, complex tmp) {
		out << tmp.re << " + i " << tmp.mn;
		return out; };
	friend istream& operator>> (istream& in, complex& tmp) {
		int k; string str;
		in >> str;
		string w[3];
		razdel(str, " +-", w, k);
		tmp.re = 0; tmp.mn = 0;
		for (int i = 0; i < k; i++) {
			int l = w[i].find("i");
			if (l >= 0) {
				w[i].erase(l, 1);
				if ((w[i] == "") or (w[i] == "-") or (w[i] == "+")) { w[i] = w[i] + "1"; }
				//tmp.mn = w[i]; <- перевести из строки в число ( функция) 
				tmp.mn = stoi(w[i]);
			}
			else {
				//tmp.re = w[i]; <- перевести из строки в число ( функция) 	
				tmp.re = stoi(w[i]);
			}
		}
		return in; };
	complex operator+ (complex tmp) {
		complex res;
		res.re = re + tmp.re;
		res.mn = mn + tmp.mn;
		return res; }
	complex operator - (complex tmp) {
		complex res;
		res.re = re - tmp.re;
		res.mn = mn - tmp.mn;
		return res; }
	complex operator * (complex tmp) {
		complex res;
		res.re = (re * tmp.re) - (mn * tmp.mn);
		res.mn = (mn * tmp.re + re * tmp.mn);
		return res; }
	complex operator / (complex tmp) {
		complex res;
		res.re = (re * tmp.re + mn * tmp.mn) / (tmp.re * tmp.re + tmp.mn * tmp.mn);
		res.mn = (mn * tmp.re - re * tmp.mn) / (tmp.re * tmp.re + tmp.mn * tmp.mn);
		return res; }
};



