#ifndef ALBUM_H
#define ALBUM_H
#include <string>
#include "Song.h"

using namespace std;

class Album
{
private:
    string albumName;
    string singerName;
    double price;
    int stock;
    Song* songs;
public:
    int howManySongs;
    void setAlbumName(string a);
    void setSinger(string a);
    void setPrice();
    void setStock(int a);
    Album();
    Song getAlbumSong(int i); 
    void setSongArray(Song a);
    string getAlbumName();
    string getSingerName();
    double getPrice();
    int getStock();
    void printSongs();
    ~Album();
    

};
#endif //ALBUM_H