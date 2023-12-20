    // Solve the momentum equation

    MRF.correctBoundaryVelocity(U);

    fvVectorMatrix UEqn
    (
        (1/e)*fvm::ddt(U)
        + (1/(e*e))*fvm::div(phi, U)
        - (1/e)*fvm::laplacian(nu, U)
        + fvm::Sp(DarcyTerm/rho, U)
        //- DC*Us/rho
        + MRF.DDt(U)
        ==
        fvOptions(U)
    );

    UEqn.relax();

    fvOptions.constrain(UEqn);

    if (pimple.momentumPredictor())
    {
        solve
        (
            UEqn
         ==
            fvc::reconstruct
            (
                (
                  - ghf*fvc::snGrad(rhok)
                  - fvc::snGrad(p_rgh)
                )*mesh.magSf()
            )
        );

        fvOptions.correct(U);
    }
