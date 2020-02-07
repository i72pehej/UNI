<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Insert title here</title>
</head>
<body>

	<jsp:useBean 
		id="usuario" 
		class= "es.uco.pw.display.javabean.UsuarioBean"
		scope= "session"
	/>
	
	<%
		if(request.getParameter("Nombre")==null){
	 %>
	  	<jsp:forward page="../view/registroView.jsp"></jsp:forward>	
	<%		
		}
	%>

	<%
		String nombre = request.getParameter("Nombre");
		String apellidos = request.getParameter("Apellidos");
		int tipoUsuario = Integer.parseInt(request.getParameter("Escojer"));
		String nombreEmpresa = request.getParameter("SI");
		String correo = request.getParameter("Correo");
		String pass = request.getParameter("Contrasena");
		
		usuario.setNombre(nombre);
		usuario.setApellidos(apellidos);
		usuario.setTipoUsuario(tipoUsuario);
		usuario.setNombreEmpresa(nombreEmpresa);
		usuario.setCorreo(correo);
		usuario.setPass(pass);
	%>
	
	<jsp:useBean 
		id="daoRL" 
		class = "es.uco.pw.data.dao.RegistroLoginDao"
		scope="session"
	/>
	
	<%
	if(daoRL.comprobarExistencia(correo)==false) {
		if(daoRL.Registro(usuario)) {
			%>
			<jsp:forward page="inicioController.jsp">
				<jsp:param name="nombreUsuario" value="<%=nombre%>"/>
			</jsp:forward>
			
		<%	
		}
	}else{
		%>
		<script type="text/javascript" charset="UTF-8">
		if(confirm("Correo ya en uso")){

			location.href='../view/registroView.jsp';
		}
		
		</script>
	<%
	}
	
	%>
	
</body>
</html>