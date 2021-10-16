#ifndef TESTENTITY_H
#define TESTENTITY_H

#include <QObject>

class TestEntity : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)

    int m_id;
    QString m_name;
public:
    Q_INVOKABLE explicit TestEntity(QObject *parent = nullptr);

    int getId() const;
    void setId(int id);

    QString getName() const;
    void setName(QString name);

signals:

    void idChanged();
    void nameChanged();

};

#endif // TESTENTITY_H
