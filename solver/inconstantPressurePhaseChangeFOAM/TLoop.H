// Solving the energy equation

iter = 0;
do
    {
        iter++;
        gamma_L.storePrevIter();

        // mixture density
        rhomix=gamma_L*(rho_La
                        +rho_Lb*max(T-TRef_rho_L,TRef_rho_L*scalar(0))
                        +rho_Lc*pow(max(T-TRef_rho_L,TRef_rho_L*scalar(0)),2)
                        +rho_Ld*pow(max(T-TRef_rho_L,TRef_rho_L*scalar(0)),2.5)
                        +rho_Le*pow(max(T-TRef_rho_L,TRef_rho_L*scalar(0)),3))
                +(scalar(1)-gamma_L)*(rho_Sa
                                      +rho_Sb*(T-TRef_rho_L)
                                      +rho_Sc*pow(T-TRef_rho_L,2));

        cp = gamma_L*(cp_La+cp_Lb*(T-TRef_cp_L)+cp_Lc*pow(T-TRef_cp_L,2)) 
            + (scalar(1) - gamma_L)*(cp_Sa+cp_Sb*(T-TRef_cp_S)+cp_Sc*pow(T-TRef_cp_S,2));

        rhomixPhiCp = fvc::interpolate(cp)*phi*fvc::interpolate(rhomix);

        rhomixPhi = fvc::interpolate(rhomix)*phi;

        rhomixCp = e*rhomix*cp+(1-e)*rou_metal*cp_metal;
		
		rhomixe = rhomix*e;
		
		rhomixPhie = fvc::interpolate(rhomix)*phi*e;

        k = gamma_L*(k_La+k_Lb*(T-TRef_k_L)+k_Lc*pow(T-TRef_k_L,2))
            + (scalar(1) - gamma_L)*(k_Sa+k_Sb*(T-TRef_k_S)+k_Sc*pow(T-TRef_k_S,2));

        fvScalarMatrix TEqn
        (
            fvm::ddt(rhomixCp,T)
          + fvm::div(rhomixPhiCp, T)
          + h_m*fvc::ddt(rhomixe,gamma_L)
          + h_m*fvc::div(rhomixPhie, gamma_L)
          - T_m*fvc::ddt(rhomixCp)
          - T_m*fvc::div(rhomixPhiCp)
          - fvm::laplacian(k, T)
        );

        TEqn.relax();

        TEqn.solve();

        Tcons = (T_L-T_S)*gamma_L+T_S;
        gamma_L = max(min(gamma_L + relaxGamma_L*cp/h_m*(T - Tcons),scalar(1)),scalar(0));

        residual = gMax(mag(gamma_L.primitiveField() - gamma_L.prevIter().primitiveField()));

        Info << "Correcting gamma_L, max residual = " << residual
        << endl;

    }while ((iter < minTiter || residual > gamma_L_Tol ) && iter <= maxTiter);
