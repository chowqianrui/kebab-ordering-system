#include "interpreter.h"
#include <iostream>
#include <stdlib.h>

// executes an operator, returns a string of execution result
// most operators will return the empty string "", except for RQ, PRINT
// If an operator causes a container exception, throw the caught exception
std::string Interpreter::execOp(std::string optr){
    if(optr == "+"){
        int right = bin.pop();
        int left = bin.pop();
        tube.enqueue(toString(left+right));
        return "";
    }
    else if(optr == "-"){
        int right = bin.pop();
        int left = bin.pop();
        tube.enqueue(toString(left-right));
        return "";
    }
    else if(optr == "*"){
        int right = bin.pop();
        int left = bin.pop();
        tube.enqueue(toString(left*right));
        return "";
    }
    else if(optr == "/"){
        int right = bin.pop();
        int left = bin.pop();
        tube.enqueue(toString(left/right));
        return "";
    }
    else if(optr == "^"){
        int right = bin.pop();
        int left = bin.pop();
        tube.enqueue(toString(recpow(left,right)));
        return "";
    }
    else if (optr == "PRINT"){
        std::string result = "";
        Queue<std::string> temp;
        while (!tube.isEmpty()){
            temp.enqueue(tube.peek());
            
            if(tube.size() == 1){
                result += tube.dequeue(); 
            } 
            else{
                result += tube.dequeue() + " ";
            }
        }
        tube = temp;
        return result; 
    }
    else if(optr == "RQ"){
        std::string result = "";
        while(!bin.isEmpty()){
            int popped = bin.pop();
            tube.enqueue(toString(popped));
            sparebin.push(popped);
            if(bin.size() == 0) result += toString(popped);
            else result += toString(popped) + " ";
        }
        while(!sparebin.isEmpty()){
            bin.push(sparebin.pop());
        }
        return result;
    }
    return "";
}

// Exponentiation function calculates x^y
//   by repeated squaring (refer to HW2)
// You may implement this either iteratively or recursively
// PRE: y >= 0
int Interpreter::recpow(int x, int y){
    if (y <= 0) return 1;
    if (y == 1) return x;
    int temp = recpow(x, y/2);
    int result = temp*temp;
    if (y % 2 == 0) return result;
    return result*x;
}

// default constructor
Interpreter::Interpreter() = default;

// copy constructor
Interpreter::Interpreter(const Interpreter& itpt){
    tube = tube.operator=(itpt.tube);
    bin = bin.operator=(itpt.bin);
    sparebin = sparebin.operator=(itpt.sparebin);
}

// assignment operator
Interpreter& Interpreter::operator=(const Interpreter& itpt){
    tube = tube.operator=(itpt.tube);
    bin = bin.operator=(itpt.bin);
    sparebin = sparebin.operator=(itpt.sparebin);
    return *this;
}

// Loads a single instruction into the tube
// Requires parsing the instruction into operators and operands
// If tube already contains items, the instruction is loaded
//   without clearing the tube contents
// This should inject a "#" operator at the end
void Interpreter::load(std::string instruction){
    std::string toload = "";
    for(int i = 0; i < instruction.size(); i++){
        if(instruction[i] != ' '){
            toload += instruction[i];
        }
        else{
            tube.enqueue(toload);
            toload = "";
        }
    }

    if(toload != ""){
        tube.enqueue(toload);
    }
    tube.enqueue("#");
}

// Returns whether there are still items in the tube to be processed
bool Interpreter::hasMoreInstructions(){
    bool moreInstr = false;

    for (unsigned int i=0; i<tube.size(); i++){
        if(tube.peek() == "+" || tube.peek() == "-" || tube.peek() == "*" || 
           tube.peek() == "/" || tube.peek() == "^" || tube.peek() == "RQ" ||
           tube.peek() == "PRINT" ){
            
            moreInstr = true;

        }
        std::string deq = tube.dequeue();
        tube.enqueue(deq);
        
    }
    return moreInstr;
}

// Remove and execute next instruction
// i.e. until a #, empty tube, print, or other error encountered
// The output of any operator(s) will be returned
// If an attempt to execute an operator causes an exception,
//   throw the caught exception
std::string Interpreter::next(){
    std::string result = "";
    std::string element = tube.dequeue();
    while(element != "#"){
        if(element == "+" || element == "PRINT" || element == "RQ" ||
            element == "*" || element == "^" || element == "/" || element == "-"){
            result += execOp(element);
        }
        else{
            bin.push(toInt(element));
        }
        if(!tube.isEmpty()){
            element = tube.dequeue();
        }
    }
    return result;
}

// Execute remaining instructions
// The outputs of each instruction will be
// appended into a single string, separated by the
// newline character '\n'. The last instruction
// will NOT be followed by a newline.
std::string Interpreter::run(){
    std::string out = "";
    while(this->numOfInstructions()>1){
        out += this->next() + '\n';
    }
    out += this->next();
    return out;
}

// Clears the contents of all member containers (tube, bin, sparebin)
void Interpreter::clear(){
    std::string removeTube = "";
    int popBin = 0;
    int popSpareBin = 0;

    while(!tube.isEmpty()){
        removeTube = tube.dequeue();
    }
    while(!bin.isEmpty()){
        popBin = bin.pop();
    }
    while(!sparebin.isEmpty()){
        popSpareBin = sparebin.pop();
    }
}

// This function will only be used for testing.
// Do not remove this include header (it may cause your code to not compile while grading)
#include "interpretersecretfunctions.h"