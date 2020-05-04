#include "settings.h"
#include <QString>
#include <QDir>
#include <QFile>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonDocument>
#include "settings.h"

static auto RES_PREFIX = QStringLiteral(":/json");

Settings::Settings(QObject *parent, QString filename) :
    QObject(parent),
    m_filename(filename)
{

}

//void Settings::ReadJsonFile()
//{
////    QString raw_json
//    auto default_setting = ReadFromInternalRes();
//}

//QString Settings::ReadFromInternalRes()
//{

//}

//QJsonObject Settings::GetJsonObject(const QString& rawJson)
//{
//    QJsonParseError json_parse_err;
//    QJsonDocument json_doc =  QJsonDocument::fromJson(rawJson.toUtf8(),&json_parse_err);
//    QJsonObject json_obj = json_doc.object();
////    return std::make_pair(json_obj, json_parse_err);

//}
