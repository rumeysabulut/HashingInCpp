//
//  List.hpp
//  Project3
//
//  Created by Rumeysa Bulut on 30.11.2017.
//  Copyright © 2017 Rumeysa Bulut. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include <list>
#include "BookCharacter.hpp"
using namespace std;
class List{
private:
    list<BookCharacter> characterList;
public:
    List();
    void block_insertion(ifstream &);
    void block_lookup();
};
#endif /* List_hpp */
