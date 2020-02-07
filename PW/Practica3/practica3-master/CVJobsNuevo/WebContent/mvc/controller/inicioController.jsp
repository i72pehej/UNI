<%@page import="java.io.Console"%>
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
		if(usuario.getCorreo()!=null){
		String nombre= request.getParameter("nombreUsuario");
	%>
		<jsp:forward page="../view/inicioView.jsp?nombreUsuario=<%= nombre%>"></jsp:forward>	
	<%			
		}
	%>

</body>
</html>