<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="ISO-8859-1" http-equiv="Content-Type" content="text/html; charset=utf-8"/>
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <Title>Inicio</Title>
    <script src="../../javascript/funcionesComunes.js"></script>
    <script src="../../javascript/funcionesInicio.js"></script>
    <link rel="stylesheet" href="../../css/general.css">
    <link rel="stylesheet" href="../../css/inicio.css">
    <link rel="stylesheet" href="../../css/headerFooter.css">
    <link href="../../css/redimensionar.css" rel="stylesheet" type="text/css">
</head>
<body onload="getParams()">

	<%@ include file ="cabeceraView.jsp" %>
    
    <main>
        <section class="principal">
            <div class="contenedor">
                 <h2 class="eslogan">Encuentre a su empleado ideal</h2>
                 <h3 class="profesion">Elija la Profesión</h3>
                 <form method="get" action="../controller/personaController.jsp">
                     <div class="cards">
                            <div class="card">
                                <button name="cientificos" value="cientificos">
                                    <img src="../../imagenes/cientificos.jpg" alt="Cientificos" />
                                </button>
                                <h4>Cientificos</h4>
                            </div>
                            <div class="card">
                                <button name="IpD" value="IpD">
                                    <img src="../../imagenes/ID.jpg" alt="Profesionales I+D" />
                                </button>
                                <h4>Profesionales I+D</h4>
                            </div>
                    </div>
                </form>
            </div>
        </section>
        <section class="galeria">
            <div class="sesgoarriba"></div>
            <div class="imagenes"><img src="../../imagenes/fondo.jpg" alt=""></div>
            <div class="imagenes"><img src="../../imagenes/fondo.jpg" alt=""></div>
            <div class="imagenes"><img src="../../imagenes/fondo.jpg" alt="">
                <div class="encima">
                   <h2>CVJobs</h2>
                    <div></div>
                </div>
            </div>
            <div class="imagenes">
                <img src="../../imagenes/fondo.jpg" alt="">
            </div>
            <div class="imagenes"><img src="../../imagenes/fondo.jpg" alt=""></div>
            <div class="sesgoabajo-unico"></div>
        </section>
    </main>
	<%@ include file ="piePaginaView.jsp" %>
</body>
</html>