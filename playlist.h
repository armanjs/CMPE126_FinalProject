/*
 * playlist.h
 *
 *  Created on: Nov 11, 2020
 *      Author: julianneto
 */

//LINKED LIST CLASS

#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include <iostream>
#include <string>

#include "track.h"

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
	void skip(track sng);
	void move(track sng, int pos); //moves song
	void previous();
	void shuffle();
	void repeat();
	void print(); //Print playlist
  void addFirst(track sng);
  void addLast(track sng);
  void add(int index, track sng);
  track getLast();
  track getFirst();
  track findTrack(int index);

};

#endif /* PLAYLIST_H_ */
