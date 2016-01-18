#include <iostream>
#include <string>
#include <algorithm>
#include "cdcatalogue.h"

// Helper method for copy constructor
// Performs deep copy of dynamic array
void CDCatalogue::CopyArray(const CDCatalogue& cat) {

    numcds = cat.numcds;
    maxsize = cat.maxsize;
    cds = new CD [cat.maxsize];
    for (int i = 0; i < numcds; i++) {
        cds[i] = cat.cds[i];
    }

}

// Default constructor
// Creates an empty CDCatalogue with default array size (4)
CDCatalogue::CDCatalogue() {
    maxsize = 4;
    cds = new CD [maxsize];
    numcds = 0;
}

// Copy constructor
// Creates a new CDCatalogue object,
//   performs a deep copy of the cat parameter's fields
CDCatalogue::CDCatalogue(const CDCatalogue& cat) {
    CopyArray(cat);
}

// Destructor
// Releases all memory allocated to private pointer members
CDCatalogue::~CDCatalogue() { 
    delete[] cds;
} 

// Insert - performs a set insertion with the CD catalogue
// Inserts CD and returns true if CD is not already in the catalogue
// Does not insert and returns false if a CD with a matching artist and album name
// already exists in the registry
// If the array is already filled before the insertion occurs, then
//   first create a new dynamic array double the size of the old array,
//   copy all CD objects from old array to new array,
//   deallocate memory associated with the old array,
//   and insert the new CD and return true.
// POST:  catalogue contains CD
// PARAM: disc = item to be inserted, its fields should not be empty string
// NOTE:  since overloaded assignment operator has not been defined,
//          "insertion" will mean updating all fields of the CD at the appropriate index

bool CDCatalogue::Insert(CD disk) {
    //Checks if either the artist or album input does not contain the empty stirng, returns false if not
    if (!disk.Update(disk.GetArtist(), disk.GetAlbum())) {
        return false;
    }

    //if the original array becomes full, create a new array double the size and copoy the original array into the new one
    if (numcds == maxsize) {
        CD* old_cds = cds;
        maxsize = maxsize*2;
        cds = new CD[maxsize];

        for (int i = 0; i < numcds; i++ ) {
            cds[i] = old_cds[i];
        }
        delete[] old_cds;
        
        //when expanded, search the array for disk, if not found return true and add disk to cds
        if (find (&cds[0], &cds[maxsize-1], disk) == &cds[maxsize-1]) {
            cds[numcds++] = disk;
            return true;
        } else {
            return false;
        }
        
    //search the array for disk, if not found return true and add disk to cds
    } else if (find (&cds[0], &cds[maxsize-1], disk) == &cds[maxsize-1] ) {
        cds[numcds++] = disk;
        return true;
    } else {
        return false;
    }
}

// Remove - performs a set removal with the CD catalogue
// Removes a CD with all matching parameters if one exists in the catalogue
// Returns false if a CD with the same parameters does not exist in the catalogue
// POST:  catalogue does not contain CD
// PARAM: disc = item to be removed, its fields should not be empty string
// NOTE:  "removal" if successful will be done by updating the parameters of the
// CD at the appropriate index using the parameters of the CD in
// the last valid index of the collection; then decrements count and returns true;
bool CDCatalogue::Remove(CD disk) {
     //Checks if either the artist or album input does not contain the empty stirng, returns false if not
    if (!disk.Update(disk.GetArtist(), disk.GetAlbum())) { 
        return false;
    }

    //searches the array for the target disk, removes target disk and shifts the remaining cds down by 1 index
    for (int i = 0; i < numcds; i++) {
        if (cds[i] == disk) {
            remove(&cds[0], &cds[numcds-1], disk);
            numcds--;
            return true;
        }
    }
    return false;
}

// Locates the array index of a CD with matching parameters
// Returns -1 if no CD with matching parameters exists in the catalogue
// PARAM: disc = item to be located, its fields should not be empty string
int CDCatalogue::Find(CD disk) const {
    if (!disk.Update(disk.GetArtist(), disk.GetAlbum())) {
        return -1;
    }

    for (int i = 0; i < numcds; i++) {
        if (cds[i] == disk) {
            return i;
        } 
    }
    return -1;
}

// Removes all CDs from the catalogue with artist matching the provided argument
// Returns false if there are not matching CDs or input is empty string,
//   otherwise returns true if at least one CD is removed
// Remaining items may appear in the array in any order, with the requirement that
//   there are no "empty" spaces in the array (i.e. an array with 5 items must occupy indices 0-4)
// POST:  catalogue contains no instances of CDs with the supplied artist name
// PARAM: dontlikeanymore = name of artist whose CDs should be removed from the catalogue
bool CDCatalogue::Boycott(string dontlikeanymore) {
    if (dontlikeanymore == "") {
        return false;
    }

    int *boycotted_cds = new int[numcds];
    int boycotted = 0, m = 0;

    //Search through the cds array, if there is a boycotted cd, save its cd index in the original array to boycotted_cds array
    for (int i = 0; i < numcds; i++) {
        if (cds[i].GetArtist() == dontlikeanymore) {
            boycotted_cds[boycotted++] = i;
        }
    }

    //Search through the cds array again, if the cd index is not a boycotted index, shift the cds array with the cd index.
    for (int k = 0; k < numcds; k++) {
        if (find(&boycotted_cds[0], &boycotted_cds[numcds-1], k) == &boycotted_cds[numcds-1]) {
            cds[m++] = cds[k];
        } 
    }

    delete[] boycotted_cds;

    if (boycotted != 0) {
        numcds -= boycotted;
        return true;
    } else {
        return false; 
    }

}

// Returns the number of CDs in the catalogue
int CDCatalogue::Count() const {
    return numcds;
}

CDCatalogue CDCatalogue::Join(const CDCatalogue& cat )const { 
    CDCatalogue *cat_join = new CDCatalogue;

    for (int i = 0; i < cat.Count(); i++) {
        cat_join->Insert(CD(cat.cds[i].GetArtist(), cat.cds[i].GetAlbum()));
    }
    for (int k = 0; k < numcds; k++) {
        cat_join->Insert(CD(cds[k].GetArtist(), cds[k].GetAlbum()));
    }

    cout << numcds << endl;
    cout << cat.Count() << endl;
    cout << cat_join->Count() << endl;

    for (int j = 0; j < cat_join->Count(); j++) {
        cout << "Artist: " << cat_join->cds[j].GetArtist() << "\nAlbum: " << cat_join->cds[j].GetAlbum() << endl;
        
    }

    return *cat_join;
}


CDCatalogue CDCatalogue::Common(const CDCatalogue& cat) const {

    /*CDCatalogue test; return test;*/

    CDCatalogue *cat_common = new CDCatalogue; //new catalogue for common

    for (int i = 0; i < numcds; i++) {

        for (int j = 0; j < cat.Count(); j++) {

            //if "this" and "cat" have the same album and arist, insert them to the new "cat_common" catalogue
            if (cat.cds[j].GetAlbum() == cds[i].GetAlbum() && cat.cds[j].GetArtist() == cds[i].GetArtist()) 

            {
                cat_common->Insert(CD(cds[i].GetArtist(), cds[i].GetAlbum())); 
            }
        }
    }

    //print the common artist and album between "this" and cat
    for (int k = 0; k < cat_common->Count(); k++) {

        cout << "\nCommon between this and cat: \n" << "Artist: " << cat_common->cds[k].GetArtist() 
            << "\nAlbum: " << cat_common->cds[k].GetAlbum() << "\n" << endl;

    }

    return *cat_common;

}

CDCatalogue CDCatalogue::Split(const CDCatalogue& cat) const {
    CDCatalogue test; return test;
}





