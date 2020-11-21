/*
 * song.h
 * Created on: Nov 11, 2020
 *      Author: julianneto
 */

// NODE CLASS FOR TRACK/SONGS
#ifndef TRACK_H_
#define TRACK_H_
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class track {
    string name;
    string artist;
    string album;
    double duration;

public:
    track(); // default constructor
    track(string name, string artist, string alb, double duration); // constructor

    friend ostream& operator<<(ostream& ofs, const track& obj);
};


#endif /* TRACK_H_ */
