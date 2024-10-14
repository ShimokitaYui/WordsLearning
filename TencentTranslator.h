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
    static QString translation_API;             // 翻译API
    static QString language_recognition_API;    // 语种识别API

    static QString APPID;  // 翻译平台ID 用户自行申请
    static QString KEY;     // 密钥

    static QString hover_translationwindow_open;

    static void getini(); // 读取配置
    static void setini(QMap<QString, QString> map); // 设置配置

    QString salt();  // 生成时间戳
    QString md5(QString str);    // md5加密

    QNetworkAccessManager* manager;
    QMap<QString, QString> map;

    void replyFinished(QNetworkReply* reply);

    QString get_language(QString text); // 获取语种
    void translation(QString text, QString language);   // 翻译并返回结果。

signals:
    void translationFinished(QString relust);
};
