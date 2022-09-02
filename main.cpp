// Classical_Logic.cpp : define o ponto de entrada para o aplicativo do console.
//Programa em desenvolvimento por Leonardo Lima da Universidade Federal Fluminense - UFF

//#include "stdafx.h"
#include <iostream>

struct Prop
{
    //Distributividade: False(não distribui) e True(distribui)
    bool subjetivo;
    bool predicativo;
    //Qualidade (True prop afirmativa e Falso prop negativa)
    bool qualidade;
    char typeProp;
};

struct TermoMedio
{
    //Distributividade do termo medio na maior e na menor
    // False(não distribui) e True(distribui)
    bool dis_maior;
    bool dis_menor;
};

class Syllogism
{
public:
    Syllogism();
    ~Syllogism();
    //Informações necessárias para avaliar um silogismo
    Prop s_maior;
    Prop s_menor;
    Prop s_conclusion;
    int s_figura;
    bool s_validade;
    TermoMedio s_medio;

    //Pegando as informações necessárias para avaliar os silogismos
    void setSyllogism(int figura, Prop maior, Prop menor, Prop conclusion)
    {
        s_maior = maior;
        s_menor = menor;
        s_conclusion = conclusion;
        s_figura = figura;
    }
    //Validade dos silogismos
    void avalicaoSyllogism()
    {
        s_validade = (avalicaoDistributividade() && avaliacaoQualidade() && avaliacaoQuantidade() && testeEspeciaisFiguras());
        printSyllogism();
    }
    bool avaliacaoQualidade()
    {
        return (regraQualiUm() && regraQualiDois() && regraQualiTres());
    }
    bool avalicaoDistributividade()
    {
        return (regraDistriUm() && regraDistriDois());
    }
    bool avaliacaoQuantidade()
    {
        return (regraQuantiUm() && regraQuantiDois());
    }

    void getTermoMedio()
    {
        //Descobrindo a distributividade do termo médio para cada figura
        switch (s_figura)
        {
            case 1: //Primeira Figura
                s_medio.dis_maior = s_maior.subjetivo;
                s_medio.dis_menor = s_menor.predicativo;
                break;
            case 2: //Segunda Figura
                s_medio.dis_maior = s_maior.predicativo;
                s_medio.dis_menor = s_menor.predicativo;
                break;
            case 3: //Terceira Figura
                s_medio.dis_maior = s_maior.subjetivo;
                s_medio.dis_menor = s_menor.subjetivo;
                break;
            case 4: //Quarta Figura
                s_medio.dis_maior = s_maior.predicativo;
                s_medio.dis_menor = s_menor.subjetivo;
                break;
        }
    }

    //D1: O termo médio tem de estar distribuído ao menos uma vez
    bool regraDistriUm()
    {
        return (s_medio.dis_maior || s_medio.dis_menor);
    }
    //D2: Um termo não pode estar distribuido na conclusão sem antes estar distribuido nas premissas
    bool regraDistriDois()
    {
        switch (s_figura)
        {
            case 1:
                if (s_conclusion.subjetivo && s_conclusion.predicativo)
                {
                    return ((s_menor.subjetivo && s_conclusion.subjetivo) && (s_maior.predicativo && s_conclusion.predicativo));
                }
                else if (s_conclusion.subjetivo && (!s_conclusion.predicativo))
                {
                    return (s_menor.subjetivo && s_conclusion.subjetivo);
                }
                else if ((!s_conclusion.subjetivo) && s_conclusion.predicativo)
                {
                    return (s_maior.predicativo && s_conclusion.predicativo);
                }
                else if ((!s_conclusion.subjetivo) && (!s_conclusion.predicativo))
                {
                    return true;
                }
                else{break;}
            case 2:
                if (s_conclusion.subjetivo && s_conclusion.predicativo)
                {
                    return ((s_menor.subjetivo && s_conclusion.subjetivo) && (s_maior.subjetivo && s_conclusion.predicativo));
                }
                else if (s_conclusion.subjetivo && (!s_conclusion.predicativo))
                {
                    return (s_menor.subjetivo && s_conclusion.subjetivo);
                }
                else if ((!s_conclusion.subjetivo) && s_conclusion.predicativo)
                {
                    return (s_maior.subjetivo && s_conclusion.predicativo);
                }
                else if ((!s_conclusion.subjetivo) && (!s_conclusion.predicativo))
                {
                    return true;
                }
                else { break; }
            case 3:
                if (s_conclusion.subjetivo && s_conclusion.predicativo)
                {
                    return ((s_menor.predicativo && s_conclusion.subjetivo) && (s_maior.predicativo && s_conclusion.predicativo));
                }
                else if (s_conclusion.subjetivo && (!s_conclusion.predicativo))
                {
                    return (s_menor.predicativo && s_conclusion.subjetivo);
                }
                else if ((!s_conclusion.subjetivo) && s_conclusion.predicativo)
                {
                    return (s_maior.predicativo && s_conclusion.predicativo);
                }
                else if ((!s_conclusion.subjetivo) && (!s_conclusion.predicativo))
                {
                    return true;
                }
                else { break; }
            case 4:
                if (s_conclusion.subjetivo && s_conclusion.predicativo)
                {
                    return ((s_menor.predicativo && s_conclusion.subjetivo) && (s_maior.subjetivo && s_conclusion.predicativo));
                }
                else if (s_conclusion.subjetivo && (!s_conclusion.predicativo))
                {
                    return (s_menor.predicativo && s_conclusion.subjetivo);
                }
                else if ((!s_conclusion.subjetivo) && s_conclusion.predicativo)
                {
                    return (s_maior.subjetivo && s_conclusion.predicativo);
                }
                else if ((!s_conclusion.subjetivo) && (!s_conclusion.predicativo))
                {
                    return true;
                }
                else { break; }
        }
    }

    //QL1: Ao menos uma das premissas deve ser afirmativa
    bool regraQualiUm()
    {
        return (s_maior.qualidade || s_menor.qualidade);
    }
    //QL2: Se uma das premissas for negativa, a conclusão deve ser negativa.
    bool regraQualiDois()
    {
        if (s_maior.qualidade && s_menor.qualidade)
        {
            return true;
        }
        else
        {
            return (!s_conclusion.qualidade);
        }
    }
    //QL3: Se ambas as premissas forem afirmativas, a conclusao deve ser afirmativa.
    bool regraQualiTres()
    {
        if (s_maior.qualidade && s_menor.qualidade)
        {
            //O "verdade" vem da condicional que precede. Evitamos escrever o condicional novamente.
            return (s_conclusion.qualidade) ? true : false;
        }
        else
        {
            return true;
        }
    }

    //QT1: Ao menos uma das premissas deve ser universal.
    bool regraQuantiUm()
    {
        return (s_maior.subjetivo || s_menor.subjetivo);
    }
    //QT2: Se uma das premissas for particular, a conclusão deve ser particular
    bool regraQuantiDois()
    {
        if (s_maior.subjetivo && s_menor.subjetivo)
        {
            //O "verdade" vem da condicional que precede. Evitamos escrever o condicional novamente.
            return true;
        }
        else
        {
            return (s_conclusion.subjetivo) ? false : true;
        }
    }
    //Função para expor o resultado
    void printSyllogism()
    {
        std::cout << "O silogismo eh : " << s_figura << "-" << s_maior.typeProp << " " << s_menor.typeProp << " " <<
                  s_conclusion.typeProp;

        if (s_validade)
        {
            std::cout << "  valido ";
        }
        else
        {
            std::cout << "  invalido ";
        }
    }

    void getSyll(int figura, int maior, int menor, int conclusao)
    {
        //Proposições Categóricas:
        Prop type_A = { true, false, true , 'A' };
        Prop type_E = { true, true, false , 'E' };
        Prop type_I = { false, false, true, 'I' };
        Prop type_O = { false, true, false, 'O' };

        Prop p_maior;
        Prop p_menor;
        Prop p_conclusao;
        //Para definir a proposição maior
        switch (maior)
        {
            case 0: p_maior = type_A;
                break;
            case 1: p_maior = type_E;
                break;
            case 2: p_maior = type_I;
                break;
            case 3: p_maior = type_O;
                break;
        }
        //Para definir a proposição menor
        switch (menor)
        {
            case 0: p_menor = type_A;
                break;
            case 1: p_menor = type_E;
                break;
            case 2: p_menor = type_I;
                break;
            case 3: p_menor = type_O;
                break;
        }
        //Para definir a conclusão
        switch (conclusao)
        {
            case 0: p_conclusao = type_A;
                break;
            case 1: p_conclusao = type_E;
                break;
            case 2: p_conclusao = type_I;
                break;
            case 3: p_conclusao = type_O;
                break;
        }
        //Criando o silogismo
        setSyllogism(figura+1, p_maior, p_menor, p_conclusao);

    }
    //Testes especificos das figuras
    bool testeEspeciaisFiguras()
    {
        switch (s_figura)
        {
            case 1: return (testeFUmEDois() && testeFUmDois());
            case 2: return (testeFUmEDois() && testeFDoisDois());
            case 3: return (testeFTres() && testeFTresDois());
            case 4: return (testeFQuatroUm() && testeFQuatroDois() && testeFQuatroTres());
            default: return false;
        }
    }
    //F1.1 e F2.1: A premissa maior deve ser universal.
    bool testeFUmEDois()
    {
        return s_maior.subjetivo;
    }
    //F1.2: A premissa menor tem que ser afirmativa.
    bool testeFUmDois()
    {
        return s_menor.qualidade;
    }
    //F2.2: As premissas devem expressar diferentes qualidades.
    bool testeFDoisDois()
    {
        return (s_maior.qualidade != s_menor.qualidade);
    }
    //F3.1: A premissa menor deve ser afirmativa.
    bool testeFTres()
    {
        return s_menor.qualidade;
    }
    //F3.2: A conclusão deve ser particular.
    bool testeFTresDois()
    {
        return (!s_conclusion.subjetivo);
    }
    //F4.1: Se a maior for afirmativa, a menor deve ser universal.
    bool testeFQuatroUm()
    {
        return	(s_maior.qualidade)? s_menor.subjetivo: true;
    }
    //F4.2: Se a menor for afirmativa, a conclusão deve ser particular.
    bool testeFQuatroDois()
    {
        return (s_menor.qualidade) ? (!s_conclusion.subjetivo) : true;
    }
    //F4.3: Se uma das premissas for negativa, a maior será universal.
    bool testeFQuatroTres()
    {
        return (s_menor.qualidade && s_maior.qualidade) ? true : s_maior.subjetivo;
    }


private:
};



Syllogism::Syllogism()
{
}

Syllogism::~Syllogism()
{
}

int main()
{
    int numeroLoop = 0; //Variável para facilitar o reconhecimento dos silogismos

    //Gerando os silogismos
    for (int i = 0; i < 4; i++)//Figuras
    {
        for (int z = 0; z < 4; z++)//Proposição Maior
        {
            for (int x = 0; x < 4; x++)//Proposição Menor
            {
                for (int y = 0; y < 4; y++)//Proposição da Conclusão
                {
                    Syllogism syll;
                    syll.getSyll(i, z, x, y);
                    syll.getTermoMedio();
                    syll.avalicaoSyllogism();
                    numeroLoop++;
                    std::cout << numeroLoop << " \n";
                }
            }

        }
    }

    return 0;
}
