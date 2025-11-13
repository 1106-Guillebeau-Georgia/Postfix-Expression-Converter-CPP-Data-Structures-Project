//Author :: Georgia Guillebeau
//Date: 06.12.2025
//Purpose: Main driver for project 3
#include "linkedStack.h"
#include "arrayStack.h"

#include <iostream>
#include <string>
using namespace std;

//Function Prototypes
bool isNotDigit(char op);
int convertToInt(char num);
void convertToPost(string& in, string& post, LinkedStack<char>& operators);
int declarePrecedence(char oper);
void evaluateExpression(string& post, float& answer, LinkedStack<float>& numbers);

int main(){
    LinkedStack<float> operandsStack; //For calculation
    LinkedStack<char> operatorsStack; //For parsing
    string infix = "", postfix = "";
    float result;
    bool keepGoing = true;
    int userInput;
    do{
        cout << "1. Convert Infix Expression" << endl << "0. Exit" << endl;
        cin >> userInput;
        cin.ignore();
        while(userInput < 0 || userInput > 1){ //Ensure valid input
            cout << "Invalid input" << endl;
            cout << "1. Convert Infix Expression" << endl << "0. Exit" << endl;
            cin >> userInput;
            cin.ignore();
        }
        if(userInput == 0){ //Check for exit condition first
            return 0;
        }
        //Contiue with program is not exit
        cout << "Enter an infix expression of integers & (+, -, *, /) Operators: ";
        getline(cin, infix);
        convertToPost(infix, postfix, operatorsStack);
        evaluateExpression(postfix, result, operandsStack);
        cout << postfix << endl << "Result: " <<  result << endl;
        postfix = "";
    }while(userInput == 1);
    return 0;
}
 
//Checks if the current character is an operator, this will be the only 'check' function because we will assume that anything else is a digit
bool isNotDigit(char op){
    if(op == '+' || op == '-' || op == '/' || op == '*' || op == '(' || op == ')'){
        return true;
    }
    return false;
}


//Sorts through the user's entered string
//Only pass the postfix string by reference since that's the only string we want to modify
void convertToPost(string& in, string& post, LinkedStack<char>& operators){
    int i = 0;
    while(i < in.length()){
        char itemToPush = in[i];
        if(itemToPush == ' '){
            //Just skip
        }
        else if(isNotDigit(itemToPush)){ //For non-digits
            if(itemToPush == ')'){ //When the current character is a closed parenthesis
                while(operators.isEmpty() == false && operators.peek() != '('){
                    post += operators.peek();
                    operators.pop();
                }
                if(operators.isEmpty() == false && operators.peek() == '('){
                    operators.pop(); //Pop the open parenthesis
                }
            }
            else if(itemToPush == '+' || itemToPush == '-' || itemToPush == '/' || itemToPush == '*'){
                //No space needed for single-digit numbers
                while(operators.isEmpty() == false && (declarePrecedence(itemToPush) <= declarePrecedence(operators.peek()))){ 
                    post += operators.peek();
                    operators.pop();
                }
                operators.push(itemToPush);
            }
            else if(itemToPush == '('){
                operators.push(itemToPush); //Push to the operator stack, if it is after an open parenthesis
            }
        }
        else{
            post += itemToPush; //Adds digits to post expression
        }
        i++;
    }
    while(operators.isEmpty() == false){ //Empty the rest of the operators stack
        post += operators.peek();
        operators.pop();
    }
}

//Only interacts with the postfix expression, and does not modify
void evaluateExpression(string& post, float& answer, LinkedStack<float>& numbers){
    int i = 0;
    while(i < post.length()){
        char itemToPush = post[i];
        if(itemToPush == ' '){
            //Skip
            i++;
            continue;
        }

        if(isNotDigit(itemToPush) == false){ //It's a number (single-digit)
            float num = convertToInt(itemToPush);
            numbers.push(num);
            i++;
        }
        else{ //It's an operator
            float first, second;
            if(itemToPush == '+'){
                first = numbers.peek();
                numbers.pop();
                second = numbers.peek();
                numbers.pop();
                answer = second + first;
            }
            else if(itemToPush == '-'){
                first = numbers.peek();
                numbers.pop();
                second = numbers.peek();
                numbers.pop();
                answer = second - first;
            }
            else if(itemToPush == '*'){
                first = numbers.peek();
                numbers.pop();
                second = numbers.peek();
                numbers.pop();
                answer = second * first;
            }
            else if(itemToPush == '/'){
                first = numbers.peek();
                numbers.pop();
                second = numbers.peek();
                numbers.pop();
                if(first == 0){
                    throw "Cannot divide by 0!";
                    answer = answer;
                    return;
                }
                else{
                    answer = second / first;
                }
            }
            numbers.push(answer); //Add the answer to the top of the stack
            i++;
        }
    }
    if(numbers.isEmpty() == false){
        answer = numbers.peek(); //Set the final answer
        numbers.pop(); //Pop final answer
    }
}

int convertToInt(char num){
    switch(num){
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':  
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default:
            throw "Not convertable";
    }
}

int declarePrecedence(char oper){
    switch(oper){
        case '+':
            return 1;
        case '-': 
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        default:
            return 0;
    }
}