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