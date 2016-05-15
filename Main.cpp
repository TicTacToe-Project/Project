/*
   Assignment: Project 454
*/

#include <iostream>
#include <vector>
#include "States.hpp"

using namespace std;

int num = 1;


void dependents(State *state, bool first);
int size (State *s);
bool win(vector<int> *p, int symbol);
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
  ///for (vector<State*>::iterator iter = state->getChildren()->begin(); iter != state->getChildren()->end(); iter++){
    for (int i = 0; i < state->getChildren()->size(); i++){
        State* test = state->getChildren(i);
        first = test->firstMove();
        dependents(test, first);
        //int t;
        //cin >> t;
        CreateDFA(test, n - 1);
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
        vector<int> *stuff = state->position();
       if (stuff->at(count) == 2 && stuff->at(count) != 1 && stuff->at(count) != 0){
      /// If move is blank, it creates a new State called child and changes that position to the symbol
      /// then adds that child to state's children
            State *child = new State();
            child->setPosition(state->position());
            child->setFirstMove(!(first));
            child->position()->at(count) = symbol;
            child->setFinal(win(child->position(), 1));
            child->setReject(win(child->position(), 0));

            if(checkCopy(state, child) == false){
                state->setStateChildren(child);
                cout << num << endl;
                child->print();
                num++;
            }
            else{
                child = nullptr;
            }
        }
        count++;
     }
}

bool win(vector<int> *p, int symbol){
    if(p->at(0) == symbol && p->at(1) == symbol && p->at(2) == symbol){
        return true;
    }
    if(p->at(0) == symbol && p->at(4) == symbol && p->at(8) == symbol){
        return true;
    }
    if(p->at(0) == symbol && p->at(6) == symbol && p->at(3) == symbol){
        return true;
    }
    if(p->at(1) == symbol && p->at(4) == symbol && p->at(7) == symbol){
        return true;
    }
    if(p->at(2) == symbol && p->at(4) == symbol && p->at(6) == symbol){
        return true;
    }
    if(p->at(2) == symbol && p->at(5) == symbol && p->at(8) == symbol){
        return true;
    }
    if(p->at(3) == symbol && p->at(4) == symbol && p->at(5) == symbol){
        return true;
    }
    if(p->at(6) == symbol && p->at(7) == symbol && p->at(8) == symbol){
        return true;
    }
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
    //vector<State *> *stuff = root->getParents();
    State* test = root;
    if(root->getParents()->empty() != true)
    {
        test = root->getParents(0);
        //cout << "is the problem here? 1" << endl;
        while(test->getParents()->empty() != true){
            if (test->getParents(0) != nullptr){
                //cout << "is the problem here? 2" << endl;
                test = test->getParents(0);             ///When this is done, test is the head of the DFA
            }
        }
    }
    return checkCopyHelp(test, root, kid);
}

bool checkCopyHelp(State *test, State *root, State *kid)
{
    /**cout << "Comparing ";
    for(int i = 0; i < test->position()->size(); i++)
        cout << test->position()->at(i);
    cout << " and ";
    for(int i = 0; i < kid->position()->size(); i++)
        cout << kid->position()->at(i);
    cout << endl;
*/
    ///if(test->position() == kid->position()){
    if(test->position()->at(0) == kid->position()->at(0) && test->position()->at(1) == kid->position()->at(1)
        && test->position()->at(2) == kid->position()->at(2) && test->position()->at(3) == kid->position()->at(3)
        && test->position()->at(4) == kid->position()->at(4) && test->position()->at(5) == kid->position()->at(5)
        && test->position()->at(6) == kid->position()->at(6) && test->position()->at(7) == kid->position()->at(7)
        && test->position()->at(8) == kid->position()->at(8)){

        test->setStateParents(root);
        cout << "A copy was found" << endl;
        cout << endl;
        cout << endl;
        //int t;
        //cin >> t;
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
  CreateDFA(s, 9);
  //s->print();
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
