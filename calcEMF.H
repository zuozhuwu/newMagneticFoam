theta_e = theta_m * m_poles / 2.0;

Iu = I * std::cos(theta_e);

Iv = I * std::cos(theta_e - 2.0 * pi/3.0);

Iw = I * std::cos(theta_e + 2.0 * pi/3.0);

forAll(faceCentres, facei)
{
	scalar x = faceCentres[facei].x();
	scalar y = faceCentres[facei].y();
	scalar z = faceCentres[facei].z();

	if(z >= m_z0 && z <= m_z1 )
	{

		theta = std::atan(y/x);

		theta += 0.5 * m_theta_c;       //rotating half m_theta_c, because the first coil is devided to two parts

		theta = (theta >= subMotorAngle) ? (theta - subMotorAngle) : theta;

		nth = int(theta / m_theta_c);

		r = std::sqrt(x*x + y*y);

		if(r > distanceSlotBottom && r <= m_distance_outter - airGap - thickTT)
		{
			vector orientationi = vector(0, 0, 0);

			scalar mri_Temp = 0.0;

			if(nth == 0 || nth == 3 || nth == 5 || nth == 7 )
			{
				orientationi = vector(-1 * x / r, -1 * y / r, 0);
			}
			else if(nth == 1 || nth == 2 || nth == 4 || nth == 6 || nth == 8)
			{
				orientationi = vector(x / r, y / r, 0);
			}

			if(nth == 0 || nth == 1 || nth == 8)    //phase U
			{
				mri_Temp = coeff_I2Mr * Iu;
				
				Mrf[facei] = mri_Temp*(orientationi & Sf[facei]);
			}
			else if(nth == 2 || nth == 3 || nth == 4)    //phase V
			{
				mri_Temp = coeff_I2Mr * Iv;
				
				Mrf[facei] = mri_Temp*(orientationi & Sf[facei]);
			}
			else if(nth == 5 || nth == 6 || nth == 7)    //phase w
			{
				mri_Temp = coeff_I2Mr * Iw;
				
				Mrf[facei] = mri_Temp*(orientationi & Sf[facei]);
			}

		}
		
	}

}
