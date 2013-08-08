#ifndef FRAMEREGULATOR_H
#define FRAMEREGULATOR_H

class FrameRegulator {
	
private:
	unsigned int fps;
	unsigned int framePause;
	
	unsigned int referenceTime;
	
public:
	FrameRegulator(unsigned int fps_) : fps(fps_), framePause(1000 / fps_) {}
	void setUp();
	void regulate();
};

#endif

