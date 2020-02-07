<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
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