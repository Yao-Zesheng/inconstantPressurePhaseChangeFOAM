{
    int iter = 0;
    scalar residual = 1;
    int iter_P = 0;
    double gamma_L_bar;
	double V_sum;
	int count;
	do
    {
		iter_P++;
		#include "gammaAveCalculate.H"
		#include "PpcmCalculate.H"
		T_S = TP_kS*(P_pcm-PRef)+TPRefS;
		T_L = TP_kL*(P_pcm-PRef)+TPRefL;
		P_pcm_pre = P_pcm;
		#include "TLoop.H"
		#include "gammaAveCalculate.H"
		#include "PpcmCalculate.H"
		residual_P = mag((P_pcm - P_pcm_pre)/P_pcm_pre);
		Info <<"Iteration process for solving the heat exchanger pressure: residual_P = "<< residual_P <<endl;
    }while ((iter < 1 || residual_P > residual_Pmin ) && iter_P <= 5);
	

    rhok = (rho_La
            +rho_Lb*max(T-TRef_rho_L,TRef_rho_L*scalar(0))
            +rho_Lc*pow(max(T-TRef_rho_L,TRef_rho_L*scalar(0)),2)
            +rho_Ld*pow(max(T-TRef_rho_L,TRef_rho_L*scalar(0)),2.5)
            +rho_Le*pow(max(T-TRef_rho_L,TRef_rho_L*scalar(0)),3))/rho_La;

    nu = 1/(nua+nub*T+nuc*pow(T-TRef_nu,2));
    DarcyTerm = DarcyConstant*pow(scalar(1)-gamma_L,2)/(pow(gamma_L,3)+DarcyTerm_epsilon);
    
	#include "gammaAveCalculate.H"
    Info <<"gamma_L_Ave = "<< gamma_L_bar <<endl;
	Info <<"residual_P = "<< residual_P <<endl;
	Info <<"T_s = "<< T_S <<endl;
	Info <<"P_pcm = "<< P_pcm <<endl;
	if(residual_P<residual_Pmin) Info <<"Convergence" << endl;
	else Info <<"Calculation not converging."<<endl;
}
