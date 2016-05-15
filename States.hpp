
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
  void setStateParents(State *s);
  vector<State*> *getChildren();
  State* getChildren(int i);
  vector<State*> *getParents();
  State* getParents(int i);
  void setFirstMove(bool b);
  void setPosition(vector<int> *p);
  void setfirst();
  void setFirstMove();
  bool firstMove();
  string getFirstPlayer();
  vector<int> *position();
  bool isFinal();
  bool isReject();
  void setFinal(bool f);
  void setReject(bool r);
  void print();

private:
  bool final;
  bool reject;
  bool firstPlayerMove;
  /// bool tie;
  ///  vector<int> * _position;
  vector<int> _position;/// = {2, 2, 2, 2, 2, 2, 2, 2, 2};
  vector<State*> _children;
  vector<State*> _parents;
};



#endif
