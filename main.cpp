// File:        main.cpp
// Author:      Geoff T
// Date:        2017-09-18
// Description: Test driver for CPSC 221 PA1
//              Only basic cases are included. You are responsible
//              for adding your own code to thoroughly test all functions of the
//              classes implemented in this assignment.

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <assert.h>
#include "kebab.h"
#include "linkedlist.h"
#include "grill.h"

using namespace std;

// forward function declarations
void runScriptedTests();
void test2 ();
void test3 ();
void test4 ();
void test5 ();
void test6 ();
void runInteractiveTest();
void displayMenu();
void handleQueryShowGrill(Grill& grill);
void handleQueryBuyX(Grill& grill);
void handleQueryBuyList(Grill& grill);
void handleQueryNewKebab(Grill& grill);
void handleQuerySwap(Grill& grill);
void handleQuerySort(Grill& grill);

int main()
{
  runScriptedTests();
  // test2();
  // test3();
  // test4();
  test5();
  // test6();
  //runInteractiveTest();

  return 0;
}

void runScriptedTests()
{
  Kebab k;
  std::string contents; 

  contents = k.listIngredients();
  if(contents != "") cout << "ERROR: list should be empty" << endl;

  k.addIngredient('V');
  k.addIngredient('%');
  k.addIngredient('\n');
  contents = k.listIngredients();
  if(contents != "") cout << "ERROR: list should be empty cuz added invalid ingredients" << endl;

  k.addIngredient('b');
  k.addIngredient('B');
  k.addIngredient('t');
  k.addIngredient('m');
  k.addIngredient('p');
  contents = k.listIngredients();
  if(!((contents == "bBtmp") || (contents == "pmtBb"))){
    cout << "ERROR: INSERTION ORDER IS NOT preserved when adding ingredients" << endl;
  }

  Kebab k2;

  k2.addIngredient('b');
  k2.addIngredient('B');
  k2.addIngredient('t');
  k2.addIngredient('T');
  k2.addIngredient('m');
  k2.addIngredient('M');
  k2.addIngredient('p');
  k2.addIngredient('P');
  k2.addIngredient('s');
  k2.addIngredient('S');
  contents = k2.listIngredients();
  assert(((contents == "bBtTmMpP") || (contents == "PpMmTtBb")));

  //TEST CASES FOR KEBAB
  //1: Testing bool addIngredient(char item);
  //2: void buildKebab(std::string s);
  //3: unsigned int numMeats() const;
  //4: bool hasSameIngredients(Kebab& k) const;
  //5: std::string listIngredients() const;
  
  //test adding an item to an ald full skewer
  // Kebab* kebab1 = new Kebab();
  // kebab1->buildKebab("BTMPSBTM");
  // if(kebab1->addIngredient('b')){
  //   cout << "ERROR: added ingredients to an already full skewer!" << endl; 
  // }
  // else{
  //   cout << "CORRECT" << endl; 
  // }
  // delete kebab1;
  // kebab1 = NULL;

  // // //test adding an item to an empty skewer
  // Kebab* kebab = new Kebab();
  // kebab->buildKebab(" ");
  // if(!kebab->addIngredient('s')){
  //   cout << "ERROR: cannot add an item to an empty skewer" << endl; 
  // }
  // else{
  //   cout << "CORRECT: below should be s" << endl; 
  //   cout << kebab->listIngredients() << endl; 
  // }
  // delete kebab;
  // kebab = NULL;

  // // //test adding an item to a skewer with less than SKEWER_SIZE item
  // Kebab* kebab3 = new Kebab();
  // kebab3->buildKebab("bhjkbhjkbhjk");
  // cout << "Below should be bbb" << endl;
  // cout << kebab3->listIngredients() << endl;
  // cout << "Below should print 3" << endl; 
  // cout << kebab3->numMeats() << endl;
  // if(kebab3->addIngredient('k')){
  //   cout << "ERROR: added an invalid k to skewer" << endl; 
  // } 
  // else{
  //   cout << "CORRECT: below should be bbb" << endl; 
  //   cout << kebab3->listIngredients() << endl; 
  // } 
  // if(kebab3->addIngredient('P')){
  //   cout << "CORRECT: below should be bbbP" << endl; 
  //   cout << kebab3->listIngredients() << endl;
  // } 
  // else{
  //   cout << "ERROR: unable to add a valid item to a not full skewer" << endl;
  // }
  // cout << "Below should be 3" << endl;
  // cout << kebab3->numMeats() << endl;
  // delete kebab3;
  // kebab3 = NULL;

  // //test hasSameIngredients
  // Kebab* kebab4 = new Kebab();
  // kebab4->buildKebab("bbB");
  // Kebab* kebab5 = new Kebab();
  // kebab5->buildKebab("BBb");
  // Kebab* kebab6 = new Kebab();
  // kebab6->buildKebab("BBBB");
  // Kebab* kebab7 = new Kebab();
  // kebab7->buildKebab("SSbby");

  // // if(!kebab4->hasSameIngredients(*kebab5) ||
  // //     !kebab5->hasSameIngredients(*kebab6) ||
  // //     kebab7->hasSameIngredients(*kebab4)){
  //   cout <<  kebab7->hasSameIngredients(*kebab4) << endl;
  // //}

  // delete kebab4;
  // kebab4 = NULL;
  // delete kebab5;
  // kebab5 = NULL;
  // delete kebab6;
  // kebab6 = NULL;
  // delete kebab7;
  // kebab7 = NULL;

  // //TEST LinkedList
  // LinkedList* ll = new LinkedList();
  // cout <<  "Should be 0; 1" << endl;
  // cout <<  ll->size() << endl;
  // cout <<  ll->isEmpty() << endl;

  // Kebab* freshkebab;
  // freshkebab = new Kebab();
  // freshkebab->buildKebab("bbbbb");

  // ll->insertBack(freshkebab);
  // cout <<  "#3: should be bbbbb" << endl;
  // cout <<  ll->elementAt(0)->listIngredients() << endl;
  // cout <<  ll->showFront()->listIngredients() << endl;
  // cout <<  ll->showBack()->listIngredients() << endl;
  // delete freshkebab;
  // freshkebab = NULL;

  // freshkebab = new Kebab();
  // freshkebab->buildKebab("BBB");

  // ll->insertBack(freshkebab);
  // cout <<  "should be BBB" << endl;
  // cout <<  ll->elementAt(1)->listIngredients() << endl;
  // cout <<  "should be bbbbb" << endl;
  // cout <<  ll->elementAt(0)->listIngredients() << endl;
  // cout <<  "should be bbbbb" << endl;
  // cout <<  ll->showFront()->listIngredients() << endl;
  // cout <<  "should be 1" << endl;
  // cout <<  ll->contains(*freshkebab) << endl;
  // cout <<  "should be 2" << endl;
  // cout <<  ll->size() << endl;
  // cout <<  ll->listKebabs() << endl;
  // delete freshkebab;
  // freshkebab = NULL;

  // freshkebab = new Kebab();
  // freshkebab->buildKebab("TTPPSb");
  // bool insert = ll->insertAt(freshkebab,1);
  // if(insert){
  //   cout <<  "inserted!" << endl;
  //   cout <<  ll->listKebabs() << endl;
  //   cout <<  ll->showFront()->listIngredients() << endl;
  //   cout <<  ll->showBack()->listIngredients() << endl;
  // }
  // else{
  //   cout <<  "ERR: printing list " << endl;
  //   cout <<  ll->listKebabs() << endl;
  // }
  // delete freshkebab;
  // freshkebab = NULL;

  // freshkebab = new Kebab();
  // freshkebab->buildKebab("bbbBBBpqq");
  // insert = ll->insertAt(freshkebab,3);
  // if(insert){
  //   cout <<  "inserted!" << endl;
  //   cout <<  ll->listKebabs() << endl;
  //   cout <<  ll->showFront()->listIngredients() << endl;
  //   cout <<  ll->showBack()->listIngredients() << endl;
  // }
  // else{
  //   cout <<  "ERR: printing list " << endl;
  //   cout <<  ll->listKebabs() << endl;
  // }
  // delete freshkebab;
  // freshkebab = NULL;

  // freshkebab = new Kebab();
  // freshkebab->buildKebab("OPqBbr");
  // insert = ll->insertAt(freshkebab,0);
  // if(insert){
  //   cout <<  "inserted!" << endl;
  //   cout <<  ll->listKebabs() << endl;
  //   cout <<  ll->showFront()->listIngredients() << endl;
  //   cout <<  ll->showBack()->listIngredients() << endl;
  // }
  // else{
  //   cout <<  "ERR: printing list " << endl;
  //   cout <<  ll->listKebabs() << endl;
  // }

  // cout <<  ll->removeAt(4)->listIngredients() << endl;
  // cout <<  ll->listKebabs() << endl;
  // cout <<  ll->showFront()->listIngredients() << endl;
  // cout <<  ll->showBack()->listIngredients() << endl;
  // cout <<  ll->size() << endl;
  // delete freshkebab;
  // freshkebab = NULL;
  // delete ll;
}

void test2(){
  Kebab k;
  std::string contents;

  k.buildKebab("");
  contents = k.listIngredients();
  assert(contents == "");

  k.buildKebab("be7b!");
  contents = k.listIngredients();
  assert(contents == "bb");

  Kebab k2;
  k2.buildKebab("bBtmp");
  contents = k2.listIngredients();
  assert(((contents == "bBtmp") || (contents == "pmtBb")));

  Kebab k3;
  k3.buildKebab("bBtTmMpPsS");
  contents = k3.listIngredients();
  assert(((contents == "bBtTmMpP") || (contents == "PpMmTtBb")));
}

void test3(){
  Kebab k1;  // empty kebab
  Kebab k2;  // non-empty, contains no meat
  Kebab k3;  // contains a single meat as only ingredient
  Kebab k4;  // contains a single meat among multiple ingredients
  Kebab k5;  // contains multiple (3) meats as only ingredient
  Kebab k6;  // contains multiple (4) meats among multiple ingredients
  Kebab k7;  // contains the maximum number (8) of meats

  k2.addIngredient('t');  k2.addIngredient('M');  k2.addIngredient('p');
  k2.addIngredient('S');  k2.addIngredient('T');

  k3.addIngredient('B');

  k4.addIngredient('T');  k4.addIngredient('m');  k4.addIngredient('P');
  k4.addIngredient('b');  k4.addIngredient('S');

  k5.addIngredient('b');  k5.addIngredient('B');  k5.addIngredient('B');

  k6.addIngredient('S');  k6.addIngredient('P');  k6.addIngredient('b');
  k6.addIngredient('t');  k6.addIngredient('B');  k6.addIngredient('b');
  k6.addIngredient('M');  k6.addIngredient('B');

  k7.addIngredient('b');  k7.addIngredient('b');  k7.addIngredient('B');
  k7.addIngredient('b');  k7.addIngredient('B');  k7.addIngredient('B');
  k7.addIngredient('b');  k7.addIngredient('B');

  assert(k1.numMeats() == 0);
  assert(k2.numMeats() == 0);
  assert(k3.numMeats() == 1);
  assert(k4.numMeats() == 1);
  assert(k5.numMeats() == 3);
  assert(k6.numMeats() == 4);
  assert(k7.numMeats() == 8);
}

void test4(){
  Kebab k1;  // b
  Kebab k2;  // bBt
  Kebab k3;  // tm
  Kebab k4;  // bmss
  Kebab k5;  // Pss

              // available kebabs
  Kebab k6;  // spTmbS
  Kebab k7;  // tmMsps
  Kebab k8;  // pPbTPB
  Kebab k9;  // mSpbBM
  Kebab k10; // mMmsmMBS
  Kebab k11; // (empty)

   // set up each Kebab
              // using addIngredient in case of errors with buildKebab
  k1.addIngredient('b');

  k2.addIngredient('b');  k2.addIngredient('B');  k2.addIngredient('t');

  k3.addIngredient('t');  k3.addIngredient('m');

  k4.addIngredient('b');  k4.addIngredient('m');
  k4.addIngredient('s');  k4.addIngredient('s');

  k5.addIngredient('P');  k5.addIngredient('s');  k5.addIngredient('s');

  k6.addIngredient('s');  k6.addIngredient('p');  k6.addIngredient('T');
  k6.addIngredient('m');  k6.addIngredient('b');  k6.addIngredient('S');

  k7.addIngredient('t');  k7.addIngredient('m');  k7.addIngredient('M');
  k7.addIngredient('s');  k7.addIngredient('p');  k7.addIngredient('s');

  k8.addIngredient('p');  k8.addIngredient('P');  k8.addIngredient('b');
  k8.addIngredient('T');  k8.addIngredient('P');  k8.addIngredient('B');

  k9.addIngredient('m');  k9.addIngredient('S');  k9.addIngredient('p');
  k9.addIngredient('b');  k9.addIngredient('B');  k9.addIngredient('M');

  k10.addIngredient('m');  k10.addIngredient('M');  k10.addIngredient('m');
  k10.addIngredient('s');  k10.addIngredient('m');  k10.addIngredient('M');
  k10.addIngredient('B');  k10.addIngredient('S');

  assert(!k11.hasSameIngredients(k1));
  assert(!k11.hasSameIngredients(k2));
  assert(!k11.hasSameIngredients(k3));
  assert(!k11.hasSameIngredients(k4));
  assert(!k11.hasSameIngredients(k5));

  assert(!k6.hasSameIngredients(k2));
  assert(!k7.hasSameIngredients(k1));
  assert(!k7.hasSameIngredients(k2));
  assert(!k7.hasSameIngredients(k4));
  assert(!k8.hasSameIngredients(k3));
  assert(!k8.hasSameIngredients(k4));
  assert(!k8.hasSameIngredients(k5));
  assert(!k9.hasSameIngredients(k2));
  assert(!k9.hasSameIngredients(k3));
  assert(!k9.hasSameIngredients(k4));
  assert(!k9.hasSameIngredients(k5));
  assert(!k10.hasSameIngredients(k2));
  assert(!k10.hasSameIngredients(k3));
  assert(!k10.hasSameIngredients(k5));

  assert(k6.hasSameIngredients(k1));
  assert(k6.hasSameIngredients(k3));
  assert(k6.hasSameIngredients(k4));
  assert(k6.hasSameIngredients(k5));
  assert(k7.hasSameIngredients(k3));
  assert(k7.hasSameIngredients(k5));
  assert(k8.hasSameIngredients(k1));
  assert(k8.hasSameIngredients(k2));
  assert(k9.hasSameIngredients(k1));
  assert(k10.hasSameIngredients(k1));
  assert(k10.hasSameIngredients(k4));
}

void test5(){
  LinkedList emptyList;
  LinkedList oneItemList;
  Kebab *item = new Kebab();
  item->addIngredient('b');
  item->addIngredient('p');
  item->addIngredient('m');
  oneItemList.insertFront(item);

  assert(emptyList.size() == 0);
  assert(emptyList.isEmpty());

  // LinkedList copiedList(oneItemList);
  // cout << copiedList.contains(*item) << endl;
  // cout << copiedList.size() << endl;
  // assert(copiedList.size() == 1);
  // assert(!copiedList.isEmpty());
  // assert(copiedList.contains(*item));
  // assert(copiedList.elementAt(0) == item);
  // assert(copiedList.elementAt(0)->listIngredients() == item->listIngredients());

  // LinkedList copiedList1;
  // copiedList1.operator=(oneItemList);
  // assert(copiedList1.size() == 1);
  // assert(!copiedList1.isEmpty());
  // assert(copiedList1.contains(*item));
  // assert(copiedList1.elementAt(0) == item);
  // assert(copiedList1.elementAt(0)->listIngredients() == item->listIngredients());

  // oneItemList.operator=(oneItemList);
  // assert(oneItemList.size() == 1);
  // assert(oneItemList.elementAt(0) == item);

}

void test6(){
  Grill g;
  std::vector<std::string> kebabs;

  Kebab* k0 = new Kebab();
  Kebab* k1 = new Kebab();
  Kebab* k2 = new Kebab();
  Kebab* k3 = new Kebab();
  Kebab* k4 = new Kebab();
  Kebab* k5 = new Kebab();
  Kebab* k6 = new Kebab();
  Kebab* k7 = new Kebab();
  Kebab* k8 = new Kebab();

  k0->addIngredient('t');
  k1->addIngredient('b');
  k2->addIngredient('b');  k2->addIngredient('b');
  k3->addIngredient('b');  k3->addIngredient('b');  k3->addIngredient('b');
  k4->addIngredient('b');  k4->addIngredient('b');
  k4->addIngredient('b');  k4->addIngredient('b');
  k5->addIngredient('b');  k5->addIngredient('b');  k5->addIngredient('b');
  k5->addIngredient('b');  k5->addIngredient('b');
  k6->addIngredient('b');  k6->addIngredient('b');  k6->addIngredient('b');
  k6->addIngredient('b');  k6->addIngredient('b');  k6->addIngredient('b');
  k7->addIngredient('b');  k7->addIngredient('b');  k7->addIngredient('b');
  k7->addIngredient('b');  k7->addIngredient('b');  k7->addIngredient('b');
  k7->addIngredient('b');
  k8->addIngredient('b');  k8->addIngredient('b');  k8->addIngredient('b');
  k8->addIngredient('b');  k8->addIngredient('b');  k8->addIngredient('b');
  k8->addIngredient('b');  k8->addIngredient('b');

   g.addKebab(*k4);  g.addKebab(*k8);  g.addKebab(*k1);  g.addKebab(*k7);
    g.addKebab(*k2);  g.addKebab(*k5);  g.addKebab(*k6);  g.addKebab(*k0);
    g.addKebab(*k3);
    g.sortByMeat();

    kebabs = g.showKebabs();
    assert(kebabs.size() == 9);
    assert(kebabs[0] == "bbbbbbbb");
    assert(kebabs[1] == "bbbbbbb");
    assert(kebabs[2] == "bbbbbb");
    assert(kebabs[3] == "bbbbb");
    assert(kebabs[4] == "bbbb");
    assert(kebabs[5] == "bbb");
    assert(kebabs[6] == "bb");
    assert(kebabs[7] == "b");
    assert(kebabs[8] == "t");
}

void runInteractiveTest()
{
  // create a Grill and populate it with some Kebabs
  Grill g;
  Kebab* freshkebab;
  freshkebab = new Kebab();
  freshkebab->buildKebab("TMTBPP");
  g.addKebab(*freshkebab);
  //delete freshkebab;
  freshkebab = new Kebab();
  freshkebab->buildKebab("B 3%#SN,M[PM TBSB54M,ZDROB8RTZ3 564 /][98Z3");
  g.addKebab(*freshkebab);
  //delete freshkebab;
  freshkebab = new Kebab();
  freshkebab->buildKebab("BMB");
  g.addKebab(*freshkebab);
  //delete freshkebab;

  string inputchoice = "";
  int choice = 0;

  while (choice != 8)
  {
    displayMenu();
    // get the menu choice from standard input
    getline(cin, inputchoice);
    choice = atoi(inputchoice.c_str());

    switch (choice)
    {
    case 1: // See the kebabs
      handleQueryShowGrill(g);
      break;
    case 2: // Buy a kebab by pointing
      handleQueryBuyX(g);
      break;
    case 3: // Buy a kebab by listing ingredients
      handleQueryBuyList(g);
      break;
    case 4: // Make a new kebab
      handleQueryNewKebab(g);
      break;
    case 5: // Swap two kebabs on the grill
      handleQuerySwap(g);
      break;
    case 6: // Descending sort the kebabs by meat amount
      handleQuerySort(g);
      break;
    case 8: // End
      cout << "Thank you, come again!" << endl;
      break;
    default: // invalid option
      cout << "Invalid choice." << endl;
      break;
    }
  }
}

// prints the options menu to screen
void displayMenu()
{
  cout << "*****************************************\n"
       << "* Welcome to Speedy Kebab terminal      *\n"
       << "* What would you like to do?            *\n"
       << "*                                       *\n"
       << "* Customer operations:                  *\n"
       << "* 1. See the kebabs on the grill        *\n"
       << "* 2. Buy a kebab by number              *\n"
       << "* 3. Buy a kebab by listing ingredients *\n"
       << "*                                       *\n"
       << "* Staff operations:                     *\n"
       << "* 4. Make a new kebab                   *\n"
       << "* 5. Swap two kebabs                    *\n"
       << "* 6. Sort by meat amounts               *\n"
       << "*                                       *\n"
       << "* 8. End                                *\n"
       << "*****************************************" << endl;
  cout << "Please enter your choice: ";
}

void handleQueryShowGrill(Grill& grill)
{
  vector<string> kebabs = grill.showKebabs();
  int numkebabs = kebabs.size();
  // pad all kebab strings with " " to make them SKEWER_SIZE
  for (int i = 0; i < numkebabs; i++)
  {
    if (kebabs[i].length() < SKEWER_SIZE)
    {
      while (kebabs[i].length() < SKEWER_SIZE)
        kebabs[i] = kebabs[i] + " ";
    }
    cout << i + 1 << "\t";
  }
  cout << endl;
  for (int i = 0; i < numkebabs; i++)
    cout << "~~~\t";
  cout << endl;
  for (int chars = 0; chars < SKEWER_SIZE; chars++)
  {
    for (int k = 0; k < numkebabs; k++)
    {
      cout << kebabs[k][chars] << "\t";
    }
    cout << endl;
  }
}

void handleQueryBuyX(Grill& grill)
{
  string inputchoice = "";
  int choice = 0;
  cout << "Enter the number of the kebab: ";
  getline(cin, inputchoice);
  choice = atoi(inputchoice.c_str());
  Kebab* purchased = grill.request((unsigned int)choice);
  if (purchased != NULL)
    cout << "Thank you, enjoy!\n" << endl;
  else
    cout << "Sorry, I cannot help you with that.\n" << endl;
  delete purchased;
}

void handleQueryBuyList(Grill& grill)
{
  string wanted;
  cout << "Enter the first character of each ingredient you want: ";
  getline(cin, wanted);
  Kebab wantedkebab;
  wantedkebab.buildKebab(wanted);
  Kebab* purchased = grill.request(wantedkebab);
  if (purchased != NULL)
    cout << "Thank you, enjoy!\n" << endl;
  else
    cout << "Sorry, I cannot help you with that.\n" << endl;
  delete purchased;
}

void handleQueryNewKebab(Grill& grill)
{
  string ilist;
  cout << "Enter the first character of each ingredient to use: ";
  getline(cin, ilist);
  Kebab* freshkebab = new Kebab();
  freshkebab->buildKebab(ilist);
  grill.addKebab(*freshkebab);
  cout << "A fresh kebab is on the grill!\n" << endl;
}

void handleQuerySwap(Grill& grill)
{
  string inputchoice = "";
  int k1 = 0;
  cout << "Enter the number of the first kebab: ";
  getline(cin, inputchoice);
  k1 = atoi(inputchoice.c_str());
  int k2 = 0;
  cout << "Enter the number of the second kebab: ";
  getline(cin, inputchoice);
  k2 = atoi(inputchoice.c_str());
  if (grill.swap((unsigned int)k1, (unsigned int)k2))
    cout << "Kebabs swapped.\n" << endl;
  else
    cout << "Sorry, you cannot do that.\n" << endl;
}

void handleQuerySort(Grill& grill)
{
  grill.sortByMeat();
  cout << "More meat on the left!\n" << endl;
}
