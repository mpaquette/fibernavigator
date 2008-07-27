/*
 * DatasetHelper.h
 *
 *  Created on: 27.07.2008
 *      Author: ralph
 */
#ifndef DATASETHELPER_H_
#define DATASETHELPER_H_

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wx/textfile.h"
#include "wx/file.h"
#include "wx/image.h"
#include "wx/wfstream.h"
#include "wx/datstrm.h"
#include "wx/txtstrm.h"

#include <vector>
#include "ArcBall.h"

#include "datasetInfo.h"
#include "selectionBox.h"

#include "mainFrame.h"
#include "theScene.h"
#include "point.h"

#include "AnatomyHelper.h"

class MainFrame;
class DatasetInfo;
class TheScene;
class AnatomyHelper;
class Point;
class SelectionBox;

class DatasetHelper {
public:
	DatasetHelper(MainFrame*);
	virtual ~DatasetHelper();

	bool load(int index = 0, wxString filename = wxT(""));
	void finishLoading(DatasetInfo*);
	bool loadSettings(wxString);
	bool loadTextFile(wxString*, wxString);
	void save(wxString);

	std::vector<std::vector<SelectionBox*> > getSelectionBoxes();
	void updateAllSelectionBoxes();
	Vector3fT mapMouse2World(int, int);
	Vector3fT mapMouse2WorldBack(int, int);
	void updateTreeDims();
	void updateTreeDS(int);

	/*
	 * Called from MainFrame when a kdTree thread signals it's finished
	 */
	void treeFinished();

	/*
	 * Helper functions
	 */
	void printTime();
	void printwxT(wxString);
	/*
	 * Check for GL error
	 */
	bool GLError();
	void printGLError(wxString function = wxT(""));

	void updateView(float x, float y, float z) {
		xSlize = x;
		ySlize = y;
		zSlize = z;
	};

	int rows;
	int columns;
	int frames;
	bool useVBO;
	unsigned int countFibers;
	Matrix4fT m_transform;
	wxString lastError;
	GLenum lastGLError;
	bool anatomy_loaded;
	bool fibers_loaded;
	bool surface_loaded;
	bool surface_isDirty;
	wxString lastPath;
	int threadsActive;

	Point* lastSelectedPoint;
	MainFrame* mainFrame;
	TheScene* scene;
	AnatomyHelper* anatomyHelper;

	bool showSagittal;
	bool showCoronal;
	bool showAxial;
	float xSlize;
	float ySlize;
	float zSlize;
	int quadrant;


private:

};

#define ID_KDTREE_FINISHED	50

#endif /* DATASETHELPER_H_ */