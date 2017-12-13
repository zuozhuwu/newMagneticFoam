Info<<"Genarating Murf"<<nl;

forAll(faceCentres, facei)
{
	scalar x = faceCentres[facei].x();
	scalar y = faceCentres[facei].y();
	scalar z = faceCentres[facei].z();

	if(z >= m_z0 && z <= m_z1 )
	{
		theta = std::atan(y/x);		

		r = std::sqrt(x*x + y*y);

		if(r > m_distance + m_H && r < m_distance + m_H + thickIron)
		{
			murf[facei] = Muri;
		}


	}

}
