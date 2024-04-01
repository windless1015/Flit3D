#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QMatrix4x4>
#include "Mesh.h"

QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)

class TrackballWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    TrackballWidget(QWidget *parent = nullptr);
    ~TrackballWidget();

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;
    void loadMesh(const std::string& filePath);
public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);
    void cleanup();

signals:
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

private:
    void setupVertexAttribs();

    bool m_core;
    int m_xRot = 0;
    int m_yRot = 0;
    int m_zRot = 0;
    QPoint m_lastPos;
    QOpenGLVertexArrayObject m_vao;
    QOpenGLBuffer m_vbo;
    QOpenGLShaderProgram* m_program = nullptr;
    int m_projMatrixLoc = 0;
    int m_mvMatrixLoc = 0;
    int m_normalMatrixLoc = 0;
    int m_lightPosLoc = 0;
    QMatrix4x4 m_proj;
    QMatrix4x4 m_camera;
    QMatrix4x4 m_world;

    Mesh m_mesh;
};
