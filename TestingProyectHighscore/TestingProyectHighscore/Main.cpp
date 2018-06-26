#include <iostream>
#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/listbox.hpp>
#include "MugettiSimpleScoreLib.h"

using namespace std;
using namespace nana;

void main()
{
	int value = 0;
	//char* name = new char();
	char name[NOMTAM];

	MugettiSimpleScoreLib* highscores = new MugettiSimpleScoreLib();

	// Dato 0
	strcpy(name, "aaa");
	highscores->RecordCurrentScore(100, name);
	// Dato 0
	strcpy(name, "asd");
	highscores->RecordCurrentScore(232, name);
	// Dato 0
	strcpy(name, "avc");
	highscores->RecordCurrentScore(568, name);
	// Dato 0
	strcpy(name, "xdd");
	highscores->RecordCurrentScore(666, name);
	// Dato 0
	strcpy(name, "ale");
	highscores->RecordCurrentScore(420, name);
	// Dato 0
	strcpy(name, "jyl");
	highscores->RecordCurrentScore(22, name);
	// Dato 0
	strcpy(name, "das");
	highscores->RecordCurrentScore(55, name);
	// Dato 0
	strcpy(name, "hfe");
	highscores->RecordCurrentScore(200, name);
	// Dato 0
	strcpy(name, "zqa");
	highscores->RecordCurrentScore(650, name);
	
	// Nana things
	form fm;

	listbox lstBox(fm, nana::rectangle(10, 10, 280, 180));
	lstBox.append_header("Score", 150);
	lstBox.append_header("Name", 120);

	// Define labels
	label puntaje1{ fm, "<bold blue size=16>Highscores</>" };
	puntaje1.format(true);

	//Define a button and answer the click event.
	button btn{ fm, "Quit" };
	btn.events().click([&fm] {
		fm.close(); // ACA VA EL CODIGO QUE QUEREMOS CUANDO SE PRESIONA EL BOT?N
	});

	for (int i = 0; i < BOARDTAM; i++) {
		highscores->GetPositionScore(i+1, value, name);
		lstBox.at(i).append({ to_string(static_cast<int>(value)), name });
	}

	//Layout management
	fm.div("vert <><<><weight=80% text><>><><weight=24<><button><>><>");
	fm["text"] << puntaje1;
	fm["button"] << btn;
	fm.collocate();

	place plc(fm);
	plc.div("<vert abc arrange=[20,130,20] gap=10>git");
	plc.field("abc") << puntaje1 << lstBox << btn;    //These buttons are children of fm.
	plc.collocate();
	fm.show();
	nana::exec();

	delete name;
	delete highscores;
}