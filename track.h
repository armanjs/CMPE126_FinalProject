/*
 * song.h
 * Created on: Nov 11, 2020
 *      Author: julianneto and armansadeghi
 */

// NODE CLASS FOR TRACK/SONGS
#ifndef TRACK_H_
#define TRACK_H_
#include <iostream>
#include <string>
#include "duration.h"

using namespace std;

class track {
    
    string artist;
    string album;
    int year;

public:
    string name;
    track(); // default constructor
    track(string name, string artist, string alb, int y, int min, int sec); // constructor

    friend ostream& operator<<(ostream& ofs, const track& obj);
    duration time;
};

#endif /* TRACK_H_ */
