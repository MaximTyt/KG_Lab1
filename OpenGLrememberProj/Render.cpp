#include "Render.h"

#include <Windows.h>
#include <GL\GL.h>
#include <GL\GLU.h>
#include <math.h>
#include <cfloat>
#define PI 3.1415927

void figure(int i, double h, double angle) {
	double M[] = { -1.5, 2,0 };
	double A[] = { 2.5, 0, 0 };
	double B[] = { 0.5, 0.5, 0 };
	double C[] = { 0, 4.5, 0 };
	double D[] = { -3, 1.5, 0 };
	double E[] = { -0.5, 0, 0 };
	double F[] = { -2, -3, 0 };
	double G[] = { 0,-3, 0 };
	double H[] = { 0.5,-0.5, 0 };
	double O[] = { 0,0,0 };
	double z1 = pow(C[0], 2) + pow(C[1], 2);
	double z2 = pow(D[0], 2) + pow(D[1], 2);
	double z3 = pow(M[0], 2) + pow(M[1], 2);
	double x12 = C[0] - D[0];
	double x23 = D[0] - M[0];
	double x31 = M[0] - C[0];
	double y12 = C[1] - D[1];
	double y23 = D[1] - M[1];
	double y31 = M[1] - C[1];
	double zx = y12 * z3 + y23 * z1 + y31 * z2;
	double zy = x12 * z3 + x23 * z1 + x31 * z2;
	double z = x12 * y31 - y12 * x31;
	O[0] = -1 * zx / (2 * z);
	O[1] = zy / (2 * z);

	double r = sqrt(pow(G[0] - F[0], 2) + pow(G[1] - F[1], 2) + pow(G[2] - F[2], 2)) / 2;
	double r1 = sqrt(pow(C[0], 2) - 2 * C[0] * O[0] + pow(O[0], 2) + pow(C[1], 2) - 2 * C[1] * O[1] + pow(O[1], 2));
	int cnt = 50;
	switch (i)
	{
	case 1:
		glBegin(GL_TRIANGLES);
		glColor3d(1, 0.627, 0.478);
		glVertex3dv(A);
		glVertex3dv(B);
		glVertex3dv(H);

		glVertex3dv(B);
		glVertex3dv(C);
		glVertex3dv(E);

		glVertex3dv(G);
		glVertex3dv(H);
		glVertex3dv(E);

		glVertex3dv(H);
		glVertex3dv(B);
		glVertex3dv(E);

		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glColor3d(1, 0.627, 0.478);
		glVertex3dv(E);
		glVertex3dv(D);
		for (int i = -cnt / 2; i <= 0; i++)
		{
			if ((O[0] + r1 * cos(i * 2 * PI / cnt) <= C[0]) && (O[0] + r1 * cos(i * 2 * PI / cnt) >= D[0]) && (O[1] + r1 * sin(i * 2 * PI / cnt) <= C[1]) && (O[1] + r1 * sin(i * 2 * PI / cnt) >= D[1]))
			{
				glVertex3d(O[0] + r1 * cos(i * 2 * PI / cnt), O[1] + r1 * sin(i * 2 * PI / cnt), 0);
			}
		}

		glBegin(GL_TRIANGLE_FAN);
		glColor3d(1, 0.627, 0.478);
		glVertex3dv(E);
		for (int i = -cnt / 2; i <= 0; i++)
		{
			glVertex3d((F[0] + G[0]) / 2 + r * cos(i * 2 * PI / cnt), (F[1] + G[1]) / 2 + r * sin(i * 2 * PI / cnt), 0);

		}

		glEnd();
		break;
	case 2:
		glBegin(GL_QUADS);
		glColor3d(1, 0, 1);

		glVertex3dv(A);
		glVertex3dv(B);
		glVertex3d(H[0] * cos(angle * PI / 180) - H[1] * sin(angle * PI / 180), H[0] * sin(angle * PI / 180) + H[1] * cos(angle * PI / 180), h);
		glVertex3d(A[0] * cos(angle * PI / 180) - A[1] * sin(angle * PI / 180), A[0] * sin(angle * PI / 180) + A[1] * cos(angle * PI / 180), h);

		glVertex3dv(A);
		glVertex3dv(B);
		glVertex3d(B[0] * cos(angle * PI / 180) - B[1] * sin(angle * PI / 180), B[0] * sin(angle * PI / 180) + B[1] * cos(angle * PI / 180), h);
		glVertex3d(A[0] * cos(angle * PI / 180) - A[1] * sin(angle * PI / 180), A[0] * sin(angle * PI / 180) + A[1] * cos(angle * PI / 180), h);

		glVertex3dv(B);
		glVertex3dv(C);
		glVertex3d(C[0] * cos(angle * PI / 180) - C[1] * sin(angle * PI / 180), C[0] * sin(angle * PI / 180) + C[1] * cos(angle * PI / 180), h);
		glVertex3d(B[0] * cos(angle * PI / 180) - B[1] * sin(angle * PI / 180), B[0] * sin(angle * PI / 180) + B[1] * cos(angle * PI / 180), h);

		glVertex3dv(D);
		glVertex3dv(E);
		glVertex3d(E[0] * cos(angle * PI / 180) - E[1] * sin(angle * PI / 180), E[0] * sin(angle * PI / 180) + E[1] * cos(angle * PI / 180), h);
		glVertex3d(D[0] * cos(angle * PI / 180) - D[1] * sin(angle * PI / 180), D[0] * sin(angle * PI / 180) + D[1] * cos(angle * PI / 180), h);

		glVertex3dv(E);
		glVertex3dv(F);
		glVertex3d(F[0] * cos(angle * PI / 180) - F[1] * sin(angle * PI / 180), F[0] * sin(angle * PI / 180) + F[1] * cos(angle * PI / 180), h);
		glVertex3d(E[0] * cos(angle * PI / 180) - E[1] * sin(angle * PI / 180), E[0] * sin(angle * PI / 180) + E[1] * cos(angle * PI / 180), h);

		glVertex3dv(G);
		glVertex3dv(H);
		glVertex3d(H[0] * cos(angle * PI / 180) - H[1] * sin(angle * PI / 180), H[0] * sin(angle * PI / 180) + H[1] * cos(angle * PI / 180), h);
		glVertex3d(G[0] * cos(angle * PI / 180) - G[1] * sin(angle * PI / 180), G[0] * sin(angle * PI / 180) + G[1] * cos(angle * PI / 180), h);

		glVertex3dv(H);
		glVertex3dv(A);
		glVertex3d(A[0] * cos(angle * PI / 180) - A[1] * sin(angle * PI / 180), A[0] * sin(angle * PI / 180) + A[1] * cos(angle * PI / 180), h);
		glVertex3d(H[0] * cos(angle * PI / 180) - H[1] * sin(angle * PI / 180), H[0] * sin(angle * PI / 180) + H[1] * cos(angle * PI / 180), h);
		glEnd();

		glBegin(GL_LINES);
		glColor3d(0, 0, 0);
		glVertex3dv(A);
		glVertex3d(A[0] * cos(angle * PI / 180) - A[1] * sin(angle * PI / 180), A[0] * sin(angle * PI / 180) + A[1] * cos(angle * PI / 180), h);

		glVertex3dv(C);
		glVertex3d(C[0] * cos(angle * PI / 180) - C[1] * sin(angle * PI / 180), C[0] * sin(angle * PI / 180) + C[1] * cos(angle * PI / 180), h);

		glVertex3dv(D);
		glVertex3d(D[0] * cos(angle * PI / 180) - D[1] * sin(angle * PI / 180), D[0] * sin(angle * PI / 180) + D[1] * cos(angle * PI / 180), h);

		glVertex3dv(F);
		glVertex3d(F[0] * cos(angle * PI / 180) - F[1] * sin(angle * PI / 180), F[0] * sin(angle * PI / 180) + F[1] * cos(angle * PI / 180), h);

		glVertex3dv(G);
		glVertex3d(G[0] * cos(angle * PI / 180) - G[1] * sin(angle * PI / 180), G[0] * sin(angle * PI / 180) + G[1] * cos(angle * PI / 180), h);
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		for (int i = -cnt / 2; i <= 0; i++)
		{
			glColor3d(1, 0, 1);
			glVertex3d((F[0] + G[0]) / 2 + r * cos(i * 2 * PI / cnt), (F[1] + G[1]) / 2 + r * sin(i * 2 * PI / cnt), 0);
			glVertex3d(((F[0] + G[0]) / 2 + r * cos(i * 2 * PI / cnt)) * cos(angle * PI / 180) - ((F[1] + G[1]) / 2 + r * sin(i * 2 * PI / cnt)) * sin(angle * PI / 180), ((F[0] + G[0]) / 2 + r * cos(i * 2 * PI / cnt)) * sin(angle * PI / 180) + ((F[1] + G[1]) / 2 + r * sin(i * 2 * PI / cnt)) * cos(angle * PI / 180), h);
		}
		glEnd();


		glBegin(GL_TRIANGLE_STRIP);
		glVertex3d(D[0], D[1], 0);
		glVertex3d(D[0] * cos(angle * PI / 180) - D[1] * sin(angle * PI / 180), D[0] * sin(angle * PI / 180) + D[1] * cos(angle * PI / 180), h);
		for (int i = -cnt / 2; i <= 0; i++)
		{
			glColor3d(1, 0, 1);
			if ((O[0] + r1 * cos(i * 2 * PI / cnt) <= C[0]) && (O[0] + r1 * cos(i * 2 * PI / cnt) >= D[0]) && (O[1] + r1 * sin(i * 2 * PI / cnt) <= C[1]) && (O[1] + r1 * sin(i * 2 * PI / cnt) >= D[1]))
			{
				glVertex3d(O[0] + r1 * cos(i * 2 * PI / cnt), O[1] + r1 * sin(i * 2 * PI / cnt), 0);
				glVertex3d((O[0] + r1 * cos(i * 2 * PI / cnt)) * cos(angle * PI / 180) - (O[1] + r1 * sin(i * 2 * PI / cnt)) * sin(angle * PI / 180), (O[0] + r1 * cos(i * 2 * PI / cnt)) * sin(angle * PI / 180) + (O[1] + r1 * sin(i * 2 * PI / cnt)) * cos(angle * PI / 180), h);
			}
		}
		glVertex3d(C[0], C[1], 0);
		glVertex3d(C[0] * cos(angle * PI / 180) - C[1] * sin(angle * PI / 180), C[0] * sin(angle * PI / 180) + C[1] * cos(angle * PI / 180), h);
		glEnd();
		break;
	}

}

void figureall(double height, double angle)
{
	int cnt = 100;
	double step_h = height / cnt, temp_h = 0;
	double step_a, temp_a = 0;
	if (cnt == 1)
		step_a = angle;
	if (cnt == 2)
		step_a = angle / 2;
	else
		step_a = angle / cnt;
	for (int i = 0; i < cnt; i++)
	{
		glPushMatrix();
		glRotated(temp_a, 0, 0, 1);
		glTranslated(0, 0, temp_h);
		figure(2, step_h, step_a);
		temp_a += step_a;
		temp_h += step_h;
		glPopMatrix();
	}
	figure(1, height, angle);
	glRotated(angle, 0, 0, 1);
	glTranslated(0, 0, height);
	figure(1, height, angle);
}
double h = 10, angle = 90, t_max = 0, h_max = 0, step = 40;
void Render(double delta_time)
{		
	t_max += delta_time * step;
	if (t_max > angle) step = -step;
	if (t_max < -angle) step = -step;

	h_max += delta_time * step / (h * 2);
	if (h_max > h) step = -step;
	if (h_max < -h) step = -step;
		
	figureall(h_max, t_max);	
}

