#include <raylib.h>
#include <stdlib.h>

#include "row_item.c"

void handle_keyboard_input(void) {
  int key = GetKeyPressed();
  switch (key) {
  case KEY_F: {
    ToggleFullscreen();
  } break;
  }
}

RowItem items[] = {
    {.name = "Barcelona", .where = "A20"},
    {.name = "Sevilla", .where = "B4"},
    {.name = "Madrid", .where = ""},
    {"", ""},
};

int main(void) {
  InitWindow(1067, 600, "Arrivals & Departures");
  SetTargetFPS(60);
  HideCursor();

  while (!WindowShouldClose()) {
    handle_keyboard_input();

    ClearBackground(BLACK);
    BeginDrawing();

    for (size_t index = 0; index < 10; index++) {
      Color color = (index % 2 == 0) ? BLACK : DARKGRAY;
      DrawRectangle(0, 60 * index, GetRenderWidth(), 100, color);
    }

    for (size_t index = 0; index < 10; index++) {
      RowItem item = items[index];
      if (item.name[0] == '\0') {
        break;
      }
      DrawText(item.name, 10, 5 + 60 * index, 50, WHITE);
    }

    EndDrawing();
  }
  CloseWindow();
  return 0;
}