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

///////


//iterate through two arrays, pass if they are similar. Use flag if they are 
CDCatalogue CDCatalogue::Split(const CDCatalogue& cat) const {
    /*CDCatalogue test; return test;*/

    //flag
    bool flag = true; 
    CDCatalogue* split_cat = new CDCatalogue;

    for (int i = 0; i < cat.Count(); i++) {

        for (int j = 0; j < numcds; j++) {

            //if the 2 arrays have similar album/artist, pass
            if (cds[i].GetAlbum() == cat.cds[j].GetAlbum() && cds[i].GetArtist() == cat.cds[j].GetArtist()) {

                flag = false;
            }
        }

    //if not similar, add it the the new catalogue "split_cat"
    if (flag) { split_cat->Insert(CD(cds[i].GetArtist(), cds[i].GetAlbum())); } 

    flag = true; 

    }

    for (int k = 0; k < split_cat->Count(); k++) {

        cout << "This album was only found in cat: \n" << "Artist: " <<split_cat->cds[k].GetArtist() 
        << "\nAlbum: " << split_cat->cds[k].GetAlbum() << endl;
    }
    
    return *split_cat;     

}
