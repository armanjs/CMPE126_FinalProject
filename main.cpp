//============================================================================
// Name        : CMPE126_LabProject.cpp
// Author      : Julianne To and Arman Sadeghi
// Version     :
// Copyright   : Your copyright notice
// Description : Lab Project : Music Playlist
//============================================================================

//Objective: To design a music playlist using linked lists

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
  track song11;

  do{
  cout << "************* Juke Box Menu ***************" << endl;
  cout << "* 1. Queue/add song to playlist.          *" << endl;
  cout << "* 2. Add to the beginning of the list.    *" << endl;
  cout << "* 3. Add to the end of the list           *" << endl;
  cout << "* 4. Queue/add song to specific position. *" << endl; 
  cout << "* 5. Shuffle playlist.                    *" << endl;
  cout << "* 6. Print playlist.                      *" << endl;
  cout << "* 7. Playlist duration.                   *" << endl;
  cout << "* 8. Search playlist.                     *" << endl;
  cout << "* 9. Remove first song.                   *" << endl;
  cout << "* 10. Remove last song.                    *" << endl;
  cout << "* 11. Remove song at specified index.     *" << endl;
  cout << "* -1. Quit program.                       *" << endl;
  cout << "*******************************************" << endl;
  cout << "Your selection: ";
  cin >> input;
  cout << endl;

  string search;

  switch(input){
    case 1:
    int sel;
    int pos;
    cout << "========================== Song Catalog =========================== " << endl;
    selections.print();
    cout << "\nSelect song to add to the playlist: ";
    cin >> sel;
    plst.queue(selections.findTrack(sel-1));
    cout << "Adding " << selections.findTrack(sel-1) << endl;
    break;
    case 2:
     cout << "========================== Song Catalog =========================== " << endl;
    selections.print();
    cout << "\nSelect song to add to the biginning of the playlist: ";
    cin >> sel;
    plst.addFirst(selections.findTrack(sel-1));
    cout << "Adding " << selections.findTrack(sel-1) << endl;
    break;
    case 3:
    cout << "========================== Song Catalog =========================== " << endl;
    selections.print();
    cout << "\nSelect song to add to the end of the playlist: ";
    cin >> sel;
    plst.addLast(selections.findTrack(sel-1));
    cout << "Adding " << selections.findTrack(sel-1) << endl;
    break;
    case 4:
    cout << "=> Queue song to specific position" << endl;
    cout << "========================== Song Catalog =========================== " << endl;
    selections.print();
    cout << "\nSelect song to add to the playlist: ";
    cin >> sel;
    /*
    if(sel > selections.size){
      cout << "Track not found. " << endl;
      break;
    } */
    cout << "Position to move to: ";
    cin >> pos;
    /*
    if(pos > plst.size){
      cout << "Position not found. " << endl;;
      break;
    }*/
    plst.add(selections.findTrack(sel-1), pos);
    break;
    case 5:
    cout << "=> Shuffling playlist" << endl;
    plst.shuffle();
    break;
    case 6:
    cout << "=> Current Playlist" << endl;
    plst.print();
    cout << "Duration: " << plst.runTime() << endl;
    break;
    case 7:
    cout << "The playlist run time is: " << plst.runTime().minute << " minutes and "
    << plst.runTime().second << " seconds." << endl;
    break;
    case 8:
    cout << "Enter the name of the song to be seached for: ";
    cin >> search;
    if (plst.contains(search)){
      cout << "the song " << search << " exists in your playlist." << endl;
    }
    else {
      cout << "The searched song was not found in your playlist" << endl;
    }
    break;
    case 9:
    cout << plst.removeFirst() << " has been removed from list." << endl;
    break;
    case 10:
    cout << plst.removeLast() << " has been removed from list." << endl;
    break;
    case 11:
    cout << "enter the index of the song you wish to remove: ";
    cin >> pos;
    cout << plst.remove(pos) << " has been removed from your list." << endl;
    break;
    case -1:
    cout << "Quitting program" << endl; 
    break;
    default:
    cout << "Invalid option, please enter a valid number." << endl;
    break;
    }
  } while(input != -1);
  
	return 0;
}
