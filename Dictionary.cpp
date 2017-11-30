//
//  Dictionary.cpp
//  Project3
//
//  Created by Rumeysa Bulut on 29.11.2017.
//  Copyright © 2017 Rumeysa Bulut. All rights reserved.
//
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <ctime>
#include "Dictionary.hpp"
#define M 131071
using namespace std;

Dictionary::Dictionary(){
    count = 0; all_collision = 0; avg_collision1 = 0; avg_collision2 = 0; avg_collision3 = 3;
    
    ifstream inputFile;
    inputFile.open("ds-set-input.txt");
    if(!inputFile){
        cout<< "Error opening input file" << endl;
        return;
    }
   
    block_insertion(inputFile);
    
    clock_t start = clock();
    block_lookup();
    clock_t end = clock();
    double elapsed_time = double (end - start) / CLOCKS_PER_SEC;
    cout << "Lookup finished after :" << elapsed_time << " seconds" << endl << endl;
}
void Dictionary::block_insertion(ifstream &inputFile){
    
    BookCharacter adiniferihakoydum;
    vector<bool> check_empty;
    unsigned long index;
    unsigned long line_count = 0;
    unsigned long collision = 0;
    string line;
    newCharacter.resize(M);
    check_empty.resize(M);
    for (unsigned long i = 0; i < M; i++) {
        check_empty[i] = true;
    }
    
    clock_t start = clock();
    while (getline(inputFile, line)) {
        line_count++;

        adiniferihakoydum = BookCharacter(line);
        
        index = hash(adiniferihakoydum.getKey());
        if(check_empty[index]){     //if that index is empty
            newCharacter[index] = adiniferihakoydum;    //insert the character
            check_empty[index] = false;
        }
        else{           // do probing and insert
            while (!check_empty[index]) {
                collision++;        //total collision number
                count++;            //collision count spesific to one index and one book character
                index = quadratic_probe(count, adiniferihakoydum.getKey());
            }
            newCharacter[index] = adiniferihakoydum;    //insert the character
            check_empty[index] = false;
            count = 0;
        }
        
        if(line_count == 1000)
            avg_collision1 = collision;
        else if(line_count == 10000)
            avg_collision2 = collision;
        else if(line_count == 100000)
            avg_collision3 = collision;
        else if(line_count == M-1)
            all_collision = collision;
        
    }
    clock_t end = clock();
    
    double elapsed_time = double (end - start) / CLOCKS_PER_SEC;
    cout << "Insertion finished after :" << elapsed_time << " seconds" << endl << endl;
    cout << "Average number of collisions (first 1000)\t | " << (long double) avg_collision1/1000 << endl;
    cout << "Average number of collisions (first 10000)\t | " << (long double) avg_collision2/10000 << endl;
    cout << "Average number of collisions (first 100000)\t | " << (long double)avg_collision3/100000 << endl;
    cout << "Average number of collisions (overall)\t | " << (long double) all_collision/(M-1) << endl << endl;
    
}

unsigned long Dictionary::hash(unsigned long k){
    unsigned long hashed_value;     //will be index
    double A = (sqrt(5) - 1)/2;
    
    hashed_value = floor(M * fmod((k*A), 1));
    return hashed_value;
}
unsigned long Dictionary::quadratic_probe(unsigned long i, unsigned long k){
    unsigned long index;
    unsigned long h = hash(k);
    index = (h + 7*i + 3*i*i) % M;
    return index;
}

void Dictionary::block_lookup(){
    BookCharacter wanted;
    unsigned long index;
    count = 0;
    ifstream lookupFile;
    ofstream lookupOut;
    lookupFile.open("ds-set-lookup.txt");
    lookupOut.open("ds-set-output-dict.txt");
    if(!lookupFile){
        cout<< "Error opening input file" << endl;
        return;
    }
    string line;
    while(getline(lookupFile, line)){
        wanted = BookCharacter(line);
        index = hash(wanted.getKey());
        if( newCharacter[index].getKey() == wanted.getKey()){
            lookupOut << line << '\t' << newCharacter[index].getCharacter() << endl;
        }
        else {
            while( newCharacter[index].getKey() != wanted.getKey()){
                count++;
                index = quadratic_probe(count, wanted.getKey());
            }
            count = 0;
            lookupOut << line << '\t' << newCharacter[index].getCharacter() << endl;
        }
    }
    
}
