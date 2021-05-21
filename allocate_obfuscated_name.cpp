#include "allocate_obfuscated_name.h"
#include <stdexcept>
#include <cmath>
#include <random>
#include <ctime>
#include <algorithm>

AllocateObfuscatedName::AllocateObfuscatedName(int needed_names_quantity_) : index_for_export(0)
{
    if(needed_names_quantity_ <= 0) {
        throw std::invalid_argument("needed_names_quantity_ is negative or zero.");
    }

    needed_names_quantity = needed_names_quantity_;
    makeNeededNamesBeAbleToMakeRequiredDigitsQuantityBiggerThanSevenDigits();
    setRequiredDigitsQuatity();
    initializeIndexes();
    initializeRandomIndexesForObfuscatedNames();

    fillObfuscatedNamesWithObfuscatedWords();
}

AllocateObfuscatedName::AllocateObfuscatedName(unsigned int needed_names_quantity_) : index_for_export(0)
{
    if(needed_names_quantity_ == 0){
        throw std::invalid_argument("needed_names_quantity_ is zero.");
    }
    needed_names_quantity = needed_names_quantity_;
    makeNeededNamesBeAbleToMakeRequiredDigitsQuantityBiggerThanSevenDigits();
    setRequiredDigitsQuatity();
    initializeIndexes();
    initializeRandomIndexesForObfuscatedNames();

    fillObfuscatedNamesWithObfuscatedWords();
}

void AllocateObfuscatedName::makeNeededNamesBeAbleToMakeRequiredDigitsQuantityBiggerThanSevenDigits()
{
    const unsigned int eight_digit = 8;
    if(needed_names_quantity < pow(3, eight_digit))
    {
        needed_names_quantity = pow(3, eight_digit);
    }
}

void AllocateObfuscatedName::setRequiredDigitsQuatity()
{
    required_digits_quantity = 1;
   
    while (pow(3, required_digits_quantity) < needed_names_quantity)
    {
        required_digits_quantity += 1;
    }
}

void AllocateObfuscatedName::initializeIndexes()
{
    indexes = new unsigned int[required_digits_quantity];
    for(unsigned int index = 0 ; index < required_digits_quantity ; index++)
    {
        indexes[index] = 0;
    }
}

void AllocateObfuscatedName::initializeRandomIndexesForObfuscatedNames()
{
    random_indexes_for_obfuscated_names = new unsigned int[needed_names_quantity];
    for(int c = 0 ; c < needed_names_quantity ; c++)
    {
        random_indexes_for_obfuscated_names[c] = c;
    }

    unsigned seed = time(nullptr);
    shuffle(random_indexes_for_obfuscated_names, random_indexes_for_obfuscated_names + needed_names_quantity, default_random_engine(seed));
}

void AllocateObfuscatedName::fillObfuscatedNamesWithObfuscatedWords()
{
    unsigned int count = 1; 
    for( ; count <= needed_names_quantity ; count+=1)
    {
        insertStringToObfuscatedNames(getObfuscatedWordDerivedFromIndexes());
        updateIndexes(); 
    }
}

void AllocateObfuscatedName::insertStringToObfuscatedNames(string to_input)
{
    obfuscated_names.push_back(to_input);
}

string AllocateObfuscatedName::getObfuscatedWordDerivedFromIndexes()
{
    string to_return = "";
    for(int count = 0 ; count < required_digits_quantity ; count++)
    {
        to_return.push_back(obfuscated_characters[indexes[count]]);
    }
    return to_return;
}

void AllocateObfuscatedName::updateIndexes()
{
    indexes[required_digits_quantity-1] += 1;
    for(int index = required_digits_quantity-1 ; index > 0 ; index--)
    {
        if(indexes[index] == 3)
        {
            indexes[index] = 0;
            indexes[index-1] += 1;
        }
    }

    if(indexes[0] > 3)
    {
        throw out_of_range("indexes[0] is bigger than 3!");
    }
}

string AllocateObfuscatedName::getNewObfuscatedName()
{
    unsigned int index = random_indexes_for_obfuscated_names[getNewIndexFromRandomIndexesForBbfuscatedNames()];
    return obfuscated_names[index];
}

unsigned int AllocateObfuscatedName::getNewIndexFromRandomIndexesForBbfuscatedNames()
{
    unsigned int to_return = index_for_export;
    index_for_export += 1;
    return to_return;
}
