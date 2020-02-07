<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1" http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>Insert title here</title>
</head>
<body>
	<jsp:useBean 
		id="usuario" 
		class= "es.uco.pw.display.javabean.UsuarioBean"
		scope= "session"
	/>
	
	<%
		if(request.getParameter("Correo")==null){
	 %>
	  	<jsp:forward page="../view/iniciarSesionView.jsp"></jsp:forward>	
	<%		
		}
	%>
	
	<%
		String correo = request.getParameter("Correo");
		String pass = request.getParameter("Contrasena");
		
		usuario.setCorreo(correo);
		usuario.setPass(pass);
		
	%>

	<jsp:useBean 
		id="daoRL" 
		class = "es.uco.pw.data.dao.RegistroLoginDao"
		scope="session"
	/>
	
	<%
		String nombre = daoRL.Autenticacion(usuario);
		if(nombre!=null){
	%>
		<jsp:forward page="inicioController.jsp">
			<jsp:param name="nombreUsuario" value="<%=nombre%>"/>
		</jsp:forward>
		
	<%	
		}else{
	%>
			<script type="text/javascript" charset="UTF-8">
			if(confirm("El correo o la contraseña son incorrectos")){

				location.href='../view/iniciarSesionView.jsp';
			}
			
			</script>
		<%
		}
	%>

</body>
</html>