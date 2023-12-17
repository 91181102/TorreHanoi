// Biblioteca design versao 3.3 atualizado em 2015.11.1

///
/// constantes para teclas
///
int PGDN = 81;
int PGUP = 73;
int ARROW_LEFT = 75;
int ARROW_RIGHT = 77;
int ARROW_UP = 72;
int ARROW_DOWN = 80;
int ESC = 27;
int RETURN = 13;
int SPACE = 32;
int SIM = 49;
int NAO = 48;
int BACK_SPACE = 8;
int F1 = 59;
int F2 = 60;
int F3 = 61;
///
/// estrutura da lista da comboBox
///
typedef struct combo{
	int cod;
	char nome[30];
}LISTA;

///
void gotoxy(int linha, int coluna){
	// posiciona o cursor nas coordenadas X e Y
	COORD point;
	point.X = coluna;
	point.Y = linha;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

void string$(int quant, char caractere){
	// printa na tela uma quantidade "n" do mesmo caractere
	int i;
	for (i=1;i<quant;i++)
	printf("%c", caractere);
}

void cor(int fonte, int fundo){
	textbackground(fundo);	// cor do fundo
	textcolor (fonte); // cor da fonte
	
	// 0 = preto		8 = cinza escuro
	// 1 = azul			9 = azul claro
	// 2 = verde		10 = verde claro (A)
	// 3 = verde agua	11 = verde agua claro (B)
	// 4 = vermelho		12 = vermelho claro (C)
	// 5 = roxo			13 = lilás (D)
	// 6 = amarelo		14 = amarelo claro (E)
	// 7 = cinza claro	15 = branco (F)
}

void border(int posX, int posY, int larg, int alt){
    int i, j;
    	
    gotoxy(posX, posY);
	putchar(218);
	string$(larg-1, 196);
	putchar(191);
    gotoxy(posX + 1, posY);

	for (i=2; i<alt; i++) {
        gotoxy(posX + (i - 1), posY);
		putchar(179);
		string$(larg-1, ' ');
		gotoxy(posX + (i - 1), posY + (larg - 1));
        putchar(179); printf("\n");
	}
	gotoxy(posX + (i - 1), posY);
	putchar(192);
	for (j=1; j<=larg-2; j++)
		putchar(196);
		putchar(217);
		printf("\n");
}

void borders(int posX, int posY, int larg, int alt, int fonte, int fundo){
    int i, j;
	    
    cor(15,0);
	
	for (i=1; i<alt+1; i++) {
        gotoxy(posX + i, posY +1);		
		string$(larg+1, ' ');printf("\n");
	}
	
	cor(fonte, fundo);
	
    gotoxy(posX, posY);
	putchar(218);
	string$(larg-1, 196);

	putchar(191);
    gotoxy(posX + 1, posY);

	for (i=2; i<alt; i++) {
        gotoxy(posX + (i - 1), posY);
		putchar(179);
		string$(larg-1, ' ');
		gotoxy(posX + (i - 1), posY + (larg - 1));
        putchar(179); printf("\n");
	}
	gotoxy(posX + (i - 1), posY);
	putchar(192);
	for (j=1; j<=larg-2; j++)
		putchar(196);
	putchar(217);
	printf("\n");
}

void borderd(int posX, int posY, int larg, int alt){
    int i, j;
    
    for (i=1; i<alt; i++){
		gotoxy(posX + i, posY);
		string$(larg, 32);		
	}
    gotoxy(posX, posY);
	putchar(201);
	for (j=1; j<=larg-2; j++)
		putchar(205);
	putchar(187);
    gotoxy(posX + 1, posY);

	for (i=2; i<alt; i++) {
        gotoxy(posX + (i - 1), posY);
		putchar(186);
        gotoxy(posX + (i - 1), posY + (larg - 1));
        putchar(186); printf("\n");
	}
	gotoxy(posX + (i - 1), posY);
	putchar(200);
	for (j=1; j<=larg-2; j++)
		putchar(205);
		putchar(188);
		printf("\n");
}

void borderdt(int posX, int posY, int larg, int alt){
    int i, j;
    
	for (i=1; i<alt; i++){
		gotoxy(posX + i, posY);
		string$(larg, 32);		
	}
    	
    gotoxy(posX, posY);
	putchar(201);
	string$(larg-1, 205);

	putchar(187);
    gotoxy(posX + 1, posY);putchar(186);
    gotoxy(posX + 1, posY + (larg - 1)); putchar(186);

    gotoxy(posX + 2, posY);putchar(204);
    gotoxy(posX + 2, posY + 1);
    string$(larg-1, 205);

    gotoxy(posX + 2, posY + (larg-1));putchar(185);

	for (i=4; i<alt; i++) {
        gotoxy(posX + (i - 1), posY);
		putchar(186);
        gotoxy(posX + (i - 1), posY + (larg - 1));
        putchar(186); printf("\n");
	}
	gotoxy(posX + (i - 1), posY);
	putchar(200);
	 string$(larg-1, 205);

		putchar(188);
		printf("\n");
}


void tabledt(int posX, int posY, int larg, int alt){
    int i, j;
    
	for (i=1; i<alt; i++){
		gotoxy(posX + i, posY);
		string$(larg, 32);		
	}
    	
    gotoxy(posX, posY);
	putchar(203);
	string$(larg-1, 205);

	putchar(187);
    gotoxy(posX + 1, posY);putchar(186);
    gotoxy(posX + 1, posY + (larg - 1)); putchar(186);

    gotoxy(posX + 2, posY);putchar(206);
    gotoxy(posX + 2, posY + 1);
    string$(larg-1, 205);

    gotoxy(posX + 2, posY + (larg-1));putchar(185);

	for (i=4; i<alt; i++) {
        gotoxy(posX + (i - 1), posY);
		putchar(186);
        gotoxy(posX + (i - 1), posY + (larg - 1));
        putchar(186); printf("\n");
	}
	gotoxy(posX + (i - 1), posY);
	putchar(202);
	 string$(larg-1, 205);

		putchar(188);
		printf("\n");
}

void mensageBox(char texto[50]){ // exibe uma mensagem no centro da tela

	int x = (24/2);
	int y = (80/2) - strlen(texto)/2;
	
	struct char_info *screen_buffer;
	screen_buffer = malloc(y * x * sizeof(struct char_info));
	_conio_gettext(y, x, y + (strlen(texto) + 3) , x + 5, screen_buffer); // Copia a parte da tela


	borders(x,y,(strlen(texto)+2), 4, 14, 4);
	gotoxy(x + 1,y + 1); printf("%s", texto); 
	gotoxy(x + 2,y + 1); printf("Tecle algo."); getch();
		
	puttext(y, x, y + (strlen(texto) + 3) , x + 5 , screen_buffer);
	normvideo();
	free(screen_buffer);
}

int inputBox(char texto[50], char op1[10], char op2[10]){ // exibe uma mensagem no centro da tela
	int x = (24/2), opcao;
	int y = (80/2) - strlen(texto)/2;
	
	struct char_info *screen_buffer;
	screen_buffer = malloc(y * x * sizeof(struct char_info));
	_conio_gettext(y, x, y + (strlen(texto) + 3) , x + 5, screen_buffer); // Copia a parte da tela
	
	borders(x,y,(strlen(texto)+2),4,14,4);
	gotoxy(x + 1,y + 1); printf("%s", texto); 
	gotoxy(x + 2,y + 1); printf("%s  %s", op1, op2); scanf("%d", &opcao);	
	
	puttext(y, x, y + (strlen(texto) + 3) , x + 5 , screen_buffer);
	normvideo();
	free(screen_buffer);
	
	return opcao;
}

int inputBoxYN(char texto[50]){ // exibe uma mensagem no centro da tela
	int x = (24/2), opcao;
	int y = (80/2) - strlen(texto)/2;
	
	struct char_info *screen_buffer;
	screen_buffer = malloc(y * x * sizeof(struct char_info));
	_conio_gettext(y, x, y + (strlen(texto) + 3) , x + 5, screen_buffer); // Copia a parte da tela
	
	borders(x,y,(strlen(texto)+2),4,14,4);
	gotoxy(x + 1,y + 1); printf("%s", texto); 
	gotoxy(x + 2,y + 1); printf("[1]-SIM [0]-NAO"); 
	do{
		opcao = tecla();		
	}while(opcao <NAO || opcao >SIM);
	
	
	puttext(y, x, y + (strlen(texto) + 3) , x + 5 , screen_buffer);
	normvideo();
	free(screen_buffer);
	
	return opcao;
}


void printcenter(char texto[70], int linha){
	// centraliza um texto na tela
	int y = (80/2) - strlen(texto)/2;
	gotoxy(linha,y); printf("%s", texto); 	
}

int tecla(){
	int op, sair = 0;
	do{// verifica qual tecla foi apertada
		fflush(stdin); // apaga buffer do teclado
		if (kbhit()){ // executa quando uma tecla é apertada
			op = getch(); // guarda o valor da tecla apertada
			sair = 1; // sai da estrutura
		}
	} while(sair == 0); // executa enquanto saida = 0
	return op; // retorna a tecla pressionada
	// 80 = seta para baixo			59 = F1 60=F2 61=F3 62=F4 63=F5
	// 72 = seta para cima			123 = F12
	// 75 = seta para esquerda		8 = BACKSPACE
	// 77 = seta para direita		9 = TAB
	// 36 = HOME					16 = SHIFT
	// 35 = END						17 = CONTROL
	// 46 = DEL						18 = ALT
	// 45 = INS						44 = PRINT SCREEN
	// 73 = PAGE UP					19 = PAUSE
	// 81 = PAGE DOWN				32 = SPACE	
}

int calendario(int posX, int posY, int linha, int coluna){
	// Aloca espaço na memória para guardar a parte da tela onde a caixa vai se abrir	
	struct char_info *screen_buffer;	
	screen_buffer = malloc((posY+23) * (posX + 12) * sizeof(struct char_info));
	_conio_gettext(posY, posX, posY+23 , posX+12 , screen_buffer); // Copia a parte da tela
	
	int ano, mes, dia, semana, data1;
	char data[8], dia1[2]; // variaveis para armazenar a data com 8 digitos e o dia com 2 digitos
	const char *mes1[] = {"01","02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"};

	int diaDoMes[6][6]; // matriz pra guardar os dias dentro do mes
	struct tm *local; // cria estrutura local para buscar a hora do sistema
	struct tm tm = {0}; // cria estrutura tm para armazenar data

	time_t t;
	t = time(NULL);
	local = localtime(&t);
		
	ano = local->tm_year; ano = ano + 1900;
	mes = local->tm_mon;
	dia = local->tm_mday;
	semana = local->tm_wday;
		
	int x = posX, y = posY, i = 0, j = semana, jj = j * 3, dias, xLin = x + 4, xCol = y;
	
	cor(15, 4); borders(x,y,22,11,15,4); borderdt(x, y, 22, 11);
	gotoxy(x, y + 5); putchar(203);
	gotoxy(x + 2, y + 5); putchar(202);
	gotoxy(x + 1, y + 5); putchar(186);
	
	cor(12,4); gotoxy(x + 3, y + 1); printf("D  S  T  Q  Q  S  S");	
	
	int op = 0, sair = 0, desenhar = 2;
	do{ // Estrutura para escolher o dia
		if (desenhar == 2){	// escolhe o mês e o ano		
			desenhar = 1; x = posX; y = posY;
			if (mes<0) {mes = 11; ano = ano - 1; tm.tm_year = ano - 1900;}
			if (mes>11) {mes = 1; ano = ano + 1; tm.tm_year = ano - 1900;}
			
			tm.tm_year = ano - 1900;
			tm.tm_mday = 1;
			tm.tm_mon = mes;
			mktime(&tm); // Reseta a nova data informada
			semana = tm.tm_wday;
			
			cor(15, 4); gotoxy(x + 1, y + 6); string$(16, 32);
			gotoxy(x + 1, y + 1); printf("%d", ano);
			for (i = 0; i<6; i++){
				cor(15,4); gotoxy(i + x + 4, y + 1); string$(21, 32); 
			}
			cor(15,4);
			switch(mes){
				case 0:  gotoxy(x + 1, y + 10); printf("JANEIRO"); dias = 31; break;
				case 1:  gotoxy(x + 1, y + 9); printf("FEVEREIRO"); dias = 28; break;
				case 2:  gotoxy(x + 1, y + 11); printf("MARCO"); dias = 31; break;
				case 3:  gotoxy(x + 1, y + 11); printf("ABRIL"); dias = 30; break;
				case 4:  gotoxy(x + 1, y + 12); printf("MAIO"); dias = 31; break;
				case 5:  gotoxy(x + 1, y + 11); printf("JUNHO"); dias = 30; break;
				case 6:  gotoxy(x + 1, y + 11); printf("JULHO"); dias = 31; break;
				case 7:  gotoxy(x + 1, y + 10); printf("AGOSTO"); dias = 31; break;
				case 8:  gotoxy(x + 1, y + 10); printf("SETEMBRO"); dias = 30; break;
				case 9:  gotoxy(x + 1, y + 10); printf("OUTUBRO"); dias = 31; break;
				case 10:  gotoxy(x + 1, y + 10); printf("NOVEMBRO"); dias = 30; break;
				case 11:  gotoxy(x + 1, y + 10); printf("DEZEMBRO"); dias = 31; break;
				default:  gotoxy(x + 1, y + 10); printf("JANEIRO"); dias = 31; break;
			}
			if (mes==1 && (ano%4==0)) dias = 29; // verifica se o ano é bissexto
			
			if (dia > dias) dia = dias; // verifica se o dia atual da posição do cursor é maior que os dias do mês
		}
		
		if (desenhar == 1){			
			desenhar = 0; i = 0; j = semana; 
			jj = 0; jj = j * 3; x = posX;
			xLin = 0; xLin = x + 4; 
			xCol = 0; xCol = y;
			
			for(x = 0; x < 31; x++){
				diaDoMes[i][j] = x + 1; 
				if (x >= dias) diaDoMes[i][j] = NULL; 
				if (i<10) gotoxy(xLin + i , (xCol + jj + 1)); 
				if (j==0) cor(14,4); else cor(15,4);
				if (diaDoMes[i][j] == dia) cor(4,14);
				if (diaDoMes[i][j] != 0) printf("%d", diaDoMes[i][j]);
				else string$(3, 32);
				j = j + 1; jj = jj + 3;
				if (j == 7){
					j = 0; i = i + 1; jj = 0;
				}
			}				
		}
		
		cor(0,15);		
		if (dia<10) {
			sprintf(data, "%d%s0%d", ano, mes1[mes], dia);
			gotoxy(linha, coluna); printf("0%d/%s/%d", dia, mes1[mes], ano);
		}
		else {
			sprintf(data, "%d%s%d", ano, mes1[mes], dia);
			gotoxy(linha, coluna); printf("%d/%s/%d", dia, mes1[mes], ano);	
		}
		data1 = atoi(data);
	
		op = tecla();		
		if (op == 27) sair = 1;// ESC
		if (op == 13) sair = 1;// RETURN
		if ((op == 75) && (dia - 1 > 0)) {dia = dia - 1; desenhar = 1;}//LEFT
		if ((op == 77) && (dia + 1 < dias + 1)) {dia = dia + 1; desenhar = 1;}//RIGHT
		if ((op == 72) && (dia - 7 > 0)) {dia = dia - 7; desenhar = 1;}// UP
		if ((op == 80) && (dia + 7 < dias + 1)) {dia = dia + 7; desenhar = 1;}// DOWN
		if (op == 73) {mes = mes - 1; desenhar = 2;}// PGUP
		if (op == 81) {mes = mes + 1; desenhar = 2;}// PGUP
		
	} while(sair == 0);	
	
	puttext(posY, posX, posY+23 , posX+12 , screen_buffer);
	normvideo();
	free(screen_buffer);
	
	return data1;	
}

int comboBox(int xLin, int xCol,char listaRecebida[][30], int quantidade){
	///
	/// Aloca espaço na memória para guardar a parte da tela onde a caixa vai se abrir	
	///
	int larg = 15, alt = quantidade+1, i;
	xLin = xLin + 1;
	struct char_info *screen_buffer;		
	screen_buffer = malloc((xCol + larg + 1) * (xLin + alt + 1) * sizeof(struct char_info));
	_conio_gettext(xCol, xLin, xCol + larg + 1, xLin + alt + 1, screen_buffer); // Copia a parte da tela	
	///
	/// Abre caixa de listagem
	///	
	for (i=0; i<alt; i++) {   	
		gotoxy(xLin + i , xCol); 		
		cor(14, 4); string$(larg +1 , 32);		
	}
	gotoxy(xLin, xCol);	cor(14, 4); string$(larg + 1, 223);	
	cor(4, 0); gotoxy(xLin + alt - 1 , xCol); string$(larg + 1, 223);
	///
	/// Inicializa variaveis
	///
	int x = 0; // linha que movimento o cursor
	int y = 0; // linha que guarda o registro da posição do cursor	
	int lin = xLin + 1; 
	int col = xCol + 1; // 
	int limite = 0; // quantidade de registros (-1)
	int retorno = -1; // assume o valor de limite
	int indice = 0; // carrega nome para a listBox
	int movimento = 0;// habilita ou desabilita a rolagem dos itens da listBox
	int registro = 0;
	int sair = 0; // Encerra a listBox quando sair=1
	int botao; // tecla apertada
	int limpar = larg - 1; // tamanho do campo nome para ser limpo na movimentação do cursor
	///
	/// Declara vetor do tamanho da quantidade de registros 
	///
	LISTA nomes[quantidade]; 
	///
	/// Carrega registros para o vetor e exibe na caixa
	///
	for(i=0;i<quantidade; i++)	{
		cor(14, 4);
		nomes[i].cod = i+1;
		strcpy(nomes[i].nome, listaRecebida[i+1]);
		gotoxy((xLin+1) + i, xCol+1); printf("%s", nomes[i].nome);
	}
	limite = quantidade - 1; // variavel limite recebe o total de registros	
	gotoxy(lin + x, col); cor(4, 14); string$(limpar, 32);
	gotoxy(lin + x, col); cor(4, 14); printf("%s", nomes[y].nome);	
	///
	/// Movimenta cursor dento da janela
	///
	sair = 0; 		
	do{			
		botao = tecla();			
		if (botao == RETURN) {sair = 1;	retorno = y+1;}
		if (botao == ESC) {sair = 1; retorno = -1;}
		///
		/// Seta para cima e cursor na borda da janela e registro maior do que zero
		///
		if (botao == ARROW_UP && x==0 && y>0 ) {
			x = 0; y = y - 1; indice = indice - 1;
			for(i=0;i<=(alt-3);i++){
				gotoxy(lin + i, col); cor(14, 4); string$(limpar,32);
				gotoxy(lin + i, col); cor(14, 4); printf("%s", nomes[indice + i].nome);					
			}
			gotoxy(lin, col); cor(4, 14); string$(limpar, 32);
			gotoxy(lin, col); cor(4, 14); printf("%s", nomes[y].nome);	
		}
		///
		/// Seta para cima e cursor maior do que a borda
		///
		if (botao == ARROW_UP && x>0) {
			x = x - 1; y = y - 1; movimento = 0;							
			gotoxy(lin + x, col); cor(4, 14); string$(limpar, 32);
			gotoxy(lin + x, col); cor(4, 14); printf("%s", nomes[y].nome);
			gotoxy(lin + x + 1, col); cor(14, 4); string$(limpar,32);
			gotoxy(lin + x + 1, col); cor(14, 4); printf("%s", nomes[y+1].nome);	
		}
		///
		/// Seta para baixo e cursor menor que o limite da janela e o vetor menor que o limite (-1)
		///
		if (botao == ARROW_DOWN && x<=(alt-4) && y<limite-1) {
			gotoxy(lin + x, col); cor(14, 4); string$(limpar,32);
			gotoxy(lin + x, col); cor(14, 4); printf("%s", nomes[y].nome);
			x = x + 1; y = y + 1;
			gotoxy(lin + x, col); cor(4, 14); string$(limpar, 32);
			gotoxy(lin + x, col); cor(4, 14); printf("%s", nomes[y].nome);
		}
		///
		/// Seta para baixo se o cursor estiver na ultima linha e houver registros
		///			
		if (botao == ARROW_DOWN && x == (alt-3) && y < (limite-1) && movimento == 1){
			y = y + 1; indice = indice + 1; x = alt-3;
			for(i=0;i<=(alt-3);i++){
				gotoxy(lin + i, col); cor(14, 4); string$(limpar,32);
				gotoxy(lin + i, col); cor(14, 4); printf("%s", nomes[indice + i].nome);					
			}
			gotoxy(lin + x, col); cor(4, 14); string$(limpar, 32);
			gotoxy(lin + x, col); cor(4, 14); printf("%s", nomes[y].nome);				
		}
		///
		/// Seta para baixo se o cursor estiver na ultima linha e houver registros
		///			
		if (botao == ARROW_DOWN && x == (alt-3) && y < (limite-1) && movimento == 0){
			movimento = 1; x = alt-3;
			for(i=0;i<=(alt-3);i++){
				gotoxy(lin + i, col); cor(14, 4); string$(limpar,32);
				gotoxy(lin + i, col); cor(14, 4); printf("%s", nomes[indice + i].nome);					
			}
			gotoxy(lin + x, col); cor(4, 14); string$(limpar, 32);
			gotoxy(lin + x, col); cor(4, 14); printf("%s", nomes[y].nome);				
		}
	///
	/// Fim da estrutura Do - While (tecla apertada)
	///	
	}while(sair == 0);	
	///
	/// Fecha janela e esvazia o buffer
	///
	puttext(xCol, xLin, xCol + larg + 1, xLin + alt + 1, screen_buffer);
	normvideo();
	free(screen_buffer); 
	///
	/// Retorna o código do nome pesquisado
	///
	return retorno;
}
