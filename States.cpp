#include "States.hpp"

State::State(){
  final = false;
  reject = false;
  draw = false;
  for (int i = 0; i < 9; i++)
      _position.push_back(2);
  firstPlayerMove = true;
   _children = new vector<State *> ();
   _parent = new vector<State *> ();
};

State::State(const State &s){
  this->final = s.final;
  this->_position = s._position;
  this->final = s.final;
  this->reject = s.reject;
  this->firstPlayerMove = s.firstPlayerMove;
  this->_children = s._children;
}

void State::setStateChildren(State *s){  
  _children->push_back(s);
}
vector<State*> *State::getChildren(){
  return _children;

}

void State::setStateParents(State *s){
  _parent->push_back(s);
}

vector<State*> *State::getParents(){
  return _parent;
}

void State::setFirstMove(bool b){
  firstPlayerMove = b;
}

bool State::firstMove(){
  return firstPlayerMove;
}

void State::setPosition(vector<int> *p){
  for (int i = 0; i < 9; i++){
    _position.at(i) = p->at(i);
  }
}
vector<int> *State::position(){
  return &_position;
}


bool State::isFinal(){
  return final;
}

bool State::isReject(){
  return reject;
}

bool State::isDraw(){
  return draw;
}

void State::setDraw(bool d){
  draw = d;
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
  if (draw)
    cout << "Draw" << endl;
  /* for (vector<State*>::iterator iter = _children->begin(); iter != _children->end(); iter++){
    (*iter)->print();
    }*/
}
