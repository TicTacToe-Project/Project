#include "States.hpp"

State::State(){
  final = false;
  reject = false;
  for (int i = 0; i < 9; i++)
    _position[i] = 2;
  firstPlayerMove = true;
   _children = new vector<State *> ();
   _parents = new vector<State *> ();
};

State::State(const State &s){
  this->final = s.final;
  for( int i = 0; i < 9; i++)
    this->_position[i] = s._position[i];

  // this->firstPlayerMove = s->firstPlayerMove;
  //  this->_children = s._children;
  final = false;
  reject = false;
  this->firstPlayerMove = !(s.firstPlayerMove);
}

void State::setStateChildren(State *s){
  _children->push_back(s);
}

void State::setStateParents(State *s){
    _parents->push_back(s);
}

vector<State*> *State::getChildren(){
  return _children;

}

vector<State*> *State::getParents(){
  return _parents;

}

void State::setFirstMove(bool b){
  firstPlayerMove = b;
}

bool State::firstMove(){
  return firstPlayerMove;
}

void State::setPosition(int p[]){

  for (int i = 0; i < 9; i++){
    // cout << "Set position " << i << " to " << p[i] << endl;
    _position[i] = p[i];

  }
  // cout << endl;
}

int *State::position(){
  return _position;
}


bool State::isFinal(){
  return final;
}

bool State::isReject(){
  return reject;
}

void State::setFinal(bool f){
  final = f;
}

void State::setReject(bool r){
  reject = r;
}

void State::print(){
  for(int i = 0; i < 9; i++)
    cout << "Position " << i << ": " << _position[i] << endl;
  if (firstPlayerMove)
    cout << "First Player Move" << endl;
  else
    cout << "Second Player Move" << endl;
  if (final)
    cout << "Final State" << endl;
  if (reject)
    cout << "Reject State" << endl;
  cout << endl;
  for (vector<State*>::iterator iter = _children->begin(); iter != _children->end(); iter++){
    (*iter)->print();
    }
}
