#ifndef SPECTRASSERVERRESPONSEHANDLER_H
#define SPECTRASSERVERRESPONSEHANDLER_H

#include <QObject>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>

#include <QJsonValue>

class SpectrasServerResponseHandler : public QObject
{
    Q_OBJECT
public:
    explicit SpectrasServerResponseHandler(QObject *parent = nullptr);

public slots:
    void handleResponse(QNetworkReply *networkReply);

};

#endif // SPECTRASSERVERRESPONSEHANDLER_H
