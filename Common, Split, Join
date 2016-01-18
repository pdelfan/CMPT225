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
