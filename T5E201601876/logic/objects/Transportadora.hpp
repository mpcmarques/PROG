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

class Transportadora {
private:
    vector<Linha> linhas;
    vector<Condutor> condutores;
    vector<Turno> turnos;
    vector<Autocarro> autocarros;
    int TEMPO_INICIO = 8 * 60;
    int TEMPO_FIM = 22 * 60 - 1;

    // funcoes private
    void atribuirServicoAosCondutores();
    void criarAutocarros();

public:
    Transportadora();

    Transportadora(std::vector<Linha> linhas, std::vector<Condutor>);

    void removerCondutor(int opt);

    void removerLinha(int opt);

    void removerAutocarro(int linhaId, int ordemNaLinha);

    void addLinha(const Linha linha);

    void addCondutor(const Condutor condutor);

    void addAutocarro(const Autocarro autocarro);

    const vector<Turno> getTurnosNaoAtribuidos();

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
