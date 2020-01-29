//
// Created by chenjs on 1/13/20.
//

#ifndef FLEXIBLEGAMEENGINE_SYMBOL_H
#define FLEXIBLEGAMEENGINE_SYMBOL_H

#include "Common.h"

class Symbol {
public:
    size_t id{0};

    Symbol(const char* str) noexcept {
        id = intern(str);
    }

    constexpr Symbol() noexcept {
        id = 0;
    }

    [[nodiscard]] const char* c_str() const{
        return get_symbol_table()[id];
    }

public:
public:
    static List<const char*>& get_symbol_table(){
        static List<const char*> table{ nullptr };
        return table;
    }
    static size_t intern(const char* str){
        if(str == nullptr){
            return 0;
        }
        List<const char*>& table = get_symbol_table();
        for(size_t i = 1;i < table.size();i++){
            if(std::strcmp(str, table[i]) == 0){
                return i;
            }
        }
        size_t len = std::strlen(str);
        char* copy = new char[len + 1];
        std::strncpy(copy, str, len);
        table.push_back(copy);
        return table.size() - 1;
    }
};

#endif //FLEXIBLEGAMEENGINE_SYMBOL_H
