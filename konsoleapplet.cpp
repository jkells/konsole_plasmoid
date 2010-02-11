/***************************************************************************
*   Copyright (C) 2009 - Jared Kells <jkells@gmail.com>                   *
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
***************************************************************************/

#include "konsoleapplet.h"
#include <QGraphicsProxyWidget>
#include <QGraphicsLinearLayout>
#include <kparts/part.h>
#include <kde_terminal_interface.h>

using namespace KParts;

KonsoleApplet::KonsoleApplet(QObject *parent, const QVariantList &args)
: Plasma::Applet(parent, args), m_konsolePart(0), m_partManager(0)
{ }

KonsoleApplet::~KonsoleApplet()
{ }

void KonsoleApplet::init()
{
	QGraphicsLinearLayout *layout = new QGraphicsLinearLayout();
	QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget(this);

	resize(600, 500);
	setAspectRatioMode(Plasma::IgnoreAspectRatio);	

	KService::Ptr service = KService::serviceByDesktopName("konsolepart");

	if( !service.isNull() )
	{
		KPluginFactory *factory = KPluginLoader(*service.data()).factory();
		if( factory )
		{
			if ( ( m_konsolePart = factory->create<KParts::ReadOnlyPart>( 0 ) ) )
			{
				proxy->setWidget( m_konsolePart->widget() );		
				
				//Start Terminal
				TerminalInterface* interface = qobject_cast<TerminalInterface*>(m_konsolePart);
				Q_ASSERT(interface);
				interface->showShellInDir( QString() );
			}
		}
	}

	layout->addItem( proxy );
	setLayout(layout);
}

#include "konsoleapplet.moc"






