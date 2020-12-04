/*
 * playlist.h
 *
 *  Created on: Nov 11, 2020
 *      Author: julianneto and armansadeghi
 */

//LINKED LIST CLASS
#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include <iostream>
#include <string>
#include "track.h"
#include "duration.h"
using namespace std;

class node{
public:
	track song;
	node* next;
	node* prev;
};

class playlist{
	node* head;
	node* tail;

public:
	int size = 0;
	track current;

  playlist();
  void queue(track sng);
  void skip(int pos);
  void add(track sng, int pos);
  void previous();
  playlist shuffle();
  void repeat();
  void print(); //Print playlist
  void printCatalog(); //prints catalog layout
  void addFirst(track sng);
  void addLast(track sng);
  void add(int index, track sng);
  duration runTime();
  track getLast();
  track getFirst();
  track findTrack(int index);
  bool search(track* head, track song);
  bool contains(string name1);
  track removeFirst();
  track removeLast();
  track remove(int index);
};

#endif /* PLAYLIST_H_ */
