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
	count = 0;
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
    int count = 1;
    while (head != NULL){
        cout << count << ") " << head->song << endl << endl;
        head = head->next;
        count++;
    }
    if (count == 0){
        cout << "List is empty." << endl;
    }
}

void playlist::add(track sng){
    // create a new node
    node* newNode = new node;
    // set the current node to stock
    newNode->song = sng;
    // link the newNode with the head
    newNode->next = head;
    // now head points to newNode
    head = newNode;
    // increase list size
    count++;
    // if the new node is the only node in the list
    if (tail == NULL){
        tail = head;
    }
    // update the head previous
    if (head != tail){
        head->next->prev = head;
    }
}
