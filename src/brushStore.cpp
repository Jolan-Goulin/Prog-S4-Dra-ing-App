#include <p6/p6.h>
#include <iostream>
#include <brush.h>
#include <brushStore.h>

glm::vec2 last_point;
int counter = 0;

/*std::vector<Brush>*/ void brushtable(p6::Context ctx){

    const auto brush_default = [&]() {
                counter++;
                if (counter%3 == 0) {
                    ctx.use_stroke = false;
                    ctx.fill = {0.2f, 0.5f, 0.7f, 0.2f};
                    ctx.circle(p6::Center{ctx.mouse()}, 
                            p6::Radius{0.01f});
                    last_point = ctx.mouse();
                }
            };



    const auto brush_rainbowSemiLines = [&]() {
                counter++;
                if (counter%3 == 0) {
                    ctx.use_stroke = false;
                    ctx.fill = {0.2f, 0.5f, 0.7f, 0.2f};
                    ctx.stroke = {1.f-2*ctx.mouse().x, 1.f-2*ctx.mouse().y, 1.f-(ctx.mouse().x+ctx.mouse().y)};
                    ctx.line(last_point, ctx.mouse());
                    ctx.circle(p6::Center{ctx.mouse()}, 
                            p6::Radius{0.01f});
                    last_point = ctx.mouse();
                }
            };

    Brush rainbowSemiLinesBrush{glm::vec2{-1.6f,0.8f}, "/home/6ima2/jolan.goulin/Bureau/Gull_portrait_ca_usa.jpg", brush_rainbowSemiLines, brush_default};

    const auto brush_circle = [&]() {
                ctx.use_stroke = false;
                ctx.fill = {0.2f, 0.5f, 0.7f, 0.2f};
                ctx.circle(p6::Center{ctx.mouse()}, 
                        p6::Radius{1.01f});
                last_point = ctx.mouse();
            };

    Brush circleBrush{glm::vec2{-1.6f,0.8f}, "/home/6ima2/jolan.goulin/Bureau/Gull_portrait_ca_usa.jpg", brush_circle, brush_circle};

    const auto brush_line = [&]() {
                ctx.use_stroke = true;
                ctx.fill = {0.2f, 0.5f, 0.7f, 1.f};
                ctx.line(last_point, ctx.mouse());
                ctx.circle(p6::Center{ctx.mouse()}, 
                        p6::Radius{0.01f});
                if(last_point == glm::vec2(0.f,0.f)){
                    last_point = ctx.mouse();
                }
            };


    Brush lineBrush{glm::vec2{-1.6f,0.8f}, "/home/6ima2/jolan.goulin/Bureau/Gull_portrait_ca_usa.jpg", brush_line, brush_line};

    const auto brush_aerograph = [&]() {
        ctx.use_stroke = false;
        if(last_point != ctx.mouse()){
            ctx.fill = {0.2f, 0.5f, 0.7f, 0.8f};
            ctx.circle(p6::Center{ctx.mouse()}, 
                    p6::Radius{0.01f});
            ctx.fill = {0.2f, 0.5f, 0.7f, 0.6f};
            ctx.circle(p6::Center{ctx.mouse()}, 
                    p6::Radius{0.03f});
            ctx.fill = {0.2f, 0.5f, 0.7f, 0.45f};
            ctx.circle(p6::Center{ctx.mouse()}, 
                    p6::Radius{0.05f});
            ctx.fill = {0.2f, 0.5f, 0.7f, 0.30f};
            ctx.circle(p6::Center{ctx.mouse()}, 
                    p6::Radius{0.07f});
            ctx.fill = {0.2f, 0.5f, 0.7f, 0.15f};
            ctx.circle(p6::Center{ctx.mouse()}, 
                    p6::Radius{0.10f});}
        last_point = ctx.mouse();
    };

    Brush aerographBrush{glm::vec2{-1.6f,0.8f}, "/home/6ima2/jolan.goulin/Bureau/Gull_portrait_ca_usa.jpg", brush_aerograph, brush_aerograph};
    
}