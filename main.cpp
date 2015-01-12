#include <iostream>

using namespace std;
const int dim=4;
char mat1[dim][dim];
char mat2[dim][dim];

void clean()
{
    for(int i=0;i<dim;i++)
        for (int j=0;j<dim;j++)
            mat1[i][j]=' ';

    for(int i=0;i<dim;i++)
        for (int j=0;j<dim;j++)
            mat2[i][j]=' ';
}

void inserisci(string parola)
{
    int c=0;

    //inserimento diagonale sx verso dx
    for(int n=0;n<dim;n++)
    {
        mat1[n][n]=parola[c];
        c++;
    }

    //inserimento diagonale dx verso sx

    for(int i=dim-1;i>=0;i--)
    {
        for(int j=0;j<dim;j++)
        {
            mat2[i][j]=parola[c];
            //cout<<"-"<<parola[c]<<"-";
            c++;
        }
    }
}

void stampa()
{
    for(int i=0;i<dim;i++)
    {
        for(int j=0;j<dim;j++)
            cout<<mat1[i][j];

        cout<<endl;
    }
}

string lettura(int pos)
{
    string ret;
    char n=mat1[pos][pos];

    if(pos==0)
        return ret.append(n,mat2[0][3]);

    if(pos==1)
        return ret.append(n,mat2[1][2]);

    if(pos==2)
        return ret.append(n,mat2[2][1]);

    if(pos==3)
        return ret.append(n,mat2[3][0]);
}

int main()
{
    string frase;

    //variabili dedicate alla lettura delle righe
    string r0="";
    string r1="";
    string r2="";
    string r3="";

    cout<<"Inserisci la frase: ";
    cin>>frase;

    int pos=0;
    for(int i=0;i<=frase.length();i=i+8)
    {
        clean();
        string app="";
        for(int j=pos;j<pos+8;j++)
        {
            app=app+frase[j];
        }

        //cout<<"-"<<app<<"-";
        inserisci(app);
        stampa();

        r0.append(lettura(0));
        r1.append(lettura(1));
        r2.append(lettura(2));
        r3.append(lettura(3));

        //passo alle 8 lettere successive
        pos=pos+8;
    }

    cout<<"Il testp cifrato sara': "<<r0<<r1<<r2<<r3;
    return 0;
}
