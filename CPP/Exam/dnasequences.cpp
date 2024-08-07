/*
Data scientists at <COMPANY NAME> are working on a utility
for genome sequencing algorithms. The utility finds anagram
patterns in a pair of DNA sequence strings. A pair of DNA
is 'special' if they are anagrams after removing any number
of occurences of at most one character from each DNA sequence.

Given n pairs of DNA, for each pair, attempt to make them
anagrams. Return a list of boolean values, one for each pair,
where True means a pair is special.

Example:
Inputs = {
    dna1 = "abcee", dna2 = "acdeedb"
    dna1 = "sljffsaje", dna2 = "sljsje"
}

Output = [True, False]
*/
using namespace std;

#include <vector>
#include <string>

bool isSpecial(string strA, string strB){
    // Init Occurances
    int occurA[256];
    int occurB[256];
    for(int i = 0; i < 256; i++){
        occurA[i] = 0;
        occurB[i] = 0;
    }

    // Populate Occurances
    for(int i = 0; i < strA.size(); i++){
        char c = strA[i];
        occurA[c]++;
    }
    for(int i = 0; i < strB.size(); i++){
        char c = strB[i];
        occurB[c]++;
    }

    // Compare occurances
    // There can only be one fail on each side
    int greaterA = 0;
    int greaterB = 0;
    for(int i = 0; i < 256; i++){
        if(occurA[i] > occurB[i]){
            greaterA++;
        }
        if(occurB[i] > occurA[i]){
            greaterB++;
        }

        if(greaterA > 1 || greaterB > 1){
            break;
        }
    }

    if(greaterA <= 1 && greaterB <= 1){
        return true;
    }
    return false;
}

vector<bool> getSequence(vector<vector<string>> dna) {
    vector<bool> results;
    for(auto pair : dna){
        results.push_back(isSpecial(pair[0], pair[1]));
    }
    return results;
}

int main(int argc, char** argv){
    vector<string> pairOne;
    pairOne.push_back("abcee");
    pairOne.push_back("acdeedb");

    vector<string> pairTwo;
    pairTwo.push_back("sljffsaje");
    pairTwo.push_back("sljsje");

    vector<vector<string>> inputDNA;
    inputDNA.push_back(pairOne);
    inputDNA.push_back(pairTwo);

    vector<bool> seq = getSequence(inputDNA);

    printf("[ ");
    for(bool special : seq){
        if(special){
            printf("True ");
        }
        else{
            printf("False ");
        }
    }
    printf("]\n");

    return 0;
}

// Passed all 15 test cases
// Took 25 minutes (had 35)
// Found the question confusing at first, but when I wrote out the number of occurances
// in the example strings I figured out the pattern.
