#ifndef DNAI_MODELS_CONTEXT_MENU_MODEL_H
#define DNAI_MODELS_CONTEXT_MENU_MODEL_H
#include <QAbstractItemModel>
#include <QHash>
#include "generictreeitem.h"

namespace dnai
{
	namespace models
	{
		class ContextMenuItem : public GenericTreeItem<ContextMenuItem>
		{
			Q_OBJECT
			Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
			Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
			Q_PROPERTY(int inputs READ inputs WRITE setInputs NOTIFY inputsChanged)
			Q_PROPERTY(int outputs READ outputs WRITE setOutputs NOTIFY outputsChanged)
			Q_PROPERTY(int instructionId READ instructionId WRITE setInstructionId NOTIFY instructionIdChanged)
			Q_PROPERTY(QString nodeName READ nodeName WRITE setNodeName NOTIFY nodeNameChanged)
            Q_PROPERTY(int type READ type WRITE setType NOTIFY typeChanged)
            Q_PROPERTY(QList<qint32> construction READ construction WRITE setConstruction NOTIFY constructionChanged)

		public:
			const QString &name() const;
			const QString &description() const;
			int inputs() const;
			int outputs() const;
			int instructionId() const;
			const QString &nodeName() const;
			int columnCount() const override;
            int type() const;
            QList<qint32> const &construction() const;

		public:
			void setName(const QString &);
			void setDescription(const QString &);
			void setInputs(int);
			void setOutputs(int);
			void setInstructionId(int);
			void setNodeName(const QString &name);
            void setType(int t);
            void setConstruction(QList<qint32> const &value);

		signals:
			void nameChanged(const QString &);
			void descriptionChanged(const QString &);
			void inputsChanged(int);
			void outputsChanged(int);
			void instructionIdChanged(int);
			void nodeNameChanged(const QString &name);
            void typeChanged(int t);
            void constructionChanged(QList<qint32> const &value);

		private:
			QString m_name;
			QString m_descrition;
			int m_inputs;
			int m_outputs;
			int m_instructionId;
			QString m_nodeName;
            int m_type = -1;
            QList<qint32> m_construction;
		};
		class ContextMenuModel : public QAbstractItemModel
		{
			Q_OBJECT
		public:
			enum ROLES
			{
				NAME = Qt::UserRole + 1,
				ITEM,
				DESCRIPTION,
				INPUTS,
                OUTPUTS,
                CONSTRUCTION,
                INSTRUCTION_ID
			};

		public:
			explicit ContextMenuModel(QObject *parent = nullptr);
			explicit ContextMenuModel(const QJsonObject &doc, QObject *parent = nullptr);

			QModelIndex index(int row, int column, const QModelIndex& parent) const override;
			QModelIndex parent(const QModelIndex& child) const override;
			ContextMenuItem* getItem(const QModelIndex& index) const;
			int rowCount(const QModelIndex& parent) const override;
			int columnCount(const QModelIndex& parent) const override;
			QVariant data(const QModelIndex& index, int role) const override;
            QHash<int, QByteArray> roleNames() const override;

            const QHash<int, ContextMenuItem*> &instructions() const;

		private:
			void parseJsonDocument(const QJsonObject &json);
			void parseJsonObj(ContextMenuItem* parent, const QJsonObject& js);
			ContextMenuItem *m_root;
            QHash<int, ContextMenuItem*> m_hash;
		};
	}
}

#endif //DNAI_MODELS_CONTEXT_MENU_MODEL_H
