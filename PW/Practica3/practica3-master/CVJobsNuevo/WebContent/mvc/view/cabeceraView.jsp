<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<script src="../../javascript/funcionesComunes.js"></script>
    <script src="../../javascript/funcionesInicio.js"></script>
    <link href="../../css/redimensionar.css" rel="stylesheet" type="text/css">
</head>
<body onload="getParams()">
	<header>
        <div class="textos">
            <div class="texto"><h1 class="titulo">CVJobs</h1></div>
            <div class="texto">
            <div id="conUsuario">
                <form method="post" action="../controller/perfilController.jsp">
                    <button class="boton" name="inicio" value="inicio">
                        <a href=""><img src="../../imagenes/icon.png" alt="perfil"/></a>
                    </button>
                </form>
                <% String nombre = request.getParameter("nombreUsuario"); %>
				<h3><%= nombre %></h3>
            </div>
            <div id="modoInvitado" style="display: none">
                <h3>Modo Invitado</h3>
            </div>
            
            </div>
        </div>
        <div class="sesgoabajo"></div>
    </header>
</body>
</html>