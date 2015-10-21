#include "Story.h"
#include "Paragraph.h"
#include "Sentence.h"
#include "Word.h"
#include <iostream>
#include <string>
#include <ctype.h>
int main(){
    // std::string input;
    // std::cout << "Input: ";
    // std::getline(std::cin, input);
    // char charArray[input.length()];
    // char* charArray = &input[0];
    char charArray[] = "Hello world";
    std::cout << sizeof(charArray) << std::endl;
    // strcpy(charArray, input.c_str());
    Sentence sentence = Sentence();    
    Word word;
    // std::cout << input.length() << std::endl;
    // std::cout << (void*)charArray << std::endl;
    int i = 0;
    while(charArray[i] != '\0'){
	char c = charArray[i];
	char * cp = &(charArray[i]);
	// std::cout << (void*)&c << std::endl;
	// std::cout << *cp << std::endl;
	// std::cout << c << std::endl;
	// std::cout << "C: ";
	// std::cout << c << std::endl;	
    	if(i == 0){
	    // std::cout << "i is 0" << std::endl;
	    std::cout << "H\n";
    	    word = Word(cp);
	    std::cout << "H\n";
    	}else{
	    // std::cout << "In here" << std::endl;
    	    if(isspace(c)){
		// std::cout << "In here" << std::endl;
		// word.show();
		std::cout << "w\n";
    		sentence.append(word);
		std::cout << "w\n";
    		word = Word(cp);
    	    }	       
    	}
	++i;
    }
    sentence.show();

    // char * input = ['H','e','l','l','o',' ','W','o','r','l','d'];
    // char input[] = "Hello world";
    // Word* word = new Word(input);
    // word->show();
    // Word w1, w2, w3, w4, w5(w4), w6=w5;
    // Sentence s1, s2, s3, s4, s5(s4), s6=s5;
    // Paragraph p1, p2, p3(p2), p4=p3;
    // Story st1, st2, st3(st2), st4=st3;
    // w1++;
    // w1--;
    // --w1;
    // ++w1;
    // s1++;
    // s1--;
    // ++s1;
    // --s1;
    // s1 = w1 + w2 + w3; 
    // s2 = w2 + w4;
    // p1 = (s1 + s2); 
    // st1 = st1 + p2 + ((p1 + p1 + p1) + 1);
    // Word w1;
    // std::cout << w1 << std::endl;
    // std::cout << "End of code" << std::endl;
}
