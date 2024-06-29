int t = 100;
int t2 = 5;
//Se invirtieron los pines 9-10, 5-6, y 1-2
int profundidad[] = {13,12,11,9,10,8,7,5,6,4,3,1,2,0, A0, A1};
int altura[] = {A2,A3,A4,A5};

void setup(){
  for(int i=0; i<=15; i++){
  	pinMode(profundidad[i],OUTPUT); //terminales 4 a 11 como Salida
  }
  for(int i=0; i<=3; i++){
    pinMode(altura[i],OUTPUT); 
  }
  
}

void loop(){
  //Altura y profundidad
  //led(0,12);
  serieLuces();
  lineaAleatoria();
  adentroAfuera();
}

//Primera animación
void serieLuces(){
  int cont = 0;
  int aumento = 4;
  bool bandera = true;
  for(int i = 0; i <= 4; i++){
  	cont = 0;
    bandera = true;
    for(int j = 0; j <= 16; j++){
    	
     	if(cont == 16 || cont == -3 || cont == 18){
			cont += bandera ? -3 : 5 ;
          	bandera = !bandera;
      	}else
          if(cont == -1){
          	break;
        }
      	led(i,cont, 1);
      	aumento = bandera ? 4 : -4;
      	cont += aumento ;
    }   
  }
}

//Segunda animación
void lineaAleatoria(){
  for(int i = 0; i<=15; i++){
  	int c = random(0,3+1);
  	int r = random(0,3+1);
  	for(int j = 0; j<= 50; j++){
    	led(c,r+0,2);
  		led(c,r+4,2);
  		led(c,r+8,2);
  		led(c,r+12,2);
    }
  }
  	
}

//Tercera animación
void adentroAfuera(){
  for(int i=0; i<=3; i++){
  	for(int j = 0; j<= 50; j++){
    	led(i,5,2);
  		led(i,6,2);
  		led(i,9,2);
  		led(i,10,2);
    }
  }
  for(int i=3; i>=0; i--){
  	for(int j = 0; j<= 50; j++){
    	led(i,0,2);
  		led(i,1,2);
  		led(i,2,2);
  		led(i,3,2);
      	led(i,4,2);
      	led(i,7,2);
      	led(i,8,2);
      	led(i,11,2);
      	led(i,12,2);
      	led(i,13,2);
      	led(i,14,2);
      	led(i,15,2);
    }
  }
}


//prender led en altura,profundidad
void led(int r, int c, int opc){
  digitalWrite(profundidad[c],HIGH);  
  digitalWrite(altura[r],HIGH);
  opc == 1 ? delay(t) : delay(t2);
  apagar();
}

void apagar(){
  for(int i=0; i<=15; i++){
    digitalWrite(profundidad[i],LOW); //terminales 4 a 11 como Salida
  }
  for(int i=0; i<=3; i++){
    analogWrite(altura[i],0);
  }
}