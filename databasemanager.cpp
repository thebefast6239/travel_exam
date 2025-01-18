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

QList<QString> DatabaseManager::getTravelGroups()
{
    QList<QString> groups;
    QSqlQuery query = executeQuery("SELECT name FROM travel_groups;");

    while (query.next()) {
        groups.append(query.value(0).toString());
    }

    return groups;
}
QList<QVariantList> DatabaseManager::getUserRoutes(int userId)
{
    QList<QVariantList> routes;
    QSqlQuery query = executeQuery("SELECT title FROM routes WHERE user_id = ?;", {userId});

    while (query.next()) {
        QVariantList route;
        route.append(query.value(0));
        routes.append(route);
    }

    return routes;
}

bool DatabaseManager::saveRoute(int userId, const QString& title, const QString& description, int groupId, const QList<QString>& points)
{
    QSqlQuery query = executeQuery("INSERT INTO routes (user_id, group_id, title, description) VALUES (?, ?, ?, ?);",
                                   {userId, groupId, title, description});
    if (query.numRowsAffected() <= 0)
        return false;
    int routeId = query.lastInsertId().toInt();
    for (const QString& point : points) {
        executeQuery("INSERT INTO route_points (route_id, description) VALUES (?, ?);", {routeId, point});
    }

    return true;
}
bool DatabaseManager::deleteRoute(int userId, const QString& title)
{
    QSqlQuery query = executeQuery("DELETE FROM routes WHERE user_id = ? AND title = ?;",
                                   {userId, title});
    return query.numRowsAffected() > 0;
}
