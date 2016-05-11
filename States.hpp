
#ifndef STATE_HPP
#define STATE_HPP

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class State{
public:
  State();
  State(const State &s);
  //~State;
  State getState();
  void setStateChildren(State *s);
  vector<State*> *getChildren();
  void setFirstMove(bool b);
  void setPosition(int p[]);
  void setfirst();
  void setFirstMove();
  bool firstMove();
  string getFirstPlayer();
  int *position();
  bool isFinal();
  bool isReject();
  void setFinal(bool f);
  void setReject(bool r);
  void print();
private:
  bool final;
  bool reject;
  bool firstPlayerMove;
  // bool tie;
  //  vector<int> * _position;
  int _position[9];// = {2, 2, 2, 2, 2, 2, 2, 2, 2};
  vector<State*> *_children;
};



#endif
