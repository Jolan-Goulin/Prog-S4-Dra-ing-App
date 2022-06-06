#include <colorPicker.h>

void draw_colorpicker(p6::Context &ctx){
    ctx.use_stroke = true;
    p6::Angle rotation = 0.0_turn;
    int counter =0;
    for(int i=0;i<10;i++){
        ctx.fill = {1.f, 0.2f*counter, 0.2f*counter, 1.f};
        ctx.rectangle(p6::Center{glm::vec2{0.8f+0.2f*float(counter%5), 0.8f+0.2f*float(counter/5)}},
                        p6::Radii{0.02f,0.02f},
                        p6::Rotation{rotation});
            counter++;
        };
    }

void colorpicker_button(){

}