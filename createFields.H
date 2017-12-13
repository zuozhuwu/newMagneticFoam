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

#include "varDefine.H"

#include "magneticDefine.H"


#include "FerriteDefine.H"























































