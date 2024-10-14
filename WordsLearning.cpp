#include "WordsLearning.h"
#include <QDebug>
WordsLearning::WordsLearning(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::WordsLearningClass())
{
	ui->setupUi(this);
	isInput = true;
	connect(this->ui->btnY, &QPushButton::clicked, this, [&]() {
		if(isInput == false)
			emit this->yesBtn();
	});
	connect(this->ui->btnN, &QPushButton::clicked, this, [&]() {
		if (isInput == false)
			emit this->noBtn();
	});
	connect(this->ui->lineEdit, &QLineEdit::returnPressed, this, [&]() {
		isInput = false;
		QString temp = ui->lineEdit->text();
		ui->lineEdit->setEnabled(false);
		ui->lineEdit->clear();
		ui->lineEdit->setPlaceholderText("Wait For Old Words");
		emit this->newWords(temp);
	});
}

WordsLearning::~WordsLearning()
{
	delete ui;
}

void WordsLearning::setOldWords(QString word) {
	ui->lineEdit->setEnabled(false);
	ui->lineEdit->setPlaceholderText("");
	ui->lineEdit->setText(word);
	isInput = false;
}

void WordsLearning::getNewWords() {
	ui->lineEdit->clear();
	ui->lineEdit->setEnabled(true);
	ui->lineEdit->setPlaceholderText("Place Enter New Words");
	ui->lineEdit->setFocus();
	isInput = true;
}