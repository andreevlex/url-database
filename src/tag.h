#ifndef TAG_H
#define TAG_H

#include <QString>
#include "dataobject.h"
#include "compositepattern.h"

class Tag : public DataObject, public AbstractComponent
{
public:
    explicit Tag(const QString &name = QString());
    Tag(const Tag &other);
    ~Tag();

    void setID(const long long id);
    long long getID() const;

    void setName(const QString& name);
    QString getName(void) const;
    bool isValid() const;
    Tag& operator=(const Tag &other);
private:
    long long  id_m{0};
    QString    name_m;
    bool       modified_m{false};

    bool saveData(QSqlQuery &query);
    bool checkIsNew() const;
    bool getModified() const;
};

bool operator ==(const Tag& loper, const Tag& roper);

#endif // TAG_H
