#include <brush.h>
void Brush::draw_brush(p6::Context &ctx){
    const auto image = p6::load_image(m_imagePath.c_str());
        ctx.image(image, p6::Center{m_position},          
        p6::RadiusY{0.05f});
}

void Brush::brush_button(p6::Context &ctx, Brush &defaultBrush){
    if(std::abs(ctx.mouse().x-m_position.x)<0.05 && std::abs(ctx.mouse().y-m_position.y)<0.05){
       this->reset_point_drawn();
       defaultBrush = *this; 
       defaultBrush.reset_point_drawn();
    }
}