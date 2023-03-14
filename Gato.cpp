#include<stdio.h>
#include<windows.h>

#define p printf
#define s scanf

const int L=3;

void gtxy (int x,int y)
{
	HANDLE ii;
	ii=GetStdHandle(STD_OUTPUT_HANDLE);
	
	COORD jj;
	jj.X=x;
	jj.Y=y;
	
	SetConsoleCursorPosition(ii,jj);
}

void Portada() //Caratula
{
	system("color F4");
	
	gtxy(36,0);	printf("IPN");
	gtxy(27,2); printf("ESIME Unidad Culhuacan");
	gtxy(25,4);	printf("Ingenieria en Computacion");
	gtxy(24,6);	printf("Fundamentos de Programacion");
	gtxy(31,8);	printf("Grupo: 1CV25");
	gtxy(25,10); printf("Examen: El juego del gato");
	gtxy(0,18); printf("Nombre del Profesor: De La Cruz Perez Arturo");
	gtxy(0,20); printf("Nombre del ALumno: Medina Garcia Carlos Alejandro");
	Sleep(7000);
	system("cls");
}

void Instrucciones() //Reglas/condiciones
{
	system("color 2");
	
	gtxy(16,0);p("Instrucciones de como jugar al Gato");
	Sleep(3000);
	gtxy(5,4);p("1.- Debe de haber 2 jugadores");
	gtxy(5,6);p("2.- El jugador uno juega con 'X' y el jugador dos juega con 'O'");
	gtxy(5,8);p("3.- Se turnaran una casilla y una casilla");
	gtxy(5,10);p("4.- El quien tenga una casilla con sus respectivos caracteres alineados ya");
	gtxy(9,11);p("sea horizontal,vertical o diagonalmente gana el juego");
	gtxy(5,13);p("5.-Para elegir una casilla se tiene que introducir las coordenadas donde: ");
	gtxy(10,14);p("-el primer dato (del 0 al 2) indica el numero de fila");
	gtxy(10,15);p("-el segundo dato (del 0 al 2) indica el numero de columna");
	gtxy(0,19);system("pause");
	system("cls");
}

char RellenarGato(char G1[L][L]) //Rellena la matriz con "?"
{
	int i,j;
	char K;
	
	K='?';
	
	for(i=0;i<L;i++)
		for(j=0;j<L;j++)
		{
			G1[i][j]=K;
		}
}

void Imprime(char G2[L][L]) //Aparece la matriz
{
	int jj=0;
	system("color F2");
	int i,j;
	p(" 0   1   2\n____________\n");
	for(i=0;i<L;i++)
	{
		for(j=0;j<L;j++)
		{
				p(" %c |",G2[i][j]);	
		}
		p("  %i\n------------\n",jj++);
	}

}

char Jugador1(char G3[L][L]) //Turno del jugador 1
{
	int xf,xc,con;

	
		do
		{
			Imprime(G3);
			con=1;
			p("\n\tJugador 1 'X'\n\nInserte el numero de fila (del 0 al 2) = ");
			s("%i", &xf);
			p("\nInserte el numero de columna (del 0 al 2) = ");
			s("%i", &xc);
			
			if((xf<0||xf>2)||(xc<0||xc>2))
			{
				p("\n\t**Exedio el limite de la tabla,inserte otras coordenadas**\n\n\n");
				con=0;
				system("pause");
				system("cls");
			}
			
			if((G3[xf][xc]=='X')||(G3[xf][xc]=='O'))
			{
				p("\n\t**Posicion ocupada, inserte otras coordenadas **\n\n\n");
				con=0;
				system("pause");
				system("cls");
			}
			
		system("cls");
		}while(con==0);
			
		G3[xf][xc]='X';
		
	
}

char Jugador2(char G4[L][L]) //Turno del jugador 2
{
	int of,oc,con;
	
		do
		{
			Imprime(G4);
			con=1;
			p("\n\tJugador 2 'O'\n\nInserte el numero de fila (del 0 al 2) = ");
			s("%i", &of);
			p("\nInserte el numero de columna (del 0 al 2) = ");
			s("%i", &oc);
			
			if((of<0||of>2)||(oc<0||oc>2))
			{
				p("\n\t**Exedio el limite de la tabla,inserte coordenadas correctas**\n\n\n");
				con=0;
				system("pause");
				system("cls");
			}
			
			if((G4[of][oc]=='X')||(G4[of][oc]=='O'))
			{
				p("\n\t**Posicion ocupada, inserte coordenadas correctas**\n\n\n");
				con=0;
				system("pause");
				system("cls");
			}
		}while(con==0);
			
		G4[of][oc]='O';

	
}

int Fin(char G6[L][L]) // Decide al ganador
{
	int i,j,cont=0;
	
	if((G6[0][0]=='X')||(G6[0][0]=='O')) // casilla 1 horizontal
	{
		if((G6[0][0]==G6[0][1])&&(G6[0][0]==G6[0][2]))
		{
			if((G6[0][0]=='X'))
			
				return 1; //Jugador 1
				
			if((G6[0][0]=='O'))
		
				return 2; //Jugador 2
		}
	}
	
	if((G6[0][0]=='X')||(G6[0][0]=='O')) // casilla 1 vertical
	{
		if((G6[0][0]==G6[1][0])&&(G6[0][0]==G6[2][0]))
		{
			if((G6[0][0]=='X'))
			
				return 1; //Jugador 1
				
			if((G6[0][0]=='O'))
		
				return 2; //Jugador 2
		}
	}
	
	if((G6[1][1]=='X')||(G6[1][1]=='O')) //Diagonal superior izquierda
	{
		if((G6[1][1]==G6[0][0])&&(G6[1][1]==G6[2][2]))
		{
			if((G6[1][1]=='X'))
			
				return 1; //Jugador 1
				
			if((G6[1][1]=='O'))
		
				return 2; //Jugador 2
		}
	}
	
	if((G6[1][1]=='X')||(G6[1][1]=='O')) //Casilla 4 horizontal
	{
		if((G6[1][1]==G6[1][0])&&(G6[1][1]==G6[1][2]))
		{
			if((G6[1][1]=='X'))
			
				return 1; //Jugador 1
				
			if((G6[1][1]=='O'))
		
				return 2; //Jugador 2
		}
	}
	
	if((G6[1][1]=='X')||(G6[1][1]=='O')) //Diagonal superior derecha
	{
		if((G6[1][1]==G6[0][2])&&(G6[1][1]==G6[2][0]))
		{
			if((G6[1][1]=='X'))
			
				return 1; //Jugador 1
				
			if((G6[1][1]=='O'))
		
				return 2; //Jugador 2
		}
	}
	
	if((G6[1][1]=='X')||(G6[1][1]=='O')) //Casilla 2 vertical
	{
		if((G6[1][1]==G6[0][1])&&(G6[1][1]==G6[2][1]))
		{
			if((G6[1][1]=='X'))
			
				return 1; //Jugador 1
				
			if((G6[1][1]=='O'))
		
				return 2; //Jugador 2
		}
	}
	
	if((G6[2][2]=='X')||(G6[2][2]=='O')) //Casilla 9 horizontal
	{
		if((G6[2][2]==G6[2][0])&&(G6[2][2]==G6[2][1]))
		{
			if((G6[1][1]=='X'))
			
				return 1; //Jugador 1
				
			if((G6[1][1]=='O'))
		
				return 2; //Jugador 2
		}
	}
	
	if((G6[2][2]=='X')||(G6[2][2]=='O')) //Casilla 9 vertical
	{
		if((G6[2][2]==G6[0][2])&&(G6[2][2]==G6[1][2]))
		{
			if((G6[1][1]=='X'))
			
				return 1; //Jugador 1
				
			if((G6[1][1]=='O'))
		
				return 2; //Jugador 2
		}
	}
	
	for(i=0;i<L;i++)
		for(j=0;j<L;j++)
		{
			if((G6[i][j]=='X')||(G6[i][j]=='O'))
			{
				cont++;
			}
			
			if(cont==9)
			{
				return 3;
			}
		}
}

void Ganador (char G7[L][L]) //Selecciona al ganador
{
		if(Fin (G7) == 1)
		
			p("\n***Gana el jugador 1!!***");
			
		if	(Fin (G7) == 2)
		
			p("\n***Gana el jugador 2!!***");
			
		if	(Fin (G7) == 3)	
		
			p("\n***Es un empate!!***");
		
}

char Juego(char G5[L][L]) //Inicia el juego
{
	char De;
	int w;
	
	system("color 4");
	
	p("Iniciar el juego con portada e instruccones : 1\nIniciar el juego con instrucciones : 2\n\n");
	s("%i", &w);
		
	system("cls");
		
	if(w==1)
		{
		Portada();
		Instrucciones();
		}
			
	if(w==2)
		
		Instrucciones();
	
	do
	{	
		int i=1;
		
		RellenarGato(G5);
		do
		{
			if(i%2>0)
			{
			Jugador1(G5);
			system("cls");
			}
			else
			{
				Jugador2(G5);
				system("cls");
			}
			i++;
				
		}while((Fin(G5)<1)||(Fin(G5)>3));
		
		Ganador(G5);
		
		p("\n\nDesea volver a jugar?  S/N = ");
		s("%s",&De);
		
		system("cls");
		
	}while(De=='S'||De=='s');

}

main()
{
	char G[L][L];

	Juego(G);
}
