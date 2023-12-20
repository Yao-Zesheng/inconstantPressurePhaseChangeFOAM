    // Solve the current average volume liquid fraction of the PCM
    gamma_L_bar = 0;
	V_sum = 0;
	count = 0;
	forAll(mesh.C(), cellid) 
	    {
            gamma_L_bar += gamma_L[cellid]*mesh.V()[cellid];
			V_sum += mesh.V()[cellid];
            count++;
        }
    gamma_L_bar /= V_sum;