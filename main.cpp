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

void printMenu(){
cout << "\n************* Juke Box Menu ***************" << endl;
  cout << "* 1. Queue song to end of playlist.       *" << endl;
  cout << "* 2. Queue song to beginning of playlist. *" << endl;
  cout << "* 3. Queue song to specified index.        *" << endl; 
  cout << "* 4. Shuffle playlist.                    *" << endl;
  cout << "* 5. Print playlist.                      *" << endl;
  cout << "* 6. Playlist duration.                   *" << endl;
  cout << "* 7. Search playlist.                     *" << endl;
  cout << "* 8. Remove first song.                   *" << endl;
  cout << "* 9. Remove last song.                    *" << endl;
  cout << "* 10. Remove song at specified index.     *" << endl;
  cout << "* 11. Add your own song at index.         *" << endl;
  cout << "* 12. Play song (no audio)                *" << endl;
  cout << "* 13. Print menu options.                 *" << endl;
  cout << "* -1. Quit program.                       *" << endl;
  cout << "*******************************************" << endl;
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
  track song11("The Girl", "City adn Colour", "Bring Me Your Love", 2008, 5, 59);
  track song12("Gimme Love", "Joji", "Gimme Love", 2020, 3, 15);
  track song13("Tongue Tied", "Group Love", "Never Trust a Happy Song", 2011, 4, 20);
  track song14("t-shirt", "boy pablo", "Soy Pablo", 2018, 2, 47);
  track song15("Forrest Gump", "Frank Ocean", "channel ORANGE", 2012, 3, 15);

//Creates catalog
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
  selections.queue(song11);
  selections.queue(song12);
  selections.queue(song13);
  selections.queue(song14);
  selections.queue(song15);

  printMenu();
  
  do{
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
    cout << "\nSelect song to add to the beginning of the playlist: ";
    cin >> sel;
    plst.addFirst(selections.findTrack(sel-1));
    cout << "Adding " << selections.findTrack(sel-1) << endl;
    break;

    case 3:
    cout << "=> Queue song to specific index" << endl;
    cout << "========================== Song Catalog =========================== " << endl;
    selections.print();
    cout << "\nSelect song to add to the playlist: ";
    cin >> sel;
    if(0 < sel && sel < selections.size){ // Check if valid song
      cout << "Position to move to: ";
      cin >> pos;   
      plst.add(selections.findTrack(sel-1), pos);
    }else{
      cout << "Song is not found." << endl;
    }
    break;

    case 4:
    cout << "=> Shuffling playlist" << endl;
    cout << "\nOriginal playlist: " << endl;
    plst.print();
    cout << "\nShuffled playlist: " << endl;
    plst = plst.shuffle();
    plst.print();
    break;

    case 5:
    cout << "=> Current Playlist" << endl;
    plst.print();
    cout << "Duration: " << plst.runTime() << endl;
    break;

    case 6:
    cout << "The playlist run time is: " << plst.runTime().minute << " minutes and "
    << plst.runTime().second << " seconds." << endl;
    break;

    case 7:
    cout << "Enter the name of the song to be seached for: ";
    cin.ignore();
    getline(cin, search);
    if (plst.contains(search)){
      cout << "The song " << "'" << search << "'" << " exists in your playlist." << endl;
    }
    else {
      cout << "The searched song was not found in your playlist" << endl;
    }
    break;

    case 8:
    cout << plst.removeFirst() << " has been removed from list." << endl;
    break;

    case 9:
    cout << plst.removeLast() << " has been removed from list." << endl;
    break;

    case 10:
    cout << "Enter the index of the song you wish to remove: ";
    cin >> pos;
    cout << plst.remove(pos) << " has been removed from your list." << endl;
    break;

    case 11: {
    string name, album, artist;
    int year = 0, minute = 0, second = 0, index = 0;
    cout << "Welcome to the track adder!" << endl;
    cout << "Please enter the name of the track: ";
    cin.ignore();
    getline(cin, name);
    cout << "Name of the artist: ";
    getline(cin, artist);
    cout << "Name of the album: ";
    getline(cin, album);
    cout << "Release year: ";
    cin >> year;
    cout << "Number of minutes: ";
    cin >> minute;
    cout << "Number of seconds: ";
    cin >> second;
    cout << "Index to be added to: ";
    cin >> index;
    track song12(name,artist,album,year,minute,second);
    plst.add(song12,index);
    cout << song12 << " has been added to playlist" << endl;
    }
    break;

    case 12:{
    plst.print();
    cout << "Enter the index of the track you wish to play: ";
    cin >> pos;
    int seconds = plst.findTrack(pos - 1).time.second;
    int minutes = plst.findTrack(pos - 1).time.minute;
    int runtime = seconds + minutes * 60;
    cout << "Now playing: " << plst.findTrack(pos - 1);
    cin.ignore();
    while (runtime > 0){
      sleep(1);
      seconds--;
      if (seconds == -1){
        minutes--;
        seconds = 59;
      }
      system("clear");

      if (seconds >= 10){
        cout << "Now playing: " << plst.findTrack(pos - 1) 
        << " " << minutes << " : " << seconds << endl;
      }
      else {
        cout << "Now playing: " << plst.findTrack(pos - 1) 
       << " " << minutes << " : 0" << seconds << endl;
      }
      runtime--;
    }
    }

    break;

    case 13:
    printMenu();
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
