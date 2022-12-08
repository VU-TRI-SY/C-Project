#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H
#include "Menu.h"
#include "Vehicle.h"
#define MAX_NUM_SPOTS 100
namespace sdds
{
	class Parking
	{
		int m_noOfSpots;
		Vehicle* m_parkingSpots[MAX_NUM_SPOTS];
		int m_noOfParkedVehicles;
		char* m_fileName;
		Menu* parkingMenu;
		Menu* selectMenu;
		bool isEmpty() ;
		void setEmpty();
		void parkingStatus() ;
		void parkVehice();
		void returnVehice();
		void listParkedVehice();
		void findVehice();
		bool closeParking();
		bool exitParking();
		bool loadDataFile();
		void saveDataFile();

	public:
		Parking();
		Parking(const char* fileName);
		Parking( const char* fileName, int noOfSpots);
		~Parking ();
		Parking(const Parking& p) = delete;
		Parking& operator=(const Parking& p) = delete;
		int run();
	};
}

#endif