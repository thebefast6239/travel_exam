#pragma once
#include <QObject>
#include <QString>
#include <QSqlQuery>
#include "databasemanager.h"

class UserManager : public QObject
{
    Q_OBJECT

public:
    explicit UserManager(DatabaseManager* dbManager, QObject *parent = nullptr);
    ~UserManager() override;

    bool registerUser(const QString& username, const QString& password);
    bool authenticate(const QString& username, const QString& password);
    int getUserId(const QString& username);
    bool isUsernameExists(const QString& username);
private:
    DatabaseManager* dbManager_;

    QString hashPassword(const QString& password);
};
