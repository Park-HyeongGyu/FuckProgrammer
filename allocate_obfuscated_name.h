#pragma once
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

class AllocateObfuscatedName
{
private:
    vector<string> obfuscated_names;
    unsigned int needed_names_quantity;

    char obfuscated_characters[3] = {'1', 'l', 'I'};
    const unsigned int quantity_obfuscated_characters = 3;
    unsigned int required_digits_quantity;
    unsigned int *indexes;

    unsigned int *random_indexes_for_obfuscated_names;
    unsigned int index_for_export;

public:
    AllocateObfuscatedName() = delete;
    AllocateObfuscatedName(unsigned int needed_names_quantity_);
    AllocateObfuscatedName(int needed_names_quantity_);
    ~AllocateObfuscatedName() {
        delete[] indexes;
        delete[] random_indexes_for_obfuscated_names;
    }

private:
    void makeNeededNamesBeAbleToMakeRequiredDigitsQuantityBiggerThanSevenDigits();
    void setRequiredDigitsQuatity();
    void initializeIndexes();
    void initializeRandomIndexesForObfuscatedNames();

    void fillObfuscatedNamesWithObfuscatedWords();
    void insertStringToObfuscatedNames(string to_input);
    string getObfuscatedWordDerivedFromIndexes();
    void updateIndexes();

public:
    string getNewObfuscatedName();
private:
    unsigned int getNewIndexFromRandomIndexesForBbfuscatedNames();
};
