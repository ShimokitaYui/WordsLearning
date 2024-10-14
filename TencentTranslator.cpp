#include "TencentTranslator.h"
#include <QSettings>
// ��ʼ��
QString TencentTranslator::translation_API = "https://fanyi-api.baidu.com/api/trans/vip/";             // ����API
QString TencentTranslator::language_recognition_API = "https://fanyi-api.baidu.com/api/trans/vip/language";    // ����ʶ��API

QString TencentTranslator::APPID = "";  // ����ƽ̨ID �û���������
QString TencentTranslator::KEY = "";     // ��Կ

QString TencentTranslator::hover_translationwindow_open = "ON";

TencentTranslator::~TencentTranslator()
{}

TencentTranslator::TencentTranslator(QObject* parent) : QObject(parent)
{
    this->manager = new QNetworkAccessManager();
    QObject::connect(this->manager, &QNetworkAccessManager::finished, this, &TencentTranslator::replyFinished);

    //// ��Ӽ�ֵ��
    //map.insert("����", "zh");
    //map.insert("Ӣ��", "en");
    //map.insert("����", "yue");
    //map.insert("������", "wyw");
    //map.insert("����", "jp");
    //map.insert("����", "kor");
    //map.insert("����", "fra");
    //map.insert("��������", "spa");
    //map.insert("̩��", "th");
    //map.insert("��������", "ara");
    //map.insert("����", "ru");
    //map.insert("��������", "pt");
    //map.insert("����", "de");
    //map.insert("�������", "it");
    //map.insert("ϣ����", "el");
    //map.insert("������", "nl");
    //map.insert("������", "pl");
    //map.insert("����������", "bul");
    //map.insert("��ɳ������", "est");
    //map.insert("������", "dan");
    //map.insert("������", "fin");
    //map.insert("�ݿ���", "cs");
    //map.insert("����������", "rom");
    //map.insert("˹����������", "slo");
    //map.insert("�����", "swe");
    //map.insert("��������", "hu");
    //map.insert("��������", "cht");
    //map.insert("Խ����", "vie");
}

QString TencentTranslator::salt()
{
    // ����ʱ���
    return QString::number(QDateTime::currentSecsSinceEpoch());
}

QString TencentTranslator::md5(QString str)
{
    return QCryptographicHash::hash(str.toUtf8(), QCryptographicHash::Md5).toHex();
}

void TencentTranslator::replyFinished(QNetworkReply* reply)
{
    QString relust = reply->readAll();

    QJsonParseError parseError;
    QJsonDocument document = QJsonDocument::fromJson(relust.toUtf8(), &parseError);

    if (parseError.error != QJsonParseError::NoError)
    {
        relust = "JSON parse error:" + parseError.errorString();
        emit translationFinished(relust); //��������
        return;
    }

    if (!document.isObject()) {
        relust = "JSON document is not an object";
        emit translationFinished(relust); //��������
        return;
    }

    QJsonObject jsonobject = document.object();

    if (jsonobject.contains("error_code") && !jsonobject["error_code"].isUndefined()) //isUndefine �Ƿ�δ����ü�
    {
        relust = "error_code: " + jsonobject["error_code"].toString() + "\n";
        relust += "error_msg: " + jsonobject["error_msg"].toString();
        emit translationFinished(relust); //��������
        return;
    }

    QJsonArray list = jsonobject["trans_result"].toArray();
    relust = "";
    for (int i = 0; i < list.size(); i++)
    {
        QString text = list.at(i).toObject()["dst"].toString();
        relust += text + "\n";
    }

    emit translationFinished(relust); //��������
}

QString TencentTranslator::get_language(QString text)
{
    return text;
}

void TencentTranslator::translation(QString text, QString language)
{
    QString thesalt = TencentTranslator::salt();
    QString str = QString("%1%2%3%4").arg(
        TencentTranslator::APPID
    ).arg(
        text
    ).arg(
        thesalt
    ).arg(
        TencentTranslator::KEY
    );

    QString sign = TencentTranslator::md5(str);
    QString url = QString("%1?q=%2&from=auto&to=%3&appid=%4&salt=%5&sign=%6").arg(
        TencentTranslator::translation_API
    ).arg(
        text
    ).arg(
        language
    ).arg(
        TencentTranslator::APPID
    ).arg(
        thesalt
    ).arg(
        sign
    );
    manager->get(QNetworkRequest(QUrl(url)));
}

void TencentTranslator::getini()
{
    QSettings* configIniRead = new QSettings("data/TencentTranslator.ini", QSettings::IniFormat);

    TencentTranslator::APPID = configIniRead->value("/TencentTranslator/APP_ID").toString();
    TencentTranslator::KEY = configIniRead->value("/TencentTranslator/KEY").toString();
    TencentTranslator::hover_translationwindow_open = configIniRead->value("/TencentTranslator/Hover_window").toString();

    delete configIniRead;
}

void TencentTranslator::setini(QMap<QString, QString> map)
{
    TencentTranslator::APPID = map.value("APPID");
    TencentTranslator::KEY = map.value("KEY");
    TencentTranslator::hover_translationwindow_open = map.value("hover_translationwindow_open");
    if (TencentTranslator::hover_translationwindow_open != QString("ON") && TencentTranslator::hover_translationwindow_open != QString("OFF"))
    {
        TencentTranslator::hover_translationwindow_open = QString("ON");
    }

    QSettings* configIniwrite = new QSettings("data/TencentTranslator.ini", QSettings::IniFormat);
    configIniwrite->setValue("/TencentTranslator/APP_ID", APPID);
    configIniwrite->setValue("/TencentTranslator/KEY", KEY);
    configIniwrite->setValue("/TencentTranslator/Hover_window", hover_translationwindow_open);

    delete configIniwrite;
}
