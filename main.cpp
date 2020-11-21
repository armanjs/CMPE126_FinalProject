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
  track song1 ("woman", "John lenon", "Double fantasy", 3.32);

  track song2 ("Last Chrismas", "Wham", "single", 4.23);

  track song3 ("Take you dancing", "Jason Derulo", "single", 3.11);
  playlist plst;
  plst.add(song1);
  plst.add(song2);
  plst.add(song3);

  plst.print();

  printJukebox();

	return 0;
}

void printJukebox(){
  
	cout << "************* Juke Box Menu ***************" << endl;
  cout << "* 1. Add song to playlist                 *" << endl;
  cout << "* 2. Skip song from playlist              *" << endl;
  cout << "* 3. Print current playlist               *" << endl;
  cout << "*******************************************" << endl;
}
