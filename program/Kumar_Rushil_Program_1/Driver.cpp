#include "Story.h"
#include "Paragraph.h"
#include "Sentence.h"
#include "Word.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

int main(){
    char charArray[] = "Strength";
    // char charArray1[] = "World";
    Word w = Word(charArray);
    ++w;
    w.show();
    ++w;
    w.show();
    // w++;
    // std::cout << std::endl;
    // w--;
    // w.show();
    // std::cout << std::endl;
    // w + 1;
    // w.show();
    // std::cout << std::endl;
    // Word w1 = Word(charArray1);
    // Sentence s;
    // Paragraph p;


    // std::cout << std::endl;
    // w++;
    // w.show();
    // std::cout << std::endl;
    // s = w + w;
    // // std::cout << s.head << std::endl;
    // s.show();
    // std::cout << std::endl;
    // s = w + w1;
    // s.prepend(w1);
    // // std::cout << s.head << std::endl;
    // s.show();
    // std::cout << std::endl;
    // s.prepend(w);
    // s.append(w1);
    // s.show();
    // std::cout << std::endl;
    // s = w + s;
    // s.show();
    // std::cout << std::endl;
    // s = s + *w;
    // delete w;
    // s.show();

    // Story story = Story("STORIES/Brady.txt");
    // // // Story story = Story("STORIES/FreshPrince.txt");
    // // // Story story = Story("STORIES/Gilligan.txt");
    // story.show();
    // story.save("outstory.txt");
    
    // std::ifstream file("input.txt");
    // std::string input((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    // int length = input.length();
    // char charArray[length];
    // for(unsigned int i = 0; i < length; i ++){
    // 	charArray[i] = input[i];
    // }
    // Word word;
    // Sentence sentence;
    // Paragraph paragraph;
    // Story story;
    // int i = 0;
    // while(charArray[i] != '\0'){
    // 	char c = charArray[i];
    // 	// std::cout << i << std::endl;
    // 	// std::cout << c << std::endl;
    // 	// if(c == '\t'){
    // 	//     std::cout << "TABBED" << std::endl;
    // 	// }
    // 	// std::cout << +c << std::endl;
    // 	if(i == 0){
    // 	    if(c == '\t'){
    // 		word = Word(charArray + i + 1);	
    // 	    }else{
    // 		word = Word(charArray + i + 1);		
    // 	    }
    // 	}else{
    // 	    if(isspace(c)){
    // 		char next = charArray[i + 1];
    // 		if(next == ' ' || next == '\t' || next == '\n'){
		    
    // 		}else{
    // 		    // std::cout << "SPACED" << std::endl;
    // 		    // std::cout << "SHOWING SENTENCE" << std::endl;
    // 		    // sentence.show();
    // 		    sentence = sentence + word;
    // 		    // std::cout << "SHOWING WORD" << std::endl;
    // 		    // word.show();
    // 		    // std::cout << "SHOWING SENTENCE" << std::endl;
    // 		    // sentence.show();
    // 		    delete[] word.text;
    // 		    word = Word(charArray + i + 1);   
    // 		}
    // 	    }
    // 	    if(c == '.' || c == '!' || c == '?'){
    // 		sentence = sentence + word;
    // 		// delete temp;
    // 		// sentence.append(word);
    // 		delete[] word.text;
    // 		word = Word(charArray + i + 1 + 1);
    // 		++i;
    // 		// std::cout << "PERIOD" << std::endl;
    // 		// sentence.show();
    // 	    	// paragraph.append(sentence);
    // 		paragraph = paragraph + sentence;
    // 		sentence.~Sentence();
    // 		sentence = Sentence();
    // 	    }
    // 	    if(c == '\t'){
    // 		// story.append(paragraph);
    // 		story = story + paragraph;
    // 		paragraph.~Paragraph();
    // 		paragraph = Paragraph();
    // 		sentence.~Sentence();
    // 		sentence = Sentence();
    // 		word = Word(charArray + i + 1);
    // 	    }
    // 	    if(*(charArray + i + 1) == '\0'){
    // 		// story.append(paragraph);
    // 		story = story + paragraph;
    // 		paragraph.~Paragraph();
    // 		paragraph = Paragraph();		
    // 	    }
    // 	}
    // 	++i;	
    // }        
    // story.show();
}
