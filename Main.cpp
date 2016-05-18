/*
   Assignment: Project 454
*/

#include <iostream>
#include <vector>
#include "States.hpp"
#include <time.h>
#include <stdlib.h>


using namespace std;

void CreateDFA(State *root, State *state);
void dependents(State *root, State *state, bool first);
int size (State *s);
bool win(vector<int> *p, int symbol);
bool draw(vector<int> *p);
bool find(State *root, State * parent, State * child);


void CreateDFA(State *root, State *state){
  if (state == nullptr || state->isFinal() || state->isReject())
    return;
  dependents(root, state, state->firstMove());
  for (vector<State*>::iterator iter = state->getChildren()->begin(); iter != state->getChildren()->end(); iter++){
    CreateDFA(root, *iter);
  }
}


void dependents(State *root, State *state, bool first){
  int symbol;
  if (first)
    symbol = 1;
  else
    symbol = 0;
  int count = 0;
  while (count < 9){
    if(state->position()->at(count) == 2 && state->position()->at(count) != 1 && state->position()->at(count) != 0){
      State *child = new State();
      child->setPosition(state->position());
      child->setFirstMove(!(first));
      child->position()->at(count) = symbol;
      child->setStateParents(state);
      child->setFinal(win(child->position(), 1));
      child->setReject(win(child->position(), 0));
      if (!(child->isFinal()) && !(child->isReject()))
	child->setReject(draw(child->position()));
      if(find(root, state, child)){
	child = nullptr;
	delete child;
      }
      else
	state->setStateChildren(child);
    }
    count++;
  }
  
}



bool win(vector<int>*p, int symbol){
  if(p->at(0) == symbol && p->at(1) == symbol && p->at(2) == symbol)
    return true;
  if(p->at(0) == symbol && p->at(4) == symbol && p->at(8) == symbol)
    return true;
  if(p->at(0) == symbol && p->at(6) == symbol && p->at(3) == symbol)
    return true;
  if(p->at(1) == symbol && p->at(4) == symbol && p->at(7) == symbol)
    return true;
  if(p->at(2) == symbol && p->at(4) == symbol && p->at(6) == symbol)
    return true;
  if(p->at(2) == symbol && p->at(5) == symbol && p->at(8) == symbol)
    return true;
  if(p->at(3) == symbol && p->at(4) == symbol && p->at(5) == symbol)
    return true;
  if(p->at(6) == symbol && p->at(7) == symbol && p->at(8) == symbol)
    return true;
  return false;
}


bool draw(vector<int> *p){
  if(p->at(0) != 2 && p->at(1) != 2 && p->at(2) != 2 && p->at(3) != 2 && p->at(4) != 2 && p->at(5) != 2 && p->at(6) != 2 && p->at(7) != 2 && p->at(8) != 2){
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




bool find(State * root, State * parent, State * child){
  if (root->position()->at(0) == child->position()->at(0) && root->position()->at(1) == child->position()->at(1) && root->position()->at(2) == child->position()->at(2) && root->position()->at(3) == child->position()->at(3) && root->position()->at(4) == child->position()->at(4) && root->position()->at(5) == child->position()->at(5) && root->position()->at(6) == child->position()->at(6) && root->position()->at(7) == child->position()->at(7) && root->position()->at(8) == child->position()->at(8)){
    root->setStateParents(parent);
    return true;
  }
  else{
    for (vector<State*>::iterator iter = (root)->getChildren()->begin(); iter != (root)->getChildren()->end(); iter++){
      if(find((*iter), parent, child))
	return true;
    }
    return false;
  }
}



int Evaluate(State * root){
  int sum;
  if(root->isFinal())
    sum = 1;
  else
    sum = 0;
  for (vector<State*>::iterator iter = (root)->getChildren()->begin(); iter != (root)->getChildren()->end(); iter++){
    sum = sum + Evaluate(*iter);
  }
  //cout << sum << endl;
  //  int total = sum /(root->getChildren()->size() + 1);
  // cout << total << endl;
  return sum;
}

int total(State *root){
  int t;
  if (root->isReject()|| root->isFinal())
    t = 1;
  else
    t =0;
  for (vector<State*>::iterator iter = (root)->getChildren()->begin(); iter != (root)->getChildren()->end(); iter++){
    t = t + total(*iter);
  }
  return t;
}


int simulation(State * root){
  int array[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  // int 
  return 0;
}
int main(){
  State * s = new State();
  CreateDFA(s, s);
  int n = size(s);
  int f = Evaluate(s);
  int t = total(s);
   float total = ((float)f /(float)t) * 100;
  cout << "Total Number of Nodes: " << n << endl;
  cout << "Probability that the first player will win: " << total << "%" << endl;
  return 0;
}




