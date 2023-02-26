//
// Created by bfurg on 26/02/2023.
//

#include "page.h"

namespace gen {
    Page::Page() {
        pageColor = std::make_shared<cv::Scalar>(cv::Scalar(255,255,255));
        CreateBasicPage(1280, 720);

    }

    Page::~Page() {

    }

    void Page::CreateBasicPage(const uint16_t &width, const uint16_t &height) {
        image = cv::Mat(height, width, CV_8UC3, pageColor.get());
    }

    void Page::CreateCustomPage(const uint16_t &width, const uint16_t &height, const uint8_t &r, const uint8_t &g,
                                  const uint8_t &b) {
        if(!image.empty())
            image.release();    // maybe ask for save?
        image = cv::Mat(height, width, CV_8UC3, cv::Scalar(r,g, b));
    }

    void Page::AddSticker(const std::string &name) {
        std::unique_ptr<Sticker> sticker = std::make_unique<Sticker>(Sticker(image, cv::Rect(25,25,100,100)));
        sticker->SetColor(pageColor);
        stickers.insert({name, std::move(sticker)});
    }

    void Page::ShowCurrentImage() {
        imshow("BasicImage", image);
        std::cout<<"Created basic image"<<std::endl;
        std::cout<<"Parameters: "<<std::endl;
        std::cout<<"\twidth: "<<image.cols<<" height: "<<image.rows<<std::endl;

        cv::waitKey(0);
        cv::destroyWindow("BasicImage");
    }

    void Page::ChangeStickerSize(const std::string &name, const uint16_t& width, const uint16_t& height) {
        stickers.at(name)->ChangeStickerSize(cv::Size(width, height));
    }

} // gen

