#include <p6/p6.h>
#include <iostream>

class Brush {
    private:
        glm::vec2 m_position;
        std::string m_imagePath;
        glm::vec2 m_lastPoint;
    public:
        std::function<void()> brush;
        std::function<void()> standBrush;
        inline const glm::vec2 getLastPoint(){return m_lastPoint;}
        inline void newLastPoint(glm::vec2 newLastPoint) {m_lastPoint = newLastPoint;}
        void drawBrush(p6::Context &ctx);
        void brushButton(p6::Context &ctx, Brush &defaultBrush);
        Brush (glm::vec2 position, std::string imagePath, std::function<void()> brush, std::function<void()> standBrush): m_position(position), m_imagePath(imagePath), brush(brush), standBrush(standBrush){}
};