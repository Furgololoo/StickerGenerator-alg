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
        void SetColor(std::weak_ptr<cv::Scalar> color);

    protected:
        void DrawRectangle();
        void RemovePreviouslyRectangle();

        cv::Rect rect;
        cv::Scalar color;
        cv::Mat& baseImage;

        std::weak_ptr<cv::Scalar> pageColor;
    };

}

#endif //STICKGEN_STICKER_H
