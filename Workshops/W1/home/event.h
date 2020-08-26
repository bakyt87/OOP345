#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H

extern unsigned g_sysClock;

namespace sdds {
    
	
	

	class Event {
	
	    char* m_event;
		unsigned long int m_startTime=0;
	public:
		Event();
		
		Event(const Event&);
		Event& operator=(const Event&);
		 ~Event();
		void display();
		void setDescription(char*);
		
    };

}
#endif
