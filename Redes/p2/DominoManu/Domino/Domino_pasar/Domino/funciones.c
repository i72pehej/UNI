bool ingresaUsuario(char * cadena, struct clients * cliente)
	{
	char * usuario, contra;
	strtok(buffer," ");
	strtok(NULL," ");
	usuario=strtok(NULL," ");
	strcpy(cliente->user,usuario);
	strtok(NULL, " ");
	contra=strtok(NULL,"\n");
	strcpy(cliente->pass,contra);
	archivo=fopen("base.txt", "a");
	sprintf(linea2, "%s %s\n", usuario, contra);
	fputs(linea2, archivo);
	fclose(archivo);
	printf("\nCLIENTE REGISTRADO CON EXITO\n");
	return TRUE;
	}


