	
	Info<<"Genarating Mr"<<endl;

	scalar subMotorAngle =  2 * pi/m_num;

	scalar m_theta_m = subMotorAngle/m_magnetic;    //delta theta between two magnetics

	const surfaceVectorField& faceCentres = mesh.Cf();

	const surfaceVectorField& Sf = mesh.Sf();

	scalar theta = 0.0;

	scalar r = 0.0;

	int nth = 1;     //the nth magnetic

	scalar deltThetaMax = m_W / m_distance_outter / 2;	

	scalar rotatingAngle = 0.0;       //rotating angle 



	forAll(faceCentres, facei)
	{
		scalar x = faceCentres[facei].x();
		scalar y = faceCentres[facei].y();
		scalar z = faceCentres[facei].z();

		if(z >= m_z0 && z <= m_z1 )
		{

			theta = std::atan(y/x);


			rotatingAngle -= int(rotatingAngle/subMotorAngle) * subMotorAngle;			
			
			theta -= rotatingAngle;

			theta  = (theta < 0) ? (theta + subMotorAngle) : theta;


			nth = int(theta / m_theta_m);

			r = std::sqrt(x*x + y*y);			

			if(
			   r >= m_distance_outter && r <= m_distance_outter + m_H && 
			   abs(theta - (startAngle_m + nth) * m_theta_m) <= deltThetaMax
			  )
			{
				vector orientationi;

				if(nth % 2 == 0)
					orientationi = vector(-1 * x, -1 * y, 0);
				else
					orientationi = vector(x, y, 0);
				

				Mrf[facei] = Mri*(orientationi & Sf[facei]);
			}

		}

	}




