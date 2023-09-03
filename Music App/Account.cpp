#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<string>
#include "Song.h"
#include "Album.h"
#include "Account.h"
#include <iomanip>
#include <fstream>
#include <time.h>

using namespace std;

//PARENT CLASS ACCOUNT-----------------------------------------------

Account::Account(char accountType) { //getting data depending on the account type 
    if (accountType == 'm') {
        accountType = 'm';
        password = "ad123"; //default password for manager
        ifstream inFile;
        string line;
        string songName;
        string songFileName;
        string singer;
        string album;
        string albumCover;
        string genre;
        double price;
        int counter = 1;
        int stock;
        inFile.open("ehe.txt");
        if (!inFile) { // file couldn't be opened
            cout << "Error: file could not be opened" << endl;
        }
        for (int i = 0; i < 13; i++) { //reading from file mechanism to assign values for both song and album data 
            getline(inFile, singer, '/');
            getline(inFile, album, '/');
            getline(inFile, songName, '/');
            getline(inFile, songFileName, '/');
            getline(inFile, albumCover, '/');
            getline(inFile, genre, '/');
            inFile >> price;
            inFile >> stock;
            songs[i].setSinger(singer);
            songs[i].setAlbum(album);
            songs[i].setSongName(songName);
            songs[i].setFileName(songFileName);
            songs[i].setAlbumCover(albumCover);
            songs[i].setGenre(genre);
            songs[i].setPrice(price);
            songs[i].setStock(stock);
            songs[i].setFileInfo();
        }
        inFile.close();
        inFile.open("ehe.txt");
        for (int i = 0; i < 13; i++) {
            int on = 1;
            getline(inFile, singer, '/');
            getline(inFile, album, '/');
            getline(inFile, songName, '/');
            getline(inFile, songFileName, '/');
            getline(inFile, albumCover, '/');
            getline(inFile, genre, '/');
            inFile >> price;
            inFile >> stock;
            albums[i].setSinger(singer);
            albums[i].setAlbumName(album);
            albums[i].setStock(stock);
        }
        inFile.close();
        for (int k = 0; k < 13; k++) { //to assign the songs to the albums that they are belong to
            for (int i = 0; i < 13; i++) {
                if (songs[k].getAlbum() == albums[i].getAlbumName())
                {
                    albums[i].setSongArray(songs[k]);
                }
            }
        }
        for (int k = 0; k < 13; k++) {     //setting album prices
            albums[k].setPrice();
        }
    }
    else if (accountType == 'c')
    {
        accountType = 'c';
        string password = "0";
    }
    balance = 0; //initalizing both balance and name variables to default values.
    name = "unknown";
}

void Account::calculateBalance() {  //these two methods in this sequence are both virtual and belong to the parent class. 
    cout << "Child class will implement this method" << endl; //parent class is abstract and these two methods are overloaded in the child classes  
                                                              //so the implementated code in the methods which are belong to the 'Account' do not matter
}

void Account::checkBalance() {
    cout << "Child class will implement this method" << endl;
}

bool Account::search(char type, string name, int ref) { //-----searching method-----checking the stocks to help to the function where its called from
    int i;
    if (type == 'a') { // 'a' for albums
        for (i = 0; i < 13; i++) {
            if (albums[i].getAlbumName() == name)
            {
                if (ref > 0) {

                    return true;
                }
            }
            else if (ref == 0) {
                return false;
            }
        }
    }
    else if (type == 's') { //'s' for songs
        for (i = 0; i < 13; i++) {
            if (songs[i].getSongName() == name) {
                if (ref > 0) {
                    return true;
                }
                else if (ref == 0) {
                    return false;
                }
            }
        }
    }
}

bool Account::check_password(string input_password) { //checking the password 
    if (password == input_password)
        return true;
    else
        return false;
}

void Account::input(char a) { //entering initial information for account types
    cout << "Please enter your name to create an account : ";
    cin >> name;
    if (a == 'c') {
        cout << "Please enter the balance you have: "; //setting balance for customer
        cin >> balance;
    }
    else if (a == 'e') {
        cout << "Balance has been set already!!" << endl; //Balance is set for manager in the constructor 
    }
}

void Account::setBalance(double newBalance) { //setting balance
    balance = newBalance;
}

Album* Account::getAlbums() { // returning albums
    return albums;
}

Song* Account::getSongs() { //returning songs
    return songs;
}

double Account::getBalance() { //returning balance
    return balance;
}

string Account::getName() { //returning name
    return name;
}

void Account::setName(string n) { //setting name
    name = n;
}

string& Account::get_password() { //returning password
    return password;
}

//END OF ACCOUNT--------------------------------------------------------------------------------------------



//Child class Customer

Customer::Customer() : Account::Account('c') { //initializing customer members
    count = 0;
    counter = 0;
    ownedSong = 0;
    ownedAlbum = 0;
    length = 0;
    act = getSongs(); //act and actual variables are both for the bought items that the customer gets from the shop
    actual = getAlbums(); // they are both initially declared as default
}

void Customer::favoriteGenres() { //assigning favorite genres of customer to the favorite genres list
    string temp = "admin"; //temporary value to get into the while loop below
    length = 0;
    cout << endl << "--------------------------------" << endl;
    cout << "Music is good when you know the genre of the music. It reveals new opportunities to discover new bands and songs." << endl;
    cout << "Genres that we have :" << endl;
    cout << "Metal" << endl << "Rock" << endl << "POP" << endl << "R&B" << endl << "Reggie" << endl << "Jazz" << endl << "Traditional" << endl;
    cout << "--------------------------------" << endl;
    while (temp != "Quit" && length < 3)
    {
        cout << "What are your favorite genres? -max 3 genres can be written- (enter 'Quit' when you see enough)" << endl;
        cout << "Enter the genre : ";
        cin >> temp;
        if (temp != "Quit") {
            favorite[length] = temp;
            length++;
        }

    }
}

void Customer::printFavoriteGenres() { //printing favorite genres
    for (int i = 0; i < length; i++) {
        cout << i + 1 << ". " << favorite[i] << endl;
    }
}


void Customer::updateBalance() { //updates the balance of the customer with the amount of money s/he wants to deposit
    double amount;
    cout << endl << endl << "Update Balance------------------" << endl;
    cout << "Your current balance is : " << this->getBalance() << "$" << endl;
    cout << "Enter the amount that you want to deposit : ";
    cin >> amount;
    this->setBalance(amount + this->getBalance());
    cout << "Transaction completed!! Thank you!!" << endl;
    cout << "Your new balance is : " << this->getBalance() << "$" << endl;
    cout << "------------------------------------" << endl;
}

double Customer::calculateBalance(double fee) { //calculating balance statue for in order to help 'order' function
    double balance = this->getBalance();
    if (checkBalance(fee)) { //to execute transaction, checking balance
        balance = balance - fee;
        cout << "Transaction completed!!" << endl;
        cout << "New Balance : " << balance << endl;
        return balance;
    }
    else {
        cout << "Sorry, not enough balance to pay!" << endl;
        cout << "Shopping Menu was closed." << endl;
        return balance;
    }
}

bool Customer::checkBalance(double fee) { //checking if the fee is greater or smaller than the balance
    if (this->getBalance() > fee) {
        return true;
    }
    else if (fee > this->getBalance()) {
        cout << "Your balance is falling short..  Please update your balance.." << endl;
        return false;
    }
}

int Customer::makeSongList() {
    //creates a songlist by using customer's songs and the preferences of customer relating with his owned songs
    for (int i = 0; i < 5; i++) {
        cout << "Enter the initial of the song that you want to add to the list -maximum 5 songname is acceptable-(enter 0 to finish the list): ";
        cin >> temp;
        if (temp != 0)
        {
            songList[count] = temp;
            count++;
        }
        else if (temp == 0)
        {
            break;
        }
        else
        {
            cout << "Please enter a valid input.\n";
            i--;
        }
    }
    return count;
}

int Customer::order(Song a, int ref) { //ordering from shop by functions with different parameters 
    if (search('s', a.getSongName(), ref)) { //this function is for songs
        act[ownedSong] = a;
        ownedSong++;
        ref--;
        return ref;
    }
    else {
        cout << "Not enough stock to buy! :(" << endl;
        return ref;
    }
}

void Customer::order(Album a, int& ref) { //this function is for albums

    if (search('a', a.getAlbumName(), ref)) {
        actual[ownedAlbum] = a;
        ownedAlbum++;
        ref--;

    }
    else {
        cout << "Not enough stock to buy! :(" << endl;

    }
}

void Customer::showSongs() { //shows the songs that costumer has and plays the song/s that the costumer wants to listen at that moment
    int option;
    int counterShowSongs = 0; //counts the number of songs that customer has 
    for (int i = 0; i < 13; i++) {
        if (act[i].getSongName() != "Unknown") { //if act[i] is not default -in other words if the costumer has bought item/s from the shop-
            counterShowSongs++;
        }
        else {
            break;
        }
    }

    if (counterShowSongs == 0) {
        cout << "No songs available" << endl;
    }

    else { //prints and plays available songs
        cout << setw(50) << endl << "Songs" << endl;
        cout << "-----------------------------------------------------------" << endl;
        for (int i = 0; i < counterShowSongs; i++) {
            cout << i + 1 << ". ";
            act[i].printSong();
        }
        do {
            cout << "Please enter the song number that you want to play (If you want to quit enter 0) : ";
            cin >> option;
            if (option != 0) {
                cout << endl << endl << "!!!WARNING!!!" << endl << "------------------" << endl;
                cout << "You can pause the song by pressing 'p' button" << endl << "You can resume the song by pressing 'r' button" << endl;
                cout << "But be careful!" << endl << "When the pause or resume key is pressed, the keys might be perceived as inputs automatically." << endl;
                cout << "In order to continue: When the song is stopped (simply wait the song to finish or close the window)" << endl << "delete the p's and r's" << endl;
                cout << "------------------" << endl;
                act[option - 1].drawAndPlay();
            }
        } while (option != 0);
    }
}


void Customer::display() { //shows the songs that belongs to the customer
    int counterShowSongs = 0;
    for (int i = 0; i < 13; i++) {
        if (act[i].getSongName() != "Unknown") {
            counterShowSongs++;
        }
        else {
            break;
        }
    }

    if (counterShowSongs == 0) { //if costumer hasnt got any songs yet 
        cout << "No songs available" << endl;
    }

    else {
        cout << setw(50) << endl << "Songs" << endl;
        cout << "-----------------------------------------------------------" << endl;
        for (int i = 0; i < counterShowSongs; i++) {
            cout << i + 1 << ". ";
            act[i].printSong();
        }
    }
}

void Customer::showSongList() { // plays a song by user choice from the created  playlist with the help of makeSongList() 
    int option;
    int counter;
    display();
    counter = makeSongList(); //taking the number of songs that have been added to the play list 
    cout << left << setw(30) << endl << "My Songs" << endl;
    cout << "-----------------------------------------------------------" << endl;
    for (int i = 0; i < counter; i++) {
        cout << left << setw(30) << act[songList[i] - 1].getSongName() << endl;
    }
    cout << endl;
    do {
        cout << "Please enter the song number that you want to play (If you want to quit enter 0) : ";
        cin >> option;
        if (option > counter) {
            while (option > counter) {
                cout << "Invalid input please try again : ";
                cin >> option;
            }
        }
        if (option != 0) {
            act[songList[option - 1] - 1].drawAndPlay();
        }
    } while (option != 0);
    cout << "Exitted" << endl;
}
//END OF CUSTOMER--------------------------------------------------------------------------------------------------------------------------------------


//Child class Manager

Manager::Manager() : Account::Account('m') { //getting manager's data from the parent class
    s = getSongs();
    a = getAlbums();
}

void Manager::set_password() { //setting new password 
    string pass;
    cout << "Please create a new password as a manager: ";
    cin >> pass;
    get_password() = pass;
}


void Manager::updateStock() { //updating the stocks by manager's choices 
    char choice;
    int temp;
    int num;
    cout << "Please choose the stock type you want to change, write 'a' for album, 's' for song: ";
    cin >> choice;
    if (choice == 'a') { //'a' for albums

        this->displayAlbums();
        cout << endl << "Please enter initial of the album : ";
        cin >> num;
        cout << endl << "Please enter the new stock for album: ";
        cin >> temp;
        a[num - 1].setStock(temp);
    }
    else if (choice == 's') { //'s' for songs
        this->displaySongs();
        int num;
        cout << endl << "Please enter the initial of the song : ";
        cin >> num;
        cout << endl << "Please enter the new stock for song: ";
        cin >> temp;

        s[num - 1].setStock(temp);
    }
    else
        cout << "You entered a wrong letter for type, you are directed to the main menu." << endl;
}

void Manager::calculateBalance(double fee) { //calculating the balance of manager by getting the customer's money transaction
    double temp;
    temp = this->getBalance() + fee;
    this->setBalance(temp);
}

void Manager::checkBalance() { //prints the current balance of manager
    cout << "Total= " << this->getBalance() << " $" << endl;
}

Song Manager::getSong(int index) {   //returns a spesific song related with the index   
    s = this->getSongs();
    return  s[index - 1];
}

Album Manager::getAlbum(int index) { //returns a spesific album related with the index
    a = this->getAlbums();
    return a[index - 1];
}

void Manager::displaySongs() { //prints the songs' information
    cout << left << setfill(' ') << setw(31) << "Songs" << setw(15) << "Stock" << endl;
    cout << "---------------------------------------------" << endl;
    for (int i = 0; i < 13; i++) {
        cout << left << setfill(' ') << i + 1 << "." << setw(31) << s[i].getSongName() << s[i].getStock() << endl;
    }
}

void Manager::displayAlbums() { //prints the albums' information
    cout << left << setfill(' ') << setw(31) << "Album" << setw(15) << "Stock" << endl;
    cout << "---------------------------------------------" << endl;
    for (int i = 0; i < 13; i++) {
        cout << left << setfill(' ') << i + 1 << "." << setw(31) << a[i].getAlbumName() << a[i].getStock() << endl;
    }
}

void Manager::setStock(int newStock, int init, char type) { //setting new stocks based on customer's transactions
    if (type == 'a') {
        a[init - 1].setStock(newStock);
    }
    else if (type == 's') {
        s[init - 1].setStock(newStock);
    }
}

void Manager::suggestRandomSong() { //suggests a random song based on the favorite genre list of the customer
    srand((unsigned int)time(NULL));
    int randomVariable;
    int counter = 0;
    string temp;
    Song tempArray[5];

    int i;
    cout << "Please!! type exact name of the genre given above that you want to get a suggested song: ";
    cin >> temp;


    //Assigning Songs-----------------------
    for (i = 0; i < 13; i++) {
        if (s[i].getGenre() == temp) {
            tempArray[counter] = s[i];
            counter++;
        }
    }
    //----------------------------------

    //Initialize random variable-----------------------
    randomVariable = rand() % counter + 0;

    //Suggest
    tempArray[randomVariable].drawAndPlay();
    cout << endl << endl << "!!!WARNING!!!" << endl << "------------------" << endl;
    cout << "You can pause the song by pressing 'p' button" << endl << "You can resume the song by pressing 'r' button" << endl;
    cout << "But be careful!" << endl << "When the pause or resume key is pressed, the keys will automatically perceived as inputs." << endl;
    cout << "In order to continue: When the song is stopped (simply wait the song to finish or close the window)" << endl << "delete the p's and r's" << endl;
    cout << "------------------" << endl;
    cout << "You can always check our shop to purchase this song. If the rythm of the song got your soul." << endl;

}
