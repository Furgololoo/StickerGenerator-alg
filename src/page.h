//
// Created by bfurg on 26/02/2023.
//

#ifndef STICKGEN_PAGE_H
#define STICKGEN_PAGE_H

#include <iostream>
#include <map>
#include <memory>
#include <opencv2/opencv.hpp>
#include "sticker.h"

namespace gen {

    class Page {

    public:

        explicit Page();
        ~Page();

        void CreateCustomPage(const uint16_t &width, const uint16_t &height, const uint8_t &r, const uint8_t &g,
                                const uint8_t &b);

        void AddSticker(const std::string& name, cv::Rect& rect);

        void ShowCurrentImage(const int time);

        void ChangeStickerSize(const std::string& name, const uint16_t& width, const uint16_t& height);

        void DrawCircle(const int& x, const int& y);

        cv::Mat GetImage() const;

    private:
        void CreateBasicPage(const uint16_t &width, const uint16_t &height);

        cv::Mat image;
        std::shared_ptr<cv::Scalar> pageColor;
        std::map<std::string, std::unique_ptr<Sticker>> stickers;
    };

} // gen

#endif //STICKGEN_PAGE_H
