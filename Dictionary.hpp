//
//  Dictionary.hpp
//  Project3
//
//  Created by Rumeysa Bulut on 29.11.2017.
//  Copyright © 2017 Rumeysa Bulut. All rights reserved.
//

#ifndef Dictionary_hpp
#define Dictionary_hpp

#include <string>
#include <vector>
#include <fstream>
#include "BookCharacter.hpp"

class Dictionary{
private:
    vector<BookCharacter> newCharacter;
    unsigned long count;
    unsigned long avg_collision1;
    unsigned long avg_collision2;
    unsigned long avg_collision3;
    unsigned long all_collision;
public:
    Dictionary();
    void block_insertion(ifstream &);
    unsigned long hash(unsigned long);
    unsigned long quadratic_probe(unsigned long, unsigned long);
    void block_lookup();
};

#endif /* Dictionary_hpp */
