//
// Created by chenjs on 1/13/20.
//

#ifndef FLEXIBLEGAMEENGINE_EVENT_H
#define FLEXIBLEGAMEENGINE_EVENT_H

#include "Common.h"

template <typename TSignature>
class Event{
public:
    List<Delegate<TSignature>> delegate_list;
public:
    Event&operator+=(Delegate<TSignature> delegate){
        delegate_list.push_back(move(delegate));
        return *this;
    }
};

#endif //FLEXIBLEGAMEENGINE_EVENT_H
