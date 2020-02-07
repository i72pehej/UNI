<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html" charset="utf-8"/>
<title>Curriculum Vitae</title>
        <script src="../../javascript/funcionesComunes.js"></script>
		<script src="../../javascript/validaciones.js"></script>
		<script src="../../javascript/funcionesCV.js"></script>
		<link href="../../css/general.css" rel="stylesheet" type="text/css">
		<link href="../../css/headerFooter.css" rel="stylesheet" type="text/css">
		<link href="../../css/CV.css" rel="stylesheet" type="text/css">
        <link href="../../css/redimensionar.css" rel="stylesheet" type="text/css">
	</head>
	<body onload="getParams()">
   <%@ include file ="cabeceraView.jsp" %>
    <main>
    
        <section class="principal">

            <div class="contenedor">
            <form id="guardar" name="inicio" onsubmit="return validarCorreo();">
                <div class="cards">
                    <div class="card">
                        <input type="file" id="fotoPerfil" onchange="document.getElementById('perfilImg').src = window.URL.createObjectURL(this.files[0])">
                        <img id="perfilImg" src="../../imagenes/icon.png" width="100" height="100" />
                        <br/><br/>
                        <label id="tipoCV" for="tipoCV">Tipo de CV</label>
                        <select id="tipo" name="tipo">
                            <option value="1">Publico</option>
                            <option value="2">Privado</option>
                            <option value="3">Protegido</option>
                        </select>
                        <br/><br/>
                        <fieldset id="datosPersonales">
                            <legend>Datos Personales</legend>
                            <label for="fechaNacimiento">Fecha de Nacimiento</label><br/>

                            <input type="date" id="fechaNacimiento" name="fechaNacimiento">
                            <br/><br/>
                            <label for="nacionalidad">Nacionalidad</label><br/>
                            <input type="text" style='width:100%' maxlength="9" id="nacionalidad" name="nacionalidad" required />
                            <br/>
                            <label for="nacionalidad">Domicilio</label><br/>
                            <input type="text" style='width:100%' maxlength="9" id="domicilio" name="domicilio" required />
                        </fieldset>
                        <fieldset id="contacto">
                            <legend>Contacto</legend>
                            <img src="../../imagenes/phone.png" class="iconos"/>
                            <input type="text" style='width:80%'  maxlength="9" id="telefono" name="telefono" placeholder="Introduzca su Telefono" onfocus="this.value=''" required />
                            <br/>
                            <img src="../../imagenes/email.png" class="iconos"/>
                            <input type="text" style='width:80%' id="correo" name="correo" placeholder="Introduzca su Correo" onfocus="this.value=''" required />
                        </fieldset>

                        <fieldset id="intereses">
                                <legend>Intereses y Líneas de trabajo</legend><br/>
                                <textarea name="textareaIntereses" id="LineaTrabajo" rows="10" cols="40"></textarea>
                            </fieldset>
                        </div>
                    <div class="card">
                        <fieldset id="datosProfesionales">
                            <input type="text"  style='width:100%' id="nombrePersona" name="nombre" placeholder="Nombre Completo" onfocus="this.value=''" required />
                            <br/>
                            <label for="profesion">Profesión o Actividad: </label>
                            <select id="profesion" name="profesion" onclick="activarRama();">
                                <option value="1">Profesional I+D</option>
                                <option value="2">Cientifico</option>
                            </select>
                            <select id="rama" name="rama" disabled>
                                <option selected="true" disabled="disabled">Seleccione la Rama</option>
                                <option value="2">Físico</option>
                                <option value="3">Astrónomo</option>
                                <option value="4">Bioquímico</option>
                                <option value="5">Biofísico</option>
                                <option value="6">Atmosférico</option>
                                <option value="7">Médico</option>
                            </select>
                        </fieldset>
                        <fieldset id="educacion">
							<legend>Educación
                            <input type="Button" value="+" class="boton" style="width:20%" onclick="agregarEducacion()"/>
                            </legend>
							<input type="text" style='width:100%' id="titulo" name="edu" placeholder="Titulo" onfocus="this.value=''" /><br/>
							<input type="text" style='width:100%' id="escuela" name="edu" placeholder="Escuela, Instituto, Universidad" onfocus="this.value=''" />
							<input type="text" size="4" id="desde" name="edu" placeholder="Desde" onfocus="this.value=''" />
							-
							<input type="text" size="4" id="hasta" name="edu" placeholder="Hasta" onfocus="this.value=''" />
						</fieldset>
						<fieldset id="experienciaLaboral">
							<legend>Experiencia Laboral</legend>
							<input type="text" style='width:100%' id="puesto" name="puesto" placeholder="Puesto" onfocus="this.value=''" /><br/>
							<input type="text" size="4" id="desde" name="desde" placeholder="Desde" onfocus="this.value=''" />
							-
							<input type="text" size="4" id="hasta" name="hasta" placeholder="Hasta" onfocus="this.value=''" />
						</fieldset>
						<fieldset id="idiomas">
							<legend>Idiomas</legend>
							<input type="text" style='width:60%' id="idioma" name="idioma" placeholder="Idioma" onfocus="this.value=''" />
							<select id="nivelIdioma" name="nivelIdioma">
								<option value="1">B1</option>
								<option value="2">B2</option>
								<option value="3">C1</option>
								<option value="4">C2</option>
							</select>
						</fieldset>
                        <fieldset id="articulos">
                            <legend>Articulos y Comentarios</legend><br/>
                            <textarea name="textareaArticulos" id="ArticulosComentarios" rows="10" cols="40"></textarea>
                        </fieldset>
                    </div>

                </div>
            </div>
        </section>

        <section class="principal">
            <div class="contenedor">
                <div class="cards">
                    <div class="card">
                        <fieldset id="proyectos">
                            <legend>Proyectos De Investigación</legend>
                            <input type="text" style='width:100%' id="tituloProyecto" name="tituloProyecto" placeholder="Titulo del Proyecto" onfocus="this.value=''"/><br/>
                            <textarea name="textareaDescripcionProyecto" rows="5" cols="20"  onfocus="this.value=''" placeholder="Descripción del Proyecto"></textarea><br/>
                            <input type="text" style='width:100%' id="rolProyecto" name="rolProyecto" placeholder="Rol en el Proyecto" onfocus="this.value=''" /><br/>
                            <input type="text" style='width:100%' id="cuantia" name="cuantia" placeholder="Cuantía" onfocus="this.value=''" /><br/>
                            <input type="text" size="4" id="desde" name="desde" placeholder="Desde" onfocus="this.value=''" />
                            -
                            <input type="text" size="4" id="hasta" name="hasta" placeholder="Hasta" onfocus="this.value=''" />
                            <br/>
                            <input type="text" style='width:100%' id="InvestigadorResponsable" name="InvestigadorResponsable" placeholder="Investigador Responsable"  onfocus="this.value=''" /><br/>
                        </fieldset>
                        <fieldset id="eventos">
                            <legend>Organización de Eventos</legend>
                                <select id="tipoEvento" name="tipoEvento">
                                <option value="1">Conferencia</option>
                                <option value="2">Jornada</option>
                                <option value="3">Reunión</option>
                            </select>
                            <input type="text" style='width:100%' id="tituloEvento" name="tituloEvento" placeholder="Titulo del Evento" onfocus="this.value=''" /><br/>
                            <input type="text" style='width:100%' id="organizacion" name="organizacion" placeholder="Organizacion" onfocus="this.value=''" /><br/>
                            <input type="text" style='width:100%' id="sponsors" name="sponsors" placeholder="Sponsors" onfocus="this.value=''" /><br/>
                            <input type="date" id="fechaNacimiento" name="fechaNacimiento">
                            <br/><br/>
                           <input type="text" style='width:100%' id="rolEvento" name="rolEvento" placeholder="Rol en la Organizacion" onfocus="this.value=''" /><br/>
                        </fieldset>

                    </div>

                    <div class="card">
                        <fieldset id="tesisDoctorales">
                            <legend>Tesos Doctorales</legend>
                            <input type="text" style='width:100%' id="tituloTesis" name="tituloTesis" placeholder="Titulo de la Tesis" onfocus="this.value=''"/><br/>
                            <textarea name="textareaDescripcionTesis" rows="5" cols="20"  onfocus="this.value=''" placeholder="Descripción de la Tesis"></textarea><br/>
                            <input type="text" style='width:100%' id="doctorado" name="doctorado" placeholder="Doctorado" onfocus="this.value=''" /><br/>
                            <input type="text" size="4" id="desde" name="desde" placeholder="Desde" onfocus="this.value=''" />
                            -
                            <input type="text" size="4" id="hasta" name="hasta" placeholder="Hasta" onfocus="this.value=''" /><br/>
                            <textarea name="meritosDerivados" rows="5" cols="20"  onfocus="this.value=''" placeholder="Meritos Derivados"></textarea><br/>
                        </fieldset>
                        <fieldset id="produccionCientifica">
                        <legend>Producción Científica</legend>
                            <textarea name="textareaPublicaciones" rows="5" cols="20"  onfocus="this.value=''" placeholder="Publicaciones"></textarea><br/>
                            <input type="text" style='width:100%' id="portfolio" name="portfolio" placeholder="portfolio" onfocus="this.value=''" /><br/>
                        </fieldset>

                    </div>
                </div>
                <!--Cuando el usuario haya rellenado los datos de su CV, al pulsar guardar estos datos se guardaran en una base de datos, haciendo uso de Java-->
                <div class="cards" id="guardarCV">
                    <div class="botonAceptar">
                        <input type="submit" value="aceptar" name="Guardar" class="boton"><br>
                    </div>
                </div>
            </form>
            <!--El usuario podrá editar su CV-->
            <div class="cards" id="editarCV" style="display:none;">
                <div class="botonEditar">
                    <input type="submit" value="Editar CV"  name="editarCV" class="boton" onclick="habilitarCampos();">
                    <input type="submit" value="Guardar Cambios" name="Guardar Cambios" class="boton" onclick="deshabilitarCampos();">
                </div>
            </div>
            </div>
        </section>
        
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