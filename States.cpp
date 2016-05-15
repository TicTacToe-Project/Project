#include "States.hpp"

State::State(){
  final = false;
  reject = false;
  draw = false;
  for (int i = 0; i < 9; i++)
    _position[i] = 2;
  firstPlayerMove = true;
   _children = new vector<State *> ();
};

State::State(const State &s){
  this->final = s.final;
  for( int i = 0; i < 9; i++)
    this->_position[i] = s._position[i];
  final = false;
  reject = false;
  this->firstPlayerMove = !(s.firstPlayerMove);
}

void State::setStateChildren(State *s){  
  _children->push_back(s);
}
vector<State*> *State::getChildren(){
  return _children;

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


State *State::find(State * root, int p[]){
  if (root == nullptr)
    return nullptr;
  for (vector<State*>::iterator iter = root->_children->begin(); iter != root->_children->end(); iter++){
     if(check((*iter)->position(), p))
       return (*iter);
     return find((*iter), p);
  }
  //return nullptr;
}

bool State::check(int p[], int q[]){
  for( int i = 0; i < 9; i++)
    if (p[i] != q[i])
      return false;
  return true;
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
 for (vector<State*>::iterator iter = _children->begin(); iter != _children->end(); iter++){
    (*iter)->print();
    }
}
