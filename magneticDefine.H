
scalar omiga_s = omiga * pi / 30;     //change rpm to radius/sec

theta_m = omiga_s * runTime.value();

forAll(faceCentres, facei)
{
	scalar x = faceCentres[facei].x();
	scalar y = faceCentres[facei].y();
	scalar z = faceCentres[facei].z();

	if(z >= m_z0 && z <= m_z1 )
	{
		theta = std::atan(y/x);

		theta_m -= int(theta_m/subMotorAngle) * subMotorAngle;			
		
		theta -= theta_m;

		theta  = (theta < 0) ? (theta + subMotorAngle) : theta;

		nth = int(theta / m_theta_m);

		r = std::sqrt(x*x + y*y);			

		if( r >= m_distance_outter && r <= m_distance_outter + m_H  )
		{
            
            Mrf[facei] = 0;         //reset all value, because when rotating, all value must be reset

		    if(theta - (startAngle_m + nth) * m_theta_m <= deltThetaMax &&
               theta - (startAngle_m + nth) * m_theta_m >= -1 * deltThetaMax)
            {
                vector orientationi = vector(0, 0, 0);

                if(nth % 2 == 0)
                    orientationi = vector(-1 * x / r, -1 * y / r, 0);
                else
                    orientationi = vector(x / r, y / r, 0);

                Mrf[facei] = Mri*(orientationi & Sf[facei]);
            }
		}
	}
}




