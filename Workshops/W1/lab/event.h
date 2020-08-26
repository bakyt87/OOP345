#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H

extern unsigned g_sysClock;

namespace sdds {
    
	
	

	class Event {
	
		char m_event[128];
		unsigned long int m_startTime=0;
	public:
		Event();
		
		void display();
		void setDescription(char*);
		
    };

}
#endif
