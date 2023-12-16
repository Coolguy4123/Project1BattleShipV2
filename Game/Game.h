/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt
 * to change this license Click
 * nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this
 * template
 */

/*
 * File:   Game.h
 * Author: Freeman Yiu
 *
 * Created on 19 October 2023, 3:08 pm
 */
// Header files
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <string>
#ifndef GAME_H
#define GAME_H
using namespace std;

// Declare classes here
// Since some Game member function require both classes, declare here to solve
// the problem
class PC;
class Player;
class Node;
class Tree;
class Graph;

// Class Game with its members and members function
class Game {
protected:
  char **arr;
  int* horzRow;
  char* vertCol;
  queue<string> log;
  stack<int> numMoves;

public:
  Game();
  ~Game();
  void mainMenu();
  void prompt();
  void drawGrid(Player&,PC&);
  void setGrid();
  void setPos(int, int, char);
  void insertLog(string);
  void printLogs();
  void pushStack();
  void promptafterLosing(Game &, Player, PC);
  char getPos(int, int);
  char getLetter(int);
  friend class Player;
  friend class PC;
};

// Second class named Player
// This class is based on the user
class Player {
private:
  map<char, int> ships;
  Tree* fbc;
  int* bvect;
  
public:
  Player();
  bool lose();
  void placement(Game &);
  void updateGrid(Game &, PC &,Graph&);
  void deductHealth(char);
  void printDestroyedShip(char);
  bool collides(Game &, int, int, int);
  bool pHit(Game &,int,int);
  int phash(char,int);
  int shipCount();
  friend class Game;
  friend class PC;
  friend class Tree;
  friend class Graph;
};

// Third class named PC
// This class refers to the enemy
// It will choose points randomly without colliding
class PC {
private:
  map<char, int> eships;
  Tree* efbc;
  int* ebvect;

public:
  PC();
  bool lose();
  void randomPlacement(Game &);
  void updateGridE(Game &, Player &,Graph &);
  void edeductHealth(char);
  void eprintDestroyedShip(char);
  int ehash(char,int);
  int eshipCount();
  bool eHit(Game &,int,int);
  friend class Game;
  friend class Player;
  friend class Tree;
};

class Node{
public:
    char val;
    Node* left;
    Node* right;
    Node(char c){
        val=c;
        left=NULL;
        right=NULL;
    }
};

class Tree{
public:
    Node* root;
    Tree(){
        root=NULL;
    }
    ~Tree(){
        delete root;
    }
    int hdiff(Node*);
    int height(Node*);
    bool find(Node*,char);
    Node* insert(Node*,char);
    Node* balance(Node*);
    Node* ll_rot(Node*);
    Node* lr_rot(Node*);
    Node* rr_rot(Node*);
    Node* rl_rot(Node*);
};

class Graph{
private: 
    int v;
    map<pair<char,char>,int>ctoi;
public:
    Graph(int num){
        v=num;
        for(int i=0;i<v;i++){
            ctoi[{'A','A'+i}]=i;
        }
    };
    int findweight(pair<char,char>);
};

#endif /* GAME_H */
