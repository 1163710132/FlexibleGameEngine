//
// Created by chenjs on 1/13/20.
//

#ifndef FLEXIBLEGAMEENGINE_COMMON_H
#define FLEXIBLEGAMEENGINE_COMMON_H

#include <vector>
#include <list>
#include <unordered_map>
#include <cstring>
#include <functional>
#include <memory>
#include <array>
#include <thread>
#include <cassert>

template <typename TKey, typename TValue>
using Dictionary = std::unordered_map<TKey, TValue>;

template <typename T>
using List = std::vector<T>;

template <typename T>
using LinkedList = std::list<T>;

template <typename T, size_t SzLength>
using Array = std::array<T, SzLength>;

template <typename T>
using Unique = std::unique_ptr<T>;

template <typename TSignature>
using Delegate = std::function<TSignature>;

using Thread = std::thread;

#define STATIC_SYMBOL(NAME) static Symbol NAME = #NAME;

using std::move;

#endif //FLEXIBLEGAMEENGINE_COMMON_H
