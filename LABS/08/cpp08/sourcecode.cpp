
/* 1 */
	
// function to calculate price of a coupon bond
double BondPrice(int n, 
       			 double couponyield, 
				 int m, 
				 double ytm, 
				 double f){
	
	double price = 0;
 
	//discounting all the coupons
	for (int i = 1; i <= (n*m); ++i){
	price += (couponyield*f/m)/pow((1+ytm/m), double(i));
	}
 
	//discounting face value
	price += f/pow(1+ytm/m, double(n*m)) ;
	
	return price;
 
}

/* 2 */
	
MyMatrix
AddMatrix(const MyMatrix& MatrixA,
          const MyMatrix& MatrixB){
	
	if (MatrixA.rows() != MatrixB.rows())
		throw("Matrices must have the same number of rows!");
	if (MatrixA.columns() != MatrixB.columns())
		throw("Matrices must have the same number of columns!");
	
	MyMatrix result(MatrixA.rows(), MatrixB.columns());
	
	for(size_t r = 0; r < MatrixA.rows(); r++){
	    for(size_t c = 0; c < MatrixB.columns(); c++){ 
		    result(r, c) = MatrixA(r,c) + MatrixB(r,c);
		}
	}
	
	return result;
}
	
		  
/* 4 */

// Define a BSCallValue function
double BSCallValue(double S, 
				   double X, 
				   double r, 
				   double sigma, 
				   double time) {
double time_sqrt=sqrt(time);
double d1=(log(S/X)+r*time)/(sigma*time_sqrt)+0.5*sigma*time_sqrt;
double d2=d1-(sigma*time_sqrt);
double c=S* N(d1) - X*exp(-r*time)*N(d2);
return c;
}

	
// norm.h
// norm.cpp
				   
