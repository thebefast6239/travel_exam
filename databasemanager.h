#pragma once
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QStringList>
#include <QVariant>
#include <QSqlRecord>

class DatabaseManager : public QObject
{
    Q_OBJECT

public:
    explicit DatabaseManager(const QString& dbName, QObject *parent = nullptr);
    ~DatabaseManager() override;

    bool open();
    void close();
    bool isOpen() const;

    QSqlQuery executeQuery(const QString& query);
    QSqlQuery executeQuery(const QString& query, const QVariantList& values);

    // Вспомогательные методы для более удобной работы
    QVariant getSingleValue(const QString& query);
    QVariant getSingleValue(const QString& query, const QVariantList& values);
    QList<QVariantList> getMultipleValues(const QString& query);
    QList<QVariantList> getMultipleValues(const QString& query, const QVariantList& values);
    QList<QString> getTravelGroups();
    QList<QVariantList> getUserRoutes(int userId);
    bool saveRoute(int userId, const QString& title, const QString& description, int groupId, const QList<QString>& points);
    bool deleteRoute(int userId, const QString& title);

private:
    QSqlDatabase db_;
    QString dbName_;

};
