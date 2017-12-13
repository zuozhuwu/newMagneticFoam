	
	Info<<"Genarating Mr"<<endl;

	const surfaceVectorField& faceCentres = mesh.Cf();

	scalar theta = 0.0;
	scalar r = 0.0;

	int nth = 1;     //the nth magnetic

	scalar deltThetaMax = m_W / m_distance / 2;



	forAll(faceCentres, facei)
	{
		scalar x = faceCentres[facei].x();
		scalar y = faceCentres[facei].y();
		scalar z = faceCentres[facei].z();

		if(z >= m_z0 && z <= m_z1 )
		{

			theta = std::atan(y/x);


			nth = int(theta / m_theta);

			r = std::sqrt(x*x + y*y);			

			if(
			   r >= m_distance && r <= m_distance + m_H && 
			   abs(theta - (0.5 + nth) * m_theta) <= deltThetaMax
			  )
			{
				vector orientationi;

				if(nth % 2 == 0)
					orientationi = vector(-1 * x, -1 * y, 0);
				else
					orientationi = vector(x, y, 0);

				const surfaceVectorField& Sf = mesh.Sf();

				Mrf[facei] = Mri*(orientationi & Sf[facei]);
			}

		}

	}




