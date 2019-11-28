package ejbd;

public class ejbd {

	public static void main(String[] args) {
		System.out.println("Se consulta el usuario 1");
		java.util.Hashtable<String,String> resul = UserDAO.queryById(1);
		if (resul==null)
			System.out.println("Se consulta el usuario 1 = NULO");
		else 
			System.out.println("El usuario " + resul.get("id") + " se llama " + 
					resul.get("first") + " " + resul.get("last") + " y tiene " + resul.get("age"));
	}

}
