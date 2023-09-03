#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<string>
#include "Song.h"
#include "Album.h"

Album::Album() {
    howManySongs = 0;
    albumName = "Unknown";
    singerName = "Unknown";
    price = 0;
    stock = 0;
    howManySongs = 0;
    songs = new Song[4];
}


void Album::printSongs() {
    int i;
    for (i = 0; i < howManySongs; i++) {
        cout << songs[i].getSongName() << endl;
    }
}

void Album::setAlbumName(string a) {
    albumName = a;
}

void Album::setSinger(string a) {
    singerName = a;
}

void Album::setPrice() {
    int i;
    for (i = 0; i < howManySongs; i++) {
        price += songs[i].getPrice();
    }
}
void Album::setStock(int a) {
    stock = a;
}

void Album::setSongArray(Song a) {
    songs[howManySongs] = a;
    howManySongs++;
}

Song Album::getAlbumSong(int i) {
    return songs[i];
}

string Album::getAlbumName() {

    return albumName;
}
string Album::getSingerName()
{
    return singerName;
}
double Album::getPrice()
{
    return price;
}
int Album::getStock()
{
    return stock;
}

Album::~Album() {
    delete[] songs;
}