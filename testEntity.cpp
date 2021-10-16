#include "testEntity.h"

TestEntity::TestEntity(QObject *parent) : QObject(parent)
{

}


int TestEntity::getId() const
{
    return m_id;
}

void TestEntity::setId(int id)
{
    if (m_id == id)
        return;

    m_id = id;
    emit idChanged();
}

QString TestEntity::getName() const
{
    return m_name;
}

void TestEntity::setName(QString name)
{
    if (m_name == name)
        return;

    m_name = name;
    emit nameChanged();
}
