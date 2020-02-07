<%@page import="java.util.ArrayList"%>
<%@page import="java.util.List"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html" charset="utf-8"/>
		<title>Mi Perfil</title>
        <script src="../../javascript/funcionesComunes.js"></script>
        <script src="../../javascript/funcionesPerfil.js"></script>
		<link href="../../css/general.css" rel="stylesheet" type="text/css">
		<link href="../../css/headerFooter.css" rel="stylesheet" type="text/css">
		<link href="../../css/miPerfil.css" rel="stylesheet" type="text/css">
        <link href="../../css/redimensionar.css" rel="stylesheet" type="text/css">
    </head>
	<body onload="getParams()">
        <header>
            <div class="textos">
                <div class="texto"><h1 class="titulo">CVJobs</h1></div>
                <div class="texto">
            </div>
            </div>
            <div class="sesgoabajo"></div>
        </header>
        <main>
        <!--Los datos del perfil del perfil de usuario se rellenará tras una consulta a la base de datos cuando se entra a la pagina-->
        <section class="principal">
            <div class="contenedor">
                <div class="cards">

                    <div class="card">
                        <div class="primero">
                            <form method="get" action="CV.html" style="float: left">
                                <input type="submit" value="verMiCV"  name="verMiCV" id="verMiCV" class="boton">
                            </form>
                            <form method="get" action="CV.html" style="float: left">
                                <input type="submit" value="verCV"  name="verCV" id="verCV" class="boton" style="display:none;">
                            </form>
                        </div>
                        <div class="primero">
                            <img src="../../imagenes/icon.png" />
                        </div>

						<br/><br/>
						<form action="../controller/perfilController.jsp" name="inicio" method="post">
							<label>Nombre:</label><br/>					
							<% String nombre = request.getParameter("nombre"); %>
							<input type="text" style='width:100%' id="nombreUsuario" name="nombreU" value="<%= nombre %>" disabled="disable"/>
							<br/><br/>
							<label for="nombreUsuario">Apellidos:</label><br/>
							<% String apellidos = request.getParameter("apellidos"); %>
							<input type="text" style='width:100%' id="apellidosUsuario" name="apellidosU" value="<%= apellidos %>" disabled="disable"/>
							<br/><br/>
							<label for="edadUsuario">Edad</label><br/>
							<% String edad = request.getParameter("edad"); %>
							<input type="text" style='width:100%' maxlength="9" id="edadUsuario" name="edadU"  value="<%=edad%>" disabled="disable"/>
	                        <br/><br/>
	                        <label for="experienciaUsuario">Experiencia</label><br/>
	                        <% String experiencia = request.getParameter("experiencia"); %>
							<input type="text" style='width:100%' maxlength="9" id="experienciaUsuario" name="experienciaU" value="<%=experiencia%>" disabled="disable"/>
	                        <br/><br/>
	                        <label for="profesion">Profesion o Actividad: </label><br/>
	                        <div id="profesionDIV">     	
	                        	<% String profesion = request.getParameter("prof"); %>
								<input type="text" style='width:100%' maxlength="9" id="profesionUsuario" name="profesionUsuario" value="<%=profesion%>" disabled="disable"/>                 
	                        	<% String rama = request.getParameter("ram"); %>
	                        	<input type="text" style='width:100%' maxlength="9" id="ramaUsuario" name="ramaUsuario" disabled="disable" value="<%=rama%>"/> 
	                        </div>
	                        <div id="profesionOption" style="display: none">
	                        	<select id="profesion" name="profesion" onclick="activarRama();" disabled="disable">
	                        	<option value="" selected disabled hidden>Selecciona Profesion</option>
	                            <option value="Profesional I+D">Profesional I+D</option>
	                            <option value="Cientifico">Cientifico</option>
	                        </select>
	                        <br/><br/>
	                        <select id="rama" name="rama" disabled>
	                            <option value="" selected disabled hidden>Selecciona Rama</option>
	                            <option value="Físico o Astrónomo">Físico o Astrónomo</option>
	                            <option value="Bioquímico o Biofísico">Bioquímico o Biofísico</option>
	                            <option value="Atmosférico">Atmosférico</option>
	                            <option value="Médico">Médico</option>
	                        </select>
	                        </div>
	                        
	                        <br/><br/>
	                        <label for="estadoLaboral">Estado Laboral</label><br/>
	                        <div id="elaboralDIV">
	                        	<% String estadoL = request.getParameter("el"); %>
	                        	<input type="text" style='width:100%' maxlength="9" id="elaboralUsuario" name="elaboralUsuario" value="<%=estadoL%>" disabled="disable"/>
	                        </div>
	                        <div id="elaboralOption" style="display: none">
		                        <select id="elaboral" name="elaboral" disabled="disable">
		                        	<option value="" selected disabled hidden>Selecciona Estado Laboral</option>
		                            <option value="Parado">Parado</option>
		                            <option value="Trabajando">Trabajando</option>
		                        </select>
	                        </div>
	                        
	                        <br/><br/>
	                        <label>Sobre Mí</label><br/>
	                        <% String descripcion = request.getParameter("descrp"); %>
	                        <textarea name="textareaResumen" class="resumen" id="resumen" rows="5" cols="50" disabled="disabled" style="color:#000;"><%=descripcion%></textarea>
	                        
	                            <!--Cuando el usuario edite su perfil, al pulsa en Guardar Cambios, dichos datos serán modificados en la base de datos mediante Java-->
	                        <input type="hidden" name="nombrevble" value="lo_que_sea" >
                            <input type="submit" id="guardar" value="Guardar Cambios" name="Guardar Cambios" class="boton" disabled="disable">
						</form>
						<input type="submit" value="editarPerfil" name="Editar Perfil" class="boton" onclick="habilitarCampo();">
							
                        <form method="get" action="CV.html">
                            <input type="submit" value="crearCV"  name="crearCV" class="boton">
                        </form>		
                    </div>
                    
                    <!--Los comentarios y puntuacion se guardaran en una base de datos con Java-->
                    <div class="card">
                        <form>
	                          <p class="clasificacion">
	                            <input id="radio1" type="radio" name="estrellas" value="5">
	                            <label class="puntua" for="radio1">*</label>
	                            <input id="radio2" type="radio" name="estrellas" value="4">
	                            <label class="puntua" for="radio2">*</label>
	                            <input id="radio3" type="radio" name="estrellas" value="3">
	                            <label class="puntua" for="radio3">*</label>
	                            <input id="radio4" type="radio" name="estrellas" value="2">
	                            <label class="puntua" for="radio4">*</label>
	                            <input id="radio5" type="radio" name="estrellas" value="1">
	                            <label class="puntua"for="radio5">*</label>
	                          </p>
	                          <div class="cajaComentarios">
	                          
	                          <%
	                          ArrayList <es.uco.pw.display.javabean.ComentarioBean> listar=(ArrayList)request.getAttribute("ArrayListID");
	                           //List<es.uco.pw.display.javabean.ComentarioBean> listar = (ArrayList<es.uco.pw.display.javabean.ComentarioBean>) request.getAttribute("comentarios");
								for(int i=0; i<listar.size(); i++){
									 System.out.println( listar.get(i).getPuntuacion());
							          System.out.println( listar.get(i).getComentario());  
							          out.println("Puntuacion: "+listar.get(i).getPuntuacion()+" ---> Comentario: "+listar.get(i).getComentario()+"</br>");
								}
	                       	%>           
	                          </div>
	                        
	                        <br/>
	                        <textarea class="comentarios" name="textareaComentarios" rows="0" cols="0" placeholder="Escribe tu comentario..." ></textarea>
	                        <br/>
	                        <input type="hidden" name="enviarComent" value="lo_que_sea" >
	                        <input type="submit" value="enviarComentario" name="Enviar" class="boton">
						</form>
                    </div>
                </div>
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
