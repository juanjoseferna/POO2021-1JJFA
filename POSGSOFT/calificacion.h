//#ifndef CALIFICACION_H
//#define CALIFICACION_H

class Calificacion{
	private:
		float notaDesarrollo = -1, notaDesafio = -1, notaCumplimiento = -1, notaInnovacion = -1, notaResultados = -1, notaInformacion = -1;
		float notaCalidadDoc = -1, notaPresentacion = -1, notaFinal;
	public:
		Calificacion();
		void setNotaDesarrollo( float );
		void setNotaDesafio( float );
		void setNotaCumplimiento( float );
		void setNotaInnovacion( float );
		void setNotaResultados( float );
		void setNotaInformacion( float );
		void setNotaCalidadDoc( float );
		void setNotaPresentacion( float );
		void calcularNotaFinal();
};

//#endif /* !CALIFICACION_H */