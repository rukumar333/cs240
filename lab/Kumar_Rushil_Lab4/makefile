all:	make_exe

make_exe:	story_obj
	g++ Word.o Sentence.o Paragraph.o Story.o Driver.o -o Driver.exe

story_obj: 	paragraph_obj
	g++ -c Story.cpp

paragraph_obj: 	sentence_obj
	g++ -c Paragraph.cpp

sentence_obj: 	word_obj
	g++ -c Sentence.cpp

word_obj: 	driver_obj
	g++ -c Word.cpp

driver_obj:
	g++ -c Driver.cpp

clean:
	rm *.o *.exe
