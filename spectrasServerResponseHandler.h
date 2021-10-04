#ifndef SPECTRASSERVERRESPONSEHANDLER_H
#define SPECTRASSERVERRESPONSEHANDLER_H

#include <QObject>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>

#include <QJsonValue>
#include "spectralMeasurement.h"
#include <QMap>


class SpectrasServerResponseHandler : public QObject
{
    Q_OBJECT
public:
    explicit SpectrasServerResponseHandler(QObject *parent = nullptr);

signals:
    void onSpectralMeasurement(SpectralMeasurement* spectralMeasurement);

public slots:
    void handleResponse(QNetworkReply *networkReply);

};

#endif // SPECTRASSERVERRESPONSEHANDLER_H
