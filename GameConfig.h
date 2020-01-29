//
// Created by chenjs on 1/13/20.
//

#ifndef FLEXIBLEGAMEENGINE_GAMECONFIG_H
#define FLEXIBLEGAMEENGINE_GAMECONFIG_H

#include "Common.h"
#include "Symbol.h"

class GameConfig{
public:
    Dictionary<size_t, const char*> entry_table;
public:
    const char* get(const Symbol& symbol) const{
        if(entry_table.contains(symbol.id)){
            return entry_table.at(symbol.id);
        }
        return nullptr;
    }
    void set(const Symbol& symbol, const char* value){
        size_t len = std::strlen(value);
        char* copy = new char[len + 1];
        std::strncpy(copy, value, len);
        if(get(symbol) != nullptr){
            delete[] get(symbol);
        }
        entry_table[symbol.id] = copy;
    }
};

#endif //FLEXIBLEGAMEENGINE_GAMECONFIG_H
