
#include <brushStore.h>
#include <iostream>
#include <p6/p6.h>

int main() {
  try {
    // Create the Context by giving the initial size and name of our window
    auto ctx = p6::Context{{1280, 720, "p6 Basic Example"}};
    // Define the update function. It will be called repeatedly.
    auto canvas = p6::Canvas{
        ctx.framebuffer_size()}; // Create an empty canvas with the same size as
                                 // the window's framebuffer
    ctx.render_to_canvas(canvas);
    const auto image = p6::load_image("./../../assets/image.jpg");
    ctx.image(
        image, p6::Center{},
        p6::RadiusY{1.f}); // Give it a height of 0.4 The width will be deduced
                           // based on the aspect_ratio of the image
    ctx.render_to_screen();
    ctx.framebuffer_resized = [&]() {
      canvas.resize(
          ctx.framebuffer_size()); // Make sure that the canvas still has the
                                   // same size as the window's framebuffer even
                                   // after it resizes
    };
    Brush defaultBrush = default_brush(ctx);

    std::vector<BrushUI> brushes = brush_table(ctx);
    auto canvasBrush = p6::Canvas{
        ctx.framebuffer_size()}; // Create an empty canvas with the same size as
                                 // the window's framebuffer
    ctx.render_to_canvas(canvasBrush);
    for (size_t i = 0; i < brushes.size(); i++) {
      brushes[i].draw_brush(ctx);
    }
    ctx.render_to_screen();

    ctx.mouse_pressed = [&](p6::MouseButton) {
      for (size_t i = 0; i < brushes.size(); i++) {
        brushes[i].brush_button(ctx, defaultBrush);
      }
    };

    ctx.update = [&]() {
      //  Clear the objects that were drawn during the previous update
      ctx.background({0.5f, 0.3f, 0.8f});
      ctx.image(canvas);
      if (ctx.shift()) {
        ctx.render_to_canvas(canvas);
        defaultBrush.brush(); // We can do some permanent drawings on our canvas
        ctx.render_to_screen();
      } else {
        defaultBrush.standBrush(); // While still being able to draw temporary
                                   // things on the screen
      }
      ctx.image(canvasBrush);
    };
    // Start the program

    ctx.start();
  }
  // Log any error that might occur
  catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
}