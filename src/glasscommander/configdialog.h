// configdialog.h
//
// Show configration buttons for GlassCommander
//
//   (C) Copyright 2016 Fred Gleason <fredg@paravelsystems.com>
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

#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QPushButton>
#include <QDialog>

#include "codecdialog.h"
#include "serverdialog.h"
#include "sourcedialog.h"
#include "streamdialog.h"

class ConfigDialog : public QDialog
{
 Q_OBJECT;
 public:
  ConfigDialog(const QString &instance_name,ServerDialog *server_dialog,
	       CodecDialog *codec_dialog,StreamDialog *stream_dialog,
	       SourceDialog *source_dialog,QWidget *parent=0);
  QSize sizeHint() const;

 protected:
  void closeEvent(QCloseEvent *e);
  void resizeEvent(QResizeEvent *e);

 private:
  ServerDialog *conf_server_dialog;
  QPushButton *conf_server_button;
  CodecDialog *conf_codec_dialog;
  QPushButton *conf_codec_button;
  StreamDialog *conf_stream_dialog;
  QPushButton *conf_stream_button;
  SourceDialog *conf_source_dialog;
  QPushButton *conf_source_button;
};


#endif  // CONFIGDIALOG_H
