#pragma once

#include <QObject>

class Word  : public QObject
{
	Q_OBJECT

public:
	Word(QObject *parent, QString);
	~Word();
	qint8 trueTimes;
	qint8 falseTimes;
	QString Words;
};
