// file:        interpreterprivate.h
// author:      Jack S-J, Geoff T
// date:        2017-10-11
// description: private methods for Interpreter
//              Declare and implement your private functions here.
//              Leave blank if you have no private functions to implement.
//              No includes or qualification necessary. Example below:

#ifndef _INTERPRETERPRIVATE_H_
#define _INTERPRETERPRIVATE_H_

int numOfInstructions(){
   int numInstr = 0;

    for (unsigned int i=0; i<tube.size(); i++){
        if(tube.peek() == "#"){
            numInstr++;
        }
        std::string deq = tube.dequeue();
        tube.enqueue(deq);
    }
    return numInstr;
}

#endif