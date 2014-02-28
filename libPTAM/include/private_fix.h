/// add a translation specified from the first three coordinates of a vector
/// @param v the translation vector
/// @ingroup gGL
inline void glTranslate(const Vector<> & v)
{
	glTranslated(v[0], v[1], v[2]);
}

/// multiply a TooN 3x3 matrix onto the current matrix stack. The GL matrix
/// last column and row are set to 0 with the lower right element to 1.
/// The matrix is also transposed to account for GL's column major format.
/// @param m the transformation matrix
/// @ingroup gGL
inline void glMultMatrix(const Matrix<3,3> &m)
{
	GLdouble glm[16];
	glm[0] = m[0][0]; glm[1] = m[1][0]; glm[2] = m[2][0]; glm[3] = 0;
	glm[4] = m[0][1]; glm[5] = m[1][1]; glm[6] = m[2][1]; glm[7] = 0;
	glm[8] = m[0][2]; glm[9] = m[1][2]; glm[10] = m[2][2]; glm[11] = 0;
	glm[12] = 0; glm[13] = 0; glm[14] = 0; glm[15] = 1;
	glMultMatrixd(glm);
}

inline void glMultMatrix(const SO3<> &so3)
{
	glMultMatrix(so3.get_matrix());
}

inline void glMultMatrix(SE3<> se3)
{
	glTranslate(se3.get_translation());
	glMultMatrix(se3.get_rotation());
}
 
