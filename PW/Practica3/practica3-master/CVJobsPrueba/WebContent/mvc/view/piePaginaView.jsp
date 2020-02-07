<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<script src="../../javascript/funcionesComunes.js"></script>
    <script src="../../javascript/funcionesInicio.js"></script>
</head>
</head>
<body>
    <footer>
        <div class="contenedor">
           <h2 class="titulo-footer">Eslogan de la empresa</h2>
           <h3 class="subtitulo-footer"></h3>
           <div class="footers">
                <div class="footer1">
                  <form method="get" action="piePagina.html">
                      <button class="boton" name="nosotros" value="nosotros">
                          <input type="submit" value="Nosotros"  name="Nosotros" class="botonPie">
                      </button>
                      <button class="boton" name="seguridad" value="seguridad">
                          <input type="submit" value="seguridad"  name="seguridad" class="botonPie">
                      </button>
                      <button class="boton" name="ayuda" value="ayuda">
                          <input type="submit" value="ayuda"  name="ayuda" class="botonPie">
                      </button>
                  </form>

                  </form>
                </div>
                <div class="footer2">
                    <button class="rSocial">
                        <img src="../../imagenes/facebookIcon.jpg" alt="Facebook" />
                    </button>
                    <button class="rSocial">
                        <img src="../../imagenes/twitterIcon.png" alt="Twitter" />
                    </button>
                </div>
            </div>
        </div>
    </footer>

</body>
</html>