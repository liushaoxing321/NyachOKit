#include "Note.hpp"
#include "Section.hpp"
#include <iostream>
int main(int argc, char *argv[], char *envp[]) {
	float location[2] = { 12,12 };
	std::list<Section> listSec;
	Section sect = Section::Section(12.0, 12.0);
	listSec.push_back(sect);
	Note NT = Note::Note(location, listSec);
	std::cout << NT.Serialize().dump();
	return 0;
}