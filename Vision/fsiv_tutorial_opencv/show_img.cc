/*!
  Ejemplo de carga de imagen y su visualización.

  Se supone que se utilizará OpenCV.

  Para compilar, puedes ejecutar:
    g++ -Wall -o esqueleto esqueleto.cc `pkg-config opencv --cflags --libs`

*/

#include <iostream>
#include <exception>

//Includes para OpenCV, Descomentar según los módulo utilizados.
#include <opencv2/core/core.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/calib3d/calib3d.hpp>

const cv::String keys =
    "{help h usage ? |      | print this message.   }"
    "{@image         |<none>| image to show.         }"
    ;

int main (int argc, char* const* argv) {
  int retCode=EXIT_SUCCESS;

  try {
    cv::CommandLineParser parser(argc, argv, keys);
    parser.about("Muestra una imagen v1.0.0");
    if (parser.has("help")) {
        parser.printMessage();
        return 0;
    }
    cv::String img_name = parser.get<cv::String>(0);

    if (!parser.check()) {
        parser.printErrors();
        return 0;
    }
    //Carga la imagen desde archivo.
    //En funcion de como se compilo opencv podra
    //cargar mas o menos formatos graficos.
    //Lee la documentacion de imread para ver mas detalles.
    cv::Mat img = cv::imread(img_name, cv::IMREAD_COLOR);

    if (img.empty()) {
       std::cerr << "Error: no he podido abrir el fichero '" << img_name << "'." << std::endl;
       return EXIT_FAILURE;
    }

    //Creo la ventana grafica para visualizar la imagen.
    //El nombre de la ventana sirve como 'handle' para gestionarla despues.
    //Lee la documentacon de namedWindow para mas detalles.
    cv::namedWindow("IMAGEN");

    //Visualizo la imagen cargada en la ventana.
    cv::imshow("IMAGEN", img);

    //Para que se actualice el la interfaz grafica es necesario llamar a
    //waitKey. Además esta función nos permite interactuar con el teclado.
    //Lee la documentacion de waitKey para mas detalles.
    cv::waitKey(0);
  }

  catch (std::exception& e) {
    std::cerr << "Capturada excepcion: " << e.what() << std::endl;
    retCode = EXIT_FAILURE;
  }

  return retCode;
}
