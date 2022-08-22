#ifndef SOLUCION_H
#define SOLUCION_H

#include<vector>
#include<string>

enum class EstadoLetra { LugarCorrecto, LugarIncorrecto, NoPresente };

std::vector<std::string> cargar_listado(const std::string & nombre_archivo);

bool intento_valido(const std::string &  intento, const std::string &  palabra_secreta, const std::vector<std::string> &listado);

std::vector<EstadoLetra> evaluar_intento(const std::string &  intento, const std::string &  palabra_secreta);

std::string respuesta_en_string(const std::vector<EstadoLetra> & respuesta);

#endif