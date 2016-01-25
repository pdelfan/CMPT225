#include <iostream>
#include "cdcatalogue.h"
#include <string>	
#include "cd.h"
using namespace std;

//testing finding an album
void insert_find_album() {

	CD album1("Linkin Park", "Numb");
	CD album2("Serge Gainsbourg", "Initials B.B");

	CDCatalogue catalogue1;
	CDCatalogue catalogue2;

	catalogue1.Insert(album1);
	catalogue2.Insert(album2);

	//find index of non-existent album and artist (returns -1)
	cout << catalogue1.Find(CD("NON-EXISTENT", "NON-EXISTENT")) << endl;

	//find index of an album (this case is at index 0)
	cout << catalogue1.Find(CD("Linkin Park", "Numb")) << endl;

}


//testing copying, finding and inserting
void copy_find_insert() {
	
	CD album1("The Beatles", "Help!");
	CD album2("David Bowie", "Blackstar");

	CDCatalogue cat1;

	cat1.Insert(album1);
	cat1.Insert(album2);

	cout << cat1.Find(album1) << endl;

	//deep copy cat1 to cat2
	CDCatalogue cat2(cat1);

	cout << cat2.Find(album1) << endl;
}


//testing adding an album, removing it and then trying to find it
void remove_album() {

	CD album1("The Beatles", "Help!");
	CD album2("A", "B");

	CDCatalogue catalogue1;

	catalogue1.Insert(album1);
	catalogue1.Insert(album2);

	//Find album2
	cout << catalogue1.Find(album2) << endl;

	//remove album2
	catalogue1.Remove(CD("A", "B"));

	//try to find album after it is deleted (should return -1)
	cout << catalogue1.Find(CD("A", "B")) << endl;
}


void test_common() {
	

	/*  using cin to test

    CDCatalogue cat1;

    	string inputalbum;
    	string inputartist;

        cout << "\nEnter the artist name: ";
        getline(cin, inputartist);
        cout << "\nEnter the album name: ";
        getline(cin, inputalbum);
        cat1.Insert(CD(inputartist, inputalbum));

	    CDCatalogue cat2(cat1);

        cout << "\nEnter the artist name: ";
        getline(cin, inputartist);
        cout << "\nEnter the album name: ";
        getline(cin, inputalbum);
        cat2.Insert(CD(inputartist, inputalbum));
*/


	//Alubms
    CD album0("0", "0");
	CD album1("1", "1");
	CD album2("2", "2");
	CD album3("3", "3");
	CD album5("5", "5");
	CD album4("4", "4");
	CD album6("6", "6");


	//Declare catalogue
	CDCatalogue cat1;
	CDCatalogue cat2;

	//Insert album
	cat1.Insert(album1);
	cat1.Insert(album2);
	cat1.Insert(album3);
	//cat1.Insert(album4);
	//cat1.Insert(album5);
	//cat1.Insert(album6);



	cat2.Insert(album1);
	cat2.Insert(album2);
	cat2.Insert(album3);
	cat2.Insert(album4);
	//cat2.Insert(album1);


  //CDCatalogue catcommon = cat1.Common(cat2);

  CDCatalogue catsplit = cat1.Split(cat2);

}


int main(){

	//remove_album();
	//insert_find_album();
	test_common();
}
