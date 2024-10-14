#pragma once

#include <QObject>
#include <QtNetwork/qnetworkreply.h>
#include <QtNetwork/qnetworkaccessmanager.h>  
#include <QJsonObject>  
#include <QJsonDocument> 
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
class TencentTranslator  : public QObject
{
	Q_OBJECT

public:
	TencentTranslator(QObject *parent);
	~TencentTranslator();
 // API
    static QString translation_API;             // ����API
    static QString language_recognition_API;    // ����ʶ��API

    static QString APPID;  // ����ƽ̨ID �û���������
    static QString KEY;     // ��Կ

    static QString hover_translationwindow_open;

    static void getini(); // ��ȡ����
    static void setini(QMap<QString, QString> map); // ��������

    QString salt();  // ����ʱ���
    QString md5(QString str);    // md5����

    QNetworkAccessManager* manager;
    QMap<QString, QString> map;

    void replyFinished(QNetworkReply* reply);

    QString get_language(QString text); // ��ȡ����
    void translation(QString text, QString language);   // ���벢���ؽ����

signals:
    void translationFinished(QString relust);
};
