// file:        arrayclass.cpp
// author:      Geoff T
// date:        2017-10-13
// description: implementation of a dynamic array class for CPSC 221 PA2

#ifdef _ARRAYCLASS_H_

// default constructor
// Creates an empty ArrayClass with DEFAULTCAPACITY
template <typename T>
ArrayClass<T>::ArrayClass()
{
  _size = 0;
  _capacity = DEFAULTCAPACITY;
  arr = new T[_capacity];
}

// parameterized constructor
// Creates an empty ArrayClass with capacity of n
template <typename T>
ArrayClass<T>::ArrayClass(unsigned int n)
{
  _size = 0;
  _capacity = n;
  arr = new T[_capacity];
}

// copy constructor
// Creates an ArrayClass as a deep copy of the parameter
template <typename T>
ArrayClass<T>::ArrayClass(const ArrayClass& ac)
{
  _size = ac._size;
  _capacity = ac._capacity;
  arr = new T[_capacity];
  for(unsigned int i = 0; i < _size; i++){
    arr[i] = ac.arr[i];
  }
}

// destructor
template <typename T>
ArrayClass<T>::~ArrayClass()
{
  T* ptr;
  ptr = arr;
  if(ptr) delete[] ptr;
  if(ptr) ptr = NULL;
}

// overloaded assignment operator
template <typename T>
ArrayClass<T>& ArrayClass<T>::operator=(const ArrayClass& ac)
{
  _size = ac.size();
  _capacity = ac.capacity();
  
  T* new_array;
  new_array = new T[ac.capacity()];

  for(unsigned int i=0; i<ac.size(); i++){
    new_array[i] = ac.arr[i];
  }

  T* ptr = arr;
  arr = new_array;
  delete[] ptr;
  return *this;
}

////////////////////////
// capacity functions //
////////////////////////

// Returns the number of elements stored in the array
template <typename T>
unsigned int ArrayClass<T>::size() const
{
  unsigned int size = _size;
  return size;
}

// Returns the maximum capacity of the array
template <typename T>
unsigned int ArrayClass<T>::capacity() const
{
  unsigned int capacity = _capacity;
  return capacity;
}

// Resizes the array
// If n is smaller than the size, then only the
//   first n elements are copied to the new array
template <typename T>
void ArrayClass<T>::resize(unsigned int n)
{
  if(n < _size){
    T* new_array;
    new_array = new T[n];
    for(unsigned int i=0; i<n; i++){
      new_array[i] = arr[i];
    }
    T* ptr;
    ptr = arr;
    arr = new_array;
    delete[] ptr;
    _size = n;
    return;
  }
  else if(n == _size) return;
  else{
    if(_capacity > n) return;
    else {
      _capacity = n;
      return;
    }
  }
  return;
}

// Check if array is empty
// return true if array is empty
template <typename T>
bool ArrayClass<T>::empty() const
{
  return (_size == 0);
}

// Resizes the array to fit exactly as many items
//   as are stored in the array
template <typename T>
void ArrayClass<T>::shrinkToFit()
{
  if(_capacity > _size){
    T* new_array;
    new_array = new T[_size];
    for(unsigned int i=0; i<_size; i++){
      new_array[i] = arr[i];
    }
    T* ptr;
    ptr = arr;
    arr = new_array;
    delete ptr;
    _capacity = _size;
  }
  return;
}

//////////////////////////////
// element access functions //
//////////////////////////////

// Returns a reference to the element at position i
//   in the array.
// Throws an out_of_range exception if i is outside
//   the bounds of valid elements
template <typename T>
T& ArrayClass<T>::operator[](unsigned int i)
{
  if(i >= _size) throw std::out_of_range ("out of range!");
  return arr[i];
}

// Returns a reference to the element at position i
//   in the array.
// Throws an out_of_range exception if i is outside
//   the bounds of valid elements
template <typename T>
T& ArrayClass<T>::at(unsigned int i)
{
 if(i >= _size) throw std::out_of_range ("out of range!");
 return arr[i];
}

// Returns a reference to the first element in the array
// Calling this on an empty array throws out_of_range exception
template <typename T>
T& ArrayClass<T>::front()
{
  if(_size == 0) throw std::out_of_range ("called front element but array is empty!");
  return arr[0];
}

// Returns a reference to the last element in the array
// Calling this on an empty array throws out_of_range exception
template <typename T>
T& ArrayClass<T>::back()
{
  if(_size == 0) throw std::out_of_range ("called last element but array is empty!");
  return arr[_size-1];
}

//////////////////////
// modify functions //
//////////////////////

// Add an element at the end
// If array is at capacity before adding, then
//   expand the array to double its capacity and
//   then add.
template <typename T>
void ArrayClass<T>::pushBack(const T& item)
{
  if(_size >= _capacity) expandArray();
  arr[_size] = item;
  _size++;
  return;
}

// Removes the last stored element in the array,
//   reducing container size by 1.
// No effect if called on an empty container
template <typename T>
void ArrayClass<T>::popBack()
{
  if(_size == 0) return;
  T* new_array;
  new_array = new T[_capacity];
  for(int i = 0; i < _size-1; i++){
    new_array[i] = arr[i];
  }
  T* ptr;
  ptr = arr;
  arr = new_array;
  delete[] ptr;
  _size--;
}

// Inserts an element before the element at specified position
// Expands the array if necessary
// Elements to the right of position (inclusive) must be shifted
// Throws out_of_range if position is > _size
// POST: item is at position, all elements formerly at position and beyond are shifted
template <typename T>
void ArrayClass<T>::insert(unsigned int position, const T& item)
{
  if(position > _size) throw std::out_of_range ("position is out of range");
  if(_size == _capacity) expandArray();
  T* new_array;
  new_array = new T[_capacity];
  _size++;
  bool added = false;

  for(int i = 0; i < _size; i++){
    if(i == position){
      new_array[i] = item;
      added = true;
    }
    else if(!added){
      new_array[i] = arr[i];
    }
    else{
      new_array[i] = arr[i-1];
    }
  }

  T* ptr;
  ptr = arr;
  arr = new_array;
  delete[] ptr;
}

// Removes an element from the array at specified position.
// Elements to the right of position will be shifted over to fill the gap
// Throws out_of_range if position is >= _size
template <typename T>
void ArrayClass<T>::erase(unsigned int position)
{
  if(position >= _size) throw std::out_of_range ("position is out of range");

  T* new_array;
  new_array = new T[_capacity];
  bool erased = false;

  for(unsigned int i = 0; i < _size; i++){
    if(i == position){
      erased = true;
      if(i == _size-1) break;
      new_array[i] = arr[i+1];
    }
    else if(erased){
      if(i==_size-1) break;
      new_array[i] = arr[i+1];
    }
    else{
      new_array[i] = arr[i];
    }
  }

  _size--;
  T* ptr;
  ptr = arr;
  arr = new_array;
  delete[] ptr;
}

// Reallocates stored items into a new array of the same size,
//   starting from specified position
// No effect if position is 0 or >= _size
// e.g. startFrom(3) on {1, 2, 3, 4, 5, 6, 7}
//   produces {4, 5, 6, 7, 1, 2, 3}
template <typename T>
void ArrayClass<T>::startFrom(unsigned int position)
{
  if(position >= _size || position == 0) return;

  T* new_array;
  new_array = new T[_capacity];

  unsigned int j = 0;
  for(unsigned int i = position; i < _size; i++){
    new_array[j] = arr[i];
    j++;
  }

  unsigned int k = 0;
  while(j<_size){
    new_array[j] = arr[k];
    k++;
    j++;
  }

  T* ptr = arr;
  arr = new_array;
  delete[] ptr;
}

//////////////////////
// helper functions //
//////////////////////

// helper method for deep copy
template <typename T>
void ArrayClass<T>::copyArray(const ArrayClass& ac)
{
  _size = ac._size;
  _capacity = ac._capacity;
  
  T* new_array;
  new_array = new T[ac._capacity];

  for(unsigned int i = 0; i < ac._size; i++){
    new_array[i] = ac.arr[i];
  }

  T* ptr;
  ptr = arr;
  arr = new_array;
  delete[] ptr;
}

// helper method for expanding array
template <typename T>
void ArrayClass<T>::expandArray()
{
  unsigned int initial_capacity = _capacity;
  unsigned int new_capacity = initial_capacity*EXPANSIONFACTOR;
  T* expandedArray;
  expandedArray = new T[new_capacity];
  
  for(unsigned int i=0; i<_size; i++){  //copy elements from old blk to new blk
    expandedArray[i] = arr[i];
  }
  
  T* ptr = arr; //create a ptr that points to old arr
  arr = expandedArray; //set arr to point to new blk
  delete[] ptr; //delete old blk
  _capacity = new_capacity;
}

#endif