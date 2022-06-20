#include <iostream>
#include <string>
using namespace std;

#define SIZE 100

//
//create stack
class my_stack {
private:
	char s[SIZE];
	int top;
public:
	my_stack();
	void push(char a);
	char pop();
	bool stack_empty();
	char top_element();
	

};

my_stack::my_stack() {
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


bool my_stack::stack_empty() {
	if (top == 0)
		return true;
	else
		return false;


}

char my_stack::top_element() {
	return(s[(top-1)]);
}

bool is_p(char ch) {
	if ((ch == '(') || (ch == ')') || (ch == '{') || (ch == '}') || (ch == '[') || (ch == ']'))
		return true;
	else
		return false;

}




int main() {
	string input;
	int c1 = 0, c2 = 0;
	int is_error = 0;

	my_stack s1;

	cout << "Input expression with three types of parantesis: ";
	cin >> input;
	for (int i = 0; i < input.size(); i++) {

		if (is_p(input[i])) {
			c1++;


			if (input[i] == ')') {
				if (s1.stack_empty()) {
					cout << "Error: An extra parenthesis ')' is found.";
					break;
				}
				else {
					if (s1.top_element() == '(') {
										c2++;
										s1.pop();
									}
					else {
						if (s1.top_element() == '(')
							cout << "Error: mis-matched parenthesis, ')' is expected.";
						if (s1.top_element() == '{')
							cout << "Error: mis-matched parenthesis, '}' is expected.";
						if (s1.top_element() == '[')
							cout << "Error: mis-matched parenthesis, ']' is expected.";
						is_error = 1;
						break;
					}
				}
				
				
			}
				
			else if (input[i] == '}') {
				if (s1.stack_empty()) {
					cout << "Error: An extra parenthesis '}' is found.";
					break;
				}

				else {
					if (s1.top_element() == '{') {
									c2++;
									s1.pop();
								}
					else {
						if(s1.top_element() == '(')
							cout << "Error: mis-matched parenthesis, ')' is expected.";
						if (s1.top_element() == '{')
							cout << "Error: mis-matched parenthesis, '}' is expected.";
						if (s1.top_element() == '[')
							cout << "Error: mis-matched parenthesis, ']' is expected.";

						is_error = 1;
						break;
					}
				}
				
				
			}
			
			else if (input[i] == ']') {
				if (s1.stack_empty()) {
					cout << "Error: An extra parenthesis ']' is found.";
					break;
				}
				else {
					if (s1.top_element() == '[') {
										c2++;
										s1.pop();
									}

					else {
						if (s1.top_element() == '(')
							cout << "Error: mis-matched parenthesis, ')' is expected.";
						if (s1.top_element() == '{')
							cout << "Error: mis-matched parenthesis, '}' is expected.";
						if (s1.top_element() == '[')
							cout << "Error: mis-matched parenthesis, ']' is expected.";
						is_error = 1;
						break;
					}
					
				}
				
				

				

			}
			
			else
				s1.push(input[i]);

		}
		else 
			continue;

	}

	if (!(s1.stack_empty()) && (is_error == 0)) {
		cout << "3. 닫는 괄호가 부족함.";
	}


	if (s1.stack_empty() && (c1 == c2*2)) {
		cout << "It's a normal expression";
	}
	

	return 0;

}


