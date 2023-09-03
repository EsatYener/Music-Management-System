/////////////////////////////////////////////////////////////////////////////
////**********************************************************************///
////* Description: Music Management System                               *///
////* Authors : Esat Yener / Simay Yasar / Tulya Aytekin / Batuhan Dilek *///
////* Number : 201811065 / 201811062 / 201811008 / 201911023             *///
////* Date   : 28.12.2020                                                *///
////**********************************************************************///
/////////////////////////////////////////////////////////////////////////////



#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<iomanip>
#include<string>
#include "Song.h"
#include "Album.h"
#include "Account.h"
#include<time.h>
#include<fstream>
#include<cstring>


using namespace std;

int main() {

	Manager main;
	main.setBalance(1000);
	Customer c;
	int choice;
	string pass;
	int count = 0, result = 0;
	int controlCounterManager = 0;
	int controlCounterCustomer = 0;
	char choiceChar;
	int i;
	int correct;
	cout << "Please select account type to sign in : " << endl;
	cout << "'m' for Manager" << endl << "'c' for Customer  " << endl << "'q' for exit from the main program" << endl;
	cout << "choice : ";
	cin >> choiceChar;

	while (choiceChar != 'q' && choiceChar != 'Q') {

		if (choiceChar == 'm' || choiceChar == 'M')
		{
			
			cout << "Enter password: ";
			cin >> pass;
			while (count < 3)
			{
				if (main.check_password(pass))
				{
					result = 1;
					break;
				}
				else
				{
					count++;
					cout << "Please try again. You have " << 4 - count << " attempts left." << endl;
				}
				cout << "Enter password: ";
				cin >> pass;
			}
			if (result == 1)
			{
				int choiceManager;

				cout << "Entered as manager" << endl;
				controlCounterManager++;
				if (controlCounterManager == 1) {
					main.set_password(); //RESET PASSWORD
					main.input('e');
					cout << endl << setfill('*') << setw(56) << "" << endl;
					cout << setfill(' ') << setw(30) << "Welcome " << main.getName() << setfill('*') << setw(20) << endl;
					cout << setfill('*') << setw(56) << "" << endl;
				}
				do {

					//MANAGER-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
					cout << endl << endl;
					/*if (controlCounterManager >= 1) {
						cout << setfill('*') << setw(56) << "" << endl;
						cout << setfill(' ') << setw(30) << "Welcome " << main.getName() << setfill('*') << setw(20) << endl;
						cout << setfill('*') << setw(56) << "" << endl;
					}*/
					cout << "----------------------MENU----------------------" << endl;
					cout << "1. Update stock" << endl << "2. Display balance" << endl << "3. Display Stocks" << endl << "4. Change Password" << endl << "5. Exit" << endl;
					cout << "Option : ";
					cin >> choiceManager;
					while (choiceManager != 1 && choiceManager != 2 && choiceManager != 3 && choiceManager != 4 && choiceManager != 5) {
						cout << "Please enter a valid input: ";
						cin >> choiceManager;
					}
					if (choiceManager == 1) {
						cout << endl << "Update Stock-------------------" << endl;
						main.updateStock();
					}
					else if (choiceManager == 2) {
						cout << endl << "Display balance------------------" << endl;
						main.checkBalance();
					}
					else if (choiceManager == 3) {
						int displayChoice;
						cout << endl << "Display Stocks-----------------" << endl;
						cout << "1. Display Songs" << endl << "2. Display albums" << endl;
						cout << "Option : ";
						cin >> displayChoice;
						if (displayChoice == 1) {
							cout << endl << endl;
							main.displaySongs();
						}
						else if (displayChoice == 2) {
							cout << endl << endl;
							main.displayAlbums();
						}
					}
					else if (choiceManager == 4) {
						main.set_password();
					}
					else if (choiceManager == 5)
					{
						cout << "Exitted!!" << endl;
						break;
					}


					//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
				} while (choiceManager != 6);
			}
			else
			{
				cout << "Cannot log into manager!! " << endl;
				choiceChar = 'c';
				cout << "You will be directed to the customer page " << endl;
			}
		}
		else if (choiceChar == 'c' || choiceChar == 'C') {
			
			//CUSTOMER-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
			//Customer c;
			cout << "You've entered the system as customer " << endl;
			controlCounterCustomer++;
			if (controlCounterCustomer == 1) {
				c.input('c');
			}

			cout << endl << endl;
			cout << setfill('*') << setw(56) << "" << endl;
			cout << setfill(' ') << setw(20) << "Welcome " << c.getName() << setfill('*') << setw(20) << endl;
			cout << setfill('*') << setw(56) << "" << endl;
			//cout << "Welcome " << c.getName() << endl;
			cout << endl << "--------------------------MENU--------------------------" << endl;
			cout << "1. Show the songs that I've bought" << endl;
			cout << "2. Make a playList" << endl;
			cout << "3. Shop" << endl;
			cout << "4. Make a favourite genre list" << endl;
			cout << "5. Make random suggestion" << endl;
			cout << "6. Update Balance" << endl;
			cout << "7. Exit" << endl;
			cout << "Please enter the choice you want to execute :) : ";
			cin >> choice;
			while (choice != 7) {
				if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6) {
					cout << "Invalid input. try again" << endl;
					continue;
				}
				if (choice == 1) {
					c.showSongs();
				}

				else if (choice == 2) {
					//c.showSongs();
					c.showSongList();

				}
				else if (choice == 3) {
					int shopChoice;
					//int orderMain;
					int init;
					int newStock; // variable to update stock
					double priceMain;
					bool balanceStatue;
					//Shop-------------------------------------------------------------------------------
					do {
						cout << "--------------------------SHOP--------------------------" << endl;
						cout << "1. Albums list" << endl << "2. Songs list" << endl << "3. EXIT" << endl << endl;
						cout << "Which one do you want to display : ";
						cin >> shopChoice;
						if (shopChoice != 1 && shopChoice != 2 && shopChoice != 3){
							cout << "Invalid input. Redirecting to main menu >:(" << endl;
							break;
						}



						//Display Songs******************************************************************
						if (shopChoice == 2) {
							main.displaySongs();
							Song tempSong;
							do {
								cout << endl << "Enter the song initial to purchase it (enter 0 to quit) : ";
								cin >> init;
								while (init > 13 || init < 0) {
									cout << "Invalid input." << endl;
									cout << "Enter the song initial to purchase it (enter 0 to quit) : ";
									cin >> init;
								}
								if (init != 0) {
									tempSong = main.getSong(init);   //Temporary song to be able to get and calculate price
									priceMain = tempSong.getPrice();
									balanceStatue = c.checkBalance(priceMain);  //this checks the balance. If 1 returns, transaction will be done. else it will exit

									if (balanceStatue) {
										newStock = c.order(tempSong, tempSong.getStock());
										cout << "Current Stock : " << newStock << endl;
										main.setStock(newStock, init, 's');
										c.setBalance(c.calculateBalance(priceMain));
										main.calculateBalance(priceMain);
									}
									else {
										init = 0;
									}
								}
							} while (init != 0);
						}
						//*******************************************************************************




					//Display Albums*****************************************************************
						else if (shopChoice == 1) {
							main.displayAlbums();
							int chooseAlbum;
							int albumOp1;
							int initial;
							do {
								cout << endl << "1. Inspect album" << endl << "2. Purchase Album" << endl <<"3. Exit" << endl;
								cout << "Enter your decision : ";
								cin >> chooseAlbum;
								if (chooseAlbum != 1 && chooseAlbum != 2 && chooseAlbum != 3) {
									cout << "Invalid input. Redirecting to main menu >:(" << endl;
									break;
								}

								if (chooseAlbum == 1) {
									//Display what album consists of___________________________________________________
									cout << "Enter the initial of the album you want to see (enter 0 to exit) : ";
									cin >> albumOp1;
									if (albumOp1 > 13 || albumOp1 < 0) {
										cout << "Invalid input. Redirecting to main menu >:(" << endl;
										break;
									}
									while (albumOp1 != 0) {
										Album* temp = main.getAlbums();
										for (i = 0; i < 13; i++) {
											if (albumOp1 == i + 1) {
												cout << "Album : " << temp[i].getAlbumName() << endl;
												initial = i;
											}
										}
										cout << endl <<  "Songs-------------" << endl;
										temp[initial].printSongs();
										cout << endl;
										cout << "Enter the initial of the album you want to see (enter 0 to exit) : ";
										cin >> albumOp1;
										if (albumOp1 > 13 || albumOp1 < 0) {
											cout << "Invalid input. Redirecting to main menu >:(" << endl;
											break;
										}
									}
								}
								//__________________________________________________________________________________


							//Purchase Album________________________________________________________________________
								else if (chooseAlbum == 2) {
									Album* tempAlbum = main.getAlbums();
									cout << "Enter the Album initial to purchase it (enter 0 to quit) : ";
									cin >> init;
									if (init != 0) {
										priceMain = tempAlbum[init - 1].getPrice();
										balanceStatue = c.checkBalance(priceMain);  //this checks the balance. If 1 returns, transaction will be done. else it will exit
										if (balanceStatue) {
											newStock = tempAlbum[init - 1].getStock();
											c.order(tempAlbum[init - 1], newStock);
											cout << "Current Stock : " << newStock << endl;
											main.setStock(newStock, init - 1, 'a');
											c.setBalance(c.calculateBalance(priceMain));
											main.calculateBalance(priceMain);
										}
										else {
											init = 0;
										}
									}
								}
								//______________________________________________________________________________________

							} while (chooseAlbum != 3);
						}

						//*******************************************************************************
					} while (shopChoice != 3);
				}
				//----------------------------------------------------------------------------------

				else if (choice == 4) {
					cout << "--------------------------FAVORITE GENRES--------------------------" << endl;
					c.favoriteGenres();

				}
				else if (choice == 5) {
					cout << "Choose one of your favorite genres to recieve a random song : " << endl;
					c.printFavoriteGenres();
					main.suggestRandomSong();
				}
				else if (choice == 6) {
					c.updateBalance();
				}


				cout << endl << "--------------------------MENU--------------------------" << endl;
				cout << "1. Show the songs that I've bought" << endl;
				cout << "2. Make a playList" << endl;
				cout << "3. Shop" << endl;
				cout << "4. Make a favourite genre list" << endl;
				cout << "5. Make random suggestion" << endl;
				cout << "6. Update Balance" << endl;
				cout << "7. Exit" << endl;
				cout << "Please enter the choice you want to execute : ";
				cin >> choice;
			} //while
			//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
		} //else if


		cout << endl << endl << "Please select account type to sign in : " << endl;
		cout << "'m' for Manager" << endl << "'c' for Customer  " << endl << "'q' for exit from the main program" << endl;
		cout << "choice : ";
		cin >> choiceChar;


	}

	
	cout << endl << "*********" << endl << "*EXITTED*" << endl << "*********" << endl;;
	return 0;
}