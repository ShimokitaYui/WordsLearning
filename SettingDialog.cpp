#include "SettingDialog.h"
#include <QRegularExpression> 
#include <QFileDialog>  
#include <QMessageBox> 

SettingDialog::SettingDialog(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::SettingDialogClass())
{
	ui->setupUi(this);
	this->setWindowTitle("Setting");
	connect(ui->lineEdit, &QLineEdit::editingFinished, this, [&]() {
		emit getPath(ui->lineEdit->text());
	});
	connect(ui->fileName, &QLineEdit::editingFinished, this, [&]() {
		emit getFileName(ui->fileName->text());
	});
	connect(ui->toolButton, &QToolButton::clicked, this, [&]() {
		QString directory = QFileDialog::getExistingDirectory(this, "Choose File", "");
		if (!directory.isEmpty()) {
			ui->lineEdit->setText(directory);
			emit getPath(directory);
		}
		else {
			QMessageBox::warning(this, "Faile Choosing", "No Choose");
		}
	});
	connect(ui->fileReadBtn, &QToolButton::clicked, this, [&]() {
		// ���� QFileDialog ʵ��  
		QFileDialog dialog;
		// �����ļ���������ֻ��ʾ .txt �ļ�  
		dialog.setNameFilter(tr("Text Files (*.txt)"));
		// ���ļ��Ի��򲢻�ȡ�ļ�·��  
		const QString fileName = dialog.getOpenFileName(nullptr, tr("Open Text File"), "", tr("Text Files (*.txt)"));
		if (!fileName.isEmpty()) {
			QString path;
			QString file;
			for (int i = 0; i < fileName.size(); i++) {
				file.push_back(fileName[i]);
				if (fileName[i] == '/') {
					path.push_back(file);
					file.clear();
				}
			}
			path.removeLast();
			ui->lineEdit->setText(path);
			ui->fileName->setText(file);
			ui->fileFullPath->setText(fileName);
			emit getPath(path);
			emit getFileName(file);
			emit readFile(fileName);
		}
		else {
			QMessageBox::warning(this, "Faile Choosing", "No File");
		}
	});
}

SettingDialog::~SettingDialog()
{
	delete ui;
}

void SettingDialog::setPath(QString path)
{
	qDebug() << path;
	ui->lineEdit->setText(path);
}

void SettingDialog::closeEvent(QCloseEvent* event)
{
	emit handleClosed();
}

void SettingDialog::setFileName(QString fileName) {
	ui->fileName->setText(fileName);
}