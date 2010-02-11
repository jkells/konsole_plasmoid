/***************************************************************************
 *   Copyright (C) 2009 - Jared Kells <jkells@gmail.com                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#ifndef KONSOLEAPPLET_H
#define KONSOLEAPPLET_H

#include <plasma/applet.h>

/* Forward Declarations */
namespace KParts
{
	class ReadOnlyPart;
	class PartManager;
}

class KonsoleApplet : public Plasma::Applet
{
    Q_OBJECT
    public:
        KonsoleApplet(QObject *parent, const QVariantList &args);
        ~KonsoleApplet();
	void init();

    private:
	KParts::ReadOnlyPart* m_konsolePart;
	KParts::PartManager* m_partManager;
};

K_EXPORT_PLASMA_APPLET(Konsole, KonsoleApplet)

#endif
