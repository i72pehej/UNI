#include <iostream>
#include <exception>

//Includes para OpenCV, Descomentar según los módulo utilizados.
#include <opencv2/core/core.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/calib3d/calib3d.hpp>

const cv::String keys =
  "{help h usage ?  |      | print this message }"
  "{@image          |      | image for process  }"
  // "{path           |.     | path to file         }"
  // "{fps            | -1.0 | fps for output video }"
  // "{N count        |100   | count of objects     }"
  // "{ts timestamp   |      | use time stamp       }"
  // "{@image2        |<none>| image2 for compare   }"
  // "{@repeat        |1     | number               }"
;

















int main (int argc, char* const* argv) {
  int retCode = EXIT_SUCCESS;

  try {
    cv::CommandLineParser parser(argc, argv, keys);
    parser.about("Application name v1.0");

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








    // Carga de una imagen seleccionada por el usuario (color o monocroma)
    cv::Mat img = cv::imread(img1, cv::IMREAD_ANYCOLOR);

    if (img.empty()) {
       std::cerr << "Error: no he podido abrir el fichero '" << img1 << "'." << std::endl;
       return EXIT_FAILURE;
    }

    //Creo la ventana grafica para visualizar la imagen.
    //El nombre de la ventana sirve como 'handle' para gestionarla despues.
    cv::namedWindow("IMAGEN ORIGINAL");
    //Visualizo la imagen cargada en la ventana.
    cv::imshow("IMAGEN ORIGINAL", img);

    // Normalizamos la imagen que se carga
    cv::Mat img_procesada;
    img.convertTo(img_procesada, CV_32F, 1.0 / 255, 0);

    // Visualizar la imagen procesada
    cv::namedWindow("IMAGEN PROCESADA");
    cv::imshow("IMAGEN PROCESADA", img_procesada);

    // Se comprueba que la imagen sea RGB (3 canales)
    bool esRGB = false;
    if (img_procesada.channels() == 3) {esRGB = true;}

    // Si es RGB el proceso se aplica solo a la iluminancia (V) en HSV
    if (esRGB == true) {
      cv::Mat img_salida = img_procesada.clone();
      cv::Mat canalesHSV[3];

      // Se transforma al formato HSV
      cv::cvtColor(img_salida, img_salida, CV_BGR2HSV);

      // Se separan los canales para poder procesar solo el canal V
      cv::split(img_salida, canalesHSV);


      // Se realiza el procesamiento del canal V
      for (size_t i = 0; i < img_salida.rows; i++) {
        for (size_t j = 0; j < img_salida.cols; j++) {
          cv::Vec3b pixel = img_salida.at<cv::Vec3b>(i, j);

          uchar B = pixel[0];
          uchar G = pixel[1];
          uchar R = pixel[2];

          // gray.at<uchar>(i, j) = (B + G + R) / 3;
        }
      }


      // Se vuelven a unir los 3 canales en la imagen
      img_salida.merge();

    } else {





    }











    cv::waitKey(0);
  }

  catch (std::exception& e) {
    std::cerr << "Capturada excepcion: " << e.what() << std::endl;
    retCode = EXIT_FAILURE;
  }

  return retCode;
}
