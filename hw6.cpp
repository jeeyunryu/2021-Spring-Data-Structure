#include <iostream>
#include <string>
using namespace std;
//madam
//abba

class my_stack {
private:
	int top;
	char s[100];
public:
	my_stack();
//constructor
	void push(char a);
	char pop();
	char top_element();


};

//constructor
my_stack::my_stack() {
	//initialize
	top = 0;
}

void my_stack::push(char a) {
	s[top] = a;
	top++;
}
char my_stack::pop() {
	top--;
	return(s[top]);
}
char my_stack::top_element() {
	return(s[top-1]);
}


int main(void) {
	my_stack s1;
	string input;
	int is_true = 1;
	int i = 0;

	cout << "Type a word to find: ";
	cin >> input;
	for (; i < (input.size() / 2); i++) {
		s1.push(input[i]);

	}
	if (input.size() % 2 != 0) {
		i++;
	
	}

	for (; i < input.size(); i++) {
		if (s1.top_element() == input[i]) {
			s1.pop();
			continue;
		}

		else {
			is_true = 0;
			cout << "No, it's not a palindrome.\n";
			break; //get out of previous loop
		}
	}

	if (is_true == 1) {
		cout << "Yes, it's a palindrome.\n";
	}

	return 0;
}