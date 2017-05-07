//
//  Transportadora.cpp
//  PROG
//
//  Created by Mateus Pedroza on 14/04/17.
//  Copyright © 2017 Mateus Pedroza. All rights reserved.
//

#include "Transportadora.hpp"

Transportadora::Transportadora(vector<Linha> linhas, vector<Condutor> condutores){
        this->linhas = linhas;
        this->condutores = condutores;
        // cria autocarros
        criarAutocarros();
        // atribui servico aos condutores
        atribuirServicoAosCondutores();
}

Transportadora::Transportadora(){
        this->linhas = vector<Linha>();
        this->condutores = vector<Condutor>();
}

void findTurnoNaoAtribuido(vector<Autocarro> autocarros,Turno &turno){
        for (Autocarro autocarro : autocarros) {
                if (autocarro.getProgramacao().size() > 0) {
                        turno = autocarro.getProgramacao()[0];
                }
        }
}

const vector<Turno> Transportadora::getTurnosNaoAtribuidos(){
        vector<Turno> turnosNaoAtribuidos;

        for (Autocarro autocarro : autocarros) {
                for (Turno turno : autocarro.getProgramacao()) {
                        if (turno.getCondutorId() == -1) {
                                turnosNaoAtribuidos.push_back(turno);
                        }
                }
        }
        return turnosNaoAtribuidos;
}
/*
const Autocarro Transportadora::getAutocarro(int linhaId, int ordemNaLinha){
        for (Autocarro autocarro : autocarros) {
                if (autocarro.getLinhaId() == linhaId && autocarro.getOrdemNaLinha() == ordemNaLinha) {
                        return autocarro;
                }
        }
        return Autocarro(0, 0, 0);
}*/


void Transportadora::atribuirServicoAosCondutores(){
        vector<Turno> turnosNaoAtribuidos = getTurnosNaoAtribuidos();

        // a medida que vai atribuindo servico aos condutores vai removendo os turnos
        // dos autocarros que vao sendo servidos.
        for (Condutor& condutor : this->condutores) {
                int minutosSemanaisRestantes = 60*condutor.getHorasPorSemana();

                // loop dos turnos, para tentar adicionar os turnos ao condutor
                for (Turno turnoNaoAtribuido : turnosNaoAtribuidos) {

                        // verificar se o condutor possui tempo semanal
                        if (minutosSemanaisRestantes - turnoNaoAtribuido.getTempoTotalEmMinutos() > 0) {
                                // verificar se o condutor ja tem algum servico
                                if (condutor.getTurnos().empty()) {
                                        // adicionar o servico ao condutor
                                        turnoNaoAtribuido.setCondutorUID(condutor.getUid());
                                        condutor.addTurno(turnoNaoAtribuido);

                                        // apagar turno da lista de turnos nao atribuidos
                                        turnosNaoAtribuidos.erase(turnosNaoAtribuidos.begin());

                                        // remover minutos semanais restantes
                                        minutosSemanaisRestantes -= turnoNaoAtribuido.getTempoTotalEmMinutos();
                                } else {
                                        // condutor ja tem algum servico
                                        // verificar se o tempo do fim do ultimo servico + descanso em minutos é menor que a data do turno nao atribuido
                                        if (condutor.getTurnos().back().getTempoFim() + (condutor.getDescanso()*60) <  turnoNaoAtribuido.getTempoInicio()) {
                                                // adicionar o servico ao condutor
                                                turnoNaoAtribuido.setCondutorUID(condutor.getUid());
                                                condutor.addTurno(turnoNaoAtribuido);

                                                // apagar turno da lista de turnos nao atribuidos
                                                turnosNaoAtribuidos.erase(turnosNaoAtribuidos.begin());

                                                // remover minutos semanais restantes
                                                minutosSemanaisRestantes -= turnoNaoAtribuido.getTempoTotalEmMinutos();
                                        }
                                }
                        } else {
                                // condutor nao possui tempo semanal
                        }
                }
                cout << "Carregado " << condutor.getTurnos().size() << " turnos" << endl;
        }
}

void Transportadora::criarAutocarros(){
        vector<Autocarro> autocarros;

        // loop linhas
        for(Linha linha : getLinhas()) {
                int ordemNaLinha = 1;

                // para cada autocarro necessario
                for(int i = 0; i < linha.getNumeroAutocarrosNecessarios(); i++) { // loop autocarros necessarios

                        // criar autocarro
                        Autocarro autocarro = Autocarro(linha.getUid(), -1, ordemNaLinha);

                        // tempo de inicio do turno
                        int tempoInicioSemanal = TEMPO_INICIO;
                        // criar um turno por dia da semana
                        for (int i = 0; i < 7; i++) {
                                // adicionar minutos de acordo com a ordem na linha
                                int tempoInicioTurno = tempoInicioSemanal;
                                tempoInicioTurno += (ordemNaLinha-1) * linha.getFreq();

                                // tempo do fim do turno
                                int tempoFimTurno = tempoInicioTurno;
                                tempoFimTurno += (linha.getTempoPercurso()*2);

                                // criar objeto
                                Turno turno = Turno(linha.getUid(), -1, ordemNaLinha, tempoInicioTurno, tempoFimTurno);
                                // adicionar ao autocarro
                                autocarro.addTurno(turno);

                                // adicionar um dia ao tempo semanal
                                tempoInicioSemanal += 24*60;
                        }
                        // adicionar na lista
                        autocarros.push_back(autocarro);

                        // acrescentar num na linha
                        ordemNaLinha++;
                }
        }
        // adicionar autocarros a transportadora
        this->autocarros = autocarros;
}

vector<Linha> Transportadora::getLinhasComParagem(string nome){
        vector<Linha> foundLinhas;

        for (Linha linha : this->linhas) {
                for(Paragem paragem : linha.getParagens()) {
                        if (paragem.getNome() == nome) {
                                foundLinhas.push_back(linha);
                        }
                }
        }
        return foundLinhas;
}

void Transportadora::addLinha(const Linha linha){
        this->linhas.push_back(linha);
}

void Transportadora::addCondutor(const Condutor condutor){
        this->condutores.push_back(condutor);
}

void Transportadora::removerLinha(int opt){
        this->linhas.erase(linhas.begin() + opt);
}

void Transportadora::removerCondutor(int opt){
        this->condutores.erase(condutores.begin() + opt);
}

vector<Condutor> Transportadora::getCondutores(){
        return this->condutores;
}

vector<Linha> Transportadora::getLinhas(){
        return this->linhas;
}
