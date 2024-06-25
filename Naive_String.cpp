#include <iostream>
#include <string>

void searchPattern(const std::string& text, const std::string& pattern) {
    int textSize = text.size();
    int patternSize = pattern.size();

    
    for (int i = 0; i <= textSize - patternSize; i++) {
        int j;

      
        for (j = 0; j < patternSize; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

     
        if (j == patternSize) {
            std::cout << "Pattern found at index " << i << std::endl;
        }
    }
}

int main() {
    std::string text = "ABABDABACDABABCABAB";
    std::string pattern = "ABABCABAB";
    searchPattern(text, pattern);
    return 0;
}
