<%@page import="java.util.ArrayList"%>
<%@page import="java.util.List"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html" charset="utf-8"/>
 <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <Title>Listado de Profesionales</Title>
    <script src="../../javascript/funcionesComunes.js"></script>
    <script src="../../javascript/funcionesPersona.js"></script>
    <link rel="stylesheet" href="../../css/general.css">
    <link rel="stylesheet" href="../../css/persona.css">
    <link rel="stylesheet" href="../../css/headerFooter.css">
    <link href="../../css/redimensionar.css" rel="stylesheet" type="text/css">
	<style>
        #tablaPersonas tr.noSearch {background:White;font-size:0.8em;}
        #tablaPersonas tr.noSearch td {padding-top:10px;text-align:right;}
		.hide{display:none;}
		.red{color:red;}
	</style>
  </head>
  <body onload="getParams()">
  <%@ include file ="cabeceraView.jsp" %>
  <main>

    <section class="principal">
      <div class="contenedor">
        <h2 class="eslogan">Listado de Profesionales</h2>
        <div class="cards">
          <div class="cardPrincipal">
            <label>Ordenar Por</label>
            <br/>
            <select onclick="ordenar(2)" id="ordenar">
              <option selected="true" disabled="disabled">Selecciona</option>
              <option value="asc"> Experiencia (ASC)</option>

              <option value="des" > Experiencia (DSC)</option>
            </select>
          <br><br>
            <label>Situacion laboral</label>
            </br>
            <select onclick="situacionLaboral(3)" id="situacionLaboral">
              <option selected="true" disabled="disabled">Selecciona</option>
              <option value="parado"> Parado</option>
              <option value="trabajando"> Trabajando</option>
            </select>
          </div>
          <div class="cardPrincipal">
				<form>
					<input type="text" class="campoTexto" id="buscardor" placeholder="Buscar por nombre" onkeyup="buscar()">
				</form>
			<br/>
          <div id="ramaDiv">
              </br><label>Seleccionar rama</label>
              <br/>
              <select onclick="rama(1)" id="rama">
                <option selected="true" disabled="disabled">Selecciona</option>
                <option value="fisico y astronomo"> Físicos y astrónomos</option>
                <option value="bioquimico y biofisico"> Bioquímicos y biofísicos</option>
                <option value="atmosferico"> Atmosféricos</option>
                <option value="medico"> Médicos</option>
              </select>
          </div>
        </div>
      </div>
    </div>
  </section>

  <section class="principal">
    <div class="contenedor">
      <div class="cards">
        <div class="card">
          <!--La tabla se rellenará tras realizar una consulta a la base de datos haciendo uso de Java-->
          <table id="tablaPersonas" border="1" summary="Profesionales">
          	<%
	        ArrayList <es.uco.pw.display.javabean.UsuarioBean> listar=(ArrayList)request.getAttribute("ArrayListID");
	        %>  
            <tr>
              <th scope="col"><h1>Nombre</h1></th>
              <th scope="col"><h1>Profesion</h1></th>
              <th scope="col"><h1>Experiencia</h1></th>
			  <th scope="col"><h1>Situación Laboral</h1></th>
              <th scope="col"></th>
            </tr>
            
            <%
            	for(int i=0; i<listar.size(); i++){
            %>
	           <tr>
	           	<td><%=listar.get(i).getNombre() %></td>
	           	<td><%=listar.get(i).getRama() %></td>
	           	<td><%=listar.get(i).getExperienciaLaboral() %></td>
	           	<td><%=listar.get(i).getSituacionLaboral() %></td>
	           	<td>
                <form method="post" action="../controller/personaController.jsp?correo=<%= listar.get(i).getCorreo() %>&verPerfil=verPerfil">
                    <input type="submit" value="verPerfil"  name="verPerfil" class="boton">
                </form>
              </td>
	           </tr>
            
            <%} %>
			<tr class='noSearch hide'>
                <td colspan="5"></td>
            </tr>
          </table>
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