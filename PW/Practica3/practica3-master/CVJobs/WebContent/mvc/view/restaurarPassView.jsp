<%@page import="java.io.NotActiveException"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html lang="es">
<head>
<meta charset="ISO-8859-1" http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <script src="../../javascript/funcionesComunes.js"></script>
	<script src="../../javascript/validaciones.js"></script>
	<link href="../../css/inicioSesion.css" rel="stylesheet" type="text/css">
    <link href="../../css/redimensionar.css" rel="stylesheet" type="text/css">
  </head>
  <body>
	<div class="contenedor">
		<img src="../../imagenes/logo.png" width="100" height="100" alt="Logo">
		<div class="contenido">
			<form action="../controller/restaurarPassController.jsp" name="inicio" method="post" onsubmit="return validarCorreo() && validarContrasena();">
				<div id="accesoDatos">
					<label>Indica tu Correo</label>
					<br/>
					<input type="text" id="correoID" class="campoTexto" name="Correo" required>
					<br/>
					<label> Indica la Nueva contraseña</label>
					<br/>
					<input type="password" id="passID" name="Contrasena" class="campoTexto" required>
					<br/>
					<input type="submit" value="Aceptar"  name="Aceptar" class="button">
				</div>
			</form>
		</div>
	</div>
  </body>
</html>