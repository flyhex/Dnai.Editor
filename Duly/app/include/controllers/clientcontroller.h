#ifndef CLIENTCONTROLLER_H_
# define CLIENTCONTROLLER_H_

#include <QHostAddress>
#include <QString>

class ClientCommunication;
class DataComEventFactory;

#include "core.pb.h"

#define CLIENT_NAME "DULY_GUI"

class ClientController {
private:
    ClientController();

public:
    static ClientController &shared();

public:
#define DECLARE_EVENT_NAME "DECLARE"
    void sendDeclareEvent(ENTITY entity_type,
                          uint32_t containerID,
                          QString const &name,
                          VISIBILITY visibility);

private:
    ClientCommunication *m_clientCom;
    DataComEventFactory *m_dataComFactory;
    QString             m_name;
    quint16             m_port;
    QHostAddress        m_addr;
};

#endif
