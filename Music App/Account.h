#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Song.h"
#include "Album.h"
#include <string>

class Account {
private :
    string name;
    double balance;
    Album albums[13];
    Song songs[13];
    string password;
    char accountType;
public:

    virtual void calculateBalance();
    virtual void checkBalance();
    bool search(char type, string name, int ref);
    Account(char accountType);
    bool check_password(string input_password);
    void input(char a);
    Album* getAlbums();
    Song* getSongs();
    double getBalance();
    string getName();
    void setName(string n);
    string& get_password();
    void setBalance(double newBalance);
};

class Customer : public Account {
private: 
    int length;
    string favorite[3];
public:
    int count; 
    int temp;
    int counter;
    int ownedSong;
    int ownedAlbum;
    Song* act;
    Album* actual;
    int songList[5];
    Customer();        
    void favoriteGenres();
    void printFavoriteGenres();
    double calculateBalance(double fee);
    bool checkBalance(double fee);
    int makeSongList();
    int order(Song a, int ref);
    void order(Album a, int &ref);
    void showSongs();
    void showSongList();
    void updateBalance();
    void display();
    //~Customer();
};

class Manager : public Account {
public:
    Song *s;
    Album *a;
    string name;
    Manager(); 
    void set_password();
    void updateStock();
    void calculateBalance(double fee);
    void checkBalance();
    Song getSong(int index);
    Album getAlbum(int index);
    void displaySongs();
    void displayAlbums();
    void setStock(int newStock, int init, char type);
    void suggestRandomSong();
};

#endif // !ACCOUNT_H
