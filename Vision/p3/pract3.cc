#include <iostream>
#include <exception>

//Includes para OpenCV, Descomentar según los módulo utilizados.
#include <opencv2/core/core.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/calib3d/calib3d.hpp>



//////////////////////////////////////////////////////////////////////////////

const cv::String keys =
    "{help h usage ? |      | print this message   }"
    // "{path           |  .   | path to file         }"
    // "{fps            |  -1.0| fps for output video }"
    // "{N count        |  100 | count of objects     }"
    // "{ts timestamp   |      | use time stamp       }"
    "{@image1        |      | image1 for compare   }"
    // "{@image2        |<none>| image2 for compare   }"
    // "{@repeat        |  1   | number               }"
    ;

//////////////////////////////////////////////////////////////////////////////

cv::Mat create_sharp_filter(int tipo, float g); //Crea un filtro Sharp 5 puntos (tipo==0) o 9 puntos (tipo==1) con una ganancia g>=0.0. El tipo de matriz será CV_32FC1.

void convolve(const cv::Mat& in, const cv::Mat& filter, cv::Mat& out, int border_type = 0); //calcula la convolución digital. La imagen de salida tendrá la mismas dimensiones y tipo de la imagen de entrada. La imagen original se extiende rellenando con ceros para poder realizar la convolución en todos los puntos de la imagen original. Precondiciones: in.type()==CV_32FC1 && filter.type()==CV_32FC1.

//////////////////////////////////////////////////////////////////////////////

int main (int argc, char* const* argv) {
  int retCode = EXIT_SUCCESS;

  try {

      cv::CommandLineParser parser(argc, argv, keys);
      parser.about("Application name v1.0.0");

      if (parser.has("help")) {
        parser.printMessage();
        return 0;
      }

      // int N = parser.get<int>("N");
      // double fps = parser.get<double>("fps");
      // cv::String path = parser.get<cv::String>("path");
      // bool use_time_stamp = parser.has("timestamp");
      cv::String img1 = parser.get<cv::String>(0);
      // cv::String img2 = parser.get<cv::String>(1);
      // int repeat = parser.get<int>(2);

      if (!parser.check()) {
        parser.printErrors();
        return 0;
      }





  }

  catch (std::exception& e) {
    std::cerr << "Capturada excepcion: " << e.what() << std::endl;
    retCode = EXIT_FAILURE;
  }

  return retCode;
}

//////////////////////////////////////////////////////////////////////////////

cv::Mat create_sharp_filter(int tipo, float g) {



}

//////////////////////////////////////////////////////////////////////////////

// Funcion de convolucion
void convolve(const cv::Mat& in, const cv::Mat& filter, cv::Mat& out, int border_type = 0) {
  // Precondiciones
  #ifndef NDEBUG
    assert(in.type() == CV_32FC1);
    assert(filter.type() == CV_32FC1);
  #endif


// REALIZAR EXTENSION DE IMAGEN



  for (size_t i = 0; i < in.rows; i++) {
    for (size_t j = 0; j < in.cols; j++) {
      for (size_t k = 0; k < filtrer.rows; k++) {
        for (size_t l = 0; l < filtrer.cols; l++) {





        }
      }
    }
  }

}

//////////////////////////////////////////////////////////////////////////////
