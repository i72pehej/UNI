<%@page import="java.util.Hashtable"%>
<%@page import="java.util.ArrayList"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html" charset="utf-8"/>
<title>Insert title here</title>
</head>
<body>


	<jsp:useBean 
		id="usuario" 
		class= "es.uco.pw.display.javabean.UsuarioBean"
		scope= "session"
	/>
	
	<jsp:useBean 
		id="daoPerfil"
		class="es.uco.pw.data.dao.PerfilDao"
		scope="session"
	/>
	
	<jsp:useBean 
		id="coment"
		class= "es.uco.pw.display.javabean.ComentarioBean"
		scope="session"
	/>
	
	
	<%
		if(usuario.getCorreo()!=null){
			Hashtable<String,String> listado = daoPerfil.listarPersona(usuario.getCorreo());
			String nombre= listado.get("nombre");
			String apellidos= listado.get("apellidos");
			String edad = listado.get("edad");
			String experiencia = listado.get("experiencia_laboral") ;
			String profesion = listado.get("profesion");
			String rama = listado.get("rama");
			String elaboral = listado.get("situacion_laboral");
			String descripcion =listado.get("descripcion");
			
			if (request.getParameter("nombrevble") != null){
				nombre = request.getParameter("nombreU");
				apellidos = request.getParameter("apellidosU");;
				edad= request.getParameter("edadU");
				experiencia = request.getParameter("experienciaU");
				if(request.getParameter("profesion")!=null){
					profesion = request.getParameter("profesion");	
				}
				if(request.getParameter("rama")!=null){
					rama = request.getParameter("rama");
				}
				if(request.getParameter("elaboral")!=null){
					elaboral = request.getParameter("elaboral");
				}
				descripcion = request.getParameter("textareaResumen");	
				
				usuario.setNombre(nombre);
				usuario.setApellidos(apellidos);
				usuario.setEdad(edad);
				usuario.setExperienciaLaboral(experiencia);
				usuario.setProfesion(profesion);
				usuario.setRama(rama);
				usuario.setSituacionLaboral(elaboral);
				usuario.setDescripcion(descripcion);
				
				daoPerfil.modificarPerfil(usuario);
			}
			
			if (request.getParameter("enviarComent") != null){
				String puntuacion = request.getParameter("estrellas");
				String comentario = request.getParameter("textareaComentarios");
				coment.setPuntuacion(puntuacion);
				coment.setComentario(comentario);
				coment.setCorreoUsuario(usuario.getCorreo());
				
				daoPerfil.insertarComentario(coment);
				
				
			}
			ArrayList<es.uco.pw.display.javabean.ComentarioBean> listar = daoPerfil.listarComentariosUsuario(usuario.getCorreo());
			request.setAttribute("ArrayListID",listar);
	%>
	
			<jsp:forward page="../view/perfilView.jsp">
				<jsp:param name="nombre" value="<%=nombre%>"/>
				<jsp:param name="apellidos" value="<%=apellidos%>"/>
				<jsp:param name="edad" value="<%=edad%>"/>
				<jsp:param name="experiencia" value="<%=experiencia%>"/>
				<jsp:param name="prof" value="<%=profesion%>"/>
				<jsp:param name="ram" value="<%=rama%>"/>
				<jsp:param name="el" value="<%=elaboral%>"/>
				<jsp:param name="descrp" value="<%=descripcion%>"/>
			</jsp:forward>
	
	<%
			
		}
	%>

		

</body>
</html>