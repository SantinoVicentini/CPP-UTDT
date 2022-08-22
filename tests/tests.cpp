#include "../Wordle/funciones.h"
#include <vector>
#include <string>
#include <gtest/gtest.h>

TEST(WordleTests, ListadoVacio){
    std::string filename = "../tests/listado_test_vacio.txt";
    std::vector<std::string> listado = cargar_listado(filename);
    ASSERT_TRUE(listado.empty());
}

TEST(WordleTests, ListadoLleno){
    std::string filename = "../tests/listado_test_lleno.txt";
    std::vector<std::string> listado = cargar_listado(filename);
    std::vector<std::string> listado_esperado = {"aviso", "banco", "bolsa", "buzon", "cajon"};
    ASSERT_EQ(listado, listado_esperado);
}

TEST(WordleTests, IntentoValidoValido){
    std::vector<std::string> listado = {"aviso", "banco", "bolsa", "buzon", "cajon"};
    std::string palabra_secreta = "bolsa";
    std::string intento = "aviso";
    ASSERT_TRUE(intento_valido(intento, palabra_secreta, listado));
}

TEST(WordleTests, IntentoValidoTamanioInvalido){
    std::vector<std::string> listado = {"aviso", "banco", "bolsa", "buzon", "cajon"};
    std::string palabra_secreta = "bolsa";
    std::string intento = "persona";
    ASSERT_FALSE(intento_valido(intento, palabra_secreta, listado));
}

TEST(WordleTests, IntentoValidoPalabraNoEnListado){
    std::vector<std::string> listado = {"aviso", "banco", "bolsa", "buzon", "cajon"};
    std::string palabra_secreta = "bolsa";
    std::string intento = "rueda";
    ASSERT_FALSE(intento_valido(intento, palabra_secreta, listado));
}

TEST(WordleTests, EvaluarIntento1){
    std::string palabra_secreta = "bolsa";
    std::string intento = "aviso";
    std::vector<EstadoLetra> respuesta_esperada = {EstadoLetra::LugarIncorrecto, EstadoLetra::NoPresente, 
        EstadoLetra::NoPresente, EstadoLetra::LugarCorrecto, EstadoLetra::LugarIncorrecto};

    ASSERT_EQ(evaluar_intento(intento, palabra_secreta), respuesta_esperada);
}

TEST(WordleTests, EvaluarIntento2){
    std::string palabra_secreta = "melon";
    std::string intento = "bolsa";
    std::vector<EstadoLetra> respuesta_esperada = {EstadoLetra::NoPresente, EstadoLetra::LugarIncorrecto, 
        EstadoLetra::LugarCorrecto, EstadoLetra::NoPresente, EstadoLetra::NoPresente};

    ASSERT_EQ(evaluar_intento(intento, palabra_secreta), respuesta_esperada);
}

TEST(WordleTests, EvaluarIntentoTodoNoPresente){
    std::string palabra_secreta = "melon";
    std::string intento = "varas";
    std::vector<EstadoLetra> respuesta_esperada = {EstadoLetra::NoPresente, EstadoLetra::NoPresente, 
        EstadoLetra::NoPresente, EstadoLetra::NoPresente, EstadoLetra::NoPresente};

    ASSERT_EQ(evaluar_intento(intento, palabra_secreta), respuesta_esperada);
}

TEST(WordleTests, EvaluarIntentoTodoCorrecto){
    std::string palabra_secreta = "bolsa";
    std::string intento = "bolsa";
    std::vector<EstadoLetra> respuesta_esperada = {EstadoLetra::LugarCorrecto, EstadoLetra::LugarCorrecto, 
        EstadoLetra::LugarCorrecto, EstadoLetra::LugarCorrecto, EstadoLetra::LugarCorrecto};

    ASSERT_EQ(evaluar_intento(intento, palabra_secreta), respuesta_esperada);
}

TEST(WordleTests, EvaluarIntentoTodoLugarIncorrecto){
    std::string palabra_secreta = "bolsa";
    std::string intento = "olsab";
    std::vector<EstadoLetra> respuesta_esperada = {EstadoLetra::LugarIncorrecto, EstadoLetra::LugarIncorrecto, 
        EstadoLetra::LugarIncorrecto, EstadoLetra::LugarIncorrecto, EstadoLetra::LugarIncorrecto};

    ASSERT_EQ(evaluar_intento(intento, palabra_secreta), respuesta_esperada);
}

TEST(WordleTests, RespuestaEnStr1){
    std::vector<EstadoLetra> respuesta = {EstadoLetra::LugarIncorrecto, EstadoLetra::NoPresente, 
        EstadoLetra::NoPresente, EstadoLetra::LugarCorrecto, EstadoLetra::LugarIncorrecto};
    std::string respuesta_str = "-XX+-";

    ASSERT_EQ(respuesta_en_string(respuesta), respuesta_str);
}

TEST(WordleTests, RespuestaEnStr2){
    std::vector<EstadoLetra> respuesta = {EstadoLetra::NoPresente, EstadoLetra::LugarIncorrecto, 
        EstadoLetra::LugarCorrecto, EstadoLetra::NoPresente, EstadoLetra::NoPresente};
    std::string respuesta_str = "X-+XX";

    ASSERT_EQ(respuesta_en_string(respuesta), respuesta_str);
}

TEST(WordleTests, RespuestaEnStrTodoNoPresente){
    std::vector<EstadoLetra> respuesta = {EstadoLetra::NoPresente, EstadoLetra::NoPresente, 
        EstadoLetra::NoPresente, EstadoLetra::NoPresente, EstadoLetra::NoPresente};
    std::string respuesta_str = "XXXXX";

    ASSERT_EQ(respuesta_en_string(respuesta), respuesta_str);
}

TEST(WordleTests, RespuestaEnStrTodoCorrecto){
    std::vector<EstadoLetra> respuesta = {EstadoLetra::LugarCorrecto, EstadoLetra::LugarCorrecto, 
        EstadoLetra::LugarCorrecto, EstadoLetra::LugarCorrecto, EstadoLetra::LugarCorrecto};
    std::string respuesta_str = "+++++";

    ASSERT_EQ(respuesta_en_string(respuesta), respuesta_str);
}

TEST(WordleTests, RespuestaEnStrTodoLugarIncorrecto){
    std::vector<EstadoLetra> respuesta = {EstadoLetra::LugarIncorrecto, EstadoLetra::LugarIncorrecto, 
        EstadoLetra::LugarIncorrecto, EstadoLetra::LugarIncorrecto, EstadoLetra::LugarIncorrecto};
    std::string respuesta_str = "-----";

    ASSERT_EQ(respuesta_en_string(respuesta), respuesta_str);
}