

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

		r = std::sqrt(x*x + y*y);

		nth = int(theta / m_theta_c);

		bool isFe = false;
		if(r > m_distance_outter - airGap - thickTT && r <= m_distance_outter - airGap)
		{
			if(abs(theta - (startAngle_c + nth + 0.5) * m_theta_c) <= angleDeltSlotTopMax)      //+0.5 because of rotating
				isFe = true;
		}
		else if(r > distanceSlotBottom && r <= m_distance_outter - airGap - thickTT)
		{
			if(abs(theta - (startAngle_c + nth + 0.5) * m_theta_c) <= angleDeltSlotBottomMax)
				isFe = true;
		}

		if(
		   (r > (m_distance_outter + m_H) && r <= (m_distance_outter + m_H + thickIron)) ||
		   (r > m_distance_inner && r <= distanceSlotBottom) ||
		   isFe
		  )
		{
			murf[facei] = Muri;
		}


	}

}
