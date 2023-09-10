#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include <array>

namespace
{
constexpr auto HEIGHT = 400;
constexpr auto WIDTH = 400;

cv::Mat get_atom(cv::Size = { WIDTH, HEIGHT });
cv::Mat get_rook(cv::Size = { WIDTH, HEIGHT });
} // anonymous namespace

int main()
{
    const auto ATOM = "Atom";
    const auto ROOK = "Rook";

    cv::Mat atom = get_atom();
    cv::Mat rook = get_rook();

    cv::imshow(ATOM, atom);
    cv::imshow(ROOK, rook);

    cv::moveWindow(ROOK, atom.cols, 0);
    cv::waitKey(0);

    return 0;
}

namespace
{
using degrees = double;
void draw_ellipse(cv::Mat img, degrees angle)
{
    const auto width = img.cols;
    const auto height = img.rows;

    cv::ellipse(img,
        { width / 2, height / 2 },
        { width / 4, height / 16 },
        angle,
        0,
        360,
        { 255, 0, 0 },
        2,
        cv::LINE_AA);
}

void draw_filled_circle(cv::Mat img, cv::Point centre)
{
    const auto radius = std::max(img.rows, img.cols) / 32;
    cv::circle(img,
        centre,
        radius,
        { 0, 0, 255 },
        cv::FILLED,
        cv::LINE_AA);
}

cv::Mat get_atom(cv::Size size)
{
    cv::Mat atom = cv::Mat::zeros(size, CV_8UC3);

    for (auto angle : { 90, 0, 45, -45 })
    {
        draw_ellipse(atom, angle);
    }
    draw_filled_circle(atom, { atom.cols / 2, atom.rows / 2 });
    return atom;
}

void draw_polygon(cv::Mat img)
{
    const auto w = img.cols;

    std::array<cv::Point, 20> points{
        cv::Point{ w/4, 7*w/8 },
        cv::Point{ 3*w/4, 7*w/8 },
        cv::Point{ 3*w/4, 13*w/16 },
        cv::Point{ 11*w/16, 13*w/16 },
        cv::Point{ 19*w/32, 3*w/8 },
        cv::Point{ 3*w/4, 3*w/8 },
        cv::Point{ 3*w/4, w/8 },
        cv::Point{ 26*w/40, w/8 },
        cv::Point{ 26*w/40, w/4 },
        cv::Point{ 22*w/40, w/4 },
        cv::Point{ 22*w/40, w/8 },
        cv::Point{ 18*w/40, w/8 },
        cv::Point{ 18*w/40, w/4 },
        cv::Point{ 14*w/40, w/4 },
        cv::Point{ 14*w/40, w/8 },
        cv::Point{ w/4, w/8 },
        cv::Point{ w/4, 3*w/8 },
        cv::Point{ 13*w/32, 3*w/8 },
        cv::Point{ 5*w/16, 13*w/16 },
        cv::Point{ w/4, 13*w/16 },
    };

    cv::fillPoly(img,
        points,
        { 255, 255, 255 },
        cv::LINE_AA);
}

void draw_line(cv::Mat img, cv::Point from, cv::Point to)
{
    cv::line(img, from, to, { 0, 0, 0 }, 2, cv::LINE_AA);
}

cv::Mat get_rook(cv::Size size)
{
    cv::Mat rook = cv::Mat::zeros(size, CV_8UC3);
    const auto w = rook.cols;

    draw_polygon(rook);
    cv::rectangle(rook, { 0, 7*w/8 }, size, { 0, 255, 255 }, cv::FILLED, cv::LINE_AA);
    draw_line(rook, {     0, 15*w/16 }, { w, 15*w/16 } );
    draw_line(rook, {   w/4,  7*w/8  }, { w/4, w } );
    draw_line(rook, {   w/2,  7*w/8  }, { w/2, w } );
    draw_line(rook, { 3*w/4,  7*w/8  }, { 3*w/4, w } );

    return rook;
}
} // anonymous namespace

