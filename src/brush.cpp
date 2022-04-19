#include <brush.h>
void Brush::drawBrush(p6::Context &ctx){
    const auto image = p6::load_image(m_imagePath.c_str());
        ctx.image(image, p6::Center{m_position},          
        p6::RadiusY{0.05f});
}

void Brush::brushButton(p6::Context &ctx, Brush &defaultBrush){
    if(std::abs(ctx.mouse().x-m_position.x)<0.05 && std::abs(ctx.mouse().y-m_position.y)<0.05){
       defaultBrush = *this; 
    }
}