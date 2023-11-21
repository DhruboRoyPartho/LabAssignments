#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int prec(char ch)
{
    if(ch == '^') return 3;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    else return -1;
}

string infix2postfix(string str)
{
    stack<char> st;
    string result;
    for(int i=0;i<str.length();i++){
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') || (str[i]>='0' && str[i]<='9')){
            result += str[i];
        }

        else if(str[i] == '(') st.push('(');

        else if(str[i] == ')'){
            while(st.top() != '('){
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && prec(str[i]) <= prec(st.top())){
                result += st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }
    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    return result;
}

bool isOperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}
 
// Function to get the priority of operators
int getPriority(char C)
{
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}
 
// Function to convert the infix expression to postfix
string infixToPostfix(string infix)
{
    infix = '(' + infix + ')';
    int l = infix.size();
    stack<char> char_stack;
    string output;
 
    for (int i = 0; i < l; i++) {
 
        // If the scanned character is an
        // operand, add it to output.
        if (isalpha(infix[i]) || isdigit(infix[i]))
            output += infix[i];
 
        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (infix[i] == '(')
            char_stack.push('(');
 
        // If the scanned character is an
        // ‘)’, pop and output from the stack
        // until an ‘(‘ is encountered.
        else if (infix[i] == ')') {
            while (char_stack.top() != '(') {
                output += char_stack.top();
                char_stack.pop();
            }
 
            // Remove '(' from the stack
            char_stack.pop();
        }
 
        // Operator found
        else {
            if (isOperator(char_stack.top())) {
                if (infix[i] == '^') {
                    while (
                        getPriority(infix[i])
                        <= getPriority(char_stack.top())) {
                        output += char_stack.top();
                        char_stack.pop();
                    }
                }
                else {
                    while (
                        getPriority(infix[i])
                        < getPriority(char_stack.top())) {
                        output += char_stack.top();
                        char_stack.pop();
                    }
                }
 
                // Push current Operator on stack
                char_stack.push(infix[i]);
            }
        }
    }
    while (!char_stack.empty()) {
        output += char_stack.top();
        char_stack.pop();
    }
    return output;
}
 
// Function to convert infix to prefix notation
string infix2prefix(string infix)
{
    // Reverse String and replace ( with ) and vice versa
    // Get Postfix
    // Reverse Postfix
    int l = infix.size();
 
    // Reverse infix
    reverse(infix.begin(), infix.end());
 
    // Replace ( with ) and vice versa
    for (int i = 0; i < l; i++) {
 
        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
 
    string prefix = infixToPostfix(infix);
 
    // Reverse postfix
    reverse(prefix.begin(), prefix.end());
 
    return prefix;
}

int main()
{
    cout<<infix2postfix("(4*2)+3")<<endl;
    cout<<infix2prefix("(4*2)+3")<<endl;
    return 0;
}