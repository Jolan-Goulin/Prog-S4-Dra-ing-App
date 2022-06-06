
#include <brushStore.h>

glm::vec2 last_point;
int counter = 0;
std::vector<BrushUI> brush_table(p6::Context &ctx) {

  std::vector<BrushUI> brush_store;
  const auto brush_default = [&]() {
    ctx.use_stroke = false;
    ctx.fill = {0.2f, 0.5f, 0.7f, 1.f};
    ctx.circle(p6::Center{ctx.mouse()}, p6::Radius{0.04f});
    last_point = ctx.mouse();
  };

  const auto brush_rainbow_semi_sines = [&]() {
    counter++;
    if (counter % 3 == 0) {
      ctx.use_stroke = false;
      ctx.fill = {0.2f, 0.5f, 0.7f, 0.2f};
      ctx.stroke = {1.f - 2 * ctx.mouse().x, 1.f - 2 * ctx.mouse().y,
                    1.f - (ctx.mouse().x + ctx.mouse().y)};
      ctx.line(last_point, ctx.mouse());
      ctx.circle(p6::Center{ctx.mouse()}, p6::Radius{0.01f});
      last_point = ctx.mouse();
    }
  };

  Brush rainbow_semi_lines_brush{brush_rainbow_semi_sines, brush_default};
  BrushUI rainbow_semi_lines_brush_UI{glm::vec2{-1.6f, 0.8f},
                                      "./../../assets/image.jpg",
                                      rainbow_semi_lines_brush};

  const auto brush_circle = [&]() {
    ctx.use_stroke = false;
    ctx.fill = {0.2f, 0.5f, 0.7f, 0.2f};
    ctx.circle(p6::Center{ctx.mouse()}, p6::Radius{1.01f});
    last_point = ctx.mouse();
  };

  Brush circle_brush{brush_circle, brush_circle};
  BrushUI circle_brush_UI{glm::vec2{-1.6f, 0.6f}, "./../../assets/image.jpg",
                          circle_brush};

  const auto brush_line = [&]() {
    ctx.use_stroke = true;
    ctx.fill = {0.2f, 0.5f, 0.7f, 1.f};
    ctx.line(last_point, ctx.mouse());
    ctx.circle(p6::Center{ctx.mouse()}, p6::Radius{0.01f});
    last_point = ctx.mouse();
    brush_store[0].get_brush()->new_point_drawn();
  };

  const auto brush_line_stand = [&]() {
    ctx.use_stroke = true;
    ctx.fill = {0.2f, 0.5f, 0.7f, 1.f};
    if (brush_store[0].get_brush()->points_drawn_number() == 0) {
      last_point = ctx.mouse();
    }
    ctx.line(last_point, ctx.mouse());
    ctx.circle(p6::Center{ctx.mouse()}, p6::Radius{0.01f});
  };
  Brush line_brush{brush_line, brush_line_stand};
  BrushUI line_brush_UI{glm::vec2{-1.6f, 0.4f}, "./../../assets/image.jpg",
                        line_brush};
  brush_store.push_back(line_brush_UI);

  const auto brush_aerograph = [&]() {
    ctx.use_stroke = false;
    if (last_point != ctx.mouse()) {
      ctx.fill = {0.2f, 0.5f, 0.7f, 0.8f};
      ctx.circle(p6::Center{ctx.mouse()}, p6::Radius{0.01f});
      ctx.fill = {0.2f, 0.5f, 0.7f, 0.6f};
      ctx.circle(p6::Center{ctx.mouse()}, p6::Radius{0.03f});
      ctx.fill = {0.2f, 0.5f, 0.7f, 0.45f};
      ctx.circle(p6::Center{ctx.mouse()}, p6::Radius{0.05f});
      ctx.fill = {0.2f, 0.5f, 0.7f, 0.30f};
      ctx.circle(p6::Center{ctx.mouse()}, p6::Radius{0.07f});
      ctx.fill = {0.2f, 0.5f, 0.7f, 0.15f};
      ctx.circle(p6::Center{ctx.mouse()}, p6::Radius{0.10f});
    }
    last_point = ctx.mouse();
  };

  Brush aerograph_brush{brush_aerograph, brush_aerograph};
  BrushUI aerograph_brush_UI{glm::vec2{-1.6f, 0.2f}, "./../../assets/image.jpg",
                             aerograph_brush};

  const auto brush_square = [&]() {
    ctx.use_stroke = true;
    ctx.fill = {0.2f, 0.5f, 0.7f, 1.f};
    p6::Angle rotation = 0.0_turn;
    ctx.rectangle(p6::Center{ctx.mouse()}, p6::Radii{0.05f, 0.05f},
                  p6::Rotation{rotation});
  };
  Brush square_brush{brush_square, brush_square};
  BrushUI square_brush_UI{glm::vec2{-1.6f, 0.f}, "./../../assets/image.jpg",
                          square_brush};

  brush_store.push_back(rainbow_semi_lines_brush_UI);
  brush_store.push_back(circle_brush_UI);
  brush_store.push_back(aerograph_brush_UI);
  brush_store.push_back(square_brush_UI);
  return brush_store;
}

Brush default_brush(p6::Context &ctx) {
  const auto brush_default = [&]() {
    ctx.use_stroke = false;
    ctx.fill = {0.2f, 0.5f, 0.7f, 1.f};
    ctx.circle(p6::Center{ctx.mouse()}, p6::Radius{0.04f});
    last_point = ctx.mouse();
  };

  return Brush{brush_default, brush_default};
};