#include "Story.h"
#include "Paragraph.h"
#include "Sentence.h"
#include "Word.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
int main(){
    // char charArray[] = "Hello world";
    std::ifstream file("input.txt");
    std::string input((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    int length = input.length();
    char charArray[length];
    for(unsigned int i = 0; i < length; i ++){
	charArray[i] = input[i];
	// std::cout << i;
	// std::cout << charArray[i];
	    
    }
    Word word;
    Sentence sentence = Sentence();    
    int i = 0;
    std::cout << std::endl;
    while(charArray[i] != '\0'){
    	char c = charArray[i];	
	// std::cout << i;
	// std::cout << charArray[i];
    	if(i == 0){
    	    word = Word(charArray + i);
    	}else{
    	    if(isspace(c)){
    		// ++i;
		// word.show();
    		sentence.append(word);
		// std::cout << "Showing" << std::endl;
		// word.show();
		// std::cout << std::endl;
		// std::cout << "WORD" << std::endl;
		// std::cout << std::endl;
		// sentence.show();
    		word.~Word();
    		word = Word(charArray + i + 1);
    	    }	       
p    	}
    	++i;
    }
    sentence.append(word);
    // std::cout << "Showing" << std::endl;
    word.show();
    // std::cout << std::endl;
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
