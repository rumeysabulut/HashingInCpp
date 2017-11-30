//
//  BookCharacter.cpp
//  Project3
//
//  Created by Rumeysa Bulut on 29.11.2017.
//  Copyright © 2017 Rumeysa Bulut. All rights reserved.
//

#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>
#include "BookCharacter.hpp"

BookCharacter::BookCharacter(){
    
}
BookCharacter::BookCharacter(string line){
    vector<string> Character;
    stringstream full_line(line);
    string info;
    while (getline(full_line, info, '\t')) {
        Character.push_back(info);
    }
    setPageNo(Character[0]);
    setLineNo(Character[1]);
    setIndex(Character[2]);
    if(Character.size() > 3){
        setCharacter(Character[3]);
    }
    generate_key();
}
void BookCharacter::setPageNo(string page_no){
    this->pageNo = stoi(page_no);
}
void BookCharacter::setLineNo(string line_no){
    this->lineNo = stoi(line_no);
}
void BookCharacter::setIndex(string index){
    this->index = stoi(index);
}
void BookCharacter::setCharacter(string character){
    this->character = character.c_str()[0];
}
int BookCharacter::getPageNo(){
    return pageNo;
}
int BookCharacter::getLineNo(){
    return lineNo;
}
int BookCharacter::getIndex(){
    return index;
}
char BookCharacter::getCharacter(){
    return character;
}
void BookCharacter::generate_key(){
    unsigned long key;
    int page, line, index;
    page = getPageNo();
    line = getLineNo();
    index = getIndex();
    
    key = page*pow(10,4) + line*pow(10,2) + index;
    this->key = key;
}
unsigned long BookCharacter::getKey(){
    return key;
}

