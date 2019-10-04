/*!
  Ejemplo de carga de un video y su visualización.

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
    "{w wait         |34    | number of msecs to wait between frames.}"
    "{@video         |<none>| video to show. Use -1 for live video.}"
    ;


void on_mouse(int event, int x, int y, int flags, void *userdata)
{
    if (event == cv::EVENT_LBUTTONDOWN)
    {
        static_cast<int*>(userdata)[0] = x;
        static_cast<int*>(userdata)[1] = y;
    }
}

int
main (int argc, char* const* argv)
{
  int retCode=EXIT_SUCCESS;

  try {

      cv::CommandLineParser parser(argc, argv, keys);
      parser.about("Muestra un video. Pulsa con el raton en un punto para ver "
                   "los valores RGB. v1.0.0");
      if (parser.has("help"))
      {
          parser.printMessage();
          return 0;
      }
      int wait = parser.get<int>("w");
      cv::String vid_name = parser.get<cv::String>(0);

      if (!parser.check())
      {
          parser.printErrors();
          return 0;
      }

      cv::VideoCapture vid;
      if (atoi(vid_name.c_str()) != 0)
         //Para abrir un dispositvo opencv usa indices.
         //para identificarlos. Usa -1 (el primero disponible).
         vid.open(atoi(vid_name.c_str()));
      else
         vid.open(vid_name);

      if (!vid.isOpened())
      {
         std::cerr << "Error: no he podido abrir el video '" << vid_name << "'." << std::endl;
         return EXIT_FAILURE;
      }


      //Creo la ventana grafica para visualizar la imagen.
      //El nombre de la ventana sirve como 'handle' para gestionarla despues.
      //Lee la documentacon de namedWindow para mas detalles.
      cv::namedWindow("VIDEO");

      //Conectamos a la ventana un callback para gestionar el raton.
      int coords[2] = {-1, -1};
      cv::setMouseCallback("VIDEO", on_mouse, coords);

      cv::Mat frame;

      //Captura el primer frame.
      //Si el frame esta vacio, puede ser un error hardware o fin del video.
      vid >> frame;
      int key = 0;

      //Muestro frames hasta fin del video (frame vacio),
      // o que el usario pulse la tecla ESCAPE (codigo ascci 27)
      while (!frame.empty() && key!=27)
      {
         //muestro el frame.
         cv::imshow("VIDEO", frame);

         if (coords[0] != -1)
         {
            const cv::Vec3b v = frame.at<cv::Vec3b>(coords[1], coords[0]);
            std::cout << "RGB point (" << coords[0] << ',' << coords[1] << "): "
                << (int)v[0] << ", " << (int)v[1] << ", " << (int)v[2]
                << std::endl;
         }

         //Espero un tiempo fijado. Si el usuario pulsa una tecla obtengo
         //el codigo ascci. Si pasa el tiempo, retorna -1.
         key = cv::waitKey(wait) & 0xff;    //& 0xff -> Coge los bits menos significativos para evitar errores con teclas pulsadas.

         //capturo el siguiente frame.
         vid >> frame;
      }
  }
  catch (std::exception& e)
  {
    std::cerr << "Capturada excepcion: " << e.what() << std::endl;
    retCode = EXIT_FAILURE;
  }
  return retCode;
}
