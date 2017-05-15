//
//  main.cpp
//  PROG
//
//  Created by Mateus Pedroza on 14/04/17.
//  Copyright © 2017 Mateus Pedroza. All rights reserved.
//
#include <queue>
#include "main.hpp"

using namespace std;

//  mantem uma só instância da transportadora
static Transportadora transportadora;


int main(int argc, const char * argv[]) {
    FileService fileService;

    transportadora = fileService.getTransportadora();

    cout << "Foi carregado uma transportadora com " << transportadora.getLinhas().size() << " linhas, "
         << transportadora.getLinhas().size() << " condutores e "
         << transportadora.getAutocarros().size() << " autocarros." << endl;

    //  mostrar menu
    showMenu();

    //  terminar programa, salvar dados.
    fileService.saveData(transportadora);
    cout << endl << "Dados salvos com sucesso!" << endl;
    return 0;
}

void displayAutocarro(Autocarro autocarro) {
    // salvar formatação default
    ios init(NULL);
    init.copyfmt(cout);

    // mostrar informacoes do autocarro
    cout << endl << "Linha: " << autocarro.getLinhaId() << " ";
    cout << "Numero: " << autocarro.getOrdemNaLinha() << " ";
    cout << "Condutor: " << autocarro.getCondutorId() << endl;

    // restaurar formatação default
    cout.copyfmt(init);

    // mostrar turnos do autocarro
    if (autocarro.getProgramacao().empty()) {
        cout << "Nao ha turnos neste autocarro!" << endl;
    } else {
        cout << "Turnos: " << endl;

        for (Turno turno: autocarro.getProgramacao()) {
            cout << "\t";
            displayTurno(turno);
        }
    }
}

void displayTurno(Turno turno){
    // salvar formatação default
    ios init(NULL);
    init.copyfmt(cout);

    cout << "Linha: " << setw(5) << left << turno.getLinhaId() << " ";
    cout << "Numero: " << setw(5) << turno.getOrdemNaLinha() << " ";

    if (turno.getCondutorId() != -1) {
        cout << "Id do condutor: " << turno.getCondutorId() << " ";
    }

    cout << "Inicio: " << setw(10) << turno.getTempoInicio() << " ";
    cout << "Fim: " << setw(10) << turno.getTempoFim() << " ";
    cout << "Tempo total do turno (minutos): " << setw(10) << turno.getTempoTotalEmMinutos() << endl;

    // restaurar formatação default
    cout.copyfmt(init);
}

void displayParagem(Paragem paragem){
    // salvar formatação default
    ios init(NULL);
    init.copyfmt(cout);

    cout << setw(25) << paragem.getNome() << setw(5) << setfill(' ') << " ";

    // restaurar formatação default
    cout.copyfmt(init);
}

void displayLinha(Linha linha){
    // salvar formatação default
    ios init(NULL);
    init.copyfmt(cout);

    cout << "Id: " << setw(10) << left << linha.getUid() << " ";
    cout << "Frequência: " << setw(10) << linha.getFreq() << endl;
    cout << "Paragens: ";
    for (Paragem paragem : linha.getParagens()) {
        displayParagem(paragem.getNome());
    }

    cout << endl;
    // restaurar formatação default
    cout.copyfmt(init);
}

void listarLinhasDisponiveis(){
    std::vector<Linha> linhas = transportadora.getLinhas();
    int count = 1;
    for (Linha linha : linhas) {
        cout << count++ << " ~>" << " ";
        displayLinha(linha);
    }
}

void removerLinha(){
    unsigned int opt;
    cout << " - Remover Linha - " << endl;
    //  mostrar linhas
    listarLinhasDisponiveis();
    //  pedir para escolher linha
    cout << "Deseja remover qual linha? " << endl;

    if (!(cin >> opt) || opt > transportadora.getLinhas().size()) {
        cout << "Opção inválida" << endl;
        return;
    }

    transportadora.removerLinha(opt);
    cout << "Linha removida com sucesso!" << endl;
}

void adicionarLinha(){
    vector<Paragem> newParagens;
    vector<int> newTempos;

    cout << " - Adicionar linha - " << endl;
    //  frequencia
    int freq;
    cout << "Qual a frequência?" << endl;
    if (!(cin >> freq) || freq < 0) {
        cout << "Frequência inválida" << endl;
        return;
    }

    //  paragens
    int numParagens;
    cout << "Qual a quantidade de paragens que a linha vai ter? " << endl;

    if (!(cin >> numParagens) || numParagens < 0) {
        cout << "Número de paragens inválido" << endl;
        return;
    }

    cin.ignore();
    //  loop adicionando paragens
    for (int i = 1; i <= numParagens; i++) {
        string nome;
        cout << "Qual o nome da " << i << " paragem?" << endl;

        if (!(getline(cin, nome))) {
            cout << "Erro: Nome inválido!" << endl;
            return;
        }

        Paragem paragem = Paragem(nome);
        newParagens.push_back(paragem);
    }

    // adicionar tempos
    for (int i = 1; i <= (int) newParagens.size(); i++) {
        int tempo;
        cout << "Qual o tempo do " << i << " percurso?" << endl;

        if (!(cin >> tempo) || tempo < 0) {
            cout << "Erro: Tempo inválido!" << endl;
            return;
        }

        newTempos.push_back(tempo);
    }

    Linha linha = Linha((int) transportadora.getLinhas().size(), freq, newParagens, newTempos);
    transportadora.addLinha(linha);

    cout << "Linha adicionada com sucesso!" << endl;
}

void gerirLinhasHandler(int opt){
    switch (opt) {
        case 1: adicionarLinha();
            break;
        case 2: removerLinha();
            break;
        case 3: listarLinhasDisponiveis();
            break;
        default:
            break;
    }
}

void gerirLinhas(){
    int opt;

    cout << endl << "## GERIR LINHAS ##" << endl;
    cout << "1 -> Adicionar linha " << endl;
    cout << "2 -> Remover linha" << endl;
    cout << "3 -> Listar linhas disponíveis" << endl;
    cout << "0 -> Voltar ao menu" << endl;

    if (!(cin >> opt) || opt < 0 || opt > 4) {
        cout << "Opção inválida!" << endl;
        return;
    }
    // chamar handler
    gerirLinhasHandler(opt);
}

void displayCondutor(Condutor condutor){
    // salvar formatação default
    ios init(NULL);
    init.copyfmt(cout);

    //  nome format
    cout << left << setw(20) << condutor.getNome() << " ";
    //  turno format
    cout << "Turno máx: " << setw(2) << condutor.getTurnoMax() << "hrs" << setw(5) << setfill(' ') << " ";
    cout << "Semana: " << setw(2) << condutor.getHorasPorSemana() << "hrs" << setw(5) << setfill(' ') << " ";
    cout << "Descanso: " << setw(2) << condutor.getDescanso() << "hrs" << setw(5) << setfill(' ') << " ";
    cout << "Turnos: " << condutor.getTurnos().size() << endl;

    // restaurar formatação default
    cout.copyfmt(init);
}

void listarCondutoresDisponiveis(){
    cout << " - Listar condutores disponíveis - " << endl;
    std::vector<Condutor> condutores = transportadora.getCondutores();
    int count = 0;

    for (Condutor condutor : condutores) {
        // ->
        cout << " " << count++ << " ~>" << " ";
        //  nome format
        displayCondutor(condutor);
    }
}

void removerCondutor(){
    unsigned int opt;
    cout << " - Remover condutor - " << endl;
    //  mostrar linhas
    listarCondutoresDisponiveis();

    //  pedir para escolher linha
    cout << "Deseja remover qual condutor?" << endl;

    if (!(cin >> opt) || opt > transportadora.getCondutores().size()) {
        cout << "Opção inválida" << endl;
        return;
    }

    transportadora.removerCondutor(opt);
    cout << "Condutor removido com sucesso!" << endl;
}

void adicionarCondutor(){
    string nome;
    int turno, horasPorSemana, descanso;

    cout << " - Adicionar Condutor - " << endl;
    cout << "Qual o nome e sobrenome do condutor?" << endl;
    //nome verificar se tem nome e sobrenome
    cin.ignore();
    if (!(getline(cin, nome)) || split(nome, ' ').size() == 1) {
        cout << "Erro: nome inválido!" << endl;
        return;
    }
    //turno
    cout << "Quantas horas é o turno diário?" << endl;
    if (!(cin >> turno) || turno > 24 || turno < 0) {
        cout << "Erro: turno inválido!" << endl;
        return;
    }
    //horas por semana
    cout << "Quantas horas por semana?" << endl;
    if (!(cin >> horasPorSemana) || horasPorSemana > 168 || horasPorSemana < 0) {
        cout << "Erro: horas por semana inválida!" << endl;
        return;
    }
    //descanso
    cout << "Qual o número mínimo de horas de descanso?" << endl;
    if (!(cin >> descanso) || descanso > 24 || descanso < 0) {
        cout << "Erro: horário de descanso inválido" << endl;
    }

    Condutor condutor = Condutor((int) transportadora.getCondutores().size(), nome, turno, horasPorSemana, descanso);

    transportadora.addCondutor(condutor);
    cout << "Condutor adicionado com sucesso!" << endl;
}

void alterarCondutor() {
    int opt, editOpt;

    cout << endl << " - Alterar condutor - " << endl;
    //  mostrar linhas
    listarCondutoresDisponiveis();

    //  pedir para escolher linha
    cout << "Deseja editar qual condutor?" << endl;
    // validar entrada
    if (!(cin >> opt) || opt > transportadora.getCondutores().size()) {
        cout << "Opção inválida" << endl;
        return;
    }

    Condutor escolhido = transportadora.getCondutores()[opt];
    cout << "Condutor escolhido: " << endl;
    displayCondutor(escolhido);

    // o que deseja editar
    cout << "O que deseja editar?" << endl;
    cout << " 1 -> Mudar nome" << endl;
    cout << " 2 -> Mudar turno maximo diario" << endl;
    cout << " 3 -> Mudar horas maximas por semana" << endl;
    cout << " 4 -> Mudar horas de descanso" << endl;
    cout << " 0 -> Voltar" << endl;
    // validar entrada
    if (!(cin >> editOpt) || editOpt > 4 || editOpt < 0) {
        cout << "Opção inválida" << endl;
        return;
    }

    switch (editOpt) {
        case 1: {
            std::string nome;
            cout << "Qual o nome e sobrenome do condutor?" << endl;
            //nome verificar se tem nome e sobrenome
            cin.ignore();
            if (!(getline(cin, nome)) || split(nome, ' ').size() == 1) {
                cout << "Erro: nome inválido!" << endl;
                return;
            }
            // mudar valor
            escolhido.setNome(nome);
            // atualizar dados da lista
            transportadora.removerCondutor(opt);
            transportadora.addCondutor(escolhido);
            // mudou com sucesso
            cout << "Nome alterado com sucesso" << endl;
            break;
        }
        case 2:
            int horasDiaria;
            cout << "Qual o novo turno maximo de horas diario?" << endl;
            // validar entrada
            if (!(cin >> horasDiaria) || horasDiaria < 0 || horasDiaria > 24) {
                cout << "Horas por turno digitada invalida" << endl;
                return;
            }
            // mudar valor
            escolhido.setTurnoMax(horasDiaria);
            // atualizar dados da lista
            transportadora.removerCondutor(opt);
            transportadora.addCondutor(escolhido);
            // mudou com sucesso
            cout << "Turno alterado com sucesso" << endl;
            break;
        case 3:
            int horasSemana;
            cout << "Qual o novo maximo de horas por semana?" << endl;
            // validar entrada
            if (!(cin >> horasSemana) || horasSemana < 0 || horasSemana > 168) {
                cout << "Horas por semana digitada invalida" << endl;
                return;
            }
            // mudar valor
            escolhido.setHorasPorSemana(horasSemana);
            // atualizar dados da lista
            transportadora.removerCondutor(opt);
            transportadora.addCondutor(escolhido);
            // mudou com sucesso
            cout << "Horas maximas por semana alteradas com sucesso" << endl;
            break;
        case 4:
            int horasDescanso;
            cout << "Qual o novo horario de descanso" << endl;
            // validar entrada
            if (!(cin >> horasDescanso) || horasDescanso < 0 || horasDescanso > 24) {
                cout << "Horas de descanso digitada invalida" << endl;
                return;
            }
            // mudar valor
            escolhido.setDescanso(horasDescanso);
            // atualizar dados da lista
            transportadora.removerCondutor(opt);
            transportadora.addCondutor(escolhido);
            // mudou com sucesso
            cout << "Descanso alterado com sucesso" << endl;
            break;
        default:
            break;
    }
}

void gerirCondutoresHandler(int opt){
    switch (opt) {
        case 1: adicionarCondutor();
            break;
        case 2: removerCondutor();
            break;
        case 3: listarCondutoresDisponiveis();
            break;
        case 4:
            alterarCondutor();
            break;
        default:
            break;
    }
}

void gerirCondutores(){
    int opt;

    cout << endl << "## GERIR CONDUTORES ##" << endl;
    cout << "1 -> Adicionar condutor" << endl;
    cout << "2 -> Remover condutor" << endl;
    cout << "3 -> Listar condutores disponíveis" << endl;
    cout << "4 -> Alterar condutor" << endl;
    cout << "0 -> Voltar ao menu" << endl;

    if (!(cin >> opt) || opt < 0 || opt > 4) {
        cout << "Opção inválida!" << endl;
        return;
    }
    //  chamar handler
    gerirCondutoresHandler(opt);
}

void displayHorariosParagem(Time tempoInicio, Paragem paragem, Linha linha){
    //set start time
    Time tempo = tempoInicio;

    // salvar formatação default
    ios init(NULL);
    init.copyfmt(cout);

    //print paragem
    cout << setw(3) << setfill(' ') << " ";
    cout << setw(10) << setfill(' ') << left << paragem.getNome() << endl;

    int count = 0;
    while (tempo.getHoras() < 22) {
        cout << setw(3) << setfill(' ') << " ";
        cout << setw(2) << setfill('0') << right << tempo.getHoras() << ":";
        cout << setw(2) << setfill('0') << tempo.getMinutos();
        cout << setw(3) << setfill(' ') << " ";
        tempo.addMinutos(linha.getFreq());

        count++;

        if (count == 6) {
            cout << endl;
            count = 0;
        }
    }
}

void verHorariosDeUmaLinha(){
    int opt;

    cout << " - Visualizar horários de uma linha - " << endl;
    cout << "Escolha a linha:" << endl;
    listarLinhasDisponiveis();

    if (!(cin >> opt) || opt < 0 || opt > (int) transportadora.getLinhas().size()) {
        cout << "Erro: opção inválida" << endl;
        return;
    }
    // salvar formatação default
    ios init(NULL);
    init.copyfmt(cout);

    //  print nome da linha
    Linha linha = transportadora.getLinhas()[opt - 1];
    cout << setw(30) << setfill(' ') << "Linha: " << linha.getUid() << endl;
    //  print paragem final
    Paragem paragemFinal = linha.getParagens().back();
    cout << setw(25) << setfill(' ') << "Rumo " << paragemFinal.getNome() << endl;
    //linha de começo
    Time tempoInicio = Time(8, 0);

    for (int i = 0; i < (int) linha.getParagens().size(); i++) {
        Paragem paragem = linha.getParagens()[i];
        //  mostrar horarios da paragem
        displayHorariosParagem(tempoInicio, paragem, linha);
        cout << endl << endl;

        tempoInicio.addMinutos(linha.getTempos()[i]);
    }
    // linha ao contrario
    cout << setw(25) << setfill(' ') << "Rumo " << linha.getParagens().front().getNome() << endl;

    for (int j = (int) linha.getParagens().size() - 1; j >= 0; j--) {
        Paragem paragem = linha.getParagens()[j];
        // mostrar horarios da paragem
        displayHorariosParagem(tempoInicio, paragem, linha);
        cout << endl << endl;

        tempoInicio.addMinutos(linha.getTempos()[j]);
    }

    // restaurar formatação default
    cout.copyfmt(init);
}

void visualizarTabelaComHorarioDeUmaParagem(){
    string nome;
    int opt;
    cout << endl << "Qual a linha que deseja consultar o horário da paragem?" << endl;
    listarLinhasDisponiveis();

    if (!(cin >> opt) || opt < 0 || opt > (int) transportadora.getLinhas().size()) {
        cout << "Erro: linha inválida" << endl;
    }
    Linha linha = transportadora.getLinhas()[opt - 1];

    cout << "Digite o nome da paragem que deseja consultar" << endl;
    cin.ignore();
    if (!(getline(cin, nome))) {
        cout << "Erro: valor digitado não é permitido" << endl;
        return;
    }

    int uid = 0;
    bool found = false;
    for (Paragem paragem : linha.getParagens()) {
        if (paragem.getNome() == nome) {
            cout << endl;
            //  mostrar horarios da paragem
            Time tempoInicio = Time(8, 0);
            if (uid > 0) {
                tempoInicio.addMinutos(linha.getTempos()[uid - 1]);
            }
            displayHorariosParagem(tempoInicio, paragem, linha);
            found = true;
            cout << endl;
        } else {
            uid++;
        }
    }
    if (!found)
        cout << "Paragem não encontrada" << endl;
}

void visualizarTrabalhoDeUmCondutor(){
    int opt;

    cout << " - Visualizar trabalho de um condutor - " << endl;

    listarCondutoresDisponiveis();

    if (!(cin >> opt) || opt > (int) transportadora.getCondutores().size()) {
        cout << "Erro: opção inválida!" << endl;
    }

    Condutor condutor = transportadora.getCondutores()[opt];
    displayCondutor(condutor);

    // mostrar trabalhos do condutor
    cout << "Turnos: " << endl;
    for (Turno turno: condutor.getTurnos()) {
        displayTurno(turno);
    }
}

void inquirirLinhasDeDeterminadaParagem(){
    string paragem;
    cout << " - Inquerir linhas de uma paragem - " << endl;
    cout << "Digite o nome da paragem: " << endl;
    cin.ignore();
    if (!(getline(cin, paragem))) {
        cout << "Erro: paragem inválida" << endl;
    }

    vector<Linha> linhasEncontradas = transportadora.getLinhasComParagem(paragem);

    if (linhasEncontradas.size() == 0) {
        cout << "Paragem não encontrada!" << endl;
    } else {
        for (Linha linha : linhasEncontradas) {
            displayLinha(linha);
        }
    }
}

void displayPercurso(Percurso percurso) {
    if (percurso.getPosPrimeiraParagem() == percurso.getPosSegundaParagem()) {
        cout << "As duas paragens coincidem!" << endl;
    } else if (percurso.getPosPrimeiraParagem() < percurso.getPosSegundaParagem()) {
        int tempoTotal = 0;
        cout << "Percurso: " << endl;
        for (int j = percurso.getPosPrimeiraParagem(); j <= percurso.getPosSegundaParagem(); j++) {
            Paragem paragem = percurso.getLinha().getParagens()[j];
            displayParagem(paragem);
            tempoTotal += percurso.getLinha().getTempos()[j - 1];
        }
    } else if (percurso.getPosPrimeiraParagem() > percurso.getPosSegundaParagem()) {
        int tempoTotal = 0;
        cout << "Percurso: " << endl;
        for (int j = percurso.getPosPrimeiraParagem(); j >= percurso.getPosSegundaParagem(); j--) {
            Paragem paragem = percurso.getLinha().getParagens()[j];
            displayParagem(paragem);
            tempoTotal += percurso.getLinha().getTempos()[j - 1];
        }
    }
    cout << endl;
}

void displayResultadoPercurso(ResultadoPercurso resultado) {
    cout << "# Resultado: " << endl;
    // display percursos
    for (Percurso percurso: resultado.getPercursos()) {
        displayPercurso(percurso);
    }
    // display tempo total
    cout << "Tempo total: " << resultado.getTempoTotal() << " minutos" << endl;
}

void calcularMostrarPercursoEntreParagens(){
    string opt1, opt2;
    priority_queue<ResultadoPercurso, vector<ResultadoPercurso>, ResultadoCompare> resultados;

    // mostrar opcoes
    cout << " - Calcular percurso entre duas paragens - " << endl;
    cin.ignore();
    cout << "Digite o nome da primeira paragem" << endl;
    getline(cin, opt1);
    cout << "Digite o nome da segunda paragem" << endl;
    getline(cin, opt2);

    // erro se as paragens sao iguais
    if (opt1 == opt2) {
        cout << "Erro: mesma paragem digitada duas vezes!" << endl;
        return;
    }

    // procurar linhas com a paragem inicial
    vector<Linha> linhasComParagemInicial = transportadora.getLinhasComParagem(opt1);
    vector<Linha> linhasComParagemFinal = transportadora.getLinhasComParagem(opt2);

    if (linhasComParagemInicial.size() == 0 || linhasComParagemFinal.size() == 0) {
        cout << "Erro: paragens escolhidas invalidas" << endl;
        return;
    }

    // loop com as linhas encontradas
    for (Linha linhaComParagemInicial: linhasComParagemInicial) {
        // posicao da primeira paragem
        int posPrimeiraParagem = linhaComParagemInicial.getPosParagem(opt1);

        // posicao da paragem final se existir na linha
        int posSegundaParagem = linhaComParagemInicial.getPosParagem(opt2);

        // encontrou a paragem na linha
        if (posSegundaParagem != -1) {
            // calcular distancia das primeiras paragens
            int distancia = linhaComParagemInicial.calcularTempoTotalEntreParagens(posPrimeiraParagem,
                                                                                   posSegundaParagem);

            // criar um percurso
            Percurso percurso = Percurso(posPrimeiraParagem, posSegundaParagem, linhaComParagemInicial, distancia);

            // criar um resultado  e adicionar o percurso
            ResultadoPercurso resultado;
            resultado.addPercurso(percurso);

            // adicionar percurso a lista
            resultados.push(resultado);
        }

        // em todas as linhas que possui paragem final, pesquisar se uma das paragens
        for (Paragem paragem : linhaComParagemInicial.getParagens()) {
            vector<Linha> linhasComParagem = transportadora.getLinhasComParagem(paragem.getNome());

            // em toda linha que contem a paragem, verificar se existe a paragem final na linha
            for (Linha linhaComParagem : linhasComParagem) {
                // posicao da paragem em comum
                int paragemInicialPos = linhaComParagem.getPosParagem(paragem.getNome());
                // posicao da paragem final
                int paragemFinalPos = linhaComParagem.getPosParagem(opt2);

                // achou paragem final na linha que nao possui a paragem inicial
                if (paragemFinalPos != -1 && linhaComParagem.getPosParagem(opt1) == -1) {
                    /* PERCURSO COMPOSTO DE DUAS ROTAS */

                    // calcular distancia da primeira rota
                    int distancia1 = linhaComParagemInicial.calcularTempoTotalEntreParagens(posPrimeiraParagem,
                                                                                            linhaComParagemInicial.getPosParagem(
                                                                                                    paragem.getNome()));
                    // calcular distancia da segunda rota
                    int distancia2 = linhaComParagem.calcularTempoTotalEntreParagens(paragemInicialPos,
                                                                                     paragemFinalPos);

                    // criar percursos
                    Percurso percurso1 = Percurso(posPrimeiraParagem,
                                                  linhaComParagemInicial.getPosParagem(paragem.getNome()),
                                                  linhaComParagemInicial, distancia1);
                    Percurso percurso2 = Percurso(paragemInicialPos, paragemFinalPos, linhaComParagem, distancia2);

                    // criar um resultados e adicionar os percursos
                    ResultadoPercurso resultado;
                    resultado.addPercurso(percurso1);
                    resultado.addPercurso(percurso2);

                    // adicionar percurso a lista
                    resultados.push(resultado);
                }
            }
        }
    }
    // nao obteve resultados
    if (resultados.empty()) {
        cout << "Nao foi encontrado um percurso entre as paragens" << endl;
        return;
    }
    // mostrar resultados
    while (!resultados.empty()) {
        displayResultadoPercurso(resultados.top());
        resultados.pop();
    }
}

void calcularCondutoresNecessariosParaLinha(){
    int linhaopt;

    cout << endl << " - Condutores necessários por linha - " << endl;
    cout << "Linhas: " << endl << endl;
    //  mostrar linhas
    listarLinhasDisponiveis();
    cout << endl;

    //  pedir para escolher linha
    cout << "Escolha a linha para a calcular a distância: " << endl;
    // verificar escolha
    if (!(cin >> linhaopt) || linhaopt <= 0 || linhaopt > (int) transportadora.getLinhas().size()) {
        cout << "Erro: escolha inválida" << endl;
        return;
    }
    cout << endl;
    Linha linha = transportadora.getLinhas()[linhaopt - 1];

    //  mostrar linha
    cout << "Linha: " << endl;
    displayLinha(linha);

    //int totalHoras = linha.getTempoPercurso();
    int turno;

    cout << endl << "Quantas horas tem o turno?" << endl;

    if (!(cin >> turno) || turno <= 0) {
        cout << "Erro: valor inválido! " << endl;
    }

    int horasLinha = 22 - 8;
    int resultado = horasLinha / turno;

    if (resultado <= 1) {
        cout << "É necessário apenas um condutor!" << endl;
    } else {
        cout << "São necessários " << resultado << " condutores" << endl;

    }
    cout << endl;
}

//  TODO listarCondutoresSemServicoAtribuido : verificar se essa e a implementacao correta
void listarCondutoresSemServicoCompletoAtribuido(){
    cout << endl << " - Listar condutores sem serviço completo atribuido  -" << endl;

    vector<Condutor> condutoresSemServico = transportadora.getCondutoresSemServicoAtribuidos();
    for (Condutor condutor: condutoresSemServico) {
        displayCondutor(condutor);
    }
}

void visualizarInformacaoAutocarro() {
    int opt, numOrdem;

    cout << endl << " - Visualizar informacao de um autocarro - " << endl;
    listarLinhasDisponiveis();
    cout << endl << "Escolha a linha do autocarro: " << endl;

    if (!(cin >> opt) || opt > transportadora.getLinhas().size()) {
        cout << "Erro: linha escolhida invalido!" << endl;
        return;
    }

    // obter linha
    Linha linha = transportadora.getLinhas()[opt - 1];

    cout << "Digite o numero da ordem do autocarro entre 1 e " << linha.getNumeroAutocarrosNecessarios() << " : ";

    if (!(cin >> numOrdem) || numOrdem > linha.getNumeroAutocarrosNecessarios()) {
        cout << "Erro: numero do autocarro na linha invalido!" << endl;
    }

    // obter autocarro
    Autocarro autocarro = transportadora.getAutocarro(linha.getUid(), numOrdem);

    // mostrar autocarro
    displayAutocarro(autocarro);
}

void listarTurnos(vector<Turno> turnos) {
    // obteve turnos, mostrar ao utilizador
    int counter = 1;
    for (Turno turno: turnos) {
        cout << setw(5) << counter << " -> ";
        displayTurno(turno);
        counter++;
    }
}

void listarTurnosSemCondutor() {
    cout << " - Listar turnos sem condutores associados - " << endl;
    // obter turnos sem condutores
    vector<Turno> turnos = transportadora.getTurnosNaoAtribuidos();

    // verificar se foi retornado algum
    if (turnos.empty()) {
        cout << "Nao ha turnos sem condutores associados!" << endl;
    } else {
        // obteve turnos, mostrar ao utilizador
        listarTurnos(turnos);
    }
}

void efetuarAtribuicaoDeServicoAumCondutor() {
    int condutOpt;
    cout << endl << " - Efetuar atribuiçao de serviço a um condutor - " << endl;
    // escolher condutor
    listarCondutoresDisponiveis();
    cout << "Digite o numero do condutor: " << endl;
    // validar escolha
    if (!(cin >> condutOpt) || condutOpt < 0 || condutOpt > transportadora.getCondutores().size()) {
        cout << "Erro: escolha invalida" << endl;
        return;
    }

    // obter condutor
    Condutor escolhido = transportadora.getCondutores()[condutOpt];
    int minutosSemanaisRestantes = escolhido.getMinutosSemanaisRestantes();
    cout << "Escolhido: " << endl;
    displayCondutor(escolhido);
    cout << "Minutos semanais restantes: " << minutosSemanaisRestantes << endl;

    // obter turnos disponiveis
    vector<Turno> turnosNaoAtribuidos = transportadora.getTurnosDisponiveisACondutor(escolhido);

    // mostrar turnos que podem ser adicionados
    listarTurnos(turnosNaoAtribuidos);

    // escolher turno a ser adicionado
    int turnoOpt;

    cout << "Digite o numero do turno a ser adicionado: " << endl;
    // validar escolha
    if (!(cin >> turnoOpt) || turnoOpt < 0 || turnoOpt > turnosNaoAtribuidos.size()) {
        cout << "Erro: escolha invalida" << endl;
        return;
    }

    transportadora.atribuirServicoAoCondutor(escolhido, turnosNaoAtribuidos[turnoOpt - 1]);

    // atualizar condutor
    transportadora.removerCondutor(condutOpt);
    transportadora.addCondutor(escolhido);

    // mostrar condutor
    cout << endl << "Servico atribuido ao condutor com sucesso!" << endl;
    displayCondutor(escolhido);
    cout << endl;
}

void menuOptHandler(int opt){
    switch (opt) {
        case 1: gerirLinhas();
            break;
        case 2: gerirCondutores();
            break;
        case 3: visualizarTabelaComHorarioDeUmaParagem();
            break;
        case 4: verHorariosDeUmaLinha();
            break;
        case 5: visualizarTrabalhoDeUmCondutor();
            break;
        case 6:
            visualizarInformacaoAutocarro();
            break;
        case 7: inquirirLinhasDeDeterminadaParagem();
            break;
        case 8: calcularMostrarPercursoEntreParagens();
            break;
        case 9: listarCondutoresSemServicoCompletoAtribuido();
            break;
        case 10:
            listarTurnosSemCondutor();
            break;
        case 11:
            efetuarAtribuicaoDeServicoAumCondutor();
            break;
        default: break;
    }
}

void showMenu(){
    int opt;
    // salvar formatação default
    ios init(NULL);
    init.copyfmt(cout);

    cout << endl << setw(40) << setfill('#') << " MENU PRINCIPAL " << setw(30) << setfill('#') << " " << endl;

    // restaurar formatação default
    cout.copyfmt(init);

    cout << "O que deseja fazer?" << endl;
    //  opcoes
    cout << "1  -> Gerir linhas" << endl;
    cout << "2  -> Gerir condutores" << endl;
    cout << "3  -> Gerar e visualizar horários de uma paragem" << endl;
    cout << "4  -> Gerar e visualizar horário de uma linha" << endl; // TODO linha ida e volda
    cout << "5  -> Visualizar trabalho de um condutor" << endl;
    cout << "6  -> Visualizar informaçao de um autocarro" << endl;
    cout << "7  -> Pesquisar sobre quais linhas incluem determinada paragem" << endl;
    cout << "8  -> Calcular e visualizar um percurso e tempos entre duas paragens" << endl;
    cout << "9  -> Listar condutores sem serviço completo atribuido" << endl;
    cout << "10 -> Listar turnos sem condutores atribuidos" << endl;
    cout << "11 -> Efetuar atribuiçao de serviço a um condutor" << endl;
    cout << "0 -> Sair" << endl;

    //  verificar input
    if (!(cin >> opt) || opt > 11 || opt < 0) {
        cout << "Opção inválida!" << endl;
        return;
    }

    if (opt != 0) {
        menuOptHandler(opt);
        //  chama menu recursivamente
        string line;
        cout << "Tecle enter para voltar ao menu principal.." << endl;
        cin.ignore();
        getline(cin, line);
        showMenu();
    }
}
