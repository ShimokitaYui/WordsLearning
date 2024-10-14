#pragma once

#include <QDialog>
#include "ui_SettingDialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SettingDialogClass; };
QT_END_NAMESPACE

class SettingDialog : public QDialog
{
	Q_OBJECT

public:
	SettingDialog(QWidget *parent = nullptr);
	~SettingDialog();
protected:
	void closeEvent(QCloseEvent* event) override;
public slots:
	void setPath(QString);
	void setFileName(QString);
signals:
	void getPath(QString);
	void getFileName(QString);
	void handleClosed();
	void readFile(QString);
private:
	Ui::SettingDialogClass *ui;
};
