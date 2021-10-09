#include "spectralMeasurementDbEntity.h"


SpectralMeasurementDbEntity::SpectralMeasurementDbEntity(QObject* parent) : BaseEntity(parent)
{
    propertyMap.insert("Uid", "");
    propertyMap.insert("Mac", "");

    QUuid u=QUuid::createUuid();
    set_uid(u.toString());
}

void SpectralMeasurementDbEntity::set_uid(QString uid)
{
    propertyMap.insert("Uid", uid);
}

QString SpectralMeasurementDbEntity::get_uid()
{
    return propertyMap.value("Uid").toString();
}

void SpectralMeasurementDbEntity::set_mac(QString mac)
{
    propertyMap.insert("Mac", mac);
}

QString SpectralMeasurementDbEntity::get_mac()
{
    return propertyMap.value("Mac").toString();
}

