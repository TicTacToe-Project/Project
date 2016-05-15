
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
  bool isDraw();
  void setDraw(bool d);
  void setFinal(bool f);
  void setReject(bool r);
  State *find(State * root, int p[]);
  bool check(int p[], int q[]);
  void print();
private:
  bool final;
  bool reject;
  bool firstPlayerMove;
  bool draw;
  int _position[9];
  vector<State*> *_children;
};



#endif
