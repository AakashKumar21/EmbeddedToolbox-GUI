#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>


class Settings : public QObject
{
    Q_OBJECT
public:
    explicit Settings(QObject *parent, QString filename);

private:
    void ReadJsonFile();
    QString m_filename;
    QString ReadFromInternalRes();
    QJsonObject GetJsonObject(const QString &rawJson);

private:

signals:

};

#endif // SETTINGS_H
