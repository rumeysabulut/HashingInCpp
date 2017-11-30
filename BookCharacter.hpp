//
//  BookCharacter.hpp
//  Project3
//
//  Created by Rumeysa Bulut on 29.11.2017.
//  Copyright © 2017 Rumeysa Bulut. All rights reserved.
//

#ifndef BookCharacter_hpp
#define BookCharacter_hpp

#include <string>
using namespace std;
class BookCharacter{
private:
    int pageNo;
    int lineNo;
    int index;
    char character;
    unsigned long key;
public:
    BookCharacter();
    BookCharacter(string);
    void generate_key();
    void setPageNo(string);
    void setLineNo(string);
    void setIndex(string);
    void setCharacter(string);
    
    int getPageNo();
    int getLineNo();
    int getIndex();
    char getCharacter();
    unsigned long getKey();
};
#endif /* BookCharacter_hpp */
