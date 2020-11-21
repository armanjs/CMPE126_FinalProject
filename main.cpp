//============================================================================
// Name        : CMPE126_LabProject.cpp
// Author      : Julianne To and Arman Sadeghi
// Version     :
// Copyright   : Your copyright notice
// Description : Lab Project : Music Playlist
//============================================================================

//Objective: To design a music playlist using linked lists and queues

#include <iostream>
#include "playlist.h"
#include "track.h"

using namespace std;

void printJukebox();

int main() {
  track song1 ("woman", "John lenon", "Double fantasy", 1980, 3.32);

  track song2 ("Last Christmas", "Wham", "single", 1984, 4.23);

  track song3 ("Take you dancing", "Jason Derulo", "single", 2020, 3.11);

  track song4 ("Night Fever", "Bee Gees", "Greatest", 1979, 3.32);
  
  playlist plst;
  plst.addFirst(song1);
  plst.addFirst(song2);
  plst.addFirst(song3);
  plst.addFirst(song4);
  plst.add(5, song2);

  plst.print();

  printJukebox();
  cout << plst.getLast();
  cout << plst.getFirst();

	return 0;
}

void printJukebox(){
  
	cout << "************* Juke Box Menu ***************" << endl;
  cout << "* 1. Add song to playlist                 *" << endl;
  cout << "* 2. Skip song from playlist              *" << endl;
  cout << "* 3. Print current playlist               *" << endl;
  cout << "*******************************************" << endl;
}
