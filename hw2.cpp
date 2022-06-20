
#include <iostream>
using namespace std;

class weight { //class type을 구현함.
	int kg;
	int g;

public: //member function declaration
	void set_weight(int n1, int n2);
	int get_weight();
};

weight add_weight(weight w1, weight w2) {
	weight tmp;
	int n;
	n = w1.get_weight() + w2.get_weight();
	tmp.set_weight(n / 1000, n % 1000);
	return tmp;
}

bool less_than(weight w1, weight w2) {
	if (w1.get_weight() < w2.get_weight())
		return true;
	else
		return false;

}

int main() {
	weight w1, w2, w3; //weight라는 class object 생섬함.
	w1.set_weight(3, 400);
	w2.set_weight(2, 700);
	w3 = add_weight(w1, w2);
	cout << w3.get_weight() << "grams\n";
	if (less_than(w1, w2))
		cout << "yes.\n";
	else
		cout << "no.\n";

}



void weight::set_weight(int n1, int n2) {
	kg = n1;
	g = n2;
}



int weight::get_weight(){
	return (kg * 1000 + g);
}

