#include "track.h"

track :: track(){
    name = "";
    artist = "";
    album = "";
    year = 0;
    duration = 0;
}

track :: track(string n, string a, string alb, int y, double dur){
    name = n;
    artist = a;
    album = alb;
    year = y;
    duration = dur;
}

ostream& operator<<(ostream& ofs, const track& obj) {
    ofs << "'" << obj.name << "' by " << obj.artist 
    << " in " << obj.album << " (" << obj.year << ") " << endl;
    return ofs;
}