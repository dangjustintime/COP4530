#include "stack.h"
#include <string>
#include <cctype>
#include <vector>

using namespace COP4530;

bool isOperand(std::string str) {
	for(auto i = str.begin(); i != str.end(); i++) {
		if(!std::isalnum(*i)) return false;
	}
	return true;
}

bool isOperator(std::string str) {
	if (str == "+" || str == "-" || str == "*" || str == "/") {
		return true;
	}
	return false;
}

std::string infix2postfix(const std::vector<std::string> &infix) {
	Stack<std::string> tokens;
	std::string post;
	for(int i = 0; i < infix.size(); i++) {
		if(isOperand(infix[i])) {
			post+=infix[i];
		} else if(isOperator(infix[i])) {
			if(tokens.empty()) {
				tokens.push(infix[i]);
			} else if(tokens.top() == "+" || tokens.top() == "-") {
				if(infix[i] == "+" || infix[i] == "-") {
					post+=tokens.top();
					tokens.pop();
					tokens.push(infix[i]);
				} else if(infix[i] == "*" || infix[i] == "/") {
					post+=infix[i];
				}
			} else if(tokens.top() == "*" || tokens.top() == "/") {
				if(infix[i] == "+" || infix[i] == "-") {
					post+=tokens.top();
					tokens.pop();
					tokens.push(infix[i]);
				} 
			} else if(tokens.top() == "(") {
				tokens.push(infix[i]);	
			}
		} else if (infix[i] == ")") {
			while(tokens.top() != "(") {
				post+=tokens.top();
				tokens.pop();
			}
			tokens.pop();
		} else if (infix[i] == "(") {	
			tokens.push(infix[i]);
		}
	}
	while(!tokens.empty()) {
		post+=tokens.top() + " ";
		tokens.pop();
	}
	/*
	if(post.back() == '(' || std::isalnum(post.back())) {
		post = "INVALID INFIX";
	}
	*/
	return post;
}
/*
double evaluatePostfix(std::string & postfix) {
	double operand1;
	double operand2;
	double operand3;
	Stack<double> operands;
	std::string op;
	for(int i = 0; i < postfix.size(); i++) {
		op+=postfix[i];
		if(std::isalpha(postfix[i]) || postfix[i] == '_' || postfix == "INVALID INFIX") {
			std::cout << "CANNOT SOLVE VARIABLES" << std::endl;
			return -999;}
		if(isspace(postfix[i]) || i == postfix.size() - 1) {
			if(isOperand(op)) {
				operand1 = std::stod(op);
				operands.push(operand1);
				op.clear();
			
			} else if(isOperator(op)) {
				operand1 = operands.top();
				operands.pop();
				operand2 = operands.top();
				operands.pop();
				if(op == "+") {
					operand3 = operand1 + operand2;
				} else if(op == "-") {
					operand3 = operand1 - operand2;
				} else if(op == "*") {
					operand3 = operand1 * operand2;
				} else if(op == "/") {
					operand3 = operand1 / operand2;
				}
				operands.push(operand3);
				op.clear();
			}
		}
	}
	return operands.top();
}
*/

int main() {
	std::string postfix;
	std::vector<std::string> tokens;
	std::string input;
	std::string token;
	while(std::getline(std::cin, input)) {
		for(int i = 0; i < input.size(); i++) {
			token+=input[i];
			if(isspace(input[i]) || i == input.size() - 1) {
				tokens.push_back(token);
				token.clear();
			}
		}	
		postfix = infix2postfix(tokens);
		//std::cout << evaluatePostfix(postfix) << std::endl;
		std::cout << postfix << std::endl;
		tokens.clear();
	}
	return 0;
}
