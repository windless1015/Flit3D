//#include <OpenMesh/Core/Mesh/PolyMesh_ArrayKernelT.hh>
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>

#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <vector>
typedef OpenMesh::TriMesh_ArrayKernelT<> Triangle_mesh;



class Mesh
{
public:
    Mesh();
    ~Mesh();
public:
    void readMesh(std::string fileName);
    const GLfloat* constData();
    const size_t getCount() const { return m_verticesVector.size(); };
    size_t getMeshVertexCount();
private:
    Triangle_mesh m_mesh;
    std::vector<GLfloat> m_verticesVector;
};