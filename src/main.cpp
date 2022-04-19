  
#include <p6/p6.h>
#include <iostream>
#include <brush.h>

int main()
{
    try {
        glm::vec2 last_point;
        int counter = 0;
        // Create the Context by giving the initial size and name of our window
        auto ctx = p6::Context{{1280, 720, "p6 Basic Example"}};
        // Define the update function. It will be called repeatedly.
        auto canvas = p6::Canvas{ctx.framebuffer_size()}; // Create an empty canvas with the same size as the window's framebuffer    
        ctx.render_to_canvas(canvas);
            const auto image = p6::load_image("/home/6ima2/jolan.goulin/Bureau/Gull_portrait_ca_usa.jpg");
            ctx.image(image, p6::Center{},          
            p6::RadiusY{1.f}); // Give it a height of 0.4 The width will be deduced based on the aspect_ratio of the image
        ctx.render_to_screen();
        ctx.framebuffer_resized = [&]() {        
            canvas.resize(ctx.framebuffer_size()); // Make sure that the canvas still has the same size as the window's framebuffer even after it resizes    
        };
        
        /*const auto brush_square = [&]() {
            ctx.use_stroke = true;
            ctx.fill = {0.2f, 0.5f, 0.7f, 1.f};
            p6::Angle rotation = 0.0_turn;
            ctx.rectangle(p6::Center{ctx.mouse()},
                    p6::Radii{0.05f,0.05f},
                    p6::Rotation{rotation});
        };*/
        const auto brush = [&]() {
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
        const auto brush2 = [&]() {
            ctx.use_stroke = false;
            ctx.fill = {0.2f, 0.5f, 0.7f, 0.2f};
            ctx.circle(p6::Center{ctx.mouse()}, 
                    p6::Radius{1.01f});
            last_point = ctx.mouse();
        };
        Brush brrush{glm::vec2{-1.6f,0.8f}, "/home/6ima2/jolan.goulin/Bureau/Gull_portrait_ca_usa.jpg", brush, brush2};
        Brush defaultBrush{glm::vec2{-1.6f,0.8f}, "/home/6ima2/jolan.goulin/Bureau/Gull_portrait_ca_usa.jpg", brush2, brush};
        auto canvasBrush = p6::Canvas{ctx.framebuffer_size()}; // Create an empty canvas with the same size as the window's framebuffer    
        ctx.render_to_canvas(canvasBrush);
            brrush.drawBrush(ctx);
        ctx.render_to_screen();

        ctx.mouse_pressed = [&brrush, &ctx, &defaultBrush](p6::MouseButton) {
            brrush.brushButton(ctx, defaultBrush);
        };


        ctx.update = [&]() {
            //  Clear the objects that were drawn during the previous update
            ctx.background({0.5f, 0.3f, 0.8f});
            ctx.image(canvas);
            // Draw a circle
            ctx.fill = {1.f, 0.7f, 0.2f, 0.3f};
            /*ctx.circle(p6::Center{-ctx.mouse()}, // Centered on the current position of the mouse
                       p6::Radius{float(cos(ctx.time()))});       // With a given radius;  */  

            if (ctx.shift()) {
                ctx.render_to_canvas(canvas);
                defaultBrush.brush(); // We can do some permanent drawings on our canvas
                ctx.render_to_screen();
            }
            else {
                defaultBrush.standBrush(); // While still being able to draw temporary things on the screen
            }
            if (ctx.ctrl()) {
                last_point = glm::vec2(0.f,0.f);

            }
            ctx.image(canvasBrush);
        };
        // Start the program
        
        ctx.start();
    }
    // Log any error that might occur
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}