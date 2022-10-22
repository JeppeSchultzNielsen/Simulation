#include <iostream>
#include <string>
#include <TFile.h>
#include <fstream>
#include <TTree.h>

using namespace::std;

int main() {
    string filename = "build/output8He9670Width100k.root";
    unique_ptr<TFile> myFile(TFile::Open(filename.c_str()));
    //Hent træet
    TTree *t = (TTree *) myFile->Get("Scoring");
    auto entries = t -> GetEntries();
    cout << entries << endl;
    double_t Li7E;
    double_t gammaE;
    double_t neutronE;
    double_t tritonE;
    double_t alphaE;
    t->SetBranchAddress("Li7E", &Li7E);
    t->SetBranchAddress("GammaE", &gammaE);
    t->SetBranchAddress("NeutronE", &neutronE);
    t->SetBranchAddress("TritonE", &tritonE);
    t->SetBranchAddress("AlphaE", &alphaE);

    double_t totE;

    ofstream mytxt("Fynboplotter/fynbo9670txt.txt");

    for(int i = 0; i < entries; i++){
        t ->GetEntry(i);
        if(Li7E == 0){
            //decay was triton or beta-decay to excited state in 8Be
            if(neutronE == 0){
                //decay ended in double alpha decay of 8Be
            }
            else{
                //decay was triton decay
                totE = neutronE + tritonE + alphaE + 4498.7;
                mytxt << totE << "\t" << neutronE << endl;
                mytxt << totE << "\t" << tritonE << endl;
                mytxt << totE << "\t" << alphaE << endl;
            }
        }
        else{
            //decay was to Li7 state
            totE = Li7E + neutronE + gammaE + 2030;
            mytxt << totE << "\t" << neutronE << endl;
            mytxt << totE << "\t" << Li7E << endl;
            if(gammaE > 0){
                mytxt << totE << "\t" << gammaE << endl;
            }
        }
        totE = 0;
    }
    mytxt.close();
}
