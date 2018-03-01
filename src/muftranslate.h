#ifndef MUFTRANSLATE_H
#define MUFTRANSLATE_H

#include <QObject>
//#include <QJsonObject>
#include <QWaitCondition>
#include <QMutex>
#include <QMutexLocker>

#include <QJsonArray>
#include <QDir>
#include <QStandardPaths>
#include <QMap>
#include <QString>

class MufTranslate : public QObject
{
	Q_OBJECT
public:
	explicit MufTranslate(const QString& lang, QObject* parent = 0);
	~MufTranslate();

	QString         operator()(const QString& code, const QString& lang = "");

private:
	static bool     loadLangFile(const QString& lang = "");
signals:
	void            languageChanged(QString);

public slots:
	bool     changeLanguage(const QString& lang);

private:
	static QString  _language;
	static QJsonArray _languageFile;

	static QMutex   _mutex;
	static QWaitCondition _condnewinfoavail;

	static bool     _hasnewinfo;
	static bool     _abort;
	static QString  languageDir;

public:
	static QMap<QString, QString> _languageList;
};

#endif // MUFTRANSLATE_H
