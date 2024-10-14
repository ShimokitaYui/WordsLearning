#include "WordsManager.h"
#include <QDateTime>
#include<QRandomGenerator>
#include <QDebug>
#include <QTime>
#include <QtGlobal>
#include <QMessageBox>
WordsManager::WordsManager(QObject *parent)
	: QObject(parent)
{
	_words.clear();
	_oldWords.clear();
	isTrue_1 = false;
	QDateTime current_date_time = QDateTime::currentDateTime();
	_fileName = current_date_time.toString("yyyy_MM_dd");
	_fileName.push_back(".txt");
	_filePath = "D:/";
	_file = new QFile(_filePath + "/" + _fileName);
	newWords = "";
	readFile(_filePath + "/" + _fileName);
}

WordsManager::~WordsManager()
{
	if (!_file->isOpen()) {
		if (!_file->open(QIODevice::ReadWrite)) {
			emit errorPath();
		}
		else {
			out = new QTextStream(_file);
		}
	}
	if (out) {
		for (int i = 0; i < _words.size(); i++) {
			*out << _words[i]->Words;
			*out << " " << _words[i]->trueTimes;
			*out << " " << _words[i]->falseTimes;
			*out << "\n";
		}
		if (!newWords.isEmpty()) {
			*out << newWords;
			*out << " " << 0;
			*out << " " << 0;
			*out << "\n";
		}
		delete out;
	}
	if (_file) {
		_file->close();
		delete _file;
	}
}

void WordsManager::setNewWord(QString newWord) 
{
	if (_words.isEmpty()) {
		emit getNewWord();
		_words.push_back(new Word(this, newWord));
	}
	else {
		int n = _words.size();
		int rand = QRandomGenerator::global()->bounded(n);  // 使用当前时间的毫秒数来设置种子
		_temp = _words[rand];
		_words[rand] = _words[_words.size() - 1];
		_words[_words.size() - 1] = _temp;
		oldWords = _temp->Words;
		emit getOldWord(_temp->Words);
	}
	newWords = newWord;
}

void WordsManager::setPath(QString path) 
{
	this->_filePath = path;
	if (_file) {
		_file->close();
		delete _file;
		_file = nullptr;
	}
	if (out) {
		delete out;
		out = nullptr;
	}
	_file = new QFile(path + "/" + _fileName);
	if (!_file->open(QIODevice::ReadWrite)) {
		emit errorPath();
	}
	else {
		out = new QTextStream(_file);
	}
}

void WordsManager::setYes() 
{
	isTrue_1 = true;
}

void WordsManager::setNo() 
{
	isTrue_1 = false;
}

void WordsManager::setYes_2()
{
	if (isTrue_1) {
		_temp->trueTimes += 1;
		if (_temp->trueTimes - _temp->falseTimes >= 5) {
			if (_file->isOpen()) {
				_oldWords.push_back(_temp);
				*out << _temp->Words;
				*out << " " << _temp->trueTimes;
				*out << " " << _temp->falseTimes;
				*out << "\n";
				_words[_words.size() - _curnum - 1] = _words[_words.size() - 1];
				_words[_words.size() - 1] = _temp;
				_words.pop_back();
			}
			else {
				if (!_file->open(QIODevice::ReadWrite)) {
					emit errorPath();
				}
				else {
					out = new QTextStream(_file);
					_oldWords.push_back(_temp);
					*out << _temp->Words;
					*out << " " << _temp->trueTimes;
					*out << " " << _temp->falseTimes;
					*out << "\n";
					_words[_words.size() - _curnum - 1] = _words[_words.size() - 1];
					_words[_words.size() - 1] = _temp;
					_words.pop_back();
				}
			}
		}
		else {
			_curnum += 1;
		}
		if (_curnum == _words.size()) {
			_curnum = 0;
			emit getNewWord();
			_words.push_back(new Word(this, newWords));
			newWords = "";
		}
		else {
			int n = _words.size() - _curnum;
			int rand = QRandomGenerator::global()->bounded(n);  // 使用当前时间的毫秒数来设置种子
			_temp = _words[rand];
			_words[rand] = _words[_words.size() - _curnum - 1];
			_words[_words.size() - _curnum - 1] = _temp;
			oldWords = _temp->Words;
			emit getOldWord(_temp->Words);
		}
	}
	else {
		setNo_2();
	}
}

void WordsManager::setNo_2() 
{
	_temp->falseTimes += 1;
	int n = _words.size() - _curnum;
	int rand = QRandomGenerator::global()->bounded(n);  // 使用当前时间的毫秒数来设置种子
	_temp = _words[rand];
	_words[rand] = _words[_words.size() - 1 - _curnum];
	_words[_words.size() - 1 - _curnum] = _temp;
	oldWords = _temp->Words;
	emit getOldWord(_temp->Words);
}

QString WordsManager::oldWord()
{
	return oldWords;
}

void WordsManager::setFileName(QString fileName)
{
	_fileName = fileName;
	if (_file) {
		_file->close();
		delete _file;
		_file = nullptr;
	}
	if (out) {
		delete out;
		out = nullptr;
	}
	_file = new QFile(_filePath + "/" + _fileName);
}

QString WordsManager::getFileName()
{
	return _fileName;
}

QString WordsManager::getPath()
{
	return _filePath;
}

void WordsManager::readFile(QString path)
{
	init();
	
	QFile tempFile(path);
	qDebug() << path;
	if (tempFile.open(QIODevice::ReadOnly)) {
		// 创建QTextStream对象用于读取文件  
		QTextStream in(&tempFile);
		// 逐行读取文件内容  
		while (!in.atEnd()) {
			QString line = in.readLine();
			qDebug() << line;
			line.push_back(' ');
			QString temp;
			uint8_t index = 0;
			Word* tW = nullptr;
			qDebug() << index;
			for (int i = 0; i < line.size(); i++) {
				if (line[i] == ' ') {
					switch (index) {
					case 0:
						tW = new Word(this, temp);
						index++;
						temp.clear();
						break;
					case 1:
						if (tW == nullptr) break;
						tW->trueTimes = temp.toUShort();
						index++;
						temp.clear();
						break;
					case 2:		
						if (tW == nullptr) break;
						index++;
						tW->falseTimes = temp.toUShort();
						if (tW->trueTimes - tW->falseTimes >= 5) {
							_oldWords.push_back(tW);
						}
						else {
							_words.push_back(tW);
						}
						temp.clear();
						break;
					default:
						break;
					}
				}
				else {
					temp.push_back(line[i]);
				}
			}
		}
		// 关闭文件  
		tempFile.close();
		qDebug() << _words.size();
		qDebug() << _oldWords.size();
	}
	else {
		emit errorPath();
	}
}

void WordsManager::init() {
	for (int i = 0; i < _words.size(); i++) {
		delete _words[i];
	}
	for (int i = 0; i < _oldWords.size(); i++) {
		delete _oldWords[i];
	}
	_words.clear();
	_oldWords.clear();
	isTrue_1 = false;
	newWords = "";
	_curnum = 0;
}