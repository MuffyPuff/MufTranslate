#ifndef MUFTRANSLATE_H
#define MUFTRANSLATE_H

#include <QObject>
//#include <QJsonObject>
#include <QJsonArray>
#include <QDir>
#include <QWaitCondition>
#include <QMutex>
#include <QMutexLocker>

#include <QStandardPaths>

class MufTranslate : public QObject
{
	Q_OBJECT
public:
	explicit MufTranslate(const QString& lang, QObject* parent = 0);
	~MufTranslate();

	QString         operator()(const QString& code, const QString& lang = "");
	static bool     changeLanguage(const QString& lang);

private:
	static bool     loadLangFile(const QString& lang = "");

signals:

public slots:

private:
	static QString  _language;
	static QJsonArray _languageFile;

	static QMutex   _mutex;
	static QWaitCondition _condnewinfoavail;

	static bool     _hasnewinfo;
	static bool     _abort;
	static QString  languageDir;
};

#endif // MUFTRANSLATE_H
