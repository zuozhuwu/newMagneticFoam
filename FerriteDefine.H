Info<<"Genarating Murf"<<nl;

scalar m_theta_c = subMotorAngle/m_coil;        //delta theta between two coils

scalar distanceSlotBottom = m_distance_outter - airGap - thickTT - deptSlot;

scalar angleDeltSlotTopMax = (m_theta_c - slotOpening / (m_distance_outter - airGap) )/2.0;

scalar angleDeltSlotBottomMax = (slotBottomWidth / distanceSlotBottom) / 2.0;



forAll(faceCentres, facei)
{
	scalar x = faceCentres[facei].x();
	scalar y = faceCentres[facei].y();
	scalar z = faceCentres[facei].z();	

	if(z >= m_z0 && z <= m_z1 )
	{
		theta = std::atan(y/x);		

		r = std::sqrt(x*x + y*y);

		nth = int(theta / m_theta_c);

		bool isFe = false;
		if(r > m_distance_outter - airGap - thickTT && r <= m_distance_outter - airGap)
		{
			if(abs(theta - (startAngle_c + nth) * m_theta_c) <= angleDeltSlotTopMax)
				isFe = true;
		}
		else if(r > distanceSlotBottom && r <= m_distance_outter - airGap - thickTT)
		{
			if(abs(theta - (startAngle_c + nth) * m_theta_c) <= angleDeltSlotBottomMax)
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
