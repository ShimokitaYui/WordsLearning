#include "MainWindow.h"
#include <WordsLearning.h>
#include <QKeyEvent>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowClass())
{
    ui->setupUi(this);
    this->setWindowTitle("Language Learning");
    _manager = new WordsManager(this);
    _manager->setPath("D:\\");
    
    connect(_manager, &WordsManager::getNewWord, ui->widget, &WordsLearning::getNewWords);
    connect(ui->widget, &WordsLearning::newWords, _manager, &WordsManager::setNewWord);
    connect(ui->widget, &WordsLearning::yesBtn, this, [&]() {
        emit _manager->setYes();
        if (!tranDialog) {
            tranDialog = new TranslateDialog(this, _manager->oldWord());
            tranDialog->show();
            connect(tranDialog, &TranslateDialog::getYes, _manager, &WordsManager::setYes_2);
            connect(tranDialog, &TranslateDialog::getNo, _manager, &WordsManager::setNo_2);
            connect(tranDialog, &TranslateDialog::handleClosed, this, [&]() {
                delete tranDialog;
                tranDialog = nullptr;
                });
        }
    }); 
    connect(ui->widget, &WordsLearning::noBtn, this, [&]() {
        emit _manager->setNo();
        if (!tranDialog) {
            tranDialog = new TranslateDialog(this, _manager->oldWord());
            tranDialog->show();
            connect(tranDialog, &TranslateDialog::getYes, _manager, &WordsManager::setYes_2);
            connect(tranDialog, &TranslateDialog::getNo, _manager, &WordsManager::setNo_2);
            connect(tranDialog, &TranslateDialog::handleClosed, this, [&]() {
                delete tranDialog;
                tranDialog = nullptr;
                });
        }
    });
    connect(_manager, &WordsManager::getOldWord, ui->widget, &WordsLearning::setOldWords);
    connect(ui->actionSetting, &QAction::triggered, this, &MainWindow::setting);
    connect(_manager, &WordsManager::errorPath, this, &MainWindow::errorHandler);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_1) {
        emit _manager->setYes();
        if (!tranDialog) {
            tranDialog = new TranslateDialog(this, _manager->oldWord());
            tranDialog->show();
            connect(tranDialog, &TranslateDialog::getYes, _manager, &WordsManager::setYes_2);
            connect(tranDialog, &TranslateDialog::getNo, _manager, &WordsManager::setNo_2);
            connect(tranDialog, &TranslateDialog::handleClosed, this, [&]() {
                delete tranDialog;
                tranDialog = nullptr;
            });
        }
    }
    else if (event->key() == Qt::Key_2) {
        emit _manager->setNo();
        if (!tranDialog) {
            tranDialog = new TranslateDialog(this, _manager->oldWord());
            tranDialog->show();
            connect(tranDialog, &TranslateDialog::getYes, _manager, &WordsManager::setYes_2);
            connect(tranDialog, &TranslateDialog::getNo, _manager, &WordsManager::setNo_2);
            connect(tranDialog, &TranslateDialog::handleClosed, this, [&]() {
                delete tranDialog;
                tranDialog = nullptr;
            });
        }
    }
    QWidget::keyPressEvent(event);
}

void MainWindow::setting() 
{
    if (_setting) {
        return;
    }
    _setting = new SettingDialog(this);    
    _setting->setFileName(_manager->getFileName());
    _setting->setPath(_manager->getPath());    
    connect(_setting, &SettingDialog::handleClosed, this, [&]() {
        delete _setting;
        _setting = nullptr;
    });
    connect(_setting, &SettingDialog::getPath, _manager, &WordsManager::setPath);
    connect(_setting, &SettingDialog::getFileName, _manager, &WordsManager::setFileName);
    connect(_setting, &SettingDialog::readFile, _manager, &WordsManager::readFile);
    _setting->exec();
}

void MainWindow::errorHandler() {
    QMessageBox::critical(this, "Faile Choosing", "No Such File");
}