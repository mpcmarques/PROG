#include "Condutor.hpp"

Condutor::Condutor(){}

Condutor::Condutor(int uid, std::string nome, int turno, int horasPorSemana, int descanso){
  this->uid = uid;
  this->nome = nome;
  this->turnoMax = turno;
  this->horasPorSemana = horasPorSemana;
  this->descanso = descanso;
}

bool Condutor::podeRealizarTurno(Turno turno) {
    // verificar se o turno esta dentro do horario de trabalho permitido e pode ser incluido nas horas semanais restantes
    if (turno.getTempoTotalEmMinutos() < (getTurnoMax() * 60) &&
        getMinutosSemanaisRestantes() - turno.getTempoTotalEmMinutos() >= 0) {
        // verificar se o ultimo turno do condutor mais o tempo de descanso e menor que o tempo inicial do turno
        // a ser adicionado
        for (Turno turnosAdquiridos: getTurnos()) {
            int tempoFinalNaoPermitido = turnosAdquiridos.getTempoFim() + getDescanso() * 60;

            // se um dos tempos + tempo de descanso passar o tempo de inicio, nao pode ser adicionado
            if (tempoFinalNaoPermitido > turno.getTempoInicio() && tempoFinalNaoPermitido < turno.getTempoFim()) {
                return false;
            }
        }
        return true;
    }
    return false;
}

int Condutor::getMinutosSemanaisRestantes() {
    int minutosSemanaisRestantes = 60 * horasPorSemana;
    for (Turno turno: turnos) {
        minutosSemanaisRestantes -= turno.getTempoTotalEmMinutos();
    }
    return minutosSemanaisRestantes;
}

std::vector<Turno> Condutor::getTurnos(){
  return this->turnos;
}

void Condutor::addTurno(Turno turno){
  this->turnos.push_back(turno);
}

std::string Condutor::getNome(){
   return nome;
 }
int Condutor::getUid(){
  return uid;
}
int Condutor::getTurnoMax(){
  return turnoMax;
}
int Condutor::getDescanso(){
  return descanso;
}
int Condutor::getHorasPorSemana(){
  return horasPorSemana;
}

std::istream& operator>>(std::istream &is, Condutor &condutor){
  std::string str;
  std::string nome;
  std::string sobrenome;

  is >> condutor.uid >> str >> nome >> sobrenome >> str >> condutor.turnoMax;
  is >> str >> condutor.horasPorSemana >> str >> condutor.descanso;

  condutor.nome = nome + " " + sobrenome;

  return is;
}

std::ostream& operator<<(std::ostream &os, Condutor &condutor){
  os << condutor.uid << " ; ";
  os << condutor.nome << " ; ";
  os << condutor.turnoMax << " ; ";
  os << condutor.horasPorSemana << " ; ";
  os << condutor.descanso;

  return os;
}

void Condutor::setTurnoMax(int turnoMax) {
  Condutor::turnoMax = turnoMax;
}

void Condutor::setHorasPorSemana(int horasPorSemana) {
  Condutor::horasPorSemana = horasPorSemana;
}

void Condutor::setDescanso(int descanso) {
  Condutor::descanso = descanso;
}

void Condutor::setNome(const std::string &nome) {
  Condutor::nome = nome;
}

