
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
  State getState();
  void setStateChildren(State *s);
  void setStateParents(State *s);
  vector<State*> *getChildren();
  vector<State*> *getParents();
  void setFirstMove(bool b);
  void setPosition(vector<int> *p);
  void setfirst();
  void setFirstMove();
  bool firstMove();
  string getFirstPlayer();
  vector<int> *position();
  bool isFinal();
  bool isReject();
  bool isDraw();
  void setDraw(bool d);
  void setFinal(bool f);
  void setReject(bool r);
  
  void print();
private:
  bool final;
  bool reject;
  bool firstPlayerMove;
  bool draw;
  vector<int> _position;
  vector<State*> *_parent;
  vector<State*> *_children;
};



#endif
