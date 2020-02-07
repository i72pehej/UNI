<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1" http-equiv="Content-Type" content="text/html; charset=utf-8"/>
<script src="../../javascript/validaciones.js"></script>
		<link href="../../css/registro.css" rel="stylesheet" type="text/css">
        <link href="../../css/redimensionar.css" rel="stylesheet" type="text/css">
	</head>
	<body>	
		<div class="contenedor">
			<img src="../../imagenes/logo.png" width="100" height="100" alt="Logo">
			<div class="contenido">
			<!--Haciendo uso de Java, se comprobará que el usuario y la contraseña no se encuentran ya registrados-->
				<form action="../controller/registroController.jsp" name="inicio" method="post" onsubmit="return validarCorreo() && validarContrasena() && comprobarClave();">
					<label>Nombre</label>
					<br/>
					<input type="text" id="nombre" class="campoTexto" name="Nombre" value="" required>
					<br/>
					<label>Apellidos</label>
					<br/>
					<input type="text" id="apellidos" class="campoTexto" name="Apellidos" value="" required>
					<br/>
					<label>Correo</label>
					<br/>
					<input type="text" id="correoID" class="campoTexto" name="Correo" value="" required>
					
					<hr>
					
					<input type="radio" name="Escojer" value="0" onchange="activainput();">Empresa
					<input type="radio" name="Escojer" value="1" onchange="desactivainput(); " checked>Empleado
					<br><br>
					<input type="Text" name="SI" class="campoTexto" placeholder="Nombre de la Empresa" id="nombreEmpresa" disabled="disabled" onfocus="this.value=''">
					
					<hr>
					
					<label>Contraseña</label>
					<br/>
					<input type="password" id="passID" name="Contrasena" class="campoTexto" required>
					<br/>
					<label>Repita la Contraseña</label>
					<br/>
					<input type="password" id="passIDRep" class="campoTexto" required>
					<br/><br/>
                    <!--Cuando se pulse el botón de aceptar, se guarda la información del nuevo usuario haciendo uso de Java-->
					<input type="submit" value="Aceptar"  name="Aceptar" class="button">
					<hr>
					
				</form>				
			</div>
		</div>
	</body>
</html>
