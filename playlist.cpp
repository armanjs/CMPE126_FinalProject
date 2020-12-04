/*
 * playlist.cpp
 *
 *  Created on: Nov 15, 2020
 *      Author: julianneto and armansadeghi
 */

#include "playlist.h"
#include "duration.h"
#include <algorithm>

playlist :: playlist(){
	head = NULL;
	tail = NULL;
	size = 0;
}

void playlist :: queue(track sng){ //add song to END of playlist
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

playlist playlist :: shuffle(){
int index;
track sng;
playlist shuffled;

for(int i = 0; i < size; i++){
  sng = findTrack(i);
  index = rand() % size;
    shuffled.add(sng, index);
  }
return shuffled;
}

void playlist::print(){
  int n = 1;
  node* temp = head;
  while (temp != NULL){
      cout << n << ". " << temp->song;
      temp = temp->next;
      n++;
  }
  if (size == 0){
      cout << "No songs in playlist." << endl;
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

void playlist :: add(track sng, int index){ //moves song
index = index - 1;
if (index == 0){ // if list is empty
        addFirst(sng);
    }
    else if (index >= size){
        cout << "Index is larger than size of playlist. Adding song to end of playlist" << endl;
        addLast(sng);
    }
    else{ // insert somewhere in the middle
        node* current = head;
        // find the correct index
        for (int i = 1; i < index; i++ ){
            current = current->next;
        }
        node* temp = current->next;
        // create a new node after temp
        current->next = new node;
        // set song to that temp
        current->next->song = sng;
        // link it with the next one
        (current->next)->next = temp;
        size++; // increment the size
        // link backwards
        temp->prev = current->next;
        current->next->prev = current;
        cout << "Adding " << sng << " to " << index << endl;
    }
}

track playlist::findTrack(int index) {
    node* temp = head;
    bool found = false;
    for (int i = 0; i < index ; ++i) {
        temp = temp->next;
    }
    if (temp != NULL){
        return temp->song;
    }
    else {
      track t1;
      cout << "Track not found" << endl;
      return t1; // connot return NULL smh
    }
} 

bool playlist::contains(string name1) {
    node* temp = head;
    while (temp != NULL){
        if (name1 == temp->song.name) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

duration playlist :: runTime(){
    node* temp = head;
    duration totalTime;

    for (int i = 0; i < size; i++){
        totalTime = totalTime + temp->song.time;
        temp = temp->next;
    }
    return totalTime;
}

track playlist::getLast(){
  return tail->song;
}

track playlist::getFirst(){
  return head->song;
}

track playlist::removeFirst() {
    if (size == 0){
        track trk;
        cout << "list is empty" << endl;
        return trk;
    }
    else {
        node* temp = head;
        head = head->next;
        size--;
        if (head == NULL){
            tail = NULL;
        }
        return temp->song;
    }
}

track playlist::removeLast() {
    if (size == 0){ // if nothing to remove
        track trk;
        cout << "list is empty" << endl;
        return trk;
    }
    else if (size == 1){
        node* temp = head;
        head = tail = NULL;
        size = 0;
        return temp->song;
    }
    else {
        node* current = head;
        for (int i = 0; i < size - 2; i++){
            current = current->next;
        }
        node* temp = tail;
        tail = current;
        tail->next = NULL;
        size--;
        return temp->song;
    }
    //return track();
}

track playlist::remove(int index) {
  index = index - 1;
    if (index < 0 || index >= size){
        cout << "index out of bounds" << endl;
        track trk;
        return trk;
    }
    if (index == 0){
        return removeFirst();
    }
    else if (index == size - 1){
       return removeLast();
    }
    else {
        node* previous = head;
        for (int i = 1; i < index; i++){
            previous = previous->next;
        }
        node* current = previous->next;
        previous->next = current->next;
        current->next->prev = previous;
        size--;
        return current->song;
    }
}
