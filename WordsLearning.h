#pragma once

#include <QWidget>
#include "ui_WordsLearning.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WordsLearningClass; };
QT_END_NAMESPACE

class WordsLearning : public QWidget
{
	Q_OBJECT

public:
	WordsLearning(QWidget *parent = nullptr);
	~WordsLearning();
	void setOldWords(QString);
	void getNewWords();
private:
	Ui::WordsLearningClass *ui;
	bool isInput;
signals:
	void yesBtn();
	void noBtn();
	void newWords(QString);
};
