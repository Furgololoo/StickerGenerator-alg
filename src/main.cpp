#include <iostream>
#include "Page.h"

int main() {

    gen::Page page;
    page.CreateBasicSticker(1280, 720, 255,255,255);
    page.AddSticker("sticker1");
    page.ChangeStickerSize("sticker1", 200, 100);
    page.ShowCurrentImage();
    return 0;
}
