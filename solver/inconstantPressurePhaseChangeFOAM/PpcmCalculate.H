// Calculate the inner pressure of the PCM-based heat exchangers
if(Vexpanmax*gamma_L_bar < Vpcm_death)
	P_pcm = (P0_accu-P_pcm0)*Vexpanmax*gamma_L_bar/Vpcm_death + P_pcm0;
else
{
	int elei=1;
	P_pcm = P0_accu*pow( V0_accu/(V0_accu-(Vexpanmax*gamma_L_bar-Vpcm_death)) , gamma);
	Vele = V0_accu - V0_accu*pow( P0_accu/Pele, 1/gamma ); // Calculate the amount of output oil for each power generation
	while(P_pcm > Pele)
	{
        P_pcm = P0_accu*pow( V0_accu/(V0_accu-(Vexpanmax*gamma_L_bar-Vpcm_death-Vele*elei)) , gamma);
		elei = elei + 1;
	}
}
	