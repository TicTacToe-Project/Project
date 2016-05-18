#include "States.hpp"

State::State(){
  final = false;
  _numTurns = 0;
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
  /* for( int i = 0; i < 9; i++)
     this->_position[i] = s._position[i];*/
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

  /* for (int i = 0; i < 9; i++){
    _position[i] = p[i];

    }*/

  for (int i = 0; i < 9; i++){
    // cout << "Set position " << i << " to " << p[i] << endl;
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

void State::setNumTurns(int n){
  _numTurns = n;
}

int State::numTurns(){
  return _numTurns;
}

/*void State::find(State * root, int p[], State * child){
  if (root->isFinal() || root->isReject() || root->isDraw()){
    //  child = nullptr;
    return ;
  }
  
  for (vector<State*>::iterator iter = root->_children->begin(); iter != root->_children->end(); iter++){
    if(check((*iter)->position(), p)){
      (*iter)->print();
      child = new State(**iter);
      return;
    }
    find(*iter, p, child);
  } 
}


/*State *State::findhelper(State * root, int p[]){
  if (root == nullptr)
    return nullptr;
  for (vector<State*>::iterator iter = root->_children->begin(); iter != root->_children->end(); iter++){
    for (int i = 0; i < 9; i++)
      cout << (*iter)->position()[i] << " & " << p[i] << endl;
    if(check((*iter)->position(), p))
      return (*iter);
    return find((*iter), p);
  }
}
*/

/*bool State::check(int p[], int q[]){
  for( int i = 0; i < 9; i++){
    //    cout << "Checking " << p[i] << " & " << q[i] << endl;
    if (p[i] != q[i])
      return false;
  }
  // cout << "Returning turn" << endl;
  return true;
  }*/
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
