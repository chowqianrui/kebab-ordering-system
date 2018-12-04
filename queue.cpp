#ifdef _QUEUE_H_


// default constructor
template <typename T>
Queue<T>::Queue(){
    front = 0;
    _size = 0;
}

// copy constructor
template <typename T>
Queue<T>::Queue(const Queue& qq){
    front = qq.front;
    _size = qq._size;
    ac.operator=(qq.ac);
}

// assignment operator
template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& qq){
    front = qq.front;
    _size = qq._size;
    ac.operator=(qq.ac);
    return *this;
}

///////////////
// accessors //
///////////////

// Return true if the queue contains no items
template <typename T>
bool Queue<T>::isEmpty() const{
    unsigned int size = _size;
    return (size == 0);
}

// Returns the number of items stored in the queue
template <typename T>
unsigned int Queue<T>::size() const{
    unsigned int size = _size;
    return size;
}

// Return a reference to the front item of the queue
// Throws an out_of_range exception if the queue is empty
template <typename T>
T& Queue<T>::peek(){
    if(_size == 0) throw std::out_of_range ("out of range!");
    return ac.front();
}

//////////////
// mutators //
//////////////

// Inserts an item to the back of the queue
template <typename T>
void Queue<T>::enqueue(const T item){
    ac.pushBack(item);
    _size++;
}

// Removes and returns (a copy of) the front item of the queue
// Throws an out_of_range exception if the queue is empty
template <typename T>
T Queue<T>::dequeue(){
    if (_size == 0) throw std::out_of_range ("rui out of range!");
    T elementAtFront = ac.at(front);
    ac.erase(front);
    _size--;
    return elementAtFront;
}

#endif