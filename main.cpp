//
//  main.cpp
//  Regex
//
//  Created by Sebastian Siejek on 11/09/2018.
//  Copyright © 2018 Sebastian Siejek. All rights reserved.
//

#include <iostream>
#include <regex>
#include <fstream>

void regexReplace(std::string word, std::string regexTemplate, std::string regexReplaced) {
    
    std::regex singleDigitNumber(regexTemplate);
    std::smatch result;
    
    if (std::regex_search(word, result, singleDigitNumber)) {
        std::string replaceText = std::regex_replace(word, singleDigitNumber, regexReplaced);
        std::cout << std::endl << replaceText;
    }
}

int main(int argc, const char * argv[]) {
    
    std::fstream file("/Users/sebastiansiejek/Studia/25.09.2017/Regex/Regex/numbers.txt", std::ios::in);
    
    if (file.good()) {
        
        std::string number;
        
        while (file >> number) {
            regexReplace(number, "^[0-9]$", "-$&");
            regexReplace(number, "^[0-9][2,]$", "+$&");
        }
        file.close();
        
    }

    return 0;
}
