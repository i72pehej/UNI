<%@page import="java.util.ArrayList"%>
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
	
	<jsp:useBean 
		id="daoPersona"
		class="es.uco.pw.data.dao.PersonaDao"
		scope="session"
	/>
	<% 
		String tipoCV="1";
		if(usuario.getCorreo()==null){
			tipoCV="1";
		}
		ArrayList<es.uco.pw.display.javabean.UsuarioBean> listar = daoPersona.listarPersonas(tipoCV);
		request.setAttribute("ArrayListID",listar);
	
	%>
	<jsp:forward page="../view/personaView.jsp"></jsp:forward>
	
	
</body>
</html>