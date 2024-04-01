#include "Mesh.h"

#include <OpenMesh/Core/IO/MeshIO.hh>
Mesh::Mesh()
{

}


Mesh::~Mesh()
{

}

void Mesh::readMesh(std::string fileName)
{
	OpenMesh::IO::read_mesh(m_mesh, fileName);

    std::vector<GLfloat>().swap(m_verticesVector);
    m_verticesVector.reserve(m_mesh.n_vertices() * 3); // Reserve space for x, y, z for each vertex

    for (Triangle_mesh::VertexIter v_it = m_mesh.vertices_begin(); v_it != m_mesh.vertices_end(); ++v_it) {
        // Get the point associated with the vertex
        Triangle_mesh::Point p = m_mesh.point(*v_it);

        // Add the coordinates to the vector
        m_verticesVector.push_back(p[0]); // x-coordinate
        m_verticesVector.push_back(p[1]); // y-coordinate
        m_verticesVector.push_back(p[2]); // z-coordinate
    }
    int a = m_mesh.n_vertices();
    //std::cout << "Loaded " << vertices.size() / 3 << " vertices." << std::endl;
}

const GLfloat* Mesh::constData()
{
    return m_verticesVector.data();
}

size_t Mesh::getMeshVertexCount()
{
    size_t vertexCount = m_mesh.n_vertices();
    return vertexCount;
}