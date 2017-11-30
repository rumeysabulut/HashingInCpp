//
//  List.cpp
//  Project3
//
//  Created by Rumeysa Bulut on 30.11.2017.
//  Copyright © 2017 Rumeysa Bulut. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
#include <algorithm>
#include "List.hpp"
List::List(){
    ifstream inputFile;
    inputFile.open("ds-set-input.txt");
    if(!inputFile){
        cout<< "Error opening input file" << endl;
        return;
    }
    block_insertion(inputFile);
    block_lookup();
}
void List::block_insertion(ifstream &inputFile){
    BookCharacter bookch;
    string line;
    clock_t start = clock();
    while(getline(inputFile, line)){
        bookch = BookCharacter(line);
        characterList.push_back(bookch);
    }
    clock_t end = clock();
    double elapsed_time = double (end - start) / CLOCKS_PER_SEC;
    cout << "Insertion finished after :" << elapsed_time << " seconds" << endl;
}
void List::block_lookup(){
    BookCharacter wanted;
    list<BookCharacter>::iterator findit;
    ifstream lookupFile;
    ofstream lookupOut;
    lookupFile.open("ds-set-lookup.txt");
    lookupOut.open("ds-set-output-list.txt");
    if(!lookupFile){
        cout<< "Error opening input file" << endl;
        return;
    }
    
    string line;
    findit = characterList.begin();
    clock_t start = clock();
    while(getline(lookupFile, line)){
        wanted = BookCharacter(line);
        
        for(int i = 0; i < characterList.size(); i++){
            if(findit->getKey() != wanted.getKey()){
                findit++;
            }
            else{
                lookupOut << line << '\t' << findit->getCharacter() << endl;
                findit = characterList.begin();
                break;
            }
        }
    }
    clock_t end = clock();
    double elapsed_time = double (end - start) / CLOCKS_PER_SEC;
    cout << "Lookup finished after :" << elapsed_time << " seconds" << endl;
}
