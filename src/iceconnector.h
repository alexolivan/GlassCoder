// iceconnector.h
//
// Source connector class for IceCast2 servers.
//
//   (C) Copyright 2014 Fred Gleason <fredg@paravelsystems.com>
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License version 2 as
//   published by the Free Software Foundation.
//
//   This program is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public
//   License along with this program; if not, write to the Free Software
//   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//

#ifndef ICECONNECTOR_H
#define ICECONNECTOR_H

#include "connector.h"

class IceConnector : public Connector
{
  Q_OBJECT;
 public:
  IceConnector(QObject *parent=0);
  ~IceConnector();
  IceConnector::ServerType serverType() const;

 protected:
  void connectToHostConnector(const QString &hostname,uint16_t port);
  void disconnectFromHostConnector();
  int64_t writeDataConnector(const char *data,int64_t len);

 private slots:
  void socketConnectedData();
  void socketDisconnectedData();
  void socketReadyReadData();
  void socketErrorData(QAbstractSocket::SocketError err);

 private:
  void ProcessHeaders(const QString &hdrs);
  void WriteHeader(const QString &str);
  QTcpSocket *ice_socket;
  QString ice_recv_buffer;
};


#endif  // ICECONNECTOR_H