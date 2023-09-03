#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<iomanip>
#include<string>
#include "Song.h"
using namespace std;

Song::Song() {
	//FILES----------------
	textureFile = "txtrs/";
	songFile = "Songs/";
	//---------------------

	//Default constructor---
	songName = "Unknown";
	songFileName = "Unknown";
	singer = "Unknown";
	album = "Unknown";
	albumCover = "Unknown";
	genre = "Unknown";
	price = 0;
	stock = 0;
	openTexture = "Unknown";
	openSong = "Unknown";
	//-----------------------

}
Song::~Song() {

}

void Song::setFileInfo() {
	openSong = songFile + songFileName;
	openTexture = textureFile + albumCover;   
}

string Song::getAlbumCover() {
	return albumCover;
}
string Song::getFileName() {
	return songFileName;
}
//These set functions will be used in Account class
void Song::setAlbumCover(string a) {
	albumCover = a;
}
void Song::setAlbum(string a) {
	album = a;
}

void Song::setFileName(string a) {
	songFileName = a;
}

void Song::setGenre(string a) {
	genre = a;
}

void Song::setPrice(double a) {
	price = a;
}

void Song::setSinger(string a) {
	singer = a;
}

void Song::setSongName(string a) {
	songName = a;
}

void Song::setStock(int a) {
	stock = a;
}

string Song::getAlbum() {
	return album;
}

string Song::getGenre() {
	return genre;
}

string Song::getSongName() {
	return songName;
}

double Song::getPrice() {
	return price;
}

string Song::getSinger() {
	return singer;
}

int Song::getStock() {
	return stock;
}

void Song::printSong() {
	cout << songName << endl;;
}


void Song::drawAndPlay() {

	//Initializing UI elements -------------------------------------
	sf::RenderWindow window(sf::VideoMode(800, 300), "Music");
	sf::Event evnt;
	sf::Music music;
	sf::Text nowPlaying;
	sf::Text nowPaused;
	sf::Text songname;
	sf::Text albumName;
	sf::Text singerName;
	sf::Font font;
	sf::RectangleShape line(sf::Vector2f(130, 3));
	sf::RectangleShape picture(sf::Vector2f(200, 200));
	sf::CircleShape triangle(20, 3);
	sf::RectangleShape pauseButton(sf::Vector2f(10, 30));
	sf::RectangleShape pauseButton2(sf::Vector2f(10, 30));
	sf::RectangleShape greenStick(sf::Vector2f(500, 5));
	sf::Texture texture;
	sf::Texture* ptr;
	sf::Keyboard b;
	float volume;
	int counter = 0;
	//--------------------------------------------------------------

	
	//initializing texts and shapes---------------------------------
	font.loadFromFile("fnt/LEMONMILK-Light.otf");
	if (!texture.loadFromFile(openTexture)) {
		cout << "Cannot find the texture" << endl;
	}
	ptr = &texture;


	//Green stick
	greenStick.setFillColor(sf::Color(29, 185, 84));
	greenStick.setPosition(250, 130);

	//Pause
	pauseButton.setPosition(507, 155);
	pauseButton.setFillColor(sf::Color(179, 179, 179));
	pauseButton2.setPosition(487, 155);
	pauseButton2.setFillColor(sf::Color(179, 179, 179));
	//triangle
	triangle.setRotation(90);
	triangle.setFillColor(sf::Color(179, 179, 179));
	triangle.setPosition(520, 150);

	//divider
	line.setFillColor(sf::Color(29 ,185 ,84));
	line.setPosition(20, 30);

	//picture
	picture.setPosition(20, 50);
	picture.setTexture(ptr);

	//Now playing..
	nowPlaying.setFont(font);
	nowPlaying.setString("Now Playing..");
	nowPlaying.setPosition(20, 10);
	nowPlaying.setCharacterSize(15);
	nowPlaying.setFillColor(sf::Color(179, 179, 179));

	//Now Paused..
	nowPaused.setFont(font);
	nowPaused.setString("Now Paused..");
	nowPaused.setPosition(20, 10);
	nowPaused.setCharacterSize(15);
	nowPaused.setFillColor(sf::Color(179, 179, 179));
	//Song name
	songname.setFont(font);
	songname.setString(songName);
	songname.setFillColor(sf::Color::White);
	songname.setPosition(230, 50);
	songname.setCharacterSize(15);

	//Album
	albumName.setFont(font);
	albumName.setString(album);
	albumName.setFillColor(sf::Color(83, 83, 83));
	albumName.setPosition(230, 70);
	albumName.setCharacterSize(15);

	//Singer
	singerName.setFont(font);
	singerName.setString(singer);
	singerName.setFillColor(sf::Color(83, 83, 83));
	singerName.setPosition(230, 90);
	singerName.setCharacterSize(15);

	//--------------------------------------------------------------


	//Opening music from file and initializing----------------------

	volume = 20;
	music.openFromFile(openSong);
	music.setVolume(volume);
	music.play();
	//--------------------------------------------------------------
	while (window.isOpen()) {
		while (window.pollEvent(evnt)) {
			if (evnt.type == sf::Event::Closed) {
				window.close();
			}
		}
		
		window.clear(sf::Color(33, 33, 33));
		if (music.getStatus() == sf::Music::Playing) {
			window.clear(sf::Color(33, 33, 33));
			window.draw(greenStick);
			window.draw(pauseButton);
			window.draw(pauseButton2);
			window.draw(nowPlaying);
			window.draw(line);
			window.draw(picture);
			window.draw(songname);
			window.draw(singerName);
			window.draw(albumName);
			window.display();
			if (b.isKeyPressed(sf::Keyboard::P)) {
				window.draw(nowPaused);
				music.pause();
				music.setVolume(20);  //sorun olabilir
			}
		}
		if (music.getStatus() == sf::Music::Paused) {
			window.clear(sf::Color(33, 33, 33));
			window.draw(greenStick);
			window.draw(triangle);
			window.draw(nowPaused);
			window.draw(line);
			window.draw(picture);
			window.draw(songname);
			window.draw(singerName);
			window.draw(albumName);
			window.display();
			if (b.isKeyPressed(sf::Keyboard::R)) {
				music.play();
				music.setVolume(20); //sorun olabilir
			}
		}
	}
}

