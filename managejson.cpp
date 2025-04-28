#include "managejson.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonParseError>
#include <QDebug>

QJsonObject readJson(const QString &filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open file:" << file.errorString();
        return QJsonObject();  // fail safe
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);
    if (parseError.error != QJsonParseError::NoError) {
        qWarning() << "JSON parse error:" << parseError.errorString();
        return QJsonObject();  // fail safe
    }

    if (jsonDoc.isObject()) {
        return jsonDoc.object();
    }

    return QJsonObject(); // catch-all fallback
}

void writeJson(const QString &filePath, const QString &key, const QString &value)
{
    // Open the file for reading
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open file:" << file.errorString();
        return;
    }

    // Read all the data from the file
    QByteArray jsonData = file.readAll();
    file.close();

    // Parse the JSON data
    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        qWarning() << "Failed to parse JSON:" << parseError.errorString();
        return;
    }

    // Convert the document to an object
    QJsonObject jsonObj = jsonDoc.object();

    // Add or update the key-value pair
    jsonObj[key] = value;

    // Create a new JSON document with the updated object
    QJsonDocument updatedDoc(jsonObj);

    // Open the file for writing
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Failed to open file for writing:" << file.errorString();
        return;
    }

    // Write the updated JSON data to the file
    file.write(updatedDoc.toJson());
    file.close();

    qDebug() << "Updated JSON written to" << filePath;
}

