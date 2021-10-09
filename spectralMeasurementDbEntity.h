#ifndef SPECTRALMEASUREMENTDBENTITY_H
#define SPECTRALMEASUREMENTDBENTITY_H

#include<qdbmanager/entities/baseEntity.h>
#include<QUuid>

class SpectralMeasurementDbEntity:public BaseEntity
{    
    Q_OBJECT
    Q_TABLENAME(SpectralMeasurement)

    Q_FIELD(QString,uid)
    Q_FIELD(QString,mac)

public:
    explicit SpectralMeasurementDbEntity(QObject* parent=0);

    QString get_uid();
    void set_uid(QString uid);

    QString get_mac();
    void set_mac(QString mac);

    virtual QString toString() { return get_mac(); }

    virtual bool equals(QObject *elem) { return qobject_cast<SpectralMeasurementDbEntity*>(elem)->toString() == toString(); }

signals:
    void changed_uid(QString uid);
    void changed_mac(QString mac);

private:
    QString uid;
    QString mac;
};

Q_DECLARE_METATYPE(SpectralMeasurementDbEntity*)

typedef QList<SpectralMeasurementDbEntity*>          QListSpectralMeasurementDbEntity;
typedef QMap<int,QListSpectralMeasurementDbEntity>   QMapSpectralMeasurementDbEntity;

#endif // SPECTRALMEASUREMENTDBENTITY_H
