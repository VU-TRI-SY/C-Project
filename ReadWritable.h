/*
*****************************************************************************
						  Milestone - #4
Full Name     : Ngoc Diem Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NFF
Completed date: Nov 29, 2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_READWRITABLE_H
#define SDDS_READWRITABLE_H

namespace sdds {
	class ReadWritable {
		bool flag;
	public:
		ReadWritable();
		virtual ~ReadWritable();
		bool isCsv() const;
		void setCsv (bool value) ;
		virtual std::ostream& write(std::ostream& os = std::cout) const = 0;
		virtual std::istream& read(std::istream& in = std::cin) = 0;
		friend std::ostream& operator << (std::ostream& os, ReadWritable& w);
		friend std::istream& operator>>(std::istream& is, ReadWritable& r);
	};
}
#endif // !SDDS_READWRITABLE_H
