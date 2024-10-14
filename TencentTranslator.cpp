#include "TencentTranslator.h"
#include <QSettings>
// 初始化
QString TencentTranslator::translation_API = "https://fanyi-api.baidu.com/api/trans/vip/";             // 翻译API
QString TencentTranslator::language_recognition_API = "https://fanyi-api.baidu.com/api/trans/vip/language";    // 语种识别API

QString TencentTranslator::APPID = "";  // 翻译平台ID 用户自行申请
QString TencentTranslator::KEY = "";     // 密钥

QString TencentTranslator::hover_translationwindow_open = "ON";

TencentTranslator::~TencentTranslator()
{}

TencentTranslator::TencentTranslator(QObject* parent) : QObject(parent)
{
    this->manager = new QNetworkAccessManager();
    QObject::connect(this->manager, &QNetworkAccessManager::finished, this, &TencentTranslator::replyFinished);

    //// 添加键值对
    //map.insert("中文", "zh");
    //map.insert("英语", "en");
    //map.insert("粤语", "yue");
    //map.insert("文言文", "wyw");
    //map.insert("日语", "jp");
    //map.insert("韩语", "kor");
    //map.insert("法语", "fra");
    //map.insert("西班牙语", "spa");
    //map.insert("泰语", "th");
    //map.insert("阿拉伯语", "ara");
    //map.insert("俄语", "ru");
    //map.insert("葡萄牙语", "pt");
    //map.insert("德语", "de");
    //map.insert("意大利语", "it");
    //map.insert("希腊语", "el");
    //map.insert("荷兰语", "nl");
    //map.insert("波兰语", "pl");
    //map.insert("保加利亚语", "bul");
    //map.insert("爱沙尼亚语", "est");
    //map.insert("丹麦语", "dan");
    //map.insert("芬兰语", "fin");
    //map.insert("捷克语", "cs");
    //map.insert("罗马尼亚语", "rom");
    //map.insert("斯洛文尼亚语", "slo");
    //map.insert("瑞典语", "swe");
    //map.insert("匈牙利语", "hu");
    //map.insert("繁体中文", "cht");
    //map.insert("越南语", "vie");
}

QString TencentTranslator::salt()
{
    // 生成时间戳
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
        emit translationFinished(relust); //发射数据
        return;
    }

    if (!document.isObject()) {
        relust = "JSON document is not an object";
        emit translationFinished(relust); //发射数据
        return;
    }

    QJsonObject jsonobject = document.object();

    if (jsonobject.contains("error_code") && !jsonobject["error_code"].isUndefined()) //isUndefine 是否未定义该键
    {
        relust = "error_code: " + jsonobject["error_code"].toString() + "\n";
        relust += "error_msg: " + jsonobject["error_msg"].toString();
        emit translationFinished(relust); //发射数据
        return;
    }

    QJsonArray list = jsonobject["trans_result"].toArray();
    relust = "";
    for (int i = 0; i < list.size(); i++)
    {
        QString text = list.at(i).toObject()["dst"].toString();
        relust += text + "\n";
    }

    emit translationFinished(relust); //发射数据
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
