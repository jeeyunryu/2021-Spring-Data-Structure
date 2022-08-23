#include <iostream>
using namespace std;

class mystack {
//private:
	int my_stack[5];
	int top;
public:
	void init();
	void push(int n);
	int pop();
	bool stack_empty();
};

void mystack::init() {
	int top = 0;
}

void mystack::push(int n) {
	my_stack[top] = n;
	top++;
}

int mystack::pop() {
		top--;
		return(my_stack[top]);
}

bool mystack::stack_empty() {
	if (top == 0)
		return true;
	else
		return false;

}
int main(void) {
	mystack s1;
	int list[5] = { 32, 123, 27, 131, 242 }, i;
	s1.init();
	for (i = 0; i < 5; i++) {
		if (list[i] > 100)
			s1.push(list[i]);
	}
	while (!s1.stack_empty()) {
		cout << s1.pop() << endl;
	}


	return 0;
}
