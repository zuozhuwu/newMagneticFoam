
    if (!args.optionFound("noH") || args.optionFound("HdotGradH"))
    {
        volVectorField H
        (
            IOobject
            (
                "H",
                runTime.timeName(),
                mesh
            ),
            fvc::reconstruct(fvc::snGrad(psi)*mesh.magSf())
        );

        if (!args.optionFound("noH"))
        {
            Info<< nl
                << "Creating field H for time "
                << runTime.timeName() << endl;

//            H.write();
        }

        if (args.optionFound("HdotGradH"))
        {
            Info<< nl
                << "Creating field HdotGradH for time "
                << runTime.timeName() << endl;

            volVectorField HdotGradH
            (
                IOobject
                (
                    "HdotGradH",
                    runTime.timeName(),
                    mesh
                ),
                H & fvc::grad(H)
            );

            HdotGradH.write();
        }
    }

    Info<< nl
            << "Creating field B for time "
            << runTime.timeName() << endl;

    volVectorField B
    (
     IOobject
            (
                "B",
                runTime.timeName(),
                mesh
            ),
            constant::electromagnetic::mu0
           *fvc::reconstruct(murf*fvc::snGrad(psi)*mesh.magSf() + murf*Mrf)
        );

 //   B.write();
    
   
