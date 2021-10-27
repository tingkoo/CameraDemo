#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    cv::Mat dstImage_ROI = dstImage(cv::Rect(20, 20, dstImage.cols - 40, dstImage.rows - 40));
    cv::Scalar scalar = cv::mean(dstImage_ROI);
    min = getMinPixel(dstImage_ROI);
    double val = min / scalar.val[0];
    ui->label_3->setText(QString::number(val, 10, 4));
}

void Dialog::on_pushButton_2_clicked()
{
    QImage Img;
    filename = QFileDialog::getOpenFileName(this, "choose image file", "/", "Image Files(*.png *.bmp *.jpg *.tif *.gif)");
    if (NULL != filename)
    {
        srcImage = cv::imread(filename.toStdString());
        dstImage.create(srcImage.size(), srcImage.type());
        cv::cvtColor(srcImage, dstImage, CV_BGR2GRAY);
        Img = QImage((const uchar*)(dstImage.data), dstImage.cols, dstImage.rows, dstImage.cols*dstImage.channels(), QImage::Format_Indexed8);
        ui->label->setAlignment(Qt::AlignCenter);
        ui->label->setPixmap(QPixmap::fromImage(Img));
    }
}

int Dialog::getMinPixel(cv::Mat Img)
{
    int iRows = Img.rows;
    int iCols = Img.cols;
    int min = Img.at<uchar>(0, 0);

    for (int i = 0; i < iRows; i++)
    {
        for (int j = 0; j < iCols; j++)
        {
            if (Img.at<uchar>(i, j) < min)
                min = Img.at<uchar>(i, j);
        }
    }
    return min;
}
