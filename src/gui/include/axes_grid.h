//
// Created by egi on 5/23/19.
//

#ifndef ANYSIM_AXES_GRID_H
#define ANYSIM_AXES_GRID_H

#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>

#include <memory>

class axes_grid : protected QOpenGLFunctions
{
public:
  axes_grid () = default;

  void init (
      QObject *parent,
      unsigned int x_tics_arg, unsigned int y_tics,
      float left_x, float right_x,
      float bottom_y, float top_y,
      float x_size, float y_size);
  void draw (QMatrix4x4 &mvp);

private:
  float x_size, y_size;
  const float tic_size = 0.01f;
  const float long_tic_size = 0.025f;
  unsigned int x_tics = 0, y_tics = 0;
  unsigned int total_coords = 0;
  const unsigned int long_tic_each = 4;
  std::unique_ptr<GLfloat[]> coords;

  QOpenGLBuffer grid_vbo;
  QOpenGLShaderProgram *program;
  QOpenGLVertexArrayObject grid_vao;
};

#endif //ANYSIM_AXES_GRID_H
