#ifndef COMMONDEF_H
#define COMMONDEF_H
#include <QString>
#include <QVector>

struct InputMF_t
{
    // name="MF1l" type="Triangular" P1="1" P2="2" P3="3" P4="4" maximum="0.9"
    QString sName;
    QString sType;
    double dP1;
    double dP2;
    double dP3;
    double dP4;
    double dMaximum;
};

struct OutputMF_t
{
    QString sName;
    QString sType;
    double dP1;
    double dP2;
    double dP3;
    double dP4;
    double dMaximum;
    QString sTSKCoefficients;
};

struct Rule_t
{
    QString sAntecedent;
    QString sConsequent;
    QString sInference;
    double dWeight;
};

struct InputData_t
{
    QString sName;
    QString sRange;
    QVector<InputMF_t> vstMF;
};

struct OutputData_t
{
    QString sName;
    QString sRange;
    QVector<OutputMF_t> vstMF;
};


struct MainWindow_t
{
    QString               sFLSName;
    bool                  bType1;//aSetID 0 type1 ---1 was Interval type2
    bool                  bInterval2;
    bool                  bTSK;
    bool                  bMamdani;
    int                   nNumberOfInputs;//_numInputs //_numofMFs we didnt save on the gui(i need to perhaps use qt functionalities to get it)
    int                   nNumberOFOutputs;
    int                   nNumberOfRules;
    QString               sProcessingMethod;//UB
    QString               sAndMethod;
    QString               sOrMethod;
    QString               sAggMethod;
    QString               sImplicationMethod;

    QVector<InputData_t>  vstInputs;
    QVector<OutputData_t> vstOutputs;
    QVector<Rule_t>       vstRules;
};

#endif // COMMONDEF_H


















