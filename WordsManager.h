#pragma once

#include <QObject>
#include <QFile>
#include <QVector>
#include <Word.h>
#include <QMap>
class WordsManager  : public QObject
{
	Q_OBJECT
public:
	WordsManager(QObject *parent);
	~WordsManager();
public slots:
	void setNewWord(QString);
	void setPath(QString);
	void setYes();
	void setNo();
	void setYes_2();
	void setNo_2();
	void setFileName(QString);
	QString getFileName();
	QString getPath();
	void readFile(QString);
	void init();
public:
	QString oldWord();
private:
	QString _filePath;//Save Filecase
	QFile* _file;
	QString newWords;
	QString oldWords;
	QVector<Word*> _words;
	Word* _temp;
	QVector<Word*> _oldWords;
	QTextStream* out;
	int _curnum;
	bool isTrue_1;
	QString _fileName;
signals:
	void getOldWord(QString);
	void getNewWord();
	void errorPath();
};
