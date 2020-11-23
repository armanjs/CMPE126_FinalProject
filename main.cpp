//============================================================================
// Name        : CMPE126_LabProject.cpp
// Author      : Julianne To and Arman Sadeghi
// Version     :
// Copyright   : Your copyright notice
// Description : Lab Project : Music Playlist
//============================================================================

//Objective: To design a music playlist using linked listss

#include <iostream>
#include "playlist.h"
#include "track.h"
#include <unistd.h>

using namespace std;

void displayTime(int min, int sec){
    system("clear");
    cout << min << " : " << sec << endl;
}

int main() {
  int input;
  playlist plst;
  playlist selections;

  //SONG OPTIONS
  track song1 ("woman", "John lenon", "Double fantasy", 1980, 3,32);
  track song2 ("Last Christmas", "Wham", "single", 1984, 4,23);
  track song3 ("Take you dancing", "Jason Derulo", "single", 2020, 3,11);
  track song4 ("Night Fever", "Bee Gees", "Greatest", 1979, 3,32);
  track song5 ("Vetement Socks" , "NAV", "Emergency Tsunami", 2020, 2,35);
  track song6 ("Clocks", "Coldplay", "A Rush of Blood to the Head", 2002,5,8);
  track song7 ("Believer", "Imagine Dragons", "Evolve", 2017, 3,24);
  track song8 ("Papaoutai", "Stromae", "Racine Carree", 2013,3,52);
  track song9 ("Shout", "Tears for Fears", "Songs From the Big Chair", 1985, 6, 34);
  track song10("Pump It", "Black Eyed Peas", "Monkey Business", 2005, 3,33);

  selections.queue(song1);
  selections.queue(song2);
  selections.queue(song3);
  selections.queue(song4);
  selections.queue(song5);
  selections.queue(song6);
  selections.queue(song7);
  selections.queue(song8);
  selections.queue(song9);
  selections.queue(song10);

  do{
  cout << "************* Juke Box Menu ***************" << endl;
  cout << "* 1. Queue song to playlist.              *" << endl;
  cout << "* 2. Skip song from playlist.             *" << endl;
  cout << "* 3. Move song to desired position.       *" << endl; 
  cout << "* 4. Repeat song.                         *" << endl;
  cout << "* 5. Shuffle playlist.                    *" << endl;
  cout << "* 6. Print playlist.                      *" << endl;
  cout << "* 7. Quit program.                        *" << endl;
  cout << "*******************************************" << endl;
  cout << "Your selection: ";
  cin >> input;
  cout << endl;

  switch(input){
    case 1:
    int sel;
    cout << "==================== Song Catalog ===================== " << endl;
    selections.print();
    cout << "\nSelect song to add to the playlist: ";
    cin >> sel;
    plst.queue(selections.findTrack(sel-1));
    cout << "Adding " << selections.findTrack(sel-1) << endl;
    break;
    case 2:
    cout << "=> Remove song from playlist" << endl;
    int pos;
    cout << "Enter the position of the song you'd like to skip: ";
    cin >> pos;
    plst.skip(pos);
    break;
    case 3:
    cout << "=> Moving song to desired location" << endl;
    int tmp;
    cout << "Position of song to move: ";
    cin >> tmp;
    plst.move(plst.findTrack(tmp), 5);
    break;
    case 4:
    cout << "=> Repeat song" << endl;
    break;
    case 5:
    cout << "=> Shuffling playlist" << endl;
    break;
    case 6:
    cout << "=> Current Playlist" << endl;
    plst.print();
    cout << "Duration: " << plst.runTime() << endl;
    break;
    case 7:
    cout << "Quitting program" << endl; 
    break;
    default:
    cout << "Invalid option, please enter a valid number." << endl;
    break;
    }
  }while(input != 7);
  
	return 0;
}
