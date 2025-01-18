#include "databasemanager.h"

DatabaseManager::DatabaseManager(const QString& dbName, QObject *parent)
    : QObject(parent), dbName_(dbName)
{
}

DatabaseManager::~DatabaseManager()
{
    close();
}

bool DatabaseManager::open()
{
    db_ = QSqlDatabase::addDatabase("QSQLITE");
    db_.setDatabaseName(dbName_);

    if (!db_.open())
    {
        qDebug() << "Error opening database:" << db_.lastError().text();
        return false;
    }

    return true;
}

void DatabaseManager::close()
{
    if (db_.isOpen()) {
        db_.close();
    }
}

bool DatabaseManager::isOpen() const
{
    return db_.isOpen();
}

QSqlQuery DatabaseManager::executeQuery(const QString& query)
{
    QSqlQuery q(db_);
    if (!q.exec(query))
    {
        qDebug() << "Error executing query:" << query << q.lastError().text();
    }
    return q;
}

QSqlQuery DatabaseManager::executeQuery(const QString& query, const QVariantList& values)
{
    QSqlQuery q(db_);
    q.prepare(query);
    for (int i = 0; i < values.size(); ++i) {
        q.bindValue(i, values[i]);
    }
    if (!q.exec())
    {
        qDebug() << "Error executing prepared query:" << query << q.lastError().text();
    }
    return q;
}


QVariant DatabaseManager::getSingleValue(const QString& query)
{
    QSqlQuery q = executeQuery(query);
    if (q.next()) {
        return q.value(0);
    }
    return QVariant();
}

QVariant DatabaseManager::getSingleValue(const QString& query, const QVariantList& values)
{
    QSqlQuery q = executeQuery(query, values);
    if (q.next()) {
        return q.value(0);
    }
    return QVariant();
}


QList<QVariantList> DatabaseManager::getMultipleValues(const QString& query)
{
    QList<QVariantList> result;
    QSqlQuery q = executeQuery(query);
    while (q.next()) {
        QVariantList row;
        for(int i = 0; i < q.record().count(); ++i){
            row.append(q.value(i));
        }
        result.append(row);
    }
    return result;
}

QList<QVariantList> DatabaseManager::getMultipleValues(const QString& query, const QVariantList& values)
{
    QList<QVariantList> result;
    QSqlQuery q = executeQuery(query, values);
    while (q.next()) {
        QVariantList row;
        for(int i = 0; i < q.record().count(); ++i){
            row.append(q.value(i));
        }
        result.append(row);
    }
    return result;
}
