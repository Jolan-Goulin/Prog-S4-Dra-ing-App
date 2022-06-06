#include <iostream>
#include <p6/p6.h>

class Brush {
private:
  glm::vec2 m_lastPoint;
  int m_points_drawn = 0;

public:
  std::function<void()> brush;
  std::function<void()> standBrush;
  inline const glm::vec2 get_last_point() { return m_lastPoint; }
  inline void new_last_point(glm::vec2 newLastPoint) {
    m_lastPoint = newLastPoint;
  }
  inline void new_point_drawn() { m_points_drawn++; }
  inline void reset_point_drawn() { m_points_drawn = 0; }
  inline int points_drawn_number() { return m_points_drawn; }
  Brush(std::function<void()> brush, std::function<void()> standBrush)
      : brush(brush), standBrush(standBrush) {}
};

class BrushUI {
private:
  glm::vec2 m_position;
  std::string m_imagePath;
  Brush m_brush;

public:
  void draw_brush(p6::Context &ctx);
  void brush_button(p6::Context &ctx, Brush &defaultBrush);
  inline Brush *get_brush() { return &m_brush; }
  inline void change_brush(Brush brush) { m_brush = brush; }
  BrushUI(glm::vec2 position, std::string imagePath, Brush brush)
      : m_position(position), m_imagePath(imagePath), m_brush(brush) {}
};