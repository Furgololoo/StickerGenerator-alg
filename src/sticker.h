//
// Created by bfurg on 25/02/2023.
//

#ifndef STICKGEN_STICKER_H
#define STICKGEN_STICKER_H

#include <opencv2/opencv.hpp>
#include <memory>
#include <iostream>

namespace gen {

    class Sticker {

    public:
        Sticker(cv::Mat& mat, cv::Rect _rect);
        ~Sticker();

        void ChangeStickerSize(cv::Size size);
        void SetPageColor(std::shared_ptr<cv::Scalar> _color);
        void DrawRectangle();

    protected:
        void RemovePreviouslyRectangle();

        cv::Rect rect;
        cv::Scalar color;
        cv::Mat& baseImage;

        std::shared_ptr<cv::Scalar> pageColor;
    };

}

#endif //STICKGEN_STICKER_H
