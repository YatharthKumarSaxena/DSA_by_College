// Note :- ^ is indicated as an exponential function as specified in stack pdf
// Don't do amendment in code otherwise program will malfunction
#include <iostream>
#include <stack>
using namespace std;
// Level of Precedence in operator function
// '^'  >  '/' == '*'  >  '+' == '-'
int precedence(char op){ // op is an operator
    if(op == '^'){
        return 2;
    }
    else if(op == '*' || op == '/'){
        return 1;
    }
    else if(op == '-' || op == '+'){
        return 0;
    }
    else{
        cout<<"Invalid operator entered !!";
    }
    return -1;
}
string infixToPostfix(string exp){ // Expression taken as input as string
    string ans = ""; // Creatiing an empty string that contain postfix expression
    stack<char>st; // Stack which store operators as per below algorithm
    st.push('('); // Used to empty stack completely
    exp.push_back(')'); // Used as delimeter
    int n = exp.length();
    for(int i=0;i<n;i++){
        char op = exp[i];
        if(op == '(')st.push(op); // If op is left parenthesis simply push in stack
        // If op are simply values like 1,2,3 or variables like A,B,C etc simply pushback in ans string
        else if(op != '+' && op != '-' && op != '/' && op != '*' && op != '^' && op != ')')ans.push_back(op);
        else if(op == '+' || op == '-' || op == '/' || op == '*' || op == '^'){ // if op are operators  
            if(st.top() == '(')st.push(op); // top of stack is ( then simply push op in stack
            // Checking precedence of two operators
            else if(precedence(op)>precedence(st.top())){ 
                st.push(op);
            }
            else{ // if precedence of both operators are same like (* and /) or (+ and -)
                while(st.top() != '('){
                    char help = st.top();
                    st.pop();
                    ans.push_back(help);
                }
                st.push(op);
            }
        }
        else{ // if op == ) i.e right parenthesis
            while(st.top() != '('){
                char help = st.top();
                st.pop(); // Removing top element of stack in ans string
                ans.push_back(help); // Pushing top element of stack in ans string
            }
            st.pop(); // Remove ( i.e left parenthesis
        }
    }
    return ans;
}