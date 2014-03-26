// icyconnection.h
//
// Abstract an ICY source connection.
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

#ifndef ICYCONNECTION_H
#define ICYCONNECTION_H

#include <stdint.h>

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtNetwork/QTcpSocket>

class IcyConnection : public QObject
{
  Q_OBJECT;
 public:
  enum ServerType {Shoutcast1Server=0,Shoutcast2Server=1,
		   Icecast1Server=2,Icecast2Server=3};
  IcyConnection(QObject *parent=0);
  ~IcyConnection();
  IcyConnection::ServerType serverType() const;
  void setServerType(IcyConnection::ServerType type);
  QString serverUsername() const;
  void setServerUsername(const QString &str);
  QString serverPassword() const;
  void setServerPassword(const QString &str);
  QString serverMountpoint() const;
  void setServerMountpoint(const QString &str);
  QString contentType() const;
  void setContentType(const QString &str);
  unsigned audioChannels() const;
  void setAudioChannels(unsigned chans);
  unsigned audioSamplerate() const;
  void setAudioSamplerate(unsigned rate);
  unsigned audioBitrate() const;
  void setAudioBitrate(unsigned rate);
  QString streamName() const;
  void setStreamName(const QString &str);
  QString streamDescription() const;
  void setStreamDescription(const QString &str);
  QString streamUrl() const;
  void setStreamUrl(const QString &str);
  QString streamGenre() const;
  void setStreamGenre(const QString &str);
  bool streamPublic() const;
  void setStreamPublic(bool state);
  void connectToServer(const QString &hostname,uint16_t port);
  int64_t writeData(const char *data,int64_t len);

 signals:
  void connected(int result,const QString &txt);
  void disconnected();
  void error(QAbstractSocket::SocketError err);

 private slots:
  void socketConnectedData();
  void socketDisconnectedData();
  void socketReadyReadData();
  void socketErrorData(QAbstractSocket::SocketError err);

 private:
  void ProcessHeaders(const QString &hdrs);
  void WriteHeader(const QString &str);
  IcyConnection::ServerType icy_server_type;
  QString icy_server_username;
  QString icy_server_password;
  QString icy_server_mountpoint;
  QString icy_content_type;
  unsigned icy_audio_channels;
  unsigned icy_audio_samplerate;
  unsigned icy_audio_bitrate;
  QString icy_stream_name;
  QString icy_stream_description;
  QString icy_stream_url;
  QString icy_stream_genre;
  bool icy_stream_public;
  QString icy_hostname;
  uint16_t icy_port;
  QTcpSocket *icy_socket;
  QString icy_recv_buffer;
};


#endif  // ICYCONNECTION_H
