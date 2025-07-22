#include <iostream>
#include <string>
using namespace std;

// Global variables
string input;   // user se li gayi input expression
int pos = 0;    // current parsing position

// Forward declaration
double expr();

// Function: whitespace skip karta hai
void skipSpaces() {
    while (pos < input.size() && input[pos] == ' ') pos++;
}

// Function: ek complete number parse karta hai (including decimals)
double number() {
    skipSpaces();
    double result = 0;

    // Parse integer part
    while (pos < input.size() && isdigit(input[pos])) {
        result = result * 10 + (input[pos] - '0');
        pos++;
    }

    // Parse fractional part agar decimal milta hai
    if (pos < input.size() && input[pos] == '.') {
        pos++;
        double frac = 0.1;
        while (pos < input.size() && isdigit(input[pos])) {
            result += (input[pos] - '0') * frac;
            frac /= 10;
            pos++;
        }
    }

    return result;
}

// Function: factor parse karta hai (ya toh ek number ya ( expr ))
double factor() {
    skipSpaces();
    if (pos < input.size() && input[pos] == '(') {
        pos++; // '(' consume karo
        double result = expr(); // parentheses ke andar ka expression evaluate karo
        skipSpaces();
        if (pos < input.size() && input[pos] == ')') {
            pos++; // ')' consume karo
        } else {
            cout << "Error: Expected closing parenthesis\n";
        }
        return result;
    } else {
        return number(); // simple number
    }
}

// Function: term parse karta hai (multiplication/division handle karta hai)
double term() {
    double result = factor();

    while (true) {
        skipSpaces();
        if (pos < input.size() && input[pos] == '*') {
            pos++;
            result *= factor(); // multiply next factor
        } else if (pos < input.size() && input[pos] == '/') {
            pos++;
            double divisor = factor();
            if (divisor != 0) {
                result /= divisor; // divide next factor
            } else {
                cout << "Error: Division by zero\n";
                result = 0;
            }
        } else {
            break; // no more * or /
        }
    }

    return result;
}

// Function: expression parse karta hai (addition/subtraction handle karta hai)
double expr() {
    double result = term();

    while (true) {
        skipSpaces();
        if (pos < input.size() && input[pos] == '+') {
            pos++;
            result += term(); // add next term
        } else if (pos < input.size() && input[pos] == '-') {
            pos++;
            result -= term(); // subtract next term
        } else {
            break; // no more + or -
        }
    }

    return result;
}

// Main function
int main() {
    cout << "Simple Arithmetic Expression Evaluator\n";
    cout << "Enter expression (or type 'exit' to quit):\n";

    while (true) {
        cout << "> ";
        getline(cin, input);

        if (input == "exit") break; // program exit condition

        pos = 0; // reset parsing position for new expression
        double result = expr(); // parse and evaluate expression
        cout << "Result: " << result << endl;
    }

    return 0;
}
