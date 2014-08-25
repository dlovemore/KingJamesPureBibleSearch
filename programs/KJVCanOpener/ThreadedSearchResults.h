/****************************************************************************
**
** Copyright (C) 2014 Donna Whisnant, a.k.a. Dewtronics.
** Contact: http://www.dewtronics.com/
**
** This file is part of the KJVCanOpener Application as originally written
** and developed for Bethel Church, Festus, MO.
**
** GNU General Public License Usage
** This file may be used under the terms of the GNU General Public License
** version 3.0 as published by the Free Software Foundation and appearing
** in the file gpl-3.0.txt included in the packaging of this file. Please
** review the following information to ensure the GNU General Public License
** version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and
** Dewtronics.
**
****************************************************************************/

#ifndef THREADED_SEARCH_RESULTS_H
#define THREADED_SEARCH_RESULTS_H

#include "dbstruct.h"
#include "VerseListModel.h"

#include <QThread>
#include <QObject>
#include <QList>

// ============================================================================


class CThreadedSearchResultWorker : public QObject
{
	Q_OBJECT
	QThread workerThreadedSearchResult;

public slots:

};

class CThreadedSearchResultCtrl : public QObject
{
	Q_OBJECT
	QThread workerThreadedSearchResult;

public:
	CThreadedSearchResultCtrl(CVerseListModel &vlm, const CSearchResultsData &theData)
		:	QObject(&vlm),
			m_searchResultsdata(theData),
			m_vlm(vlm)
	{

	}

	void deactivate();


private:
	bool m_bActive;								// Set to True if the results of this thread is to be used to drive results.  Set to False if this result has been superceded by later results and we need to ignore this
	CSearchResultsData m_searchResultsdata;		// Current search results data being operated on
	TSharedParsedPhrasesList m_lstPhrases;		// Copy of phrases to work on
	CVerseListModel &m_vlm;
};

// ============================================================================

#endif	// THREADED_SEARCH_RESULTS_H

