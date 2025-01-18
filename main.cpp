#include <QApplication>
#include "databasemanager.h"
#include "loginwindow.h"
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString dbPath = QDir::currentPath() + "/travel_service.db";
    DatabaseManager dbManager(dbPath);

    if (dbManager.open()) {
        qDebug() << "Database connected successfully!";
        // Создание таблиц (если они еще не созданы)
        dbManager.executeQuery("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY AUTOINCREMENT, username TEXT UNIQUE NOT NULL, password_hash TEXT NOT NULL);");
        dbManager.executeQuery("CREATE TABLE IF NOT EXISTS travel_groups (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT UNIQUE NOT NULL);");
        dbManager.executeQuery("CREATE TABLE IF NOT EXISTS routes (id INTEGER PRIMARY KEY AUTOINCREMENT, user_id INTEGER NOT NULL, group_id INTEGER NOT NULL, title TEXT NOT NULL, description TEXT, FOREIGN KEY (user_id) REFERENCES users(id), FOREIGN KEY (group_id) REFERENCES travel_groups(id));");
        dbManager.executeQuery("CREATE TABLE IF NOT EXISTS route_points (id INTEGER PRIMARY KEY AUTOINCREMENT, route_id INTEGER NOT NULL, latitude REAL NOT NULL, longitude REAL NOT NULL, description TEXT, FOREIGN KEY (route_id) REFERENCES routes(id));");
        dbManager.executeQuery("CREATE TABLE IF NOT EXISTS ratings (id INTEGER PRIMARY KEY AUTOINCREMENT, user_id INTEGER NOT NULL, route_id INTEGER NOT NULL, rating INTEGER NOT NULL, FOREIGN KEY (user_id) REFERENCES users(id), FOREIGN KEY (route_id) REFERENCES routes(id));");

        LoginWindow *loginWindow = new LoginWindow(&dbManager);
        loginWindow->show();
    } else {
        qDebug() << "Failed to connect to the database.";
    }

    return a.exec();
}
