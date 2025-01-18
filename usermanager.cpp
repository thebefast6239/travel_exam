#include "usermanager.h"
#include <QCryptographicHash>
#include <QDebug>

UserManager::UserManager(DatabaseManager *dbManager, QObject *parent)
    : QObject(parent), dbManager_(dbManager)
{
}

UserManager::~UserManager()
{
}

bool UserManager::registerUser(const QString &username, const QString &password)
{
    if (isUsernameExists(username)) {
        qDebug() << "User with this username already exists.";
        return false; // User with this username already exists
    }

    QString passwordHash = hashPassword(password);
    QSqlQuery q = dbManager_->executeQuery("INSERT INTO users (username, password_hash) VALUES (?, ?);",
                                           {username, passwordHash});
    return q.numRowsAffected() > 0;
}

bool UserManager::authenticate(const QString &username, const QString &password)
{
    QString passwordHash = hashPassword(password);
    QSqlQuery q = dbManager_->executeQuery("SELECT COUNT(*) FROM users WHERE username = ? AND password_hash = ?;", {username, passwordHash});
    if(q.next()){
        return q.value(0).toInt() > 0;
    }
    return false;
}

int UserManager::getUserId(const QString &username)
{
    QVariant id = dbManager_->getSingleValue("SELECT id FROM users WHERE username = ?;", {username});
    if (id.isValid()){
        return id.toInt();
    }
    return -1; // Error: User not found
}

bool UserManager::isUsernameExists(const QString &username)
{
    QVariant count = dbManager_->getSingleValue("SELECT COUNT(*) FROM users WHERE username = ?;", {username});
    if(count.isValid()){
        return count.toInt() > 0;
    }
    return false; //Error: query failed.
}

QString UserManager::hashPassword(const QString &password)
{
    QByteArray passwordBytes = password.toUtf8();
    QByteArray hashBytes = QCryptographicHash::hash(passwordBytes, QCryptographicHash::Sha256);
    return hashBytes.toHex();
}
