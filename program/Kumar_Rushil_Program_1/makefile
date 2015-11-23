all:	make_exe

make_exe:	story_obj
	g++ -g -std=c++11 Word.o Sentence.o Paragraph.o Story.o Chelsea_grader.o -o Driver.exe

story_obj: 	paragraph_obj
	g++ -g -std=c++11 -c Story.cpp

paragraph_obj: 	sentence_obj
	g++ -c -g -std=c++11 Paragraph.cpp

sentence_obj: 	word_obj
	g++ -c -g -std=c++11 Sentence.cpp

word_obj: 	driver_obj
	g++ -c -g -std=c++11 Word.cpp

# driver_obj:
# 	g++ -c -g -std=c++11 Driver.cpp

driver_obj:
	g++ -c -g -std=c++11 Chelsea_grader.cpp

clean:
	rm *.o *.exe
