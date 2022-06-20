#include <iostream>
#include <string>
#define SIZE 100
#define EOS '$'

using namespace std;


class op_stack{
	char s[SIZE];
	int top;
public:
	op_stack();
	void push(char x);
	char pop();
	bool empty();
	char top_element();


};

op_stack::op_stack() {
	top = 0;

}
int get_precedence(char op)
{
	if ((op == '$') || (op == '('))
		return (0);
	if ((op == '+') || (op == '-'))
		return (1);
	if ((op == '*') || (op == '/') || (op == '%'))
		return (2);
}
bool is_operand(char ch)
{
	if ((ch == '(') || (ch == ')') || (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/') || (ch == '%') || (ch == '$'))
		return false;
	else
		return true;

}
int main() {

	string input, output;
	op_stack stack1;

	cout << "Input an infix expression to convert: ";
	cin >> input;
	input += EOS;
	stack1.push(EOS);

	for (int i = 0; i < input.size(); i++)
	{
		if (is_operand(input[i]))
			output += input[i];
		else//operator
		{
			if (input[i] == ')')
			{
				if (stack1.top_element() != '(') {
					output += stack1.pop();
					i--;
					continue;
				}

				if (stack1.top_element() == '(')
					stack1.pop();
					

			}

			else if (input[i] == '(')
			{
				stack1.push(input[i]);
			}

			else// +, -, *, /, %
			{
				if (get_precedence(input[i]) >= get_precedence(stack1.top_element()))
					stack1.push(input[i]);
				else if(get_precedence(input[i]) < get_precedence(stack1.top_element()))
				{
					
					output += stack1.pop();

				}
				else
				{
					continue;
				}
					

			}
		}


	}


	cout << output;
	return 0;


}

void op_stack::push(char x)
{
	s[top] = x;
	top++;
}
char op_stack::pop()
{
	top--;
	return(s[top]);
}

bool op_stack::empty() {
	if (top == 0)
		return true;

}

char op_stack::top_element() {
	return(s[top-1]);
}



