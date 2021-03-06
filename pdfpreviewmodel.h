/*
 *
 *  ShowMee - Presentation software with touch interface
 *
 *  Copyright (C) 2011   Warp Networks, S.L. All rights reserved.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */


#ifndef PDFPREVIEWMODEL_H
#define PDFPREVIEWMODEL_H

#include <QAbstractListModel>
#include <QVector>

class PdfPreviewModel : public QAbstractListModel
{
Q_OBJECT
public:
    explicit PdfPreviewModel(QObject *parent = 0);
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent) const;
    void addDirToSearch(QString& dir);
    void removeDirToSearch(QString& dir);
    void searchPdfFiles();

signals:

public slots:
    void changeCurrentDir(int index);

private:
    Q_DISABLE_COPY(PdfPreviewModel);
    enum PdfPreviewRoles { TITLE, PAGES, IMAGE, IS_FILE, PATH };
    QString _currentDir;
    QVector<QString> _pdfFiles;
    QVector<QString> _dirs;

};

#endif // PDFPREVIEWMODEL_H
