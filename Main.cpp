/*
   Assignment: Project 454
*/

#include <iostream>
#include <vector>
#include "States.hpp"

using namespace std;

void dependents(State *state, bool first);
int size (State *s);
bool win(int p[], int symbol);
bool checkCopy(State *root, State *kid);
bool checkCopyHelp(State *test, State *root, State *kid);

void CreateDFA(State *state, int n){
  bool first;
  dependents(state, state->firstMove());
  if (n == 0)
    return;
  if (state->isFinal())
    return;
  if (state->isReject())
    return;
  //  cout << "State Parent " << endl;
  // state->print();
  for (vector<State*>::iterator iter = state->getChildren()->begin(); iter != state->getChildren()->end(); iter++){
     first = (*iter)->firstMove();
     dependents(*iter, first);
     CreateDFA(*iter, n - 1);
      }
}

void dependents(State *state, bool first){
  int symbol;
  if (first == true)
    symbol = 1;
  else
    symbol = 0;
  int count = 0;
     while (count < 9){
       if (state->position()[count] == 2 && state->position()[count] != 1 && state->position()[count] != 0){
      // If move is blank, it creates a new State called child and changes that position to the symbol
      // then adds that child to state's children
            State *child = new State();
            child->setPosition(state->position());
            child->setFirstMove(!(first));
            child->position()[count] = symbol;
            child->setFinal(win(child->position(), 1));
            child->setReject(win(child->position(), 0));
            if(checkCopy(state, child) == false)
                state->setStateChildren(child);
            else
                child = NULL;
        }
        count++;
     }
}

bool win(int p[], int symbol){
  if(p[0] == symbol && p[1] == symbol && p[2] == symbol)
    return true;
  if(p[0] == symbol && p[4] == symbol && p[8] == symbol)
    return true;
  if(p[0] == symbol && p[6] == symbol && p[3] == symbol)
    return true;
  if(p[1] == symbol && p[4] == symbol && p[7] == symbol)
    return true;
  if(p[2] == symbol && p[4] == symbol && p[6] == symbol)
    return true;
  if(p[2] == symbol && p[5] == symbol && p[8] == symbol)
    return true;
  if(p[3] == symbol && p[4] == symbol && p[5] == symbol)
    return true;
  if(p[6] == symbol && p[7] == symbol && p[8] == symbol)
    return true;
  return false;
}

int size (State *s){
  if (s == nullptr)
    return 0;
  int count = 0;
  for(vector<State*>::iterator iter = s->getChildren()->begin(); iter != s->getChildren()->end(); iter++)
    count = size(*iter) + count;
  return count + 1;
  }

bool checkCopy(State *root, State *kid)
{
    State *test = root->getParents()->at(0);
    while (test->getParents()->at(0) != nullptr)
        test = test->getParents()->at(0);             ///When this is done, test is the head of the DFA
    return checkCopyHelp(test, root, kid);
}

bool checkCopyHelp(State *test, State *root, State *kid)
{
    if(test->position() == kid->position()){
        test->setStateParents(root);
        return true;
    }
    else{
        for(int i = 0; i < test->getChildren()->size(); i++)
        {
            State* thing = test->getChildren()->at(i);
            if(checkCopyHelp(thing, root, kid) == true)
                return true;
        }
        return false;
    }
}

int main(){
  State * s = new State();
  CreateDFA(s, 5);
  // s->print();
  int n = size(s);
  cout << "Total Number of Nodes: " << n << endl;
  return 0;
}

/**
  Things that need to be done:
    We need to set up each node with a vector of pointer to of parent nodes because in a DFA, unlike a tree, a node can have multiple nodes going to it.
    Do also do this we need to have a lookup function when we are adding dependents to see if there is a path already going to that node.
    >>>We also need to report the total number or wins
*/
