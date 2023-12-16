  /*
   * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
   * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
   */

  /* 
   * File:   main.cpp
   * Author: Freeman Yiu
   *
   * Created on 19 October 2023, 3:07 pm
   */

//All header files
  #include <cstdlib>
  #include <iostream>
  #include <iomanip>
  #include <cctype>
  #include <algorithm>
  #include <string>
  #include <map>
  #include <ctime>
  #include <queue>
  #include "Game.h"
  #include "Functions.h"

  using namespace std;

  /*
   * 
   */

  int main(int argc, char** argv) {
    srand(time(0));

      Game newGame;
      Player p1;
      PC p2;
      Graph g(10);
      newGame.mainMenu();
      p1.placement(newGame);
      p2.randomPlacement(newGame);

    newGame.drawGrid(p1,p2);
    while(!p1.lose()&&!p2.lose()){
      p1.updateGrid(newGame,p2,g);
      p2.updateGridE(newGame,p1,g);
      cout<<endl;
      newGame.drawGrid(p1,p2);
    }

    newGame.promptafterLosing(newGame,p1,p2);
      return 0;
  }

