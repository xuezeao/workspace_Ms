/****************************************************************************
**
** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "myinputpanel.h"

//! [0]

MyInputPanel::MyInputPanel()
    : QWidget(0, Qt::Tool | Qt::WindowStaysOnTopHint),
      lastFocusedWidget(0)
{
    form.setupUi(this);

    connect(qApp, SIGNAL(focusChanged(QWidget*,QWidget*)),
            this, SLOT(saveFocusWidget(QWidget*,QWidget*)));
    form.backspceButton->setProperty("buttonValue",QVariant(QChar(0x08)));

    signalMapper.setMapping(form.panelButton_1, form.panelButton_1);
    signalMapper.setMapping(form.panelButton_2, form.panelButton_2);
    signalMapper.setMapping(form.panelButton_3, form.panelButton_3);
    signalMapper.setMapping(form.panelButton_4, form.panelButton_4);
    signalMapper.setMapping(form.panelButton_5, form.panelButton_5);
    signalMapper.setMapping(form.panelButton_6, form.panelButton_6);
    signalMapper.setMapping(form.panelButton_7, form.panelButton_7);
    signalMapper.setMapping(form.panelButton_8, form.panelButton_8);
    signalMapper.setMapping(form.panelButton_9, form.panelButton_9);
    signalMapper.setMapping(form.panelButton_star, form.panelButton_star);
    signalMapper.setMapping(form.panelButton_0, form.panelButton_0);
    signalMapper.setMapping(form.panelButton_hash, form.panelButton_hash);
    signalMapper.setMapping(form.panelButton_a, form.panelButton_a);
    signalMapper.setMapping(form.panelButton_b, form.panelButton_b);
    signalMapper.setMapping(form.panelButton_c, form.panelButton_c);
    signalMapper.setMapping(form.panelButton_d, form.panelButton_d);
    signalMapper.setMapping(form.panelButton_e, form.panelButton_e);
    signalMapper.setMapping(form.panelButton_f, form.panelButton_f);
    signalMapper.setMapping(form.panelButton_g, form.panelButton_g);
    signalMapper.setMapping(form.panelButton_h, form.panelButton_h);
    signalMapper.setMapping(form.panelButton_i, form.panelButton_i);
    signalMapper.setMapping(form.panelButton_j, form.panelButton_j);
    signalMapper.setMapping(form.panelButton_k, form.panelButton_k);
    signalMapper.setMapping(form.panelButton_l, form.panelButton_l);
    signalMapper.setMapping(form.panelButton_m, form.panelButton_m);
    signalMapper.setMapping(form.panelButton_n, form.panelButton_n);
    signalMapper.setMapping(form.panelButton_o, form.panelButton_o);
    signalMapper.setMapping(form.panelButton_p, form.panelButton_p);
    signalMapper.setMapping(form.panelButton_q, form.panelButton_q);
    signalMapper.setMapping(form.panelButton_r, form.panelButton_r);
    signalMapper.setMapping(form.panelButton_s, form.panelButton_s);
    signalMapper.setMapping(form.panelButton_t, form.panelButton_t);
    signalMapper.setMapping(form.panelButton_u, form.panelButton_u);
    signalMapper.setMapping(form.panelButton_v, form.panelButton_v);
    signalMapper.setMapping(form.panelButton_w, form.panelButton_w);
    signalMapper.setMapping(form.panelButton_x, form.panelButton_x);
    signalMapper.setMapping(form.panelButton_y, form.panelButton_y);
    signalMapper.setMapping(form.panelButton_z, form.panelButton_z);
    signalMapper.setMapping(form.panelButton_comma, form.panelButton_comma);
    signalMapper.setMapping(form.panelButton_dot, form.panelButton_dot);
    signalMapper.setMapping(form.backspceButton, form.backspceButton);

    connect(form.panelButton_1, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_2, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_3, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_4, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_5, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_6, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_7, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_8, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_9, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_star, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_0, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_hash, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));

    connect(form.panelButton_a, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_b, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_c, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_d, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_e, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_f, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_g, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_h, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_i, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_j, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_k, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_l, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_m, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_n, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_o, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_p, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_q, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_r, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_s, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_t, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_u, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_v, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_w, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_x, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_y, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_z, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_comma, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_dot, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.backspceButton, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));

    connect(&signalMapper, SIGNAL(mapped(QWidget*)),
            this, SLOT(buttonClicked(QWidget*)));


}

//! [0]

bool MyInputPanel::event(QEvent *e)
{
    switch (e->type()) {
//! [1]
    case QEvent::WindowActivate:
        if (lastFocusedWidget)
            lastFocusedWidget->activateWindow();
        break;
//! [1]
    default:
        break;
    }

    return QWidget::event(e);
}

//! [2]

void MyInputPanel::saveFocusWidget(QWidget * /*oldFocus*/, QWidget *newFocus)
{
    if (newFocus != 0 && !this->isAncestorOf(newFocus)) {
        lastFocusedWidget = newFocus;
    }
}

//! [2]

//! [3]

void MyInputPanel::buttonClicked(QWidget *w)
{
    QChar chr = qvariant_cast<QChar>(w->property("buttonValue"));
  //  Qt::Key_Backspace;
    //qDebug() << chr;
    emit characterGenerated(chr);
}

//! [3]
