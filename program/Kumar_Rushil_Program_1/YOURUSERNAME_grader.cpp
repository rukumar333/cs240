#include "Word.h"
#include "Sentence.h"
#include "Paragraph.h"
#include "Story.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

/*
	Fill in the following program according to the comments.

	As you add your functionality, remove the print statements, and
	comment out the "incomplete" increment.

	If your program does not have a certain functionality implemented
	leave the print statement instead.

	Also leave the print statement if your implementation is incomplete
	or causes a segfault with your code.
*/

int main()
{
	int fi = 0;

	//--------- FILE IO ----------------------

	cout<<endl<<"----------------------------------------------"<<endl;
	cout<<"FILE IO FUNCTIONS"<<endl'

	//read in file Brady.txt to create a story
	cout<<"Reading file for story not implemented"<<endl;
	++fi;

	//save story
	cout<<"Save story not implemented"<<endl;
	++fi;

	//print out story
	cout<<"<< for story not implemented"<<endl;
	++fi;

	cout<<endl<<"----------------------------------------------"<<endl;

	//--------- FIRST FUNCTIONS --------------

	cout<<endl<<"----------------------------------------------"<<endl;
	cout<<"FIRST FUNCTIONS"<<endl;

	//get paragraph using story.first()
	cout<<"story.first() not implemented"<<endl;
	++fi;

	//print out paragraph
	cout<<"<<for para not implemented"<<endl;
	++fi;

	//get sentence using para.first()
	cout<<"para.first() not implemented"<<endl;
	++fi;

	//print out sentence
	cout<<"<<for sentence not implemented"<<endl;
	++fi;

	//get word using sentence.first()
	cout<<"sentence.first() not implemented"<<endl;
	++fi;

	//print out word
	cout<<"<< for word not implemented"<<endl;
	++fi;

	cout<<endl<<"----------------------------------------------"<<endl;

	//---------- OPERATORS IN FORM A + B --------

	cout<<endl<<"----------------------------------------------"<<endl;
	cout<<"A+B OPERATORS"<<endl;

	//For this and the following sections either use the above
	//created word/sent/para/story
	//or instantiate them using some other constructor
	//After using each operator, print out the result

	//story + story = story
	cout<<"story + story = story not implemented"<<endl;
	++fi;

	//story + para = story
	cout<<"story + para = story not implemented"<<endl;
	++fi;

	//para + story = story
	cout<<"para + story = story not implemented"<<endl;
	++fi;

	//para + para = para
	cout<<"para + para = para not implemented"<<endl;
	++fi;

	//para + sentence = para
	cout<<"para + sent = para not implemented"<<endl;
	++fi;

	//sent + para = para
	cout<<"sent + para = para not implemented"<<endl;
	++fi;

	//sent + sent = para
	cout<<"sent + sent = para not implemented"<<endl;
	++fi;

	//sent + word = sent
	cout<<"sent + word = sent not implemented"<<endl;
	++fi;

	//word + sent = sent
	cout<<"word + sent = sent not implemented"<<endl;
	++fi;

	//word + word = sent
	cout<<"word + word = sent not implemented"<<endl;
	++fi;

	cout<<endl<<"----------------------------------------------"<<endl;

	//---------- OPERATORS IN FORM A++ and A-- --------------

	cout<<endl<<"----------------------------------------------"<<endl;
	cout<<"A++ AND A-- OPERATORS"<<endl;

	//word++
	cout<<"word in caps not implemented"<<endl;
	++fi;

	//word--
	cout<<"word in lower not implemented"<<endl;
	++fi;

	//sent++
	cout<<"sent in caps not implemented"<<endl;
	++fi;

	//sent--
	cout<<"sent in lower not implemented"<<endl;
	++fi;

	//para++
	cout<<"para in caps not implemented"<<endl;
	++fi;

	//para--
	cout<<"para in lower not implemented"<<endl;
	++fi;

	//story++
	cout<<"story in caps not implemented"<<endl;
	++fi;

	//story--
	cout<<"story in lower not implemented"<<endl;
	++fi;

	cout<<endl<<"----------------------------------------------"<<endl;

	//---------- OPERATORS IN FORM A+1----------

	cout<<endl<<"----------------------------------------------"<<endl;
	cout<<"A+1 OPERATORS"<<endl;

	//word+1
	cout<<"word + 1 not implemented"<<endl;
	++fi;

	//sent+1
	cout<<"sent + 1 not implemented"<<endl;
	++fi;

	//para+1
	cout<<"para + 1 not implemented"<<endl;
	++fi;

	//story+1
	cout<<"story + 1 not implemented"<<endl;
	++fi;

	cout<<endl<<"----------------------------------------------"<<endl;

	//----------- PIG LATIN OPERATORS -----------

	cout<<endl<<"----------------------------------------------"<<endl;
	cout<<"PIG LATIN OPERATORS"<<endl;

	//word pig latin
	cout<<"word in pig latin not implemented"<<endl;
	++fi;

	//word unpig latin
	cout<<"word pig latin undone not implemented"<<endl;
	++fi;

	//sent pig latin
	cout<<"sent pig latin not implemented"<<endl;
	++fi;

	//sent unpig latin
	cout<<"sent pig latin undone not implemented"<<endl;
	++fi;

	//para pig latin
	cout<<"para pig latin not implemented"<<endl;
	++fi;

	//para unpig latin
	cout<<"para pig latin undone not implemented"<<endl;
	++fi;

	//story pig latin
	cout<<"story pig latin not implemented"<<endl;
	++fi;

	//story unpig latin
	cout<<"story pig latin undone not implemented"<<endl;
	++fi;

	cout<<endl<<"----------------------------------------------"<<endl;

	cout<<endl<<"TOTAL INCOMPLETE: "<<fi<<endl;
	return 0;
}

