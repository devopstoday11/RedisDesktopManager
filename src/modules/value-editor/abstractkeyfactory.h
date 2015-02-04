#pragma once 

#include <QString>
#include <QVariantMap>
#include <QSharedPointer>
#include <functional>
#include "keymodel.h"

namespace RedisClient{
    class Connection;
}

namespace ValueEditor {

class AbstractKeyFactory
{
public:
    virtual void loadKey(QSharedPointer<RedisClient::Connection> connection,
                         QString keyFullPath, int dbIndex,
                         std::function<void(QSharedPointer<Model>)> callback) = 0;

    virtual void addKey(QSharedPointer<RedisClient::Connection> connection,
                         QString keyFullPath, int dbIndex, QString type,
                         const QVariantMap &row) = 0;

};

}
