#ifndef DNAI_CORE_ENUMHANDLER_H
#define DNAI_CORE_ENUMHANDLER_H

#include <queue>

#include <QObject>

#include "entitymanager.h"

namespace dnai
{
    namespace gcore
    {
        class EnumHandler : public QObject
        {
            Q_OBJECT

        public:
            EnumHandler(EntityManager &manager);
            ~EnumHandler() = default;

        public:
            void setup();

        signals:
            void valueSet(dnai::models::Entity *enumeration, QString name, QString value);
            void valueRemoved(dnai::models::Entity *enumeration, QString name);

        public slots:
            void onEntityAdded(::core::EntityID id, models::Entity &entity);

        public:
            Q_INVOKABLE void renameValue(quint32 entity, QString name, QString newName, bool save = true);
            Q_INVOKABLE void setValue(quint32 entity, QString name, QString value, bool save = true);
            Q_INVOKABLE void removeValue(quint32 entity, QString const &name, bool save = true);

        private:
            void onValueSet(::core::EntityID enumeration, QString const &name, QString const &value);
            void onSetValueError(::core::EntityID enumeration, QString const &name, QString const &value, QString const &message);

            void onValueRemoved(::core::EntityID enumeration, QString const &name);
            void onRemoveValueError(::core::EntityID enumeration, QString const &name, QString const &message);

        private:
            EntityManager &manager;

        private:
            std::queue<QString> m_pendingRemove;
        };
    }
}

#endif // DNAI_CORE_ENUMHANDLER_H
