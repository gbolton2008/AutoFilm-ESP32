#include "devSequence.h"

struct devSequence devSequences[NUM_DEV_SEQUENCES] = {
	{"C41",
	 7,
	 {180, 195, 45, 180, 60, 60, 30},											   // processTime
	 {"Prewarm", "Developer", "Bleach", "Fix", "Rinse 1", "Rinse 2", "Fin Rinse"}, // processName
	 {
		 {1, 5.5, 5.5, 5.5, 3.5, 3.5, 1}, // CW rotations processCycle
		 {1, 5, 5, 5, 3, 3, 1}},		  // CCW rotations processCycle
	 {
		 {37.8, 37.8, 32, 32, 32, 32, 32},			// min processTemp
		 {38, 38, 38, 38, 38, 38, 38},				// preferred processTemp
		 {38.2, 38.2, 38.2, 38.2, 38.2, 38.2, 38.2} // max processTemp
	 }},
	{"E6",
	 12,
	 {180, 360, 120, 120, 360, 120, 360, 240, 120, 120, 120, 30},
	 {"Preheat", "FirstDev", "Wash 1", "Reversal", "ColorDev", "PreBleach", "Bleach", "Fixer", "Wash 2", "Wash 3", "Wash 4", "Fin Rinse"},
	 {{1, 5.5, 3.5, 5, 5.5, 5.5, 5.5, 5.5, 3.5, 3.5, 3.5, 3.5},
	  {1, 5, 3, 5.5, 5, 5.5, 5.5, 5.5, 3, 3, 3, 3}},
	 {{37.5, 37.7, 33.0, 37.7, 37.0, 37, 37.5, 37.5, 33.0, 33.0, 33.0, 19.0},
	  {38.0, 38.0, 38.0, 38.0, 38.0, 38.0, 38.0, 38.0, 38.0, 38.0, 38.0, 20.0},
	  {38.5, 38.3, 38.0, 38.3, 39.0, 38, 38.5, 38.5, 38.5, 38.5, 38.5, 21.0}}},
	{"ECN-2",
	 9,
	 {180, 0, 210, 60, 180, 150, 120, 300, 120},
	 {"Prebath", "RemJet", "Developer", "Stop Bath", "Wash", "Bleach", "Fixer", "Wash 2", "Fin Rinse"},
	 {{1, 0, 5.5, 3.5, 3.5, 5.5, 5.5, 3.5, 1},
	  {1, 0, 5, 3, 3, 5, 5, 3, 1}},
	 {{27.0, 0, 40.8, 27.0, 27.0, 27.0, 27.0, 27.0, 27.0},
	  {38.0, 0, 41.0, 38.0, 38.0, 38.0, 38.0, 38.0, 38.0},
	  {38.0, 0, 41.2, 38.0, 38.0, 38.0, 38.0, 38.0, 38.0}}},
	{"B&W",
	 7,
	 {510, 30, 300, 60, 90, 120, 30},
	 {"Developer", "Stop", "Fix", "Rinse 1", "Rinse 2", "Rinse 3", "Fin Rinse"},
	 {{5.5, 3.5, 3.5, 3.5, 3.5, 3.5, 1},
	  {5, 3, 3, 3, 3, 3, 1}},
	 {{19, 19, 19, 19, 19, 19, 19},
	  {20, 20, 20, 20, 20, 20, 20},
	  {21, 21, 21, 21, 21, 21, 21}}},
	{"Custom",
	 4,
	 {10, 10, 10, 10},
	 {"Developer", "Stop", "Fix", "Rinse"},
	 {{5.5, 3.5, 3.5, 3.5},
	  {5, 3, 3, 3}},
	 {{19, 19, 19, 19},
	  {20, 20, 20, 20},
	  {21, 21, 21, 21}}},
	{"B&WREV",
	 12,
	 {720, 300, 300, 60, 120, 60, 120, 360, 60, 300, 60, 60},
	 {"FirstDev", "Wash 1", "Bleach", "Wash 2", "Clearing", "Wash 3", "Reversal", "SecondDev", "Wash 4", "Fix", "Wash 5", "Fin Rinse"},
	 {{5.5, 3.5, 5.5, 3.5, 5.5, 3.5, 5.5, 5.5, 3.5, 5.5, 3.5, 3.5},
	  {5, 3, 5, 3, 5, 3, 5, 5, 3, 5, 3, 3}},
	 {{19.5, 15.5, 19.5, 15.5, 19.5, 15.5, 19.5, 19.5, 15.5, 19.5, 15.5, 15.5},
	  {20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0},
	  {20.5, 22.5, 22.5, 22.5, 22.5, 22.5, 22.5, 22.5, 22.5, 22.5, 22.5, 22.5}}}};

struct devSequence *findSequenceByName(const char *processName)
{
	for (int i = 0; i < NUM_DEV_SEQUENCES; i++)
	{
		if (strcmp(devSequences[i].processName, processName) == 0)
		{
			return &devSequences[i];
		}
	}
	return NULL; // Return NULL if not found
}
