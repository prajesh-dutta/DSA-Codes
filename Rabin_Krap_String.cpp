#include <iostream>
#include <string>
#include <cmath>

using namespace std;


void rabinKarpSearch(const string& text, const string& pattern, int prime) {
    int textSize = text.size();
    int patternSize = pattern.size();
    int i, j;
    int patternHash = 0; 
    int textHash = 0; 
    int h = 1;
    int d = 256; 

    
    for (i = 0; i < patternSize - 1; i++)
        h = (h * d) % prime;

    
    for (i = 0; i < patternSize; i++) {
        patternHash = (d * patternHash + pattern[i]) % prime;
        textHash = (d * textHash + text[i]) % prime;
    }

    
    for (i = 0; i <= textSize - patternSize; i++) {
        
        if (patternHash == textHash) {
            
            for (j = 0; j < patternSize; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }

            
            if (j == patternSize)
                cout << "Pattern found at index " << i << endl;
        }

        
        if (i < textSize - patternSize) {
            textHash = (d * (textHash - text[i] * h) + text[i + patternSize]) % prime;

         
            if (textHash < 0)
                textHash = (textHash + prime);
        }
    }
}

int main() {
    string text = "ARGENTINA WON THE WORLDCUP";
    string pattern = "WORLD";
    int prime = 101; 
    rabinKarpSearch(text, pattern, prime);
    return 0;
}
