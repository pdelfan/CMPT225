#include <iostream>
#include <string>
#include <algorithm>
#include <array>

#include "cdcatalogue.h"

// Helper method for copy constructor
// Performs deep copy of dynamic array
void CDCatalogue::CopyArray(const CDCatalogue& cat) {

    numcds = cat.numcds;
    maxsize = cat.maxsize;
    cds = new CD [cat.maxsize];

    //copy(cat.cds, cat.cds + numcds, cds);

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
    //Checks if either the input of artist or album does not contain the empty stirng and returns true
    if (!disk.Update(disk.GetArtist(), disk.GetAlbum())) {
        return false;
    }

    if (numcds == maxsize) {
        CD* old_cds = cds;
        maxsize = maxsize*2;
        cds = new CD[maxsize];

        for (int i = 0; i < numcds; i++ ) {
            cds[i] = old_cds[i];
        }

        delete[] old_cds;
        cds[numcds++] = disk;
        return true;
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
    if (!disk.Update(disk.GetArtist(), disk.GetAlbum())) {
        return false;
    }

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
    CDCatalogue result;
    for (int i = 0; i < maxsize; i++) {
        result.Insert(cds[i]);
        result.Insert(cat.cds[i]);
    }

    cout << "Number of cds in cat: " << cat.numcds << endl;
    cout << "Number of cds: " << result.numcds << endl;

    return result;
}

CDCatalogue CDCatalogue::Common(const CDCatalogue& cat) const {
    CDCatalogue test; return test;
}

CDCatalogue CDCatalogue::Split(const CDCatalogue& cat) const {
    CDCatalogue test; return test;
}





