#include "TranslateDialog.h"
#include <QKeyEvent>
TranslateDialog::TranslateDialog(QWidget* parent)
	: QDialog(parent)
	, ui(new Ui::TranslateDialogClass())
{
	ui->setupUi(this);
	this->setWindowTitle("Second Confirm");
	translator = new TencentTranslator(this);
	translator->translation("happy", "zh");
	ui->en_t->setText("happy");
	ui->zh_t->setText("Wait for Translate");
	connect(translator, &TencentTranslator::translationFinished, this, [&](QString temp) {
		ui->zh_t->setText(temp);
	});
}


TranslateDialog::TranslateDialog(QWidget *parent, QString target)
	: QDialog(parent)
	, ui(new Ui::TranslateDialogClass())
{
	ui->setupUi(this);
	translator = new TencentTranslator(this);
	translator->translation(target, "zh");
	ui->en_t->setText(target);
	ui->zh_t->setText("Wait for Translate");
	connect(translator, &TencentTranslator::translationFinished, this, [&](QString temp) {
		ui->zh_t->setText(temp);
	});
}

TranslateDialog::~TranslateDialog()
{
	delete ui;
}

void TranslateDialog::keyPressEvent(QKeyEvent* event) {
	if (event->key() == Qt::Key_1) {
		emit getYes();
		this->close();
	}
	else if (event->key() == Qt::Key_2) {
		emit getNo();
		this->close();
	}
	QWidget::keyPressEvent(event);
}

void TranslateDialog::closeEvent(QCloseEvent* event)
{
	emit handleClosed();
}
