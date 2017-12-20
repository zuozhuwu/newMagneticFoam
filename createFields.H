    
    #include "varDefine.H"

    fileName file("savedResults");   //creating a file for output

    OFstream of(file);

    of<<"\"the time\"" << "\"the rms(root-mean-square) current\"" << '\t' << "\"the ratating speed(rpm)\"" << '\t'
      << "\"the U phase inductance\"" << '\t' << "\"the V phase inductance\"" << '\t'
      << "\"the W phase inductance\"" << '\t' << "\"the torque\"" << '\t' 
      << "\"the voltage\"" << nl;


    Info<< "Reading field psi\n" << endl;
    volScalarField psi
    (
        IOobject
        (
            "psi",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

//    Info<< "Reading transportProperties wzz\n" << endl;


	



    IOdictionary transportProperties
    (
        IOobject
        (
            "transportProperties",
            runTime.constant(),
            mesh,
            IOobject::MUST_READ_IF_MODIFIED,
            IOobject::NO_WRITE
        )
    );

    transportProperties.lookup("I") >> I;

    transportProperties.lookup("omiga") >> omiga;


   // List<magnet> magnets(transportProperties.lookup("magnets"));

    surfaceScalarField murf
    (
        IOobject
        (
            "murf",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::AUTO_WRITE
        ),
        mesh,
        1
    );

    surfaceScalarField Mrf
    (
        IOobject
        (
            "Mrf",
            runTime.timeName(),
            mesh
        ),
        mesh,
        dimensionedScalar("Mr", dimensionSet(0, 1, 0, 0, 0, 1, 0), 0)
    );

/*
    forAll(magnets, i)
    {
        label magnetZonei = mesh.faceZones().findZoneID(magnets[i].name());

        if (magnetZonei == -1)
        {
            FatalIOErrorIn(args.executable().c_str(), transportProperties)
                << "Cannot find faceZone for magnet " << magnets[i].name()
                << exit(FatalIOError);
        }

        const labelList& faces = mesh.faceZones()[magnetZonei];

        const scalar muri = magnets[i].mur();
        const scalar Mri = magnets[i].Mr().value();
        const vector& orientationi = magnets[i].orientation();

        const surfaceVectorField& Sf = mesh.Sf();

        forAll(faces, i)
        {
            label facei = faces[i];
            murf[facei] = muri;
            Mrf[facei] = Mri*(orientationi & Sf[facei]);
        }
    }
*/

	//change muri of the specified zone
/*
	scalar Lmin, Lmax, Hmin, Hmax;

	Lmin = 0.02;
	Lmax = 0.2;
	Hmin = -0.01;
	Hmax = 0.01;

	scalar murfIron = 800;
*/

//scalar x = mesh.boundaryMesh()[patchI].faceCentres()[faceI].x();
//scalar y = mesh.boundaryMesh()[patchI].faceCentres()[faceI].y();
//scalar z = mesh.boundaryMesh()[patchI].faceCentres()[faceI].z();

/*
const vectorField& faceCentres = mesh.Cf().boundaryField()[patchI];

forAll(faceCentres, facei)
{
scalar x = faceCentres[facei].x();
scalar y = faceCentres[facei].y();
scalar z = faceCentres[facei].z();

fcpatch[facei] = vector(x, y, z);
}
*/

/*
	const surfaceVectorField& faceCentres = mesh.Cf();
	forAll(faceCentres, facei)
	{
		scalar x = faceCentres[facei].x();
		scalar y = faceCentres[facei].y();
		scalar z = faceCentres[facei].z();

		if(x > Lmin && x < Lmax && y > Hmin && y < Hmax && z > Hmin && z < Hmax)
		{
			murf[facei] = murfIron;
		}

	}
*/

//initialize inductance_now and inductance_passed
for(int8_t i = 0; i < m_coil; i++)
{
    inductance_now[i] = inductance_passed[i] = 0;
}


#include "FerriteDefine.H"

//calculating for runTime = 0

//#include "magneticDefine.H"

//#include "calcEMF.H"

//solve(fvm::laplacian(murf, psi) + fvc::div(murf*Mrf));

//#include "calcBH.H"

//#include "calcInductance.H"

//#include "calcTorque.H"

//#include "outputCtrl.H"















































