IOdictionary transportProperties
(
    IOobject
    (
        "transportProperties",
        runTime.constant(),
        mesh,
        IOobject::MUST_READ,
        IOobject::NO_WRITE
    )
);

singlePhaseTransportModel laminarTransport(U, phi);

// Thermal expansion coefficient [1/K]
dimensionedScalar beta
(
    "beta",
    dimless/dimTemperature,
    laminarTransport
);

// Reading density rho
dimensionedScalar rho(transportProperties.lookup("rho"));

// Reading specific heat capacity
dimensionedScalar TRef_cp_S(transportProperties.lookup("TRef_cp_S"));
dimensionedScalar cp_Sa(transportProperties.lookup("cp_Sa"));
dimensionedScalar cp_Sb(transportProperties.lookup("cp_Sb"));
dimensionedScalar cp_Sc(transportProperties.lookup("cp_Sc"));

dimensionedScalar TRef_cp_L(transportProperties.lookup("TRef_cp_L"));
dimensionedScalar cp_La(transportProperties.lookup("cp_La"));
dimensionedScalar cp_Lb(transportProperties.lookup("cp_Lb"));
dimensionedScalar cp_Lc(transportProperties.lookup("cp_Lc"));

// Reading thermal conductivity
dimensionedScalar TRef_k_S(transportProperties.lookup("TRef_k_S"));
dimensionedScalar k_Sa(transportProperties.lookup("k_Sa"));
dimensionedScalar k_Sb(transportProperties.lookup("k_Sb"));
dimensionedScalar k_Sc(transportProperties.lookup("k_Sc"));

dimensionedScalar TRef_k_L(transportProperties.lookup("TRef_k_L"));
dimensionedScalar k_La(transportProperties.lookup("k_La"));
dimensionedScalar k_Lb(transportProperties.lookup("k_Lb"));
dimensionedScalar k_Lc(transportProperties.lookup("k_Lc"));

// Latent heat of melting
dimensionedScalar h_m(transportProperties.lookup("h_m"));

// Solidus and liquidus temperatures
dimensionedScalar T_S(transportProperties.lookup("T_S"));
dimensionedScalar T_L(transportProperties.lookup("T_L"));

// Calculate melting temperature
dimensionedScalar T_m
(
    "T_m",
    (T_L+T_S)/scalar(2.0)
);

// Reading parameters for Darcy source term
dimensionedScalar DarcyConstant(transportProperties.lookup("DarcyConstant"));
dimensionedScalar DarcyTerm_epsilon(transportProperties.lookup("DarcyTerm_epsilon"));

// Reading kinematic viscosity
dimensionedScalar TRef_nu(transportProperties.lookup("TRef_nu"));
dimensionedScalar nua(transportProperties.lookup("nua"));
dimensionedScalar nub(transportProperties.lookup("nub"));
dimensionedScalar nuc(transportProperties.lookup("nuc"));

// Reading liquid density
dimensionedScalar TRef_rho_L(transportProperties.lookup("TRef_rho_L"));
dimensionedScalar rho_La(transportProperties.lookup("rho_La"));
dimensionedScalar rho_Lb(transportProperties.lookup("rho_Lb"));
dimensionedScalar rho_Lc(transportProperties.lookup("rho_Lc"));
dimensionedScalar rho_Ld(transportProperties.lookup("rho_Ld"));
dimensionedScalar rho_Le(transportProperties.lookup("rho_Le"));

// Reading solid density
dimensionedScalar TRef_rho_S(transportProperties.lookup("TRef_rho_S"));
dimensionedScalar rho_Sa(transportProperties.lookup("rho_Sa"));
dimensionedScalar rho_Sb(transportProperties.lookup("rho_Sb"));
dimensionedScalar rho_Sc(transportProperties.lookup("rho_Sc"));

// Reference temperature [K]
dimensionedScalar TRef("TRef", dimTemperature, laminarTransport);

// 读取孔隙率
dimensionedScalar e(transportProperties.lookup("e"));

// 读取泡沫金属的密度
dimensionedScalar rou_metal(transportProperties.lookup("rou_metal"));

// 读取泡沫金属的热容
dimensionedScalar cp_metal(transportProperties.lookup("cp_metal"));

// 读取蓄能器参数
dimensionedScalar P0_accu(transportProperties.lookup("P0_accu"));
dimensionedScalar V0_accu(transportProperties.lookup("V0_accu"));
dimensionedScalar Vexpanmax(transportProperties.lookup("Vexpanmax"));
dimensionedScalar deltaTSL(transportProperties.lookup("deltaTSL"));
dimensionedScalar gamma(transportProperties.lookup("gamma"));
dimensionedScalar Pele(transportProperties.lookup("Pele")); 
dimensionedScalar Vele(transportProperties.lookup("Vele")); 


//读取PCM熔点随压力变化的关系
dimensionedScalar Vpcm_death(transportProperties.lookup("Vpcm_death"));
dimensionedScalar PRef(transportProperties.lookup("PRef"));
dimensionedScalar P_pcm(transportProperties.lookup("P_pcm"));
dimensionedScalar P_pcm0(transportProperties.lookup("P_pcm0"));
dimensionedScalar TPRefS(transportProperties.lookup("TPRefS"));
dimensionedScalar TPRefL(transportProperties.lookup("TPRefL"));
dimensionedScalar TP_kS(transportProperties.lookup("TP_kS"));
dimensionedScalar TP_kL(transportProperties.lookup("TP_kL"));

//压力迭代中间变量
dimensionedScalar P_pcm_pre(transportProperties.lookup("P_pcm_pre"));
dimensionedScalar residual_P(transportProperties.lookup("residual_P"));
dimensionedScalar residual_Pmin(transportProperties.lookup("residual_Pmin"));