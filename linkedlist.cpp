  #include "linkedlist.h"
  
  // default constructor
  LinkedList::LinkedList() {
    length = 0;
    front = NULL;
    back = NULL;
  }

  // copy constructor, performs deep copy of list elements
  LinkedList::LinkedList(const LinkedList& ll){
    copyList(ll); 
  }

  // destructor
  LinkedList::~LinkedList(){
    deleteList();
  }

  // helper function for deep copy
  // Used by copy constructor and operator=
  // should create new Kebab objects
  void LinkedList::copyList(const LinkedList& ll){
    length = ll.length;
    
    if(ll.length == 0) return;
    
    if (ll.length == 1){
      Node* newNode = new Node(ll.front->data);
      front = newNode;
      back = newNode;
    }
    
    else{
      Node* newNode = new Node(ll.front->data);
      front = newNode;
      Node* curr = ll.front->next;

      while(curr){
        newNode->next = new Node(curr->data);
        curr = curr->next;
        newNode = newNode->next;
      }

      back = newNode;
    }
    return;
  }



  // helper function for deep delete
  // Used by destructor and copy/assignment
  // Deallocates Nodes and the Kebabs inside
  void LinkedList::deleteList(){
    Node* curNode = front;
    while(curNode){
      Node* old = curNode;
      curNode = curNode->next;
      old->data = NULL; //delete node
      delete old;
      old = NULL;
    }
    curNode = NULL;
    front = NULL;
  }

  // MUTATORS

  // Inserts an item at the front of the list
  // POST:  List contains item at position 0
  // PARAM: item = item to be inserted
  void LinkedList::insertFront(Kebab* item){
    Node* newHead = new Node(item);
    if(length == 0 | front == NULL){
      front = newHead;
      back = newHead;
    }
    else{
      newHead->next = front;
      front = newHead;
    }
    length++;
    newHead = NULL;
  }

  // Inserts an item at the back of the list
  // POST:  List contains item at back
  // PARAM: item = item to be inserted
  void LinkedList::insertBack(Kebab* item){
    Node* newNode = new Node(item);
    
    if(length == 0){
      front = newNode;
      back = newNode;
    }
    else{
      back->next = newNode;
      back = newNode;
    }
    length++;
    newNode = NULL;
  }

  // Inserts an item in position p (0-indexed)
  // Returns false for invalid index
  // PRE:   0 <= p <= size
  // POST:  List contains item at position p
  // PARAM: item = item to be inserted, p = position where item will be inserted
  bool LinkedList::insertAt(Kebab* item, unsigned int p){
    if(p>length) return false;

    if(p==0){
      insertFront(item);
    }
    else if(p==length){
      insertBack(item);
    }
    else{
      unsigned int count = 0;
      Node* cur = front;
      Node* temp = NULL;
      Node* befTemp = NULL;

      while(cur){
        if(count == p){
          temp = cur;
          break;
        }
        if(count+1 == p){
          befTemp = cur;
        }
        count++;
        cur = cur->next;
      }

      Node* newNode = new Node(item);
      newNode->next = temp;
      befTemp->next = newNode;
      length++;

      cur = NULL;
      temp = NULL;
      befTemp = NULL;
      newNode = NULL;
    }
     return true;
  }

  // Removes and returns an item from position p (0-indexed)
  // Return NULL if index is invalid
  // PRE:   0 <= p < size
  // POST:  Item is removed from list.
  //        Node is deallocated but Kebab should in memory
  //        Thus set data to NULL before deleting
  // PARAM: p = position from where item will be removed
  Kebab* LinkedList::removeAt(unsigned int p){
    if(length == 0 | p >= length) return NULL;

    Node* pPre = NULL;
    Node* pCur = front;
    unsigned int curIndex = 0;
    Kebab* kebab = NULL;
    
    while(pCur){  //loop to get pointer pointing towards desired index

      if(curIndex == p){
        break;
      }

      curIndex++;
      pPre = pCur;
      pCur = pCur->next;
    }

    if(pCur){
      
      if(pPre){
        pPre->next = pCur->next;
        if(pPre->next == NULL){
          back = pPre;
        }
        kebab = pCur->data;
        length--;
        if(length == 1){  //if deleting last node in a length = 2 list, set back as front
          back = pPre;
        }
        pCur->data = NULL;
        pCur->next = NULL;
        delete pCur;
        pCur = NULL;
        return kebab;
      }
      else{ //handles case of deleting first node
        front = pCur->next;
        back = pCur->next;
        length--;
        kebab = pCur->data;
        pCur->data = NULL;
        delete pCur;
        pCur = NULL;
        return kebab;
      }

    }
    else{
      return NULL;
    }
    return NULL;
  }

  // ACCESSORS

  // Returns size of list
  unsigned int LinkedList::size() const{
  	return length;
  }

  // Returns whether the list is empty
  bool LinkedList::isEmpty() const{
  	return (length==0);
  }

  // Returns existence of a Kebab that has at least
  //   all the same ingredients as k, in any order
  //   i.e. the list has a Kebab whose ingredients
  //   are a super-multiset of k's ingredients
  bool LinkedList::contains(Kebab& k) const{
    if(length == 0) return false;
    
    Node* cur = front;
    while(cur->next != NULL){
      if(cur->data->hasSameIngredients(k)) return true;
      else{
        cur = cur->next;
      }
    }
    if(cur->data->hasSameIngredients(k)) return true;
    return false;
  }

  // Returns item at index (0-indexed)
  // Returns NULL if index is invalid
  Kebab* LinkedList::elementAt(unsigned int p) const{
  	if (p>=length) return NULL;
    Node *cur = front;
    unsigned int i=0;
    
    while(cur->next != NULL){
      if (i == p) {
        return cur->data;
      }
      else {
        i++;
        cur = cur->next;
      }
    }
    if (i == p) return cur->data;
    else return NULL;
  }

  // OVERLOADED OPERATORS

  // overloaded assignment operator
  // must work in the following cases:
  // list2 = list1 -> general case
  // list2 = list2 -> should do nothing
  LinkedList& LinkedList::operator=(const LinkedList& ll){
    if(this != &ll) copyList(ll);
    return *this;
  }


