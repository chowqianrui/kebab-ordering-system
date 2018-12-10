  #include <iostream>
  #include <cstdlib>
  #include "kebab.h"
  
  //default constructor
  Kebab::Kebab() = default;

  // Adds item to the pointy end of the skewer
  //   and returns true if skewer has space to add
  //   and item is a valid ingredient
  // Returns false if skewer is full or ingredient is invalid
  bool Kebab::addIngredient(char item){
    if(isValidIngredient(item) && skewer.size()<maxlength){
      skewer.push_back(item);
      return true;
    }
    return false;
  }

  // Adds the ingredients specified by s using addIngredient
  //   up to the capacity of the skewer
  void Kebab::buildKebab(std::string s){
    bool add;
    for(char& c : s) {
      add = addIngredient(c);
    }
  }

  // returns the number of meat items on this kebab
  unsigned int Kebab::numMeats() const{
    unsigned int numMeatInSkewer = 0;
    for(unsigned int i = 0; i < skewer.size() ; i++) {
        if(skewer.at(i)=='b' | skewer.at(i)=='B'){
          numMeatInSkewer++;
        }
    }
    return numMeatInSkewer;
  }

  // Returns true iff this kebab contains at least the same collection
  // of ingredients as k, in any order
  // Note that this kebab may contain more total ingredients than k,
  // but will return true as long as this kebab's ingredients is
  // a super-multiset of k's ingredients
  bool Kebab::hasSameIngredients(Kebab& k) const{
    int b = 0;
    int t = 0;
    int m = 0;
    int p = 0;
    int s = 0;

    int b1 = 0;
    int t1 = 0;
    int m1 = 0;
    int p1 = 0;
    int s1 = 0;

    for(int i=0; i<(int)skewer.size(); i++){
      if(skewer.at(i)=='b' | skewer.at(i)=='B') b++ ;
      if(skewer.at(i)=='t' | skewer.at(i)=='T') t++ ;
      if(skewer.at(i)=='m' | skewer.at(i)=='M') m++ ;
      if(skewer.at(i)=='p' | skewer.at(i)=='P') p++ ;
      if(skewer.at(i)=='s' | skewer.at(i)=='S') s++ ;
    }

     for(int i=0; i<(int)k.skewer.size(); i++){
      if(k.skewer.at(i)=='b' | k.skewer.at(i)=='B') b1++ ;
      if(k.skewer.at(i)=='t' | k.skewer.at(i)=='T') t1++ ;
      if(k.skewer.at(i)=='m' | k.skewer.at(i)=='M') m1++ ;
      if(k.skewer.at(i)=='p' | k.skewer.at(i)=='P') p1++ ;
      if(k.skewer.at(i)=='s' | k.skewer.at(i)=='S') s1++ ;
    }

    if(b>=b1 && t>=t1 && m>=m1 && p>=p1 && s>=s1){
      return true;
    }
    else {
      return false;
    }
  }

  // Returns a string representing the ingredients on this kebab
  //   in the order in which they are skewered
  std::string Kebab::listIngredients() const {
    std::string str(skewer.begin(), skewer.end());
  return str;
}