#ifndef SURFACE_H_
#define SURFACE_H_

#include "DatasetInfo.h"

#include "../misc/Fantom/FBSplineSurface.h"
#include "../misc/Fantom/FTensor.h"
#include "../misc/IsoSurface/TriangleMesh.h"

#include <vector>

class KdTree;
class wxToggleButton;
class wxBitmapButton;

class Surface : public DatasetInfo
{
public:
    Surface();
    virtual ~Surface();

    void execute();

    bool load( wxString filename ) { return false; }
    void draw();

    void clean() {}
    void smooth();
    void flipAxis( AxisType axe ){}
    GLuint getCutTex() { return m_CutTex; }

    void movePoints();
    void flipNormals();
    virtual void createPropertiesSizer( PropertiesWindow *parent );
    virtual void updatePropertiesSizer();
    std::vector< std::vector< double > > getSplinePoints() { return m_splinePoints; }
    void setSetSampleRate( float r ) { m_sampleRateT = m_sampleRateU = r; execute(); }
    std::vector<Vector> getSurfaceVoxelPositions();

    bool save( wxString filename ) const;

private:
    void generateTexture() {}
    void generateGeometry();
    void generateLICGeometry();
    void initializeBuffer() {}
    void createCutTexture();
    GLuint getGLuint() { return 0; }

    FTensor getCovarianceMatrix(std::vector< std::vector< double > > points);
    void getSplineSurfaceDeBoorPoints(  std::vector< std::vector< double > > &givenPoints,
                                            std::vector< std::vector< double > > &deBoorPoints,
                                            int numRows, int numCols);

    float getXValue(int y , int z, int numPoints);
    void boxTest(int left, int right, int axis);

private:
    wxToggleButton *m_ptoggleDrawPoints;
    wxBitmapButton *m_pbtnMoveBoundaryLeft;
    wxBitmapButton *m_pbtnMoveBoundaryRight;

    double m_radius;
    double m_my;
    int m_numDeBoorRows;
    int m_numDeBoorCols;
    int m_order;
    double m_sampleRateU;
    double m_sampleRateT;
    double m_xAverage;
    double m_yAverage;
    double m_zAverage;

    std::vector< std::vector< double > > m_splinePoints;

    int m_renderpointsPerCol;
    int m_renderpointsPerRow;
    int m_numPoints;
    float *m_boxMin;
    float *m_boxMax;
    float* m_pointArray;
    float m_xValue;
    int m_count;
    int subDCount;
    float m_normalDirection;

    GLuint m_CutTex;
    KdTree *m_kdTree;

    std::vector< std::vector<float> >m_testLines;
    bool m_positionsCalculated;
    std::vector<Vector>m_svPositions;
};


#endif /*SURFACE_H_*/
