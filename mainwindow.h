/**********************************************************************
 *  mainwindow.h
 **********************************************************************
 * Copyright (C) 2021 MX Authors
 *
 * Authors: Adrian <adrian@mxlinux.org>
 *          Dolphin_Oracle
 *          MX Linux <http://mxlinux.org>
 *
 * This is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this package. If not, see <http://www.gnu.org/licenses/>.
 **********************************************************************/


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMessageBox>
#include <QProcess>
#include <QSettings>

#include "cmd.h"
#include "editshare.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void centerWindow();

public slots:

private slots:
    void cmdDone();
    void cmdStart();
    void on_buttonAbout_clicked();
    void on_buttonHelp_clicked();
    void on_pushAddShare_clicked();
    void on_pushButtonAddUser_clicked();
    void on_pushButtonRemoveShare_clicked();
    void on_pushButtonRemoveUser_clicked();
    void on_pushButtonRestartSamba_clicked();
    void on_pushEditShare_clicked();
    void on_pushButtonUserPassword_clicked();
    void progress(int elapsed, int duration); // updates progressBar when tick signal is emited
    void setConnections();
    void updateOutput();

private:
    Ui::MainWindow *ui;
    Cmd cmd;
    EditShare *editshare;
    QProcess proc;
    QSettings settings;
    QStringList listUsers();
    void refreshShareList();
    void refreshUserList();
};


#endif

