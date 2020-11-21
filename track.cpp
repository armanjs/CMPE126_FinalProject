#include "track.h"

track :: track(){
    name = "";
    artist = "";
    album = "";
    duration = 0;
}

track :: track(string n, string a, string alb,  double dur){
    name = n;
    artist = a;
    album = alb;
    duration = dur;
}

ostream& operator<<(ostream& ofs, const track& obj) {
    ofs << "'" << obj.name << "' by " << obj.artist 
    << " in " << obj.album << " (" << obj.duration << ") " << endl;
    return ofs;
}