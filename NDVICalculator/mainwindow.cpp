/*
                  GNU LESSER GENERAL PUBLIC LICENSE
                       Version 3, 29 June 2007
 Copyright (C) 2007 Free Software Foundation, Inc. <http://fsf.org/>
 Everyone is permitted to copy and distribute verbatim copies
 of this license document, but changing it is not allowed.
  This version of the GNU Lesser General Public License incorporates
the terms and conditions of version 3 of the GNU General Public
License, supplemented by the additional permissions listed below.
  0. Additional Definitions.
  As used herein, "this License" refers to version 3 of the GNU Lesser
General Public License, and the "GNU GPL" refers to version 3 of the GNU
General Public License.
  "The Library" refers to a covered work governed by this License,
other than an Application or a Combined Work as defined below.
  An "Application" is any work that makes use of an interface provided
by the Library, but which is not otherwise based on the Library.
Defining a subclass of a class defined by the Library is deemed a mode
of using an interface provided by the Library.
  A "Combined Work" is a work produced by combining or linking an
Application with the Library.  The particular version of the Library
with which the Combined Work was made is also called the "Linked
Version".
  The "Minimal Corresponding Source" for a Combined Work means the
Corresponding Source for the Combined Work, excluding any source code
for portions of the Combined Work that, considered in isolation, are
based on the Application, and not on the Linked Version.
  The "Corresponding Application Code" for a Combined Work means the
object code and/or source code for the Application, including any data
and utility programs needed for reproducing the Combined Work from the
Application, but excluding the System Libraries of the Combined Work.
  1. Exception to Section 3 of the GNU GPL.
  You may convey a covered work under sections 3 and 4 of this License
without being bound by section 3 of the GNU GPL.
  2. Conveying Modified Versions.
  If you modify a copy of the Library, and, in your modifications, a
facility refers to a function or data to be supplied by an Application
that uses the facility (other than as an argument passed when the
facility is invoked), then you may convey a copy of the modified
version:
   a) under this License, provided that you make a good faith effort to
   ensure that, in the event an Application does not supply the
   function or data, the facility still operates, and performs
   whatever part of its purpose remains meaningful, or
   b) under the GNU GPL, with none of the additional permissions of
   this License applicable to that copy.
  3. Object Code Incorporating Material from Library Header Files.
  The object code form of an Application may incorporate material from
a header file that is part of the Library.  You may convey such object
code under terms of your choice, provided that, if the incorporated
material is not limited to numerical parameters, data structure
layouts and accessors, or small macros, inline functions and templates
(ten or fewer lines in length), you do both of the following:
   a) Give prominent notice with each copy of the object code that the
   Library is used in it and that the Library and its use are
   covered by this License.
   b) Accompany the object code with a copy of the GNU GPL and this license
   document.
  4. Combined Works.
  You may convey a Combined Work under terms of your choice that,
taken together, effectively do not restrict modification of the
portions of the Library contained in the Combined Work and reverse
engineering for debugging such modifications, if you also do each of
the following:
   a) Give prominent notice with each copy of the Combined Work that
   the Library is used in it and that the Library and its use are
   covered by this License.
   b) Accompany the Combined Work with a copy of the GNU GPL and this license
   document.
   c) For a Combined Work that displays copyright notices during
   execution, include the copyright notice for the Library among
   these notices, as well as a reference directing the user to the
   copies of the GNU GPL and this license document.
   d) Do one of the following:
       0) Convey the Minimal Corresponding Source under the terms of this
       License, and the Corresponding Application Code in a form
       suitable for, and under terms that permit, the user to
       recombine or relink the Application with a modified version of
       the Linked Version to produce a modified Combined Work, in the
       manner specified by section 6 of the GNU GPL for conveying
       Corresponding Source.
       1) Use a suitable shared library mechanism for linking with the
       Library.  A suitable mechanism is one that (a) uses at run time
       a copy of the Library already present on the user's computer
       system, and (b) will operate properly with a modified version
       of the Library that is interface-compatible with the Linked
       Version.
   e) Provide Installation Information, but only if you would otherwise
   be required to provide such information under section 6 of the
   GNU GPL, and only to the extent that such information is
   necessary to install and execute a modified version of the
   Combined Work produced by recombining or relinking the
   Application with a modified version of the Linked Version. (If
   you use option 4d0, the Installation Information must accompany
   the Minimal Corresponding Source and Corresponding Application
   Code. If you use option 4d1, you must provide the Installation
   Information in the manner specified by section 6 of the GNU GPL
   for conveying Corresponding Source.)
  5. Combined Libraries.
  You may place library facilities that are a work based on the
Library side by side in a single library together with other library
facilities that are not Applications and are not covered by this
License, and convey such a combined library under terms of your
choice, if you do both of the following:
   a) Accompany the combined library with a copy of the same work based
   on the Library, uncombined with any other library facilities,
   conveyed under the terms of this License.
   b) Give prominent notice with the combined library that part of it
   is a work based on the Library, and explaining where to find the
   accompanying uncombined form of the same work.
  6. Revised Versions of the GNU Lesser General Public License.
  The Free Software Foundation may publish revised and/or new versions
of the GNU Lesser General Public License from time to time. Such new
versions will be similar in spirit to the present version, but may
differ in detail to address new problems or concerns.
  Each version is given a distinguishing version number. If the
Library as you received it specifies that a certain numbered version
of the GNU Lesser General Public License "or any later version"
applies to it, you have the option of following the terms and
conditions either of that published version or of any later version
published by the Free Software Foundation. If the Library as you
received it does not specify a version number of the GNU Lesser
General Public License, you may choose any version of the GNU Lesser
General Public License ever published by the Free Software Foundation.
  If the Library as you received it specifies that a proxy can decide
whether future versions of the GNU Lesser General Public License shall
apply, that proxy's public statement of acceptance of any version is
permanent authorization for you to choose that version for the
Library.
*/

/*
 * Application Name: NDVICalculator
 * Author: Tairan Liu
 * Copyright 2018, Tairan Liu
 * Version: 0.1-dev
 * Email: liutairan2012@gmail.com
 * Status: Under development
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    removeToolBar(ui->mainToolBar);
    srcPath = "";
    destPath = "";
    _status = false;

    //QImage tempImage("/Users/liutairan/Desktop/TestBigImage/NIR.JPG");
    //qDebug() << tempImage.size();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_srcPushButton_clicked()
{
    srcPath = QFileDialog::getExistingDirectory(this, "Choose source directory", "", QFileDialog::ShowDirsOnly);
    if (srcPath.length() > 0)
    {
        ui->srcLineEdit->setText(srcPath);
        qDebug() << srcPath;

        QStringList filters;
        filters << "*.jpg";
        QFileInfoList fileInfoList = QDir(srcPath).entryInfoList(filters, QDir::Files|QDir::NoDotAndDotDot);
        inputFileNumber = fileInfoList.length();

        srcFileModel = new QFileSystemModel(this);
        //srcFileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
        srcFileModel->setRootPath(srcPath);
        ui->srcListView->setModel(srcFileModel);
        ui->srcListView->setRootIndex(srcFileModel->setRootPath(srcPath));
    }
}

void MainWindow::on_destPushButton_clicked()
{
    destPath = QFileDialog::getExistingDirectory(this, "Choose destination directory", "", QFileDialog::ShowDirsOnly);
    if (destPath.length() > 0)
    {
        ui->destLineEdit->setText(destPath);
        qDebug() << destPath;

        destFileModel = new QFileSystemModel(this);
        destFileModel->setRootPath(destPath);
        ui->destListView->setModel(destFileModel);
        ui->destListView->setRootIndex(destFileModel->setRootPath(destPath));
    }
}

void MainWindow::on_startPushButton_clicked()
{
    set_status(true);
}

void MainWindow::on_stopPushButton_clicked()
{
    set_status(false);
}

bool MainWindow::get_status()
{
    return _status;
}

void MainWindow::set_status(bool value)
{
    if (value != _status)
    {
        _status = value;
        if (_status == true)
        {
            thread = new QThread();
            worker = new SerialWorker (srcPath, destPath);

            worker->moveToThread(thread);
            connect(worker, SIGNAL(workRequested()), thread, SLOT(start()));
            connect(thread, SIGNAL(started()), worker, SLOT(doWork()));
            connect(worker, SIGNAL(finished()), thread, SLOT(quit()), Qt::DirectConnection);
            connect(worker, SIGNAL(progressChanged(int)), this, SLOT(updateProgress(int)));
            worker->requestWork();
        }
        else if (_status == false)
        {
            worker->abort();
            thread->wait();
        }
        emit statusChanged(_status);
    }
}

void MainWindow::updateProgress(int value)
{
    ui->progressBar->setValue(int(100.0*(inputFileNumber-value)/inputFileNumber));
}

SerialWorker::SerialWorker(QString source, QString destination, QObject *parent) :
    QObject(parent)
{
    _working =false;
    _abort = false;
    srcPath = source;
    destPath = destination;
    QStringList filters;
    filters << "*.jpg";
    srcFileInfoList = QDir(srcPath).entryInfoList(filters, QDir::Files|QDir::NoDotAndDotDot);
    colorband = new QImage("/Users/liutairan/Documents/QT/NDVICalculator/newcolorbar.png");
    colorStepNumber = colorband->width();
    colorStep = 2.0/colorStepNumber;
}

void SerialWorker::requestWork()
{
    mutex.lock();
    _working = true;
    _abort = false;
    qDebug()<<"Request worker start in Thread "<<thread()->currentThreadId();
    mutex.unlock();

    emit workRequested();
}

void SerialWorker::abort()
{
    mutex.lock();
    if (_working) {
        _abort = true;
        qDebug()<<"Request worker aborting in Thread "<<thread()->currentThreadId();
    }
    mutex.unlock();
}

void SerialWorker::doWork()
{
    qDebug()<<"Starting worker process in Thread "<<thread()->currentThreadId();

    mutex.lock();
    bool abort = _abort;
    mutex.unlock();

    while ((!abort) && (srcFileInfoList.length() > 0))
    {
        realWorker(srcFileInfoList.at(0));

        mutex.lock();
        bool abort = _abort;
        mutex.unlock();
        if (abort) {
            qDebug()<<"Aborting worker process in Thread "<<thread()->currentThreadId();
            break;
        }
    }

    if ((abort == false) && (srcFileInfoList.length() == 0))
    {
        qDebug() << "Job finished";
    }
    // Set _working to false, meaning the process can't be aborted anymore.
    mutex.lock();
    _working = false;
    mutex.unlock();

    qDebug()<<"Worker process finished in Thread "<<thread()->currentThreadId();

    emit finished();
}

void SerialWorker::realWorker(QFileInfo fileInfo)
{
    qDebug() << "Start time" << QDateTime::currentDateTime().toString("yyyy_MM_dd_hh_mm_ss_zzz");
    qDebug() << fileInfo.absoluteFilePath();
    QImage tempImage(fileInfo.absoluteFilePath());

    QImage newGImage(tempImage.size(), QImage::Format_RGB32);
    QImage newBImage(tempImage.size(), QImage::Format_RGB32);

    for (int i=0; i< tempImage.width(); i++)
    {
        for (int j=0; j< tempImage.height(); j++)
        {
            QRgb tempRgb = tempImage.pixel(i,j);
            double tempNDVI_G = -1.0;
            if ((qRed(tempRgb) + qGreen(tempRgb) + 1) < 1e-7)
            {
                tempNDVI_G = -1.0;
            }
            else
            {
                tempNDVI_G = (double(qRed(tempRgb) - qGreen(tempRgb)))/(double(qRed(tempRgb) + qGreen(tempRgb)));
            }

            int colorIndex_G = int((tempNDVI_G + 1.0)/colorStep);

            if (colorIndex_G < colorStepNumber)
            {
                newGImage.setPixel(i,j, colorband->pixel(colorIndex_G, 0));
            }
            else if (colorIndex_G >= colorStepNumber)
            {
                newGImage.setPixel(i,j, colorband->pixel(colorStepNumber-1, 0));
            }

            //
            double tempNDVI_B = -1.0;
            if ((qRed(tempRgb) + qBlue(tempRgb) + 1) < 1e-7)
            {
                tempNDVI_B = -1.0;
            }
            else
            {
                tempNDVI_B = (double(qRed(tempRgb) - qBlue(tempRgb)))/(double(qRed(tempRgb) + qBlue(tempRgb)));
            }

            int colorIndex_B = int((tempNDVI_B + 1.0)/colorStep);

            if (colorIndex_B < colorStepNumber)
            {
                newBImage.setPixel(i,j, colorband->pixel(colorIndex_B, 0));
            }
            else if (colorIndex_B >= colorStepNumber)
            {
                newBImage.setPixel(i,j, colorband->pixel(colorStepNumber-1, 0));
            }
        }
    }
    QString newPath_G = destPath + "/" + fileInfo.baseName() + "_G.jpg";
    QString newPath_B = destPath + "/" + fileInfo.baseName() + "_B.jpg";
    newGImage.save(newPath_G);
    newBImage.save(newPath_B);
    try
    {
        addExif(fileInfo, newPath_G);
        addExif(fileInfo, newPath_B);
    }
    catch (...)
    {}

    qDebug() << "End time" << QDateTime::currentDateTime().toString("yyyy_MM_dd_hh_mm_ss_zzz");
    srcFileInfoList.pop_front();
    emit progressChanged(srcFileInfoList.length());
}

void SerialWorker::addExif(QFileInfo fileInfo, QString newFilePath)
{
    QString srcFilePath = fileInfo.absoluteFilePath();
    QString destFilePath = newFilePath;

    QProcess *process = new QProcess(this);
    process->setProcessChannelMode(QProcess::MergedChannels);
    QString cmd = "python editexif.py " + srcFilePath + " " + destFilePath;
    process->start(cmd, QIODevice::ReadWrite);
    // Wait for it to start
    if(!process->waitForStarted())
        ;

    // Continue reading the data until EOF reached
    QByteArray data;

    while(process->waitForReadyRead())
        data.append(process->readAll());

    // Output the data
    qDebug() << data.data();
}
