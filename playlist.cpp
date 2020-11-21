/*
 * playlist.cpp
 *
 *  Created on: Nov 15, 2020
 *      Author: julianneto
 */

#include "playlist.h"

playlist :: playlist(){
	head = NULL;
	tail = NULL;
	size = 0;
}

void playlist :: queue(track song){

}

void playlist :: skip(track song){ //same as delete

}

void playlist :: move(track song, int pos){ //moves song

}

void playlist :: previous(){

}

void playlist :: shuffle(){

}

void playlist :: repeat(){

}

void playlist::print(){
  int n = 1;
  while (head != NULL){
      cout << n << ") " << head->song << endl;
      head = head->next;
      n++;
  }
  if (size == 0){
      cout << "List is empty." << endl;
  }
}

void playlist::addFirst(track sng){
  // create a new node
  node* newNode = new node;
  // set the current node to stock
  newNode->song = sng;
  // link the newNode with the head
  newNode->next = head;
  // now head points to newNode
  head = newNode;
  // increase list size
  size++;
  // if the new node is the only node in the list
  if (tail == NULL){
      tail = head;
  }
  // update the head previous
  if (head != tail){
      head->next->prev = head;
  }
}

track playlist::getLast(){
  return tail->song;
}

track playlist::getFirst(){
  return head->song;
}
