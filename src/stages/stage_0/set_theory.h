#pragma once

#include <unordered_set>
#include <utility>
#include <vector>

template <typename T>
std::unordered_set<T> unionSets(const std::unordered_set<T>& set_1, const std::unordered_set<T>& set_2){

    if(set_1.size() < set_2.size()){
        std::unordered_set<T> result = set_2;
        result.insert(set_1.begin(), set_1.end());
        return result;
    }

    std::unordered_set<T> result = set_1;
    result.insert(set_2.begin(), set_2.end());
    return result;
}

template <typename T>
std::unordered_set<T> intersectionSets(const std::unordered_set<T>& set_1, const std::unordered_set<T>& set_2){
    if(set_1.size() > set_2.size()){
        return intersectionSets(set_2, set_1);
    }

    std::unordered_set<T> result;
    for(const auto& elem : set_1){
        if(set_2.count(elem)) result.insert(elem);
    }

    return result;
}

template <typename T>
std::unordered_set<T> differenceOfSets(const std::unordered_set<T>& set_1, const std::unordered_set<T>& set_2){
    if(set_1.empty()) return {};
    if(set_2.empty()) return set_1;

    std::unordered_set<T> result;
    if(set_1.size() > set_2.size()){
        result.reserve(set_1.size() - set_2.size());
    }

    for(const auto& elem : set_1){
        if(!set_2.count(elem)) result.insert(elem);
    }

    return result;
}

template <typename T>
std::unordered_set<T> complementOfSet(const std::unordered_set<T>& mainSet, const std::unordered_set<T>& universalSet){
    // universalSet - mainSet
    return differenceOfSets(universalSet, mainSet);
}

template <typename T>
std::unordered_set<T> symmetricDifference(const std::unordered_set<T>& set_1, const std::unordered_set<T>& set_2){
    if(set_1.size() < set_2.size()){
        return symmetricDifference(set_2, set_1);
    }
    if(set_2.empty()) return set_1;

    std::unordered_set<T> result = set_1;

    for(const auto& elem : set_2){
        if(!result.erase(elem)){ // .erase(key) returns 1 if removed, 0 if not found!
            result.insert(elem);
        }
    }

    return result;
}

template <typename T>
bool isSubsetOf(const std::unordered_set<T>& set_1, const std::unordered_set<T>& set_2){
    if(set_1.size() > set_2.size()) return false;

    for(const auto& elem : set_1){
        if(!set_2.count(elem)) return false;
    }

    return true;
}

template <typename T>
bool isProperSubsetOf(const std::unordered_set<T>& set_1, const std::unordered_set<T>& set_2){
    if(set_1.size() >= set_2.size()) return false;

    return isSubsetOf(set_1, set_2);
}

template <typename T>
bool areDisjoint(const std::unordered_set<T>& set_1, const std::unordered_set<T>& set_2){
    if(set_1.size() > set_2.size()){
        return areDisjoint(set_2, set_1);
    }

    for(const auto& elem : set_1){
        if(set_2.count(elem)) return false;
    }

    return true;
}

template <typename T, typename A>
std::vector<std::pair<T,A>> cartesianProducts(const std::unordered_set<T>& set_1, const std::unordered_set<A>& set_2){
    std::vector<std::pair<T,A>> result;
    result.reserve(set_1.size() * set_2.size());

    for(const auto& a : set_1){
        for(const auto& b : set_2){
            result.emplace_back(a, b);
        }
    }

    return result;
}