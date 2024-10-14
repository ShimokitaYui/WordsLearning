#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include <QString>
#include <WordsManager.h>
#include <SettingDialog.h>
#include <TranslateDialog.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowClass; };
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void keyPressEvent(QKeyEvent* event) override;
public slots:
    void setting();
    void errorHandler();
private:
    Ui::MainWindowClass *ui;
    WordsManager* _manager;
    SettingDialog* _setting;
    TranslateDialog* tranDialog;
};
