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

void playlist :: queue(track sng){

}

void playlist :: skip(track sng){ //same as delete

}

void playlist :: move(track sng, int pos){ //moves song

}

void playlist :: previous(){

}

void playlist :: shuffle(){

}

void playlist :: repeat(){

}

void playlist::print(){
  int n = 1;
  node* temp = head;
  while (temp != NULL){
      cout << n << ") " << temp->song << endl;
      temp = temp->next;
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

void playlist::addLast(track sng) {
    node* newNode = new node;
    newNode->song = sng;
    node* temp = tail;
    if (tail == NULL){ // if list is empty
        head = tail = newNode;
    }
    else {
        // link the new node with the last
        tail->next = newNode;
        // tail is now pointing to the last element
        tail = tail->next;
    }
    size++; // increment the size
    tail->prev = temp; // link backwards
}

void playlist::add(int index, track sng) {
    if (index == 0){ // if list is empty
        addFirst(sng);
    }
    else if (index >= size){
        addLast(sng);
    }
    else{ // insert somewhere in the middle
        node* temp = head;
        // find the correct index
        for (int i = 1; i < index; i++ ){
            temp = temp->next;
        }
        node* temp1 = temp->next;
        // create a new node after temp
        temp->next = new node;
        // set song to that temp
        temp->next->song = sng;
        // link it with the next one
        (temp->next)->next = temp1;
        size++; // increment the size
        // link backwards
        temp1->prev = temp->next;
        temp->next->prev = temp;
    }
}

/*
track playlist::findTrack(int index) {
    node* temp = head;
    for (int i = 0; i < index ; ++i) {
        temp = temp->next;
    }
    if (temp != NULL){
        return temp->song;
    }
    else
        return NULL; // connot return NULL smh
} */

track playlist::getLast(){
  return tail->song;
}

track playlist::getFirst(){
  return head->song;
}
