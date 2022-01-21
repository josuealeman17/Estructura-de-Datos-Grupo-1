#include "Expresion.h"
#include "Token.h"

Funcion::RPN Expresion::notacionPolacaInversa(string str)
{
	std::vector<std::string> queue;
	std::stack<std::string> stack;

	std::string obj = "";
	TokenTypes type = TokenTypes::ELSE;
	TokenTypes prevType = TokenTypes::ELSE; // negative sign detection

	bool acceptDecimal = true;
	bool acceptNegative = true;

	// token reading and detection
	for (int i = 0, eqLen = (int)strlen(eqn); i < eqLen; i++) {
		char t = eqn[i];

		// skip spaces and commas
		if (t == ' ' || t == ',') {
			//prevType = TokenTypes::ELSE;
			continue;
		}

		// classify token
		if (isNumber(t)) {
			type = TokenTypes::CONSTANT;
			if (t == '.') {
				acceptDecimal = false;
			}
			else if (t == '-') {
				acceptNegative = false;
			}

			int startI = i;
			if (i < eqLen - 1) {
				while (isNumber(eqn[i + 1], acceptDecimal, acceptNegative)) {
					i++;
					if (i >= eqLen - 1) {
						break;
					}
				}
			}
			obj = std::string(eqn).substr(startI, i - startI + 1);

			// subtraction sign detection
			if (obj == "-") {
				type = TokenTypes::OPERATOR;
			}
		}
		else {
			obj = findElement(i, eqn, functionNames);
			if (obj != "") {
				// found valid object
				type = contains<char>(operators, obj[0]) ? TokenTypes::OPERATOR : TokenTypes::FUNCTION;
			}
			else {
				obj = findElement(i, eqn, constantNames);
				if (obj != "") {
					// found valid object
					type = TokenTypes::CONSTANT;
				}
				else {
					obj = findElement(i, eqn, keys<double>(variables));
					if (obj != "") {
						type = TokenTypes::CONSTANT;
					}
					else if (contains<char>(leftBrackets, t)) {
						type = TokenTypes::LPAREN;
						obj = "(";
					}
					else if (contains<char>(rightBrackets, t)) {
						type = TokenTypes::RPAREN;
						obj = ")";
					}
					else {
						type = TokenTypes::ELSE;
					}
				}
			}
			i += obj.size() - 1;
		}

		// do something with the token
		const char* last_stack = (stack.size() > 0) ? stack.top().c_str() : "";
		switch (type) {
		case TokenTypes::CONSTANT:
			queue.push_back(obj);
			break;
		case TokenTypes::FUNCTION:
			stack.push(obj);
			break;
		case TokenTypes::OPERATOR:
			if (stack.size() != 0) {
				while (
					/*
						stk = stack top = last_stack
						obj = obj
									stk is a function
								AND
									stk is not an operator
							OR
								stk has a higher precedence than obj
							OR
									they have equal precedence
								AND
									stk is left associative
						AND
							stk is not a left bracket
					*/
					(
						(contains<std::string>(functionNames, last_stack) &&
							!contains<char>(operators, last_stack[0])) ||
						getPrecedence(last_stack) > getPrecedence(obj) ||
						((getPrecedence(last_stack) == getPrecedence(obj)) &&
							isLeftAssociative(last_stack))
						) &&
					!contains<char>(leftBrackets, last_stack[0])
					) {
					// pop from the stack to the queue
					queue.push_back(stack.top());
					stack.pop();
					if (stack.size() == 0) {
						break;
					}
					last_stack = stack.top().c_str();
				}
			}
			stack.push(obj);
			break;
		case TokenTypes::LPAREN:
			stack.push(obj);
			break;
		case TokenTypes::RPAREN:
			while (last_stack[0] != '(') {
				// pop from the stack to the queue
				queue.push_back(stack.top());
				stack.pop();
				last_stack = stack.top().c_str();
			}
			stack.pop();
			break;
		default:
			return queue;
		}

		// reset type
		prevType = type;
	}

	while (stack.size() > 0) {
		// pop from the stack to the queue
		queue.push_back(stack.top());
		stack.pop();
	}

	return queue;
}
