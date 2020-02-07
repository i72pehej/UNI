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
		String nombre= request.getParameter("nombreUsuario");
		System.out.println("PERSONA CONTrOLLER "+nombre);
	
		if(request.getParameter("verPerfil")!=null){
			String correo = request.getParameter("correo");
	%>
		<jsp:forward page="../controller/perfilController.jsp">
			<jsp:param name="correo" value="<%=correo%>"/>
		</jsp:forward>
	
	<%		
		}
	
		String cienf = request.getParameter("cientificos");
		String IpD = request.getParameter("IpD");
		String opcion = null;
		String tipoCV1="1";
		String tipoCV2=null;
		if(usuario.getCorreo()==null){
			tipoCV1="1";
		}else if(usuario.getCorreo()!=null){
			tipoCV1="1";
			tipoCV2="2";
		}
		
		if(cienf!=null){
			opcion = "Cientifico";
		
		}else if(IpD!=null){
			opcion = "Profesional I+D";
		}
		System.out.println(opcion);
		ArrayList<es.uco.pw.display.javabean.UsuarioBean> listar = daoPersona.listarPersonas(tipoCV1, tipoCV2, opcion);
		request.setAttribute("ArrayListID",listar);
	
	%>
		<jsp:forward page="../view/personaView.jsp">
			<jsp:param name="nombreUsuario" value="<%=nombre%>"/>
		</jsp:forward>
	
	
</body>
</html>