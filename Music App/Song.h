#ifndef SONG_H
#define SONG_H
#include<string>
using namespace std;

class Song {
private:
	string songName; 
	string songFileName; 
	string singer; 
	string album; 
	string albumCover; 
	string genre; 
	double price;
	int stock;

	//For UI----------
	//File names
	string textureFile;
	string songFile;

	//Concatenated strings
	string openTexture;
	string openSong;
public:

	Song();
	void setAlbumCover(string a); //þarký jpg adý
	void setSongName(string a);
	void setFileName(string a); //þarký ogg adý
	void setSinger(string a);
	void setAlbum(string a);
	void setGenre(string a);
	void setPrice(double a);
	void setStock(int a);
	void setFileInfo();
	//silinecek------
	string getAlbumCover();
	string getFileName();
	//------------------
	string getSongName();
	string getSinger();
	string getAlbum();
	string getGenre();
	double getPrice();
	int getStock();
	void drawAndPlay();
	~Song();
	void printSong();

};


#endif // !SONG_H
