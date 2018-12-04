#ifdef _STACK_H_

// default constructor
template <typename T>
Stack<T>::Stack() = default;

// copy constructor
template <typename T>
Stack<T>::Stack(const Stack& st){
    ac.operator=(st.ac);
}

// assignment operator
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& st){
    ac.operator=(st.ac);
    return *this;
}

///////////////
// accessors //
///////////////

// Return true if the stack contains no items
template <typename T>
bool Stack<T>::isEmpty() const{
    return (ac.size() == 0);
}

// Returns the number of items stored in the stack
template <typename T>
unsigned int Stack<T>::size() const{
    return ac.size();
}

// Return a reference to the top item of the stack
// Throws an out_of_range exception if the stack is empty
template <typename T>
T& Stack<T>::peek(){
    if(ac.size() == 0) throw std::out_of_range ("out of range!");
    else return ac.back();
}

//////////////
// mutators //
//////////////

// Pushes an item to the top of the stack
template <typename T>
void Stack<T>::push(const T item){
    ac.pushBack(item);
}

// Removes and returns (a copy of) the top item of the stack
// Throws an out_of_range exception if the stack is empty
template <typename T>
T Stack<T>::pop(){
    if(ac.empty()) throw std::out_of_range ("out of range!");
    T popped = ac.back();
    ac.popBack();
    return popped;
}

#endif