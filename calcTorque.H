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

        vector orientationi = vector(x, y, 0);

		if(abs(r - m_distance_outter) < delt_mesh_error_max )
		{
		    if(abs(theta - (startAngle_m + nth) * m_theta_m) <= deltThetaMax)
            {
                fluxLinkage_m += abs((B[facei] & orientationi) * (Sf[facei] & orientationi) );                      
            }
		}
	}
}

Info<<"currency: "<< I<<nl;

Info<<"fluxlinkage: "<<fluxLinkage_m<<nl;

torque = 1.5 * m_poles/2 * I * fluxLinkage_m;
