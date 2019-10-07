/*!
  Ejemplo de carga de imagen y su recorrido para calcular estadisticos
  simples.

  Se supone que se utilizará OpenCV.

  Para compilar, puedes ejecutar:
    g++ -Wall -o esqueleto esqueleto.cc `pkg-config opencv --cflags --libs`

*/

#include <iostream>
#include <exception>
#include <valarray>

//Includes para OpenCV, Descomentar según los módulo utilizados.
#include <opencv2/core/core.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/calib3d/calib3d.hpp>

const cv::String keys =
    "{help h usage ? |      | print this message.   }"
    "{@image         |<none>| input image.          }"
    ;

/*!
    @brief Calcular los valores medios de una imagen y sus desviaciones.

    Ejemplo simple de recorrido de una imagen. OpenCv ya tiene funciones
    para calcular los valores medios y las desviaciones de forma mas eficiente.

    Esta es la forma menos eficiente de recorrer una imagen. Mira la
    documentacion de opencv para ver otras.

    @param[in] img es la imagen rgb de entrada.
    @param[out] means son los valores rgb medios.
    @param[out] devs son las desviaciones.

    @pre img no esta vacia.
    @pre img es de tipo CV_8UC3 (RGB en formato byte).
*/
void
compute_stats_opt(const cv::Mat& img, std::valarray<double>& means,
                                      std::valarray<double>& devs)
{
    //Comprobacion de precondiciones.
    CV_Assert( !img.empty() );
    CV_Assert( img.type() == CV_8UC3 );   //CV_8UC3: 8bits, unsigend, 3canales(RGB)

    means.resize(3, 0.0);
    devs.resize(3, 0.0);

    //Para cada fila 0 ... img.rows-1
    for (int row=0; row<img.rows; ++row)
        //Para cada columna 0 ... img.cols-1
        for (int col=0; col<img.cols; ++col)
            {
                //Acceder a un pixel con el metodo at<Tipo de pixel>(fila, columna).
                //Aqui cada pixel es una tripleta de 3 bytes -> CV_8UC3
                //que opencv representa como un vector de 3 bytes -> Vec3b.
                const cv::Vec3b v = img.at<cv::Vec3b>(row, col);    //Vec3b: Vector de 3bytes = lo que sabemos de 8UC3.
                //También podríamos tener:
                //   Un solo byte por pixel CV_8UC1 ->  at<byte>
                //   Un solo float por pixel CV_32FC1  ->  at<float>
                //   tres floats por pixel CV_32FC3   -> at<cv::Vec3f>
                //   ... mas combinaciones.


                means[0] += v[0];
                means[1] += v[1];
                means[2] += v[2];
                devs[0] += v[0]*v[0];
                devs[1] += v[1]*v[1];
                devs[2] += v[2]*v[2];
             }
    const double count = img.rows*img.cols;
    if (count > 0.0)
    {
        means /= count;
        devs /= count;
        devs = devs - means*means;
        devs = std::sqrt(devs);
    }
}

int
main (int argc, char* const* argv)
{
  int retCode=EXIT_SUCCESS;

  try {

      cv::CommandLineParser parser(argc, argv, keys);
      parser.about("Muestra una imagen v1.0.0");
      if (parser.has("help"))
      {
          parser.printMessage();
          return 0;
      }
      cv::String img_name = parser.get<cv::String>(0);

      if (!parser.check())
      {
          parser.printErrors();
          return 0;
      }
      //Carga la imagen desde archivo.
      //En funcion de como se compilo opencv podra
      //cargar mas o menos formatos graficos.
      //Lee la documentacion de imread para ver mas detalles.
      cv::Mat img = cv::imread(img_name, cv::IMREAD_COLOR);

      if (img.empty())
      {
         std::cerr << "Error: no he podido abrir el fichero '" << img_name << "'." << std::endl;
         return EXIT_FAILURE;
      }

        std::valarray<double> means;
        std::valarray<double> devs;

        //calculamos los estadisticos.
        compute_stats_opt(img, means, devs);

        std::cout << "Valores medios RGB: " << means[0] << ", "
            << means[1] << ", " << means[2] << std::endl;
        std::cout << "Desviaciones   RGB: " << devs[0] << ", "
            << devs[1] << ", " << devs[2] << std::endl;


      //Creo la ventana grafica para visualizar la imagen.
      //El nombre de la ventana sirve como 'handle' para gestionarla despues.
      //Lee la documentacon de namedWindow para mas detalles.
      cv::namedWindow("IMG");

      //Visualizo la imagen cargada en la ventana.
      cv::imshow("IMG", img);

      //Para que se actualice el la interfaz grafica es necesario llamar a
      //waitKey. Además esta función nos permite interactuar con el teclado.
      //Lee la documentacion de waitKey para mas detalles.
      cv::waitKey(0);

  }
  catch (std::exception& e)
  {
    std::cerr << "Capturada excepcion: " << e.what() << std::endl;
    retCode = EXIT_FAILURE;
  }
  return retCode;
}
