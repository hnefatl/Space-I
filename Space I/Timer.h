#ifndef _TIMER_H
#define _TIMER_H

class Timer
{
public:
	Timer();

	void Start();
	void Stop();
	void Pause();
	void Resume();

	unsigned long GetTicks() const;
	bool IsPaused() const;
	bool IsStopped() const;
protected:
	bool Paused;
	bool Stopped;

	unsigned long StartTicks;
	unsigned long PausedTicks;
};

#endif