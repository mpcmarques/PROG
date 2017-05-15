//
//  Transportadora.hpp
//  PROG
//
//  Created by Mateus Pedroza on 14/04/17.
//  Copyright © 2017 Mateus Pedroza. All rights reserved.

#ifndef Transportadora_h
#define Transportadora_h

#include "Linha.hpp"
#include "Condutor.hpp"

using namespace std;

/**
 * Classe representa a transportadora
 */
class Transportadora {
private:
    vector<Linha> linhas;
    vector<Condutor> condutores;
    vector<Turno> turnos;
    vector<Autocarro> autocarros;
    int TEMPO_INICIO = 8 * 60;

    // funcoes private
    void atribuirServicoAosCondutores();

    void criarAutocarros();

public:
    Transportadora();

    /**
     * Construtor da transportadora
     * @param linhas Linhas da transportadora
     * @param condutores Condutores da transportadora
     */
    Transportadora(std::vector<Linha> linhas, std::vector<Condutor> condutores);

    /**
     * Remove o condutor no indice
     * @param opt Indice
     */
    void removerCondutor(int opt);

    /**
     * Remove a linha no indice
     * @param opt Indice
     */
    void removerLinha(int opt);

    /**
     * Remove um autocarro
     * @param linhaId Linha do autocarro a ser removido
     * @param ordemNaLinha Num ordem do autocarro a ser removido
     */
    void removerAutocarro(int linhaId, int ordemNaLinha);

    /**
     * Adiciona uma linha
     * @param linha Linha a ser adicionada
     */
    void addLinha(const Linha linha);

    /**
     * Adiciona um condutor
     * @param condutor Condutor a ser adicionado
     */
    void addCondutor(const Condutor condutor);

    /**
     * Adiciona um autocarro
     * @param autocarro Autocarro a ser adicionado
     */
    void addAutocarro(const Autocarro autocarro);

    /**
     * @param condutor Condutor a ser pesquisado
     * @return Os turnos disponiveis ao condutor
     */
    vector<Turno> getTurnosDisponiveisACondutor(Condutor condutor);

    /**
     * Atribui servico a um condutor
     * @param condutor Condutor a ser atribuido servico
     * @param turno Turno a ser atribuido a condutor
     */
    void atribuirServicoAoCondutor(Condutor &condutor, Turno turno);

    /**
     * Retorna os turnos nao atribuidos
     * @return Turnos nao atribuidos
     */
    const vector<Turno> getTurnosNaoAtribuidos();

    /**
     * Retorna as linhas que contem a paragem
     * @param nome Nome da paragem
     * @return Linhas que contem a paragem
     */
    vector<Linha> getLinhasComParagem(string nome);

    //  getters
    // const Autocarro getAutocarro(int linhaId, int ordemNaLinha);
    std::vector<Condutor> getCondutores();

    std::vector<Linha> getLinhas();

    vector<Condutor> getCondutoresSemServicoAtribuidos();

    const vector<Turno> &getTurnos() const;

    const vector<Autocarro> &getAutocarros() const;

    const Autocarro getAutocarro(int linhaId, int ordemNaLinha) const;

    const Linha getLinha(int linhaId) const;

    // setteers
    void setLinhas(const vector<Linha> &linhas);

    void setCondutores(const vector<Condutor> &condutores);

    void setTurnos(const vector<Turno> &turnos);

    void setAutocarros(const vector<Autocarro> &autocarros);
};


#endif /* Transportadora_h */
