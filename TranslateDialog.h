#pragma once

#include <QDialog>
#include "ui_TranslateDialog.h"
#include <TencentTranslator.h>
#include <QKeyEvent>
#include <QCloseEvent>
QT_BEGIN_NAMESPACE
namespace Ui { class TranslateDialogClass; };
QT_END_NAMESPACE

class TranslateDialog : public QDialog
{
	Q_OBJECT

public:
	TranslateDialog(QWidget* parent = nullptr);
	TranslateDialog(QWidget *parent, QString target);
	~TranslateDialog();

private:
	Ui::TranslateDialogClass *ui;
	TencentTranslator* translator;
protected:
	void keyPressEvent(QKeyEvent* event) override;
	void closeEvent(QCloseEvent* event) override;
signals:
	void getYes();
	void getNo();
	void handleClosed();
};
