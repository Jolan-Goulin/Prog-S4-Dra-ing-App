#include <p6/p6.h>
#include <iostream>

class Brush {
    private:
        glm::vec2 m_position;
        std::string m_imagePath;
        glm::vec2 m_lastPoint;
        int m_points_drawn = 0;
    public:
        std::function<void()> brush;
        std::function<void()> standBrush;
        inline const glm::vec2 get_last_point(){return m_lastPoint;}
        inline void new_last_point(glm::vec2 newLastPoint) {m_lastPoint = newLastPoint;}
        inline void new_point_drawn() {m_points_drawn++;}
        inline void reset_point_drawn() {m_points_drawn = 0;}
        inline int points_drawn_number(){return m_points_drawn;}
        void draw_brush(p6::Context &ctx);
        void brush_button(p6::Context &ctx, Brush &defaultBrush);
        Brush (glm::vec2 position, std::string imagePath, std::function<void()> brush, std::function<void()> standBrush): m_position(position), m_imagePath(imagePath), brush(brush), standBrush(standBrush){}
};