/*
   Assignment: Project 454
*/

#include <iostream>
#include <vector>
#include "States.hpp"

using namespace std;

void dependents(State *root, State *state, bool first);
int size (State *s);
bool win(int p[], int symbol);
//bool checkCopy(State *root, State *parent, State *kid);
bool draw(int p[]);
//bool check(int p[], int a[]);

void CreateDFA(State *root, State *state, int n){
  if (n == 0 || state == nullptr)
    return;
  if (state->isFinal())
    return;
  if (state->isReject())
    return;
  if(state->isDraw())
    return;
  dependents(root, state, state->firstMove());
  for (vector<State*>::iterator iter = state->getChildren()->begin(); iter != state->getChildren()->end(); iter++){
    CreateDFA(root, *iter, n - 1);
  }
}

void dependents(State *root, State *state, bool first){
  cout << "Setting Dependents " << endl;
  int symbol;
  if (first)
    symbol = 1;
  else
    symbol = 0;
  int count = 0;
  while (count < 9){
    if (state->position()[count] == 2 && state->position()[count] != 1 && state->position()[count] != 0){
      // If move is blank, it creates a new State called child and changes that position to the symbol
      // then adds that child to state's children
      int check[9];
      for(int i = 0; i < 9; i++)
	   check[i] = state->position()[i];
      check[count] = symbol;
      cout << "Looking for..." << endl;
      for (int i = 0; i < 9; i++)
	cout << "Position " << i << ": " << check[i] << endl;
      cout << endl;
      State *child = root->find(root, check);
      if (child == nullptr){
	   child = new State();
	   cout << "Was nullptr" << endl;
	   cout << "Count was " << count << endl;
	   child->setPosition(state->position());
	   child->setFirstMove(!(state->firstMove()));
	   child->position()[count] = symbol;
	   child->setFinal(win(child->position(), 1));
	   child->setReject(win(child->position(), 0));
	   child->setDraw(draw(child->position()));
      }
      else
	cout << "Found it!" << endl;
      
      state->setStateChildren(child);
      //	state->setStateChildren(child);
      /*	if(checkCopy(root, state, child)){
		child = nullptr;
		delete child; 
	cout << "Deleted Child" << endl;
	}
        else {
	cout << "Set Child from Dependents, not copy" << endl;
	
	}*/
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

bool draw(int p[]){
  if(p[0] != 2 && p[1] != 2 && p[2] != 2 && p[3] != 2 && p[4] != 2 && p[5] != 2 && p[6] != 2 && p[7] != 2 && p[8] != 2){
    cout << "Set Draw" << endl;
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


/*bool checkCopy(State *root, State *parent, State *child){
  cout << "Checking for Copy " << endl;
  cout << endl;
  //  if (root == nullptr)
  //return false;

  if (root->isFinal() || root->isReject() || root->isDraw())
    return false;
  
  for(vector<State*>::iterator iter = root->getChildren()->begin(); iter != root->getChildren()->end(); iter++){
       cout << endl;
    cout << "Comparing " << endl;
    for (int i = 0; i < 9; i++){
      cout << "Position " << i << ": iter = " << (*iter)->position()[i] << " & child = " << child->position()[i];
      cout << endl;
    }
    cout << endl;
    
    cout << endl;
    if (check(child->position(), (*iter)->position())){
      cout << endl;
      cout << "HERE" << endl;
      cout << endl;
      cout << endl;
      cout << endl;
      parent->setStateChildren(*iter);
      cout << "Setting new child from checkCopy" << endl;
      for( int i = 0; i < 9; i++)
	cout << child->position()[i] << " ";
      cout << endl;
      return true;

    }
    else{
      cout << "Going deeper" << endl;
      return checkCopyhelp(*iter, parent, child);
    }
  }
  //  return false;
}



bool checkCopyHelp(State *root, State *parent, State *child){
   for(vector<State*>::iterator iter = root->getChildren()->begin(); iter != root->getChildren()->end(); iter++){
     
*/

bool check(int p[], int a[]){
  for(int i = 0; i < 9; i++)
    if (p[i] != a[i])
      return false;
      return true;
  /*  bool is_equal = false;
  for (int i = 0; i < 9; i++)
    is_equal = (p[i] == a[i]);
    return is_equal;*/

}



int main(){
  State * s = new State();
  CreateDFA(s, s, 8);
  //  s->print();
  int q[9] = {2, 2, 2, 1, 1, 1, 1, 1, 0};
  int b[9] = {2, 2, 2, 1, 1, 1, 1, 1, 0};
  if (check(q, b))
    cout << "Same" << endl;
  int n = size(s);
  cout << "Total Number of Nodes: " << n << endl;
  return 0;
}

