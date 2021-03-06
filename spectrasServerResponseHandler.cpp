#include "spectrasServerResponseHandler.h"

SpectrasServerResponseHandler::SpectrasServerResponseHandler(QObject *parent) : QObject(parent)
{

}

void SpectrasServerResponseHandler::handleResponse(QNetworkReply *networkReply)
{
    QByteArray bytes = networkReply->readAll();
    QString str = QString::fromUtf8(bytes.data(), bytes.size());

    QJsonDocument jsonDocument = QJsonDocument::fromJson(str.toUtf8());
    QJsonObject jsonObject = jsonDocument.object();

    //QString strFromObj = QJsonDocument(jsonObject).toJson(QJsonDocument::Compact).toStdString().c_str();

    QJsonValue valuesArrayValue = jsonObject.value("values");
    //QJsonArray valuesArray = valuesArrayValue.toArray();

    QVariantMap jsonMap=jsonObject.toVariantMap();
    QMap valuesMap=jsonMap.value("values").toMap();

    //QList valuesList=valuesMap.keys().toList();

    SpectralMeasurement* spectralMeasurement=new SpectralMeasurement();
    QMap<float, float>* spectralMeasurementValues=spectralMeasurement->getValues();

    foreach( QString key, valuesMap.keys() ){
        qDebug()<<key.toFloat();
        qDebug()<<valuesMap.value(key).toFloat();

        QMap<float,float>* foo=new QMap<float,float>();

        spectralMeasurementValues->insert(key.toFloat(),valuesMap.value(key).toFloat());
    }

    emit this->onSpectralMeasurement(spectralMeasurement);

}
