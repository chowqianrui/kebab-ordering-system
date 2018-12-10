#include "grill.h"
  
  Grill::Grill()=default;

  // Switches the kebabs at pos1 and pos2
  // Returns true if positions are valid and swap can be performed
  // Returns false if positions are invalid
  bool Grill::swap(unsigned int pos1, unsigned int pos2){
    if(pos1 == pos2 || pos1 == 0 || pos2 == 0 || pos1>rack.size() || pos2>rack.size()){
      return false;
    }

    int pos_1 = pos1 - 1;
    int pos_2 = pos2 - 1;

    if(pos_1 > pos_2){
      int temp = pos_1;
      pos_1 = pos_2;
      pos_2 = temp;
    }

    Kebab* remove1 = rack.removeAt(pos_1);
    Kebab* remove2 = rack.removeAt(pos_2-1);
    
    if(rack.insertAt(remove2,pos_1) && rack.insertAt(remove1,pos_2)){
      return true;
    }
    
    else
      return false;
  }

  // remove and return the kebab at a 1-indexed
  // position on the grill
  // return NULL if pos invalid
  Kebab* Grill::request(unsigned int pos){
    return rack.removeAt(pos-1);
  }

  // remove and return the leftmost kebab matching
  // at least the ingredients of r, in any order
  // return NULL if no match found
  Kebab* Grill::request(Kebab& r){
    for(unsigned int i=0; i<rack.size(); i++){
      if(rack.elementAt(i)->hasSameIngredients(r)){
        return rack.removeAt(i);
      }
    }
    return NULL;
  }

  void Grill::addKebab(Kebab& n){
    rack.insertBack(&n);
  }

  // arrange in decreasing order of # of meat items
  void Grill::sortByMeat(){
    for(unsigned int i=0; i<=rack.size(); i++){
      int bef_index = (int) i-2;

      while(bef_index>=0){
        if(rack.elementAt(bef_index)->numMeats()< rack.elementAt(bef_index+1)->numMeats()){
          swap(bef_index+1, bef_index+2);
        }
        bef_index--;
      }

    }
    return;
  }

  // returns a vector containing the string representation of all
  //   kebabs on the grill
  std::vector<std::string> Grill::showKebabs() const{
    std::vector<std::string> kebabOnGrill;
    for(unsigned int i=0; i<rack.size(); i++){
      kebabOnGrill.push_back(rack.elementAt(i)->listIngredients());
    }
    return kebabOnGrill;
  }