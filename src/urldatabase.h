#ifndef URLDATABASE_H
#define URLDATABASE_H

#include "refrecord.h"
#include "config.h"
#include "tag.h"
#include <QString>
#include <QtSql/QtSql>
#include <vector>

class QTableView;
class QSqlTableModel;
class QSqlQueryModel;

class UrlDatabase: public QObject
{
    Q_OBJECT
public:

    UrlDatabase(QTableView * refRecords, QTableView * tags, QObject *parent = 0);
    virtual ~UrlDatabase();

    void update();
    void showRefs();
    void showTags();
    void showFavoriteRefs();

protected:

    QSqlTableModel *RefRecordsModel_m;
    QSqlTableModel *TagsModel_m;
    QSqlQueryModel *QueryModel_m;
private:
    QTableView * refRecords_m{nullptr};
    QTableView * tags_m{nullptr};
};

#endif // URLDATABASE_H
