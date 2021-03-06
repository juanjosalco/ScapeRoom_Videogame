#include "Game.h"


Game::Game(){
    creaElementos();
    creaComandos();
}

void Game::creaComandos(){
    WordList* comandos=parser.getComands();
    comandos->addCommand("go", new MoveToCommand(personaje));
    comandos->addCommand("take", new TakeCommand(personaje));
    comandos->addCommand("help", new HelpCommand(comandos));
    comandos->addCommand("use",new UseCommand(personaje));
    comandos->addCommand("inventory",new InventoryCommand(personaje));
    comandos->addCommand("exit",new ExitCommand(personaje));
}

/*crea todos los elementos que están presentes en el juego 
y los configura (cuartos sus zones y que objetos hay en cada room)*/
void Game::creaElementos(){
    
    personaje=new Character("Juan Carlos");
    start=new Zone("Centro","aqui te despertaste",00);
    chest=new Zone("Baul","Un viejo baul con un candado",01);
    bookcase=new Zone("Librero","Un librero desgastado con 5 libros",02);
    table=new Zone("Comedor","Un comedor antiguo con 3 velas apagadas en el centro",04);
    desk=new Zone("Escritorio","Un escritorio con una computadora apagada",05);
    clocks=new Zone("Reloj","Un reloj de pendulo al que le falta una aguja",03);
    zexit=new Zone("Salida","Es la unica puerta de la habitacion y tal vez tu unica salida",06);
    note1=new Note("nota_inicial","Una carta escrita a mano",false, "Bienvenido… Tal vez te preguntes que haces aquí… \nTendrás que averiguarlo por ti mismo, este cuarto contiene las respuestas que buscas y la manera de salir de aquí.\nPD:  Espero que no tardes demasiado o tendré qué sacar otro cadaver de esa habitación. ");
    note2=new Note("nota_Baul","Una ficha de texto",true, "Si usaste la llave para intentar abrir la puerta me decepcionas, ¿De verdad pensaste que sería tan fácil?. \nSi viniste directo al baúl, que suerte tienes. \nDe seguro ya te habrás preguntado quien soy y porqué hago esto, de lo primero puedo decirte que soy alguien que conoces pero del porque… \n\nEs algo que deberás averiguar.");
    note3=new Note("nota_librero","Una hoja de recortes",true, "Parece que no has olvidado lo que aprendiste en la escuela, aunque tal vez a mí sí. \nY si así fue, también olvidaste lo que me hiciste, espero que antes de que terminemos aquí lo recuerdes.\nPD: Justo al terminar este día pero también al inicio del mañana podrás encontrar más respuestas");
    note4=new Note("nota_reloj","Una placa con una inscripcion",true, "¿El tiempo vuela cuando te diviertes cierto? ¿O solo soy yo?, cómo sea… \nQué tantos privilegios tenías que no te dabas cuenta de que eran privilegios. \nEspero recuerdes a aquellos que no tenemos ni uno de ellos.\nPD: Parece que no eres tan tonto como recordaba, tu siempre estuviste bajo los reflectores \ny yo en tu sombra ojalá aún tengas ese brillo abrasador porque lo necesitarás.");
    note5=new Note("nota_Mesa","Un mensaje el techo escrito en sangre",true,"Que raro tu mirando hacia arriba, siendo que siempre nos miraste hacia abajo, por cierto, ¿Te gustaron mis velas mágicas? \nFueron un favor de un gran amigo, dime… ¿Alguna vez has hecho favores? \nPD:  Espero recuerdes mantenerte conectado con las personas que amas, no queremos que se pierdan de tus memes…");
    note6=new Note("nota_Escritorio","Un mensaje en la computadora",true,"De seguro tienes frío, pero tranquilo es algo temporal, ya sea que termines con él o él contigo. \nTodo depende de ti, de todas formas, creo que has terminado por hoy, la contraseña del cajón de abajo a la derecha es 2629, \nábrela, toma la llave y lárgate de aquí.. Si puedes…");
    note7=new Note("nota_final","Una carta hecha a mano",true, "Bienvenido al final, o al comienzo ya que todo final siempre es el comienzo de algo mejor. \nAsí que espero que de ahora en adelante seas mejor con las personas que te rodean, y espero que tu corazón ya no sea tan frío como las gotas de lluvia que caían sobre mi rostro aquella noche \npor no poder irme en camión…¡¡¡ DEBISTE PRESTARME ESOS 5 PESOOOOOOOS !!! Era tu mejor amigo… Solo te pedí ayuda… Y que hiciste? \nPD: Tranquilo… Si piensas en buscarme saliendo de aquí, no lo intentes, ya estaré muerto o tal vez tu lo estés \n\n**Escuchas un ruido detrás de ti, cuando volteas…**");
    note8=new Note("nota_final_alter","Una carta hecha a mano",true, "* Despiertas de nuevo en la cama del hospital, al parecer fue demasiado estrés por semana 5 \nescuchas a tu familia y amigos alegrarse porque abriste los ojos… \nPero también lo escuchas a él decir…");
    piece1=new Piece("Llave","Esta vieja y oxidada pero aún debe de funcionar",false,01,true);
    piece2=new Piece("Ficha_APA","Es una Ficha de biblioteca que dice \nTabu \nIntroduccion a C++ \nMás alla del bien y el mal \nEl arte de la guerra",true,02,true);
    piece3=new Piece("Aguja_de_reloj","Parece pertenecer a un reloj antiguo por su forma tan rebuscada y elegante",true,03,true);
    piece4=new Piece("Encendedor","Un zippo de metal con la incripcion 'Magico'",true,04,true);
    piece5=new Piece("Cable_de_alimentacion","Un simple cable de alimentacion para computadora",true,05,true);
    piece6=new Piece("Llave_final","Esta vieja y oxidada pero aún debe de funcionar",true,06,true);
    

    personaje->setPosition(start);
    start->addItem(note1);
    start->addItem(piece1);
    chest->addItem(note2);
    chest->addItem(piece2);
    bookcase->addItem(note3);
    bookcase->addItem(piece3);
    clocks->addItem(note4);
    clocks->addItem(piece4);
    table->addItem(note5);
    table->addItem(piece5);
    desk->addItem(note6);
    desk->addItem(piece6);
    zexit->addItem(note7);
    zexit->addItem(note8);
    
    //setear las zonas al rededor de otras
    start->setZonez(chest);
    start->setZonez(bookcase);
    start->setZonez(clocks);
    start->setZonez(table);
    start->setZonez(desk);
    start->setZonez(zexit);

    chest->setZonez(start);
    chest->setZonez(bookcase);
    chest->setZonez(clocks);
    chest->setZonez(table);
    chest->setZonez(desk);
    chest->setZonez(zexit);

    bookcase->setZonez(start);
    bookcase->setZonez(chest);
    bookcase->setZonez(clocks);
    bookcase->setZonez(table);
    bookcase->setZonez(desk);
    bookcase->setZonez(zexit);

    clocks->setZonez(start);
    clocks->setZonez(chest);
    clocks->setZonez(bookcase);
    clocks->setZonez(table);
    clocks->setZonez(desk);
    clocks->setZonez(zexit);

    clocks->setZonez(start);
    clocks->setZonez(chest);
    clocks->setZonez(bookcase);
    clocks->setZonez(table);
    clocks->setZonez(desk);
    clocks->setZonez(zexit);

    table->setZonez(start);
    table->setZonez(chest);
    table->setZonez(bookcase);
    table->setZonez(clocks);
    table->setZonez(desk);
    table->setZonez(zexit);

    desk->setZonez(start);
    desk->setZonez(chest);
    desk->setZonez(bookcase);
    desk->setZonez(clocks);
    desk->setZonez(table);
    desk->setZonez(zexit);

    zexit->setZonez(start);
    zexit->setZonez(chest);
    zexit->setZonez(bookcase);
    zexit->setZonez(clocks);
    zexit->setZonez(table);
    zexit->setZonez(desk);
}

void Game::imprimeBienvenida(){
    std::cout<< "Te despiertas después de un coma de 5 días, lo último que recuerdas es a tu mejor amigo decir, “- Todo va a estar bien…”. \nEstás adolorido, encerrado entre 4 paredes con una puerta frente a ti  y en el piso una nota con una llave." << std::endl;
    std::cout<< "Miras alrededor y ves varias cosas, un librero, escritorio, un reloj de péndulo, mesa y un baúl."<<std::endl;
    std::cout<< "Debes escapar lo antes posible!! Haz uso de todo lo que encuentres en la habitación para descifrar cómo salir."<<std::endl;
    std::cout << "Si necesitas ayuda teclea la palabra: help" << std::endl;
    std::cout <<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"<< std::endl;
    std::cout <<"░█████████████████████████████████████████████████████████████████████████░"<< std::endl;
    std::cout <<"░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░"<< std::endl;
    std::cout <<"░█░░░░░░░░░░░░░░┌───────────────────────┐░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░"<< std::endl;
    std::cout <<"░█░░░░░░░░░░░██░│█████║██║██║██║██║█████│░██░░░░░░░░┌──▄───┐░░░░░░░░░░░░░█░"<< std::endl;
    std::cout <<"░█░░░░░░░░░░░░░░└───────────────────────┘░░░░░░░░░░┌┘▀░│░░▀└┐░░░░░░░░░░░░█░"<< std::endl;
    std::cout <<"░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░│▌░░░░░░▐│░░░░░░░░░░░░█░"<< std::endl;
    std::cout <<"░█░░░░░░░░░░░░░░░██░██░██░██░██░██░██░██░░░░░░░░░░░└┐▄░▄░░▄┌┘░░░░░░░░░░░░█░"<< std::endl;
    std::cout <<"░█┌──┐░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░└──────┘░░░░░░░░░░░░░█░"<< std::endl;
    std::cout <<"░█│╔╗│░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║░"<< std::endl;
    std::cout <<"░█│║║│░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║░"<< std::endl;
    std::cout <<"░█│║║│░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▄▄░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║░"<< std::endl;
    std::cout <<"░█│║║│░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▄▄▄██▄▄▄░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║░"<< std::endl;
    std::cout <<"░█│║║│░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░████░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║░"<< std::endl;
    std::cout <<"░█│║║│░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║░"<< std::endl;
    std::cout <<"░█│║║│░░░░░░░░░░░░░░░░░░░░░░░░░░░░░───█░░█───░░░░░░░░░░░░░░░░░░░░░░░░░░░░║░"<< std::endl;
    std::cout <<"░█│╚╝│░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░──────░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║░"<< std::endl;
    std::cout <<"░█└──┘░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║░"<< std::endl;
    std::cout <<"░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░"<< std::endl;
    std::cout <<"░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░"<< std::endl;
    std::cout <<"░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░"<< std::endl;
    std::cout <<"░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░"<< std::endl;
    std::cout <<"░█░░░░░░░▄▄▄▄▄▄▄▄▄▄▄░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░"<< std::endl;
    std::cout <<"░█░░░░░░█▒▒▒▒▒▒▒▒▒▒▒█░░░░░░░░░░░░╔═════════════════╗░░░░░░░░░░░░░░░░░░░░░█░"<< std::endl;
    std::cout <<"░█░░░░░░▌▒▒▒▒▒╬▒▒▒▒▒▐░░░░░░░░░░░░║▒▒▒▒▒▒▀▀▀▀▒▒▀─┐▒▒║░░░░░░░░░░░░░░░░░░░░░█░"<< std::endl;
    std::cout <<"░█░░░░░░▌═══════════▐░░░░░░░░░░░░║▒▒▒▀▀▀▀▀▀▀▀▀▀─┘▒▒║░░░░░░░░░░░░░░░░░░░░░█░"<< std::endl;
    std::cout <<"░█████████████████████████████████████████████████████████████████████████░"<< std::endl;
    std::cout <<"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"<< std::endl;
}

void Game::play(){

    imprimeBienvenida();
    bool finished = false;
    while (!finished) {
        Command* command = parser.generateCommand();
        command->run(); // se esta ejecutando polimorfismo
    }
}