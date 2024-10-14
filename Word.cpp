#include "Word.h"

Word::Word(QObject *parent, QString word)
	: QObject(parent)
{
	trueTimes = 0;
	falseTimes = 0;
	Words = word;
}

Word::~Word()
{}
