forAll(faceCentres, facei)
{
	scalar x = faceCentres[facei].x();
	scalar y = faceCentres[facei].y();
	scalar z = faceCentres[facei].z();

	if(z >= m_z0 && z <= m_z1 )
	{

        Mrf[facei] = 0;         //reset all value, because when rotating, all value must be reset
       
		theta = std::atan(y/x);


		theta_m -= int(theta_m/subMotorAngle) * subMotorAngle;			
		
		theta -= theta_m;

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




