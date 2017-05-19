# База данных ссылок на ресурсы интернет.

База данных для хранения ссылок на различный контент из сети интернет.
Для хранения данных используется база на основе sqllite3. Для начала работы
не нужно настраивать сервер баз данных.

## Возможности

Хранит ссылки и тэги. Ссылки могут иметь более одного тэга.
Список избранных ссылок.
База имеет возможность проверить ссылки на наличие в запрещенном 
реестре сайтов на территории России. Ресурс [antizapret.info](https://antizapret.info)

## Настройка

Для сборки необходимо установить пакет
команда:
`sudo apt-get install libgl1-mesa-dev`


## Примененные шаблоны проектирования

Была выбрана концепция
Редактирование через объекты, просмотр через табличные представления

Для решения поставленных целей были выбраны следующие шаблоны:
1. класс DataObject - Паттерн Template Method (шаблонный метод)
    Был выбран потому, что объекты базы данных имеют одинаковый интерфейс,
    но каждая таблица имеет различную структуру хранения
    Реализованы подклассы:
    - Tag
    - RefRecord
2. класс TagsList -  Паттерн Composite (компоновщик)
    Необходим для управления коллекцией тэгов.
    Одна ссылка может содержать много тэгов.
3. класс DataObjectFactory - Паттерн Фабричный метод (Factory Method)
    Для реализации концепции "редактирование через объекты" был
    реализован данный шаблон, потомки которого позволяют создавать тэги и ссылки.
    Реализованы:
    - RefRecords
    - Tags
4. класс UrlDatabase - Паттерн Facade (фасад)
    Для упращения интерфейса был реализован данный шаблон, который
    позволяет предоставить универсальный интерейс для визуализации данных из базы
    Реализованы методы:
    - update - обновление интерфейса пользователя по требованию
    - showRefs - отображает общий список ссылок
    - showTags - отображает общий список тэгов
    - showFavoriteRefs - отображает список избранных ссылок
