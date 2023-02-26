//
// Created by bfurg on 25/02/2023.
//

#include "Sticker.h"

namespace gen {

    Sticker::Sticker(cv::Mat& mat, cv::Rect _rect): baseImage(mat) {
        rect = _rect;
        color = cv::Scalar(0, 0, 0);
        DrawRectangle();
    }

    Sticker::~Sticker() {

    }

    void Sticker::ChangeStickerSize(cv::Size size) {
        RemovePreviouslyRectangle();
        rect.width = size.width;
        rect.height = size.height;
        DrawRectangle();
    }

    void Sticker::DrawRectangle() {
        cv::rectangle(baseImage, rect, color, 4, cv::LineTypes::LINE_8, 0);
    }

    void Sticker::RemovePreviouslyRectangle() {

    }

    void Sticker::SetColor(std::weak_ptr<cv::Scalar> color) {
        pageColor = color;
    }

}
